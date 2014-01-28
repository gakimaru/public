#include <stdio.h>
#include <stdlib.h>

#include <assert.h>

#include <mutex>
#include <atomic>

template<class T>
class CSingleton;

template<class T>
class CSafeSingleton;

template<class T>
class CSafeSingletonInitializer;

template<class T>
class CSafeSingletonUsing;

//シングルトン基底クラス
class CSingletonBase
{
public:
	enum E_TYPE
	{
		THREAD_SAFE,   //スレッドセーフ自動シングルトン（自動生成のみ、自動削除不可）
		AUTO,          //自動シングルトン（自動生成／自動削除、手動削除可）
		SAFE_SINGLETON,//セーフシングルトン（手動生成、自動削除）
	};
protected:
	//コンストラクタ
	CSingletonBase() :
		m_isReleased(false)
	{
	}
	//デストラクタ
	~CSingletonBase()
	{
	}
protected:
	bool m_isReleased;
};

//シングルトンテンプレート
template<class T>
class CSingleton : public CSingletonBase
{
	friend class CSafeSingleton<T>;
	friend class CSafeSingletonInitializer<T>;
	friend class CSafeSingletonUsing<T>;
private:
	void* operator new(const size_t size){ return m_buff; }
	void operator delete(void*){}
public:
	//オペレータを実装して本来のオブジェクトを偽装（代理）
	T* operator->(){ return m_this; }
	const T* operator->() const { return m_this; }
private:
	T& operator*(){ return *m_this; }
	const T& operator*() const { return *m_this; }
	operator T*(){ return m_this; }
	operator const T*() const { return m_this; }
	operator T&(){ return *m_this; }
	operator const T&() const { return *m_this; }
private:
	//コピーコンストラクタ禁止
	explicit CSingleton(CSingleton<T>&){}
	explicit CSingleton(CSingleton<T>*){}
	explicit CSingleton(T&){}
	explicit CSingleton(T*){}
	//コピーオペレーター禁止
	CSingleton<T>& operator=(const CSingleton<T>&){ return *this; }
	CSingleton<T>& operator=(const CSingleton<T>*){ return *this; }
	CSingleton<T>& operator=(const T&){ return *this; }
	CSingleton<T>& operator=(const T*){ return *this; }
private:
	void addRef()
	{
		++m_refCount;
		if (!m_this)
		{
			auto create_lambda = []()
			{
				m_this = new T;
			};
			if (T::SINGLETON_TYPE == THREAD_SAFE)
				std::call_once(m_once, create_lambda);
			else
				create_lambda();
		}
	}
	void release()
	{
		if (m_isReleased)
			return;
		m_isReleased = true;
		if (m_refCount <= 0)
			return;
		--m_refCount;
		if (T::SINGLETON_TYPE != THREAD_SAFE && m_refCount == 0)
		{
			deleteThis();
		}
	}
	void deleteThis()
	{
		if (m_this)
		{
			delete m_this;
			m_this = nullptr;
			m_refCount = 0;
		}
	}
private:
	//コンストラクタ
	CSingleton(CSafeSingleton<T>*) :
		CSingletonBase()
	{
		addRef();
	}
public:
	//コンストラクタ
	CSingleton() :
		CSingletonBase()
	{
	//	assert(T::SINGLETON_TYPE != SAFE_SINGLETON);
		if (T::SINGLETON_TYPE == SAFE_SINGLETON)
		{
			fprintf(stderr, "CSingleton can not use when T::SINGLETON_TYPE is SAFE_SINGLETON.\n");
			m_isReleased = true;
			return;
		}
		addRef();
	}
	//デストラクタ
	~CSingleton()
	{
		release();
	}
private:
	static std::once_flag m_once;
	static T* m_this;
	static char m_buff[sizeof(T)];
	static std::atomic<int> m_refCount;
};

//セーフシングルトンテンプレート
template<class T>
class CSafeSingleton : public CSingleton<T>
{
	friend class CSafeSingletonInitializer<T>;
	friend class CSafeSingletonUsing<T>;
private:
	//コンストラクタ
	CSafeSingleton() :
		CSingleton<T>::CSingleton(this)
	{
	}
	//デストラクタ
	~CSafeSingleton()
	{
		CSingleton<T>::~CSingleton();
	}
};

#define MAKE_SINGLETON_INSTANCE(T) \
	std::once_flag CSingleton<T>::m_once; \
	T* CSingleton<T>::m_this = nullptr; \
	char CSingleton<T>::m_buff[sizeof(T)]; \
	std::atomic<int> CSingleton<T>::m_refCount = 0; \

//セーフシングルトンイニシャライザーテンプレート
template<class T>
class CSafeSingletonInitializer
{
	static_assert(T::SINGLETON_TYPE == CSingletonBase::SAFE_SINGLETON, "class T::SINGLETON_TYPE is not SAFE_SINGLETON.");
public:
	//オペレータを実装して本来のオブジェクトを偽装（代理）
	T* operator->(){ return m_singleton; }
	const T* operator->() const { return m_singleton; }
private:
	T& operator*(){ return *m_singleton; }
	const T& operator*() const { return *m_singleton; }
	operator T*(){ return m_singleton; }
	operator const T*() const { return m_singleton; }
	operator T&(){ return *m_singleton; }
	operator const T&() const { return *m_singleton; }
private:
	//コピーコンストラクタ禁止
	explicit CSafeSingletonInitializer(CSafeSingletonInitializer<T>&){}
	explicit CSafeSingletonInitializer(CSafeSingletonInitializer<T>*){}
	explicit CSafeSingletonInitializer(T&){}
	explicit CSafeSingletonInitializer(T*){}
	//コピーオペレーター禁止
	CSafeSingletonInitializer<T>& operator=(const CSafeSingletonInitializer<T>&){ return *this; }
	CSafeSingletonInitializer<T>& operator=(const CSafeSingletonInitializer<T>*){ return *this; }
	CSafeSingletonInitializer<T>& operator=(const T&){ return *this; }
	CSafeSingletonInitializer<T>& operator=(const T*){ return *this; }
public:
	void release(){ m_singleton.release(); }
	void deleteThis(){ m_singleton.deleteThis(); }
public:
	static bool isAlreadyExist()
	{
		return m_name != nullptr;
	}
private:
	void setName(const char* name)
	{
		if (!m_name)
			m_name = name;
	}
public:
	CSafeSingletonInitializer(const char* name):
		m_singleton()
	{
	//	assert(!isAlreadyExist());
		if (isAlreadyExist())
		{
			fprintf(stderr, "CSafeSingletonInitializer: already exist!\n");
			m_singleton.release();
			return;
		}
		setName(name);
	}
	~CSafeSingletonInitializer()
	{
		m_name = nullptr;
	}
private:
	CSafeSingleton<T> m_singleton;
	static const char* m_name;
};

#define MAKE_SAFE_SINGLETON_INITIALIZER_INSTANCE(T) \
	const char* CSafeSingletonInitializer<T>::m_name = 0; \

//セーフシングルトン使用テンプレート
template<class T>
class CSafeSingletonUsing
{
	static_assert(T::SINGLETON_TYPE == CSingletonBase::SAFE_SINGLETON, "class T::SINGLETON_TYPE is not SAFE_SINGLETON.");
	static_assert(T::SAFE_SINGLETON_USING_STACK_MAX > 0, "class T::SAFE_SINGLETON_USING_STACK_MAX is under 0.");
public:
	//オペレータを実装して本来のオブジェクトを偽装（代理）
	T* operator->(){ return m_singleton; }
	const T* operator->() const { return m_singleton; }
private:
	T& operator*(){ return *m_singleton; }
	const T& operator*() const { return *m_singleton; }
	operator T*(){ return m_singleton; }
	operator const T*() const { return m_singleton; }
	operator T&(){ return *m_singleton; }
	operator const T&() const { return *m_singleton; }
private:
	//コピーコンストラクタ禁止
	explicit CSafeSingletonUsing(CSafeSingletonUsing<T>&){}
	explicit CSafeSingletonUsing(CSafeSingletonUsing<T>*){}
	explicit CSafeSingletonUsing(T&){}
	explicit CSafeSingletonUsing(T*){}
	//コピーオペレーター禁止
	CSafeSingletonUsing<T>& operator=(const CSafeSingletonUsing<T>&){ return *this; }
	CSafeSingletonUsing<T>& operator=(const CSafeSingletonUsing<T>*){ return *this; }
	CSafeSingletonUsing<T>& operator=(const T&){ return *this; }
	CSafeSingletonUsing<T>& operator=(const T*){ return *this; }
private:
	void pushStack(const char* name)
	{
		m_thisStack = new STACK(m_stackList, name);
		if (m_thisStack)
			m_stackList = m_thisStack;
	}
	void popStack()
	{
		if (m_thisStack)
		{
			m_stackList = m_thisStack->m_next;
			delete m_thisStack;
		}
	}
public:
	void debugPrint()
	{
		STACK* stack = m_stackList;
		while (stack)
		{
			printf("[%s]\n", stack->m_name);
			stack = stack->m_next;
		}
		printf("(%d/%d)\n", m_stackNum, m_stackNumMax);
	}
public:
	CSafeSingletonUsing(const char* name) :
		m_singleton()
	{
	//	assert(CSafeSingletonInitializer<T>::isAlreadyExist());
		if (!CSafeSingletonInitializer<T>::isAlreadyExist())
		{
			fprintf(stderr, "CSafeSingletonInitializer: not exist!\n");
			m_singleton.release();
			return;
		}
		pushStack(name);
	}
	~CSafeSingletonUsing()
	{
		popStack();
	}
private:
	struct STACK
	{
		STACK* m_next;
		const char* m_name;
		STACK(STACK* next, const char* name) :
			m_next(next),
			m_name(name)
		{
		}
		~STACK()
		{
		}
		void* operator new(const size_t size)
		{
		//	assert(m_stackNum < T::SAFE_SINGLETON_USING_STACK_MAX);
			if (m_stackNum >= T::SAFE_SINGLETON_USING_STACK_MAX)
			{
				fprintf(stderr, "CSafeSingletonUsing: stack over flow.\n");
				return 0;
			}
			const int index = m_stackNum++;
			if (m_stackNumMax < m_stackNum)
				m_stackNumMax = m_stackNum;
			return &m_stackBuff[index];
		}
		void operator delete(void*)
		{
			--m_stackNum;
		}
	};
	CSafeSingleton<T> m_singleton;
	STACK* m_thisStack;
	static __declspec(thread) int m_stackNum;
	static __declspec(thread) int m_stackNumMax;
	static __declspec(thread) STACK* m_stackList;
	static __declspec(thread) char m_stackBuff[T::SAFE_SINGLETON_USING_STACK_MAX][sizeof(STACK)];
};

#define MAKE_SAFE_SINGLETON_USING_INSTANCE(T) \
	int CSafeSingletonUsing<T>::m_stackNum = 0; \
	int CSafeSingletonUsing<T>::m_stackNumMax = 0; \
	CSafeSingletonUsing<T>::STACK* CSafeSingletonUsing<T>::m_stackList = nullptr; \
	char CSafeSingletonUsing<T>::m_stackBuff[T::SAFE_SINGLETON_USING_STACK_MAX][sizeof(CSafeSingletonUsing<T>::STACK)];

#define MAKE_SAFE_SINGLETON_INSTANCE(T) \
	MAKE_SINGLETON_INSTANCE(T); \
	MAKE_SAFE_SINGLETON_INITIALIZER_INSTANCE(T); \
	MAKE_SAFE_SINGLETON_USING_INSTANCE(T);

//仮リソースマネージャクラス
class CResManager
{
	//シングルトンクラス対応
	friend CSingleton<CResManager>;
public:
	static const CSingletonBase::E_TYPE SINGLETON_TYPE = CSingletonBase::SAFE_SINGLETON;
	static const std::size_t SAFE_SINGLETON_USING_STACK_MAX = 3;

private:
	//コンストラクタはプライベート化する
	CResManager():
		m_val(0)
	{
		printf("constructor!\n");
	}
	//デストラクタ
	~CResManager()
	{
		printf("desstructor!\n");
	}
public:
	int getVal() const { return m_val; }
	void setVal(const int val) { m_val = val; }
private:
	int m_val;
};

//サブ処理A
void subA()
{
	CSafeSingletonUsing<CResManager> res("subA");
	res->setVal(123);
}

//サブ処理B
void subB()
{
	CSafeSingletonUsing<CResManager> res("subB");
	printf("getVal()=%d\n", res->getVal());
	extern void subC();
	subC();
	printf("getVal()=%d\n", res->getVal());
	res.debugPrint();
}

//サブ処理C
void subC()
{
	CSafeSingletonUsing<CResManager> res("subC");
	res->setVal(456);
	CSafeSingletonInitializer<CResManager> res2("subC");
	CSafeSingletonUsing<CResManager> res3("subC2");
	CSingleton<CResManager> res4;
	res.debugPrint();
}

//テスト
int main(const int argc, const char* argv[])
{
	{
		CSafeSingletonUsing<CResManager> res3("main");
		CSafeSingletonInitializer<CResManager> res("main");
		CSafeSingletonUsing<CResManager> res2("main");
		subA();
		subB();
		res2.debugPrint();
	//	res.deleteThis();
	}
	return EXIT_SUCCESS;
}

MAKE_SAFE_SINGLETON_INSTANCE(CResManager);

// End of file

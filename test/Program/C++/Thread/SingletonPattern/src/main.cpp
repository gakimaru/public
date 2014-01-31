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

//�V���O���g�����N���X
class CSingletonBase
{
public:
	enum E_TYPE
	{
		THREAD_SAFE,   //�X���b�h�Z�[�t�����V���O���g���i���������̂݁A�����폜�s�j
		AUTO,          //�����V���O���g���i���������^�����폜�A�蓮�폜�j
		SAFE_SINGLETON,//�Z�[�t�V���O���g���i�蓮�����A�����폜�j
	};
protected:
	//�R���X�g���N�^
	CSingletonBase() :
		m_isReleased(false)
	{
	}
	//�f�X�g���N�^
	~CSingletonBase()
	{
	}
protected:
	bool m_isReleased;
};

//�V���O���g���e���v���[�g
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
	//�I�y���[�^���������Ė{���̃I�u�W�F�N�g���U���i�㗝�j
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
	//�R�s�[�R���X�g���N�^�֎~
	explicit CSingleton(CSingleton<T>&){}
	explicit CSingleton(CSingleton<T>*){}
	explicit CSingleton(T&){}
	explicit CSingleton(T*){}
	//�R�s�[�I�y���[�^�[�֎~
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
	//�R���X�g���N�^
	CSingleton(CSafeSingleton<T>*) :
		CSingletonBase()
	{
		addRef();
	}
public:
	//�R���X�g���N�^
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
	//�f�X�g���N�^
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

//�Z�[�t�V���O���g���e���v���[�g
template<class T>
class CSafeSingleton : public CSingleton<T>
{
	friend class CSafeSingletonInitializer<T>;
	friend class CSafeSingletonUsing<T>;
private:
	//�R���X�g���N�^
	CSafeSingleton() :
		CSingleton<T>::CSingleton(this)
	{
	}
	//�f�X�g���N�^
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

//�Z�[�t�V���O���g���C�j�V�����C�U�[�e���v���[�g
template<class T>
class CSafeSingletonInitializer
{
	static_assert(T::SINGLETON_TYPE == CSingletonBase::SAFE_SINGLETON, "class T::SINGLETON_TYPE is not SAFE_SINGLETON.");
public:
	//�I�y���[�^���������Ė{���̃I�u�W�F�N�g���U���i�㗝�j
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
	//�R�s�[�R���X�g���N�^�֎~
	explicit CSafeSingletonInitializer(CSafeSingletonInitializer<T>&){}
	explicit CSafeSingletonInitializer(CSafeSingletonInitializer<T>*){}
	explicit CSafeSingletonInitializer(T&){}
	explicit CSafeSingletonInitializer(T*){}
	//�R�s�[�I�y���[�^�[�֎~
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

//�Z�[�t�V���O���g���g�p�e���v���[�g
template<class T>
class CSafeSingletonUsing
{
	static_assert(T::SINGLETON_TYPE == CSingletonBase::SAFE_SINGLETON, "class T::SINGLETON_TYPE is not SAFE_SINGLETON.");
	static_assert(T::SAFE_SINGLETON_USING_STACK_MAX > 0, "class T::SAFE_SINGLETON_USING_STACK_MAX is under 0.");
public:
	//�I�y���[�^���������Ė{���̃I�u�W�F�N�g���U���i�㗝�j
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
	//�R�s�[�R���X�g���N�^�֎~
	explicit CSafeSingletonUsing(CSafeSingletonUsing<T>&){}
	explicit CSafeSingletonUsing(CSafeSingletonUsing<T>*){}
	explicit CSafeSingletonUsing(T&){}
	explicit CSafeSingletonUsing(T*){}
	//�R�s�[�I�y���[�^�[�֎~
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

//�����\�[�X�}�l�[�W���N���X
class CResManager
{
	//�V���O���g���N���X�Ή�
	friend CSingleton<CResManager>;
public:
	static const CSingletonBase::E_TYPE SINGLETON_TYPE = CSingletonBase::SAFE_SINGLETON;
	static const std::size_t SAFE_SINGLETON_USING_STACK_MAX = 3;

private:
	//�R���X�g���N�^�̓v���C�x�[�g������
	CResManager():
		m_val(0)
	{
		printf("constructor!\n");
	}
	//�f�X�g���N�^
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

//�T�u����A
void subA()
{
	CSafeSingletonUsing<CResManager> res("subA");
	res->setVal(123);
}

//�T�u����B
void subB()
{
	CSafeSingletonUsing<CResManager> res("subB");
	printf("getVal()=%d\n", res->getVal());
	extern void subC();
	subC();
	printf("getVal()=%d\n", res->getVal());
	res.debugPrint();
}

//�T�u����C
void subC()
{
	CSafeSingletonUsing<CResManager> res("subC");
	res->setVal(456);
	CSafeSingletonInitializer<CResManager> res2("subC");
	CSafeSingletonUsing<CResManager> res3("subC2");
	CSingleton<CResManager> res4;
	res.debugPrint();
}

//�e�X�g
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

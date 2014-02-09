//--------------------------------------------------------------------------------
//���\�[�X�r���_�[�����e�X�g

#include <stdio.h>
#include <stdlib.h>
#include <atomic>

//--------------------------------------------------------------------------------
//�y�T���v���p�_�~�[�z���ʌ^�錾�Ƌ��ʊ֐�

//CRC32�^
typedef unsigned int CRC32;

//CRC�Z�o�֐�
CRC32 CRC(const char* str)
{
	return 123;//�_�~�[
}

//--------------------------------------------------------------------------------
//�y�T���v���p�_�~�[�z�V���O���g���N���X

//�V���O���g���A�N�Z�X�N���X�i�_�~�[�j
template<class T>
class CSingletonUsing
{
public:
	//�I�y���[�^
	T* operator->(){ return &m_instance; }//�A���[���Z�q
public:
	//�R���X�g���N�^
	CSingletonUsing(const char* name)
	{}
private:
	//�t�B�[���h
	static T m_instance;//�V���O���g���C���X�^���X
};

//�V���O���g��static�C���X�^���X�����p�}�N��
#define SINGLETON_INSTANCE(T) \
	T CSingletonUsing<T>::m_instance;

//--------------------------------------------------------------------------------
//���\�[�X�}�l�[�W������

//----------------------------------------
//�萔

//���\�[�X����
enum E_RES_ATTR
{
	RES_ATTR_MOVABLE = 0x00000000,//�Ĕz�u�\
	RES_ATTR_FIXED = 0x00000001,//�Ĕz�u�s��
};

//----------------------------------------
//�^

//���\�[�X�n���h��
struct HRES
{
	union
	{
		struct
		{
			unsigned int m_id;//�C�ӂ̎���ID
			CRC32 m_pathCRC;//�t�@�C���p�XCRC
		};
		unsigned long long m_key;//64bit�L�[
	};
	//�R���X�g���N�^
	HRES(unsigned int id, CRC32 path_crc) :
		m_id(id),
		m_pathCRC(path_crc)
	{}
	HRES(unsigned long long key) :
		m_key(key)
	{}
	//�f�t�H���g�R���X�g���N�^
	HRES()
	{}
};

//--------------------------------------------------------------------------------
//���\�[�X�r���_�[

//----------------------------------------
//�萔

//���\�[�X�r���h����
enum E_RES_BUILD_ATTR
{
	RES_TO_COPY_ONLY = 0x00000001,//�R�s�[�̂�
	RES_TO_BUILD = 0x00000000,//�\�z�����K�v
	
	RES_REQUIRED_FILE = 0x00000002,//���\�[�X�ɂ̓t�@�C�����K�v
	RES_NOT_REQUIRED_FILE = 0x00000000,//���\�[�X�ɂ̓t�@�C�����s�v
};

//�r���h����
enum E_BUILD_RESULT
{
	BUILD_IMPOSSIBLE = 0,//�r���h�E�R�s�[�s��
	BUILD_SUCCESS = 1,//�r���h����
	BUILD_RETRY = -1,//�r���h���s�F���g���C�v��
	BUILD_GIVEUP = -2,//�r���h���s�F���߂�
};

//----------------------------------------
//���\�[�X�\�z�v�����N���X
//�����\�[�X�t�@�C�����w�肵�č\�z��v�����邽�߂̃N���X
//���\�z��̃������̎w����\�i�ʏ�̓��\�[�X�r���_�[�ɂ���ċK�肳���j
//���{���̓��\�[�X�t�@�C���𔺂�Ȃ���������̃f�[�^��A
//�@���\�[�X�̈ˑ��֌W�A���\�[�X�D��x�A�\�z���g���C�̃^�C���A�E�g�A
//�@�������J�e�S���Ƃ����������������A���̃T���v���ł͂����܂őΉ����Ȃ�
class CResBuildReqInfo
{
public:
	//�萔
	static const int MEM_INFO_MAX = 2;//���������̍ő吔
public:
	//�f�[�^�^
	//���������^
	struct T_MEM_INFO
	{
		int m_memId;//������ID
		bool m_isDenyShare;//���L�֎~�i������ID���Ⴄ�������\�[�X�̋֎~�j
		bool m_isLocked;//���b�N�i�j���֎~�j
		void* m_loadedBuff;//�ǂݍ��݌�̃o�b�t�@
		//�R���X�g���N�^
		T_MEM_INFO(const int mem_id, const bool is_deny_share = true, bool is_locked = false) :
			m_memId(mem_id),
			m_isDenyShare(is_deny_share),
			m_isLocked(is_locked),
			m_loadedBuff(nullptr)
		{}
		//�f�t�H���g�R���X�g���N�^
		T_MEM_INFO(){}
	};
public:
	//�A�N�Z�b�T
	int getResTypeId() const { return m_resTypeId; }//���\�[�X���ID�擾
	int getBuilderTypeId() const { return m_builderTypeId; }//���\�[�X�r���_�[���ID�擾
public:
	//���\�b�h
	//���������ǉ�
	bool addMemInfo(const T_MEM_INFO&& info)
	{
		if (m_memInfoNum >= MEM_INFO_MAX)
			return false;
		m_memInfo[m_memInfoNum++] = info;
		return true;
	}
	//���������擾
	int getMemInfoNum() const { return m_memInfoNum; }
	T_MEM_INFO* getMemInfo(const int index)
	{
		if (index < 0 || index >= m_memInfoNum)
			return nullptr;
		return &m_memInfo[index];
	}
	//���������擾
	const T_MEM_INFO* getMemInfo(const int index) const
	{
		if (index < 0 || index >= m_memInfoNum)
			return nullptr;
		return &m_memInfo[index];
	}
	//���������X�V
	T_MEM_INFO* setMemInfo(const int index, const T_MEM_INFO&& info)
	{
		if (index < 0 || index >= m_memInfoNum)
			return nullptr;
		m_memInfo[index] = info;
		return &m_memInfo[index];
	}
	//��ʓI�ȃt�@�C�����\�[�X�n���h���쐬
	HRES makeNormalHandle() const
	{
		HRES handle(0, m_pathCRC);
		return handle;
	}
	////�n���h���쐬
	//HRES makeHandle() const
	//{
	//	CResBuiderProxy proxy(m_builderTypeId);
	//	return proxy.makeHandle(*this);
	//}
public:
	//�R���X�g���N�^
	//���\�z���郊�\�[�X�̃��\�[�X���ID�A���\�[�X�r���_�[���ID�ƃ��\�[�X�̃p�X��n��
	CResBuildReqInfo(const int res_type_id, const int builder_type_id, const char* path) :
		m_resTypeId(res_type_id),
		m_builderTypeId(builder_type_id),
		m_pathCRC(CRC(path)),
		m_memInfoNum(0)
	{
	}
	//�f�X�g���N�^
	~CResBuildReqInfo()
	{
	}
private:
	//�t�B�[���h
	int m_resTypeId;//���\�[�X���ID
	int m_builderTypeId;//���\�[�X�r���_�[���ID
	CRC32 m_pathCRC;//���\�[�X�p�X�iCRC�j
	T_MEM_INFO m_memInfo[MEM_INFO_MAX];//���\�[�X�\�z�p�̃��������
	int m_memInfoNum;
};

//----------------------------------------
//���\�[�X�\�z�v���N���X
template<class T>
class CResBuildReq : public CResBuildReqInfo
{
public:
	//���\�b�h
	//�n���h�����s
	HRES makeHandle() const
	{
		T builder;
		return builder.makeHandle(*this);
	}
public:
	//�R���X�g���N�^
	//���\�z���郊�\�[�X�̃p�X��n��
	CResBuildReq(const char* path) :
		CResBuildReqInfo(T::RES_TYPE_ID, T::BUILDER_TYPE_ID, path)
	{
		//���\�[�X�\�z�v�����̃f�t�H���g�ݒ�
		T::setDefaultMemInfo(*this);

		//���\�[�X�r���_�[�t�@�N�g���[�V���O���g������
		CResBuilderFactory<T>::createSingleton();
	}
	//�f�X�g���N�^
	~CResBuildReq()
	{
	}
};

//----------------------------------------
//���\�[�X�r���_�[�C���^�[�t�F�[�X�N���X
class IResBuider
{
public:
	//���\�b�h
	//�n���h���쐬
	virtual HRES makeHandle(const CResBuildReqInfo& req_info) = 0;
	//���\�[�X�\�z
	virtual E_BUILD_RESULT create(const CResBuildReqInfo& req_info) = 0;
	//���\�[�X�R�s�[
	virtual E_BUILD_RESULT copy(const CResBuildReqInfo& req_info, const void* src_res) = 0;
	//���\�[�X�j��
	virtual E_BUILD_RESULT destroy(void* res) = 0;
public:
	//�f�X�g���N�^
	virtual ~IResBuider()
	{}
};

//----------------------------------------
//���\�[�X�r���_�[�t�@�N�g���[���ۃN���X
class CAbstractResBuilderFactory
{
public:
	//�A�N�Z�b�T
	virtual int getBuilderTypeID() const = 0;//���\�[�X�r���_�[���ID�擾
	CAbstractResBuilderFactory* getNext() const { return m_next; }//���̃��\�[�X�r���_�[�t�@�N�g���[�擾
public:
	//���\�b�h
	//���\�[�X�r���_�[�\�z
	virtual IResBuider* createBuilder(const int builder_type_id, char* buff, const std::size_t buff_size) = 0;
	//���\�[�X�r���_�[�j��
	virtual bool deleteBuilder(const int builder_type_id, IResBuider* p) = 0;
	//���\�[�X�r���_�[�t�@�N�g���[�̐擪�m�[�h���擾
	static CAbstractResBuilderFactory* getFactoryHead() { return m_head; }
protected:
	//�t�B�[���h
	CAbstractResBuilderFactory* m_next;//���̃��\�[�X�r���_�[�t�@�N�g���[
	static std::atomic<CAbstractResBuilderFactory*> m_head;//���\�[�X�r���_�[�t�@�N�g���[�̐擪�m�[�h
};

//���\�[�X�r���_�[�t�@�N�g���[���ۃN���X�Fstatic�ϐ��̃C���X�^���X��
std::atomic<CAbstractResBuilderFactory*> CAbstractResBuilderFactory::m_head = nullptr;//���\�[�X�r���_�[�t�@�N�g���[�̐擪�m�[�h

//----------------------------------------
//���\�[�X�r���_�[�t�@�N�g���[�N���X
//�����\�[�X�r���_�[���\�z���邽�߂̃N���X�B
//�@�u�A�u�X�g���N�g�t�@�N�g���[�p�^�[���v�̎����B
//���Q�[�����Ŏg�p����郊�\�[�X�r���_�[�t�@�N�g���[��
//�@�S�ăV���O���g���Ƃ��ĕێ����A�A�����X�g�łȂ����Ă���B
//�����\�[�X�r���_�[�𐶐�����ۂ́A�t�@�N�g���[�̘A�����X�g�����ǂ���
//�@�^�C�vID�ɊY������t�@�N�g���[�ŃC���X�^���X�𐶐����ĕԂ��B
//�@�u�`�F�C���I�u���X�|���V�r���e�B�p�^�[���v�̉��p�B
//�I�y���[�^
template<class T>
class CResBuilderFactory : public CAbstractResBuilderFactory
{
	friend class CResBuildReq<T>;
	friend void* operator new(std::size_t size, CAbstractResBuilderFactory&, char* buff, const std::size_t buff_size);
	friend void operator delete(void* p, CAbstractResBuilderFactory&, char*, const std::size_t);
public:
	//�萔
	static const int RES_TYPE_ID = T::RES_TYPE_ID;//���\�[�X���ID
	static const E_RES_ATTR RES_ATTR = T::RES_ATTR;//���\�[�X����
	static const int BUILDER_TYPE_ID = T::BUILDER_TYPE_ID;//���\�[�X�r���_�[���ID
	static const E_RES_BUILD_ATTR TO_BUILD = T::TO_BUILD;//�\�z�ɂ̓r���h�������K�v���H
	static const E_RES_BUILD_ATTR REQUIRED_FILE = T::REQUIRED_FILE;//�\�z�ɂ̓t�@�C�����K�v���H
public:
	//�A�N�Z�b�T
	int getBuilderTypeID() const override { return BUILDER_TYPE_ID; }//���\�[�X�r���_�[���ID�擾
public:
	//���\�b�h
	//���\�[�X�r���_�[�\�z
	//���I�[�o�[���C�h
	IResBuider* createBuilder(const int builder_type_id, char* buff, const std::size_t buff_size) override
	{
		if (builder_type_id != BUILDER_TYPE_ID)
		{
			if (!m_next)
				return nullptr;
			//���\�[�X�r���_�[���ID���قȂ�ꍇ�A���̘A�����X�g�ɂ�����
			//���`�F�C���I�u���X�|���V�r���e�B�p�^�[��
			return m_next->createBuilder(builder_type_id, buff, buff_size);
		}
		return new(this, buff, buff_size) T();
	}
	//���\�[�X�r���_�[�j��
	//���I�[�o�[���C�h
	bool deleteBuilder(const int builder_type_id, IResBuider* p) override
	{
		if (builder_type_id != BUILDER_TYPE_ID)
		{
			if (!m_next)
				return nullptr;
			//���\�[�X�r���_�[���ID���قȂ�ꍇ�A���̘A�����X�g�ɂ�����
			//���`�F�C���I�u���X�|���V�r���e�B�p�^�[��
			return m_next->deleteBuilder(builder_type_id, p);
		}
		T* derived = dynamic_cast<T*>(p);
		if (!derived)
			return false;
		derived->~T();
		operator delete(derived, this, nullptr, 0);
		return true;
	}
private:
	//���\�b�h
	//���N���X�̃V���O���g���C���X�^���X����
	static void createSingleton()
	{
		if (m_this)
			return;

		//�V���O���g���C���X�^���X����
		m_this = new(m_this, m_buff, sizeof(m_buff))CResBuilderFactory<T>();
		
		//�A�����X�g�ɘA��
		//���X���b�h�Z�[�t�����b�N�t���[�ȘA����@
		m_this->m_next = m_head.load();
		while (!m_head.compare_exchange_weak(m_this->m_next, m_this));
		
		//ID�̏d���`�F�b�N
		{
			CAbstractResBuilderFactory* _this = m_this;
			CAbstractResBuilderFactory* node = m_head.load();
			while (node)
			{
				if (node != m_this && m_this->getBuilderTypeID() == node->getBuilderTypeID())
				{
					fprintf(stderr, "BUILDER_TYPE_ID(%d) is alread exist!\n", m_this->BUILDER_TYPE_ID);
				}
				node = node->getNext();
			}
		}
	}
private:
	//�t�B�[���h
	static CResBuilderFactory<T>* m_this;//���N���X�V���O���g���C���X�^���X�̃|�C���^
	static char m_buff[];//���N���X�V���O���g���C���X�^���X�̃o�b�t�@
};

//���\�[�X�r���_�[�t�@�N�g���[�e���v���[�g�N���X��static�C���X�^���X�����p
#define RESOURCE_BUILDER_FACTORY_INSTANCE(T) \
	CResBuilderFactory<T>* CResBuilderFactory<T>::m_this = nullptr; \
	char CResBuilderFactory<T>::m_buff[sizeof(CResBuilderFactory<T>)];

//----------------------------------------
//���\�[�X�r���_�[�t�@�N�g���[�����p�z�unew
void* operator new(std::size_t size, CAbstractResBuilderFactory*, char* buff, const std::size_t buff_size)
{
	if (size > buff_size)
		return nullptr;
	return buff;
}
//���\�[�X�r���_�[�t�@�N�g���[�����p�z�udelete
void operator delete(void* p, CAbstractResBuilderFactory*, char*, const std::size_t)
{}

//----------------------------------------
//���\�[�X�r���_�[�v���L�V�[�N���X
//�����\�[�X�r���_�[�̃C���X�^���X���\�z���邽�߂̃o�b�t�@�������A
//�@���\�[�X�r���_�[�Ƃ��ĐU��܂��N���X
//�@�i���[�J���ϐ��̃o�b�t�@�Ń��\�[�X�r���_�[�̃C���X�^���X�𐶐����邽�߂Ɏg�p����j
class CResBuiderProxy
{
public:
	//�萔
	static const size_t BUILDER_SIZE_MAX = 32;//���\�[�X�r���_�[�̍ő�T�C�Y�i�o�C�g�j
	//�����\�[�X�r���_�[�̓X�^�b�N�̃��������g�p����
	//���t�B�[���h����������Ȃ����\�[�X�r���_�[�̃T�C�Y��4�o�C�g
public:
	//���\�b�h
	//�n���h�����s
	//HRES makeHandle(const CResBuildReqInfo& req_info)
	//{
	//	if (!m_builder)
	//		return false;
	//	return m_builder->makeHandle(req_info);
	//}
	//���\�[�X�r���h
	E_BUILD_RESULT create(const CResBuildReqInfo& req_info)
	{
		if (!m_builder)
			return BUILD_IMPOSSIBLE;
		return m_builder->create(req_info);
	}
	//���\�[�X�R�s�[�r���h
	E_BUILD_RESULT copy(const CResBuildReqInfo& req_info, const void* src_res)
	{
		if (!m_builder || !src_res)
			return BUILD_IMPOSSIBLE;
		return m_builder->copy(req_info, src_res);
	}
	//���\�[�X�j��
	E_BUILD_RESULT destroy(void* res)
	{
		if (!m_builder)
			return BUILD_IMPOSSIBLE;
		return m_builder->destroy(res);
	}
public:
	//�R���X�g���N�^
	CResBuiderProxy(const int builder_type_id) :
		m_builderType(builder_type_id),
		m_builder(nullptr)
	{
		CAbstractResBuilderFactory* factory = CAbstractResBuilderFactory::getFactoryHead();
		if (factory)
			m_builder = factory->createBuilder(m_builderType, m_builderBuff, BUILDER_SIZE_MAX);
	}
	//�f�X�g���N�^
	~CResBuiderProxy()
	{
		CAbstractResBuilderFactory* factory = CAbstractResBuilderFactory::getFactoryHead();
		if (factory)
			factory->deleteBuilder(m_builderType, m_builder);
	}
private:
	//�t�B�[���h
	const int m_builderType;//�r���_�[���
	IResBuider* m_builder;//���\�[�X�r���_�[
	char m_builderBuff[BUILDER_SIZE_MAX];//���\�[�X�r���_�[�p�o�b�t�@
};

//--------------------------------------------------------------------------------
//�y�T���v���p�_�~�[�z���\�[�X�}�l�[�W���N���X

#include <vector>

//���\�[�X�}�l�[�W���N���X�i�_�~�[�j
class CResManager
{
public:
	//���\�b�h
	//�r���h�v��
	//�����\�[�X�ɃA�N�Z�X���邽�߂̃n���h����Ԃ�
	template<class T>
	HRES request(T& req)
	{
		HRES handle = req.makeHandle();
		requestCore(req);
		return handle;
	}
	//�S�v�����r���h�i�_�~�[�j
	//���{�����̂悤�ȃ��\�b�h�ł͂Ȃ��A���̃r���h�������W���u�Ƃ��ē�������
	void createAll()
	{
		for (CResBuildReqInfo& build_info : m_reqList)
		{
			CResBuiderProxy proxy(build_info.getBuilderTypeId());
			proxy.create(build_info);
		}
	}
	//�S�v�����R�s�[�Ńr���h�i�_�~�[�j
	//���{�����̂悤�ȃ��\�b�h�ł͂Ȃ��A���̃r���h�������W���u�Ƃ��ē�������
	void copyAll()
	{
		for (CResBuildReqInfo& build_info : m_reqList)
		{
			CResBuiderProxy proxy(build_info.getBuilderTypeId());
			void* src_res_dummy = "";
			proxy.copy(build_info, src_res_dummy);
		}
	}
	//�S���\�[�X��j���i�_�~�[�j
	//���{�����̂悤�ȃ��\�b�h�ł͂Ȃ��A���̔j���������W���u�Ƃ��ē�������
	void destroyAll()
	{
		for (CResBuildReqInfo& build_info : m_reqList)
		{
			CResBuiderProxy proxy(build_info.getBuilderTypeId());
			void* res_dummy = "";
			proxy.destroy(res_dummy);
		}
	}
private:
	void requestCore(CResBuildReqInfo& req)
	{
		m_reqList.push_back(req);
	}
private:
	//�t�B�[���h
	std::vector<CResBuildReqInfo> m_reqList;//�r���h�v�����X�g
};

//���\�[�X�}�l�[�W���V���O���g���C���X�^���X
SINGLETON_INSTANCE(CResManager);

//--------------------------------------------------------------------------------
//�y�T���v���z�^�C�g���ŗL�̃��\�[�X�r���_�[�N���X

//----------------------------------------
//�萔�F���\�[�X���ID
enum E_RES_TYPE_ID
{
	RES_UNKNOWN = 0,
	RES_MODEL,//���f��
	RES_TEXTURE,//�e�N�X�`��
};

//----------------------------------------
//�萔�F���\�[�X�r���_�[���ID
enum E_BUILDER_TYPE_ID
{
	BUILDER_UNKNOWN = 0,
	BUILDER_MODEL,//���f���\�z
	BUILDER_TEXTURE,//�e�N�X�`���\�z
};

//----------------------------------------
//�萔�F������ID
enum E_MEM_ID
{
	MEM_MAIN_MODEL,//���C���������F���f�����p
	MEM_GPU_MODEL,//GPU�������F���f���\�z�p
	MEM_GPU_TEX,//GPU�������F�e�N�X�`���\�z�p
};

//----------------------------------------
//�Ǝ����\�[�X�r���_�[�N���X�F���f���p
//���r���h���s���ɁA�r���h�X���b�h�������C���X�^���X�𐶐�����
//�@create() ���\�b�h�����s����B
//��create() ���\�b�h�̃p�����[�^ CResBuildReqInfo �ɁA
//�@�ǂݍ��񂾃t�@�C���̃o�b�t�@��A�\�z��̃��������Ȃǂ��i�[����Ă���
//���f�t�H���g�R���X�g���N�^�����g���Ȃ�
//���t�B�[���h�͍D���ɒǉ����ėǂ����A
//�@CResBuiderProxy::BUILDER_SIZE_MAX �𒴂���T�C�Y�͕s�B
//�����\�[�X�r���_�[�͎��s�̓s�x�C���X�^���X�𐶐����邪�A
//�@CResBuiderProxy�ɂ���ă��[�J���ϐ��Ƃ��Đ��������B
class CModelResourceBuilder : public IResBuider
{
public:
	//�萔
	//���K�{
	static const E_RES_TYPE_ID RES_TYPE_ID = RES_MODEL;//���\�[�X���ID
	static const E_RES_ATTR RES_ATTR = RES_ATTR_MOVABLE;//���\�[�X�����F�Ĕz�u�\
	static const E_BUILDER_TYPE_ID BUILDER_TYPE_ID = BUILDER_MODEL;//���\�[�X�r���_�[���ID
	static const E_RES_BUILD_ATTR TO_BUILD = RES_TO_BUILD;//�\�z�ɂ̓r���h�������K�v���H
	static const E_RES_BUILD_ATTR REQUIRED_FILE = RES_REQUIRED_FILE;//�\�z�ɂ̓t�@�C�����K�v���H
public:
	//���\�b�h
	//�����������쐬�i�f�t�H���g�ݒ�j
	//���K�{
	static void setDefaultMemInfo(CResBuildReqInfo& req_info)
	{
		req_info.addMemInfo(CResBuildReqInfo::T_MEM_INFO(MEM_MAIN_MODEL));
		req_info.addMemInfo(CResBuildReqInfo::T_MEM_INFO(MEM_GPU_MODEL));
	}
public:
	//���\�b�h
	//�n���h�����s
	//���I�[�o�[���C�h
	HRES makeHandle(const CResBuildReqInfo& req_info) override
	{
		return req_info.makeNormalHandle();
	}
	//���\�[�X�\�z
	//���I�[�o�[���C�h
	E_BUILD_RESULT create(const CResBuildReqInfo& req_info) override
	{
		printf("CModelResourceBuilder::create(%d, %d)\n", req_info.getResTypeId(), req_info.getBuilderTypeId());
		return BUILD_SUCCESS;
	}
	//���\�[�X�R�s�[
	//���I�[�o�[���C�h
	E_BUILD_RESULT copy(const CResBuildReqInfo& req_info, const void* src_res) override
	{
		printf("CModelResourceBuilder::copy(%d, %d, %p)\n", req_info.getResTypeId(), req_info.getBuilderTypeId(), src_res);
		return BUILD_SUCCESS;
	}
	//���\�[�X�j��
	//���I�[�o�[���C�h
	E_BUILD_RESULT destroy(void* res) override
	{
		printf("CModelResourceBuilder::destroy(%p)\n", res);
		return BUILD_SUCCESS;
	}
public:
	//�R���X�g���N�^
	CModelResourceBuilder()
	{
	}
	//�f�X�g���N�^
	~CModelResourceBuilder() override
	{
	}
};

//���\�[�X�r���_�[�t�@�N�g���[�V���O���g����static�C���X�^���X��
RESOURCE_BUILDER_FACTORY_INSTANCE(CModelResourceBuilder);

//----------------------------------------
//�Ǝ����\�[�X�r���_�[�N���X�F�e�N�X�`���p
class CTextureResourceBuilder : public IResBuider
{
public:
	//�萔
	//���K�{
	static const E_RES_TYPE_ID RES_TYPE_ID = RES_TEXTURE;//���\�[�X���ID
	static const E_RES_ATTR RES_ATTR = RES_ATTR_MOVABLE;//���\�[�X�����F�Ĕz�u�\
	static const E_BUILDER_TYPE_ID BUILDER_TYPE_ID = BUILDER_TEXTURE;//���\�[�X�r���_�[���ID
	static const E_RES_BUILD_ATTR TO_BUILD = RES_TO_COPY_ONLY;//�\�z�ɂ̓r���h�������K�v���H
	static const E_RES_BUILD_ATTR REQUIRED_FILE = RES_REQUIRED_FILE;//�\�z�ɂ̓t�@�C�����K�v���H
public:
	//���\�b�h
	//�����������쐬�i�f�t�H���g�ݒ�j
	//���K�{
	static void setDefaultMemInfo(CResBuildReqInfo& req_info)
	{
		req_info.addMemInfo(CResBuildReqInfo::T_MEM_INFO(MEM_GPU_TEX));
	}
public:
	//���\�b�h
	//�n���h�����s
	//���I�[�o�[���C�h
	HRES makeHandle(const CResBuildReqInfo& req_info) override
	{
		return req_info.makeNormalHandle();
	}
	//���\�[�X�\�z
	//���I�[�o�[���C�h
	E_BUILD_RESULT create(const CResBuildReqInfo& req_info) override
	{
		printf("CTextureResourceBuilder::create(%d, %d)\n", req_info.getResTypeId(), req_info.getBuilderTypeId());
		return BUILD_SUCCESS;
	}
	//���\�[�X�R�s�[
	//���I�[�o�[���C�h
	E_BUILD_RESULT copy(const CResBuildReqInfo& req_info, const void* src_res) override
	{
		printf("CTextureResourceBuilder::copy(%d, %d, %p)\n", req_info.getResTypeId(), req_info.getBuilderTypeId(), src_res);
		return BUILD_SUCCESS;
	}
	//���\�[�X�j��
	//���I�[�o�[���C�h
	E_BUILD_RESULT destroy(void* res) override
	{
		printf("CTextureResourceBuilder::destroy(%p)\n", res);
		return BUILD_SUCCESS;
	}
public:
	//�R���X�g���N�^
	CTextureResourceBuilder()
	{
	}
	//�f�X�g���N�^
	~CTextureResourceBuilder() override
	{
	}
};

//���\�[�X�r���_�[�t�@�N�g���[�V���O���g����static�C���X�^���X��
RESOURCE_BUILDER_FACTORY_INSTANCE(CTextureResourceBuilder);

//--------------------------------------------------------------------------------
//�y�T���v���z�r���h�v������

//----------------------------------------
//�r���h���N�G�X�g�@
void func1()
{
	//���f�����\�[�X�̃r���h�v�������\�z
	CResBuildReq<CModelResourceBuilder> req("/data/chara/x0010.mdl");

	//�r���h�v��
	CSingletonUsing<CResManager> res_man("func1");//���\�[�X�}�l�[�W���V���O���g���ɃA�N�Z�X
	HRES handle = res_man->request(req);
}

//----------------------------------------
//�r���h���N�G�X�g�A
void func2()
{
	//�e�N�X�`�����\�[�X�̃r���h�v�������\�z
	CResBuildReq<CTextureResourceBuilder> req("/data/chara/x0010.tex");
	req.getMemInfo(0)->m_isLocked = true;//�������ݒ�ύX

	//�r���h�v��
	CSingletonUsing<CResManager> res_man("func2");//���\�[�X�}�l�[�W���V���O���g���ɃA�N�Z�X
	HRES handle = res_man->request(req);
}

//--------------------------------------------------------------------------------
//�y�T���v���z�r���h����

//���\�[�X�\�z�����i�_�~�[�j
void createAll()
{
	//�S�v�����r���h
	CSingletonUsing<CResManager> res_man("createAll");//���\�[�X�}�l�[�W���V���O���g���ɃA�N�Z�X
	res_man->createAll();
}

//���\�[�X�R�s�[�����i�_�~�[�j
void copyAll()
{
	//�S�v�����r���h
	CSingletonUsing<CResManager> res_man("copyAll");//���\�[�X�}�l�[�W���V���O���g���ɃA�N�Z�X
	res_man->copyAll();
}

//���\�[�X�j�������i�_�~�[�j
void destroyAll()
{
	//�S�v�����r���h
	CSingletonUsing<CResManager> res_man("destroyAll");//���\�[�X�}�l�[�W���V���O���g���ɃA�N�Z�X
	res_man->destroyAll();
}

//--------------------------------------------------------------------------------
//�y�T���v���z�e�X�g���C��
int main(const int argc, const char* argv[])
{
	//�r���h�v��
	printf("----- �r���h�v�� -----\n");
	func1();
	func2();
	
	//�r���h���s
	printf("----- �r���h���s -----\n");
	createAll();

	//�R�s�[���s
	printf("----- �R�s�[���s -----\n");
	copyAll();

	//���\�[�X�j��
	printf("----- ���\�[�X�j�� -----\n");
	destroyAll();

	//�I��
	return EXIT_SUCCESS;
}

// End of file

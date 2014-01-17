#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <glm/glm.hpp>

//================================================================================
//Observer�p�^�[��

//----------------------------------------
//�y�����zC++11��Ή��̃R���p�C���Ȃ�Aoverride, final �L�[���[�h���������Ȃ��}�N���ő�p
//#define override
//#define final

//----------------------------------------

//--------------------
//�y���C�u�������z�Ϗ��C���^�[�t�F�[�X
template<class T>
class IDelegate
{
public:
	//�X�V����
	virtual void update(T& target) = 0;
};

//--------------------
//�y���C�u�������z�Ϗ��I�u�W�F�N�g�o�^�N���X
template<class T>
class CDelegateRegister
{
public:
	//�Ϗ��I�u�W�F�N�g�o�^
	void registDelegate(IDelegate<T>* delegate){ m_delegate = delegate; }
	//�X�V����
	void update()
	{
		printf("CDelegateRegister<T>::update() : m_delete->update()\n");
		if (m_delegate)
		{
			m_delegate->update(m_target);
		}
	}
public:
	//�R���X�g���N�^
	CDelegateRegister(T& target) : m_target(target), m_delegate(nullptr) {}
private:
	//�t�B�[���h
	T& m_target;//�ΏۃI�u�W�F�N�g
	IDelegate<T>* m_delegate;//�Ϗ��I�u�W�F�N�g
};

//--------------------
//�y���C�u�������z���ʃV�X�e���P�N���X
class CCommonSystem1
{
public:
	//�Ϗ��I�u�W�F�N�g�o�^
	void registDelegate(IDelegate<CCommonSystem1>* delegate){ m_delegateRegister.registDelegate(delegate); }
	//�X�V����
	void update()
	{
		printf("CCommonSystem1::update()\n");

		//�X�V�����̈Ϗ�
		m_delegateRegister.update();
	}
	//���b�Z�[�W�擾
	const char* getMessage() const{ return "CCommonSystem1's message";  }
public:
	//�R���X�g���N�^
	CCommonSystem1() : m_delegateRegister(*this) {}
private:
	//�t�B�[���h
	CDelegateRegister<CCommonSystem1> m_delegateRegister;//�Ϗ��I�u�W�F�N�g
};

//--------------------
//�y���C�u�������z���ʃV�X�e���Q�N���X
class CCommonSystem2
{
public:
	//�Ϗ��I�u�W�F�N�g�o�^
	void registDelegate(IDelegate<CCommonSystem2>* delegate){ m_delegateRegister.registDelegate(delegate); }
	//�X�V����
	void update()
	{
		printf("CCommonSystem2::update()\n");

		//�X�V�����̈Ϗ�
		m_delegateRegister.update();
	}
	//�V�X�e�����擾
	const char* getSystemName() const{ return "Common System 2"; }
public:
	//�R���X�g���N�^
	CCommonSystem2() : m_delegateRegister(*this) {}
private:
	//�t�B�[���h
	CDelegateRegister<CCommonSystem2> m_delegateRegister;//�Ϗ��I�u�W�F�N�g
};

//----------------------------------------

//--------------------
//�y�^�C�g�����z�Ǝ��V�X�e��
class CMySystem
{
public:
	//���ʏ����P�����̊g���X�V����
	void updateSystem1(CCommonSystem1& target)
	{
		printf("CMySystem::updateSystem1() : target.getMessage()=\"%s\"\n", target.getMessage());
	}
	//���ʏ����Q�����̊g���X�V����
	void updateSystem2(CCommonSystem2& target)
	{
		printf("CMySystem::updateSystem2() : target.getSystemName()=\"%s\"\n", target.getSystemName());
	}
private:
	//���ʏ����V�X�e���P�����̃I�u�U�[�o�[�i�Ϗ��I�u�W�F�N�g�j
	class CObserver1 : public IDelegate<CCommonSystem1>
	{
	public:
		//�X�V����
		void update(CCommonSystem1& target) override
		{
			m_this.updateSystem1(target);
		}
	public:
		CObserver1(CMySystem& me) : m_this(me) {}
	private:
		CMySystem& m_this;
	};
	//���ʏ����V�X�e���Q�����̃I�u�U�[�o�[�i�Ϗ��I�u�W�F�N�g�j
	class CObserver2 : public IDelegate<CCommonSystem2>
	{
	public:
		//�X�V����
		void update(CCommonSystem2& target) override
		{
			m_this.updateSystem2(target);
		}
	public:
		CObserver2(CMySystem& me) : m_this(me) {}
	private:
		CMySystem& m_this;
	};
public:
	//�R���X�g���N�^
	CMySystem(CCommonSystem1& sys1, CCommonSystem2& sys2) :
		m_observer1(*this),
		m_observer2(*this)
	{
		//�I�u�U�[�o�[�o�^
		sys1.registDelegate(&m_observer1);
		sys2.registDelegate(&m_observer2);
	}
private:
	//�t�B�[���h
	CObserver1 m_observer1;//���ʏ����V�X�e���P�����̃I�u�U�[�o�[
	CObserver2 m_observer2;//���ʏ����V�X�e���Q�����̃I�u�U�[�o�[
};

//----------------------------------------
//Observer�p�^�[���e�X�g���C���֐�
void testObserver()
{
	printf("\n- testObserver() -\n\n");

	CCommonSystem1 sys1; //���ʃV�X�e���P
	CCommonSystem2 sys2; //���ʃV�X�e���Q
	CMySystem my_sys(sys1, sys2); //�Ǝ��V�X�e��

	//���ʃV�X�e���̍X�V����
	sys1.update();
	sys2.update();
	//�����ʃV�X�e�����̏������s���ɁA�u�Ǝ��V�X�e���v�̃I�u�U�[�o�[�ɏ������Ϗ������
}

//================================================================================
//Adapter�p�^�[��

//----------------------------------------
//�y�����zC++11��Ή��̃R���p�C���Ȃ�Aoverride, final �L�[���[�h���������Ȃ��}�N���ő�p
//#define override
//#define final

//----------------------------------------
//�y�����z�x�N�g�����Z�^��`
typedef glm::vec3 vec3;//GLM���p

//----------------------------------------
//�y�����z���ʊ֐�
template<typename T, std::size_t N1> std::size_t lengthOfArray(const T(&var)[N1]){ return N1; } //�z��̗v�f����Ԃ��i�^���S�Łj
//template<typename T> T max(T var1, Tvar2){ return var1 > var2 ? var1 : var2; }                //�傫�����̒l��Ԃ��i�^���S�Łj
//#define lengthOfArray(var) (sizeof(var1) / sizeof(var1[0])                                    //�z��̗v�f����Ԃ�
#define max(var1, var2) (var1 > var2 ? var1 : var2)                                             //�傫�����̒l��Ԃ�

//----------------------------------------

//--------------------
//NPC
class CNPC //�����̋��ʃC���^�[�t�F�[�X���������Ă��Ȃ�
{
public:
	const char* getName() const { return m_name; }       //���O���擾
	const vec3& getPos() const { return m_pos; }         //�ʒu���擾
	void setPos(const vec3 pos) { m_pos = pos; }         //�ʒu���X�V
	float getRotY() const { return m_rot_y; }            //Y���̌������擾
	void setRotY(const float rot_y) { m_rot_y = rot_y; } //Y���̌������X�V
public:
	//�R���X�g���N�^
	CNPC(const char* name, const vec3 pos, const float rot_y) :
		m_name(name),
		m_pos(pos),
		m_rot_y(rot_y)
	{}
private:
	//�t�B�[���h
	const char* m_name;//���O
	vec3 m_pos;        //�ʒu
	float m_rot_y;     //Y���̌���
};

//--------------------
//��
class CTBox //�����̋��ʃC���^�[�t�F�[�X���������Ă��Ȃ�
{
public:
	int getID() const { return m_id; }           //ID���擾
	const vec3& getPos() const { return m_pos; } //�ʒu���擾
	float getRotY() const { return m_rot_y; }    //Y���̌������擾
public:
	//�R���X�g���N�^
	CTBox(const int id, const vec3 pos, const float rot_y) :
		m_id(id),
		m_pos(pos),
		m_rot_y(rot_y)
	{}
private:
	//�t�B�[���h
	const int m_id;     //ID
	const vec3 m_pos;   //�ʒu
	const float m_rot_y;//Y���̌���
};

//----------------------------------------

//--------------------
//�O���V�X�e���P
namespace other_system1
{
	//�ϐ�
	static int s_npc_num = 0;
	static CNPC* s_npc[10];
	
	//������
	void init()
	{
		s_npc[s_npc_num++] = new CNPC("���Y", vec3(10.f, 11.f, 12.f), 0.1f);
		s_npc[s_npc_num++] = new CNPC("���Y", vec3(20.f, 21.f, 22.f), 0.2f);
		s_npc[s_npc_num++] = new CNPC("�O�Y", vec3(30.f, 31.f, 32.f), 0.3f);
		s_npc[s_npc_num++] = new CNPC("�l�N", vec3(40.f, 41.f, 42.f), 0.4f);
		s_npc[s_npc_num++] = new CNPC("�ܘN", vec3(50.f, 51.f, 52.f), 0.5f);
	}
	
	//���ӂ�NPC�������W
	int findAroundNPC(CNPC* ref_npc[], const int ref_max)
	{
		int ref_num = 0;
		for (int index = 0; index < s_npc_num && index < ref_max; ++index)
		{
			ref_npc[ref_num++] = s_npc[index];
		}
		return ref_num;
	}
}

//--------------------
//�O���V�X�e���Q
namespace other_system2
{
	//�ϐ�
	static int s_tbox_num = 0;
	static CTBox* s_tbox[10];

	//������
	void init()
	{
		s_tbox[s_tbox_num++] = new CTBox(101, vec3(15.f, 15.f, 15.f), 1.1f);
		s_tbox[s_tbox_num++] = new CTBox(102, vec3(25.f, 25.f, 25.f), 1.2f);
		s_tbox[s_tbox_num++] = new CTBox(103, vec3(35.f, 35.f, 35.f), 1.3f);
		s_tbox[s_tbox_num++] = new CTBox(104, vec3(45.f, 45.f, 45.f), 1.4f);
		s_tbox[s_tbox_num++] = new CTBox(105, vec3(55.f, 55.f, 55.f), 1.5f);
	}

	//���ӂ̕󔠏������W
	int findAroundTBox(CTBox* ref_tbox[], const int ref_max)
	{
		int ref_num = 0;
		for (int index = 0; index < s_tbox_num && index < ref_max; ++index)
		{
			ref_tbox[ref_num++] = s_tbox[index];
		}
		return ref_num;
	}
}

//----------------------------------------

//--------------------
//�^�[�Q�b�g�p�A�_�v�^�[�C���^�[�t�F�[�X
class ITargetAdapter
{
public:
	virtual void getIdentifier(char* buff, const size_t buff_size) const = 0;//���ʏ����擾
	virtual const vec3& getPos() const = 0;                                  //�ʒu���擾
	virtual float getRotY() const = 0;                                       //Y���̌������擾
};

//--------------------
//NPC�����^�[�Q�b�g�p�A�_�v�^�[
class CTargetAdapterNPC : public ITargetAdapter
{
public:
	//���ʏ����擾
	void getIdentifier(char* buff, const size_t buff_size) const override
	{
		sprintf_s(buff, buff_size, "NPC\"%s\"", m_npc.getName());
	}
	//�ʒu���擾
	const vec3& getPos() const override
	{ 
		return m_npc.getPos();
	}
	//Y���̌������擾
	float getRotY() const override
	{
		return m_npc.getRotY();
	}
public:
	//�R���X�g���N�^
	CTargetAdapterNPC(CNPC& npc) :
		m_npc(npc)
	{}
private:
	//�t�B�[���h
	CNPC& m_npc;//NPC
};

//--------------------
//�󔠌����^�[�Q�b�g�p�A�_�v�^�[
class CTargetAdapterTBox : public ITargetAdapter
{
public:
	//���ʏ����擾
	void getIdentifier(char* buff, const size_t buff_size) const override
	{
		sprintf_s(buff, buff_size, "��(%d)", m_tbox.getID());
	}
	//�ʒu���擾
	const vec3& getPos() const override
	{
		return m_tbox.getPos();
	}
	//Y���̌������擾
	float getRotY() const override
	{
		return m_tbox.getRotY();
	}
public:
	//�R���X�g���N�^
	CTargetAdapterTBox(CTBox& tbox) :
		m_tbox(tbox)
	{}
private:
	//�t�B�[���h
	CTBox& m_tbox;//��
};

//----------------------------------------

//--------------------
//�^�[�Q�b�g�����p�z�unew
class CTargetCollector;
void* operator new(std::size_t size, const CTargetCollector*, void* buff){ return buff; }//�R���X�g���N�^���s�p�ɗ^����ꂽ�|�C���^�[�����̂܂ܕԂ�����
void operator delete(void* mem, const CTargetCollector*, void* buff){}//�_�~�[�F�Ȃɂ��Ȃ��i�z�unew��delete�͈�΂œo�^���Ȃ��ƃ_���j

//--------------------
//�^�[�Q�b�g���W�����N���X
class CTargetCollector
{
public:
	//���ӂ̃^�[�Q�b�g�������W
	void findAroundTarget()
	{
		//���ӂ�NPC�������W
		CNPC* ref_npc[4];
		const int ref_npc_num = other_system1::findAroundNPC(ref_npc, lengthOfArray(ref_npc));

		//���ӂ̕󔠏������W
		CTBox* ref_tbox[3];
		const int ref_tbox_num = other_system2::findAroundTBox(ref_tbox, lengthOfArray(ref_tbox));

		//�^�[�Q�b�g���ɒu������
		m_numTargets = 0;
		{
			//NPC�����^�[�Q�b�g���ɒu������
			for (int index = 0; index < ref_npc_num; ++index)
			{
				if (m_numTargets < MAX_TARGETS)
				{
					try
					{
						m_target[m_numTargets] = new(this, m_targetBuff[m_numTargets]) CTargetAdapterNPC(*ref_npc[index]);
						++m_numTargets;
					}
					catch (...)
					{
						fprintf(stderr, "CTargetAdapterNPC allocation failure.\n");
					}
				}
			}
			//�󔠏����^�[�Q�b�g���ɒu������
			for (int index = 0; index < ref_tbox_num; ++index)
			{
				if (m_numTargets < MAX_TARGETS)
				{
					try
					{
						m_target[m_numTargets] = new(this, m_targetBuff[m_numTargets]) CTargetAdapterTBox(*ref_tbox[index]);
						++m_numTargets;
					}
					catch (...)
					{
						fprintf(stderr, "CTargetAdapterTBox allocation failure.\n");
					}
				}
			}
			//�^�[�Q�b�g���̃\�[�g�i�X�N���[�����W�ŉ����тɁj
			//...�̑���ɃV���b�t��
			time_t timer;
			time(&timer);
			srand(static_cast<unsigned int>(timer));
			const int shuffle_num = rand() % 20;
			for (int num = 0; num < shuffle_num; ++num)
			{
				const int index1 = rand() % m_numTargets;
				const int index2 = rand() % m_numTargets;
				ITargetAdapter* target_temp = m_target[index1];
				m_target[index1] = m_target[index2];
				m_target[index2] = target_temp;
			}
		}
	}
	//�^�[�Q�b�g�����擾
	ITargetAdapter* getTarget(const int index)
	{
		if (index < 0 || index >= m_numTargets)
			return nullptr;
		return m_target[index];
	}
	//�^�[�Q�b�g��񐔂��擾
	int getTargetNum() const{ return m_numTargets; }
public:
	//�R���X�g���N�^
	CTargetCollector() :
		m_numTargets(0)
	{}
private:
	//�t�B�[���h
	static const std::size_t MAX_TARGETS = 10;                                                                       //�^�[�Q�b�g���̍ő吔
	static const std::size_t MAX_SIZE_OF_TARGET_ADAPTER = max(sizeof(CTargetAdapterNPC), sizeof(CTargetAdapterTBox));//�^�[�Q�b�g���p�o�b�t�@�̃T�C�Y
	char m_targetBuff[MAX_TARGETS][MAX_SIZE_OF_TARGET_ADAPTER];//�^�[�Q�b�g���p�̃o�b�t�@
	ITargetAdapter* m_target[MAX_TARGETS];                     //�^�[�Q�b�g���
	int m_numTargets;                                          //�^�[�Q�b�g��
};

//----------------------------------------
//Adapter�p�^�[���e�X�g���C���֐�
void testAdapter()
{
	printf("\n- testAdapter() -\n\n");
	
	//�O���V�X�e���P������
	other_system1::init();

	//�O���V�X�e���Q������
	other_system2::init();

	//���ӂ̃^�[�Q�b�g�������W
	CTargetCollector target_coll;
	target_coll.findAroundTarget();

	//�^�[�Q�b�g����\��
	//���^�[�Q�b�g��NPC���󔠂��C�ɂ����ꗥ�̏������s���Ă���
	for (int index = 0; index < target_coll.getTargetNum(); ++index)
	{
		ITargetAdapter* target = target_coll.getTarget(index);
		if (target)
		{
			//�A�_�v�^�[�̍�p�ɂ��A���ۂɂ�NPC�ƕ󔠂̂��ꂼ��ŗL�̏��������s����Ă���
			char identifier[128];
			target->getIdentifier(identifier, sizeof(identifier));
			const vec3& pos = target->getPos();
			const float rot_y = target->getRotY();
			printf("[%d] \"%s\" pos=(%.1f, %.1f, %.1f) rot=(%.1f)\n", index, identifier, pos[0], pos[1], pos[2], rot_y);
		}
	}
}

//================================================================================
//Proxy�p�^�[��(1)

//----------------------------------------
//�y�����zC++11��Ή��̃R���p�C���Ȃ�Aoverride, final �L�[���[�h���������Ȃ��}�N���ő�p
//#define override
//#define final

//----------------------------------------

//--------------------
//�L�����N�^�[�C���^�[�t�F�[�X�N���X
class CCharacter;
class ICharacter
{
public:
	//�����X�V
	virtual void update() = 0;
	//�`�揈��
	virtual void draw() = 0;
	//�\�z�ς݃t���O�擾
	virtual bool isBuilt() const = 0;
	//�{�̎擾
	virtual const CCharacter* getReal() const = 0;
};

//--------------------
//�L�����N�^�[�N���X
class CCharacter : public ICharacter
{
public:
	//�����X�V
	void update() override
	{
		//�����o��
		++m_step;
		
		//2�X�e�b�v�ȏ�o�߂�����A1/4�̊m���ō\�z�����Ƃ������Ƃɂ���
		if (m_step > 2 && rand() % 4 == 0)
		{
			m_isBuilt = true;
		}
	}
	//�`�揈��
	void draw() override
	{
		printf("This is real \"%s\"!\n", m_name);
	}
	//�\�z�ς݃t���O�擾
	bool isBuilt() const override
	{
		return m_isBuilt;
	}
	//�{�̎擾
	const CCharacter* getReal() const override
	{
		return this;
	}
public:
	//�A�N�Z�b�T
	const char* getName() const { return m_name; }//���O�擾
	int getStep() const { return m_step; }        //�����X�e�b�v�擾
public:
	//�R���X�g���N�^
	CCharacter(const char* name) :
		m_name(name),
		m_step(0),
		m_isBuilt(false)
	{}
private:
	//�t�B�[���h
	const char* m_name;//���O
	int m_step;//�����X�e�b�v
	bool m_isBuilt;//�\�z�ς݃t���O
};

//----------------------------------------

//--------------------
//���[�f�B���O���̃L�����N�^�[�㗝�N���X
class CCharacterProxy : public ICharacter
{
public:
	//�����X�V
	virtual void update() override
	{
		m_realObj->update();//�Ϗ�
	}
	//�`�揈��
	virtual void draw()
	{
		printf("Now is loading \"%s\"... (step=%d)\n", m_realObj->getName(), m_realObj->getStep());
	}
	//�\�z�ς݃t���O�擾
	bool isBuilt() const override
	{
		return false;
	}
	//�{�̎擾
	const CCharacter* getReal() const override
	{
		return m_realObj;
	}
public:
	//�{���̎��̂��Z�b�g
	void setRealObj(CCharacter* real_obj)
	{
		m_realObj = real_obj;
	}
public:
	//�R���X�g���N�^
	CCharacterProxy() :
		m_realObj(nullptr)
	{}
private:
	//�t�B�[���h
	CCharacter* m_realObj;//�{���̎���
};

//--------------------
//�L�����N�^�[�R���N�V����
class CCharacterCollection
{
public:
	//--------------------
	//�C�e���[�^�[�N���X
	class CIterator
	{
	public:
		//�C�e���[�^�[�p�^�錾
		typedef CIterator type;
		typedef ICharacter* value_type;
	public:
		//�C�e���[�^�[�p�I�y���[�^�[
		operator value_type() { return m_chara; }            //�L���X�g
		operator const value_type() const { return m_chara; }//�L���X�g
		value_type operator->() { return m_chara; }             //�Q��
		const value_type operator->() const { return m_chara; } //const�Q��
		ICharacter& operator*() { return *m_chara; }            //���̉�
		const ICharacter& operator*() const { return *m_chara; }//const���̉�
		type& operator++() { ++m_index; m_chara = m_coll[m_index]; return *this; }//�O�u�C���N�������g
		type operator++(int) { type prev = *this; ++(*this); return prev; }       //��u�C���N�������g
		type& operator--() { --m_index; m_chara = m_coll[m_index]; return *this; }//�O�u�f�N�������g
		type operator--(int) { type prev = *this; --(*this); return prev; }       //��u�f�N�������g
		bool operator==(const type& ite) const//��r
		{
			if (m_chara == nullptr && ite.m_chara == nullptr)
				return true;
			if (m_chara == nullptr || ite.m_chara == nullptr)
				return false;
			return m_chara->getReal() == ite->getReal();
		}
	public:
		//�R���X�g���N�^
		CIterator(CCharacterCollection& coll, const int index) :
			m_coll(coll),
			m_index(index)
		{
			m_chara = m_coll[index];
		}
	private:
		//�t�B�[���h
		CCharacterCollection& m_coll;//�L�����N�^�[�R���N�V����
		int m_index;                 //�R���N�V�����̃J�����g�C���f�b�N�X
		ICharacter* m_chara;         //�L�����N�^�[�I�u�W�F�N�g
	};

public:
	//�C�e���[�^�\�p���\�b�h
	CIterator begin() { CIterator ite(*this, 0); return ite; }       //�擪�C�e���[�^�[��Ԃ�
	CIterator end() { CIterator ite(*this, m_charaNum); return ite; }//�I�[�C�e���[�^�[��Ԃ�
	bool empty() const { return m_charaNum == 0; }                   //�v�f���󂩁H
	int size() const { return m_charaNum; }                          //�v�f����Ԃ�
	ICharacter* operator[](const int index)                          //�v�f��Ԃ��@�������Ńv���L�V�[�ɑΉ�
	{
		if (index < 0 || index >= m_charaNum)
			return nullptr;
		CCharacter* realChara = m_chara[index];
		ICharacter* chara = realChara;
		if (!realChara->isBuilt())
		{
			//�\�z���ς�ł��Ȃ��ꍇ�A�v���L�V�\��Ԃ�
			static CCharacterProxy proxy;//�v���L�V�[�̃C���X�^���X�i�ė��p����F����Flyweight�p�^�[���j
			proxy.setRealObj(realChara);
			chara = &proxy;
		}
		return chara;
	}
public:
	//�L�����ǉ�
	void addChara(const char* name)
	{
		if (m_charaNum >= CHARA_MAX)
			return;
		CCharacter* chara = new CCharacter(name);
		if (chara)
		{
			m_chara[m_charaNum++] = chara;
		}
	}
public:
	//�R���X�g���N�^
	CCharacterCollection() :
		m_charaNum(0)
	{}
	//�f�X�g���N�^
	~CCharacterCollection()
	{
		//�S�č폜
		for (int index = 0; index < m_charaNum; ++index)
		{
			if (m_chara[index])
			{
				delete m_chara[index];
				m_chara[index] = nullptr;
			}
		}
	}
private:
	//�t�B�[���h
	static const int CHARA_MAX = 32;//�L�������̍ő吔
	CCharacter* m_chara[CHARA_MAX]; //�L�������
	int m_charaNum;                 //�L�������
};
//����for_each
template<class T, class F>
void for_each(T ite, T end, F functor)
{
	for (; ite != end; ++ite)
	{
		functor(ite);
	}
}
template<class T, class F, class P1>
void for_each(T ite, T end, F functor, P1& param1)
{
	for (; ite != end; ++ite)
	{
		functor(ite, param1);
	}
}

//----------------------------------------

//--------------------
//���ʏ����V�X�e��
namespace common_system
{
	//�L�����N�^�[�X�V�����i�֐��I�u�W�F�N�g�j
	struct Update
	{
		void operator()(ICharacter* chara)
		{
			chara->update();
		}
	};
	
	//�L�����N�^�[�`�揈���i�֐��I�u�W�F�N�g�j
	struct Draw
	{
		void operator()(ICharacter* chara)
		{
			chara->draw();
		}
	};

	//�L�����N�^�[�\�z�����`�F�b�N
	struct isBuiltAll
	{
		void operator()(ICharacter* chara, bool& is_built_all)
		{
			if (!chara->isBuilt())
			{
				is_built_all = false;
			}
		}
	};
};

//----------------------------------------
//Proxy�p�^�[��(2)�e�X�g���C���֐�
void testProxy1()
{
	printf("\n- testProxy1() -\n\n");

	//�L�����N�^�[����
	CCharacterCollection chara_coll;
	chara_coll.addChara("���Y");
	chara_coll.addChara("���Y");
	chara_coll.addChara("�O�Y");
	chara_coll.addChara("�l�Y");
	chara_coll.addChara("�ܘY");

	//�S�L�����N�^�[�̍\�z����������܂ŏ���
	for (int step = 0; ; ++step)
	{
		printf("- step: %d -\n", step);
		for_each(chara_coll.begin(), chara_coll.end(), common_system::Update());
		for_each(chara_coll.begin(), chara_coll.end(), common_system::Draw());
		bool is_built_all = true;
		for_each(chara_coll.begin(), chara_coll.end(), common_system::isBuiltAll(), is_built_all);
		if (is_built_all)
		{
			printf("- finish. -\n");
			break;
		}
	}
}

//================================================================================
//Proxy�p�^�[��(2)�F�ȈՔŃX�}�[�g�|�C���^�[

//----------------------------------------
//�ȈՔŃX�}�[�g�|�C���^�[�̃e���v���[�g�N���X
template<class T>
class CSmartPtr
{
private:
	//�Q�Ə��^
	struct T_REF_INFO
	{
		T* m_realObj;//�{���̃I�u�W�F�N�g
		int m_refCount;//�Q�ƃJ�E���^
		//�R���X�g���N�^
		T_REF_INFO(T* real_obj, const int ref_count) :
			m_realObj(real_obj),
			m_refCount(ref_count)
		{}
		T_REF_INFO(T_REF_INFO& info) :
			m_realObj(info.m_realObj),
			m_refCount(info.m_refCount)
		{}
	};
public:
	//�I�y���[�^���������Ė{���̃I�u�W�F�N�g���U���i�㗝�j
	T* operator->(){ return m_refInfo ? m_refInfo->m_realObj : nullptr; }
	const T* operator->() const { return m_refInfo ? m_refInfo->m_realObj : nullptr; }
	T& operator*(){ return *m_refInfo->m_realObj; }
	const T& operator*() const { return *m_refInfo->m_realObj; }
	//������Z�q�F�X�}�[�g�|�C���^�[����
	CSmartPtr<T>& operator=(CSmartPtr<T>& obj)
	{
		//���łɎQ�Ƃ��Ă���Ȃ�Ȃɂ����Ȃ�
		if (m_refInfo == obj.m_refInfo)
			return *this;
		
		//�Q�ƃJ�E���^���J�E���g�_�E��
		release();
			
		//�Q�Ə����R�s�[
		m_refInfo = obj.m_refInfo;
			
		//�Q�ƃJ�E���^���J�E���g�A�b�v
		addRef();
		
		return *this;
	}
	//������Z�q�F�|�C���^�[����
	CSmartPtr<T>& operator=(T* real_obj)
	{
		//���łɎQ�Ƃ��Ă���Ȃ�Ȃɂ����Ȃ�
		if (m_refInfo && m_refInfo->m_realObj == real_obj)
			return *this;
		
		//�Q�ƃJ�E���^���J�E���g�_�E��
		release();
		
		if (real_obj)//nullptr ������͂Ȃɂ����Ȃ�
		{
			//�Q�Ə��𐶐�
			m_refInfo = new T_REF_INFO(real_obj, 1);
		}
		return *this;
	}
private:
	//�Q�ƃJ�E���^���J�E���g�A�b�v
	void addRef()
	{
		if (!m_refInfo)
			return;
		++m_refInfo->m_refCount;
	}
	//�Q�ƃJ�E���^���J�E���g�_�E��
	void release()
	{
		if (!m_refInfo)
			return;
		if (m_refInfo->m_refCount > 0)
		{
			--m_refInfo->m_refCount;
			if (m_refInfo->m_refCount == 0)
			{
				//�Q�ƃJ�E���^��0�ɂȂ�����I�u�W�F�N�g���폜
				if (m_refInfo->m_realObj)
				{
					delete m_refInfo->m_realObj;//�{���̃I�u�W�F�N�g���폜
					m_refInfo->m_realObj = nullptr;
				}
				delete m_refInfo;//�Q�Ə����폜
			}
		}
		m_refInfo = nullptr;
	}
public:
	//�R���X�g���N�^
	CSmartPtr(T* real_obj)
	{
		//�Q�Ə��𐶐�
		m_refInfo = new T_REF_INFO(real_obj, 1);
	}
	//�R�s�[�R���X�g���N�^
	CSmartPtr(CSmartPtr<T>& smart_ptr)
	{
		//�Q�Ə����R�s�[
		m_refInfo = smart_ptr.m_refInfo;
		
		//�Q�ƃJ�E���^���J�E���g�A�b�v
		addRef();
	}
	//�f�X�g���N�^
	~CSmartPtr()
	{
		//�Q�ƃJ�E���^���J�E���g�_�E��
		release();
	}
private:
	//�t�B�[���h
	T_REF_INFO* m_refInfo;//�Q�Ə��
};

//----------------------------------------
//�e�X�g�p�N���X
//�����ꎩ�͉̂��̃C���^�[�t�F�[�X�������Ȃ����ʂ̃N���X
//�@���̃N���X���X�}�[�g�|�C���^�[�ň���
class CTest
{
public:
	//�A�N�Z�b�T
	const char* getName() const { return m_name; }
public:
	//�R���X�g���N�^
	CTest(const char* name)
	{
		printf("CTest::Ctest(\"%s\")\n", name);
		m_name = name;
	}
	//�f�X�g���N�^
	~CTest()
	{
		printf("CTest::~Ctest() : m_name=\"%s\"\n", m_name);
	}
private:
	//�t�B�[���h
	const char* m_name;//���O
};

//----------------------------------------
//Proxy�p�^�[��(2)�e�X�g���C���֐�
void testProxy2()
{
	printf("\n- testProxy2() -\n\n");

	//�X�}�[�g�|�C���^�[�� CTest �̃C���X�^���X�𐶐�
	//���R�ɃR�s�[���Ă��A�K�؂ȊJ�����s���Ă����
	//�y���Ӂz
	//�֐��ɃX�}�[�g�|�C���^�[��n�����́A�l�n���ɂ��Ȃ���
	//�֐�����delete���������鎖�ɒ��ӁB

	printf("(begin function)\n");
	CSmartPtr<CTest> obj1 = new CTest("���Y");
	printf("[01] obj1->getName()=\"%s\"\n", obj1->getName());
	printf("     (*obj1).getName()=\"%s\"\n", (*obj1).getName());
	CSmartPtr<CTest> obj2 = new CTest("���Y");
	printf("[02] obj2->getName()=\"%s\"\n", obj2->getName());
	CSmartPtr<CTest> obj3 = new CTest("�O�Y");
	printf("[03] obj3->getName()=\"%s\"\n", obj3->getName());
	{
		printf("(begin block)\n");
		CSmartPtr<CTest> obj4 = new CTest("�l�N");
		printf("[04] obj4->getName()=\"%s\"\n", obj4->getName());
		CSmartPtr<CTest> obj5 = new CTest("�ܘY");
		printf("[05] obj5->getName()=\"%s\"\n", obj5->getName());
		printf("obj2 = obj4\n");
		obj2 = obj4;//�X�}�[�g�|�C���^�[�̑���F�u���Y�v�� delete ���s����
		printf("[06] obj1->getName()=\"%s\"\n", obj1->getName());
		printf("     obj2->getName()=\"%s\"\n", obj2->getName());
		printf("     obj3->getName()=\"%s\"\n", obj3->getName());
		printf("     obj4->getName()=\"%s\"\n", obj4->getName());
		printf("     obj5->getName()=\"%s\"\n", obj5->getName());
		printf("obj1 = obj2\n");
		obj1 = obj2;//�X�}�[�g�|�C���^�[�̑���F�u���Y�v�� delete ���s����
		printf("[07] obj1->getName()=\"%s\"\n", obj1->getName());
		printf("     obj2->getName()=\"%s\"\n", obj2->getName());
		printf("     obj3->getName()=\"%s\"\n", obj3->getName());
		printf("     obj4->getName()=\"%s\"\n", obj4->getName());
		printf("     obj5->getName()=\"%s\"\n", obj5->getName());
		//�u���b�N�I���F�u�ܘY�v��delete ���s����
		printf("(end block)\n");
	}
	printf("[08] obj1->getName()=\"%s\"\n", obj1->getName());
	printf("     obj2->getName()=\"%s\"\n", obj2->getName());
	printf("     obj3->getName()=\"%s\"\n", obj3->getName());
	printf("obj3 = nullptr\n");
	obj3 = nullptr;//obj3�𖾎��I�ɉ���F�u�O�Y�v��delete ���s����
	printf("[09] obj1->getName()=\"%s\"\n", obj1->getName());
	printf("     obj2->getName()=\"%s\"\n", obj2->getName());
//	printf("     obj3->getName()=\"%s\"\n", obj3->getName());//�G���[
	printf("obj2 = nullptr\n");
	obj2 = nullptr;//obj2�𖾎��I�ɉ���F�u�l�N�v��delete �͍s���Ȃ�
	printf("[10] obj1->getName()=\"%s\"\n", obj1->getName());
//	printf("     obj2->getName()=\"%s\"\n", obj2->getName());//�G���[
//	printf("     obj3->getName()=\"%s\"\n", obj3->getName());//�G���[
	//obj1�͖����I�ȉ�����Ȃ�
	printf("(end function)\n");
	//�֐��I���F�֐��𔲂��鎞�Ɂu�l�N�v�� delete ���s����
}

//================================================================================
//�e�X�g���C���֐�
void testMain()
{
	//Observer�e�X�g
	testObserver();
	
	//Adapter�e�X�g
	testAdapter();

	//Proxy�e�X�g(1)
	testProxy1();

	//Proxy�e�X�g(2)
	testProxy2();
}

//================================================================================
int main(const int argc, const char* argv[])
{
	testMain();

	return EXIT_SUCCESS;
}

// End of file

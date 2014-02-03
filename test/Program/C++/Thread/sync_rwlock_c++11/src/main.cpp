#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <atomic>

#include <chrono> //���Ԍv���p
#include <random> //���������p

//--------------------------------------------------------------------------------
//���샊�[�h�E���C�g���b�N�N���X

#include <thread>
#include <atomic>

//----------------------------------------

//�X���b�h���[�J���X�g���[�W�C���q
#define thread_local __declspec(thread) //C++11

//�X���b�hID�^
//typedef std::thread::id THREAD_ID;//C++11
typedef std::size_t THREAD_ID;//C++11
static const THREAD_ID INVALID_THREAD_ID = 0xffffffff;//������ID

//���݂̃X���b�hID�擾�֐�
//inline THREAD_ID  GetThisThreadID(){ return std::this_thread::get_id(); } //C++11
inline THREAD_ID GetThisThreadID(){ return std::this_thread::get_id().hash(); } //C++11

//�X���b�hID�N���X
class CThreadID
{
public:
	//�A�N�Z�b�T
	const THREAD_ID getID() const { return m_threadId; }//�X���b�hID���擾
	const char* getName() const { return m_threadName; }//�X���b�h�����擾
public:
	//�A�N�Z�b�T�istatic�j
	static THREAD_ID getThisID(){ return m_thisThreadID; }//���݂̃X���b�h�̃X���b�hID���擾
	static const char* getThisName(){ return m_thisThreadName; }//���݂̃X���b�h�̃X���b�h�����擾
public:
	//���\�b�h
	bool isThisThread() const { return m_threadId == getThisID(); }//���݂̃X���b�h�Ɠ����X���b�h������
private:
	//���\�b�h(static)
	static void setThisThread()//���݂̃X���b�h�̃X���b�hID���Z�b�g
	{
		if (m_thisThreadID == INVALID_THREAD_ID)
			m_thisThreadID = GetThisThreadID();
	}
	static void resetThisThread(const char* name)//���݂̃X���b�h�̃X���b�hID�����Z�b�g
	{
		m_thisThreadID = GetThisThreadID();
		m_thisThreadName = name;
	}
public:
	//�I�y���[�^�i���j
	bool operator==(const CThreadID& o) const { return m_threadId == o.getID(); }//ID��v����
	bool operator!=(const CThreadID& o) const { return m_threadId != o.getID(); }//ID�s��v����
	bool operator==(const THREAD_ID& id) const { return m_threadId == id; }//ID��v����
	bool operator!=(const THREAD_ID& id) const { return m_threadId != id; }//ID�s��v����
	CThreadID& operator=(const CThreadID& o) //�R�s�[���Z�q
	{
		m_threadId = o.m_threadId;
		m_threadName = o.m_threadName;
		return *this;
	}
private:
	//�I�y���[�^�i�֎~�j
	CThreadID& operator=(const THREAD_ID& id) { return *this; }//�R�s�[���Z�q�i�֎~�j
public:
	//�R�s�[�R���X�g���N�^�i���j
	explicit CThreadID(const CThreadID& o) :
		m_threadId(o.m_threadId),
		m_threadName(o.m_threadName)
	{
	}
private:
	//�R�s�[�R���X�g���N�^�i�֎~�j
	explicit CThreadID(const THREAD_ID& id){}
public:
	//�R���X�g���N�^
	//���X���b�h�����w�肵�A�����Ō��݂̃X���b�hID���擾���ĕێ�
	//��TLS�ɂ��L�^
	CThreadID(const char* name)
	{
		resetThisThread(name);
		m_threadId = m_thisThreadID;
		m_threadName = m_thisThreadName;
	}
	//�f�t�H���g�R���X�g���N�^
	//������TLS�ɋL�^�ς݂̃X���b�hID�i�Ɩ��O�j���擾
	CThreadID()
	{
		setThisThread();
		m_threadId = m_thisThreadID;
		m_threadName = m_thisThreadName;
	}
private:
	//�t�B�[���h
	THREAD_ID m_threadId;//�X���b�hID�i�I�u�W�F�N�g�ɕۑ�����l�j
	const char* m_threadName;//�X���b�h���i�I�u�W�F�N�g�ɕۑ�����l�j
	static thread_local THREAD_ID m_thisThreadID;//���݂̃X���b�h�̃X���b�hID(TLS)
	static thread_local const char* m_thisThreadName;//���݂̃X���b�h��(TLS)
};
//static�ϐ��̃C���X�^���X��
thread_local THREAD_ID CThreadID::m_thisThreadID = INVALID_THREAD_ID;//�X���b�hID(TLS)
thread_local const char* CThreadID::m_thisThreadName = nullptr;//�X���b�h��(TLS)

//----------------------------------------
//���[�h�E���C�g���b�N�N���X
//���e�ʐߖ�̂��߂ɁAPOSIX�X���b�h���C�u�����ł̂悤�ɁA���݂̃X���b�h�̃��b�N��Ԃ�ێ����Ȃ�
//���K�����b�N�N���X CRWLock::LockR, CRWLock::LockR_AsNecessary, CRWLock::LockW ���g�p���A
//�@�����Ɍ��݂̃��b�N��Ԃ�ێ�����
class CRWLock
{
public:
	//�萔
	static const int DEFAULT_SPIN_COUNT = 1000;//�X�s�����b�N�J�E���g�̃f�t�H���g�l
	enum E_WLOCK_PRIORITY//���C�g���b�N�D��x
	{
		WLOCK_PRIORITIZED,//���C�g���b�N�D��
		NOT_WLOCK_PRIORITIZED,//���C�g���b�N�D�悵�Ȃ�
		ALL_WLOCK//�S�ă��C�g���b�N�ɂ���i���[�h���b�N�������I�Ƀ��C�g���b�N�ɂȂ�j
	};
public:
	//----------------------------------------
	//�y�N���X���N���X�z�N���X�錾
	class RLock;
	class RLockAsNecessary;
	class WLock;
	//----------------------------------------
	//�y�N���X���N���X�z���b�N�N���X�@���p����p
	class Lock
	{
		friend class CRWLock;
	public:
		//�A�N�Z�b�T
		bool isWriteLock() const { return m_isWriteLock; }//���C�g���b�N���[�h���H
		bool isUnlocked() const { return m_isUnlocked; }//���݃A�����b�N��Ԃ��H�i���b�N��ԂȂ̂����ʁj
	public:
		//���\�b�h

		//�����I�ȃ��[�h���b�N
		//�����[�h���b�N�����u�K�v�ɉ����ă��[�h���b�N�v�Ȃ瓯������ɂȂ�
		//�������I�ȃ��b�N������p���\�b�h
		//���ʏ�̓R���X�g���N�^�Ń��b�N����̂Ŏg�p���Ȃ�
		void rlock(const int spin_count = DEFAULT_SPIN_COUNT)
		{
			if (!m_isUnlocked)
				return;
			m_lock.rlock(spin_count, m_ignoreThreadId);
			m_isWriteLock = false;
			m_isUnlocked = false;
		}
		//�����I�ȃ��C�g���b�N
		//�������I�ȃ��b�N������p���\�b�h
		//���ʏ�̓R���X�g���N�^�Ń��b�N����̂Ŏg�p���Ȃ�
		void wlock(const int spin_count = DEFAULT_SPIN_COUNT)
		{
			if (!m_isUnlocked)
				return;
			m_lock.wlock(spin_count);
			m_isWriteLock = true;
			m_isUnlocked = false;
		}
		//�����I�ȃA�����b�N
		//���ʏ�̓f�X�g���N�^�ŃA�����b�N����̂Ŏg�p���Ȃ�
		void unlock()
		{
			if (m_isUnlocked)
				return;
			if (m_isWriteLock)
				m_lock.wunlock();
			else
				m_lock.runlock();
			m_isUnlocked = true;
		}
	private:
		//�I�y���[�^
		Lock& operator=(const Lock& o){ return *this; }//�R�s�[���Z�q�i�֎~�j
	private:
		//�R���X�g���N�^
		explicit Lock(const Lock& o) :m_lock(o.m_lock){}//�R�s�[�R���X�g���N�^�i�֎~�j
	public:
		//���[�u�R���X�g���N�^
		inline Lock(Lock&& lock) :
			m_lock(lock.m_lock),
			m_ignoreThreadId(lock.m_ignoreThreadId),
			m_isWriteLock(lock.m_isWriteLock),
			m_isUnlocked(lock.m_isUnlocked)
		{
			//�ړ����̃��b�N�I�u�W�F�N�g�̓A�����b�N�����ɂ��āA
			//�f�X�g���N�^�ŃA�����b�N���Ă��܂����Ƃ�h��
			lock.m_isUnlocked = true;
		}
	protected:
		//�R���X�g���N�^�@���e�탍�b�N�N���X����̂ݎg�p
		
		//���[�h���b�N�p�R���X�g���N�^
		inline Lock(const RLock*, CRWLock& lock, const int spin_count = DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(INVALID_THREAD_ID),
			m_isWriteLock(false),
			m_isUnlocked(false)
		{
			//���[�h���b�N
			m_lock.rlock(spin_count, m_ignoreThreadId);
		}
		//�K�v�ɉ����ă��[�h���b�N�p�R���X�g���N�^
		inline Lock(const RLockAsNecessary*, CRWLock& lock, const CThreadID& ignore_thread_id, const int spin_count = DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(ignore_thread_id.getID()),
			m_isWriteLock(false),
			m_isUnlocked(false)
		{
			//�K�v�ɉ����ă��[�h���b�N
			m_lock.rlock(spin_count, m_ignoreThreadId);
		}
		inline Lock(const RLockAsNecessary*, CRWLock& lock, const THREAD_ID ignore_thread_id, const int spin_count = DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(ignore_thread_id),
			m_isWriteLock(false),
			m_isUnlocked(false)
		{
			//�K�v�ɉ����ă��[�h���b�N
			m_lock.rlock(spin_count, m_ignoreThreadId);
		}
		//���C�g���b�N�p�R���X�g���N�^
		inline Lock(const WLock*, CRWLock& lock, const int spin_count = DEFAULT_SPIN_COUNT) :
			m_lock(lock),
			m_ignoreThreadId(INVALID_THREAD_ID),
			m_isWriteLock(true),
			m_isUnlocked(false)
		{
			//���C�g���b�N
			m_lock.wlock(spin_count);
		}
	public:
		//�f�X�g���N�^
		//���A�����b�N
		~Lock()
		{
			unlock();
		}
	private:
		//�t�B�[���h
		CRWLock& m_lock;//���[�h�E���C�g�I�u�W�F�N�g�̎Q��
		THREAD_ID m_ignoreThreadId;//���[�h���b�N�𖳎�����X���b�hID
		bool m_isWriteLock;//���C�g���b�N���[�h���H
		bool m_isUnlocked;//�A�����b�N��Ԃ��H
	};
public:
	//----------------------------------------
	//�y�N���X���N���X�z���[�h���b�N�N���X
	class RLock : public Lock
	{
	private:
		//�I�y���[�^
		RLock& operator=(const RLock& o){ return *this; }//�R�s�[���Z�q�i�֎~�j
	private:
		//�R���X�g���N�^
		explicit RLock(const Lock& o) :Lock(o){}//�R�s�[�R���X�g���N�^�i�֎~�j
	public:
		//���[�u�R���X�g���N�^
		inline RLock(RLock&& lock) :
			Lock(std::move(lock))
		{}
	public:
		//�R���X�g���N�^
		inline RLock(CRWLock& lock, const int spin_count = DEFAULT_SPIN_COUNT) :
			Lock(this, lock, spin_count)
		{}
		//�f�X�g���N�^
		inline ~RLock()
		{}
	};
	//----------------------------------------
	//�y�N���X���N���X�z�K�v�ɉ����ă��[�h���b�N�N���X
	class RLockAsNecessary : public Lock
	{
	private:
		//�I�y���[�^
		RLockAsNecessary& operator=(const RLockAsNecessary& o){ return *this; }//�R�s�[���Z�q�i�֎~�j
	private:
		//�R���X�g���N�^
		explicit RLockAsNecessary(const RLockAsNecessary& o) :Lock(o){}//�R�s�[�R���X�g���N�^�i�֎~�j
	public:
		//���[�u�R���X�g���N�^
		inline RLockAsNecessary(RLockAsNecessary&& lock) :
			Lock(std::move(lock))
		{}
	public:
		//�R���X�g���N�^
		inline RLockAsNecessary(CRWLock& lock, const CThreadID& ignore_thread_id, const int spin_count = DEFAULT_SPIN_COUNT) :
			Lock(this, lock, ignore_thread_id, spin_count)
		{}
		inline RLockAsNecessary(CRWLock& lock, const THREAD_ID ignore_thread_id, const int spin_count = DEFAULT_SPIN_COUNT) :
			Lock(this, lock, ignore_thread_id, spin_count)
		{}
		inline RLockAsNecessary(CRWLock& lock, const int spin_count = DEFAULT_SPIN_COUNT) :
			Lock(this, lock, CThreadID::getThisID(), spin_count)
		{}
		//�f�X�g���N�^
		inline ~RLockAsNecessary()
		{}
	};
	//----------------------------------------
	//�y�N���X���N���X�z���C�g���b�N�N���X
	class WLock : public Lock
	{
	private:
		//�I�y���[�^
		WLock& operator=(const WLock& lock){ return *this; }//�R�s�[���Z�q�i�֎~�j
	private:
		//�R���X�g���N�^
		explicit WLock(const WLock& lock) :Lock(lock){}//�R�s�[�R���X�g���N�^�i�֎~�j
	public:
		//���[�u�R���X�g���N�^
		inline WLock(WLock&& lock) :
			Lock(std::move(lock))
		{}
	public:
		//�R���X�g���N�^
		inline WLock(CRWLock& lock, const int spin_count = DEFAULT_SPIN_COUNT) :
			Lock(this, lock, spin_count)
		{}
		//�f�X�g���N�^
		inline ~WLock()
		{}
	};
	//----------------------------------------
	//�y�N���X���N���X�z�i�ȏ�ŏI���j

public:
	//�y���b�N�I�u�W�F�N�g��Ԃ����b�N���\�b�h�z
	//���E�Ӓl�Q�Ƃ��g�p���邱�Ƃɂ��A�u�R�s�[�R���X�g���N�^�v��
	//�@��ʂ��āu���[�u�R���X�g���N�^�v���L�q�ł���
	//������𗘗p���āA�֐��̓����ō쐬�����I�u�W�F�N�g�̓��e��
	//�@�Ăяo�����̃I�u�W�F�N�g�Ɉړ�����B
	//�@���[�u�R���X�g���N�^�ł́A�ړ����I�u�W�F�N�g��
	//�@�A�����b�N�ς݈����ɂ��Ă����̂ŁA�֐��I������
	//�@���[�J���I�u�W�F�N�g�̃f�X�g���N�^���Ăяo����Ă��A
	//�@�A�����b�N���Ă��܂����Ƃ��Ȃ��B

	//�y���b�N�I�u�W�F�N�g��Ԃ����b�N���\�b�h�z���[�h���b�N
	RLock rLock(const int spin_count = DEFAULT_SPIN_COUNT)
	{
		RLock lock(*this, spin_count);
		return std::move(lock);
	}
	//�y���b�N�I�u�W�F�N�g��Ԃ����b�N���\�b�h�z�K�v�ɉ����ă��[�h���b�N
	RLockAsNecessary rLockAsNecessary(const CThreadID& ignore_thread_id, const int spin_count = DEFAULT_SPIN_COUNT)
	{
		RLockAsNecessary lock(*this, ignore_thread_id, spin_count);
		return std::move(lock);
	}
	RLockAsNecessary rLockAsNecessary(const THREAD_ID ignore_thread_id, const int spin_count = DEFAULT_SPIN_COUNT)
	{
		RLockAsNecessary lock(*this, ignore_thread_id, spin_count);
		return std::move(lock);
	}
	RLockAsNecessary rLockAsNecessary(const int spin_count = DEFAULT_SPIN_COUNT)
	{
		RLockAsNecessary lock(*this, spin_count);
		return std::move(lock);
	}
	//�y���b�N�I�u�W�F�N�g��Ԃ����b�N���\�b�h�z���C�g���b�N
	WLock wLock(const int spin_count = DEFAULT_SPIN_COUNT)
	{
		WLock lock(*this, spin_count);
		return std::move(lock);
	}

private:
	//���\�b�h�@�����b�N�N���X����̂ݎg�p

	//���[�h���b�N
	//���K�v�ɉ����ă��[�h���b�N�̋@�\�������
	void rlock(const int spin_count, const THREAD_ID ignore_thread_id)
	{
		//�S�ă��C�g���b�N�ɂ��郂�[�h�p����
		if (m_wlockPrioritized == ALL_WLOCK)
		{
			wlock(spin_count);
			return;
		}
		
		//���[�h���b�N�X�L�b�v�`�F�b�N
		//�����[�h�E���C�g���b�N�I�u�W�F�N�g�C���X�^���X�������A����сA���[�h���b�N���ɁA
		//�@���ɃX���b�hID���w�肳��Ă����ꍇ�A���A���ꂪ����ID�ł������ꍇ�A
		//�@���[�h���b�N���X�L�b�v����
		if (ignore_thread_id != INVALID_THREAD_ID && m_ignoreThreadId == ignore_thread_id)//&& m_writeLock.load() == false)
		                                                                                  //�����C�g���b�N��Ԃ̓`�F�b�N���Ȃ�
		                                                                                  //���v���O������M�����č�������O�ꂷ��
																						  //�����ɂ��̔�����s���Ă��Am_lock �ŕی삵�Ȃ�����͕s�m���ȃu���b�N
		{
			m_readLock.fetch_add(1);
			return;
		}

		//���[�h���b�N�\��J�E���g�A�b�v
		//�������͕K�v�Ȃ����A���ǐՎ��̎Q�l�p
		m_readLockReserved.fetch_add(1);

		//���[�h���b�N�ҋ@���[�v
		while (1)
		{
			//�����ϐ��X�V���b�N���[�v
			int spin_count_now = 0;
			while (m_lock.test_and_set())
			{
				if (spin_count == 0 || ++spin_count_now % spin_count == 0)
					std::this_thread::sleep_for(std::chrono::milliseconds(0));//�X���[�v
			}

			//�����ϐ��X�V���b�N���擾�ł����̂ŁA���C�g���b�N�̏�Ԃ��`�F�b�N
			if (m_writeLock.load() == false &&//���C�g���b�N��Ԃł͂Ȃ�
				(m_wlockPrioritized != WLOCK_PRIORITIZED ||//���C�g���b�N�D�惂�[�h�ł͂Ȃ�
				 m_wlockPrioritized == WLOCK_PRIORITIZED && m_writeLockReserved.load() == 0))//���C�g���b�N�D�惂�[�h�Ȃ�A���C�g���b�N�\�񂪂Ȃ����Ƃ��`�F�b�N
			{
				//���[�h���b�NOK
				m_readLock.fetch_add(1);//���[�h���b�N�J�E���g�A�b�v
				m_lock.clear();//�����ϐ��X�V���b�N����
				break;
			}

			//�����ϐ��X�V���b�N����
			//�����[�h���b�N���擾�ł���܂ōĂёҋ@
			m_lock.clear();
		}

		//���[�h���b�N�\��J�E���g�_�E��
		//�������͕K�v�Ȃ����A���ǐՎ��̎Q�l�p
		m_readLockReserved.fetch_sub(1);
	}
	//���C�g���b�N
	void wlock(const int spin_count)
	{
		//���C�g���b�N�\��J�E���g�A�b�v
		m_writeLockReserved.fetch_add(1);
		
		//���C�g���b�N�ҋ@���[�v
		while (1)
		{
			//�����ϐ��X�V���b�N���[�v
			int spin_count_now = 0;
			while (m_lock.test_and_set())
			{
				if (spin_count == 0 || ++spin_count_now % spin_count == 0)
					std::this_thread::sleep_for(std::chrono::milliseconds(0));//�X���[�v
			}

			//�����ϐ��X�V���b�N���擾�ł����̂ŁA���[�h���b�N�ƃ��C�g���b�N�̏�Ԃ��`�F�b�N
			if (m_readLock.load() == 0 && m_writeLock.load() == false)
			{
				//���C�g���b�NOK
				m_writeLock.store(true);//���C�g���b�NON
				m_lock.clear();//�����ϐ��X�V���b�N����
				break;
			}

			//�����ϐ��X�V���b�N����
			//�����C�g���b�N���擾�ł���܂ōĂёҋ@
			m_lock.clear();
		}
		
		//���C�g���b�N�\��J�E���g�_�E��
		m_writeLockReserved.fetch_sub(1);
	}
	//���[�h�A�����b�N
	void runlock()
	{
		//�S�ă��C�g���b�N�ɂ��郂�[�h�p����
		if (m_wlockPrioritized == ALL_WLOCK)
		{
			wunlock();
			return;
		}

		//���[�h���b�N�J�E���g�_�E��
		m_readLock.fetch_sub(1);
	}
	//���C�g�A�����b�N
	void wunlock()
	{
		//���C�g���b�NOFF
		m_writeLock.store(false);
	}
public:
	//�A�N�Z�b�T
	THREAD_ID getIgnoreThreadID() const { return m_ignoreThreadId; }//�u�K�v�ɉ����ă��[�h���b�N�v�p�̃X���b�hID
	void setIgnoreThreadID(const THREAD_ID thread_id) { m_ignoreThreadId = thread_id; }//�u�K�v�ɉ����ă��[�h���b�N�v�p�̃X���b�hID���X�V
	int getReadLockReserved() const { return m_readLockReserved; }//���[�h���b�N�\��J�E���^ �������͕K�v�Ȃ����A���ǐՎ��̎Q�l�p
	int getReadLock() const { return m_readLock; }//���[�h���b�N�J�E���^
	int getWriteLockReserved() const { return m_writeLockReserved; }//���C�g���b�N�\��J�E���^
	bool getWriteLock() const { return m_writeLock; }//���C�g���b�N�t���O
	E_WLOCK_PRIORITY getWlockPrioritized() const { return m_wlockPrioritized; }//���C�g���b�N�D��x
public:
	//�R���X�g���N�^
	CRWLock(const THREAD_ID ignore_thread_id, const E_WLOCK_PRIORITY wlock_prioritized) :
		m_ignoreThreadId(ignore_thread_id),
		m_readLockReserved(0),
		m_readLock(0),
		m_writeLockReserved(0),
		m_writeLock(false),
		m_lock(),
		m_wlockPrioritized(wlock_prioritized)
	{}
	CRWLock(const CThreadID& ignore_thread_id, const E_WLOCK_PRIORITY wlock_prioritized) :
		CRWLock(ignore_thread_id.getID(), wlock_prioritized)
	{}
	CRWLock(const CThreadID& ignore_thread_id) :
		CRWLock(ignore_thread_id.getID(), WLOCK_PRIORITIZED)
	{}
	CRWLock(const THREAD_ID ignore_thread_id) :
		CRWLock(ignore_thread_id, WLOCK_PRIORITIZED)
	{}
	CRWLock(const E_WLOCK_PRIORITY wlock_prioritized) :
		CRWLock(CThreadID::getThisID(), wlock_prioritized)
	{}
	CRWLock() :
		CRWLock(CThreadID::getThisID(), WLOCK_PRIORITIZED)
	{}
	//�f�X�g���N�^
	~CRWLock()
	{}
private:
	//�t�B�[���h
	THREAD_ID m_ignoreThreadId;//�u�K�v�ɉ����ă��[�h���b�N�v�p�̃X���b�hID
	std::atomic<int> m_readLockReserved;//���[�h���b�N�\��J�E���^ �������͕K�v�Ȃ����A���ǐՎ��̎Q�l�p
	std::atomic<int> m_readLock;//���[�h���b�N�J�E���^
	std::atomic<int> m_writeLockReserved;//���C�g���b�N�\��J�E���^
	std::atomic<bool> m_writeLock;//���C�g���b�N�t���O
	std::atomic_flag m_lock;//�����ϐ��X�V�p���b�N�t���O
	E_WLOCK_PRIORITY m_wlockPrioritized;//���C�g���b�N�D��x
};

//���[�h���b�N�N���X�A�K�v�ɉ����ă��[�h���b�N�N���X�A���C�g���b�N�N���X�̕ʖ���ݒ�
typedef CRWLock::RLock CRWLockR;
typedef CRWLock::RLockAsNecessary CRWLockR_AsNecessary;
typedef CRWLock::WLock CRWLockW;

//�yC++11�X�^�C���z���[�h���b�N�N���X�A�K�v�ɉ����ă��[�h���b�N�N���X�A���C�g���b�N�N���X�̕ʖ���ݒ�
//using CRWLockR = CRWLock::RLock;
//using CRWLockR_AsNecessary = CRWLock::RLockAsNecessary;
//using CRWLockW = CRWLock::WLock;

//--------------------------------------------------------------------------------

//���C���X���b�h���
static CThreadID s_mainThread("MainThread");

//���[�h�E���C�g���b�N�I�u�W�F�N�g
static CRWLock s_lock;
//static CRWLock s_lock(CRWLock::NOT_WLOCK_PRIORITIZED);
//static CRWLock s_lock(s_mainThread);
//static CRWLock s_lock(s_mainThread, CRWLock::NOT_WLOCK_PRIORITIZED);
//static CRWLock s_lock(CRWLock::ALL_WLOCK);

//���L�f�[�^
static int s_commonData = 0;

//�X���b�h�ŗL�f�[�^
__declspec(thread) int s_tlsData = 0;
//thread_local int s_tlsData = 0;//Visual C++ 2013 �ł� thread_local �L�[���[�h���g���Ȃ�

//�������݃X���b�h
void threadFuncW(const char* name)
{
	//�J�n
	printf("- begin:(W)%s -\n", name);
	fflush(stdout);

	//����
	std::random_device seed_gen;
	std::mt19937 rnd(seed_gen());
	std::uniform_int_distribution<int> sleep_time(0, 499);

	//�኱�����_���ŃX���[�v�i0�`499 msec�j
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));

	//����
	for (int i = 0; i < 3; ++i)
	{
		//���C�g���b�N�擾
		CRWLockW lock(s_lock);

		//�f�[�^�\���i�O�j
		printf("(W)%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//�f�[�^�擾
		int common_data = s_commonData;
		int tls_data = s_tlsData;

		//�f�[�^�X�V
		++common_data;
		++tls_data;

		//�኱�����_���ŃX���[�v�i0�`499 msec�j
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));

		//�f�[�^�����߂�
		s_commonData = common_data;
		s_tlsData = tls_data;

		//�f�[�^�\���i��j
		printf("(W)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//���C�g���b�N���
		lock.unlock();

		//�኱�����_���ŃX���[�v�i0�`499 msec�j
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));
	}

	//�I��
	printf("- end:(W)%s -\n", name);
	fflush(stdout);
}

//�ǂݍ��݃X���b�h
void threadFuncR(const char* name)
{
	//�J�n
	printf("- begin:(R)%s -\n", name);
	fflush(stdout);

	//����
	std::random_device seed_gen;
	std::mt19937 rnd(seed_gen());
	std::uniform_int_distribution<int> sleep_time(0, 499);

	//�኱�����_���ŃX���[�v�i0�`499 msec�j
	std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));

	//����
	for (int i = 0; i < 3; ++i)
	{
		//���[�h���b�N�擾
		CRWLockR lock(s_lock);

		//�f�[�^�\���i�O�j
		printf("(R)%s: [BEFORE] commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//�኱�����_���ŃX���[�v�i0�`499 msec�j
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));

		//�f�[�^�\���i��j
		printf("(R)%s: [AFTER]  commonData=%d, tlsData=%d\n", name, s_commonData, s_tlsData);
		fflush(stdout);

		//���[�h���b�N���
		lock.unlock();

		//�኱�����_���ŃX���[�v�i0�`499 msec�j
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time(rnd)));
	}

	//�I��
	printf("- end:(R)%s -\n", name);
	fflush(stdout);
}

//�e�X�g
int main(const int argc, const char* argv[])
{
	//�X���b�h�쐬
	std::thread thread_obj1 = std::thread(threadFuncR, "���Y");
	std::thread thread_obj2 = std::thread(threadFuncR, "���Y");
	std::thread thread_obj3 = std::thread(threadFuncR, "�O�Y");
	std::this_thread::sleep_for(std::chrono::microseconds(1));
	std::thread thread_obj4 = std::thread(threadFuncW, "���q");
	std::thread thread_obj5 = std::thread(threadFuncW, "�|�q");
	std::thread thread_obj6 = std::thread(threadFuncW, "�~�q");

	//�X���b�h�I���҂�
	{
		auto begin = std::chrono::high_resolution_clock::now();
		thread_obj1.join();
		thread_obj2.join();
		thread_obj3.join();
		thread_obj4.join();
		thread_obj5.join();
		thread_obj6.join();
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Time = %.6f sec\n", duration);
	}
	
	//���[�h�^���C�g���b�N�̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			CRWLockW lock(s_lock);
			lock.unlock();
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Read-WriteLock:wlock * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//���[�h�^���C�g���b�N�̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			CRWLockR lock(s_lock);
			lock.unlock();
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast< std::chrono::microseconds >(end - begin).count()) / 1000000.);
		printf("Read-WriteLock:rlock * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//���[�h�^���C�g���b�N�̎擾�Ɖ�����ʂɎ��s���Ď��Ԃ��v��
	{
		CThreadID current_thread_id;
		auto begin = std::chrono::high_resolution_clock::now();
		static const int TEST_TIMES = 10000000;
		for (int i = 0; i < TEST_TIMES; ++i)
		{
			CRWLockR_AsNecessary lock(s_lock, current_thread_id);
		//	CRWLockR_AsNecessary lock(s_lock);//���X���b�hID�̎w����ȗ������猻�݂̃X���b�h�Ƃ��ď�������
			lock.unlock();
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count()) / 1000000.);
		printf("Read-WriteLock:rlockAsNecessary * %d = %.6f sec\n", TEST_TIMES, duration);
	}

	//--------------------------------------------------------------------------------

	//���b�N�I�u�W�F�N�g�g�p���@�T���v��
	{
		//�u���[�h���b�N�v�̋L�q�p�^�[��
		CRWLockR lock1(s_lock);         //�p�^�[���@�F�R���X�g���N�^�Ń��b�N
		CRWLockR lock2(s_lock.rLock()); //�p�^�[���A�FrLock() ���\�b�h�Ń��b�N
		CRWLockR lock3 = s_lock.rLock();//�p�^�[���B�FrLock() ���\�b�h�Ń��b�N�@��������Z�q�g�p
		auto lock4 = s_lock.rLock();    //�p�^�[���C�FrLock() ���\�b�h�Ń��b�N�@��auto�^�g�p
		//����������A�����I�� .unlock() ���\�b�h���Ă΂Ȃ��Ă��A
		//�@�����u���b�N���甲����Ƃ��Ɏ����I�Ƀ��b�N��������
	}
	{
		//�u�K�v�ɉ����ă��[�h���b�N�v�̋L�q�p�^�[��
		CRWLockR_AsNecessary lock1(s_lock);                    //�p�^�[���@�F�R���X�g���N�^�Ń��b�N
		CRWLockR_AsNecessary lock2(s_lock.rLockAsNecessary()); //�p�^�[���A�FrLockAsNecessary() ���\�b�h�Ń��b�N
		CRWLockR_AsNecessary lock3 = s_lock.rLockAsNecessary();//�p�^�[���B�FrLockAsNecessary() ���\�b�h�Ń��b�N�@��������Z�q�g�p
		auto lock4 = s_lock.rLockAsNecessary();                //�p�^�[���C�FrLockAsNecessary() ���\�b�h�Ń��b�N�@��auto�^�g�p
		//����������A�����I�� .unlock() ���\�b�h���Ă΂Ȃ��Ă��A
		//�@�����u���b�N���甲����Ƃ��Ɏ����I�Ƀ��b�N��������
	}
	{
		//�u���C�g���b�N�v�̋L�q�p�^�[��
		CRWLockW lock1(s_lock);         //�p�^�[���@�F�R���X�g���N�^�Ń��b�N
		lock1.unlock();
		CRWLockW lock2(s_lock.wLock()); //�p�^�[���A�FrLock() ���\�b�h�Ń��b�N
		lock2.unlock();
		CRWLockW lock3 = s_lock.wLock();//�p�^�[���B�FrLock() ���\�b�h�Ń��b�N�@��������Z�q�g�p
		lock3.unlock();
		auto lock4 = s_lock.wLock();    //�p�^�[���C�FrLock() ���\�b�h�Ń��b�N�@��auto�^�g�p
		//����������A�����I�� .unlock() ���\�b�h���Ă΂Ȃ��Ă��A
		//�@�����u���b�N���甲����Ƃ��Ɏ����I�Ƀ��b�N��������
		//�����C�g���b�N�͑��d�Ăяo���Ńf�b�h���b�N����̂ŁA��̃T���v���ł͖����I�ȃA�����b�N�𕹗p���Ă���
	}
	
	return EXIT_SUCCESS;
}

// End of file

#include "stdafx.h"

#if 1

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>

//----------------------------------------
//�e�X�g�p�N���X
//���}�l�[�W�N���X�̂��߁uref�v��t����
//���}�l�[�W�N���X�́A�uIDisposable�v�C���^�[�t�F�[�X�������ÖٓI�ɍs���A�f�X�g���N�^�ɑΉ��t����
public ref class CTest// : public IDisposable//IDisposable�𖾎��I�ɐ錾����K�v�Ȃ�
{
public:
	//���\�b�h
	//���O�\��
	void showName()//const//�}�l�[�W�N���X�̃��\�b�h�ɂ��̏C���q�͎g���Ȃ�
	{
		System::Console::WriteLine(L"���O=\"{0}\"", m_name);//.Net Framework���̕�����W���o��
	}
public:
	//�R���X�g���N�^
	CTest(System::String^ name):
		m_name(name)
	{
		msclr::interop::marshal_context context;//�}�l�[�W�^�̕�������l�C�e�B�u�^�ɕϊ��i�}�[�V�������O�j
		printf("�R���X�g���N�^(%s)\n", context.marshal_as<const char*>(m_name));//C����W�����C�u�������̕�����W���o��
	}
	//�f�X�g���N�^
	//��IDisposable::Dispose()�̎����Ƃ��ĉ��߂����
	//��C#�ł͂��̊֐����t�@�C�i���C�U�ŁA�f�X�g���N�^��
	//�@�����I�� IDisposable::Dispose() �Ăяo���̕K�v������̂Œ���
	~CTest()
	{
		msclr::interop::marshal_context context;//�}�l�[�W�^�̕�������l�C�e�B�u�^�ɕϊ��i�}�[�V�������O�j
		std::cout << "�f�X�g���N�^(" << context.marshal_as<std::string>(m_name) << ")" << std::endl;//C++����̕W�����C�u�������̕�����W���o��
	}
protected:
	//�t�@�C�i���C�U
	//���K�x�[�W�R���N�V�������ɃI�u�W�F�N�g���폜����ۂɎ��s
	!CTest()
	{
		System::Console::WriteLine(L"�t�@�C�i���C�U({0})", m_name);//.Net Framework���̕�����W���o��
	}
private:
	//�t�B�[���h
	System::String^ m_name;//���O
};

//----------------------------------------
//���C���֐�
int main(array<System::String^>^ args)//.Net Framework�X�^�C��
//int main(const int argc, const char* argv[])//C/C++����X�^�C���i�����OK�j
{
	{
		CTest^ obj1 = gcnew CTest(L"�e�X�g1");//gcnew�ŃC���X�^���X����
		obj1->showName();//�A���[���Z�q�Ń����o�[�A�N�Z�X
		CTest^% obj1ex = obj1;//�n���h���̎Q��
		delete obj1;//delete�͂��̂܂�
	}
	{
		CTest obj2(L"�e�X�g2");//���ڃ��[�J���ϐ��Ƃ��ăC���X�^���X�������Ȃ�
		obj2.showName();
	}
	{
		CTest^ obj3 = gcnew CTest(L"�e�X�g3");//gcnew�ŃC���X�^���X����
		obj3->showName();
		//delete obj3;//delete���Ȃ�
	}
	//�����I�ȃK�x�[�W�R���N�V�����Ăяo��
	//�������S�~������邪�A�S�~�ƔF�������܂Ŏ��Ԃ������邱�Ƃ�����
	System::Console::WriteLine(L"ToralMemory={0}", System::GC::GetTotalMemory(false));//�m�ۍς݃������\��
	System::GC::Collect();
	System::Console::WriteLine(L"ToralMemory={0}", System::GC::GetTotalMemory(false));//�m�ۍς݃������\��
	//�I��
	System::Console::WriteLine(L"�I��");
	return EXIT_SUCCESS;
}

#else

#include <stdio.h>
#include <stdlib.h>

//----------------------------------------
//�ȈՔŃX�}�[�g�|�C���^�[�̃e���v���[�g�N���X
//Boost C++ �� smart_ptr �̂悤�ɁA�폜�������w�肷��悤�ȋ@�\�͂Ȃ�
template<class T>
class CSmartPtr
{
private:
	//�Q�Ə��^
	struct T_REF_INFO
	{
		//�t�B�[���h
		T* m_realObj;  //�{���̃I�u�W�F�N�g
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
	//�Q�ƃJ�E���^�J�E���g�A�b�v
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
class CTest
{
public:
	//���\�b�h
	//���O�\��
	void showName() const
	{
		printf("���O=\"%s\"\n", m_name);
	}
public:
	//�R���X�g���N�^
	CTest(const char* name) :
		m_name(name)
	{
		printf("�R���X�g���N�^(%s)\n", m_name);
	}
	//�f�X�g���N�^
	~CTest()
	{
		printf("�f�X�g���N�^(%s)\n", m_name);
	}
private:
	//�t�B�[���h
	const char* m_name;//���O
};

//----------------------------------------
//�e�X�g���C���֐�
int main(const int argc, const char* argv[])
{
	{
		CSmartPtr<CTest> obj1 = new CTest("�e�X�g1");//�C���X�^���X�𐶐����ăX�}�[�g�|�C���^�ň���
		obj1->showName();//�A���[���Z�q�Ń����o�[�A�N�Z�X
		obj1 = nullptr;//delete�͎g�p�����Anullptr�̑���Ŕj��
	}
	{
		CTest obj2("�e�X�g2");//���ڃ��[�J���ϐ��Ƃ��ăC���X�^���X�������Ȃ�
		obj2.showName();
	}
	{
		CSmartPtr<CTest> obj3 = new CTest("�e�X�g3");//�C���X�^���X�𐶐����ăX�}�[�g�|�C���^�ň���
		obj3->showName();
		//obj1 = nullptr;//�����I�ɔj�����Ȃ�
	}
	
	//�I��
	return EXIT_SUCCESS;
}

#endif

// End of file

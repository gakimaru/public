#include <fstream>//�t�@�C�����o�̓X�g���[��
#include <boost/serialization/serialization.hpp>//�V���A���C�Y

#include <boost/archive/text_oarchive.hpp>//�e�L�X�g�o�̓A�[�J�C�u
#include <boost/archive/text_iarchive.hpp>//�e�L�X�g���̓A�[�J�C�u

#include <boost/archive/binary_oarchive.hpp>//�o�C�i���o�̓A�[�J�C�u
#include <boost/archive/binary_iarchive.hpp>//�o�C�i�����̓A�[�J�C�u

#include <boost/archive/xml_oarchive.hpp>//XML�o�̓A�[�J�C�u
#include <boost/archive/xml_iarchive.hpp>//XML���̓A�[�J�C�u

#include <boost/serialization/string.hpp>//std::string�p
#include <boost/serialization/vector.hpp>//std::vector�p
#include <boost/serialization/list.hpp>//std::list�p
#include <boost/serialization/map.hpp>//std::map�p
#include <boost/serialization/set.hpp>//std::set�p
#include <boost/serialization/deque.hpp>//std::deque�p

//#define USE_SPLIT_MEMBER//serialize()�֐���load()�֐���save()�֐��ɕ����Ďg���ꍇ�A���̃}�N����L��������
//#define USE_NON_INTRUSIVE_TYPE//��N���^�������ăV���A���C�Y����Ȃ炱�̃}�N����L��������

#ifdef USE_SPLIT_MEMBER
#include <boost/serialization/split_member.hpp>//BOOST_SERIALIZATION_SPLIT_MEMBER�p
#endif//USE_SPLIT_MEMBER

//--------------------------------------------------------------------------------

//--------------------
//�V���A���C�Y�ΏۃN���X�P
class CTest1
{
public:
	//�A�N�Z�b�T
	int getData1() const { return m_data1; }//�f�[�^1�擾
	void setData1(const int value){ m_data1 = value; }//�f�[�^1�X�V
	float getData2() const { return m_data2; }//�f�[�^2�擾
	void setData2(const float value){ m_data2 = value; }//�f�[�^2�X�V
	char getData3(const int index) const { return m_data3[index]; }//�f�[�^3�擾
	void setData3(const int index, const int value){ m_data3[index] = value; }//�f�[�^3�X�V
private:

	//�V���A���C�Y�p�e���v���[�g�֐�
	//���V���A���C�Y�ƃf�V���A���C�Y�̋��ʏ���
	//��private�X�R�[�v�ɂ�����Ńt�����h�N���X��ݒ肷��
	friend class boost::serialization::access;
#ifndef USE_SPLIT_MEMBER
	template<class Archive>
	void serialize(Archive& arc, const unsigned int version)
	{
		printf("serialize:version=%d\n", version);//�o�[�W������\��
		arc & m_data1;//�f�[�^1 ���A�[�J�C�u�� & ���Z�q�Ńf�[�^��n��
		arc & m_data2 & m_data3;//�f�[�^2 & �f�[�^3 ���A�����ăf�[�^��n�����Ƃ��\
	}
#else//USE_SPLIT_MEMBER
	BOOST_SERIALIZATION_SPLIT_MEMBER();
	template<class Archive>
	void save(Archive& arc, const unsigned int version) const
	{
		printf("save:version=%d\n", version);//�o�[�W������\��
		arc & m_data1;//�f�[�^1
		arc & m_data2 & m_data3;//�f�[�^2 & �f�[�^3
	}
	template<class Archive>
	void load(Archive& arc, const unsigned int version)
	{
		printf("load:version=%d\n", version);//�o�[�W������\��
		arc & m_data1;//�f�[�^1
		arc & m_data2 & m_data3;//�f�[�^2 & �f�[�^3
	}
#endif//USE_SPLIT_MEMBER
private:
	//�t�B�[���h
	int m_data1;//�f�[�^1�Fint�^
	float m_data2;//�f�[�^2�Ffloat�^
	char m_data3[3];//�f�[�^3�F�z��^
};
//--------------------
//�V���A���C�Y�ݒ�
BOOST_CLASS_VERSION(CTest1, 99);//�o�[�W�����ݒ�
BOOST_CLASS_TRACKING(CTest1, boost::serialization::track_never);//VC++�ŃG���[ C4308��������邽�߂̐ݒ�

//--------------------
//�V���A���C�Y�e�X�g�P�F�e�L�X�g�A�[�J�C�u
void serializeTest1()
{
	printf("--------------------\n");
	printf("�V���A���C�Y�F�e�L�X�g�A�[�J�C�u\n");
	//�I�u�W�F�N�g����
	CTest1 obj;
	//�e�X�g�f�[�^���Z�b�g
	obj.setData1(123);
	obj.setData2(4.56f);
	obj.setData3(0, 7);
	obj.setData3(1, 8);
	obj.setData3(2, 9);
	//���s�O�̏�ԕ\��
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
	//�V���A���C�Y
	std::ofstream stream("test1.txt");//�t�@�C���o�̓X�g���[������
	boost::archive::text_oarchive arc(stream);//�o�̓A�[�J�C�u�����F�e�L�X�g�A�[�J�C�u
	arc << obj;//�V���A���C�Y
	stream.close();//�X�g���[�����N���[�Y
}
//--------------------
//�f�V���A���C�Y�e�X�g�P�F�e�L�X�g�A�[�J�C�u
void deserializeTest1()
{
	printf("--------------------\n");
	printf("�f�V���A���C�Y�F�e�L�X�g�A�[�J�C�u\n");
	//�I�u�W�F�N�g����
	CTest1 obj;
	//�f�V���A���C�Y
	std::ifstream stream("test1.txt");//�t�@�C�����̓X�g���[������
	boost::archive::text_iarchive arc(stream);//���̓A�[�J�C�u�����F�e�L�X�g�A�[�J�C�u
	arc >> obj;//�f�V���A���C�Y
	stream.close();//�X�g���[�����N���[�Y
	//���ʂ�\��
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
}
//--------------------
//�V���A���C�Y���f�V���A���C�Y�e�X�g�P�F�e�L�X�g�A�[�J�C�u
void test1()
{
	//�V���A���C�Y
	serializeTest1();
	//�f�V���A���C�Y
	deserializeTest1();
}

//--------------------------------------------------------------------------------

//--------------------
//�V���A���C�Y�e�X�g�Q�F�o�C�i���A�[�J�C�u
void serializeTest2()
{
	printf("--------------------\n");
	printf("�V���A���C�Y�F�o�C�i���A�[�J�C�u\n");
	//�I�u�W�F�N�g����
	CTest1 obj;
	//�e�X�g�f�[�^���Z�b�g
	obj.setData1(123);
	obj.setData2(4.56f);
	obj.setData3(0, 7);
	obj.setData3(1, 8);
	obj.setData3(2, 9);
	//���s�O�̏�ԕ\��
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
	//�V���A���C�Y
	std::ofstream stream("test2.bin");//�t�@�C���o�̓X�g���[������
	boost::archive::binary_oarchive arc(stream);//�o�̓A�[�J�C�u�����F�o�C�i���A�[�J�C�u
	arc << obj;//�V���A���C�Y
	stream.close();//�X�g���[�����N���[�Y
}
//--------------------
//�f�V���A���C�Y�e�X�g�Q�F�o�C�i���A�[�J�C�u
void deserializeTest2()
{
	printf("--------------------\n");
	printf("�f�V���A���C�Y�F�o�C�i���A�[�J�C�u\n");
	//�I�u�W�F�N�g����
	CTest1 obj;
	//�f�V���A���C�Y
	std::ifstream stream("test2.bin");//�t�@�C�����̓X�g���[������
	boost::archive::binary_iarchive arc(stream);//���̓A�[�J�C�u�����F�o�C�i���A�[�J�C�u
	arc >> obj;//�f�V���A���C�Y
	stream.close();//�X�g���[�����N���[�Y
	//���ʂ�\��
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
}
//--------------------
//�V���A���C�Y���f�V���A���C�Y�e�X�g�Q�F�o�C�i���A�[�J�C�u
void test2()
{
	//�V���A���C�Y
	serializeTest2();
	//�f�V���A���C�Y
	deserializeTest2();
}

//--------------------------------------------------------------------------------

//--------------------
//�V���A���C�Y�ΏۃN���X�R
class CTest3
{
public:
	//�A�N�Z�b�T
	int getData1() const { return m_data1; }//�f�[�^1�擾
	void setData1(const int value){ m_data1 = value; }//�f�[�^1�X�V
	float getData2() const { return m_data2; }//�f�[�^2�擾
	void setData2(const float value){ m_data2 = value; }//�f�[�^2�X�V
	char getData3(const int index) const { return m_data3[index]; }//�f�[�^3�擾
	void setData3(const int index, const int value){ m_data3[index] = value; }//�f�[�^3�X�V
private:
	//�V���A���C�Y�p�e���v���[�g�֐�
	//���V���A���C�Y�ƃf�V���A���C�Y�̋��ʏ���
	//��private�X�R�[�v�ɂ�����Ńt�����h�N���X��ݒ肷��
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& arc, const unsigned int version)
	{
		printf("serialize:version=%d\n", version);//�o�[�W������\��
		arc & BOOST_SERIALIZATION_NVP(m_data1);//�f�[�^1 ���A�[�J�C�u�� & ���Z�q�Ńf�[�^��n��
		arc & BOOST_SERIALIZATION_NVP(m_data2) & BOOST_SERIALIZATION_NVP(m_data3);//�f�[�^2 & �f�[�^3 ���A�����ăf�[�^��n�����Ƃ��\
	}
private:
	//�t�B�[���h
	int m_data1;//�f�[�^1�Fint�^
	float m_data2;//�f�[�^2�Ffloat�^
	char m_data3[3];//�f�[�^3�F�z��^
};
//--------------------
//�V���A���C�Y�ݒ�
BOOST_CLASS_VERSION(CTest3, 99);//�o�[�W�����ݒ�

//--------------------
//�V���A���C�Y�e�X�g�R�FXML�A�[�J�C�u
void serializeTest3()
{
	printf("--------------------\n");
	printf("�V���A���C�Y�FXML�A�[�J�C�u\n");
	//�I�u�W�F�N�g����
	CTest3 obj;
	//�e�X�g�f�[�^���Z�b�g
	obj.setData1(123);
	obj.setData2(4.56f);
	obj.setData3(0, 7);
	obj.setData3(1, 8);
	obj.setData3(2, 9);
	//���s�O�̏�ԕ\��
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
	//�V���A���C�Y
	std::ofstream stream("test3.xml");//�t�@�C���o�̓X�g���[������
	boost::archive::xml_oarchive arc(stream);//�o�̓A�[�J�C�u�����FXML�A�[�J�C�u
	arc << BOOST_SERIALIZATION_NVP(obj);//�V���A���C�Y
	stream.close();//�X�g���[�����N���[�Y
}
//--------------------
//�f�V���A���C�Y�e�X�g�R�FXML�A�[�J�C�u
void deserializeTest3()
{
	printf("--------------------\n");
	printf("�f�V���A���C�Y�FXML�A�[�J�C�u\n");
	//�I�u�W�F�N�g����
	CTest3 obj;
	//�f�V���A���C�Y
	std::ifstream stream("test3.xml");//�t�@�C�����̓X�g���[������
	boost::archive::xml_iarchive arc(stream);//���̓A�[�J�C�u�����FXML�A�[�J�C�u
	arc >> BOOST_SERIALIZATION_NVP(obj);//�f�V���A���C�Y
	stream.close();//�X�g���[�����N���[�Y
	//���ʂ�\��
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
}
//--------------------
//�V���A���C�Y���f�V���A���C�Y�e�X�g�R�FXML�A�[�J�C�u
void test3()
{
	//�V���A���C�Y
	serializeTest3();
	//�f�V���A���C�Y
	deserializeTest3();
}

//--------------------------------------------------------------------------------

//--------------------
//�V���A���C�Y�ΏۃN���X�S
//�����N���X
class CTest4sub
{
public:
	//�A�N�Z�b�T
	int getVal1() const { return m_val1; }//�l1�擾
	void setVal1(const int value){ m_val1 = value; }//�l1�X�V
	int getVal2() const { return m_val2; }//�l2�擾
	void setVal2(const int value){ m_val2 = value; }//�l2�X�V
private:
#ifndef USE_NON_INTRUSIVE_TYPE
	//�V���A���C�Y�p�e���v���[�g�֐�
	//���V���A���C�Y�ƃf�V���A���C�Y�̋��ʏ���
	//��private�X�R�[�v�ɂ�����Ńt�����h�N���X��ݒ肷��
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& arc, const unsigned int version)
	{
		printf("sub::serialize:version=%d\n", version);//�o�[�W������\��
		arc & BOOST_SERIALIZATION_NVP(m_val1)//�l1
		    & BOOST_SERIALIZATION_NVP(m_val2);//�l2
	}
private:
#else//USE_NON_INTRUSIVE_TYPE
public:
#endif//USE_NON_INTRUSIVE_TYPE
	//�t�B�[���h
	int m_val1;//�l1
	int m_val2;//�l2
};
#ifdef USE_NON_INTRUSIVE_TYPE
//��N���^�V���A���C�Y�֐�
namespace boost{
	namespace serialization{
		template <class Archive>
		void serialize(Archive& arc, CTest4sub& sub, const unsigned int version)
		{
			printf("[non-intrusive]sub::serialize:version=%d\n", version);//�o�[�W������\��
			arc & BOOST_SERIALIZATION_NVP(sub.m_val1)//�l1
				& BOOST_SERIALIZATION_NVP(sub.m_val2);//�l2
		}
	}
}
#endif//USE_NON_INTRUSIVE_TYPE
//�f�[�^�N���X
class CTest4
{
public:
	//�A�N�Z�b�T
	int getData1() const { return m_data1; }//�f�[�^1�擾
	void setData1(const int value){ m_data1 = value; }//�f�[�^1�X�V
	float getData2() const { return m_data2; }//�f�[�^2�擾
	void setData2(const float value){ m_data2 = value; }//�f�[�^2�X�V
	char getData3(const int index) const { return m_data3[index]; }//�f�[�^3�擾
	void setData3(const int index, const int value){ m_data3[index] = value; }//�f�[�^3�X�V
	CTest4sub& getData4(){ return m_data4; }//�f�[�^4�擾
	CTest4sub& getData5(const int index){ return m_data5[index]; }//�f�[�^5�擾
	CTest4sub* getData6(){ return m_data6; }//�f�[�^6�擾
	void setData6(CTest4sub* obj){ m_data6 = obj; }//�f�[�^6�X�V
	CTest4sub* getData7(){ return m_data7; }//�f�[�^7�擾
	void setData7(CTest4sub* obj){ m_data7 = obj; }//�f�[�^7�X�V
private:
	//�V���A���C�Y�p�e���v���[�g�֐�
	//���V���A���C�Y�ƃf�V���A���C�Y�̋��ʏ���
	//��private�X�R�[�v�ɂ�����Ńt�����h�N���X��ݒ肷��
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& arc, const unsigned int version)
	{
		printf("serialize:version=%d\n", version);//�o�[�W������\��
		arc & BOOST_SERIALIZATION_NVP(m_data1)//�f�[�^1
			& BOOST_SERIALIZATION_NVP(m_data2)//�f�[�^2
			& BOOST_SERIALIZATION_NVP(m_data3)//�f�[�^3
			& BOOST_SERIALIZATION_NVP(m_data4)//�f�[�^4
			& BOOST_SERIALIZATION_NVP(m_data5)//�f�[�^5
			& BOOST_SERIALIZATION_NVP(m_data6)//�f�[�^6
			& BOOST_SERIALIZATION_NVP(m_data7);//�f�[�^7
	}
private:
	//�t�B�[���h
	int m_data1;//�f�[�^1�Fint�^
	float m_data2;//�f�[�^2�Ffloat�^
	char m_data3[3];//�f�[�^3�F�z��^
	CTest4sub m_data4;//�f�[�^�S�F�\����
	CTest4sub m_data5[2];//�f�[�^�T�F�\���̂̔z��
	CTest4sub* m_data6;//�f�[�^�U�F�\���̂̃|�C���^
	CTest4sub* m_data7;//�f�[�^�V�F�\���̂̃|�C���^�i�k�����̓���m�F�p�j
};
//--------------------
//�V���A���C�Y�ݒ�
BOOST_CLASS_VERSION(CTest4, 99);//�o�[�W�����ݒ�
BOOST_CLASS_VERSION(CTest4sub, 100);//�o�[�W�����ݒ�

//--------------------
//�V���A���C�Y�e�X�g�S�F���G�ȍ\���̃f�[�^�iXML�A�[�J�C�u�j
void serializeTest4()
{
	printf("--------------------\n");
	printf("�V���A���C�Y�F���G�ȍ\���̃f�[�^�iXML�A�[�J�C�u�j\n");
	//�I�u�W�F�N�g����
	CTest4 obj;
	//�e�X�g�f�[�^���Z�b�g
	obj.setData1(123);
	obj.setData2(4.56f);
	obj.setData3(0, 7);
	obj.setData3(1, 8);
	obj.setData3(2, 9);
	obj.getData4().setVal1(10);
	obj.getData4().setVal2(11);
	obj.getData5(0).setVal1(12);
	obj.getData5(0).setVal2(13);
	obj.getData5(1).setVal1(14);
	obj.getData5(1).setVal2(15);
	obj.setData6(new CTest4sub());//�|�C���^�ϐ��ɂ̓������m�ۂ����I�u�W�F�N�g���Z�b�g
	obj.getData6()->setVal1(16);
	obj.getData6()->setVal2(17);
	obj.setData7(nullptr);//�k���|�C���^���Z�b�g
	//���s�O�̏�ԕ\��
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
	printf("data4={val1=%d, val2=%d}\n", obj.getData4().getVal1(), obj.getData4().getVal2());
	printf("data5[0]={val1=%d, val2=%d}\n", obj.getData5(0).getVal1(), obj.getData5(0).getVal2());
	printf("data5[1]={val1=%d, val2=%d}\n", obj.getData5(1).getVal1(), obj.getData5(1).getVal2());
	printf("data6={val1=%d, val2=%d}\n", obj.getData6()->getVal1(), obj.getData6()->getVal2());
	printf("data7=0x%p\n", obj.getData7());
	//�V���A���C�Y
	std::ofstream stream("test4.xml");//�t�@�C���o�̓X�g���[������
	boost::archive::xml_oarchive arc(stream);//�o�̓A�[�J�C�u�����FXML�A�[�J�C�u
	arc << BOOST_SERIALIZATION_NVP(obj);//�V���A���C�Y
	stream.close();//�X�g���[�����N���[�Y
}
//--------------------
//�f�V���A���C�Y�e�X�g�S�F���G�ȍ\���̃f�[�^�iXML�A�[�J�C�u�j
void deserializeTest4()
{
	printf("--------------------\n");
	printf("�f�V���A���C�Y�F���G�ȍ\���̃f�[�^�iXML�A�[�J�C�u�j\n");
	//�I�u�W�F�N�g����
	CTest4 obj;
	//�f�V���A���C�Y
	std::ifstream stream("test4.xml");//�t�@�C�����̓X�g���[������
	boost::archive::xml_iarchive arc(stream);//���̓A�[�J�C�u�����FXML�A�[�J�C�u
	arc >> BOOST_SERIALIZATION_NVP(obj);//�f�V���A���C�Y
	stream.close();//�X�g���[�����N���[�Y
	//���ʂ�\��
	printf("data1=%d\n", obj.getData1());
	printf("data2=%.2f\n", obj.getData2());
	printf("data3={%d, %d, %d}\n", obj.getData3(0), obj.getData3(1), obj.getData3(2));
	printf("data4={val1=%d, val2=%d}\n", obj.getData4().getVal1(), obj.getData4().getVal2());
	printf("data5[0]={val1=%d, val2=%d}\n", obj.getData5(0).getVal1(), obj.getData5(0).getVal2());
	printf("data5[1]={val1=%d, val2=%d}\n", obj.getData5(1).getVal1(), obj.getData5(1).getVal2());
	printf("data6={val1=%d, val2=%d}\n", obj.getData6()->getVal1(), obj.getData6()->getVal2());
	printf("data7=0x%p\n", obj.getData7());
}
//--------------------
//�V���A���C�Y���f�V���A���C�Y�e�X�g�S�F���G�ȍ\���̃f�[�^�iXML�A�[�J�C�u�j
void test4()
{
	//�V���A���C�Y
	serializeTest4();
	//�f�V���A���C�Y
	deserializeTest4();
}

//--------------------------------------------------------------------------------

//--------------------
//�e�X�g
int main()
{
	test1();
	test2();
	test3();
	test4();
}

// End of file

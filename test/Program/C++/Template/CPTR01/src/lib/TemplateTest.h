//�e���v���[�g�֐��^�e���v���[�g�N���X�^��e���v���[�g�N���X�̐錾

#pragma once
#ifndef __TEMPLATE_TEST_H__
#define __TEMPLATE_TEST_H__

void normalFunc();

template<typename T>T min(const T l, const T r);//���F���̒��x�̓��e�Ȃ�w�b�_�[��ɃR�[�h�𒼐ڋL�q����ׂ������A����̓e�X�g�ׂ̈� .inl �Ɏ������𕪂��Ă���B
template<typename T>T max(const T l, const T r);//�i����j

template<class T>
class template_class
{
private:
	T var;
public:
	template_class(const T par);
	~template_class();
public:
	void test() const;
};

class base1
{
public:
	void foo() const;
};

class base2
{
public:
	virtual void foo() const;
};

template<class T>
class base3
{
public:
	void base_foo() const;
};

class derived1a : public base1
{
public:
	void foo() const;
};

class derived1b : public base1
{
public:
	void foo() const;
};

class derived2a : public base2
{
public:
	virtual void foo() const;
};

class derived2b : public base2
{
public:
	virtual void foo() const;
};

class derived3a : public base3<derived3a>
{
public:
	void foo() const;
};

class derived3b : public base3<derived3b>
{
public:
	void foo() const;
};

#endif//__TEMPLATE_TEST_H__

// End of file

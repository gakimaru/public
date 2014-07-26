#include <stdio.h>

#include <algorithm>

#include "sub.h"

//���ؗp�\���̂`
//�R�s�[�I�y���[�^
type_a& type_a::operator=(const type_a& rhs)
{
	var = rhs.var + 1000000;
	printf("                    operator=(const type_a& rhs) : var=%7d(%7d+1000000), this=%p, &rhs=%p\n", var, rhs.var, this, &rhs);
	return *this;
}
//�R�s�[�R���X�g���N�^
type_a::type_a(const type_a& obj) :
	var(obj.var + 2000000)
{
	printf("                    type_a(const type_a& obj)    : var=%7d(%7d+2000000), this=%p, &obj=%p\n", var, obj.var, this, &obj);
}
//�R���X�g���N�^
type_a::type_a(const int v) :
	var(v)
{
	printf("                    type_a(const int v)          : var=%7d, this=%p\n", var, this);
}
//�R���X�g���N�^
type_a::type_a() :
	var(0)
{
	printf("                    type_a()                     : var=%7d, this=%p\n", var, this);
}
//�f�X�g���N�^
type_a::~type_a()
{
	printf("                    ~type_a()                    : var=%7d, this=%p\n", var, this);
}

//���ؗp�\���̂a
//�R�s�[�I�y���[�^
type_b& type_b::operator=(const type_b& rhs)
{
	var = rhs.var + 1000000;
	printf("                    operator=(const type_b& rhs) : var=%7d(%7d+1000000), this=%p, &rhs=%p\n", var, rhs.var, this, &rhs);
	return *this;
}
//�R�s�[�R���X�g���N�^
type_b::type_b(const type_b& obj) :
var(obj.var + 2000000)
{
	printf("                    type_b(const type_b& obj)    : var=%7d(%7d+2000000), this=%p, &obj=%p\n", var, obj.var, this, &obj);
}
//���[�u�I�y���[�^
type_b& type_b::operator=(type_b&& rhs)
{
	var = rhs.var + 3000000;
	printf("                    operator=(type_b&& rhs)      : var=%7d(%7d+3000000), this=%p, &rhs=%p\n", var, rhs.var, this, &rhs);
	return *this;
}
//���[�u�R���X�g���N�^
type_b::type_b(type_b&& obj) :
var(obj.var + 4000000)
{
	printf("                    type_b(type_b&& obj)         : var=%7d(%7d+4000000), this=%p, &obj=%p\n", var, obj.var, this, &obj);
}
//�R���X�g���N�^
type_b::type_b(const int v) :
var(v)
{
	printf("                    type_b(const int v)          : var=%7d, this=%p\n", var, this);
}
//�R���X�g���N�^
type_b::type_b() :
var(0)
{
	printf("                    type_b()                     : var=%7d, this=%p\n", var, this);
}
//�f�X�g���N�^
type_b::~type_b()
{
	printf("                    ~type_b()                    : var=%7d, this=%p\n", var, this);
}

//�y�����r�z
//�p�^�[���`�@�F�߂�l�𕁒ʂɕԂ�
type_a getA(const int v)
{
	printf("    [type_a getA(const int v)]\n");
	printf("    type_a x;\n");
	type_a x;
	printf("    x.var = v; (&x=%p)\n", &x);
	x.var = v;
	printf("    return x;\n");
	return x;
}
//�p�^�[���`�A�F�߂�l��std::move()�ŕԂ�
type_a getA_v(const int v)
{
	printf("    [type_a getA_v(const int v)]\n");
	printf("    type_a x;\n");
	type_a x;
	printf("    x.var = v; (&x=%p)\n", &x);
	x.var = v;
	printf("    return std::move(x);\n");
	return std::move(x);
}
//�p�^�[���a�@�F�߂�l�𕁒ʂɕԂ�
type_b getB(const int v)
{
	printf("    [type_b getB(const int v)]\n");
	printf("    type_b x;\n");
	type_b x;
	printf("    x.var = v; (&x=%p)\n", &x);
	x.var = v;
	printf("    return x;\n");
	return x;
}
//�p�^�[���a�A�F�߂�l��std::move()�ŕԂ�
type_b getB_v(const int v)
{
	printf("    [type_a getB_v(const int v)]\n");
	printf("    type_b x;\n");
	type_b x;
	printf("    x.var = v; (&x=%p)\n", &x);
	x.var = v;
	printf("    return std::move(x);\n");
	return std::move(x);
}

//--------------------------------------------------------------------------------
//���S�Ȏ󂯓n���e�X�g

//Perfectforward�i���S�Ȏ󂯓n���j�e�X�g�p�\����

//���[�u�R���X�g���N�^
forPerfectForward::forPerfectForward(const forPerfectForward&& obj) :
	m_val1(obj.m_val1),
	m_val2(obj.m_val2)
{
	printf("move constructor (val1=%d, val2=%d)\n", m_val1, m_val2);
}
//�R�s�[�R���X�g���N�^
forPerfectForward::forPerfectForward(const forPerfectForward& obj) :
	m_val1(obj.m_val1),
	m_val2(obj.m_val2)
{
	printf("copy constructor (val1=%d, val2=%d)\n", m_val1, m_val2);
}
//�R���X�g���N�^�i�����l���E�Ӓl�Q�Ɠn���j
forPerfectForward::forPerfectForward(const int&& val1, const int&& val2) :
	m_val1(val1),
	m_val2(val2)
{
	printf("constructor[right value reference] (val1=%d, val2=%d)\n", m_val1, m_val2);
}
//�R���X�g���N�^�i�����l���Q�Ɠn���j
forPerfectForward::forPerfectForward(const int& val1, const int& val2) :
	m_val1(val1),
	m_val2(val2)
{
	printf("constructor[value referecnc] (val1=%d, val2=%d)\n", m_val1, m_val2);
}
//�f�t�H���g�R���X�g���N�^
forPerfectForward::forPerfectForward() :
	m_val1(0),
	m_val2(0)
{}

// End of file

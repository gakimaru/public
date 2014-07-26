#include <stdio.h>

#include <algorithm>

#include "sub.h"

//検証用構造体Ａ
//コピーオペレータ
type_a& type_a::operator=(const type_a& rhs)
{
	var = rhs.var + 1000000;
	printf("                    operator=(const type_a& rhs) : var=%7d(%7d+1000000), this=%p, &rhs=%p\n", var, rhs.var, this, &rhs);
	return *this;
}
//コピーコンストラクタ
type_a::type_a(const type_a& obj) :
	var(obj.var + 2000000)
{
	printf("                    type_a(const type_a& obj)    : var=%7d(%7d+2000000), this=%p, &obj=%p\n", var, obj.var, this, &obj);
}
//コンストラクタ
type_a::type_a(const int v) :
	var(v)
{
	printf("                    type_a(const int v)          : var=%7d, this=%p\n", var, this);
}
//コンストラクタ
type_a::type_a() :
	var(0)
{
	printf("                    type_a()                     : var=%7d, this=%p\n", var, this);
}
//デストラクタ
type_a::~type_a()
{
	printf("                    ~type_a()                    : var=%7d, this=%p\n", var, this);
}

//検証用構造体Ｂ
//コピーオペレータ
type_b& type_b::operator=(const type_b& rhs)
{
	var = rhs.var + 1000000;
	printf("                    operator=(const type_b& rhs) : var=%7d(%7d+1000000), this=%p, &rhs=%p\n", var, rhs.var, this, &rhs);
	return *this;
}
//コピーコンストラクタ
type_b::type_b(const type_b& obj) :
var(obj.var + 2000000)
{
	printf("                    type_b(const type_b& obj)    : var=%7d(%7d+2000000), this=%p, &obj=%p\n", var, obj.var, this, &obj);
}
//ムーブオペレータ
type_b& type_b::operator=(type_b&& rhs)
{
	var = rhs.var + 3000000;
	printf("                    operator=(type_b&& rhs)      : var=%7d(%7d+3000000), this=%p, &rhs=%p\n", var, rhs.var, this, &rhs);
	return *this;
}
//ムーブコンストラクタ
type_b::type_b(type_b&& obj) :
var(obj.var + 4000000)
{
	printf("                    type_b(type_b&& obj)         : var=%7d(%7d+4000000), this=%p, &obj=%p\n", var, obj.var, this, &obj);
}
//コンストラクタ
type_b::type_b(const int v) :
var(v)
{
	printf("                    type_b(const int v)          : var=%7d, this=%p\n", var, this);
}
//コンストラクタ
type_b::type_b() :
var(0)
{
	printf("                    type_b()                     : var=%7d, this=%p\n", var, this);
}
//デストラクタ
type_b::~type_b()
{
	printf("                    ~type_b()                    : var=%7d, this=%p\n", var, this);
}

//【動作比較】
//パターンＡ①：戻り値を普通に返す
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
//パターンＡ②：戻り値をstd::move()で返す
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
//パターンＢ①：戻り値を普通に返す
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
//パターンＢ②：戻り値をstd::move()で返す
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
//完全な受け渡しテスト

//Perfectforward（完全な受け渡し）テスト用構造体

//ムーブコンストラクタ
forPerfectForward::forPerfectForward(const forPerfectForward&& obj) :
	m_val1(obj.m_val1),
	m_val2(obj.m_val2)
{
	printf("move constructor (val1=%d, val2=%d)\n", m_val1, m_val2);
}
//コピーコンストラクタ
forPerfectForward::forPerfectForward(const forPerfectForward& obj) :
	m_val1(obj.m_val1),
	m_val2(obj.m_val2)
{
	printf("copy constructor (val1=%d, val2=%d)\n", m_val1, m_val2);
}
//コンストラクタ（初期値を右辺値参照渡し）
forPerfectForward::forPerfectForward(const int&& val1, const int&& val2) :
	m_val1(val1),
	m_val2(val2)
{
	printf("constructor[right value reference] (val1=%d, val2=%d)\n", m_val1, m_val2);
}
//コンストラクタ（初期値を参照渡し）
forPerfectForward::forPerfectForward(const int& val1, const int& val2) :
	m_val1(val1),
	m_val2(val2)
{
	printf("constructor[value referecnc] (val1=%d, val2=%d)\n", m_val1, m_val2);
}
//デフォルトコンストラクタ
forPerfectForward::forPerfectForward() :
	m_val1(0),
	m_val2(0)
{}

// End of file

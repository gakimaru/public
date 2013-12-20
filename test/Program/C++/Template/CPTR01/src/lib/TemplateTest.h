//テンプレート関数／テンプレートクラス／非テンプレートクラスの宣言

#pragma once
#ifndef __TEMPLATE_TEST_H__
#define __TEMPLATE_TEST_H__

void normalFunc();

template<typename T>T min(const T l, const T r);//注：この程度の内容ならヘッダー上にコードを直接記述するべきだが、今回はテストの為に .inl に実装部を分けている。
template<typename T>T max(const T l, const T r);//（同上）

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

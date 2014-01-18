#include <stdio.h>
#include <stdlib.h>
#include <typeinfo.h>

#define USE_RTTIT

class CBase
{
public:
	void print(){ printf("CBase\n"); }
	void moreBase(){}
	CBase() : var_base(1) {}
	int var_base;
};
class CDerived : public CBase
{
public:
	void print(){ printf("CDerived\n"); }
	void moreDerived(){}
	CDerived() : CBase(), var_derived(2) {}
	int var_derived;
};
class CBaseA
{
public:
	void print(){ printf("CBaseA\n"); }
	void moreBaseA(){}
	CBaseA() : var_base_a(3) {}
	int var_base_a;
};
class CBaseB
{
public:
	void print(){ printf("CBaseB\n"); }
	void moreBaseB(){}
	CBaseB() : var_base_b(4) {}
	int var_base_b;
};
class CDerivedAB : public CBaseA, public CBaseB
{
public:
	void print(){ printf("CDerivedAB\n"); }
	void moreDerivedAB(){}
	CDerivedAB() : CBaseA(), CBaseB(), var_derived_ab(5) {}
	int var_derived_ab;
};
class CDerivedC : public CDerivedAB
{
public:
	void print(){ printf("CDerivedC\n"); }
	void moreDerivedAB(){}
	void moreDerivedC(){}
	CDerivedC() : CDerivedAB(), var_derived_c(6) {}
	int var_derived_c;
};

class CVBase
{
public:
	virtual void print(){ printf("CVBase\n"); }
	virtual void moreBase(){}
	CVBase() : var_base(1) {}
	int var_base;
};
class CVDerived : public CVBase
{
public:
	void print() override { printf("CVDerived\n"); }
	virtual void moreDerived(){}
	CVDerived() : CVBase(), var_derived(2) {}
	int var_derived;
};
class CVBaseA
{
public:
	virtual void print(){ printf("CVBaseA\n"); }
	virtual void moreBaseA(){}
	CVBaseA() : var_base_a(3) {}
	int var_base_a;
};
class CVBaseB
{
public:
	virtual void print(){ printf("CVBaseB\n"); }
	virtual void moreBaseB(){}
	CVBaseB() : var_base_b(4) {}
	int var_base_b;
};
class CVDerivedAB : public CVBaseA, public CVBaseB
{
public:
	void print() override { printf("CVDerivedAB\n"); }
	virtual void moreDerivedAB(){}
	CVDerivedAB() : CVBaseA(), CVBaseB(), var_derived_ab(5) {}
	int var_derived_ab;
};
class CVDerivedC : public CVDerivedAB
{
public:
	void print() override { printf("CVDerivedC\n"); }
	void moreDerivedAB() override {}
	virtual void moreDerivedC(){}
	CVDerivedC() : CVDerivedAB(), var_derived_c(6) {}
	int var_derived_c;
};

class COther
{
public:
	void print(){ printf("COther\n"); }
	int var_other;
};

int main(const int argc, const char* argv[])
{
	//RTTIテスト

	//プリミティブ型
	{
		printf("\n- プリミティブ型 -\n");
		printf("int var_i = 0;\n");
		int var_i = 0;
		printf("int* var_p = nullptr;\n");
		int* var_p = nullptr;
		printf("typeid(int).name()    = \"%s\"\n", typeid(int).name());
		printf("typeid(int*).name()   = \"%s\"\n", typeid(int*).name());
		printf("typeid(var_i).name()  = \"%s\"\n", typeid(var_i).name());
		printf("typeid(var_p).name()  = \"%s\"\n", typeid(var_p).name());
		printf("typeid(*var_p).name() = \"%s\"\n", typeid(*var_p).name());
	}

	//（非仮想）クラス型
	{
		printf("\n- （非仮想）クラス型 -\n");
		printf("sizeof(CBase)      = %d\n", sizeof(CBase));
		printf("sizeof(CDerived)   = %d\n", sizeof(CDerived));
		printf("sizeof(CBaseA)     = %d\n", sizeof(CBaseA));
		printf("sizeof(CBaseB)     = %d\n", sizeof(CBaseB));
		printf("sizeof(CDerivedAB) = %d\n", sizeof(CDerivedAB));
		printf("sizeof(CDerivedC)  = %d\n", sizeof(CDerivedC));
		printf("CDerived* derived     = new CDerived;\n");
		CDerived* derived = new CDerived;
		printf("CBase* base           = new CBase;\n");
		CBase* base = new CBase;
		printf("CBase* base_poly      = derived;\n");
		CBase* base_poly = derived;
		printf("CDerivedC* derivedC   = new CDerivedC;\n");
		CDerivedAB* derivedC = new CDerivedC;
		printf("CDerivedAB* derivedAB = new CDerivedAB;\n");
		CDerivedAB* derivedAB = new CDerivedAB;
		printf("CBaseA* baseA         = new CBaseA;\n");
		CBaseA* baseA = new CBaseA;
		printf("CBaseA* baseA_poly    = derivedAB;\n");
		CBaseA* baseA_poly = derivedAB;
		printf("CBaseB* baseB         = new CBaseB;\n");
		CBaseB* baseB = new CBaseB;
		printf("CBaseB* baseB_poly    = derivedAB;\n");
		CBaseB* baseB_poly = derivedAB;
		printf("typeid(derived).name()     = \"%s\"\n", typeid(derived).name());
		printf("typeid(base).name()        = \"%s\"\n", typeid(base).name());
		printf("typeid(base_poly).name()   = \"%s\"\n", typeid(base_poly).name());
		printf("typeid(derivedAB).name()   = \"%s\"\n", typeid(derivedAB).name());
		printf("typeid(baseA).name()       = \"%s\"\n", typeid(baseA).name());
		printf("typeid(baseA_poly).name()  = \"%s\"\n", typeid(baseA_poly).name());
		printf("typeid(baseB).name()       = \"%s\"\n", typeid(baseB).name());
		printf("typeid(baseB_poly).name()  = \"%s\"\n", typeid(baseB_poly).name());
		printf("typeid(*derived).name()    = \"%s\"\n", typeid(*derived).name());
		printf("typeid(*base).name()       = \"%s\"\n", typeid(*base).name());
		printf("typeid(*base_poly).name()  = \"%s\"\n", typeid(*base_poly).name());
		printf("typeid(*derivedAB).name()  = \"%s\"\n", typeid(*derivedAB).name());
		printf("typeid(*baseA).name()      = \"%s\"\n", typeid(*baseA).name());
		printf("typeid(*baseA_poly).name() = \"%s\"\n", typeid(*baseA_poly).name());
		printf("typeid(*baseB).name()      = \"%s\"\n", typeid(*baseB).name());
		printf("typeid(*baseB_poly).name() = \"%s\"\n", typeid(*baseB_poly).name());
		printf("(typeid(*base)       == typeid(*derived))   = %s\n", typeid(*base)       == typeid(*derived)   ? "true" : "false");
		printf("(typeid(*base_poly)  == typeid(*derived))   = %s\n", typeid(*base_poly)  == typeid(*derived)   ? "true" : "false");
		printf("(typeid(*base_poly)  == typeid(CDerived))   = %s\n", typeid(*base_poly)  == typeid(CDerived)   ? "true" : "false");
		printf("(typeid(*baseA)      == typeid(*derivedAB)) = %s\n", typeid(*baseA)      == typeid(*derivedAB) ? "true" : "false");
		printf("(typeid(*baseA_poly) == typeid(*derivedAB)) = %s\n", typeid(*baseA_poly) == typeid(*derivedAB) ? "true" : "false");
		printf("(typeid(*baseB)      == typeid(*derivedAB)) = %s\n", typeid(*baseB)      == typeid(*derivedAB) ? "true" : "false");
		printf("(typeid(*baseB_poly) == typeid(*derivedAB)) = %s\n", typeid(*baseB_poly) == typeid(*derivedAB) ? "true" : "false");
		printf("derived->print();    ... "); derived->print();
		printf("base->print();       ... "); base->print();
		printf("base_poly->print();  ... "); base_poly->print();
		printf("derivedC->print();   ... "); derivedC->print();
		printf("derivedAB->print();  ... "); derivedAB->print();
		printf("baseA->print();      ... "); baseA->print();
		printf("baseA_poly->print(); ... "); baseA_poly->print();
		printf("baseB->print();      ... "); baseB->print();
		printf("baseB_poly->print(); ... "); baseB_poly->print();
		printf("derived                                   = %p\n", derived);
		printf("reinterpret_cast<CBase*>(derived)         = %p\n", reinterpret_cast<CBase*>(derived));
		printf("static_cast<CBase*>(derived)              = %p\n", static_cast<CBase*>(derived));
		printf("dynamic_cast<CBase*>(derived)             = %p\n", dynamic_cast<CBase*>(derived));
		printf("reinterpret_cast<COther*>(derived)        = %p\n", reinterpret_cast<COther*>(derived));
		printf("//static_cast<COther*>(derived)           = %p\n", nullptr);// static_cast<COther*>(derived));//コンパイルエラー
		printf("//dynamic_cast<COther*>(derived)          = %p\n", nullptr);// dynamic_cast<COther*>(derived));//コンパイルエラー
		printf("base                                      = %p\n", base);
		printf("reinterpret_cast<CDerived*>(base)         = %p\n", reinterpret_cast<CDerived*>(base));
		printf("static_cast<CDerived*>(base)              = %p\n", static_cast<CDerived*>(base));
		printf("//dynamic_cast<CDerived*>(base)           = %p\n", nullptr);// dynamic_cast<CDerived*>(base));//コンパイルエラー
		printf("reinterpret_cast<COther*>(base)           = %p\n", reinterpret_cast<COther*>(base));
		printf("//static_cast<COther*>(base)              = %p\n", nullptr);// static_cast<COther*>(base));//コンパイルエラー
		printf("//dynamic_cast<COther*>(base)             = %p\n", nullptr);// dynamic_cast<COther*>(base));//コンパイルエラー
		printf("derivedAB                                 = %p\n", derivedAB);
		printf("reinterpret_cast<CBaseA*>(derivedAB)      = %p\n", reinterpret_cast<CBaseA*>(derivedAB));
		printf("static_cast<CBaseA*>(derivedAB)           = %p\n", static_cast<CBaseA*>(derivedAB));
		printf("dynamic_cast<CBaseA*>(derivedAB)          = %p\n", dynamic_cast<CBaseA*>(derivedAB));
		printf("reinterpret_cast<CBaseB*>(derivedAB)      = %p\n", reinterpret_cast<CBaseB*>(derivedAB));
		printf("static_cast<CBaseB*>(derivedAB)           = %p\n", static_cast<CBaseB*>(derivedAB));
		printf("dynamic_cast<CBaseB*>(derivedAB)          = %p\n", dynamic_cast<CBaseB*>(derivedAB));
		printf("reinterpret_cast<COther*>(derivedAB)      = %p\n", reinterpret_cast<COther*>(derivedAB));
		printf("//static_cast<COther*>(derivedAB)         = %p\n", nullptr);// static_cast<COther*>(derivedAB));//コンパイルエラー
		printf("//dynamic_cast<COther*>(derivedAB)        = %p\n", nullptr);// dynamic_cast<COther*>(derivedAB));//コンパイルエラー
		printf("baseA                                     = %p\n", baseA);
		printf("reinterpret_cast<CDerivedAB*>(baseA)      = %p\n", reinterpret_cast<CDerivedAB*>(baseA));
		printf("static_cast<CDerivedAB*>(baseA)           = %p\n", static_cast<CDerivedAB *>(baseA));
		printf("//dynamic_cast<CDerivedAB*>(baseA)        = %p\n", nullptr);// dynamic_cast<CDerivedAB*>(baseA));//コンパイルエラー
		printf("reinterpret_cast<CBaseB*>(baseA)          = %p\n", reinterpret_cast<CBaseB*>(baseA));
		printf("//static_cast<CBaseB*>(baseA)             = %p\n", nullptr);// static_cast<CBaseB *>(baseA));//コンパイルエラー
		printf("//dynamic_cast<CBaseB*>(baseA)            = %p\n", nullptr);// dynamic_cast<CBaseB*>(baseA));//コンパイルエラー
		printf("reinterpret_cast<COther*>(baseA)          = %p\n", reinterpret_cast<COther*>(baseA));
		printf("//static_cast<COther*>(baseA)             = %p\n", nullptr);// static_cast<COther*>(baseA));//コンパイルエラー
		printf("//dynamic_cast<COther*>(baseA)            = %p\n", nullptr);// dynamic_cast<COther*>(baseA));//コンパイルエラー
		printf("baseA_poly                                = %p\n", baseA_poly);
		printf("reinterpret_cast<CDerivedAB*>(baseA_poly) = %p\n", reinterpret_cast<CDerivedAB*>(baseA_poly));
		printf("static_cast<CDerivedAB*>(baseA_poly)      = %p\n", static_cast<CDerivedAB *>(baseA_poly));
		printf("//dynamic_cast<CDerivedAB*>(baseA_poly)   = %p\n", nullptr);// dynamic_cast<CDerivedAB*>(baseA_poly));//コンパイルエラー
		printf("reinterpret_cast<CBaseB*>(baseA_poly)     = %p\n", reinterpret_cast<CBaseB*>(baseA_poly));
		printf("//static_cast<CBaseB*>(baseA_poly)        = %p\n", nullptr);// static_cast<CBaseB *>(baseA_poly));//コンパイルエラー
		printf("//dynamic_cast<CBaseB*>(baseA_poly)       = %p\n", nullptr);// dynamic_cast<CBaseB*>(baseA_poly));//コンパイルエラー
		printf("reinterpret_cast<COther*>(baseA_poly)     = %p\n", reinterpret_cast<COther*>(baseA_poly));
		printf("//static_cast<COther*>(baseA_poly)        = %p\n", nullptr);// static_cast<COther*>(baseA_poly));//コンパイルエラー
		printf("//dynamic_cast<COther*>(baseA_poly)       = %p\n", nullptr);// dynamic_cast<COther*>(baseA_poly));//コンパイルエラー
		printf("baseB                                     = %p\n", baseB);
		printf("reinterpret_cast<CDerivedAB*>(baseB)      = %p\n", reinterpret_cast<CDerivedAB*>(baseB));
		printf("static_cast<CDerivedAB*>(baseB)           = %p\n", static_cast<CDerivedAB *>(baseB));
		printf("//dynamic_cast<CDerivedAB*>(baseB)        = %p\n", nullptr);// dynamic_cast<CDerivedAB*>(baseB));//コンパイルエラー
		printf("reinterpret_cast<CBaseA*>(baseB)          = %p\n", reinterpret_cast<CBaseA*>(baseB));
		printf("//static_cast<CBaseA*>(baseB)             = %p\n", nullptr);// static_cast<CBaseA *>(baseB));//コンパイルエラー
		printf("//dynamic_cast<CBaseA*>(baseB)            = %p\n", nullptr);// dynamic_cast<CBaseA*>(baseB));//コンパイルエラー
		printf("reinterpret_cast<COther*>(baseB)          = %p\n", reinterpret_cast<COther*>(baseB));
		printf("//static_cast<COther*>(baseB)             = %p\n", nullptr);// static_cast<COther*>(baseB));//コンパイルエラー
		printf("//dynamic_cast<COther*>(baseB)            = %p\n", nullptr);// dynamic_cast<COther*>(baseB));//コンパイルエラー
		printf("baseB_poly                                = %p\n", baseB_poly);
		printf("reinterpret_cast<CDerivedAB*>(baseB_poly) = %p\n", reinterpret_cast<CDerivedAB*>(baseB_poly));
		printf("static_cast<CDerivedAB*>(baseB_poly)      = %p\n", static_cast<CDerivedAB *>(baseB_poly));
		printf("//dynamic_cast<CDerivedAB*>(baseB_poly)   = %p\n", nullptr);// dynamic_cast<CDerivedAB*>(baseB_poly));//コンパイルエラー
		printf("reinterpret_cast<CBaseA*>(baseB_poly)     = %p\n", reinterpret_cast<CBaseA*>(baseB_poly));
		printf("//static_cast<CBaseA*>(baseB_poly)        = %p\n", nullptr);// static_cast<CBaseA *>(baseB_poly));//コンパイルエラー
		printf("//dynamic_cast<CBaseA*>(baseB_poly)       = %p\n", nullptr);// dynamic_cast<CBaseA*>(baseB_poly));//コンパイルエラー
		printf("reinterpret_cast<COther*>(baseB_poly)     = %p\n", reinterpret_cast<COther*>(baseB_poly));
		printf("//static_cast<COther*>(baseB_poly)        = %p\n", nullptr);// static_cast<COther*>(baseB_poly));//コンパイルエラー
		printf("//dynamic_cast<COther*>(baseB_poly)       = %p\n", nullptr);// dynamic_cast<COther*>(baseB_poly));//コンパイルエラー
		delete derived;
		delete base;
		delete derivedC;
		delete derivedAB;
		delete baseA;
		delete baseB;
	}

	//仮想クラス型
	{
		printf("\n- 仮想クラス型 -\n");
		printf("sizeof(CVBase)      = %d\n", sizeof(CVBase));
		printf("sizeof(CVDerived)   = %d\n", sizeof(CVDerived));
		printf("sizeof(CVBaseA)     = %d\n", sizeof(CVBaseA));
		printf("sizeof(CVBaseB)     = %d\n", sizeof(CVBaseB));
		printf("sizeof(CVDerivedAB) = %d\n", sizeof(CVDerivedAB));
		printf("sizeof(CVDerivedC)  = %d\n", sizeof(CVDerivedC));
		printf("CVDerived* derived     = new CVDerived;\n");
		CVDerived* derived = new CVDerived;
		printf("CVBase* base           = new CVBase;\n");
		CVBase* base = new CVBase;
		printf("CVBase* base_poly      = derived;\n");
		CVBase* base_poly = derived;
		printf("CVDerivedC* derivedC   = new CVDerivedC;\n");
		CVDerivedC* derivedC = new CVDerivedC;
		printf("CVDerivedAB* derivedAB = new CVDerivedAB;\n");
		CVDerivedAB* derivedAB = new CVDerivedAB;
		printf("CVBaseA* baseA         = new CVBaseA;\n");
		CVBaseA* baseA = new CVBaseA;
		printf("CVBaseA* baseA_poly    = derivedAB;\n");
		CVBaseA* baseA_poly = derivedAB;
		printf("CVBaseB* baseB         = new CVBaseB;\n");
		CVBaseB* baseB = new CVBaseB;
		printf("CVBaseB* baseB_poly    = derivedAB;\n");
		CVBaseB* baseB_poly = derivedAB;
		printf("typeid(derived).name()     = \"%s\"\n", typeid(derived).name());
		printf("typeid(base).name()        = \"%s\"\n", typeid(base).name());
		printf("typeid(base_poly).name()   = \"%s\"\n", typeid(base_poly).name());
		printf("typeid(derivedAB).name()   = \"%s\"\n", typeid(derivedAB).name());
		printf("typeid(baseA).name()       = \"%s\"\n", typeid(baseA).name());
		printf("typeid(baseA_poly).name()  = \"%s\"\n", typeid(baseA_poly).name());
		printf("typeid(baseB).name()       = \"%s\"\n", typeid(baseB).name());
		printf("typeid(baseB_poly).name()  = \"%s\"\n", typeid(baseB_poly).name());
#ifdef USE_RTTIT
		printf("typeid(*derived).name()    = \"%s\"\n", typeid(*derived).name());//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("typeid(*base).name()       = \"%s\"\n", typeid(*base).name());//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("typeid(*base_poly).name()  = \"%s\"\n", typeid(*base_poly).name());//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("typeid(*derivedAB).name()  = \"%s\"\n", typeid(*derivedAB).name());//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("typeid(*baseA).name()      = \"%s\"\n", typeid(*baseA).name());//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("typeid(*baseA_poly).name() = \"%s\"\n", typeid(*baseA_poly).name());//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("typeid(*baseB).name()      = \"%s\"\n", typeid(*baseB).name());//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("typeid(*baseB_poly).name() = \"%s\"\n", typeid(*baseB_poly).name());//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("(typeid(*base)       == typeid(*derived))   = %s\n", typeid(*base)       == typeid(*derived)   ? "true" : "false");//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("(typeid(*base_poly)  == typeid(*derived))   = %s\n", typeid(*base_poly)  == typeid(*derived)   ? "true" : "false");//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("(typeid(*base_poly)  == typeid(CVDerived))  = %s\n", typeid(*base_poly)  == typeid(CVDerived)  ? "true" : "false");//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("(typeid(*baseA)      == typeid(*derivedAB)) = %s\n", typeid(*baseA)      == typeid(*derivedAB) ? "true" : "false");//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("(typeid(*baseA_poly) == typeid(*derivedAB)) = %s\n", typeid(*baseA_poly) == typeid(*derivedAB) ? "true" : "false");//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("(typeid(*baseB)      == typeid(*derivedAB)) = %s\n", typeid(*baseB)      == typeid(*derivedAB) ? "true" : "false");//RTTI無効時は実行時エラー（コンパイル時ワーニング）
		printf("(typeid(*baseB_poly) == typeid(*derivedAB)) = %s\n", typeid(*baseB_poly) == typeid(*derivedAB) ? "true" : "false");//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("derived->print();    ... "); derived->print();
		printf("base->print();       ... "); base->print();
		printf("base_poly->print();  ... "); base_poly->print();
		printf("derivedC->print();   ... "); derivedC->print();
		printf("derivedAB->print();  ... "); derivedAB->print();
		printf("baseA->print();      ... "); baseA->print();
		printf("baseA_poly->print(); ... "); baseA_poly->print();
		printf("baseB->print();      ... "); baseB->print();
		printf("baseB_poly->print(); ... "); baseB_poly->print();
		printf("derived                                    = %p\n", derived);
		printf("reinterpret_cast<CVBase*>(derived)         = %p\n", reinterpret_cast<CVBase*>(derived));
		printf("static_cast<CVBase*>(derived)              = %p\n", static_cast<CVBase*>(derived));
		printf("dynamic_cast<CVBase*>(derived)             = %p\n", dynamic_cast<CVBase*>(derived));
		printf("reinterpret_cast<COther*>(derived)         = %p\n", reinterpret_cast<COther*>(derived));
		printf("//static_cast<COther*>(derived)            = %p\n", nullptr);// static_cast<COther*>(derived));//コンパイルエラー
#ifdef USE_RTTIT
		printf("dynamic_cast<COther*>(derived)             = %p\n", dynamic_cast<COther*>(derived));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("base                                       = %p\n", base);
		printf("reinterpret_cast<CVDerived*>(base)         = %p\n", reinterpret_cast<CVDerived*>(base));
		printf("static_cast<CVDerived*>(base)              = %p\n", static_cast<CVDerived*>(base));
#ifdef USE_RTTIT
		printf("dynamic_cast<CVDerived*>(base)             = %p\n", dynamic_cast<CVDerived*>(base));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("reinterpret_cast<COther*>(base)            = %p\n", reinterpret_cast<COther*>(base));
		printf("//static_cast<COther*>(base)               = %p\n", nullptr);// static_cast<COther*>(base));//コンパイルエラー
#ifdef USE_RTTIT
		printf("dynamic_cast<COther*>(base)                = %p\n", dynamic_cast<COther*>(base));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("derivedAB                                  = %p\n", derivedAB);
		printf("reinterpret_cast<CVBaseA*>(derivedAB)      = %p\n", reinterpret_cast<CVBaseA*>(derivedAB));
		printf("static_cast<CVBaseA*>(derivedAB)           = %p\n", static_cast<CVBaseA*>(derivedAB));
		printf("dynamic_cast<CVBaseA*>(derivedAB)          = %p\n", dynamic_cast<CVBaseA*>(derivedAB));
		printf("reinterpret_cast<CVBaseB*>(derivedAB)      = %p\n", reinterpret_cast<CVBaseB*>(derivedAB));
		printf("static_cast<CVBaseB*>(derivedAB)           = %p\n", static_cast<CVBaseB*>(derivedAB));
		printf("dynamic_cast<CVBaseB*>(derivedAB)          = %p\n", dynamic_cast<CVBaseB*>(derivedAB));
		printf("reinterpret_cast<COther*>(derivedAB)       = %p\n", reinterpret_cast<COther*>(derivedAB));
		printf("//static_cast<COther*>(derivedAB)          = %p\n", nullptr);// static_cast<COther*>(derivedAB));//コンパイルエラー
#ifdef USE_RTTIT
		printf("dynamic_cast<COther*>(derivedAB)           = %p\n", dynamic_cast<COther*>(derivedAB));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("baseA                                      = %p\n", baseA);
		printf("reinterpret_cast<CVDerivedAB*>(baseA)      = %p\n", reinterpret_cast<CVDerivedAB*>(baseA));
		printf("static_cast<CVDerivedAB*>(baseA)           = %p\n", static_cast<CVDerivedAB *>(baseA));
#ifdef USE_RTTIT
		printf("dynamic_cast<CVDerivedAB*>(baseA)          = %p\n", dynamic_cast<CVDerivedAB*>(baseA));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("reinterpret_cast<CVBaseB*>(baseA)          = %p\n", reinterpret_cast<CVBaseB*>(baseA));
		printf("//static_cast<CVBaseB*>(baseA)             = %p\n", nullptr);// static_cast<CVBaseB*>(baseA));//コンパイルエラー
#ifdef USE_RTTIT
		printf("dynamic_cast<CVBaseB*>(baseA)              = %p\n", dynamic_cast<CVBaseB*>(baseA));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("reinterpret_cast<COther*>(baseA)           = %p\n", reinterpret_cast<COther*>(baseA));
		printf("//static_cast<COther*>(baseA)              = %p\n", nullptr);// static_cast<COther*>(baseA));//コンパイルエラー
		printf("//dynamic_cast<COther*>(baseA)             = %p\n", nullptr);// dynamic_cast<COther*>(baseA));//コンパイルエラー
		printf("baseA_poly                                 = %p\n", baseA_poly);
		printf("reinterpret_cast<CVDerivedAB*>(baseA_poly) = %p\n", reinterpret_cast<CVDerivedAB*>(baseA_poly));
		printf("static_cast<CVDerivedAB*>(baseA_poly)      = %p\n", static_cast<CVDerivedAB *>(baseA_poly));
#ifdef USE_RTTIT
		printf("dynamic_cast<CVDerivedAB*>(baseA_poly)     = %p\n", dynamic_cast<CVDerivedAB*>(baseA_poly));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("reinterpret_cast<CVBaseB*>(baseA_poly)     = %p\n", reinterpret_cast<CVBaseB*>(baseA_poly));
		printf("//static_cast<CVBaseB*>(baseA_poly)        = %p\n", nullptr);// static_cast<CVBaseB *>(baseA_poly));//コンパイルエラー
#ifdef USE_RTTIT
		printf("dynamic_cast<CVBaseB*>(baseA_poly)         = %p\n", dynamic_cast<CVBaseB*>(baseA_poly));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("reinterpret_cast<COther*>(baseA_poly)      = %p\n", reinterpret_cast<COther*>(baseA_poly));
		printf("//static_cast<COther*>(baseA_poly)         = %p\n", nullptr);// static_cast<COther*>(baseA_poly));//コンパイルエラー
		printf("//dynamic_cast<COther*>(baseA_poly)        = %p\n", nullptr);// dynamic_cast<COther*>(baseA_poly));//コンパイルエラー
		printf("baseB                                      = %p\n", baseB);
		printf("reinterpret_cast<CVDerivedAB*>(baseB)      = %p\n", reinterpret_cast<CVDerivedAB*>(baseB));
		printf("static_cast<CVDerivedAB*>(baseB)           = %p\n", static_cast<CVDerivedAB *>(baseB));
#ifdef USE_RTTIT
		printf("dynamic_cast<CVDerivedAB*>(baseB)          = %p\n", dynamic_cast<CVDerivedAB*>(baseB));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("reinterpret_cast<CVBaseA*>(baseB)          = %p\n", reinterpret_cast<CVBaseA*>(baseB));
		printf("//static_cast<CVBaseA*>(baseB)             = %p\n", nullptr);// static_cast<CVBaseA *>(baseB));//コンパイルエラー
#ifdef USE_RTTIT
		printf("dynamic_cast<CVBaseA*>(baseB)              = %p\n", dynamic_cast<CVBaseA*>(baseB));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("reinterpret_cast<COther*>(baseB)           = %p\n", reinterpret_cast<COther*>(baseB));
		printf("//static_cast<COther*>(baseB)              = %p\n", nullptr);// static_cast<COther*>(baseB));//コンパイルエラー
		printf("//dynamic_cast<COther*>(baseB)             = %p\n", nullptr);// dynamic_cast<COther*>(baseB));//コンパイルエラー
		printf("baseB_poly                                 = %p\n", baseB_poly);
		printf("reinterpret_cast<CVDerivedAB*>(baseB_poly) = %p\n", reinterpret_cast<CVDerivedAB*>(baseB_poly));
		printf("static_cast<CVDerivedAB*>(baseB_poly)      = %p\n", static_cast<CVDerivedAB *>(baseB_poly));
#ifdef USE_RTTIT
		printf("dynamic_cast<CVDerivedAB*>(baseB_poly)     = %p\n", dynamic_cast<CVDerivedAB*>(baseB_poly));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("reinterpret_cast<CVBaseA*>(baseB_poly)     = %p\n", reinterpret_cast<CVBaseA*>(baseB_poly));
		printf("//static_cast<CVBaseA*>(baseB_poly)        = %p\n", nullptr);// static_cast<CVBaseA *>(baseB_poly));//コンパイルエラー
#ifdef USE_RTTIT
		printf("dynamic_cast<CVBaseA*>(baseB_poly)         = %p\n", dynamic_cast<CVBaseA*>(baseB_poly));//RTTI無効時は実行時エラー（コンパイル時ワーニング）
#endif
		printf("reinterpret_cast<COther*>(baseB_poly)      = %p\n", reinterpret_cast<COther*>(baseB_poly));
		printf("//static_cast<COther*>(baseB_poly)         = %p\n", nullptr);// static_cast<COther*>(baseB_poly));//コンパイルエラー
		printf("//dynamic_cast<COther*>(baseB_poly)        = %p\n", nullptr);// dynamic_cast<COther*>(baseB_poly));//コンパイルエラー
		delete derived;
		delete base;
		delete derivedC;
		delete derivedAB;
		delete baseA;
		delete baseB;
	}

	return EXIT_SUCCESS;
}

// End of file

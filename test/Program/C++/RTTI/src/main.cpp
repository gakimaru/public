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

	extern int printDefinedMacro(const int argc, const char* argv[]);
	printDefinedMacro(argc, argv);

	extern int testConcatenateStr(const int argc, const char* argv[]);
	testConcatenateStr(argc, argv);

	extern int testConcatenateToken(const int argc, const char* argv[]);
	testConcatenateToken(argc, argv);

	extern int testDengerMacro(const int argc, const char* argv[]);
	testDengerMacro(argc, argv);

	extern int testFade(const int argc, const char* argv[]);
	testFade(argc, argv);

	extern int testAssert(const int argc, const char* argv[]);
	testAssert(argc, argv);

	return EXIT_SUCCESS;
}

//定義済みマクロ表示
int printDefinedMacro(const int argc, const char* argv[])
{
	printf("\n- printDefinedMacro -\n\n");
	printf("\n【ANSI C準拠の定義済みマクロ】\n");
	printf("__FILE__      = \"%s\"\n", __FILE__);
	printf("__LINE__      = %d\n", __LINE__);
	printf("__DATE__      = \"%s\"\n", __DATE__);
	printf("__TIME__      = \"%s\"\n", __TIME__);
	printf("__TIMESTAMP__ = \"%s\"\n", __TIMESTAMP__);
	printf("\n【Microsoft 固有の定義済みマクロ】\n");
	printf("__COUNTER__        = %d\n", __COUNTER__);	//←カウントアップを確認するために３回使用
	printf("__COUNTER__        = %d\n", __COUNTER__);	//←
	printf("__COUNTER__        = %d\n", __COUNTER__);	//←
	printf("__FUNCDNAME__      = \"%s\"\n", __FUNCDNAME__);
	printf("__FUNCSIG__        = \"%s\"\n", __FUNCSIG__);
	printf("__FUNCTION__       = \"%s\"\n", __FUNCTION__);
	printf("_INTEGRAL_MAX_BITS = %d\n", _INTEGRAL_MAX_BITS);
	printf("_M_IX86_FP         = %d\n", _M_IX86_FP);
	printf("_MSC_FULL_VER      = %d\n", _MSC_FULL_VER);
	printf("_MSC_VER           = %d\n", _MSC_VER);
	return 0;
}
//関数オーバーロード用のダミー関数（__FUNCDNAME__テスト用）
void printDefinedMacro()
{}

//文字列化マクロ
#define TO_STRING(x) #x

//マクロ展開付き文字列化マクロ
#define TO_STRING_EX(x) TO_STRING(x)

#include <stdio.h>
#include <assert.h>

//Visual C++ 固有の定義済みマクロ「__FUNCSIG__」を標準化するために、
//「__FUNC__」として再定義（他のビルド環境でも __FUNC__ を用いればソースコードを共通利用できるようにする）
#define __FUNC__ __FUNCSIG__

//ファイル名取得関数
const char* getFileName(const char* path)
{
	const char* p = path + strlen(path) - 1;
	while (p > path)
	{
		if (*p == '\\' || *p == '/')
			return p + 1;
		--p;
	}
	return path;
}

//定義済みマクロを活用したアサーション
#define MY_ASSERT(expr, msg) \
	if (!(expr)) \
	{ \
		fprintf(stderr, "------------------------------------------------------------\n"); \
		fprintf(stderr, "Assertion failed!\n"); \
		fprintf(stderr, "%s(%d): %s\n", getFileName(__FILE__), __LINE__, __FUNC__); \
		fprintf(stderr, "%s\n", #expr);	/* ←exprを # で文字列化 */ \
		fprintf(stderr, "%s\n", msg); \
		fprintf(stderr, "------------------------------------------------------------\n"); \
		assert(expr);	/* ←処理比較とabortのために、標準で用意されているassert()を実行 */ \
	}

//アサーションテスト
int testAssert(const int argc, const char* argv[])
{
	printf("\n- testAssert -\n\n");
	struct STRUCT
	{
		char memberA;
		short memberB;
		int memberC;
		char memberD;
	};
	MY_ASSERT(sizeof(STRUCT) == 8, "STRUCT構造体のサイズが8バイトではありません！");
	return 0;
}

//ファイル名取得関数
const char* getFileName2(const char* path, const size_t path_len)
{
	const char* p = path + path_len - 1;
	while (p > path)
	{
		if (*p == '\\' || *p == '/')
			return p + 1;
		--p;
	}
	return path;
}

//処理行情報作成マクロ
//#define MAKE_FUNC_LINE_INFO() getFileName2(__FILE__ "(" #__LINE__ "):" __FUNC__, strlen(__FILE__))//コンパイルエラー
//#define MAKE_FUNC_LINE_INFO() getFileName2(__FILE__ "(" TO_STRING(__LINE__) "):" __FUNC__ TO_STRING( [テスト!]) TO_STRING(123), strlen(__FILE__))
#define MAKE_FUNC_LINE_INFO() getFileName2(__FILE__ "(" TO_STRING_EX(__LINE__) "):" __FUNC__ TO_STRING( [テスト!]) TO_STRING(123), strlen(__FILE__))

//文字列連結テスト
int testConcatenateStr(const int argc, const char* argv[])
{
	printf("\n- testConcatenateStr -\n\n");
	const char* func_line_info = MAKE_FUNC_LINE_INFO();
	printf("MAKE_FUNC_LINE_INFO() = \"%s\"\n", func_line_info);
	return 0;
}

//幾つかの関数
//void functionForTokenConcatenateTestAAA01(){ printf("TEST: AAA-01\n"); }
//void functionForTokenConcatenateTestAAA02(){ printf("TEST: AAA-02\n"); }
//void functionForTokenConcatenateTestBBB01(){ printf("TEST: BBB-01\n"); }
//void functionForTokenConcatenateTestBBB02(){ printf("TEST: BBB-02\n"); }

//トークン連結演算子を使った関数定義マクロ
#define MAKE_TEST(ID, NO) \
	void functionForTokenConcatenateTest ## ID ## NO () \
	{ \
	printf("TEST: " #ID "-" #NO "\n"); \
	}

//幾つかの関数
MAKE_TEST(AAA, 01)
MAKE_TEST(AAA, 02)
MAKE_TEST(BBB, 01)
MAKE_TEST(BBB, 02)

//トークン連結演算子を使った関数呼び出しマクロ
#define TEST(ID, NO) functionForTokenConcatenateTest ## ID ## NO ()

//トークン連結テスト
int testConcatenateToken(const int argc, const char* argv[])
{
	printf("\n- testConcatenateToken -\n\n");
	TEST(AAA, 01);
	TEST(AAA, 02);
	TEST(BBB, 01);
	TEST(BBB, 02);
	return 0;
}

//最大値判定マクロ
#define MAX(a, b) (a > b ? a : b)

#define ONCE once
#pragma ONCE

int testDengerMacro(const int argc, const char* argv[])
{
	printf("\n- testDengerMacro -\n\n");
	int x = MAX(1, 2);     //結果：x=2
	int y = MAX(4, 3);     //結果：y=3
	int z = MAX(++x, ++y); //結果：z=5（期待値）⇒ z=6（実際）
	printf("x=%d, y=%d, z=%d\n", x, y, z);
	return 0;
}

//符号判定処理
int fsign(float val)
{
	return val < 0.f ? -1 : val > 0.f ? 1 : 0;
}

//フェード処理
class CFade
{
public:
	//ゴールに達しているか？
	bool isGoal() const { return m_now == m_goal; }
	//更新処理
	void update(float elapsed_time)
	{
		if (!isGoal())
		{
			int sign_before = fsign(m_now - m_goal);
			m_now += (m_gradual * elapsed_time);
			int sign_after = fsign(m_now - m_goal);
			if (sign_before != sign_after)
				m_now = m_goal;
		}
	}
	//フェード開始
	void start(float time, float begin, float end)
	{
		m_goal = end;
		m_gradual = (end - begin) / time;
	}
	//現在の状態を表示
	void debugPrint(int flame)
	{
		printf("%2d: now=%.3f, goal=%.3f, gradual=%.3f, isGoal()=%d\n", flame, m_now, m_goal, m_gradual, isGoal());
	}
public:
	//コンストラクタ
	CFade(float now) :
		m_now(now),
		m_goal(now),
		m_gradual(0.f)
	{}
private:
	//フィールド
	float m_now;    //現在の状態
	float m_goal;   //ゴール
	float m_gradual;//1秒あたりの変化量
};

//フェードテスト
int testFade(const int argc, const char* argv[])
{
	printf("\n- testFade -\n\n");

	//30フレーム想定で、1フレーム当たりの処理時間
	const float elapsed_time = 1.f / 30.f;
	printf("elapsed_time=%.3f\n", elapsed_time);
	int flame = 0;

	//フェードオブジェクトを初期化
	CFade fade(1.f);

	//フェード開始
	fade.start(1.5f, 1.f, 0.5f);//1.5秒かけて、最大(1.0）から半分（0.5）までフェード
	fade.debugPrint(flame++);

	//20フレームだけ更新
	for (int i = 0; i < 20; ++i)
	{
		fade.update(elapsed_time);//更新処理
		fade.debugPrint(flame++);
	}
	
	//フェードを途中変更
	fade.start(1.5f, 0.5f, 1.f);//1.5秒かけて、半分（0.5）から最大(1.0）までフェード

	//フェード完了まで更新
	while (!fade.isGoal())
	{
		fade.update(elapsed_time);//更新処理
		fade.debugPrint(flame++);
	}

	return 0;
}

// End of file

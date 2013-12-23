#include "process/composite.h"
#include "process/data_chara.h"
#include "process/data_map.h"
#include "proxies/proxy_chara.h"
#include "proxies/proxy_map.h"
#include "process/process.h"

namespace
{
	CComponent* s_component_top = nullptr;

	void initComponents()
	{
		CCompositeProcess* comp_map1 = new CCompositeMap(new CMapData("Map1"));
		CCompositeProcess* comp_map2 = new CCompositeMap(new CMapData("Map2"));
		CCompositeProcess* comp_chara1 = new CCompositeChara(new CCharaData("Chara1"));
		CCompositeProcess* comp_chara2 = new CCompositeChara(new CCharaData("Chara2"));
		s_component_top = comp_map1;
		comp_map1->addNext(comp_map2);
		comp_map1->addChild(comp_chara1);
		comp_map2->addChild(comp_chara2);
	}

	void printComponents(CComponent* p)
	{
		if (!p)
			return;
		while (p)
		{
			CComposite* comp = p->getComposition();
			if (comp)
			{
				CCompositeProcess* comp_proc = reinterpret_cast<CCompositeProcess*>(comp);
				comp_proc->getProxyPrint()->printName();
				comp_proc->getProxyPrint()->printMessage(123, "test!");
				comp_proc->getProxyUpdate()->update(1.23f);
				comp_proc->getProxyUpdate()->animation();
				comp_proc->getProxyDraw()->preDraw(1, nullptr);
				comp_proc->getProxyDraw()->postDraw(2, nullptr);
				printComponents(comp->getChildTop());
			}
			p = p->getNext();
		}
	}
	void printComponents()
	{
		printComponents(s_component_top);
	}

	void finalizeComponents()
	{
		if (s_component_top)
		{
			s_component_top->removeNextAll();
			delete s_component_top;
			s_component_top = nullptr;
		}
	}
};

void test()
{
	initComponents();
	printComponents();
	finalizeComponents();
}

// End of file

#include "process/composite.h"

//CCompositeProcess::CCompositeProcess() :
//CComposite(),
//m_proxyPrint(nullptr)
//{
//}

CCompositeProcess::CCompositeProcess(CProxyPrint* proxy_print, CProxyUpdate* proxy_update, CProxyDraw* proxy_draw) :
CComposite(),
m_proxyPrint(proxy_print),
m_proxyUpdate(proxy_update),
m_proxyDraw(proxy_draw)
{
}

// End of file

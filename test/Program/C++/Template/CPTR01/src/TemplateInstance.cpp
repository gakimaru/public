//テンプレート関数／テンプレートクラスの明示的なインスタンス化
//※コンパイル速度向上の為。

#include "lib/TemplateTest.inl"

template int min<int>(int, int);
template int max<int>(int, int);

template class template_class<int>;
template class template_class<double>;

template class base3<derived3a>;
template class base3<derived3b>;

// End of file

#include "sub.h"

//通常関数
bool predicate_func(const data_t& lhs, const data_t& rhs)
{
	return lhs.m_key < rhs.m_key;
}

// End of file

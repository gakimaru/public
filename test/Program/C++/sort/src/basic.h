//--------------------------------------------------------------------------------
//��{�֐�
#pragma once
#ifndef __BASIC_H
#define __BASIC_H

//#define USE_GCC//GCC�g�p���͂��̃}�N����L��������

//�A���C�������g�����iC++11�݊��j
#ifdef USE_GCC
//#define alignas(n) __attribute__((aligned(n)))//for GCC
//#define alignof(T) __alignof__(T)//for GCC
#else//USE_GCC
#define alignas(n) __declspec(align(n))//for Visual C++
#define alignof(T) __alignof(T)//for Visual C++
#endif//USE_GCC

//�A���C�������g�w��t���������m�ۊ֐�
#ifdef USE_GCC
#include <cstddef>//std::size_t�p
#include <stdlib.h>//posix_memalign()�p
#include <memory.h>//free()�p
inline void* _aligned_malloc(const std::size_t size, const std::size_t alignment)
{
	void *p;
	int ret = posix_memalign(&p, alignment, size);
	return (ret == 0) ? p : 0;
}
inline void _aligned_free(void* p)
{
	free(p);
}
#else//USE_GCC
#include <memory.h>//_aligned_malloc(), _aligned_free()�p
//void* _aligned_malloc(size_t size, size_t alignment);
//void _aligned_free(void* p);
#endif//USE_GCC

#endif//__BASIC_H

// End of file

#ifndef __VECTOR_H_
#define __VECTOR_H_

//#define USE_GCC//GCC���g�p
#define USE_SIMD//�����I��SIMD���Z���g�p����
//#define USE_LOAD_STORE//�����I�ȃ��[�h�^�X�g�A�������g�p ���g��Ȃ���������
//#define USE_MM_EXTRACT_PS//_mm_extract_ps�֐�(SSE3)���g�p ���g���������\�[�X�R�[�h�̌݊������m�������A�g��Ȃ���������

//�A���C�������g����
#ifdef USE_GCC
#define ATTR_ALIGN(n) __attribute__((aligned(n)))//for GCC
#else//USE_GCC
#define ATTR_ALIGN(n) __declspec(align(n))//for Visual C++
#endif//USE_GCC
#define ATTR_ALIGN16 ATTR_ALIGN(16)//16�o�C�g�A���C�������g�w��

//SIMD���Z�Ώۃf�[�^�p����
#ifdef USE_SIMD
#define ATTR_SIMD128 ATTR_ALIGN16//SIMD���Z�Ώۃf�[�^�p128�r�b�g�A���C�������g�w��
#else//USE_SIMD
#define ATTR_SIMD128
#endif//USE_SIMD

#ifdef USE_SIMD
//�����̃T���v���v���O�����ł́ASSE�`SSE4.1�̖��߂��g�p
//#include <x86intrin.h>//x86 instructions
//#include <mmintrin.h>//MMX(Pentium MMX!)
//#include <mm3dnow.h>//3dnow!(K6 - 2) (deprecated)
//#include <xmmintrin.h>//SSE + MMX (Pentium 3, Athlon XP)
//#include <emmintrin.h>//SSE2 + SSE + MMX (Pentiuem 4, Ahtlon 64)
//#include <pmmintrin.h>//SSE3 + SSE2 + SSE + MMX (Pentium 4 Prescott, Ahtlon 64 San Diego)
//#include <tmmintrin.h>//SSSE3 + SSE3 + SSE2 + SSE + MMX (Core 2, Bulldozer)
//#include <popcntintrin.h>//POPCNT(Core i7, Phenom subset of SSE4.2 and SSE4A)
//#include <ammintrin.h>//SSE4A + SSE3 + SSE2 + SSE + MMX (Phenom)
#include <smmintrin.h>//SSE4.1 + SSSE3 + SSE3 + SSE2 + SSE + MMX (Core i7, Bulldozer)
//#include <nmmintrin.h>//SSE4.2 + SSE4.1 + SSSE3 + SSE3 + SSE2 + SSE + MMX (Core i7, Bulldozer)
//#include <wmmintrin.h>//AES (Core i7 Westmere, Bulldozer)
//#include <immintrin.h>//AVX, SSE4_2 + SSE4_1 + SSSE3 + SSE3 + SSE2 + SSE + MMX (Core i7 Sandy Bridge, Bulldozer)
//#include <ivec.h>//MMX�ɂ�鐮���x�N�g���N���X
//#include <fvec.h>//SSE�ɂ�镂�������_�x�N�g���N���X
//#include <dvec.h>//SSE2�ɂ�鐮���x�N�g���N���X
#else//USE_SIMD
#include <math.h>//sqrt
#endif//USE_SIMD

#ifdef USE_SIMD
//----------
//�x�N�g���N���X�v�Z�p�֐�
//�񍀉��Z�q�p�֐��Ƌ��ʊ֐�
//��SIMD���Z��p
inline float getScalar(const __m128 val)
{
#ifdef USE_MM_EXTRACT_PS
	float f;
	_MM_EXTRACT_FLOAT(f, val, 0);//(dest, src, ndx): *((int*)&(dest)) = _mm_extract_ps((src), (ndx))
	return f;
#else//USE_MM_EXTRACT_PS
	return *reinterpret_cast<const float*>(&val);
#endif//USE_MM_EXTRACT_PS
}
inline __m128 calcAdd(const __m128 lhs, const __m128 rhs)//�񍀂̑����Z
{
	return _mm_add_ps(lhs, rhs);//ret �� {lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2], lhs[3] + rhs[3]}
}
inline __m128 calcSub(const __m128 lhs, const __m128 rhs)//�񍀂̈����Z
{
	return _mm_sub_ps(lhs, rhs);//ret �� {lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2], lhs[3] - rhs[3]}
}
inline __m128 calcMul(const __m128 lhs, const float rhs)//�񍀂̊|���Z
{
	return _mm_mul_ps(lhs, _mm_set1_ps(rhs));//ret �� {lhs[0] * rhs, lhs[1] * rhs, lhs[2] * rhs, lhs[3] * rhs}
}
inline __m128 calcDiv(const __m128 lhs, const float rhs)//�񍀂̊���Z
{
	return _mm_div_ps(lhs, _mm_set1_ps(rhs));//ret �� {lhs[0] / rhs, lhs[1] / rhs, lhs[2] / rhs, lhs[3] / rhs}
}
inline float calcDot(const __m128 lhs, const __m128 rhs)//���όv�Z
{
	return getScalar(//ret �� arg0[0]
	         _mm_dp_ps(lhs, rhs, 0x71)//arg0 �� {lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2] + 0.f, 0.f, 0.f, 0.f}
	       );
}
inline __m128 calcDot(const __m128 val)//���όv�Z
{
	return _mm_dp_ps(val, val, 0x77);//ret �� {val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + 0.f, (���l), (���l), 0.f}
}
inline __m128 calcSqrtDot(const __m128 val)//sqrt(����)�v�Z
{
	return _mm_sqrt_ps(//ret �� {sqrt(arg0[0]), sqrt(arg0[1]), sqrt(arg0[2]), sqrt(arg0[3])}
	         _mm_dp_ps(val, val, 0x77)//arg0 �� {val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + 0.f, (���l), (���l), 0.f}
	       );
}
inline __m128 calcCross(const __m128 lhs, const __m128 rhs)//�O�όv�Z
{
	return _mm_sub_ps(//ret �� {arg2[0] - arg5[0], arg2[1] - arg5[1], arg2[2] - arg5[2], arg2[3] - arg5[3]}
	         _mm_mul_ps(//arg2 �� {arg0[0] * arg1[0], arg0[1] * arg1[1], arg0[2] * arg1[2], arg0[3] * arg1[3]}
	           _mm_shuffle_ps(lhs, lhs, _MM_SHUFFLE(3, 0, 2, 1)),//arg0 �� {lhs[1], lhs[2], lhs[0], lhs[3]}
	           _mm_shuffle_ps(rhs, rhs, _MM_SHUFFLE(3, 1, 0, 2)) //arg1 �� {rhs[2], rhs[0], rhs[1], rhs[3]}
	         ),
	         _mm_mul_ps(//arg5 �� {arg3[0] * arg4[0], arg3[1] * arg4[1], arg3[2] * arg4[2], arg3[3] * arg4[3]}
	           _mm_shuffle_ps(lhs, lhs, _MM_SHUFFLE(3, 1, 0, 2)),//arg3 �� {lhs[2], lhs[0], lhs[1], lhs[3]}
	           _mm_shuffle_ps(rhs, rhs, _MM_SHUFFLE(3, 0, 2, 1)) //arg4 �� {rhs[1], rhs[2], rhs[0], rhs[3]}
	         )
	       );
	return lhs;
}
inline float calcNorm2(const __m128 val)//�m����^2�v�Z
{
	return getScalar(//ret �� arg0[0]
	         calcDot(val)//arg0 �� {val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + 0.f, (���l), (���l), 0.f}
	       );
}
inline float calcNorm(const __m128 val)//�m�����v�Z
{
	return getScalar(//ret �� arg0[0]
	         calcSqrtDot(val)//arg0 �� {sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + 0.f), (���l), (���l), 0.f}
	       );
}
inline __m128 calcNormalize(const __m128 val)//���K��
{
	return _mm_div_ps(//ret �� {arg1[0] / arg0[0], arg1[1] / arg0[1], arg1[2] / arg0[2], arg1[3] / arg0[3]}
	         val,            //arg0: val
	         calcSqrtDot(val)//arg1 �� {sqrt(val[0] * val[0] + val[1] * val[1] + val[2] * val[2] + 0.f), (���l), (���l), 0.f}
	       );
}
inline float calcNormalizeDot(const __m128 lhs, const __m128 rhs)//���K���x�N�g���œ��όv�Z
{
	return calcDot(calcNormalize(lhs), calcNormalize(rhs));//ret �� calcDot(calcNormalize(lhs), calcNormalize(rhs))
}
inline float calcDistance2(const __m128 from, const __m128 to)//����^2�v�Z
{
	return getScalar(//ret �� arg1[0]
	         calcDot(//arg1 �� {arg0[0] * arg0[0], arg0[1] * arg0[1], arg0[2] * arg0[2], 0.f}
	           _mm_sub_ps(to, from)//arg0 �� {to[0] - from[0], to[1] - from[1], to[2] - from[2], to[3] - from[3]}
	         )
	       );
}
inline float calcDistance(const __m128 from, const __m128 to)//�����v�Z
{
	return getScalar(//ret �� arg1[0]
	         calcSqrtDot(//arg1 �� {sqrt(arg0[0] * arg0[0]), sqrt(arg0[1] * arg0[1]), sqrt(arg0[2] * arg0[2]), 0.f}
	           _mm_sub_ps(to, from)//arg0 �� {to[0] - from[0], to[1] - from[1], to[2] - from[2], to[3] - from[3]}
	         )
	       );
}
inline __m128 calcAdd(const __m128 lhs, const float rhs)//�񍀂̑����Z
{
	return calcAdd(lhs, calcMul(calcNormalize(lhs), rhs));//ret �� lhs + normalize(lhs) * rhs
}
inline __m128 calcSub(const __m128 lhs, const float rhs)//�񍀂̈����Z
{
	return calcSub(lhs, calcMul(calcNormalize(lhs), rhs));//ret �� lhs - normalize(lhs) * rhs
}
#endif//USE_SIMD

#ifdef USE_SIMD
//----------
//�x�N�g���N���X�v�Z�p�\����
#ifdef USE_GCC
#define DECLARE_M128_S//__m128_s �\���̂��g�p
#endif//USE_GCC
#ifndef DECLARE_M128_S
//Visual C++ �ł́A__m128 �͌��X�\���̂Ȃ̂ŁA__m128_s��__m128�̕ʖ��Ƃ���
typedef __m128 __m128_s;
#else//DECLARE_M128_S
//GCC�ł́A�񍀉��Z�qoperator�� __m128 ���g����悤�ɁA__m128 �����b�v�����\���� __m128_s ��p��
struct __m128_s
{
	__m128 m_val;
	inline operator __m128() const { return m_val; }
	inline __m128_s(const __m128 val) :
		m_val(val)
	{}
};
#endif//DECLARE_M128_S
#endif//USE_SIMD

//----------
//�x�N�g���N���X
struct vec3
{
	//�t�B�[���h
#ifdef USE_SIMD
#ifndef USE_LOAD_STORE
	//SIMD���Z�g�p�A���Aunion�ōœK�������f�[�^�\��
	union
	{
		__m128 m_val128;
		float m_val[4];
	};
#else//USE_LOAD_STORE
	//SIMD���Z�g�p�A���A�����I�ȃ��[�h�^�X�g�A�g�p���̃f�[�^�\��
	float ATTR_SIMD128 m_val[4];
#endif//USE_LOAD_STORE
#else//USE_SIMD
	//SIMD��g�p���̃f�[�^�\��
	float m_val[3];
#endif//USE_SIMD
	//�A�N�Z�b�T
	float& x() { return m_val[0]; }
	float& y() { return m_val[1]; }
	float& z() { return m_val[2]; }
	float x() const { return m_val[0]; }
	float y() const { return m_val[1]; }
	float z() const { return m_val[2]; }
	void x(const float val){ m_val[0] = val; }
	void y(const float val){ m_val[1] = val; }
	void z(const float val){ m_val[2] = val; }
	float& operator[](const int index){ return m_val[index]; }
	const float& operator[](const int index) const { return m_val[index]; }
#ifdef USE_SIMD
	//���[�h�^�X�g�A���\�b�h
	inline __m128 load() const//���[�h
	{
	#ifndef USE_LOAD_STORE
		return m_val128;//ret �� m_val128
	#else//USE_LOAD_STORE
		return _mm_load_ps(m_val);//ret �� {m_val[0], m_val[1], m_val[2], m_val[3]}
	#endif//USE_LOAD_STORE
	}
	inline __m128 load1() const//���[�h
	{
	#ifndef USE_LOAD_STORE
		//[NG]
		//return _mm_set1_ps(m_val[0]);//ret �� {m_val[0], m_val[0], m_val[0], m_val[0]}
		//[OK]
		return _mm_set_ps(0.f, m_val[0], m_val[0], m_val[0]);//ret �� {m_val[0], m_val[0], m_val[0], 0.f}
	#else//USE_LOAD_STORE
		//[NG]
		//return _mm_load1_ps(m_val);//ret �� {m_val[0], m_val[0], m_val[0], m_val[0]}
		//[OK]
		return _mm_blend_ps(//ret �� {arg0[0], arg0[1], arg0[2], arg1[3]}
		         _mm_load1_ps(m_val),//arg0 �� {m_val[0], m_val[0], m_val[0], m_val[0]}
		         _mm_setzero_ps(),   //arg1 �� {0.f, 0.f, 0.f, 0.f}
		         0x08
		       );
	#endif//USE_LOAD_STORE
	}
	inline __m128 loadS() const//���[�h
	{
	#ifndef USE_LOAD_STORE
		return _mm_set_ss(m_val[0]);//ret �� {m_val[0], 0.f, 0.f, 0.f}
	#else//USE_LOAD_STORE
		return _mm_load_ss(m_val);//ret �� {m_val[0], 0.f, 0.f, 0.f}
	#endif//USE_LOAD_STORE
	}
	inline float loadSF() const//���[�h
	{
	#ifndef USE_LOAD_STORE
		return m_val[0];//ret �� m_val[0]
	#else//USE_LOAD_STORE
		return getScalar(//ret �� arg0[0]
		         _mm_load_ss(m_val)//arg0 �� {m_val[0], 0.f, 0.f, 0.f}
		       );
	#endif//USE_LOAD_STORE
	}
	inline void store(const __m128 val)//�X�g�A
	{
	#ifndef USE_LOAD_STORE
		m_val128 = val;//val �� m_val128
	#else//USE_LOAD_STORE
		_mm_store_ps(m_val, val);//{val[0], val[1], val[2], val[3]} �� m_val
	#endif//USE_LOAD_STORE
	}
	inline void store1(const __m128 val)//�X�g�A
	{
	#ifndef USE_LOAD_STORE
		//[NG]
		//m_val128 = _mm_set1_ps(//{arg0, arg0, arg0, arg0} �� m_val128
		//             getScalar(val)//arg0 �� val[0]
		//           );
		//[OK]
		m_val128 = _mm_blend_ps(//{arg1[0], arg1[1], arg1[2], arg2[3]} �� m_val128
		             _mm_set1_ps(     //arg1 �� {arg0, arg0, arg0, arg0}
		               getScalar(val)//arg0 �� val[0]
		             ),
		             _mm_setzero_ps(),//arg2 �� {0.f, 0.f, 0.f, 0.f}
		             0x08
		           );
	#else//USE_LOAD_STORE
		//[NG]
		//_mm_store1_ps(m_val,//{arg0, arg0, arg0, arg0} �� m_val
		//  getScalar(val)//arg0 �� val[0]
		//);
		//[OK]
		_mm_store_ps(m_val,//arg3 �� m_val
		  _mm_blend_ps(//arg3 �� {arg1[0], arg1[1], arg1[2], arg2[3]}
		    _mm_set1_ps(     //arg1 �� {arg0, arg0, arg0, arg0}
		      getScalar(val)//arg0 �� val[0]
		    ),
		    _mm_setzero_ps(),//arg2 �� {0.f, 0.f, 0.f, 0.f}
		    0x08
		  )
		);
	#endif//USE_LOAD_STORE
	}
	inline void store1(const float val)//�X�g�A
	{
	#ifndef USE_LOAD_STORE
		//[NG]
		//m_val128 = _mm_set1_ps(val);//{val, val, val, val} �� m_val128
		//[OK]
		m_val128 = _mm_set_ps(0.f, val, val, val);//{val, val, val, 0.f} �� m_val128
	#else//USE_LOAD_STORE
		//[NG]
		//_mm_store1_ps(m_val, val);//{val[0], val[0], val[0], val[0]} �� m_val
		//[OK]
		_mm_store_ps(m_val,//arg0 �� m_val128
		  _mm_set_ps(0.f, val, val, val)//arg0 �� {val, val, val, 0.f}
		);
	#endif//USE_LOAD_STORE
	}
	inline void storeS(const __m128 val)//�X�g�A
	{
	#ifndef USE_LOAD_STORE
		m_val[0] = getScalar(val);//val[0] �� m_val[0]
	#else//USE_LOAD_STORE
		_mm_store_ss(m_val, val);//val[0] �� m_val[0]
	#endif//USE_LOAD_STORE
	}
	inline void storeSF(const float val)//�X�g�A
	{
	#ifndef USE_LOAD_STORE
		m_val[0] = val;//val �� m_val[0]
	#else//USE_LOAD_STORE
		_mm_store_ss(m_val,//arg0[0] �� m_val[0]
		  _mm_set_ss(val)//arg0 �� {val, 0.f, 0.f, 0.f}
		);
	#endif//USE_LOAD_STORE
	}
	inline void storeZero()//�X�g�A
	{
	#ifndef USE_LOAD_STORE
		m_val128 = _mm_setzero_ps();//{0.f, 0.f, 0.f, 0.f} �� m_val128
	#else//USE_LOAD_STORE
		_mm_store_ss(m_val,//arg0 �� m_val
		  _mm_setzero_ps()//arg0 �� {0.f, 0.f, 0.f, 0.f}
		);
	#endif//USE_LOAD_STORE
	}
#endif//USE_SIMD
	//�I�y���[�^
	inline vec3& operator+=(const vec3& rhs)
	{
	#ifdef USE_SIMD
		store(//arg2 �� m_val
		  calcAdd(//arg2 �� {arg0[0] + arg1[0], arg0[1] + arg1[1], arg0[2] + arg1[2], arg0[3] + arg1[3]}
		    load(),   //arg0 �� m_val
		    rhs.load()//arg1 �� rhs.m_val
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 3; ++index)
			m_val[index] += rhs.m_val[index];
	#endif//USE_SIMD
		return *this;
	}
	inline vec3& operator+=(const float rhs)
	{
	#ifdef USE_SIMD
		store(//arg2 �� m_val
		  calcAdd(//arg2 �� arg0 + normalize(arg0) * arg1
		    load(),//arg0 �� m_val
		    rhs    //arg1: rhs
		  )
		);
	#else//USE_SIMD
		vec3 rhs_tmp(*this);
		rhs_tmp.normalize();
		rhs_tmp *= rhs;
		*this += rhs_tmp;
	#endif//USE_SIMD
		return *this;
	}
	inline vec3& operator-=(const vec3& rhs)
	{
	#ifdef USE_SIMD
		store(//arg2 �� m_val
		  calcSub(//arg2 �� {arg0[0] - arg1[0], arg0[1] - arg1[1], arg0[2] - arg1[2], arg0[3] - arg1[3]}
		    load(),   //arg0 �� m_val
		    rhs.load()//arg1 �� rhs.m_val
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 3; ++index)
			m_val[index] -= rhs.m_val[index];
	#endif//USE_SIMD
		return *this;
	}
	inline vec3& operator-=(const float rhs)
	{
	#ifdef USE_SIMD
		store(//arg2 �� m_val
		  calcSub(//arg2 �� arg0 - normalize(arg0) * arg1
		    load(),//arg0 �� m_val
		    rhs    //arg1 �� rhs
		  )
		);
	#else//USE_SIMD
		vec3 rhs_tmp(*this);
		rhs_tmp.normalize();
		rhs_tmp *= rhs;
		*this -= rhs_tmp;
	#endif//USE_SIMD
		return *this;
	}
	inline vec3& operator*=(const float rhs)
	{
	#ifdef USE_SIMD
		store(//arg2 �� m_val
		  calcMul(//arg2 �� {arg0[0] * arg1, arg0[1] * arg1, arg0[2] * arg1, arg0[3] * arg1}
		    load(),//arg0 �� m_val
		    rhs    //arg1 �� rhs
		  )
		 );
	#else//USE_SIMD
		for (int index = 0; index < 3; ++index)
			m_val[index] *= rhs;
	#endif//USE_SIMD
		return *this;
	}
	inline vec3& operator/=(const float rhs)
	{
	#ifdef USE_SIMD
		store(//arg2 �� m_val
		  calcDiv(//arg2 �� {arg0[0] / arg1, arg0[1] / arg1, arg0[2] / arg1, arg0[3] / arg1}
		    load(),//arg0 �� m_val
		    rhs    //arg1 �� rhs
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 3; ++index)
			m_val[index] /= rhs;
	#endif//USE_SIMD
		return *this;
	}
	//�L���X�g�I�y���[�^
	inline operator float() const
	{
		return norm();
	}
#ifdef USE_SIMD
	inline operator __m128() const
	{
		return load();//ret �� m_val
	}
#ifdef DECLARE_M128_S
	inline operator __m128_s() const
	{
		return load();//ret �� m_val
	}
#endif//DECLARE_M128_S
#endif//USE_SIMD
	//�R�s�[�I�y���[�^
	inline vec3& operator=(const vec3& rhs)
	{
	#ifdef USE_SIMD
		store(rhs.load());
	#else//USE_SIMD
		for (int index = 0; index < 3; ++index)
			m_val[index] = rhs.m_val[index];
	#endif//USE_SIMD
		return *this;
	}
#ifdef USE_SIMD
	inline vec3& operator=(const __m128 rhs)
	{
		store(rhs);//rhs �� m_val
		return *this;
	}
#ifdef DECLARE_M128_S
	inline vec3& operator=(const __m128_s& rhs)
	{
		store(rhs);//rhs �� m_val
		return *this;
	}
#endif//DECLARE_M128_S
#endif//USE_SIMD
	//���\�b�h
	//����
	inline float dot(const vec3& target) const
	{
	#ifdef USE_SIMD
		return calcDot(//ret �� calcDot(arg0, arg1)
		         load(),      //arg0 �� m_val
		         target.load()//arg1 �� target.m_val
		       );
	#else//USE_SIMD
		return m_val[0] * target.m_val[0] +
		       m_val[1] * target.m_val[1] +
		       m_val[2] * target.m_val[2];
	#endif//USE_SIMD
	}
	//���K������
	inline float normalizeDot(const vec3& target) const
	{
	#ifdef USE_SIMD
		return calcNormalizeDot(//ret �� calcNormalizeDot(arg0, arg1)
		         load(),      //arg0 �� m_val
		         target.load()//arg1 �� target.m_val
		       );
	#else//USE_SIMD
		vec3 tmp1(*this);
		vec3 tmp2(target);
		tmp1.normalize();
		tmp2.normalize();
		return tmp1.m_val[0] * tmp2.m_val[0] +
		       tmp1.m_val[1] * tmp2.m_val[1] +
		       tmp1.m_val[2] * tmp2.m_val[2];
	#endif//USE_SIMD
	}
	//�O��
#ifdef USE_SIMD
	inline __m128_s cross(const vec3& target) const
	{
		return calcCross(//ret �� calcCross(arg0, arg1)
		         load(),      //arg0 �� m_val
		         target.load()//arg1 �� target.m_val
		       );
	}
#else//USE_SIMD
	inline vec3 cross(const vec3& target) const
	{
		return vec3(
		         m_val[1] * target.m_val[2] - m_val[2] * target.m_val[1],
		         m_val[2] * target.m_val[0] - m_val[0] * target.m_val[2],
		         m_val[0] * target.m_val[1] - m_val[1] * target.m_val[0]
		       );
	}
#endif//USE_SIMD
	//�m����^2�擾
	inline float norm2() const
	{
	#ifdef USE_SIMD
		return calcNorm2(//ret �� calcNorm2(arg0)
		         load()//arg0 �� m_val
		       );
	#else//USE_SIMD
		return m_val[0] * m_val[0] +
		       m_val[1] * m_val[1] +
		       m_val[2] * m_val[2];
	#endif//USE_SIMD
	}
	//�m�����擾
	inline float norm() const
	{
	#ifdef USE_SIMD
		return calcNorm(//ret �� calcNorm(arg0)
		         load()//arg0 �� m_val128
		       );
	#else//USE_SIMD
		return sqrt(norm2());
	#endif//USE_SIMD
	}
	//����^2�擾
	inline float length2() const
	{
		return norm2();
	}
	//�����擾
	inline float length() const
	{
		return norm();
	}
	//���K��
	inline vec3& normalize()
	{
	#ifdef USE_SIMD
		store(//arg1 �� m_val
		  calcNormalize(//arg1 �� calcNormalize(arg0)
		    load()//arg0 �� m_val
		  )
		);
	#else//USE_SIMD
		const float val_norm = norm();
		for (int index = 0; index < 3; ++index)
			m_val[index] /= val_norm;
	#endif//USE_SIMD
		return *this;
	}
#ifdef USE_SIMD
	inline __m128_s normalize() const
	{
		return calcNormalize(//ret �� calcNormalize(arg0)
		         load()//arg0 �� m_val
		       );
	}
#else//USE_SIMD
	inline vec3 normalize() const
	{
		const float val_norm = norm();
		return vec3(m_val[0] / val_norm, m_val[1] / val_norm, m_val[2] / val_norm);
	}
#endif//USE_SIMD
	//����^2�v�Z
	inline float distance2(const vec3& from)
	{
	#ifdef USE_SIMD
		return calcDistance2(//ret �� calcDist2(arg0, arg1)
		         from.load(),//arg0 �� from.m_val
		         load()      //arg1 �� m_val
		       );
	#else//USE_SIMD
		vec3 tmp(*this);
		tmp -= from;
		return tmp.norm2();
	#endif//USE_SIMD
	}
	//�����v�Z
	inline float distance(const vec3& from)
	{
	#ifdef USE_SIMD
		return calcDistance(//ret �� calcDist(arg0, arg1)
		         from.load(),//arg0 �� from.m_val
		         load()      //arg1 �� m_val
		       );
	#else//USE_SIMD
		vec3 tmp(*this);
		tmp -= from;
		return tmp.norm();
	#endif//USE_SIMD
	}
	//�R�s�[�R���X�g���N�^
	inline vec3(const vec3& obj)
#ifdef USE_SIMD
#ifndef USE_LOAD_STORE
		: m_val128(obj.m_val128)//obj.m_val128 �� m_val128
	{}
#else//USE_LOAD_STORE
	{
		store(obj.load());//obj.m_val �� m_val
	}
#endif//USE_LOAD_STORE
#else//USE_SIMD
	{
		for (int index = 0; index < 3; ++index)
			m_val[index] = obj.m_val[index];
	}
#endif//USE_SIMD
	//�R���X�g���N�^
	inline vec3(const float x, const float y, const float z)
#ifdef USE_SIMD
#ifndef USE_LOAD_STORE
		:m_val128(_mm_set_ps(0.f, z, y, x))//{x, y, z, 0.f} �� m_val128
	{}
#else//USE_LOAD_STORE
	{
		store(_mm_set_ps(0.f, z, y, x));//{x, y, z, 0.f} �� m_val
	}
#endif//USE_LOAD_STORE
#else//USE_SIMD
	{
		m_val[0] = x;
		m_val[1] = y;
		m_val[2] = z;
	}
#endif//USE_SIMD
	inline vec3(const float val)
#ifdef USE_SIMD
#ifndef USE_LOAD_STORE
		//[NG]
		//:m_val128(_mm_set1_ps(val))//{val, val, val, val} �� m_val128
		//[OK]
		:m_val128(_mm_set_ps(0.f, val, val, val))//{val, val, val, 0.f} �� m_val128
	{}
#else//USE_LOAD_STORE
	{
		//[NG]
		//store(_mm_set1_ps(val));//{val, val, val, val} �� m_val
		//[OK]
		store1(val);//{val, val, val, 0.f} �� m_val
	}
#endif//USE_LOAD_STORE
#else//USE_SIMD
	{
		for (int index = 0; index < 3; ++index)
			m_val[index] = val;
	}
#endif//USE_SIMD
#ifdef USE_SIMD
	inline vec3(const __m128 val)
#ifndef USE_LOAD_STORE
		:m_val128(val)//val �� m_val128
	{}
#else//USE_LOAD_STORE
	{
		store(val);//val �� m_val
	}
#endif//USE_LOAD_STORE
#ifdef DECLARE_M128_S
	inline vec3(const __m128_s& val)
#ifndef USE_LOAD_STORE
		:m_val128(val)//val �� m_val128
	{}
#else//USE_LOAD_STORE
	{
		store(val);//val �� m_val
	}
#endif//USE_LOAD_STORE
#endif//DECLARE_M128_S
#endif//USE_SIMD
	inline vec3()
#ifdef USE_SIMD
#ifndef USE_LOAD_STORE
		:m_val128(_mm_setzero_ps())//{0.f, 0.f, 0.f, 0.f} �� m_val128
	{}
#else//USE_LOAD_STORE
	{
		storeZero();//{0.f, 0.f, 0.f, 0.f} �� m_val128
	}
#endif//USE_LOAD_STORE
#else//USE_SIMD
	{
		for (int index = 0; index < 3; ++index)
			m_val[0] = 0.f;
	}
#endif//USE_SIMD
	//�f�X�g���N�^
	inline ~vec3()
	{}
};

//�񍀉��Z�q�p�I�y���[�^
#ifdef USE_SIMD
//��SIMD���Z���� vec3 �^�̂܂܂ł͂Ȃ��A__m128�^�Ƃ��ĉ��Z���A__m128_s�^��Ԃ�
inline __m128_s operator+(const vec3& lhs, const vec3& rhs){ return calcAdd(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128_s operator+(const vec3& lhs, const __m128_s& rhs){ return calcAdd(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128_s operator+(const __m128_s& lhs, const vec3& rhs){ return calcAdd(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128_s operator+(const __m128_s& lhs, const __m128_s& rhs){ return calcAdd(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128_s operator+(const vec3& lhs, const float rhs){ return calcAdd(static_cast<__m128>(lhs), rhs); }
inline __m128_s operator+(const __m128_s& lhs, const float rhs){ return calcAdd(static_cast<__m128>(lhs), rhs); }

inline __m128_s operator-(const vec3& lhs, const vec3& rhs){ return calcSub(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128_s operator-(const vec3& lhs, const __m128_s& rhs){ return calcSub(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128_s operator-(const __m128_s& lhs, const vec3& rhs){ return calcSub(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128_s operator-(const __m128_s& lhs, const __m128_s& rhs){ return calcSub(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128_s operator-(const vec3& lhs, const float rhs){ return calcSub(static_cast<__m128>(lhs), rhs); }
inline __m128_s operator-(const __m128_s& lhs, const float rhs){ return calcSub(static_cast<__m128>(lhs), rhs); }

inline __m128_s operator*(const vec3& lhs, const float rhs){ return calcMul(static_cast<__m128>(lhs), rhs); }
inline __m128_s operator*(const __m128_s& lhs, const float rhs){ return calcMul(static_cast<__m128>(lhs), rhs); }

inline __m128_s operator/(const vec3& lhs, const float rhs){ return calcDiv(static_cast<__m128>(lhs), rhs); }
inline __m128_s operator/(const __m128_s& lhs, const float rhs){ return calcDiv(static_cast<__m128>(lhs), rhs); }

inline float dot(const vec3& lhs, const vec3& rhs){ return calcDot(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline float dot(const vec3& lhs, const __m128_s& rhs){ return calcDot(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline float dot(const __m128_s& lhs, const vec3& rhs){ return calcDot(lhs, static_cast<__m128>(rhs)); }
inline float dot(const __m128_s& lhs, const __m128_s& rhs){ return calcDot(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }

inline float normalizeDot(const vec3& lhs, const vec3& rhs){ return calcNormalizeDot(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline float normalizeDot(const vec3& lhs, const __m128_s& rhs){ return calcNormalizeDot(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline float normalizeDot(const __m128_s& lhs, const vec3& rhs){ return calcNormalizeDot(lhs, static_cast<__m128>(rhs)); }
inline float normalizeDot(const __m128_s& lhs, const __m128_s& rhs){ return calcNormalizeDot(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }

inline __m128_s cross(const vec3& lhs, const vec3& rhs){ return calcCross(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128_s cross(const vec3& lhs, const __m128_s& rhs){ return calcCross(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128_s cross(const __m128_s& lhs, const vec3& rhs){ return calcCross(lhs, static_cast<__m128>(rhs)); }
inline __m128_s cross(const __m128_s& lhs, const __m128_s& rhs){ return calcCross(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }

inline float norm2(const vec3& val){ return calcNorm2(static_cast<__m128>(val)); }
inline float norm2(const __m128_s& val){ return calcNorm2(static_cast<__m128>(val)); }
inline float norm(const vec3& val){ return calcNorm(static_cast<__m128>(val)); }
inline float norm(const __m128_s& val){ return calcNorm(static_cast<__m128>(val)); }

inline float length2(const vec3& val){ return calcNorm2(static_cast<__m128>(val)); }
inline float length2(const __m128_s& val){ return calcNorm2(static_cast<__m128>(val)); }
inline float length(const vec3& val){ return calcNorm(static_cast<__m128>(val)); }
inline float length(const __m128_s& val){ return calcNorm(static_cast<__m128>(val)); }

inline __m128_s normalize(const vec3& val){ return calcNormalize(static_cast<__m128>(val)); }
inline __m128_s normalize(const __m128_s& val){ return calcNormalize(static_cast<__m128>(val)); }

inline float distance2(const vec3& from, const vec3& to){ return calcDistance2(static_cast<__m128>(from), static_cast<__m128>(to)); }
inline float distance2(const vec3& from, const __m128_s& to){ return calcDistance2(static_cast<__m128>(from), static_cast<__m128>(to)); }
inline float distance2(const __m128_s& from, const vec3& to){ return calcDistance2(static_cast<__m128>(from), static_cast<__m128>(to)); }
inline float distance2(const __m128_s& from, const __m128_s& to){ return calcDistance2(static_cast<__m128>(from), static_cast<__m128>(to)); }
inline float distance(const vec3& from, const vec3& to){ return calcDistance(static_cast<__m128>(from), static_cast<__m128>(to)); }
inline float distance(const vec3& from, const __m128_s& to){ return calcDistance(static_cast<__m128>(from), static_cast<__m128>(to)); }
inline float distance(const __m128_s& from, const vec3& to){ return calcDistance(static_cast<__m128>(from), static_cast<__m128>(to)); }
inline float distance(const __m128_s& from, const __m128_s& to){ return calcDistance(static_cast<__m128>(from), static_cast<__m128>(to)); }

#else//USE_SIMD
//����SIMD���Z���� vec3 �^�̂܂܉��Z����
inline vec3 operator+(const vec3& lhs, const vec3& rhs){ vec3 tmp(lhs); return (tmp += rhs); }
inline vec3 operator+(const vec3& lhs, const float rhs){ vec3 tmp(lhs); return (tmp += rhs); }

inline vec3 operator-(const vec3& lhs, const vec3& rhs){ vec3 tmp(lhs); return (tmp -= rhs); }
inline vec3 operator-(const vec3& lhs, const float rhs){ vec3 tmp(lhs); return (tmp -= rhs); }

inline vec3 operator*(const vec3& lhs, const float rhs){ vec3 tmp(lhs); return (tmp *= rhs); }

inline vec3 operator/(const vec3& lhs, const float rhs){ vec3 tmp(lhs); return (tmp /= rhs); }

inline float dot(const vec3& lhs, const vec3& rhs){ return lhs.dot(rhs); }
inline float normalizeDot(const vec3& lhs, const vec3& rhs){ return lhs.normalizeDot(rhs); }

inline vec3 cross(const vec3& lhs, const vec3& rhs){ return lhs.cross(rhs); }

inline float norm2(const vec3& val){ return val.norm2(); }
inline float norm(const vec3& val){ return val.norm(); }

inline float length2(const vec3& val){ return val.length2(); }
inline float length(const vec3& val){ return val.length(); }

inline vec3 normalize(const vec3& val){ vec3 tmp(val); return tmp.normalize(); }

inline float distance2(const vec3& from, const vec3& to){ vec3 tmp(to); return tmp.distance2(from); }
inline float distance(const vec3& from, const vec3& to){ vec3 tmp(to); return tmp.distance(from); }
#endif//USE_SIMD

#endif//__VECTOR_H_

// End of file

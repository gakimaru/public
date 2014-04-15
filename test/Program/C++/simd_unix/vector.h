#ifndef __VECTOR_H_
#define __VECTOR_H_

#define USE_GCC//GCCを使用
#define USE_SIMD//明示的なSIMD演算を使用する
//#define USE_MM_EXTRACT_PS//_mm_extract_ps関数(SSE3)を使用 ※使った方がソースコードの互換性が高いが、使わない方が早い

//アラインメント属性
#ifdef USE_GCC
#define ATTR_ALIGN(n) __attribute__((aligned(n)))//for GCC
#else//USE_GCC
#define ATTR_ALIGN(n) __declspec(align(n))//for VC
#endif//USE_GCC
#define ATTR_ALIGN16 ATTR_ALIGN(16)

//SIMD用属性
#ifdef USE_SIMD
#define ATTR_SIMD128 ATTR_ALIGN16
#else//USE_SIMD
#define ATTR_SIMD128
#endif//USE_SIMD

#ifdef USE_SIMD
//#include <mmintrin.h>//MMX
//#include <xmmintrin.h>//SSE
//#include <emmintrin.h>//SSE2
//#include <pmmintrin.h>//SSE3
//#include <tmmintrin.h>//SSSE3
//#include <ammintrin.h>//SSE4A(AMD)
#include <smmintrin.h>//SSE4.1
//#include <nmmintrin.h>//SSE4.2
//#include <wmmintrin.h>//AES暗号化およびPCLMULQDQ
//#include <immintrin.h>//AVX1,AVX2
#else//USE_SIMD
#include <math.h>//sqrt
#endif//USE_SIMD

#ifdef USE_SIMD
//----------
//ベクトルクラス計算用関数
//operatorが使えるように、__m128用の構造体を用意
struct __m128_s
{
	__m128 m_val;
	inline operator __m128() const { return m_val; }
	inline __m128_s& operator=(const __m128 val)
	{
		m_val = val;
		return *this;
	}
	inline __m128_s(const __m128 val) :
		m_val(val)
	{}
};
//二項演算子用関数と共通関数
//※SIMD演算専用
inline float getScalar(const __m128 val)
{
#ifdef USE_MM_EXTRACT_PS
	union conv
	{
		const int i;
		const float f;
		inline float operator()() const { return f; }
		inline conv(const __m128 val) :
			i(_mm_extract_ps(val, 0))
		{}
	};
	return conv(val)();
#else//USE_MM_EXTRACT_PS
	return *reinterpret_cast<const float*>(&val);
#endif//USE_MM_EXTRACT_PS
}
inline __m128 calcAdd(const __m128 lhs, const __m128 rhs)//二項の足し算
{
	return _mm_add_ps(lhs, rhs);//ret ← {lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2], lhs[3] + rhs[3]}
}
inline __m128 calcSub(const __m128 lhs, const __m128 rhs)//二項の引き算
{
	return _mm_sub_ps(lhs, rhs);//ret ← {lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2], lhs[3] - rhs[3]}
}
inline __m128 calcMul(const __m128 lhs, const float rhs)//二項の掛け算
{
	return _mm_mul_ps(lhs, _mm_set1_ps(rhs));//ret ← {lhs[0] * rhs, lhs[1] * rhs, lhs[2] * rhs, lhs[3] * rhs}
}
inline __m128 calcDiv(const __m128 lhs, const float rhs)//二項の割り算
{
	return _mm_div_ps(lhs, _mm_set1_ps(rhs));//ret ← {lhs[0] / rhs, lhs[1] / rhs, lhs[2] / rhs, lhs[3] / rhs}
}
inline float calcNorm2(const __m128 val)//ノルム^2計算
{
	return getScalar(//ret ← arg4[0]
	         _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	           _mm_hadd_ps(    //arg2 ← {arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	             _mm_mul_ps(val, val),//arg0 ← {val[0] * val[0], val[1] * val[1], val[2] * val[2], val[3] * val[3]}
	             _mm_setzero_ps()     //arg1 ← {0.f, 0.f, 0.f, 0.f}
	           ),
	           _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	         )
	       );
}
inline float calcNorm(const __m128 val)//ノルム計算
{
	return getScalar(//ret ← arg5[0]
	         _mm_sqrt_ss(//arg5 ← {sqrt(arg4[0]), arg4[1], arg4[2], arg4[3]}
	           _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	             _mm_hadd_ps(   //arg2 ← {arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	               _mm_mul_ps(val, val),//arg0 ← {val[0] * val[0], val[1] * val[1], val[2] * val[2], val[3] * val[3]}
	               _mm_setzero_ps()     //arg1 ← {0.f, 0.f, 0.f, 0.f}
	             ),
	            _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	           )
	         )
	       );
}
inline __m128 calcNormalize(const __m128 val)//正規化
{
	return _mm_div_ps(//ret ← {arg7[0] / arg8[0], arg7[1] / arg8[1], arg7[2] / arg8[2], arg7[3] / arg8[3]}
	         val,        //arg7: val
	         _mm_set1_ps(//arg8 ← {arg6, arg6, arg6, arg6}
	           getScalar(//arg6 ← arg5[0]
	            _mm_sqrt_ss(//arg5 ← {sqrt(arg4[0]), arg4[1], arg4[2], arg4[3]}
	             _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	               _mm_hadd_ps(      //arg2 ← {arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	                   _mm_mul_ps(val, val),//arg0 ← {val[0] * val[0], val[1] * val[1], val[2] * val[2], val[3] * val[3]}
	                   _mm_setzero_ps()     //arg1 ← {0.f, 0.f, 0.f, 0.f}
	                 ),
	                 _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	               )
	             )
	           )
	         )
	       );
}
inline __m128 calcAdd(const __m128 lhs, const float rhs)//二項の足し算
{
	return calcAdd(lhs, calcMul(calcNormalize(lhs), rhs));//ret ← lhs + normalize(lhs) * rhs
}
inline __m128 calcSub(const __m128 lhs, const float rhs)//二項の引き算
{
	return calcSub(lhs, calcMul(calcNormalize(lhs), rhs));//ret ← lhs - normalize(lhs) * rhs
}
inline float calcDot(const __m128 lhs, const __m128 rhs)//内積計算
{
	return getScalar(//ret ← arg4[0]
	         _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	           _mm_hadd_ps(    //arg2 ← {arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	             _mm_mul_ps(lhs, rhs),//arg0 ← {lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2], lhs[3] * rhs[3]}
	             _mm_setzero_ps()     //arg1 ← {0.f, 0.f, 0.f, 0.f}
	           ),
	           _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	         )
	       );
}
inline float calcNormalizeDot(const __m128 lhs, const __m128 rhs)//正規化ベクトルで内積計算
{
	return calcDot(calcNormalize(lhs), calcNormalize(rhs));
}
inline __m128 calcCross(const __m128 lhs, const __m128 rhs)//外積計算
{
	return _mm_sub_ps(//ret ← {arg2[0] - arg5[0], arg2[1] - arg5[1], arg2[2] - arg5[2], arg2[3] - arg5[3]}
	         _mm_mul_ps(//arg2 ← {arg0[0] * arg1[0], arg0[1] * arg1[1], arg0[2] * arg1[2], arg0[3] * arg1[3]}
	           _mm_shuffle_ps(lhs, lhs, _MM_SHUFFLE(3, 0, 2, 1)),//arg0 ← {lhs[1], lhs[2], lhs[0], lhs[3]}
	           _mm_shuffle_ps(rhs, rhs, _MM_SHUFFLE(3, 1, 0, 2)) //arg1 ← {rhs[1], rhs[2], rhs[0], rhs[3]}
	         ),
	         _mm_mul_ps(//arg5 ← {arg3[0] * arg4[0], arg3[1] * arg4[1], arg3[2] * arg4[2], arg3[3] * arg4[3]}
	           _mm_shuffle_ps(lhs, lhs, _MM_SHUFFLE(3, 1, 0, 2)),//arg3 ← {lhs[1], lhs[2], lhs[0], lhs[3]}
	           _mm_shuffle_ps(rhs, rhs, _MM_SHUFFLE(3, 0, 2, 1)) //arg4 ← {rhs[1], rhs[2], rhs[0], rhs[3]}
	         )
	       );
	return lhs;
}
inline float calcDistance2(const __m128 from, const __m128 to)//距離^2計算
{
	const __m128 val_diff = _mm_sub_ps(to, from);//ret ← {to[0] - from[0], to[1] - from[1], to[2] - from[2], to[3] - from[3]}
	return getScalar(//ret ← arg4[0]
	         _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	           _mm_hadd_ps(    //arg2 ← :{arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	             _mm_mul_ps(val_diff, val_diff),//arg0 ← {val_diff[0] * val_diff[0], val_diff[1] * val_diff[1], val_diff[2] * val_diff[2], val_diff[3] * val_diff[3]}
	             _mm_setzero_ps()               //arg1 ← {0.f, 0.f, 0.f, 0.f}
	           ),
	           _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	         )
	       );
}
inline float calcDistance(const __m128 from, const __m128 to)//距離計算
{
	const __m128 val_diff = _mm_sub_ps(to, from);//ret ← {to[0] - from[0], to[1] - from[1], to[2] - from[2], to[3] - from[3]}
	return getScalar(//ret ← arg5[0]
	         _mm_sqrt_ss(//arg5 ← {sqrt(arg4[0]), arg4[1], arg4[2], arg4[3]}
	           _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	             _mm_hadd_ps(    //arg2 ← {arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	               _mm_mul_ps(val_diff, val_diff),//arg0 ← {val_diff[0] * val_diff[0], val_diff[1] * val_diff[1], val_diff[2] * val_diff[2], val_diff[3] * val_diff[3]}
	               _mm_setzero_ps()//arg1 ← {0.f, 0.f, 0.f, 0.f}
	             ),
	             _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	           )
	         )
	       );
}
#endif//USE_SIMD

//----------
//ベクトルクラス
struct vec3
{
	//フィールド
#ifdef USE_SIMD
	float ATTR_SIMD128 m_val[4];
#else//USE_SIMD
	float m_val[3];
#endif//USE_SIMD
	//アクセッサ
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
	//オペレータ
	inline vec3& operator+=(const vec3& rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg2 → m_val
		  calcAdd(//arg2 ← {arg0[0] + arg1[0], arg0[1] + arg1[1], arg0[2] + arg1[2], arg0[3] + arg1[3]}
		    _mm_load_ps(m_val),   //arg0 ← m_val
		    _mm_load_ps(rhs.m_val)//arg1 ← rhs.m_val
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
		_mm_store_ps(m_val,//arg2 → m_val
		  calcAdd(//arg2 ← arg0 + normalize(arg0) * arg1
		    _mm_load_ps(m_val),//arg0 ← m_val
		    rhs                //arg1: rhs
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
		_mm_store_ps(m_val,//arg2 → m_val
		  calcSub(//arg2 ← {arg0[0] - arg1[0], arg0[1] - arg1[1], arg0[2] - arg1[2], arg0[3] - arg1[3]}
		    _mm_load_ps(m_val),   //arg0 ← m_val
		    _mm_load_ps(rhs.m_val)//arg1 ← rhs.m_val
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
		_mm_store_ps(m_val,//arg2 → m_val
		  calcSub(//arg2 ← arg0 - normalize(arg0) * arg1
		    _mm_load_ps(m_val),//arg0 ← m_val
		    rhs                //arg1: rhs
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
		_mm_store_ps(m_val,//arg2 → m_val
		  calcMul(//arg2 ← {arg0[0] * arg1, arg0[1] * arg1, arg0[2] * arg1, arg0[3] * arg1}
		    _mm_load_ps(m_val),//arg0 ← m_val
		    rhs                //arg1:rhs
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
		_mm_store_ps(m_val,//arg2 → m_val
		  calcDiv(//arg2 ← {arg0[0] / arg1, arg0[1] / arg1, arg0[2] / arg1, arg0[3] / arg1}
		    _mm_load_ps(m_val),//arg0 ← m_val
		    rhs                //arg1:rhs
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 3; ++index)
			m_val[index] /= rhs;
	#endif//USE_SIMD
		return *this;
	}
	//キャストオペレータ
	inline operator float() const
	{
		return norm();
	}
#ifdef USE_SIMD
	inline operator __m128() const
	{
		return _mm_load_ps(m_val);//ret ← m_val
	}
	inline operator __m128_s() const
	{
		return _mm_load_ps(m_val);//ret ← m_val
	}
#endif//USE_SIMD
	//コピーオペレータ
	inline vec3& operator=(const vec3& rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
		  _mm_load_ps(rhs.m_val)//arg0 ← rhs.m_val
		);
	#else//USE_SIMD
		for (int index = 0; index < 3; ++index)
			m_val[index] = rhs.m_val[index];
	#endif//USE_SIMD
		return *this;
	}
#ifdef USE_SIMD
	inline vec3& operator=(const __m128 rhs)
	{
		_mm_store_ps(m_val,//arg0 → m_val
		  rhs//arg0: rhs
		);
		return *this;
	}
	inline vec3& operator=(const __m128_s& rhs)
	{
		_mm_store_ps(m_val,//arg0 → m_val
		  rhs.m_val//arg0: rhs
		);
		return *this;
	}
#endif//USE_SIMD
	//メソッド
	//内積
	inline float dot(const vec3& target) const
	{
	#ifdef USE_SIMD
		return calcDot(//ret ← calcDot(arg0, arg1)
		         _mm_load_ps(m_val),      //arg0 ← m_val
		         _mm_load_ps(target.m_val)//arg1 ← target.m_val
		       );
	#else//USE_SIMD
		return m_val[0] * target.m_val[0] +
		       m_val[1] * target.m_val[1] +
		       m_val[2] * target.m_val[2];
	#endif//USE_SIMD
	}
	//正規化内積
	inline float normalizeDot(const vec3& target) const
	{
	#ifdef USE_SIMD
		return calcNormalizeDot(//ret ← calcNormalizeDot(arg0, arg1)
		         _mm_load_ps(m_val),      //arg0 ← m_val
		         _mm_load_ps(target.m_val)//arg1 ← target.m_val
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
	//外積
#ifdef USE_SIMD
	inline __m128_s cross(const vec3& target) const
	{
		return calcCross(//ret ← calcCross(arg0, arg1)
		         _mm_load_ps(m_val),      //arg0 ← m_val
		         _mm_load_ps(target.m_val)//arg1 ← target.m_val
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
	//ノルム^2取得
	inline float norm2() const
	{
	#ifdef USE_SIMD
		return calcNorm2(//ret ← calcNorm2(arg0)
		         _mm_load_ps(m_val)//arg0 ← m_val
		       );
	#else//USE_SIMD
		return m_val[0] * m_val[0] +
		       m_val[1] * m_val[1] +
		       m_val[2] * m_val[2];
	#endif//USE_SIMD
	}
	//ノルム取得
	inline float norm() const
	{
	#ifdef USE_SIMD
		return calcNorm(//ret ← calcNorm(arg0)
		         _mm_load_ps(m_val)//arg0 ← m_val
		       );
	#else//USE_SIMD
		return sqrt(
		         m_val[0] * m_val[0] +
		         m_val[1] * m_val[1] +
		         m_val[2] * m_val[2]
		       );
	#endif//USE_SIMD
	}
	//長さ^2取得
	inline float length2() const
	{
		return norm2();
	}
	//長さ取得
	inline float length() const
	{
		return norm();
	}
	//正規化
	inline vec3& normalize()
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg1 → m_val
		  calcNormalize(//arg1 ← calcNormalize(arg0)
		    _mm_load_ps(m_val)//arg0 ← m_val
		  )
		);
	#else//USE_SIMD
		const float norm = sqrt(
		                     m_val[0] * m_val[0] +
		                     m_val[1] * m_val[1] +
		                     m_val[2] * m_val[2]
		                   );
		for (int index = 0; index < 3; ++index)
			m_val[index] /= norm;
	#endif//USE_SIMD
		return *this;
	}
#ifdef USE_SIMD
	inline __m128_s normalize() const
	{
		return calcNormalize(//ret ← calcNormalize(arg0)
		         _mm_load_ps(m_val)//arg0 ← m_val
		       );
	}
#else//USE_SIMD
	inline vec3 normalize() const
	{
		const float norm = sqrt(
			m_val[0] * m_val[0] +
			m_val[1] * m_val[1] +
			m_val[2] * m_val[2]
			);
		return vec3(m_val[0] / norm, m_val[1] / norm, m_val[2] / norm);
	}
#endif//USE_SIMD
	//距離^2計算
	inline float distance2(const vec3& from)
	{
	#ifdef USE_SIMD
		return calcDistance2(//ret ← calcDist2(arg0)
		         _mm_load_ps(from.m_val),//arg0 ← from.m_val
		         _mm_load_ps(m_val)      //arg1 ← m_val
		       );
	#else//USE_SIMD
		vec3 tmp(*this);
		tmp -= from;
		return tmp.norm2();
	#endif//USE_SIMD
	}
	//距離計算
	inline float distance(const vec3& from)
	{
	#ifdef USE_SIMD
		return calcDistance(//ret ← calcDist(arg0)
		         _mm_load_ps(from.m_val),//arg0 ← from.m_val
		         _mm_load_ps(m_val)      //arg1 ← m_val
		       );
	#else//USE_SIMD
		vec3 tmp(*this);
		tmp -= from;
		return tmp.norm();
	#endif//USE_SIMD
	}
	//コピーコンストラクタ
	inline vec3(const vec3& obj)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
			_mm_load_ps(obj.m_val)//arg0 ← obj.m_val
			);
	#else//USE_SIMD
		for (int index = 0; index < 3; ++index)
			m_val[index] = obj.m_val[index];
	#endif//USE_SIMD
	}
	//コンストラクタ
	inline vec3(const float x, const float y, const float z)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
		  _mm_set_ps(0.f, z, y, x)//arg0 ← {z, y, z, 0.f}
		);
	#else//USE_SIMD
		m_val[0] = x;
		m_val[1] = y;
		m_val[2] = z;
	#endif//USE_SIMD
	}
	inline vec3(const float val)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
		  _mm_set1_ps(val)//arg0 ← {val, val, val, val}
		);
	#else//USE_SIMD
		for (int index = 0; index < 3; ++index)
			m_val[index] = val;
	#endif//USE_SIMD
	}
#ifdef USE_SIMD
	inline vec3(const __m128 val)
	{
		_mm_store_ps(m_val,//arg0 → m_val
		  val//arg0: val
		);
	}
	inline vec3(const __m128_s& val)
	{
		_mm_store_ps(m_val,//arg0 → m_val
		  val.m_val//arg0: val
		);
	}
#endif//USE_SIMD
	inline vec3()
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
		  _mm_setzero_ps()//arg0 ← {0.f, 0.f, 0.f, 0.f}
		);
	#else//USE_SIMD
		for (int index = 0; index < 3; ++index)
			m_val[0] = 0.f;
	#endif//USE_SIMD
	}
	//デストラクタ
	inline ~vec3()
	{}
};

//二項演算子用オペレータ
#ifdef USE_SIMD
//※SIMD演算時は vec3 型のままではなく、__m128型として演算し、__m128_s型を返す
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
//※非SIMD演算時は vec3 型のまま演算する
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

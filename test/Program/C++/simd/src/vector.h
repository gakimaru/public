#ifndef __VECTOR_H_
#define __VECTOR_H_

//#define USE_GCC//GCCを使用
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
//#include <immintrin.h>//AVX
#else//USE_SIMD
#include <math.h>//sqrt
#endif//USE_SIMD

#ifdef USE_SIMD
//二項演算子用関数と共通関数
//※SIMD演算専用
inline float get_scalar(const __m128 val)
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
inline __m128 calc_add(const __m128 lhs, const __m128 rhs){ return _mm_add_ps(lhs, rhs); }//ret:{lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2], lhs[3] + rhs[3]}
inline __m128 calc_sub(const __m128 lhs, const __m128 rhs){ return _mm_sub_ps(lhs, rhs); }//ret:{lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2], lhs[3] - rhs[3]}
inline __m128 calc_mul(const __m128 lhs, const __m128 rhs){ return _mm_mul_ps(lhs, rhs); }//ret:{lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2], lhs[3] * rhs[3]}
inline __m128 calc_div(const __m128 lhs, const __m128 rhs){ return _mm_div_ps(lhs, rhs); }//ret:{lhs[0] / rhs[0], lhs[1] / rhs[1], lhs[2] / rhs[2], lhs[3] / rhs[3]}
inline float calc_norm2(const __m128 val)//ノルム^2計算
{
	const __m128 val_pow = _mm_mul_ps(val, val);//ret ← {val[0] * val[0], val[1] * val[1], val[2] * val[2], val[3] * val[3]}
	return get_scalar(//ret ← arg4[0]
	         _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	           _mm_hadd_ps(    //arg2 ← {arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	             val_pow,        //arg0: val_pow
	             _mm_setzero_ps()//arg1 ← {0.f, 0.f, 0.f, 0.f}
	           ),
	           _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	         )
	       );
}
inline float calc_norm(const __m128 val)//ノルム計算
{
	const __m128 val_pow = _mm_mul_ps(val, val);//ret ← {val[0] * val[0], val[1] * val[1], val[2] * val[2], val[3] * val[3]}
	return get_scalar(//ret ← arg5[0]
	         _mm_sqrt_ss(//arg5 ← {sqrt(arg4[0]), arg4[1], arg4[2], arg4[3]}
	           _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	             _mm_hadd_ps(   //arg2 ← {arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	               val_pow,        //arg0: val_pow
	               _mm_setzero_ps()//arg1 ← {0.f, 0.f, 0.f, 0.f}
	             ),
	            _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	           )
	         )
	       );
}
inline __m128 calc_normalize(const __m128 val)//正規化
{
	const __m128 val_pow = _mm_mul_ps(val, val);//ret ← {val[0] * val[0], val[1] * val[1], val[2] * val[2], val[3] * val[3]}
	return _mm_div_ps(//ret ← {arg7[0] / arg8[0], arg7[1] / arg8[1], arg7[2] / arg8[2], arg7[3] / arg8[3]}
	         val,        //arg7: val
	         _mm_set1_ps(//arg8 ← {arg6, arg6, arg6, arg6}
	           get_scalar(//arg6 ← arg5[0]
	            _mm_sqrt_ss(//arg5 ← {sqrt(arg4[0]), arg4[1], arg4[2], arg4[3]}
	             _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	               _mm_hadd_ps(      //arg2 ← {arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	                   val_pow,        //arg0: val_pow
	                   _mm_setzero_ps()//arg1 ← {0.f, 0.f, 0.f, 0.f}
	                 ),
	                 _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	               )
	             )
	           )
	         )
	       );
}
inline float calc_dist2(const __m128 from, const __m128 to)//距離^2計算
{
	const __m128 val_diff = _mm_sub_ps(to, from);//ret ← {to[0] - from[0], to[1] - from[1], to[2] - from[2], to[3] - from[3]}
	const __m128 val_pow = _mm_mul_ps(val_diff, val_diff);//ret ← {val_diff[0] * val_diff[0], val_diff[1] * val_diff[1], val_diff[2] * val_diff[2], val_diff[3] * val_diff[3]}
	return get_scalar(//ret ← arg4[0]
	         _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	           _mm_hadd_ps(    //arg2 ← :{arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	             val_pow,        //arg0: val_pow
	             _mm_setzero_ps()//arg1 ← {0.f, 0.f, 0.f, 0.f}
	           ),
	           _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	         )
	       );
}
inline float calc_dist(const __m128 from, const __m128 to)//距離計算
{
	const __m128 val_diff = _mm_sub_ps(to, from);//ret ← {to[0] - from[0], to[1] - from[1], to[2] - from[2], to[3] - from[3]}
	const __m128 val_pow = _mm_mul_ps(val_diff, val_diff);//ret ← {val_diff[0] * val_diff[0], val_diff[1] * val_diff[1], val_diff[2] * val_diff[2], val_diff[3] * val_diff[3]}
	return get_scalar(//ret ← arg5[0]
	         _mm_sqrt_ss(//arg5 ← {sqrt(arg4[0]), arg4[1], arg4[2], arg4[3]}
	           _mm_hadd_ps(//arg4 ← {arg2[0] + arg2[1], arg2[2] + arg2[3], arg3[0] + arg3[1], arg3[2] + arg3[3]}
	             _mm_hadd_ps(    //arg2 ← {arg0[0] + arg0[1], arg0[2] + arg0[3], arg1[0] + arg1[1], arg1[2] + arg1[3]}
	               val_pow,        //arg0: val_pow
	               _mm_setzero_ps()//arg1 ← {0.f, 0.f, 0.f, 0.f}
	             ),
	             _mm_setzero_ps()//arg3 ← {0.f, 0.f, 0.f, 0.f}
	           )
	         )
	       );
}
#endif//USE_SIMD

struct vec4
{
	//フィールド
	float ATTR_SIMD128 m_val[4];
	//アクセッサ
	inline float& x() { return m_val[0]; }
	inline float& y() { return m_val[1]; }
	inline float& z() { return m_val[2]; }
	inline float& w() { return m_val[3]; }
	inline float x() const { return m_val[0]; }
	inline float y() const { return m_val[1]; }
	inline float z() const { return m_val[2]; }
	inline float w() const { return m_val[3]; }
	inline void x(const float val){ m_val[0] = val; }
	inline void y(const float val){ m_val[1] = val; }
	inline void z(const float val){ m_val[2] = val; }
	inline void w(const float val){ m_val[3] = val; }
	inline float& operator[](const int index){ return m_val[index]; }
	inline const float& operator[](const int index) const { return m_val[index]; }
	//オペレータ
	inline vec4& operator+=(const vec4& rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg2 → m_val
		  calc_add(//arg2 ← {arg0[0] + arg1[0], arg0[1] + arg1[1], arg0[2] + arg1[2], arg0[3] + arg1[3]}
		    _mm_load_ps(m_val),   //arg0 ← m_val
		    _mm_load_ps(rhs.m_val)//arg1 ← rhs.m_val
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[index] += rhs.m_val[index];
	#endif//USE_SIMD
		return *this;
	}
	inline vec4& operator+=(const float rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg2 → m_val
		  calc_add(//arg2 ← {arg0[0] + arg1[0], arg0[1] + arg1[1], arg0[2] + arg1[2], arg0[3] + arg1[3]}
		    _mm_load_ps(m_val),//arg0 ← m_val
		    _mm_set1_ps(rhs)   //arg1 ← {rhs, rhs, rhs, rhs}
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[index] += rhs;
	#endif//USE_SIMD
		return *this;
	}
	inline vec4& operator-=(const vec4& rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg2 → m_val
		  calc_sub(//arg2 ← {arg0[0] - arg1[0], arg0[1] - arg1[1], arg0[2] - arg1[2], arg0[3] - arg1[3]}
		    _mm_load_ps(m_val),   //arg0 ← m_val
		    _mm_load_ps(rhs.m_val)//arg1 ← rhs.m_val
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[index] -= rhs.m_val[index];
	#endif//USE_SIMD
		return *this;
	}
	inline vec4& operator-=(const float rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg2 → m_val
		  calc_sub(//arg2 ← {arg0[0] - arg1[0], arg0[1] - arg1[1], arg0[2] - arg1[2], arg0[3] - arg1[3]}
		    _mm_load_ps(m_val),//arg0 ← m_val
		    _mm_set1_ps(rhs)   //arg1 ← {rhs, rhs, rhs, rhs}
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[index] -= rhs;
	#endif//USE_SIMD
		return *this;
	}
	inline vec4& operator*=(const vec4& rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg2 → m_val
		  calc_mul(//arg2 ← {arg0[0] * arg1[0], arg0[1] * arg1[1], arg0[2] * arg1[2], arg0[3] * arg1[3]}
		    _mm_load_ps(m_val),   //arg0 ← m_val
		    _mm_load_ps(rhs.m_val)//arg1 ← rhs.m_val
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[index] *= rhs.m_val[index];
	#endif//USE_SIMD
		return *this;
	}
	inline vec4& operator*=(const float rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg2 → m_val
		  calc_mul(//arg2 ← {arg0[0] * arg1[0], arg0[1] * arg1[1], arg0[2] * arg1[2], arg0[3] * arg1[3]}
		    _mm_load_ps(m_val),//arg0 ← m_val
		    _mm_set1_ps(rhs)   //arg1 ← {rhs, rhs, rhs, rhs}
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[index] *= rhs;
	#endif//USE_SIMD
		return *this;
	}
	inline vec4& operator/=(const vec4& rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg2 → m_val
		  calc_div(//arg2 ← {arg0[0] / arg1[0], arg0[1] / arg1[1], arg0[2] / arg1[2], arg0[3] / arg1[3]}
		    _mm_load_ps(m_val),   //arg0 ← m_val
		    _mm_load_ps(rhs.m_val)//arg1 ← rhs.m_val
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[index] /= rhs.m_val[index];
	#endif//USE_SIMD
		return *this;
	}
	inline vec4& operator/=(const float rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg2 → m_val
		  calc_div(//arg2 ← {arg0[0] / arg1[0], arg0[1] / arg1[1], arg0[2] / arg1[2], arg0[3] / arg1[3]}
		    _mm_load_ps(m_val),//arg0 ← m_val
		    _mm_set1_ps(rhs)   //arg1 ← {rhs, rhs, rhs, rhs}
		  )
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
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
#endif//USE_SIMD
	//コピーオペレータ
	inline vec4& operator=(const vec4& rhs)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
		  _mm_load_ps(rhs.m_val)//arg0 ← rhs.m_val
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[index] = rhs.m_val[index];
	#endif//USE_SIMD
		return *this;
	}
#ifdef USE_SIMD
	inline vec4& operator=(const __m128 rhs)
	{
		_mm_store_ps(m_val,//arg0 → m_val
		  rhs//arg0: rhs
		);
		return *this;
	}
#endif//USE_SIMD
	//メソッド
	//ノルム^2取得
	inline float norm2() const
	{
	#ifdef USE_SIMD
		return calc_norm2(//ret ← calc_norm2(arg0)
		         _mm_load_ps(m_val)//arg0 ← m_val
		       );
	#else//USE_SIMD
		return m_val[0] * m_val[0] +
		       m_val[1] * m_val[1] +
		       m_val[2] * m_val[2] +
		       m_val[3] * m_val[3];
	#endif//USE_SIMD
	}
	//ノルム取得
	inline float norm() const
	{
	#ifdef USE_SIMD
		return calc_norm(//ret ← calc_norm(arg0)
		         _mm_load_ps(m_val)//arg0 ← m_val
		       );
	#else//USE_SIMD
		return sqrt(
		         m_val[0] * m_val[0] +
		         m_val[1] * m_val[1] +
		         m_val[2] * m_val[2] +
		         m_val[3] * m_val[3]
		       );
	#endif//USE_SIMD
	}
	//正規化
	inline vec4& normalize()
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg1 → m_val
		  calc_normalize(//arg1 ← calc_normalize(arg0)
		    _mm_load_ps(m_val)//arg0 ← m_val
		  )
		);
	#else//USE_SIMD
		const float norm = sqrt(
		                     m_val[0] * m_val[0] +
		                     m_val[1] * m_val[1] +
		                     m_val[2] * m_val[2] +
		                     m_val[3] * m_val[3]
		                   );
		for (int index = 0; index < 4; ++index)
			m_val[index] /= norm;
	#endif//USE_SIMD
		return *this;
	}
	inline const vec4 normalize() const
	{
	#ifdef USE_SIMD
		return vec4(
		         calc_normalize(//ret ← calc_normalize(arg0)
		           _mm_load_ps(m_val)//arg0 ← m_val
		         )
		       );
	#else//USE_SIMD
		const float norm = sqrt(
			m_val[0] * m_val[0] +
			m_val[1] * m_val[1] +
			m_val[2] * m_val[2] +
			m_val[3] * m_val[3]
			);
		return vec4(m_val[0] / norm, m_val[1] / norm, m_val[2] / norm, m_val[3] / norm);
	#endif//USE_SIMD
	}
	//距離^2計算
	inline float dist2(const vec4& from)
	{
	#ifdef USE_SIMD
		return calc_dist2(//ret ← calc_dist2(arg0)
		         _mm_load_ps(from.m_val),//arg0 ← from.m_val
		         _mm_load_ps(m_val)      //arg1 ← m_val
		       );
	#else//USE_SIMD
		vec4 tmp(*this);
		tmp -= from;
		return tmp.norm2();
	#endif//USE_SIMD
	}
	//距離計算
	inline float dist(const vec4& from)
	{
	#ifdef USE_SIMD
		return calc_dist(//ret ← calc_dist(arg0)
		         _mm_load_ps(from.m_val),//arg0 ← from.m_val
		         _mm_load_ps(m_val)      //arg1 ← m_val
		       );
	#else//USE_SIMD
		vec4 tmp(*this);
		tmp -= from;
		return tmp.norm();
	#endif//USE_SIMD
	}
	//コンストラクタ
	inline vec4(const float x, const float y, const float z, const float w)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
		  _mm_set_ps(w, z, y, x)//arg0 ← {x, y, z, w}
		);
	#else//USE_SIMD
		m_val[0] = x;
		m_val[1] = y;
		m_val[2] = z;
		m_val[3] = w;
	#endif//USE_SIMD
	}
	inline vec4(const float x, const float y, const float z)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
		  _mm_set_ps(1.f, z, y, x)//arg0 ← {z, y, z, 1.f}
		);
	#else//USE_SIMD
		m_val[0] = x;
		m_val[1] = y;
		m_val[2] = z;
		m_val[3] = 1.f;
	#endif//USE_SIMD
	}
	inline vec4(const float val)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
		  _mm_set1_ps(val)//arg0 ← {val, val, val, val}
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[index] = val;
	#endif//USE_SIMD
	}
	inline vec4(const vec4& obj)
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
		  _mm_load_ps(obj.m_val)//arg0 ← obj.m_val
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[index] = obj.m_val[index];
	#endif//USE_SIMD
	}
#ifdef USE_SIMD
	inline vec4(const __m128 val)
	{
		_mm_store_ps(m_val,//arg0 → m_val
		  val//arg0: val
		);
	}
#endif//USE_SIMD
	inline vec4()
	{
	#ifdef USE_SIMD
		_mm_store_ps(m_val,//arg0 → m_val
		  _mm_setzero_ps()//arg0 ← {0.f, 0.f, 0.f, 0.f}
		);
	#else//USE_SIMD
		for (int index = 0; index < 4; ++index)
			m_val[0] = 0.f;
	#endif//USE_SIMD
	}
	//デストラクタ
	inline ~vec4()
	{}
};

//二項演算子用オペレータ
#ifdef USE_SIMD
//※SIMD演算時は vec4 型のままではなく、__m128型として演算する
inline __m128 operator+(const vec4& lhs, const vec4& rhs){ return calc_add(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128 operator+(const vec4& lhs, const __m128 rhs){ return calc_add(static_cast<__m128>(lhs), rhs); }
inline __m128 operator+(const __m128 lhs, const vec4& rhs){ return calc_add(lhs, static_cast<__m128>(rhs)); }

inline __m128 operator-(const vec4& lhs, const vec4& rhs){ return calc_sub(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128 operator-(const vec4& lhs, const __m128 rhs){ return calc_sub(static_cast<__m128>(lhs), rhs); }
inline __m128 operator-(const __m128 lhs, const vec4& rhs){ return calc_sub(lhs, static_cast<__m128>(rhs)); }

inline __m128 operator*(const vec4& lhs, const vec4& rhs){ return calc_mul(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128 operator*(const vec4& lhs, const __m128 rhs){ return calc_mul(static_cast<__m128>(lhs), rhs); }
inline __m128 operator*(const __m128 lhs, const vec4& rhs){ return calc_mul(lhs, static_cast<__m128>(rhs)); }

inline __m128 operator/(const vec4& lhs, const vec4& rhs){ return calc_div(static_cast<__m128>(lhs), static_cast<__m128>(rhs)); }
inline __m128 operator/(const vec4& lhs, const __m128 rhs){ return calc_div(static_cast<__m128>(lhs), rhs); }
inline __m128 operator/(const __m128 lhs, const vec4& rhs){ return calc_div(lhs, static_cast<__m128>(rhs)); }

inline float norm2(const vec4& val){ return calc_norm2(static_cast<__m128>(val)); }

inline float norm(const vec4& val){ return calc_norm(static_cast<__m128>(val)); }

inline __m128 normalize(const vec4& val){ return calc_normalize(static_cast<__m128>(val)); }

inline float dist2(const vec4& from, const vec4& to){ return calc_dist2(static_cast<__m128>(from), static_cast<__m128>(to)); }
inline float dist2(const vec4& from, const __m128 to){ return calc_dist2(static_cast<__m128>(from), to); }
inline float dist2(const __m128 from, const vec4& to){ return calc_dist2(from, static_cast<__m128>(to)); }

inline float dist(const vec4& from, const vec4& to){ return calc_dist(static_cast<__m128>(from), static_cast<__m128>(to)); }
inline float dist(const vec4& from, const __m128 to){ return calc_dist(static_cast<__m128>(from), to); }
inline float dist(const __m128 from, const vec4& to){ return calc_dist(from, static_cast<__m128>(to)); }

#else//USE_SIMD
//※非SIMD演算時は vec4 型のまま演算する
inline vec4 operator+(const vec4& lhs, const vec4& rhs){ vec4 tmp(lhs); return (tmp += rhs); }
inline vec4 operator-(const vec4& lhs, const vec4& rhs){ vec4 tmp(lhs); return (tmp -= rhs); }
inline vec4 operator*(const vec4& lhs, const vec4& rhs){ vec4 tmp(lhs); return (tmp *= rhs); }
inline vec4 operator/(const vec4& lhs, const vec4& rhs){ vec4 tmp(lhs); return (tmp /= rhs); }
inline float norm2(const vec4& val){ return val.norm2(); }
inline float norm(const vec4& val){ return val.norm(); }
inline vec4 normalize(const vec4& val){ vec4 tmp(val); return tmp.normalize(); }
inline float dist2(const vec4& from, const vec4& to){ vec4 tmp(to); return tmp.dist2(from); }
inline float dist(const vec4& from, const vec4& to){ vec4 tmp(to); return tmp.dist(from); }
#endif//USE_SIMD

#endif//__VECTOR_H_

// End of file

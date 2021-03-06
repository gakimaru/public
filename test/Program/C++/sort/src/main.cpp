//--------------------------------------------------------------------------------
//ソートアルゴリズム用コンパイラスイッチ
#ifdef _OPENMP
#define ODD_EVEN_SORT_USE_OPENMP//奇遇転置ソート：OpenMPを使用する場合は、このマクロを有効にする
#define SHEAR_SORT_USE_OPENMP//シェアソート：OpenMPを使用する場合は、このマクロを有効にする
//#define SHEAR_SORT_USE_OPENMP_NEST//シェアソート：OpenMPのparallelの入れ子処理を使用する場合は、このマクロを有効にする ※有効にするとかえって遅くなる、もしくは、正常に動作しない
//#define INPLACE_MERGE_SORT_USE_OPENMP//インプレースマージソート：OpenMPを使用する場合は、このマクロを有効にする ※有効にすると遅くなることがある
#endif//_OPENMP
#define QUICK_SORT_NO_USE_RECURSIVE_CALL//クイックソートの再帰処理版を無効にする場合は、このマクロを有効にする
#ifdef _OPENMP
//#define QUICK_SORT_USE_OPENMP//クイックソート：OpenMPを使用する場合は、このマクロを有効にする ※有効にするとかえって遅くなる
#endif//_OPENMP

#include <stdio.h>
#include <stdlib.h>

#include <stdlib.h>//qsort関数用
#include <stdint.h>//intptr_t用
#include <crtdefs.h>//ptrdiff_t用
#include <cstddef>//std::size_t用
#include <type_traits>//C++11 std::is_class, std::conditional用
#include <functional>//std::less, std::greater用
#include <utility>//C++11 std::move用
#include <assert.h>//assert用

#include "basic.h"

//--------------------------------------------------------------------------------
//様々なソートアルゴリズム
//--------------------------------------------------------------------------------

//========================================
//ソート／探索補助処理
//========================================

//----------------------------------------
//ソート用標準プレディケート関数オブジェクト：less
//※対象オブジェクトが operator<に対応している必要あり
template<typename T>
struct less{
	inline bool operator()(const T& val1, const T& val2) const
	{
		return val1 < val2;
	}
};
//----------------------------------------
//線形探索用標準プレディケート関数オブジェクト：eqal_to
//※対象オブジェクトが operator==に対応している必要あり
template<typename T>
struct equal_to{
	template<typename V>
	inline bool operator()(const T& val1, const V& val2) const
	{
		return val1 == val2;
	}
};
//----------------------------------------
//二分探索用標準比較関数オブジェクト：compare_to
//※対象オブジェクトが operator==, operator<に対応している必要あり
template<typename T>
struct compare_to{
	template<typename V>
	inline int operator()(const T& val1, const V& val2) const
	{
		if (val1 == val2)
			return 0;
		else if (val1 < val2)
			return 1;
		else//if (val1 > val2)
			return -1;
	}
};

//----------------------------------------
//比較ソート処理オーバーロード関数用マクロ
//※プレディケート関数指定版
#define sortFuncSetByUserPredicate(func_name) \
	template<class T, std::size_t N, class PREDICATE> \
	inline std::size_t func_name(T(&array)[N], PREDICATE predicate) \
	{ \
		return func_name(array, N, predicate); \
	} \
	template<class T, class PREDICATE> \
	inline std::size_t func_name(T* begin, T* end, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(begin, size, predicate); \
	} \
	template<class ITERATOR, class PREDICATE> \
	inline std::size_t func_name(ITERATOR& begin, ITERATOR& end, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(&begin[0], size, predicate); \
	} \
	template<class CONTAINER, class PREDICATE> \
	inline std::size_t func_name(CONTAINER& con, PREDICATE predicate) \
	{ \
		std::size_t size = con.size(); \
		return size == 0 ? 0 : func_name(&(con.at(0)), size, predicate); \
	}
//※標準プレディケート関数使用版
#define sortFuncSetByDefaultPredicate(func_name) \
	template<class T> \
	inline std::size_t func_name(T* array, const std::size_t size) \
	{ \
		return func_name(array, size, less<T>()); \
	} \
	template<class T, std::size_t N> \
	inline std::size_t func_name(T(&array)[N]) \
	{ \
		return func_name(array, less<T>()); \
	} \
	template<class T> \
	inline std::size_t func_name(T* begin, T* end) \
	{ \
		return func_name(begin, end, less<T>()); \
	} \
	template<class ITERATOR> \
	inline std::size_t func_name(ITERATOR& begin, ITERATOR& end) \
	{ \
		return func_name(begin, end, less<typename ITERATOR::value_type>()); \
	} \
	template<class CONTAINER> \
	inline std::size_t func_name(CONTAINER& con) \
	{ \
		return func_name(con, less<typename CONTAINER::value_type>()); \
	}
#define sortFuncSet(func_name) \
	sortFuncSetByUserPredicate(func_name) \
	sortFuncSetByDefaultPredicate(func_name)

//----------------------------------------
//非比較ソート処理オーバーロード関数用マクロ
//※キー取得用関数オブジェクト指定版
#define distributedSortFuncSetByUserFunctor(func_name) \
	template<class T, std::size_t N, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(T(&array)[N], GET_KEY_FUNCTOR get_key_functor) \
	{ \
		return func_name(array, N, get_key_functor); \
	} \
	template<class T, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(T* begin, T* end, GET_KEY_FUNCTOR get_key_functor) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(begin, size, get_key_functor); \
	} \
	template<class ITERATOR, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(ITERATOR& begin, ITERATOR& end, GET_KEY_FUNCTOR get_key_functor) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? 0 : func_name(&begin[0], size, get_key_functor); \
	} \
	template<class CONTAINER, class GET_KEY_FUNCTOR> \
	inline std::size_t func_name(CONTAINER& con, GET_KEY_FUNCTOR get_key_functor) \
	{ \
		std::size_t size = con.size(); \
		return size == 0 ? 0 : func_name(&(con.at(0)), size, get_key_functor); \
	}
#define distributedSortFuncSet(func_name) \
	distributedSortFuncSetByUserFunctor(func_name)

//----------------------------------------
//探索処理オーバーロード関数用マクロ
#define searchFuncSetByUserFunc(func_name) \
	template<class T, class PREDICATE_OR_COMPARISON> \
	inline const T* func_name(const T* array, const std::size_t size, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		return func_name(const_cast<T*>(array), size, predicate_or_comparison); \
	} \
	template<class T, std::size_t N, class PREDICATE_OR_COMPARISON> \
	inline T* func_name(T(&array)[N], PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		return func_name(array, N, predicate_or_comparison); \
	} \
	template<class T, std::size_t N, class PREDICATE_OR_COMPARISON> \
	inline const T* func_name(const T(&array)[N], PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		return func_name(const_cast<T*>(array), N, predicate_or_comparison); \
	} \
	template<class T, class PREDICATE_OR_COMPARISON> \
	inline T* func_name(T* begin, T* end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(begin, size, predicate_or_comparison); \
	} \
	template<class T, class PREDICATE_OR_COMPARISON> \
	inline const T* func_name(const T* begin, const T* end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, predicate_or_comparison); \
	} \
	template<class ITERATOR, class PREDICATE_OR_COMPARISON> \
	inline typename ITERATOR::value_type* func_name(ITERATOR& begin, ITERATOR& end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(&begin[0], size, predicate_or_comparison); \
	} \
	template<class ITERATOR, class PREDICATE_OR_COMPARISON> \
	inline const typename ITERATOR::value_type* func_name(const ITERATOR& begin, const ITERATOR& end, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = end - begin; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, predicate_or_comparison); \
	} \
	template<class CONTAINER, class PREDICATE_OR_COMPARISON> \
	inline typename CONTAINER::value_type* func_name(CONTAINER& con, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = con.size(); \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, predicate_or_comparison); \
	} \
	template<class CONTAINER, class PREDICATE_OR_COMPARISON> \
	inline const typename CONTAINER::value_type* func_name(const CONTAINER& con, PREDICATE_OR_COMPARISON predicate_or_comparison) \
	{ \
		const std::size_t size = con.size(); \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, predicate_or_comparison); \
	}
//※探索値指定版：プレディケート関数と値で比較
#define searchFuncSetPredicateAndValue(func_name) \
	template<class T, typename V, class PREDICATE> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(array, size, _equal); \
	} \
	template<class T, typename V, class PREDICATE> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _equal); \
	} \
	template<class T, std::size_t N, typename V, class PREDICATE> \
	inline T* func_name##Value(T(&array)[N], const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(array, N, _equal); \
	} \
	template<class T, std::size_t N, typename V, class PREDICATE> \
	inline const T* func_name##Value(const T(&array)[N], const V& value, PREDICATE predicate) \
	{ \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _equal); \
	} \
	template<class T, typename V, class PREDICATE> \
	inline T* func_name##Value(T* begin, T* end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _equal); \
	} \
	template<class T, typename V, class PREDICATE> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const T& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _equal); \
	} \
	template<class ITERATOR, typename V, class PREDICATE> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const typename ITERATOR::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _equal); \
	} \
	template<class ITERATOR, typename V, class PREDICATE> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value, &predicate](const typename ITERATOR::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _equal); \
	} \
	template<class CONTAINER, typename V, class PREDICATE> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value, &predicate](const typename CONTAINER::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _equal); \
	} \
	template<class CONTAINER, typename V, class PREDICATE> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value, PREDICATE predicate) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value, &predicate](const typename CONTAINER::value_type& val1) -> bool { return predicate(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _equal); \
	}
//※探索値指定版：標準のプレディケート関数と値で比較
#define searchFuncSetByDefaultPredicateAndValue(func_name) \
	template<class T, typename V> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value) \
	{ \
		auto _equal = [&value](T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(array, size, _equal); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value) \
	{ \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _equal); \
	} \
	template<class T, std::size_t N, typename V> \
	inline T* func_name##Value(T(&array)[N], const V& value) \
	{ \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(array, N, _equal); \
	} \
	template<class T, std::size_t N, typename V> \
	inline const T* func_name##Value(const T(&array)[N], const V& value) \
	{ \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _equal); \
	} \
	template<class T, typename V> \
	inline T* func_name##Value(T* begin, T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _equal); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const T& val1) -> bool { return equal_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _equal); \
	} \
	template<class ITERATOR, typename V> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const typename ITERATOR::value_type& val1) -> bool { return equal_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _equal); \
	} \
	template<class ITERATOR, typename V> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _equal = [&value](const typename ITERATOR::value_type& val1) -> bool { return equal_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _equal); \
	} \
	template<class CONTAINER, typename V> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value](const typename CONTAINER::value_type& val1) -> bool { return equal_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _equal); \
	} \
	template<class CONTAINER, typename V> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _equal = [&value](const typename CONTAINER::value_type& val1) -> bool { return equal_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _equal); \
	}
#define searchFuncSetByPredicate(func_name) \
	searchFuncSetByUserFunc(func_name) \
	searchFuncSetPredicateAndValue(func_name) \
	searchFuncSetByDefaultPredicateAndValue(func_name)
//※探索値指定版：比較関数と値で比較
#define searchFuncSetByComparisonAndValue(func_name) \
	template<class T, typename V, class COMPARISON> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](T& val1) -> int { return comparison(val1, value); }; \
		return func_name(array, size, _comparison); \
	} \
	template<class T, typename V, class COMPARISON> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _comparison); \
	} \
	template<class T, std::size_t N, typename V, class COMPARISON> \
	inline T* func_name##Value(T(&array)[N], const V& value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return func_name(array, N, _comparison); \
	} \
	template<class T, std::size_t N, typename V, class COMPARISON> \
	inline const T* func_name##Value(const T(&array)[N], const V &value, COMPARISON comparison) \
	{ \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _comparison); \
	} \
	template<class T, typename V, class COMPARISON> \
	inline T* func_name##Value(T* begin, T* end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _comparison); \
	} \
	template<class T, typename V, class COMPARISON> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const T& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _comparison); \
	} \
	template<class ITERATOR, typename V, class COMPARISON> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const typename ITERATOR::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _comparison); \
	} \
	template<class ITERATOR, typename V, class COMPARISON> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value, &comparison](const typename ITERATOR::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _comparison); \
	} \
	template<class CONTAINER, typename V, class COMPARISON> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value, &comparison](const typename CONTAINER::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _comparison); \
	} \
	template<class CONTAINER, typename V, class COMPARISON> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value, COMPARISON comparison) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value, &comparison](const typename CONTAINER::value_type& val1) -> int { return comparison(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _comparison); \
	}
//※探索値指定版：標準比較関数と値で比較
#define searchFuncSetByDefaultComparisonAndValue(func_name) \
	template<class T, typename V> \
	inline T* func_name##Value(T* array, const std::size_t size, const V& value) \
	{ \
		auto _comparison = [&value](T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(array, size, _comparison); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* array, const std::size_t size, const V& value) \
	{ \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), size, _comparison); \
	} \
	template<class T, std::size_t N, typename V> \
	inline T* func_name##Value(T(&array)[N], const V& value) \
	{ \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(array, N, _comparison); \
	} \
	template<class T, std::size_t N, typename V> \
	inline const T* func_name##Value(const T(&array)[N], const V &value) \
	{ \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return func_name(const_cast<T*>(array), N, _comparison); \
	} \
	template<class T, typename V> \
	inline T* func_name##Value(T* begin, T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(begin, size, _comparison); \
	} \
	template<class T, typename V> \
	inline const T* func_name##Value(const T* begin, const T* end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const T& val1) -> int { return compare_to<T>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<T*>(begin), size, _comparison); \
	} \
	template<class ITERATOR, typename V> \
	inline typename ITERATOR::value_type* func_name##Value(ITERATOR& begin, ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const typename ITERATOR::value_type& val1) -> int { return compare_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&begin[0], size, _comparison); \
	} \
	template<class ITERATOR, typename V> \
	inline const typename ITERATOR::value_type* func_name##Value(const ITERATOR& begin, const ITERATOR& end, const V& value) \
	{ \
		const std::size_t size = end - begin; \
		auto _comparison = [&value](const typename ITERATOR::value_type& val1) -> int { return compare_to<typename ITERATOR::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(const_cast<typename ITERATOR::value_type*>(&begin[0]), size, _comparison); \
	} \
	template<class CONTAINER, typename V> \
	inline typename CONTAINER::value_type* func_name##Value(CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value](const typename CONTAINER::value_type& val1) -> int { return compare_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(con.at(0)), size, _comparison); \
	} \
	template<class CONTAINER, typename V> \
	inline const typename CONTAINER::value_type* func_name##Value(const CONTAINER& con, const V& value) \
	{ \
		const std::size_t size = con.size(); \
		auto _comparison = [&value](const typename CONTAINER::value_type& val1) -> int { return compare_to<typename CONTAINER::value_type>()(val1, value); }; \
		return size == 0 ? nullptr : func_name(&(const_cast<CONTAINER*>(&con)->at(0)), size, _comparison); \
	}
#define searchFuncSetByComparison(func_name) \
	searchFuncSetByUserFunc(func_name) \
	searchFuncSetByComparisonAndValue(func_name) \
	searchFuncSetByDefaultComparisonAndValue(func_name)

//----------------------------------------
//整列状態確認
template<class T, class PREDICATE>
inline std::size_t calcUnordered(const T* array, const std::size_t size, PREDICATE predicate)
{
	std::size_t unordered = 0;
	const T* prev = array;
	const T* now = prev + 1;
	for (std::size_t i = 1; i < size; ++i, ++now, ++prev)
	{
		if (predicate(*now, *prev))
			++unordered;
	}
	return unordered;
}
sortFuncSet(calcUnordered);

//----------------------------------------
//データの入れ替え
template<class T>
struct _swapArithmetic{
	inline static void exec(T& val1, T& val2)
	{
		T tmp;
		tmp = val2;
		val2 = val1;
		val1 = tmp;
	}
};
template<class T>
struct _swapArithmetic<T*>{
	inline static void exec(T*& val1, T*& val2)
	{
		T* tmp;
		tmp = val2;
		val2 = val1;
		val1 = tmp;
	}
};
template<class T>
struct _swapObjects{
	inline static void exec(T& val1, T& val2)
	{
	#if 1//ムーブコンストラクタとムーブオペレータを使用して入れ替え（#include <utility> の std::swap() と同じ）
		T tmp = std::move(val2);
		val2 = std::move(val1);
		val1 = std::move(tmp);
	#else//コンストラクタ／オペレータの呼び出しを避けて単純なメモリコピー
		char tmp[sizeof(T)];
		memcpy(tmp, &val2, sizeof(T));
		memcpy(&val2, &val1, sizeof(T));
		memcpy(&val1, tmp, sizeof(T));
	#endif
	}
};
template<class T>
struct _swapObjects<T*>{
	inline static void exec(T*& val1, T*& val2)
	{
		_swapArithmetic<T*>::exec(val1, val2);
	}
};
//データ入れ替え関数（直接使用する関数）
template<class T>
inline void swapValues(T& val1, T& val2)
{
	std::conditional<std::is_arithmetic<T>::value,
		_swapArithmetic<T>,
		_swapObjects<T>
	>::type::exec(val1, val2);
}

//----------------------------------------
//データのローテーション
template<class T>
struct _rotateArithmetic{
	inline static void exec(T* val1, T* val2, int step)
	{
		T tmp;
		tmp = *val2;
		while (val1 != val2)
		{
			T* val2_prev = val2 - step;
			*val2 = *val2_prev;
			val2 = val2_prev;
		}
		*val1 = tmp;
	}
};
template<class T>
struct _rotateArithmetic<T*>{
	inline static void exec(T** val1, T** val2, int step)
	{
		T* tmp;
		tmp = *val2;
		while (val1 != val2)
		{
			T** val2_prev = val2 - step;
			*val2 = *val2_prev;
			val2 = val2_prev;
		}
		*val1 = tmp;
	}
};
template<class T>
struct _rotateObjects{
	inline static void exec(T* val1, T* val2, int step)
	{
	#if 1//ムーブコンストラクタとムーブオペレータを使用して入れ替え
		T tmp = std::move(*val2);
		while (val1 != val2)
		{
			T* val2_prev = val2 - step;
			*val2 = std::move(*val2_prev);
			val2 = val2_prev;
		}
		*val1 = std::move(tmp);
	#else//コンストラクタ／オペレータの呼び出しを避けて単純なメモリコピー
		char tmp[sizeof(T)];
		memcpy(tmp, val2, sizeof(T));
		while (val1 != val2)
		{
			T* val2_prev = val2 - step;
			memcpy(val2, val2_prev, sizeof(T));
			val2 = val2_prev;
		}
		memcpy(val1, tmp, sizeof(T));
	#endif
	}
};
template<class T>
struct _rotateObjects<T*>{
	inline static void exec(T** val1, T** val2, int step)
	{
		_rotateArithmetic<T*>::exec(val1, val2, step);
	}
};
//データローテーション関数（直接使用する関数）
template<class T>
inline void rotateValues(T* val1, T* val2, int step)
{
	std::conditional<std::is_arithmetic<T>::value,
		_rotateArithmetic<T>,
		_rotateObjects<T>
	>::type::exec(val1, val2, step);
}

//----------------------------------------
//イテレータの差（要素数）を返す
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::input_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::output_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::forward_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::bidirectional_iterator_tag)
{
	typename ITERATOR::difference_type size = 0;
	for (; begin != end; ++begin)
		++size;
	return size;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end, std::random_access_iterator_tag)
{
	return end - begin;
}
template<class ITERATOR>
inline typename ITERATOR::difference_type iteratorDifference(ITERATOR begin, ITERATOR end)
{
	typename ITERATOR::iterator_category category;
	return iteratorDifference(begin, end, category);
}

//----------------------------------------
//for-each
template<class ITERATOR, class FUNCTOR>
void forEach(ITERATOR begin, ITERATOR end, FUNCTOR functor)
{
	for (; begin != end; ++begin)
	{
		functor(*begin);
	}
}
template<class CONTAINER, class FUNCTOR>
void forEach(CONTAINER container, FUNCTOR functor)
{
	typename CONTAINER::iterator begin = container.begin();
	typename CONTAINER::iterator end = container.end();
	forEach(begin, end, functor);
}
template<typename T, std::size_t N, class FUNCTOR>
void forEach(T(&array)[N], FUNCTOR functor)
{
	T* begin = array;
	T* end = array + N;
	forEach(begin, end, functor);
}
template<typename T, std::size_t N, class FUNCTOR>
void forEach(const T(&array)[N], FUNCTOR functor)
{
	const T* begin = array;
	const T* end = array + N;
	forEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void forEach(T* array, const std::size_t size, FUNCTOR functor)
{
	T* begin = array;
	T* end = array + size;
	forEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void forEach(const T* array, const std::size_t size, FUNCTOR functor)
{
	const T* begin = array;
	const T* end = array + size;
	forEach(begin, end, functor);
}
//----------------------------------------
//reverse for-each
template<class ITERATOR, class FUNCTOR>
void reverseForEach(ITERATOR begin, ITERATOR end, FUNCTOR functor)
{
	while (begin != end)
	{
		--begin;
		functor(*begin);
	}
}
template<class CONTAINER, class FUNCTOR>
void reverseForEach(CONTAINER container, FUNCTOR functor)
{
	typename CONTAINER::reverse_iterator rbegin = container.rbegin();
	typename CONTAINER::reverse_iterator rend = container.rend();
	forEach(rbegin, rend, functor);//リバースイテレータ＋forEachで処理
}
template<typename T, std::size_t N, class FUNCTOR>
void reverseForEach(T(&array)[N], FUNCTOR functor)
{
	T* begin = array + N;
	T* end = array;
	reverseForEach(begin, end, functor);
}
template<typename T, std::size_t N, class FUNCTOR>
void reverseForEach(const T(&array)[N], FUNCTOR functor)
{
	const T* begin = array + N;
	const T* end = array;
	reverseForEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void reverseForEach(T* array, const std::size_t size, FUNCTOR functor)
{
	T* begin = array + size;
	T* end = array;
	reverseForEach(begin, end, functor);
}
template<typename T, class FUNCTOR>
void reverseForEach(const T* array, const std::size_t size, FUNCTOR functor)
{
	const T* begin = array + size;
	const T* end = array;
	reverseForEach(begin, end, functor);
}

//========================================
//ソートアルゴリズムの説明
//========================================

//・計算時間：
//    - O(n)       ... データ件数分の時間
//    - O(n ^ 2)   ... データ件数の２乗分の時間
//    - O(log n)   ... log2(データ件数)分の時間（4→2, 16→4, 1024→10,1048576→20）
//    - O(n log n) ... n×log n 分の時間
//・メモリ使用量：
//    - O(1)       ... １件分のメモリが必要
//    - O(n)       ... データ件数分のメモリが必要
//    - O(log n)   ... log2(データ件数)分のメモリが必要
//・安定性：
//    - ○         ... キーが同じデータの順序性が維持されることを保証する
//                     例：{ 3-a, 5-b, 4-c, 5-d, 9-e, 3-f, 4-g, 3-h, 5-i } → { 3-a, 3-f, 3-h, 4-c, 4-g, 5-b, 5-d, 5-i, 9-e }
//    - ×         ... 例：(同上)                                          → { 3-a, 3-h, 3-f, 4-c, 4-g, 5-i, 5-d, 5-b, 9-e }

//========================================
//ソートアルゴリズム分類：交換ソート
//========================================

//----------------------------------------
//アルゴリズム：バブルソート
//----------------------------------------
//・最良計算時間：O(n)
//・平均計算時間：O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
//※交換発生有無のチェックを行い、最適化する。
//----------------------------------------
template<class T, class PREDICATE>
std::size_t bubbleSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	std::size_t end = size - 1;
	//for (std::size_t i = 0; i < end - 1; ++i)
	while (true)
	{
		bool is_swapped = false;
		T* now = array;
		T* next = now + 1;
		for (std::size_t ii = 0; ii < end; ++ii, ++now, ++next)
		{
			if (predicate(*next, *now))
			{
				swapValues(*next, *now);
				is_swapped = true;
				++swapped_count;
			}
		}
		--end;
		if (end == 0 || !is_swapped)
			break;
	}
	return swapped_count;
}
sortFuncSet(bubbleSort);

//----------------------------------------
//アルゴリズム：シェーカーソート
//----------------------------------------
//・最良計算時間：O(n)
//・平均計算時間：O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
//※交換発生有無のチェックを行い、最適化する。
//----------------------------------------
template<class T, class PREDICATE>
std::size_t shakerSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	std::size_t begin = 0;
	std::size_t end = size - 1;
	while(true)
	{
		bool is_swapped = false;
		T* now = array + begin;
		T* next = now + 1;
		for (std::size_t i = begin; i < end; ++i, ++now, ++next)
		{
			if (predicate(*next, *now))
			{
				swapValues(*next, *now);
				is_swapped = true;
				++swapped_count;
			}
		}
		--end;
		if (begin == end || !is_swapped)
			break;
		is_swapped = false;
		now = array + end;
		T* prev = now - 1;
		for (std::size_t i = end; i > begin; --i, --now, --prev)
		{
			if (predicate(*now, *prev))
			{
				swapValues(*now, *prev);
				is_swapped = true;
				++swapped_count;
			}
		}
		++begin;
		if (begin == end || !is_swapped)
			break;
	}
	return swapped_count;
}
sortFuncSet(shakerSort);

//----------------------------------------
//アルゴリズム：奇遇転置ソート
//----------------------------------------
//・最良計算時間：O(2n)
//・平均計算時間：O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)×並列処理分
//・安定性：　　　○
//----------------------------------------
//※OpenMPを使用し、並列化で最適化する。
//----------------------------------------
template<class T, class PREDICATE>
std::size_t oddEvenSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	std::size_t end = size - 1;
	bool is_swapped = true;
	while (is_swapped)
	{
		is_swapped = false;
		for (std::size_t odd_even = 0; odd_even < 2; ++odd_even)
		{
			int i;//本来は std::size_t
			T* now;
			T* next;
	#ifdef ODD_EVEN_SORT_USE_OPENMP
		#pragma omp parallel for reduction(+:swapped_count) reduction(||:is_swapped) private(now, next)
	#endif//ODD_EVEN_SORT_USE_OPENMP
			for (i = odd_even; i < static_cast<int>(end); i += 2)
			{
				now = array + i;
				next = now + 1;
				if (predicate(*next, *now))
				{
					swapValues(*next, *now);
					is_swapped = true;
					++swapped_count;
				}
			}
		}
	}
	return swapped_count;
}
sortFuncSet(oddEvenSort);

//----------------------------------------
//アルゴリズム：シェアソート
//----------------------------------------
//・最良計算時間：O(n^1.5)
//・平均計算時間：O(n^1.5)
//・最悪計算時間：O(n^1.5)
//・メモリ使用量：O(1)×並列処理分
//・安定性：　　　×
//----------------------------------------
//※OpenMPを使用し、並列化で最適化する。
//※内部で奇遇転地ソートを使用し、二重に並列化するが、
//　他のソートアルゴリズムを使用した方が効率的かもしれない。
//----------------------------------------
#include <math.h>//sqrt()用
#ifdef SHEAR_SORT_USE_OPENMP_NEST
#include <omp.h>//omp_set_nested()用
#endif//SHEAR_SORT_USE_OPENMP_NEST
template<class T, class PREDICATE>
std::size_t shearSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
#ifdef SHEAR_SORT_USE_OPENMP_NEST
	const int omp_nested_before = omp_get_nested();
	omp_set_nested(1);//並列化のネストを許可
#endif//SHEAR_SORT_USE_OPENMP_NEST
	std::size_t swapped_count = 0;
	int row;//本来は std::size_t
	int col;//本来は std::size_t
	std::size_t rows_col;
	std::size_t cols_row;
	std::size_t rows_1_col;
	std::size_t cols_1_row;
	std::size_t col_odd_even;
	std::size_t row_odd_even;
	bool is_swapped;
	T* now;
	T* next;
	bool is_odd;
	std::size_t rows = static_cast<std::size_t>(sqrt(size));//正方形のデータとして扱うための行数算出
	std::size_t over = size % rows;//余り算出
	if (over > 0 && (rows & 0x1) == 0x1)//余りが出た場合、（余りを除く）行数が偶数になるように調整
	{
		--rows;
		over = size % rows;
	}
	const std::size_t cols = size / rows;//1行当たりの列数算出
	auto log2 = [](std::size_t val) -> std::size_t
	{
		std::size_t result = 0;
		while (val >>= 1)
			++result;
		return result;
	};
	const int sorting_count = log2(rows) + 1;//ソート実行回数を算出
	for (int i = 0; i < sorting_count; ++i)
	{
		//各行ごとに、列方向にソート
		//※偶数行は小さい順、奇数行は大きい順にソート
#if defined(SHEAR_SORT_USE_OPENMP_NEST)
	#pragma omp parallel for reduction(+:swapped_count) private(cols_row, cols_1_row, is_swapped, col_odd_even, is_odd)
#elif defined(SHEAR_SORT_USE_OPENMP)
	#pragma omp parallel for reduction(+:swapped_count) private(cols_row, cols_1_row, is_swapped, col_odd_even, is_odd, col, now, next)
#endif//SHEAR_SORT_USE_OPENMP
		for (row = 0; row <= static_cast<int>(rows); ++row)
		{
			cols_row = row == static_cast<int>(rows) ? over : cols;
			if (cols_row > 1)
			{
				is_odd = ((row & 0x1) == 0x1);
				//奇遇転置ソート
				cols_1_row = cols_row - 1;
				is_swapped = true;
				while (is_swapped)
				{
					is_swapped = false;
					for (col_odd_even = 0; col_odd_even < 2; ++col_odd_even)
					{
				#ifdef SHEAR_SORT_USE_OPENMP_NEST
					#pragma omp parallel for reduction(+:swapped_count) reduction(||:is_swapped) private(now, next)
				#endif//SHEAR_SORT_USE_OPENMP_NEST
						for (col = col_odd_even; col < static_cast<int>(cols_1_row); col += 2)
						{
							now = array + row * cols + col;
							next = now + 1;
							if ((!is_odd && predicate(*next, *now)) ||//偶数行は小さい順
								( is_odd && predicate(*now, *next)))  //奇数行は大きい順
							{
								swapValues(*next, *now);
								is_swapped = true;
								++swapped_count;
							}
						}
					}
				}
			}
		}
		//各列ごとに、行方向にソート
		//※小さい順にソート
#if defined(SHEAR_SORT_USE_OPENMP_NEST)
	#pragma omp parallel for reduction(+:swapped_count) private(rows_col, rows_1_col, row_odd_even, is_swapped)
#elif defined(SHEAR_SORT_USE_OPENMP)
	#pragma omp parallel for reduction(+:swapped_count) private(rows_col, rows_1_col, row_odd_even, is_swapped, row, now, next)
#endif//SHEAR_SORT_USE_OPENMP
		for (col = 0; col < static_cast<int>(cols); ++col)
		{
			rows_col = rows + (col < static_cast<int>(over) ? 1 : 0);
			//奇遇転置ソート
			rows_1_col = rows_col - 1;
			is_swapped = true;
			while (is_swapped)
			{
				is_swapped = false;
				for (row_odd_even = 0; row_odd_even < 2; ++row_odd_even)
				{
			#ifdef SHEAR_SORT_USE_OPENMP_NEST
				#pragma omp parallel for reduction(+:swapped_count) reduction(||:is_swapped) private(now, next)
			#endif//SHEAR_SORT_USE_OPENMP_NEST
					for (row = row_odd_even; row < static_cast<int>(rows_1_col); row += 2)
					{
						now = array + row * cols + col;
						next = now + cols;
						if (predicate(*next, *now))
						{
							swapValues(*next, *now);
							is_swapped = true;
							++swapped_count;
						}
					}
				}
			}
		}
	}
	{
		//各行ごとに、列方向にソート
		//※小さい順にソート
#if defined(SHEAR_SORT_USE_OPENMP_NEST)
	#pragma omp parallel for reduction(+:swapped_count) private(cols_row, cols_1_row, col_odd_even, is_swapped)
#elif defined(SHEAR_SORT_USE_OPENMP)
	#pragma omp parallel for reduction(+:swapped_count) private(cols_row, cols_1_row, col_odd_even, is_swapped, col, now, next)
#endif//SHEAR_SORT_USE_OPENMP
		for (row = 0; row <= static_cast<int>(rows); ++row)
		{
			cols_row = row == static_cast<int>(rows) ? over : cols;
			if (cols_row > 1)
			{
				//奇遇転置ソート
				cols_1_row = cols_row - 1;
				is_swapped = true;
				while (is_swapped)
				{
					is_swapped = false;
					for (col_odd_even = 0; col_odd_even < 2; ++col_odd_even)
					{
					#ifdef SHEAR_SORT_USE_OPENMP_NEST
						#pragma omp parallel for reduction(+:swapped_count) reduction(||:is_swapped) private(now, next)
					#endif//SHEAR_SORT_USE_OPENMP_NEST
						for (col = col_odd_even; col < static_cast<int>(cols_1_row); col += 2)
						{
							now = array + row * cols + col;
							next = now + 1;
							if (predicate(*next, *now))
							{
								swapValues(*next, *now);
								is_swapped = true;
								++swapped_count;
							}
						}
					}
				}
			}
		}
	}
#ifdef SHEAR_SORT_USE_OPENMP_NEST
	omp_set_nested(omp_nested_before);
#endif//SHEAR_SORT_USE_OPENMP_NEST
	return swapped_count;
}
sortFuncSet(shearSort);

//----------------------------------------
//アルゴリズム：コムソート
//----------------------------------------
//・最良計算時間：O(n)
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　×
//----------------------------------------
template<class T, class PREDICATE>
std::size_t combSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	std::size_t h = size;
	const T* end = array + size;
	while (true)
	{
		h = h == 1 ? 1 : h * 10 / 13;
		bool is_swapped = false;
		T* now = array;
		T* next = now + h;
		while (next < end)
		{
			if (predicate(*next, *now))
			{
				swapValues(*next, *now);
				is_swapped = true;
				++swapped_count;
			}
			++now;
			++next;
		}
		if (h == 1 && !is_swapped)
			break;
	}
	return swapped_count;
}
sortFuncSet(combSort);

//----------------------------------------
//アルゴリズム：ノームソート
//----------------------------------------
//・最良計算時間：O(n)
//・平均計算時間：O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
template<class T, class PREDICATE>
std::size_t gnomeSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	const T* end = array + size;
	T* now = array;
	T* next = now + 1;
	while (next < end)
	{
		if (predicate(*next, *now))
		{
			T* prev = now;
			now = next;
			while (prev >= array)
			{
				if (predicate(*now, *prev))
				{
					swapValues(*now, *prev);
					++swapped_count;
				}
				else
					break;
				--prev;
				--now;
			}
		}
		now = next;
		++next;
	}
	return swapped_count;
}
sortFuncSet(gnomeSort);

//========================================
//ソートアルゴリズム分類：分割交換ソート
//========================================

//----------------------------------------
//アルゴリズム：クイックソート
//----------------------------------------
//・最良計算時間：O(n log n)
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(log n)〜O(n) ※ループ処理版は O(32*2)
//・安定性：　　　×
//----------------------------------------
//※再帰処理を使用せず、スタックを使用したループ処理にして最適化する。
//　（最大件数を log2(4294967296) = 32 とする）
//----------------------------------------
template<class T, class PREDICATE>
std::size_t _quickSort(T* array, const std::size_t size, PREDICATE predicate)
{
#ifndef QUICK_SORT_NO_USE_RECURSIVE_CALL
	//--------------------
	//再帰処理版
	if (size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	//配列の範囲情報
	const T* term = array + size;
	T* begin = array;
	T* end = array + size - 1;
	//軸を決定
	const T* mid = array + (size >> 1);
	const T* pivot =
		predicate(*begin, *mid) ?
			predicate(*mid, *end) ?
				mid :
				predicate(*end, *begin) ?
					begin :
					end :
			predicate(*end, *mid) ?
				mid :
				predicate(*begin, *end) ?
					begin :
					end;
	//軸未満の配列と軸以上の配列に二分
	while (true)
	{
		while (predicate(*begin, *pivot))
			++begin;
		while (predicate(*pivot, *end))
			--end;
		if (begin >= end)
			break;
		swapValues(*begin, *end);
		pivot = pivot == begin ? end : pivot == end ? begin : pivot;//軸の位置調整（軸の位置も入れ替わるため）
		++swapped_count;
		++begin;
		--end;
	}
	//再帰処理
	swapped_count += _quickSort(array, begin - array, predicate);//軸未満の配列
	swapped_count += _quickSort(end + 1, term - end - 1, predicate);//軸以上の配列
	return swapped_count;
#else//QUICK_SORT_NO_USE_RECURSIVE_CALL
#ifndef QUICK_SORT_USE_OPENMP
	//--------------------
	//スタック処理版
	std::size_t swapped_count = 0;
	struct stack_t
	{
		T* array;
		std::size_t size;
	};
	static const int STACK_DEPTH_MAX = 32 * 2;
	stack_t stack[STACK_DEPTH_MAX];
	//最初の配列をスタックにプッシュ
	stack_t* stack_p = &stack[0];
	stack_p->array = array;
	stack_p->size = size;
	int stack_curr = 1;//スタック位置
	while (stack_curr > 0)
	{
		//配列をスタックから取得
		stack_p = &stack[--stack_curr];
		T* _array = stack_p->array;
		const size_t _size = stack_p->size;
		//配列の範囲情報
		const T* term = _array + _size;
		T* begin = _array;
		T* end = _array + _size - 1;
		//軸を決定
		const T* mid = _array + (_size >> 1);
		const T* pivot =
			predicate(*begin, *mid) ?
				predicate(*mid, *end) ?
					mid :
					predicate(*end, *begin) ?
						begin :
						end :
				predicate(*end, *mid) ?
					mid :
					predicate(*begin, *end) ?
						begin :
						end;
		//軸未満の配列と軸以上の配列に二分
		while (true)
		{
			while (predicate(*begin, *pivot))
				++begin;
			while (predicate(*pivot, *end))
				--end;
			if (begin >= end)
				break;
			swapValues(*begin, *end);
			pivot = pivot == begin ? end : pivot == end ? begin : pivot;//軸の位置調整（軸の位置も入れ替わるため）
			++swapped_count;
			++begin;
			--end;
		}
		//recursive = 0 : 軸未満の配列をプッシュ
		//            1 : 軸以上の配列をプッシュ
		for (int recursive = 0; recursive < 2; ++recursive)
		{
			T* new_array = recursive == 0 ? _array : end + 1;
			const std::size_t new_size = recursive == 0 ? begin - _array : term - end - 1;
			if (new_size >= 1)
			{
				stack_p = &stack[stack_curr++];
				assert(stack_curr <= STACK_DEPTH_MAX);
				stack_p->array = new_array;
				stack_p->size = new_size;
			}
		}
	}
	return swapped_count;
#else//QUICK_SORT_USE_OPENMP
	//--------------------
	//OpenMP＆キュー処理版
	//※並列化のためにスタックではなくキューを使用。
	//　そのため、全件分のキュー（メモリ）が必要。
	//　パフォーマンスも今ひとつ。
	std::size_t swapped_count = 0;
	struct queue_t
	{
		T* array;
		std::size_t size;
	};
	queue_t* queue = new queue_t[size];
	//最初の配列をキューにプッシュ
	queue_t* queue_p = &queue[0];
	queue_p->array = array;
	queue_p->size = size;
	unsigned int queue_write = 1;//キュー書き込み位置
	unsigned int queue_read = 0;//キュー読み込み位置
	unsigned int queue_read_tmp;
	unsigned int queue_write_tmp;
	T* _array;
	size_t _size;
	const T* term;
	T* begin;
	T* end;
	const T* mid;
	const T* pivot;
	int recursive;
	T* new_array;
	std::size_t new_size;
	while (queue_read != queue_write)
	{
		queue_read_tmp = queue_read;
		queue_write_tmp = queue_write;
		const int loop_count = queue_write_tmp > queue_read_tmp ? queue_write_tmp - queue_read_tmp : size - queue_write_tmp + queue_read_tmp;
	#pragma omp parallel for reduction(+:swapped_count) private(queue_p, _array, _size, term, begin, end, mid, pivot, recursive, new_array, new_size, queue_read_tmp, queue_write_tmp)
		for (int loop = 0; loop < loop_count; ++loop)
		{
		#pragma omp critical
			{ queue_read_tmp = queue_read++; }
			//if (true)
			{
				//配列をキューから取得
				queue_p = &queue[queue_read_tmp % size];
				_array = queue_p->array;
				_size = queue_p->size;
				//配列の範囲情報
				term = _array + _size;
				begin = _array;
				end = _array + _size - 1;
				//軸を決定
				mid = _array + (_size >> 1);
				pivot =
					predicate(*begin, *mid) ?
						predicate(*mid, *end) ?
							mid :
							predicate(*end, *begin) ?
								begin :
								end :
						predicate(*end, *mid) ?
							mid :
							predicate(*begin, *end) ?
								begin :
								end;
				//軸未満の配列と軸以上の配列に二分
				while (true)
				{
					while (predicate(*begin, *pivot))
						++begin;
					while (predicate(*pivot, *end))
						--end;
					if (begin >= end)
						break;
					swapValues(*begin, *end);
					pivot = pivot == begin ? end : pivot == end ? begin : pivot;//軸の位置調整（軸の位置も入れ替わるため）
					++swapped_count;
					++begin;
					--end;
				}
				//recursive = 0 : 軸未満の配列をプッシュ
				//            1 : 軸以上の配列をプッシュ
				for (recursive = 0; recursive < 2; ++recursive)
				{
					new_array = recursive == 0 ? _array : end + 1;
					new_size = recursive == 0 ? begin - _array : term - end - 1;
					if (new_size >= 1)
					{
					#pragma omp critical
						{ queue_write_tmp = queue_write++; }
						assert(queue_write_tmp >= queue_read ? queue_write_tmp - queue_read < size : size - queue_write_tmp + queue_read < size);
						queue_p = &queue[queue_write_tmp % size];
						queue_p->array = new_array;
						queue_p->size = new_size;
					}
				}
			}
		}
	}
	delete[] queue;
	return swapped_count;
#endif//QUICK_SORT_USE_OPENMP
#endif//QUICK_SORT_NO_USE_RECURSIVE_CALL
}
template<class T, class PREDICATE>
inline std::size_t quickSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	return _quickSort(array, size, predicate);
}
sortFuncSet(quickSort);

//========================================
//ソートアルゴリズム分類：選択ソート
//========================================

//----------------------------------------
//アルゴリズム：選択ソート
//----------------------------------------
//・最良計算時間：O(n^2)
//・平均計算時間：O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　×
//----------------------------------------
template<class T, class PREDICATE>
std::size_t selectionSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	T* now = array;
	const std::size_t size_1 = size - 1;
	for (std::size_t i = 0; i < size_1; ++i, ++now)
	{
		T* min = now;
		T* check = now;
		for (std::size_t ii = i + 1; ii < size; ++ii)
		{
			++check;
			if (predicate(*check, *min))
				min = check;
		}
		if (now != min)
		{
			swapValues(*min, *now);
			++swapped_count;
		}
	}
	return swapped_count;
}
sortFuncSet(selectionSort);

//----------------------------------------
//アルゴリズム：ヒープソート
//----------------------------------------
//・最良計算時間：O(n log n)
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n log n)
//・メモリ使用量：O(1)
//・安定性：　　　×
//----------------------------------------
template<class T, class PREDICATE>
std::size_t heapSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	//二分ヒープ登録
	for (std::size_t heap_size = 1; heap_size < size; ++heap_size)
	{
		T* now = array + heap_size;
		//アップヒープ
		std::size_t parent_i = heap_size;
		while (parent_i > 0)
		{
			parent_i = (parent_i - 1) >> 1;
			T* parent = array + parent_i;
			if (predicate(*parent, *now))
			{
				swapValues(*parent, *now);
				++swapped_count;
			}
			else
				break;
			now = parent;
		}
	}
	//二分ヒープ取り出し
	for (std::size_t heap_size = size - 1; heap_size > 0; --heap_size)
	{
		T* now = array + heap_size;
		//ダウンヒープ
		{
			swapValues(*array, *now);
			++swapped_count;
		}
		now = array;
		std::size_t child_i = 0;
		while (true)
		{
			child_i = (child_i << 1) + 1;
			if (child_i >= heap_size)
				break;
			T* child = array + child_i;
			T* child_r = child_i + 1 < heap_size ? child + 1 : nullptr;
			if (child_r && predicate(*child, *child_r))
			{
				child = child_r;
				++child_i;
			}
			if(predicate(*now, *child))
			{
				swapValues(*now, *child);
				++swapped_count;
			}
			else
				break;
			now = child;
		}
	}
	return swapped_count;
}
sortFuncSet(heapSort);

//========================================
//ソートアルゴリズム分類：挿入ソート
//========================================

//----------------------------------------
//アルゴリズム：挿入ソート
//----------------------------------------
//・最良計算時間：O(n)
//・平均計算時間：O(n^2)
//・最悪計算時間：O(n^2)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
template<class T, class PREDICATE>
std::size_t insertionSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	const T* end = array + size;
	T* now = array;
	T* next = now + 1;
	while (next < end)
	{
		if (predicate(*next, *now))
		{
			T* min = now;
			T* prev = now - 1;
			while (prev >= array)
			{
				if (predicate(*next, *prev))
					min = prev;
				else
					break;
				--prev;
			}
			rotateValues(min, next, 1);
			++swapped_count;
		}
		++now;
		++next;
	}
	return swapped_count;
}
sortFuncSet(insertionSort);

//----------------------------------------
//アルゴリズム：シェルソート
//----------------------------------------
//・最良計算時間：O(n)
//・平均計算時間：O(n log^2 n) or O(n^3/2)
//・最悪計算時間：O(n log^2 n)
//・メモリ使用量：O(1)
//・安定性：　　　×
//----------------------------------------
template<class T, class PREDICATE>
std::size_t shellSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	const T* end = array + size;
	const std::size_t h_max = size / 3;
	std::size_t h = 1;
	while (h <= h_max)
		h = 3 * h + 1;
	while (h > 0)
	{
		T* now = array;
		T* next = now + h;
		while (next < end)
		{
			if (predicate(*next, *now))
			{
				T* min = now;
				T* prev = now - h;
				while (prev >= array)
				{
					if (predicate(*next, *prev))
						min = prev;
					else
						break;
					prev -= h;
				}
				rotateValues(min, next, h);
				++swapped_count;
			}
			++now;
			++next;
		}
		h = (h - 1) / 3;
	}
	return swapped_count;
}
sortFuncSet(shellSort);

//----------------------------------------
//アルゴリズム：インプレースマージソート
//----------------------------------------
//・最良計算時間：O(n log2 n)
//・平均計算時間：O(n log2 n)
//・最悪計算時間：O(n log2 n)
//・メモリ使用量：O(1)
//・安定性：　　　○
//----------------------------------------
//※OpenMPを使用し、並列化が可能。
//----------------------------------------
template<class T, class PREDICATE>
std::size_t inplaceMergeSort(T* array, const std::size_t size, PREDICATE predicate)
{
#ifndef INPLACE_MERGE_SORT_USE_OPENMP
	//通常版
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	for (std::size_t block_size = 1; block_size < size; block_size <<= 1)
	{
		const std::size_t merge_size = block_size << 1;
		const std::size_t left_block_size = block_size;
		for (std::size_t merge_pos = 0; merge_pos + block_size <= size; merge_pos += merge_size)
		{
			const std::size_t right_block_size = merge_pos + merge_size <= size ? block_size : size % block_size;
			T* left_begin = array + merge_pos;
			T* left_end = left_begin + left_block_size;
			T* right_begin = left_end;
			T* right_end = right_begin + right_block_size;
			T* left = left_end - 1;
			T* right = right_begin;
			T* left_ins_prev = nullptr;
			while (right < right_end)
			{
				if (predicate(*right, *left))//左ブロックの右端と右ブロックの左端をチェック
				{
				#if 0
					//挿入位置検索 ※線形検索
					T* left_ins = left;
					while (left_ins >= left_begin && predicate(*right, *left_ins))
						--left_ins;
					++left_ins;
				#else
					//挿入位置検索 ※二分検索
					T* left_ins;
					{
						T* search_begin = left_ins_prev ? left_ins_prev + 1 : left_begin;
						std::size_t search_range_half = (right - search_begin) >> 1;
						std::size_t search_pos = search_range_half;
						left_ins = search_begin + search_pos;
						while (search_range_half > 1)
						{
							search_range_half = search_range_half >> 1;
							left_ins = search_begin + search_pos;
							if (predicate(*right, *left_ins))
								search_pos -= search_range_half;
							else
								search_pos += search_range_half;
						}
						while (left_ins < right && !predicate(*right, *left_ins))
							++left_ins;
						while (left_ins >= search_begin && predicate(*right, *left_ins))
							--left_ins;
						++left_ins;
						left_ins_prev = left_ins;
					}
				#endif
					//挿入
					rotateValues(left_ins, right, 1);
					++swapped_count;
					++left;
					++right;
				}
				else
					break;
			}
		}
	}
	return swapped_count;
#else//INPLACE_MERGE_SORT_USE_OPENMP
	//OpenMP版
	if (!array || size <= 1)
		return 0;
	std::size_t swapped_count = 0;
	std::size_t merge_pos;
	std::size_t right_block_size;
	T* left_begin;
	T* left_end;
	T* left;
	T* left_ins_prev;
	T* left_ins;
	T* right_begin;
	T* right_end;
	T* right;
	T* search_begin;
	std::size_t search_range_half;
	std::size_t search_pos;
	for (std::size_t block_size = 1; block_size < size; block_size <<= 1)
	{
		const std::size_t merge_size = block_size << 1;
		const std::size_t left_block_size = block_size;
		const int loop_count = static_cast<int>((size / merge_size) + (size % merge_size > block_size));
	#pragma omp parallel for reduction(+:swapped_count) private(merge_pos, right_block_size, left_begin, left_end, left, left_ins_prev, left_ins, right_begin, right_end, right, search_begin, search_range_half, search_pos)
		for (int i = 0; i< loop_count; ++i)
		{
			merge_pos = i * merge_size;
			right_block_size = merge_pos + merge_size <= size ? block_size : size % block_size;
			left_begin = array + merge_pos;
			left_end = left_begin + left_block_size;
			right_begin = left_end;
			right_end = right_begin + right_block_size;
			left = left_end - 1;
			right = right_begin;
			left_ins_prev = nullptr;
			while (right < right_end)
			{
				if (predicate(*right, *left))//左ブロックの右端と右ブロックの左端をチェック
				{
				#if 0
					//挿入位置検索 ※線形検索
					left_ins = left;
					while (left_ins >= left_begin && predicate(*right, *left_ins))
						--left_ins;
					++left_ins;
				#else
					//挿入位置検索 ※二分検索
					{
						search_begin = left_ins_prev ? left_ins_prev + 1 : left_begin;
						search_range_half = (right - search_begin) >> 1;
						search_pos = search_range_half;
						left_ins = search_begin + search_pos;
						while (search_range_half > 1)
						{
							search_range_half = search_range_half >> 1;
							left_ins = search_begin + search_pos;
							if (predicate(*right, *left_ins))
								search_pos -= search_range_half;
							else
								search_pos += search_range_half;
						}
						while (left_ins < right && !predicate(*right, *left_ins))
							++left_ins;
						while (left_ins >= search_begin && predicate(*right, *left_ins))
							--left_ins;
						++left_ins;
						left_ins_prev = left_ins;
					}
				#endif
					//挿入
					rotateValues(left_ins, right, 1);
					++swapped_count;
					++left;
					++right;
				}
				else
					break;
			}
		}
	}
	return swapped_count;
#endif//INPLACE_MERGE_SORT_USE_OPENMP
}
sortFuncSet(inplaceMergeSort);

//========================================
//ソートアルゴリズム分類：混成ソート
//========================================

//----------------------------------------
//アルゴリズム：イントロソート
//----------------------------------------
//・最良計算時間：O(n log n)
//・平均計算時間：O(n log n)
//・最悪計算時間：O(n log n)
//・メモリ使用量：O(n log n) ※ループ処理版は O(32*2)
//・安定性：　　　×
//----------------------------------------
//※クイックソートの再帰レベルが log n に達したら、
//　ヒープソートに切り替える。
//　また、再起の末、ソートの対象件数が一定数（32など）未満に
//　なったら、挿入ソートに切り替える。
//※STLのstd::sort()と同様の手法。
//----------------------------------------
//※再帰処理を使用せず、ループ処理にして最適化する。
//　（最大件数を log2(4294967296) = 32 とする）
//※挿入ソート切り替えタイミングを16に設定する。
//　（VC++2013のSTL std::sortでは32）
//※（再帰の末）対象件数が一定以下になったときに切り替えるアルゴリズムは、
//　本来の挿入ソートではなく、シェルソートを使用するスタイルに改良。
//※再帰が一定以上深くなったときに切り替えるアルゴリズムは、
//　本来のヒープソートではなく、シェルソートを使用するスタイルに改良。
//※整列済み判定を最初に一度行うことで最適化する。
//----------------------------------------
template<class T, class PREDICATE>
std::size_t _introSort(T* array, const std::size_t size, PREDICATE predicate)
{
	int depth_max = 0;//ヒープソートに切り替える再帰（スタック）の深さ
	for (std::size_t size_tmp = size; size_tmp > 1; size_tmp >>= 1, ++depth_max);
	//--------------------
	//クイックソート：スタック処理版
	//※再帰処理版は省略
	static const std::size_t SIZE_THRESHOLD = 16;//32;//挿入ソートに切り替える件数
	std::size_t swapped_count = 0;
	struct stack_t
	{
		T* array;
		std::size_t size;
		int depth;
	};
	static const int STACK_DEPTH_MAX = 32 * 2;
	stack_t stack[STACK_DEPTH_MAX];
	//最初の配列をスタックにプッシュ
	stack_t* stack_p = &stack[0];
	stack_p->array = array;
	stack_p->size = size;
	stack_p->depth = depth_max;
	int stack_curr = 1;//スタック位置
	while (stack_curr > 0)
	{
		//配列をスタックから取得
		stack_p = &stack[--stack_curr];
		T* _array = stack_p->array;
		const size_t _size = stack_p->size;
		const int _depth = stack_p->depth;
		//配列の範囲情報
		const T* term = _array + _size;
		T* begin = _array;
		T* end = _array + _size - 1;
		//軸を決定
		const T* mid = _array + (_size >> 1);
		const T* pivot =
			predicate(*begin, *mid) ?
				predicate(*mid, *end) ?
					mid :
					predicate(*end, *begin) ?
						begin :
						end :
				predicate(*end, *mid) ?
					mid :
					predicate(*begin, *end) ?
						begin :
						end;
		//軸未満の配列と軸以上の配列に二分
		while (true)
		{
			while (predicate(*begin, *pivot))
				++begin;
			while (predicate(*pivot, *end))
				--end;
			if (begin >= end)
				break;
			swapValues(*begin, *end);
			pivot = pivot == begin ? end : pivot == end ? begin : pivot;//軸の位置調整（軸の位置も入れ替わるため）
			++swapped_count;
			++begin;
			--end;
		}
		//recursive = 0 : 軸未満の配列をプッシュ
		//            1 : 軸以上の配列をプッシュ
		for (int recursive = 0; recursive < 2; ++recursive)
		{
			T* new_array = recursive == 0 ? _array : end + 1;
			const std::size_t new_size = recursive == 0 ? begin - _array : term - end - 1;
			const int new_depth = _depth - 1;
			if (new_size >= 1)
			{
				if (new_size < SIZE_THRESHOLD)
				{
					//swapped_count += insertionSort(new_array, new_size, predicate);//【本来の処理】挿入ソートに切り替え
					//swapped_count += combSort(new_array, new_size, predicate);//【改良】コムソートに切り替え
					swapped_count += shellSort(new_array, new_size, predicate);//【改良】シェルソートに切り替え
				}
				else if (new_depth == 0)
				{
					//swapped_count += heapSort(new_array, new_size, predicate);//【本来の処理】ヒープソートに切り替え
					//swapped_count += combSort(new_array, new_size, predicate);//【改良】コムソートに切り替え
					swapped_count += shellSort(new_array, new_size, predicate);//【改良】シェルソートに切り替え
				}
				else
				{
					//再帰
					stack_p = &stack[stack_curr++];
					stack_p->array = new_array;
					stack_p->size = new_size;
					stack_p->depth = new_depth;
				}
			}
		}
	}
	return swapped_count;
}
template<class T, class PREDICATE>
inline std::size_t introSort(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size <= 1)
		return 0;
	if (calcUnordered(array, size, predicate) == 0)
		return 0;
	return _introSort(array, size, predicate);
}
sortFuncSet(introSort);

//========================================
//ソートアルゴリズム分類：分布ソート
//========================================

//----------------------------------------
//アルゴリズム：基数ソート
//----------------------------------------
//・最良計算時間：O(n*k/d) ※k=キーの範囲、d=基数(256)
//・平均計算時間：O(n*k/d)
//・最悪計算時間：O(n*k/d)
//・メモリ使用量：O(n) ※実際は O(n * 2) のキー情報(12 bytes) + O(256 * 256) のキー分布情報(4 bytes) + O(1〜8) のスタック情報（4 bytes）
//・安定性：　　　○
//----------------------------------------
#include <climits>//***_MAX用
#include <type_traits>//C++11 std:is_same, std::is_signed, std::make_unsigned, std::conditional, std::integral_constant用
#include <memory.h>//_aligned_malloc(), _aligned_free()用
//キーの最大値取得
template<typename KEY_TYPE>
struct _radix_key{
	typedef
		typename std::conditional <
			std::is_same<KEY_TYPE, unsigned char>::value,
			std::integral_constant<unsigned char, UCHAR_MAX>,
			typename std::conditional <
				std::is_same<KEY_TYPE, signed char>::value,
				std::integral_constant<signed char, SCHAR_MAX>,
				typename std::conditional <
					std::is_same<KEY_TYPE, unsigned short>::value,
					std::integral_constant<unsigned short, USHRT_MAX>,
					typename std::conditional <
						std::is_same<KEY_TYPE, signed short>::value,
						std::integral_constant<signed short, SHRT_MAX>,
						typename std::conditional <
							std::is_same<KEY_TYPE, unsigned int>::value,
							std::integral_constant<unsigned int, UINT_MAX>,
							typename std::conditional <
								std::is_same<KEY_TYPE, signed int>::value,
								std::integral_constant<signed int, INT_MAX>,
								typename std::conditional <
									std::is_same<KEY_TYPE, unsigned long>::value,
									std::integral_constant<unsigned long, ULONG_MAX>,
									typename std::conditional <
										std::is_same<KEY_TYPE, signed long>::value,
										std::integral_constant<signed long, LONG_MAX>,
										typename std::conditional <
											std::is_same<KEY_TYPE, unsigned long long>::value,
											std::integral_constant<unsigned long long, ULLONG_MAX>,
											typename std::conditional <
												std::is_same<KEY_TYPE, signed long long>::value,
												std::integral_constant<signed long long, LLONG_MAX>,
												std::integral_constant<std::size_t, UINT_MAX>
											>::type
										>::type
									>::type
								>::type
							>::type
						>::type
					>::type
				>::type
			>::type
		>::type
			max_t;
	static const KEY_TYPE MAX = max_t::value;
};
//キーを取得　※キーが符号付型の場合
template<class T, class GET_KEY_FUNCTOR>
struct _radix_key_s{
	typedef typename GET_KEY_FUNCTOR::key_type KEY_TYPE;
	typedef typename std::make_unsigned<KEY_TYPE>::type KEY_TYPE_U;
	inline static KEY_TYPE_U getKey(const T& obj, GET_KEY_FUNCTOR get_key_functor)
	{
		KEY_TYPE key = get_key_functor(obj);
		return key >= 0 ?
					static_cast<KEY_TYPE_U>(key) + _radix_key<KEY_TYPE>::MAX + 1:
					static_cast<KEY_TYPE_U>(key  + _radix_key<KEY_TYPE>::MAX + 1);
	}
};
//キーを取得　※キーが符号なし型の場合
template<class T, class GET_KEY_FUNCTOR>
struct _radix_key_u{
	typedef typename GET_KEY_FUNCTOR::key_type KEY_TYPE;
	typedef KEY_TYPE KEY_TYPE_U;
	inline static KEY_TYPE_U getKey(const T& obj, GET_KEY_FUNCTOR get_key_functor)
	{
		return get_key_functor(obj);
	}
};
//キーを取得
template<class T, class GET_KEY_FUNCTOR>
struct radix_key{
	typedef typename GET_KEY_FUNCTOR::key_type KEY_TYPE;
	typedef typename std::make_unsigned<KEY_TYPE>::type KEY_TYPE_U;
	typedef
		typename std::conditional<
			std::is_signed<KEY_TYPE>::value,
			_radix_key_s<T, GET_KEY_FUNCTOR>,
			_radix_key_u<T, GET_KEY_FUNCTOR>
		>::type
			get_key_t;
	inline static KEY_TYPE_U getKey(const T& obj, GET_KEY_FUNCTOR get_key_functor){ return get_key_t::getKey(obj, get_key_functor); }
};
//基数ソート本体
template<class T, class GET_KEY_FUNCTOR>
inline std::size_t radixSort(T* array, const std::size_t size, GET_KEY_FUNCTOR get_key_functor)
{
	if (!array || size <= 1)
		return 0;

#if 0//再帰処理版
	std::size_t swapped_count = 0;

	typedef typename GET_KEY_FUNCTOR::key_type KEY_TYPE;//キー型
	typedef typename std::make_unsigned<KEY_TYPE>::type KEY_TYPE_U;//符号なしキー型

	static const std::size_t RADIX = 256;//基数

	//キー情報定義
	struct key_t
	{
		mutable const key_t* next;//次のキー情報
		const T* ref;//実データの参照
		KEY_TYPE_U key;//キー
		inline KEY_TYPE_U set(const T* _ref, const KEY_TYPE_U _key)//値のセット
		{
			next = nullptr;
			ref = _ref;
			key = _key;
			return key;
		}
	};
	//キー情報生成
	KEY_TYPE_U key_max = 0;//キーの最大値
	key_t* key_tbl = new key_t[size];//※newでメモリ確保
	{
		T* elem_p = array;
		key_t* key_p = key_tbl;
		for (std::size_t index = 0; index < size; ++index, ++elem_p, ++key_p)
			key_max = std::max(key_max, key_p->set(elem_p, radix_key<T, GET_KEY_FUNCTOR>::getKey(*elem_p, get_key_functor)));
	}
	//キーの最大値から最大の長さを算出
	std::size_t key_len =
		(key_max & 0xff00000000000000llu) != 0 ? 8 :
		(key_max & 0x00ff000000000000llu) != 0 ? 7 :
		(key_max & 0x0000ff0000000000llu) != 0 ? 6 :
		(key_max & 0x000000ff00000000llu) != 0 ? 5 :
		(key_max & 0xff000000) != 0 ? 4 :
		(key_max & 0x00ff0000) != 0 ? 3 :
		(key_max & 0xff00) != 0 ? 2 :
		(key_max & 0xff) != 0 ? 1 :
		0;
	if (key_len == 0)//キーが 0 しかなければこの時点で終了
	{
		delete key_tbl;//メモリ破棄
		return 0;
	}
	
	//ソート用関数オブジェクト
	struct sort_functor
	{
		//分布情報
		struct bucket_t
		{
			const key_t* keys;//キー情報の連結リスト
			std::size_t count;//キー情報数
			inline void add(const key_t* key_p)//キー追加（連結）
			{
				key_p->next = keys;
				keys = key_p;
				++count;
			}
		};
		//カウントテーブル型
		typedef bucket_t bucket_tbl_t[RADIX];
		//インデックス計算
		inline static unsigned char calcDigit(const KEY_TYPE_U key, const std::size_t key_len)
		{
			return (key >> (key_len << 3)) & 0xff;
		}
		//ソート内部処理用関数オブジェクト
		//※次の基数別にキーを集める／ソート済み配列にデータをコピー
		struct inner_functor
		{
			void operator()(T* sorted_array, std::size_t& array_index, const key_t* key_list, const std::size_t key_list_count, std::size_t key_len, const bool is_odd)
			{
				//キーがなければ、ソート済み配列にデータをコピー
				if (key_len == 0)
				{
					if (is_odd)//奇数回目の実行の場合
					{
						T* sorted_p = sorted_array + array_index + key_list_count;
						const key_t* key_p = key_list;
						while (key_p)
						{
							*(--sorted_p) = std::move(*key_p->ref);
							++array_index;
							key_p = key_p->next;
						}
					}
					else//if(!is_odd)//偶数回目の実行の場合
					{
						T* sorted_p = sorted_array + array_index;
						const key_t* key_p = key_list;
						while (key_p)
						{
							*(sorted_p++) = std::move(*key_p->ref);
							++array_index;
							key_p = key_p->next;
						}
					}
					return;//終了
				}
				//次の基数別にキーを集める
				--key_len;
				bucket_tbl_t child_tbl;
				memset(child_tbl, 0, sizeof(child_tbl));
				const key_t* key_p = key_list;
				while (key_p)
				{
					const key_t* next_p = key_p->next;
					child_tbl[calcDigit(key_p->key, key_len)].add(key_p);
					key_p = next_p;
				}
				//さらに次の基数別にキーを集める
				for (auto& child : child_tbl)
				{
					if (child.keys)
						inner_functor()(sorted_array, array_index, child.keys, child.count, key_len, !is_odd);
				}
			}
		};
		//ソート初回処理
		//※基数別にキーを集める
		inline void operator()(T* sorted_array, std::size_t& array_index, const key_t* key_tbl, std::size_t size, std::size_t key_len)
		{
			//基数別にキーを集める
			--key_len;
			bucket_tbl_t child_tbl;
			memset(child_tbl, 0, sizeof(child_tbl));
			const key_t* key_p = key_tbl;
			for (std::size_t index = 0; index < size; ++index, ++key_p)
				child_tbl[calcDigit(key_p->key, key_len)].add(key_p);
			//次の基数別にキーを集める／ソート済み配列にデータをコピー
			for (auto& child : child_tbl)
			{
				if (child.keys)
					inner_functor()(sorted_array, array_index, child.keys, child.count, key_len, true);
			}
		}
	};
	//ソート済みデータ配列作成
	T* sorted_array = static_cast<T*>(_aligned_malloc(sizeof(T)* size, alignof(T)));//※_aligned_mallocでメモリ確保
	std::size_t array_index = 0;
	//ソート
	sort_functor()(sorted_array, array_index, key_tbl, size, key_len);
	//ソート済みデータを元の配列にコピー
	{
		const T* src_p = sorted_array;
		T* dst_p = array;
		for (std::size_t index = 0; index < size; ++index, ++src_p, ++dst_p)
			*dst_p = std::move(*src_p);
	}
	delete key_tbl;//メモリ破棄
	_aligned_free(sorted_array);//メモリ破棄
#else//ループ処理版
	std::size_t swapped_count = 0;

	//#define RADIX_IS_16//基数を16にする場合は、このマクロを有効化する（無効化時の基数は256)
	//※基数は、256の方が速いが、16の方が所用メモリ量を抑えられる

	typedef typename GET_KEY_FUNCTOR::key_type KEY_TYPE;//キー型
	typedef typename std::make_unsigned<KEY_TYPE>::type KEY_TYPE_U;//符号なしキー型

	typedef unsigned int size_type;//サイズ型
	typedef unsigned int index_type;//インデックス型

	//キー情報定義
	struct key_t
	{
		mutable const key_t* next;//次のキー情報
		const T* ref;//実データの参照
		KEY_TYPE_U key;//キー

		//初期化
		inline KEY_TYPE_U init(const T* _ref, const KEY_TYPE_U _key)
		{
			next = nullptr;
			ref = _ref;
			key = _key;
			return key;
		}
	};

	//キー情報メモリ確保
	key_t* key_tbl = new key_t[size];
	if (!key_tbl)//メモリ確保に失敗したら終了
		return 0;

	//キー情報生成
	KEY_TYPE_U key_max = 0;//キーの最大値
	{
		T* elem_p = array;
		key_t* key_p = key_tbl;
		for (index_type index = 0; index < size; ++index, ++elem_p, ++key_p)
			key_max = std::max(key_max, key_p->init(elem_p, radix_key<T, GET_KEY_FUNCTOR>::getKey(*elem_p, get_key_functor)));
	}
	//キーの最大値から最大の長さを算出
	const index_type KEY_LEN = (
	#ifndef RADIX_IS_16//基数が256(8bit)の場合の計算
		(key_max & 0xff00000000000000llu) != 0llu ? 8 :
		(key_max & 0x00ff000000000000llu) != 0llu ? 7 :
		(key_max & 0x0000ff0000000000llu) != 0llu ? 6 :
		(key_max & 0x000000ff00000000llu) != 0llu ? 5 :
		(key_max & 0x00000000ff000000u)   != 0u   ? 4 :
		(key_max & 0x0000000000ff0000u)   != 0u   ? 3 :
		(key_max & 0x000000000000ff00u)   != 0u   ? 2 :
		(key_max & 0x00000000000000ffu)   != 0u   ? 1 :
	#else//RADIX_IS_16//基数が16(4bit)の場合の計算
		(key_max & 0xf000000000000000llu) != 0llu ? 16 :
		(key_max & 0x0f00000000000000llu) != 0llu ? 15 :
		(key_max & 0x00f0000000000000llu) != 0llu ? 14 :
		(key_max & 0x000f000000000000llu) != 0llu ? 13 :
		(key_max & 0x0000f00000000000llu) != 0llu ? 12 :
		(key_max & 0x00000f0000000000llu) != 0llu ? 11 :
		(key_max & 0x000000f000000000llu) != 0llu ? 10 :
		(key_max & 0x0000000f00000000llu) != 0llu ?  9 :
		(key_max & 0x00000000f0000000u)   != 0u   ?  8 :
		(key_max & 0x000000000f000000u)   != 0u   ?  7 :
		(key_max & 0x0000000000f00000u)   != 0u   ?  6 :
		(key_max & 0x00000000000f0000u)   != 0u   ?  5 :
		(key_max & 0x000000000000f000u)   != 0u   ?  4 :
		(key_max & 0x0000000000000f00u)   != 0u   ?  3 :
		(key_max & 0x00000000000000f0u)   != 0u   ?  2 :
		(key_max & 0x000000000000000fu)   != 0u   ?  1 :
	#endif//RADIX_IS_16
		0);
	if (KEY_LEN == 0)//キーの桁数が 0 ならこの時点で終了
	{
		delete[] key_tbl;//メモリ破棄
		return 0;
	}

#ifndef RADIX_IS_16//基数が256(8bit)の場合の計算
	static const index_type RADIX = 256;//基数が256(8bit)の場合 ※基数 = 分布数
#else//RADIX_IS_16//基数が16(4bit)の場合の計算
	static const index_type RADIX = 16;//基数が16(4bit)の場合 ※基数 = 分布数
#endif//RADIX_IS_16

	//分布情報型定義
	struct bucket_t
	{
		const key_t* keys;//キー情報の連結リスト

		//キーを追加（連結）
		inline const key_t* add(const key_t* key_p)
		{
			const key_t* next_p = key_p->next;
			key_p->next = keys;
			keys = key_p;
			return next_p;
		}
	};
	//分布情報セット型定義
	struct bucket_set_t
	{
		bucket_t bucket_tbl[RADIX];//分布情報

		//初期化
		inline bucket_t* init()
		{
			memset(this, 0, sizeof(bucket_set_t));
			return bucket_tbl;
		}
		//指定の桁の分布位置計算
		inline static unsigned char calcDigit(const KEY_TYPE_U key, const index_type key_column)
		{
		#ifndef RADIX_IS_16//基数が256(8bit)の場合の計算
			return (key >> (key_column << 3)) & 0xff;//基数が256(8bit)の場合の計算
		#else//RADIX_IS_16//基数が16(4bit)の場合の計算
			return (key >> (key_column << 2)) & 0xf;//基数が16(4bit)の場合の計算
		#endif//RADIX_IS_16
		};
	};
	//スタック型定義
	struct stack_t
	{
		index_type bucket_index;//分布情報のインデックス

		//初期化
		inline void init()
		{
			bucket_index = 0;
		}
	};
	
	//メモリ確保
	const key_t** sorted_key_tbl = new const key_t*[size];//ソート済みキー情報
	bucket_set_t* bucket_tbl_set = new bucket_set_t[KEY_LEN];//分布情報セット
	stack_t* stack = new stack_t[KEY_LEN];//スタック
	if (!sorted_key_tbl || !bucket_tbl_set || !stack)//メモリ確保に失敗したら終了
	{
		if (key_tbl)
			delete[] key_tbl;//メモリ破棄
		if (sorted_key_tbl)
			delete[] sorted_key_tbl;//メモリ破棄
		if (bucket_tbl_set)
			delete[] bucket_tbl_set;//メモリ破棄
		if (stack)
			delete[] stack;//メモリ破棄
		return 0;
	}

	//最初の桁（最上位の桁）の分布を集計
	index_type stack_depth = 1;//スタックの深さ
	{
		const index_type stack_index = stack_depth - 1;//スタックインデックス
		const index_type key_column = KEY_LEN - 1;//処理対象桁
		//最初の桁用の分布情報初期化
		bucket_t* bucket_tbl = bucket_tbl_set[stack_index].init();
		//最初の桁用の分布情報にキーを追加
		const key_t* key_p = key_tbl;
		for (index_type index = 0; index < size; ++index, ++key_p)
			bucket_tbl[bucket_set_t::calcDigit(key_p->key, key_column)].add(key_p);
		//最初の桁用のスタック初期化
		stack[stack_index].init();
	}
	
	//ソート処理メイン
	index_type sorted_key_index = 0;//ソート済みキー情報のインデックス（コピー先の位置）初期化
	while (stack_depth != 0)
	{
		const index_type stack_index = stack_depth - 1;//スタックインデックス

		//スタック取り出し
		stack_t* stack_p = &stack[stack_index];
		const index_type bucket_index = stack_p->bucket_index++;
		if (bucket_index == RADIX)//分布情報の終端に達したら前の桁に戻る
		{
			--stack_depth;
			continue;
		}
		//分布情報取得
		bucket_t* bucket_tbl = bucket_tbl_set[stack_index].bucket_tbl;
		const bucket_t* bucket_p = &bucket_tbl[bucket_index];
		const key_t* keys = bucket_p->keys;
		if (keys)
		{
			//末端（最下位）の桁なら、ソート済み配列にキーをコピー
			if (stack_depth == KEY_LEN)
			{
				const key_t** sorted_key_p = sorted_key_tbl + sorted_key_index;//キーコピーの初期位置
				if ((stack_depth & 0x1) != 0x0)//奇数回目の実行か？　※基数回目ではリンクリストが逆順に連結されている
				{
					//コピー開始位置を移動
					for (const key_t* key_p = keys; key_p; key_p = key_p->next)
						++sorted_key_p;
					//逆順にコピー
					for (const key_t* key_p = keys; key_p; key_p = key_p->next)
					{
						*(--sorted_key_p) = key_p;
						++sorted_key_index;
					}
				}
				else
				{
					//正順にコピー
					for (const key_t* key_p = keys; key_p; key_p = key_p->next)
					{
						*(sorted_key_p++) = key_p;
						++sorted_key_index;
					}
				}
			}
			//次の桁の分布を集計
			else//if(stack_depth < key_len_real)
			{
				//スタックの深さを次に進める
				const index_type next_stack_index = stack_depth;//次のスタックインデックス
				++stack_depth;//スタックの深さ
				const index_type next_key_column = KEY_LEN - stack_depth;//次の処理対象桁
				//分布情報初期化
				bucket_tbl = bucket_tbl_set[next_stack_index].init();
				//次の桁の分布情報にキーを追加 ※キー情報を使いまわすため、リンクリストがつなぎ直される
				for (const key_t* key_p = keys; key_p;)
					key_p = bucket_tbl[bucket_set_t::calcDigit(key_p->key, next_key_column)].add(key_p);
				//次の桁の処理用スタックを初期化
				stack[next_stack_index].init();
			}
		}
	}

	//ソート済みデータを元に配列の入れ替え
	auto copyToArray = [&array, &size, &sorted_key_tbl]() -> std::size_t
	{
		std::size_t swapped_count = 0;
		const key_t** sorted_key_pp = sorted_key_tbl;//ソート済み位置（移動先）のキー情報を参照
		T* dst_p = array;//実際のデータを参照
		for (index_type dst_index = 0; dst_index < size; ++dst_index, ++sorted_key_pp, ++dst_p)
		{
			const key_t** dst_tmp_key_pp = sorted_key_pp;//ソート済み位置（移動先）のキー情報を参照
			const key_t* dst_tmp_key_p = *dst_tmp_key_pp;//ソート済み位置（移動先）のキー情報を取得
			if (!dst_tmp_key_p || dst_tmp_key_p->ref == dst_p)//並び替え済み、もしくは、最初から正しい位置にあるなら処理しない
				continue;
			T* dst_tmp_p = dst_p;//最初の移動先
			T tmp = std::move(*dst_tmp_p);//ソート済み位置の値を退避　※連鎖的な値の移動の最後に使用する値
			while (dst_tmp_key_p)//移動済みのキーを参照したら終了
			{
				const T* src_p = dst_tmp_key_p->ref;//移動元の値を参照 ※ソート前の位置
				if (src_p == dst_p)//退避した値の位置を指したらループ終了
					break;
				*dst_tmp_p = std::move(*src_p);//元の位置からソート済み位置に値をコピー
				++swapped_count;

				//連鎖的な値の移動
				*dst_tmp_key_pp = nullptr;//移動済みにする
				dst_tmp_p = const_cast<T*>(src_p);//移動元の位置を次のループでの移動先にする
				index_type dst_tmp_index = dst_tmp_p - array;//移動先のインデックスを算出
				dst_tmp_key_pp = sorted_key_tbl + dst_tmp_index;//ソート済み位置（移動先）のキー情報を参照
				dst_tmp_key_p = *(dst_tmp_key_pp);//ソート済み位置（移動先）のキー情報を取得
			}
			*dst_tmp_p = std::move(tmp);//ループ前に退避した値を最後の位置にコピー
			*dst_tmp_key_pp = nullptr;//移動済みにする
			++swapped_count;
		}
		return swapped_count;
	};
	swapped_count = copyToArray();
	
	//メモリ破棄
	delete[] key_tbl;//メモリ破棄
	delete[] sorted_key_tbl;//メモリ破棄
	delete[] bucket_tbl_set;//メモリ破棄
	delete[] stack;//メモリ破棄
#endif
	return swapped_count;
}
distributedSortFuncSet(radixSort);

//========================================
//探索アルゴリズム
//========================================

//----------------------------------------
//アルゴリズム：線形探索
//----------------------------------------
//・最良計算時間：O(1)
//・平均計算時間：O(n/2)
//・最悪計算時間：O(n)
//・探索失敗時：  O(n)
//----------------------------------------
template<class T, class PREDICATE>
T* linearSearch(T* array, const std::size_t size, PREDICATE predicate)
{
	if (!array || size == 0)
		return nullptr;
	T* now = array;
	for (std::size_t i = 0; i < size; ++i, ++now)//順次探索
	{
		if (predicate(*now))//探索キーと一致したら終了
			return now;
	}
	return nullptr;//探索失敗
}
searchFuncSetByPredicate(linearSearch);

//----------------------------------------
//アルゴリズム：二分探索
//----------------------------------------
//・最良計算時間：O(1)
//・平均計算時間：O(log n)
//・最悪計算時間：O(log n)
//・探索失敗時：  O(log n)
//----------------------------------------
template<class T, class COMPARISON>
T* binarySearch(T* array, const std::size_t size, COMPARISON comparison)
{
	if (!array || size == 0)
		return nullptr;
	std::size_t range = size;
	T* begin = array;
	T* found = nullptr;
	while (true)
	{
		const std::size_t range_half = range / 2;//探索範囲の半分の範囲
		T* mid = begin + range_half;//探索範囲の中心要素
		const int comp = comparison(*mid);//中心要素を探索キーと比較
		if (comp == 0)//中心要素が探索キーと一致
			found = mid;//発見した場所を記憶 ※見つかった位置の先頭を発見するため、探索を続行する
		if (range_half == 0)//探索範囲が残っていなければ探索終了
			break;
		if (comp <= 0)//探索キーが中心要素より小さいか同じだった場合、次に中心より前の範囲に絞って探索する
			range = range_half;
		else//if (comp > 0)//探索キーが中心要素より大きかった場合、次に中心より後の範囲に絞って探索する
		{
			begin = mid + 1;
			range -= (range_half + 1);
		}
	}
	if (found && found != begin)//見つかった地点が先頭でなければ、一つ前を調べる
	{
		T* found_prev = found - 1;
		if (comparison(*found_prev) == 0)//一つ前が一致するならそれを返す
			found = found_prev;
	}
	return found;
}
searchFuncSetByComparison(binarySearch);

//--------------------------------------------------------------------------------
//各種ソートアルゴリズムテスト
//--------------------------------------------------------------------------------

#include <memory.h>//_aligned_malloc,memalign用
#include <algorithm>//std::sort, std::for_each用
#include <array>//C++11 std::array用
#include <random>//C++11 random用
#include <chrono>//C++11 std::chrono用
#include <bitset>//std::bitset用
#include <functional>//C++11 std::function用

#include "sub.h"

//----------------------------------------
//テスト用構造体の配列型
class array_t : public std::array<data_t, TEST_DATA_COUNT>
{
public:
	void* operator new(const size_t size)
	{
		return _aligned_malloc(sizeof(array_t), alignof(array_t));
	}
	void operator delete (void* p)
	{
		_aligned_free(p);
	}
};

//----------------------------------------
//テスト用の比較処理
//qsort用関数
inline int predicate_func_qsort(const void*lhs, const void*rhs)
{
	return reinterpret_cast<const data_t*>(lhs)->m_key - reinterpret_cast<const data_t*>(rhs)->m_key;
}
//通常関数
extern bool predicate_func(const data_t& lhs, const data_t& rhs);
//インライン関数
inline bool predicate_func_inline(const data_t& lhs, const data_t& rhs)
{
	return lhs.m_key < rhs.m_key;
}
//関数オブジェクト
struct predicate_functor{
	inline bool operator()(const data_t& lhs, const data_t& rhs)
	{
		return lhs.m_key < rhs.m_key;
	}
};
//ラムダ関数
auto predicate_lambda = [](const data_t& lhs, const data_t& rhs) -> bool
{
	return lhs.m_key < rhs.m_key;
};
//二項比較オペレータ
//※sort関数に比較関数の指定を省略した場合、このオペレータが使用される
inline bool operator<(const data_t& lhs, const data_t& rhs){ return lhs.m_key < rhs.m_key; }
//※sort関数にstd::greater<T>()を指定した場合、このオペレータが使用される
inline bool operator>(const data_t& lhs, const data_t& rhs){ return lhs.m_key > rhs.m_key; }
//※linearSearch関数／binarySearch関数に比較関数の指定を省略した場合、このオペレータが使用される
inline bool operator==(const data_t& lhs, const int rhs){ return lhs.m_key == rhs; }
//※binarySearch関数に比較関数の指定を省略した場合、このオペレータが使用される
inline bool operator<(const data_t& lhs, const int rhs){ return lhs.m_key < rhs; }

//デフォルト
//#define predicate_default predicate_func
//#define predicate_default predicate_func_inline
//#define predicate_default predicate_functor()
#define predicate_default predicate_lambda

//----------------------------------------
//メイン
int main(const int argc, const char* argv[])
{
	//時間計測
	auto begin_time = std::chrono::system_clock::now();
	auto prev_time = begin_time;

	//処理時間計測
	auto calcElapsedTime = [](const std::chrono::system_clock::time_point& now_time, const std::chrono::system_clock::time_point& prev_time) -> double
	{
		const auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(now_time - prev_time);
		const auto elapsed_time = static_cast<double>(duration.count()) / 1000000000.;
		return elapsed_time;
	};
	auto getElapsedTime = [&calcElapsedTime](const std::chrono::system_clock::time_point& prev_time) -> double
	{
		return calcElapsedTime(std::chrono::system_clock::now(), prev_time);
	};

	//処理時間表示
	auto printElapsedTimeDirect = [&calcElapsedTime](const double elapsed_time, const bool is_preint) -> std::chrono::system_clock::time_point
	{
		if (is_preint)
			printf("*elapsed time=%.9llf sec.\n", elapsed_time);
		return std::chrono::system_clock::now();
	};
	auto printElapsedTime = [&calcElapsedTime, &printElapsedTimeDirect](const std::chrono::system_clock::time_point& prev_time, const bool is_print) -> std::chrono::system_clock::time_point
	{
		const auto now_time = std::chrono::system_clock::now();
		const auto elapsed_time = calcElapsedTime(now_time, prev_time);
		return printElapsedTimeDirect(elapsed_time, is_print);
	};

	//配列状態表示
	auto showArrayCondition = [&prev_time, &printElapsedTime](const array_t* array)
	{
		int ng = calcUnordered(*array, predicate_default);
		if (ng == 0)
			printf("Array is ordered. [record(s)=%d]\n", array->size());
		else
			printf("[NG] Array is NOT ordered! [NG=%d / record(s)=%d]\n", ng, array->size());
		{
			std::bitset<TEST_DATA_COUNT> seq_no_map;
			const std::size_t size = array->size();
			const data_t* prev = &array->at(0);
			const data_t* now = prev + 1;
			bool array_is_not_stable = false;
			bool array_is_broken = false;
			seq_no_map[prev->m_seqNo] = true;
			for (std::size_t i = 1; i < size; ++i, ++now, ++prev)
			{
				seq_no_map[now->m_seqNo] = true;
				if (prev->m_key == now->m_key && prev->m_seqNo > now->m_seqNo)
					array_is_not_stable = true;
			}
			if (seq_no_map.count() != TEST_DATA_COUNT)
				array_is_broken = true;
			if (array_is_broken)
				printf("[NG] Array is BROKEN !! Sorting-program is mistaken !\n");
			if (array_is_not_stable)
				printf("Array is NOT STABLE.\n");
			else
				printf("Array is stable.\n");
		}
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};

	//配列初期化
	enum init_type_t
	{
		init_shuffle1 = 0,//シャッフルパターン1
		init_shuffle2,//シャッフルパターン2
		init_shuffle3,//シャッフルパターン3
		init_ordered,//整列済みパターン
		init_reversed,//逆順整列済みパターン
		init_ordered_without_both_ends,//整列済みパターン（ただし、始端と終端のみ入れ替え）
		init_hard_with_quick_sort,//クイックソートに厳しいパターン
		init_pattern_num//初期化パターン数
	};
	auto makeArray = [&prev_time, &printElapsedTime, &showArrayCondition](array_t*& array, const init_type_t type, const char* type_name)
	{
		printf("----- Make Array(%s) -----\n", type_name);
		array = new array_t();
		int key = 0;
		int same_key_num = 0;
		auto nextKey = [&key, &same_key_num]() -> int
		{
			const int now_key = key;
			++same_key_num;
			if (same_key_num % TEST_DATA_SAME_KEY_NUM == 0)
				++key;
			return now_key;
		};
		switch (type)
		{
		case init_shuffle1:
		case init_shuffle2:
		case init_shuffle3:
		case init_ordered:
		case init_ordered_without_both_ends:
			{
				for (data_t& obj : *array)
					obj.m_key = nextKey();
			}
			break;
		case init_reversed:
			{
				for_each(array->rbegin(), array->rend(), [&nextKey](data_t& obj)
					{
						obj.m_key = nextKey();
					}
				);
			}
			break;
		case init_hard_with_quick_sort:
			{
				std::mt19937 random_engine(type);
				const std::size_t size = array->size();
				const std::size_t top = 0;
				const std::size_t mid = size >> 1;
				const std::size_t btm = size - 1;
				(*array)[top].m_key = nextKey();
				if(size >= 3)
					(*array)[mid].m_key = nextKey();
				if (size >= 2)
					(*array)[btm].m_key = nextKey();
				if (size > 4)
				{
					data_t* obj_begin = &(*array)[mid + 1];
					data_t* obj_end = &(*array)[size - 1];
					for (data_t* obj = obj_begin; obj <= obj_end; ++obj)
						obj->m_key = nextKey();
					std::shuffle(obj_begin, obj_end, random_engine);
				}
				if (size > 3)
				{
					data_t* obj_begin = &(*array)[top + 1];
					data_t* obj_end = &(*array)[mid];
					for (data_t* obj = obj_begin; obj < obj_end; ++obj)
						obj->m_key = nextKey();
					std::shuffle(obj_begin, obj_end, random_engine);
				}
			}
			break;
		}
		switch (type)
		{
		case init_shuffle1:
		case init_shuffle2:
		case init_shuffle3:
			{
				std::mt19937 random_engine(type);
				std::shuffle(array->begin(), array->end(), random_engine);
			}
			break;
		case init_ordered_without_both_ends:
			{
				swapValues((*array)[0], (*array)[array->size() - 1]);
			}
			break;
		}
		int seq_no = 0;
		for (data_t& obj : *array)
			obj.m_seqNo = seq_no++;
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
		showArrayCondition(array);
	#if 0//配列情報表示（デバッグ確認用）
		const data_t* element0_p = &(*array)[0];
		const data_t* element1_p = &(*array)[1];
		const std::size_t data_size = sizeof(data_t);
		const std::size_t element_size = reinterpret_cast<intptr_t>(element1_p)-reinterpret_cast<intptr_t>(element0_p);
		const std::size_t array_size = sizeof(*array);
		const std::size_t element_count = array->size();
		printf("array_size=%d, element_count=%d, element_size=%d, data_size=%d, element0_p=%p, element1_p=%p\n", array_size, element_count, element_size, data_size, element0_p, element1_p);
	#endif
	};
	array_t* array_shuffle1 = nullptr;
	array_t* array_shuffle2 = nullptr;
	array_t* array_shuffle3 = nullptr;
	array_t* array_ordered = nullptr;
	array_t* array_reversed = nullptr;
	array_t* array_ordered_without_both_ends = nullptr;
	array_t* array_hard_with_quick_sort = nullptr;
	auto makeArraySet = [&makeArray, &array_shuffle1, &array_shuffle2, &array_shuffle3, &array_ordered, &array_reversed, &array_ordered_without_both_ends, &array_hard_with_quick_sort]()
	{
		#define PARAM(x) array_##x, init_##x, #x
		makeArray(PARAM(shuffle1));
		makeArray(PARAM(shuffle2));
		makeArray(PARAM(shuffle3));
		makeArray(PARAM(ordered));
		makeArray(PARAM(reversed));
		makeArray(PARAM(ordered_without_both_ends));
		makeArray(PARAM(hard_with_quick_sort));
		#undef PARAM
	};
	auto copyWorkArray = [&prev_time, &printElapsedTime, &array_shuffle1, &array_shuffle2, &array_shuffle3, &array_ordered, &array_reversed, &array_ordered_without_both_ends, &array_hard_with_quick_sort](array_t*& array, const init_type_t type, const char* type_name)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("----- Copy Work Array(%s) -----\n", type_name);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
		array = new array_t();
		const array_t* array_src = nullptr;
		switch (type)
		{
		case init_shuffle1:                   array_src = array_shuffle1; break;
		case init_shuffle2:                   array_src = array_shuffle2; break;
		case init_shuffle3:                   array_src = array_shuffle3; break;
		case init_ordered:                    array_src = array_ordered; break;
		case init_reversed:                   array_src = array_reversed; break;
		case init_ordered_without_both_ends:  array_src = array_ordered_without_both_ends; break;
		case init_hard_with_quick_sort:       array_src = array_hard_with_quick_sort; break;
		}
		memcpy(array, array_src,sizeof(array_t));
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};

	//配列削除
	auto deleteArray = [&prev_time, &printElapsedTime](array_t*& array, const char* type_name)
	{
		printf("----- Delete array(%s) -----\n", type_name);
		delete array;
		array = nullptr;
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};
	auto deleteArraySet = [&deleteArray, &array_shuffle1, &array_shuffle2, &array_shuffle3, &array_ordered, &array_reversed, &array_ordered_without_both_ends, &array_hard_with_quick_sort]()
	{
		#define PARAM(x) array_##x, #x
		deleteArray(PARAM(shuffle1));
		deleteArray(PARAM(shuffle2));
		deleteArray(PARAM(shuffle3));
		deleteArray(PARAM(ordered));
		deleteArray(PARAM(reversed));
		deleteArray(PARAM(ordered_without_both_ends));
		deleteArray(PARAM(hard_with_quick_sort));
		#undef PARAM
	};
	auto deleteWorkArray = [&prev_time, &printElapsedTime](array_t*& array, const char* type_name)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("----- Delete Work Array(%s) -----\n", type_name);
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
		delete array;
		array = nullptr;
		const bool is_print = false;
		prev_time = printElapsedTime(prev_time, is_print);
	};

	//ソート
	typedef std::function<std::size_t(array_t*)> sort_procedure;
	auto sort = [&prev_time, &getElapsedTime, &printElapsedTimeDirect, &showArrayCondition](array_t*& array, sort_procedure sort_proc, double& elapsed_time, std::size_t& swapped_count)
	{
	#ifdef TEST_DATA_WATCH_CONSTRUCTOR
		printf("----- Sort -----\n");
	#endif//TEST_DATA_WATCH_CONSTRUCTOR
		prev_time = std::chrono::system_clock::now();
		swapped_count = sort_proc(array);
		elapsed_time = getElapsedTime(prev_time);
		const bool is_print = true;
		prev_time = printElapsedTimeDirect(elapsed_time, is_print);
		showArrayCondition(array);
		if (swapped_count != 0xffffffff)
			printf("[swapped=%d count(s)]\n", swapped_count);
	};
	
	//計測
	auto measure = [&copyWorkArray, &sort, &deleteWorkArray](const init_type_t type, const char* type_name, sort_procedure sort_proc, double& elapsed_time, std::size_t& swapped_count)
	{
		printf("\n");
		printf("------------------------------\n");
		printf("Sort array(%s)\n", type_name);
		printf("------------------------------\n");
		array_t* array = nullptr;//配列
		copyWorkArray(array, type, type_name);//配列初期化
		sort(array, sort_proc, elapsed_time, swapped_count);//ソート
		deleteWorkArray(array, type_name);//配列削除
	};

	//ソート処理時間集計用構造体
	struct sum_t
	{
		int count;
		double elapsed_time_sum;
		double elapsed_time_avg;
		double elapsed_time_min;
		double elapsed_time_max;
		std::size_t swapped_count_sum;
		std::size_t swapped_count_avg;
		std::size_t swapped_count_min;
		std::size_t swapped_count_max;
		void add(const double elapsed_time, const std::size_t swapped_count)
		{
			++count;
			if (elapsed_time_sum == -1.)
				elapsed_time_sum = 0.;
			elapsed_time_sum += elapsed_time;
			elapsed_time_avg = elapsed_time_sum / static_cast<double>(count);
			if (elapsed_time_min == -1. || elapsed_time_min > elapsed_time)
				elapsed_time_min = elapsed_time;
			if (elapsed_time_max == -1. || elapsed_time_max < elapsed_time)
				elapsed_time_max = elapsed_time;
			if (swapped_count != 0xffffffff)
			{
				if (swapped_count_sum == 0xffffffff)
					swapped_count_sum = 0;
				swapped_count_sum += swapped_count;
				swapped_count_avg = swapped_count_sum / static_cast<std::size_t>(count);
				if (swapped_count_min == 0xffffffff || swapped_count_min > swapped_count)
					swapped_count_min = swapped_count;
				if (swapped_count_max == 0xffffffff || swapped_count_max < swapped_count)
					swapped_count_max = swapped_count;
			}
		}
		sum_t() :
			count(0),
			elapsed_time_sum(-1.),
			elapsed_time_avg(-1.),
			elapsed_time_min(-1.),
			elapsed_time_max(-1.),
			swapped_count_sum(0xffffffff),
			swapped_count_avg(0xffffffff),
			swapped_count_min(0xffffffff),
			swapped_count_max(0xffffffff)
		{}
	};
	
	//まとめて計測
	auto measureAll = [&measure](const char* sort_type_name, sort_procedure sort_proc) -> sum_t
	{
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("============================================================\n");

		#define PARAM(x) init_##x, #x

		//ソート処理時間集計
		sum_t sum;
		double elapsed_time;
		std::size_t swapped_count;

		//シャッフルパターン１
		measure(PARAM(shuffle1), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//シャッフルパターン２
		measure(PARAM(shuffle2), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//シャッフルパターン３
		measure(PARAM(shuffle3), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//整列済みパターン
		measure(PARAM(ordered), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//逆順整列済みパターン
		measure(PARAM(reversed), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//整列済みパターン（ただし、始端と終端のみ入れ替え）
		measure(PARAM(ordered_without_both_ends), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		//クイックソートに厳しいパターン
		measure(PARAM(hard_with_quick_sort), sort_proc, elapsed_time, swapped_count);
		sum.add(elapsed_time, swapped_count);

		#undef PARAM

		printf("\n");
		printf("============================================================\n");
		printf("Sort type: [%s]\n", sort_type_name);
		printf("* Total time       = %.9llf sec.\n", sum.elapsed_time_sum);
		printf("* Average time     = %.9llf sec.\n", sum.elapsed_time_avg);
		printf("* Min time         = %.9llf sec.\n", sum.elapsed_time_min);
		printf("* Max time         = %.9llf sec.\n", sum.elapsed_time_max);
		if (sum.swapped_count_sum != 0xffffffff)
		{
			printf("* Total Swapped    = %9u count(s)\n", sum.swapped_count_sum);
			printf("* Average  Swapped = %9u count(s)\n", sum.swapped_count_avg);
			printf("* Min Swapped      = %9u count(s)\n", sum.swapped_count_min);
			printf("* Max Swapped      = %9u count(s)\n", sum.swapped_count_max);
		}
		printf("============================================================\n");

		return sum;
	};
	
	//----------------------------------------
	//測定開始
	printf("============================================================\n");
	printf("Initialize\n");
	printf("============================================================\n");
	makeArraySet();
	printf("\n");
	printf("\n");

	//----------------------------------------
	//標準ライブラリによるソート

#if 1
	//--------------------
	//Cライブラリ：qsort関数
	//アルゴリズム：クイックソート
	auto clib_qsort = [](array_t* array) -> std::size_t
	{
		qsort(&array->at(0), array->size(),sizeof(data_t), predicate_func_qsort);
		return 0xffffffff;
	};
	const sum_t sum_clib_qsort = measureAll("C-Library qsort", clib_qsort);
	printf("\n");
	printf("\n");

	//--------------------
	//STLソート1：通常関数で比較
	//アルゴリズム：イントロソート（クイックソート＋ヒープソート＋挿入ソート）
	auto stl_sort1 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), predicate_func);
		return 0xffffffff;
	};
	const sum_t sum_stl1 = measureAll("STL std::sort(with function)", stl_sort1);
	printf("\n");
	printf("\n");

	//STLソート2：インライン関数で比較
	//アルゴリズム：（同上）
	auto stl_sort2 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), predicate_func_inline);
		return 0xffffffff;
	};
	const sum_t sum_stl2 = measureAll("STL std::sort(with inline function)", stl_sort2);
	printf("\n");
	printf("\n");

	//STLソート3：関数オブジェクトで比較
	//アルゴリズム：（同上）
	auto stl_sort3 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), predicate_functor());
		return 0xffffffff;
	};
	const sum_t sum_stl3 = measureAll("STL std::sort(with functor)", stl_sort3);
	printf("\n");
	printf("\n");

	//STLソート4：ラムダ関数で比較
	//アルゴリズム：（同上）
	auto stl_sort4 = [](array_t* array) -> std::size_t
	{
		std::sort(array->begin(), array->end(), predicate_lambda);
		return 0xffffffff;
	};
	const sum_t sum_stl4 = measureAll("STL std::sort(with lamda)", stl_sort4);
	printf("\n");
	printf("\n");

	//--------------------
	//STL安定ソート
	//アルゴリズム：マージソート ※外部メモリ使用あり
	auto stl_stable_sort = [](array_t* array) -> std::size_t
	{
		std::stable_sort(array->begin(), array->end(), predicate_func);
		return 0xffffffff;
	};
	const sum_t sum_stl_stable = measureAll("STL std::stable_sort *Not inplace", stl_stable_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//交換ソート

	//アルゴリズム：バブルソート
	auto bubble_sort = [](array_t* array) -> std::size_t
	{
		return bubbleSort(*array, predicate_default);
	};
	const sum_t sum_bubble = measureAll("Bubble sort", bubble_sort);
	printf("\n");
	printf("\n");
	
	//アルゴリズム：シェーカーソート
	auto shaker_sort = [](array_t* array) -> std::size_t
	{
		return shakerSort(*array, predicate_default);
	};
	const sum_t sum_shaker = measureAll("Shaker sort", shaker_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：奇遇転置ソート
	auto odd_even_sort = [](array_t* array) -> std::size_t
	{
		return oddEvenSort(*array, predicate_default);
	};
	const sum_t sum_odd_even = measureAll("Odd-Even sort", odd_even_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：シェアソート
	auto shear_sort = [](array_t* array) -> std::size_t
	{
		return shearSort(*array, predicate_default);
	};
	const sum_t sum_shear = measureAll("Shear sort", shear_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：コムソート
	auto comb_sort = [](array_t* array) -> std::size_t
	{
		return combSort(*array, predicate_default);
	};
	const sum_t sum_comb = measureAll("Comb sort", comb_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：ノームソート
	auto gnome_sort = [](array_t* array) -> std::size_t
	{
		return gnomeSort(*array, predicate_default);
	};
	const sum_t sum_gnome = measureAll("Gnome sort", gnome_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：クイックソート
	auto quick_sort = [](array_t* array) -> std::size_t
	{
		return quickSort(*array, predicate_default);
	};
	const sum_t sum_quick = measureAll("Quick sort", quick_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//選択ソート

	//アルゴリズム：選択ソート
	auto selection_sort = [](array_t* array) -> std::size_t
	{
		return selectionSort(*array, predicate_default);
	};
	const sum_t sum_selection = measureAll("Selection sort", selection_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：ヒープソート
	auto heap_sort = [](array_t* array) -> std::size_t
	{
		return heapSort(*array, predicate_default);
	};
	const sum_t sum_heap = measureAll("Heap sort", heap_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//挿入ソート

	//アルゴリズム：挿入ソート
	auto insertion_sort = [](array_t* array) -> std::size_t
	{
		return insertionSort(*array, predicate_default);
	};
	const sum_t sum_insertion = measureAll("Insertion sort", insertion_sort);
	printf("\n");
	printf("\n");

	//アルゴリズム：シェルソート
	auto shell_sort = [](array_t* array) -> std::size_t
	{
		return shellSort(*array, predicate_default);
	};
	const sum_t sum_shell = measureAll("Shell sort", shell_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//マージソート

	//アルゴリズム：インプレースマージソート
	auto inplace_merge_sort = [](array_t* array) -> std::size_t
	{
		return inplaceMergeSort(*array, predicate_default);
	};
	const sum_t sum_inplace_merge = measureAll("Inplace Merge sort", inplace_merge_sort);
	printf("\n");
	printf("\n");
#endif

	//----------------------------------------
	//混成ソート

	//アルゴリズム：イントロソート
	auto intro_sort = [](array_t* array) -> std::size_t
	{
		return introSort(*array, predicate_default);
	};
	const sum_t sum_intro = measureAll("Intro sort", intro_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//非比較ソート

	//アルゴリズム：基数ソート
	auto radix_sort = [](array_t* array) -> std::size_t
	{
		struct getKey{
			typedef int key_type;
			//typedef unsigned int key_type;
			//typedef unsigned char key_type;
			inline key_type operator()(const data_t& obj){ return obj.m_key; }
		};
		return radixSort(*array, getKey());
	};
	const sum_t sum_radix = measureAll("Radix sort", radix_sort);
	printf("\n");
	printf("\n");

	//----------------------------------------
	//測定終了

	//結果を表示
	auto printLine = [](const char* name, const sum_t& sum)
	{
		printf("- %-23s %13.9llf/%13.9llf/%13.9llf/%13.9llf",
			name,
			sum.elapsed_time_sum,
			sum.elapsed_time_avg,
			sum.elapsed_time_min,
			sum.elapsed_time_max);
		if (sum.swapped_count_sum != 0xffffffff)
		{
			printf("%11u/%11u/%11u/%11u",
				sum.swapped_count_sum,
				sum.swapped_count_avg,
				sum.swapped_count_min,
				sum.swapped_count_max);
		}
		printf("\n");
	};
	printf("============================================================\n");
	printf("Result(Summary)\n");
	printf("============================================================\n");
	printf("Array Element size = %d Bytes\n", sizeof(data_t));
	printf("Array Element(s)   = %d Count(s)\n", array_shuffle1->size());
	printf("Total Array size   = %d Bytes\n", sizeof(*array_shuffle1));
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("- Sort name:                Elapsed Time (Sum/Average/Min/Max) [sec.]             Swapped (Sum/Average/Min/Max) [count(s)]\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
#if 1
	printf("[C-Library sort](Quick sort)\n");
	printLine("qsort(inline-function):", sum_clib_qsort);
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("[STL sort](Intro sort)\n");
	printLine("std::sort(function):", sum_stl1);
	printLine("std::sort(inline-func):", sum_stl2);
	printLine("std::sort(functor):", sum_stl3);
	printLine("std::sort(lambda):", sum_stl4);
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("[STL stable sort](Merge sort) *Not In-place sort\n");
	printLine("std::stable_sort<S>:", sum_stl_stable);
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Exchange sorts]\n");
	printLine("Bubble sort<S>:", sum_bubble);
	printLine("Shaker sort<S>:", sum_shaker);
	printLine("Odd-Even sort<S>:", sum_odd_even);
	printLine("Shear sort:", sum_shear);
	printLine("Comb sort:", sum_comb);
	printLine("Gnome sort<S>:", sum_gnome);
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Partition-exchange sorts]\n");
	printLine("Quick sort:", sum_quick);
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Selection sorts]\n");
	printLine("Selection sort:", sum_selection);
	printLine("Heap sort:", sum_heap);
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Insertion sorts]\n");
	printLine("Insertion sort<S>:", sum_insertion);
	printLine("Shell sort:", sum_shell);
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Merge sorts]\n");
	printLine("Inplace-Merge sort<S>:", sum_inplace_merge);
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
#endif
	printf("[Hybrid sorts]\n");
	printLine("Intro sort:", sum_intro);
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("[Distribution sorts] *Not In-place sort\n");
	printLine("Radix sort<S>:", sum_radix);
	printf("--------------------------------------------------------------------------------------------------------------------------------\n");
	printf("* <S> ... Stable sort algorithm.\n");
	printf("\n");

#if 0
	//----------------------------------------
	//バリエーションテスト

#if 1
	//----------------------------------------
	//ソートのバリエーション
	{
		//コンテナを直接渡してソートする方法
		array_t& arr = *array_shuffle1;
		const std::size_t reuslt = bubbleSort(arr, predicate_default);
		//その他のソート指定方法
		const std::size_t reuslt1 = bubbleSort(&arr.at(0), arr.size(), predicate_default);
		//const std::size_t reuslt2 = bubbleSort(arr._Elems, predicate_default);//VC++
		const std::size_t reuslt3 = bubbleSort(&arr.at(0), &arr.at(arr.size() - 1) + 1, predicate_default);
		const std::size_t reuslt4 = bubbleSort(arr.begin(), arr.end(), predicate_default);
		const std::size_t reuslt5 = bubbleSort(arr, predicate_default);
		//比較関数を省略する方法 ※ operator<(const T&, const T&) が定義されている必要あり
		const std::size_t reuslt6 = bubbleSort(&arr.at(0), arr.size());
		//const std::size_t reuslt7 = bubbleSort(arr._Elems);//VC++
		const std::size_t reuslt8 = bubbleSort(&arr.at(0), &arr.at(arr.size() - 1) + 1);
		const std::size_t reuslt9 = bubbleSort(arr.begin(), arr.end());
		const std::size_t reuslt10 = bubbleSort(arr);
		//専用の比較関数を設けず、比較を逆転する方法 ※ operator>(const T&, const T&) が定義されている必要あり
		const std::size_t reuslt11 = bubbleSort(arr, std::greater<data_t>());
	}
#endif
	
#if 1
	//----------------------------------------
	//探索テスト
#if 1
	//線形探索
	{
		for (int target = -1; target < 40; ++target)
		{
			const data_t* data_def = linearSearchValue(*array_shuffle1, target);
			{
				array_t& arr = *array_shuffle1;
				const array_t& const_arr = *array_shuffle1;
				const data_t* data1_def = linearSearchValue(arr, target);
				const data_t* data2_def = linearSearchValue(const_arr, target);
				const data_t* data3_def = linearSearchValue(arr.begin(), arr.end(), target);
				const data_t* data4_def = linearSearchValue(arr.cbegin(), arr.cend(), target);
				const data_t* data5_def = linearSearchValue(const_arr.begin(), const_arr.end(), target);
				//const data_t* data6_def = linearSearchValue(arr._Elems, target);//VC++
				//const data_t* data7_def = linearSearchValue(const_arr._Elems, target);//VC++
				const data_t* data8_def = linearSearchValue(&arr.at(0), arr.size(), target);
				const data_t* data9_def = linearSearchValue(&const_arr.at(0), const_arr.size(), target);
				const data_t* data10_def = linearSearchValue(&arr.at(0), &arr.at(0) + arr.size(), target);
				const data_t* data11_def = linearSearchValue(&const_arr.at(0), &const_arr.at(0) + const_arr.size(), target);
			}
			auto search_predicate = [&target](const data_t& data) -> bool { return data.m_key == target; };
			const data_t* data = linearSearch(*array_shuffle1, search_predicate);
			{
				array_t& arr = *array_shuffle1;
				const array_t& const_arr = *array_shuffle1;
				const data_t* data1 = linearSearch(arr, search_predicate);
				const data_t* data2 = linearSearch(const_arr, search_predicate);
				const data_t* data3 = linearSearch(arr.begin(), arr.end(), search_predicate);
				const data_t* data4 = linearSearch(arr.cbegin(), arr.cend(), search_predicate);
				const data_t* data5 = linearSearch(const_arr.begin(), const_arr.end(), search_predicate);
				//const data_t* data6 = linearSearch(arr._Elems, search_predicate);//VC++
				//const data_t* data7 = linearSearch(const_arr._Elems, search_predicate);//VC++
				const data_t* data8 = linearSearch(&arr.at(0), arr.size(), search_predicate);
				const data_t* data9 = linearSearch(&const_arr.at(0), const_arr.size(), search_predicate);
				const data_t* data10 = linearSearch(&arr.at(0), &arr.at(0) + arr.size(), search_predicate);
				const data_t* data11 = linearSearch(&const_arr.at(0), &const_arr.at(0) + const_arr.size(), search_predicate);
			}
			auto search_predicate_val = [](const data_t& data, const int target) -> bool { return data.m_key == target; };
			const data_t* data_val = linearSearchValue(*array_shuffle1, target, search_predicate_val);
			{
				array_t& arr = *array_shuffle1;
				const array_t& const_arr = *array_shuffle1;
				const data_t* data1_val = linearSearchValue(arr, target, search_predicate_val);
				const data_t* data2_val = linearSearchValue(const_arr, target, search_predicate_val);
				const data_t* data3_val = linearSearchValue(arr.begin(), arr.end(), target, search_predicate_val);
				const data_t* data4_val = linearSearchValue(arr.cbegin(), arr.cend(), target, search_predicate_val);
				const data_t* data5_val = linearSearchValue(const_arr.begin(), const_arr.end(), target, search_predicate_val);
				//const data_t* data6_val = linearSearchValue(arr._Elems, target, search_predicate_val);//VC++
				//const data_t* data7_val = linearSearchValue(const_arr._Elems, target, search_predicate_val);//VC++
				const data_t* data8_val = linearSearchValue(&arr.at(0), arr.size(), target, search_predicate_val);
				const data_t* data9_val = linearSearchValue(&const_arr.at(0), const_arr.size(), target, search_predicate_val);
				const data_t* data10_val = linearSearchValue(&arr.at(0), &arr.at(0) + arr.size(), target, search_predicate_val);
				const data_t* data11_val = linearSearchValue(&const_arr.at(0), &const_arr.at(0) + const_arr.size(), target, search_predicate_val);
			}

			if (data_def)
				printf("target=%d, linearSearch=[%d, %d]\n", target, data_def->m_key, data_def->m_seqNo);
			else
				printf("target=%d, linearSearch=nullptr\n", target);
		}
	}
#endif

#if 1
	//二分探索
	{
		auto sort_pred = [](const data_t& lhs, const data_t& rhs) -> bool { return lhs.m_key < rhs.m_key; };
		introSort(*array_shuffle1, sort_pred);
		for (int target = -1; target < 40; ++target)
		{
			const data_t* data_def = binarySearchValue(*array_shuffle1, target);
			{
				array_t& arr = *array_shuffle1;
				const array_t& const_arr = *array_shuffle1;
				const data_t* data1_def = binarySearchValue(arr, target);
				const data_t* data2_def = binarySearchValue(const_arr, target);
				const data_t* data3_def = binarySearchValue(arr.begin(), arr.end(), target);
				const data_t* data4_def = binarySearchValue(arr.cbegin(), arr.cend(), target);
				const data_t* data5_def = binarySearchValue(const_arr.begin(), const_arr.end(), target);
				//const data_t* data6_def = binarySearchValue(arr._Elems, target);//VC++
				//const data_t* data7_def = binarySearchValue(const_arr._Elems, target);//VC++
				const data_t* data8_def = binarySearchValue(&arr.at(0), arr.size(), target);
				const data_t* data9_def = binarySearchValue(&const_arr.at(0), const_arr.size(), target);
				const data_t* data10_def = binarySearchValue(&arr.at(0), &arr.at(0) + arr.size(), target);
				const data_t* data11_def = binarySearchValue(&const_arr.at(0), &const_arr.at(0) + const_arr.size(), target);
			}
			auto search_comparison = [&target](const data_t& data) -> int { return target - data.m_key; };
			const data_t* data = binarySearch(*array_shuffle1, search_comparison);
			{
				array_t& arr = *array_shuffle1;
				const array_t& const_arr = *array_shuffle1;
				const data_t* data1 = binarySearch(arr, search_comparison);
				const data_t* data2 = binarySearch(const_arr, search_comparison);
				const data_t* data3 = binarySearch(arr.begin(), arr.end(), search_comparison);
				const data_t* data4 = binarySearch(arr.cbegin(), arr.cend(), search_comparison);
				const data_t* data5 = binarySearch(const_arr.begin(), const_arr.end(), search_comparison);
				//const data_t* data6 = binarySearch(arr._Elems, search_comparison);//VC++
				//const data_t* data7 = binarySearch(const_arr._Elems, search_comparison);//VC++
				const data_t* data8 = binarySearch(&arr.at(0), arr.size(), search_comparison);
				const data_t* data9 = binarySearch(&const_arr.at(0), const_arr.size(), search_comparison);
				const data_t* data10 = binarySearch(&arr.at(0), &arr.at(0) + arr.size(), search_comparison);
				const data_t* data11 = binarySearch(&const_arr.at(0), &const_arr.at(0) + const_arr.size(), search_comparison);
			}
			auto search_comparison_val = [](const data_t& data, const int target) -> int { return target - data.m_key; };
			const data_t* data_val = binarySearch(*array_shuffle1, search_comparison);
			{
				array_t& arr = *array_shuffle1;
				const array_t& const_arr = *array_shuffle1;
				const data_t* data1_val = binarySearchValue(arr, target, search_comparison_val);
				const data_t* data2_val = binarySearchValue(const_arr, target, search_comparison_val);
				const data_t* data3_val = binarySearchValue(arr.begin(), arr.end(), target, search_comparison_val);
				const data_t* data4_val = binarySearchValue(arr.cbegin(), arr.cend(), target, search_comparison_val);
				const data_t* data5_val = binarySearchValue(const_arr.begin(), const_arr.end(), target, search_comparison_val);
				//const data_t* data6_val = binarySearchValue(arr._Elems, target, search_comparison_val);//VC++
				//const data_t* data7_val = binarySearchValue(const_arr._Elems, target, search_comparison_val);//VC++
				const data_t* data8_val = binarySearchValue(&arr.at(0), arr.size(), target, search_comparison_val);
				const data_t* data9_val = binarySearchValue(&const_arr.at(0), const_arr.size(), target, search_comparison_val);
				const data_t* data10_val = binarySearchValue(&arr.at(0), &arr.at(0) + arr.size(), target, search_comparison_val);
				const data_t* data11_val = binarySearchValue(&const_arr.at(0), &const_arr.at(0) + const_arr.size(), target, search_comparison_val);
			}

			if (data_def)
				printf("target=%d, binarySearch=[%d, %d]\n", target, data_def->m_key, data_def->m_seqNo);
			else
				printf("target=%d, binarySearch=nullptr\n", target);
		}
	}
#endif
#endif
#endif

	//----------------------------------------
	//測定終了
	printf("============================================================\n");
	printf("Finalize\n");
	printf("============================================================\n");
	deleteArraySet();
	printf("\n");
	printf("\n");
	printf("============================================================\n");
	printf("End\n");
	printf("============================================================\n");
	printElapsedTime(begin_time, true);//処理時間表示

#if 0
	//ポインタ変数のソート処理動作確認
	{
		printf("\n");
		printf("\n");
		printf("--- Test for sort with pointer ---\n");
		static const std::size_t data_num = 10;
		std::array<data_t, data_num> d_arr;
		std::array<data_t*, data_num> p_arr;
		for (int i = 0; i < data_num; ++i)
		{
			d_arr[i].m_key = i;
			p_arr[data_num - i - 1] = &d_arr[i];
		}
		auto printData = [&p_arr]()
		{
			for (data_t* p : p_arr)
			{
				printf("[%d] ", p->m_key);
			}
			printf("\n");
		};
		auto predicate = [](data_t* val1, data_t* val2){ return val1->m_key < val2->m_key; };
		std::size_t unordered = calcUnordered(p_arr, predicate);
		printf("[Before]\n");
		printData();
		printf("unordered=%d\n", unordered);
		introSort(p_arr, predicate);
		unordered = calcUnordered(p_arr, predicate);
		printf("[After]\n");
		printData();
		printf("unordered=%d\n", unordered);
		printf("--- End ---\n");
	}
#endif
	
	return EXIT_SUCCESS;
}

// End of file

#include <stdio.h>
#include <stdlib.h>

template<typename T>
constexpr T power( T x, unsigned int y )
{
    return y == 1 ? x : x * power( x, y - 1 ) ;
}

//値が二つの max()
template<typename T1, typename T2>
constexpr T1 max(T1 n1, T2 n2){ return n1 > n2 ? n1 : n2;  }

//値が三つ以上の max() : 再帰処理（注：テンプレートの特殊化ではなく、関数のオーバーロードで再帰を終結させている）
template<typename T1, typename T2, typename T3, typename... Tx>
constexpr T1 max(T1 n1, T2 n2, T3 n3, Tx... nx){ return max(max(n1, n2), n3, nx...); } //nxが空になったら値が二つの方が呼ばれる

int main(const int argc, const char* argv[])
{
	const int v1 = max(1, 2);
	const int v2 = max(3, 4, 5);
	const int v3 = max(6, 7, 8, 9);
	const int v4 = max(10, 11, 12, 13, 14);
	const int v5 = max(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14);
	const int v6 = max(6, 5, 4, 3, 2, 1);
	const int v7 = max(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15);
	printf("{%d, %d, %d, %d, %d, %d, %d}\n", v1, v2, v3, v4, v5, v6, v7);
	return EXIT_SUCCESS;
}

// End of file

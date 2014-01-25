#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#ifdef _OPENMP
#include <omp.h>
#endif

//素数判定
bool isPrime(const int n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else if (n % 2 == 0)
		return false;
	for (int i = 3; i <= n / i; i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

//メイン関数
int main(const int argc, const char* argv[])
{
#pragma omp parallel//num_threads(3)
	{
		printf("[BEGIN]\n");
		printf("Hello, OpenMP!\n");
		printf("[END]\n");
	}
	
	//CPUスペック表示
#ifdef _OPENMP
	printf("omp_get_num_procs()=%d\n", omp_get_num_procs());
	printf("omp_get_max_threads()=%d\n", omp_get_max_threads());
#endif
	
	//処理時間計測準備
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	
	//処理時間計測（開始）
	LARGE_INTEGER begin;
	QueryPerformanceCounter(&begin);

	//集計
	int prime_num= 0;
	long long prime_total = 0;
	long long sum = 0;
	{
		int i, j, k;

		//三重ループで集計
#pragma omp parallel for reduction(+:sum) private(j, k)
		for (i = 0; i < 2000; ++i)
		{
			sum += i;
			for (j = 0; j < 2000; ++j)
			{
				sum += j;
				for (k = 0; k < 2000; ++k)
				{
					sum += k;
				}
			}
		}

		//素数を数える
#pragma omp parallel
		{
			static const int PRIME_MAX = 200000;
			static const int PRIME_NUM_MAX = 20000;
#pragma omp for
			for (i = 0; i < PRIME_MAX; ++i)
			{
				if (prime_num < PRIME_NUM_MAX && isPrime(i))
				{
#pragma omp atomic
					++prime_num;
#pragma omp atomic
					prime_total += i;
				}
			}
		}
	}

	//処理時間計測（終了）
	LARGE_INTEGER end;
	QueryPerformanceCounter(&end);
	float time = static_cast<float>(static_cast<double>(end.QuadPart - begin.QuadPart) / static_cast<double>(freq.QuadPart));
	
	//結果表示
	printf("prime_num=%d, prime_total=%lld, sum=%lld, time=%.6f sec\n", prime_num, prime_total, sum, time);
	/*
	omp_lock_t myLock;
	omp_init_lock(&myLock);
	omp_set_lock(&myLock);
	omp_unset_lock(&myLock);
	omp_set_dynamic(false);
	omp_set_num_threads(2);
#pragma omp parallel num_threads(5)
	{
		printf("[begin]\n");
		fflush(stdout);
#pragma omp parallel num_threads(2)
		{
			sub();
		}
		printf("[end]\n");
		fflush(stdout);
	}
	printf("Hello, OpenMP!\n");
*/
	return EXIT_SUCCESS;
}

// End of file


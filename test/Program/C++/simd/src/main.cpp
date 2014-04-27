#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

#include <chrono>//処理時間計測用

extern void sub(vec3& v1, vec3& v1_n, vec3& v2, vec3& v2_n, vec3& vdist, vec3& vdist_n, float& dist_val, float& dot_val, float& dot_val_n, vec3& vcross, vec3& vcross_n, vec3& v3, vec3& v3_n, const float add, const float mul, const float div, const float sub, const int dummy);

//テストメイン
int main(const int argc, const char* argv[])
{
	const auto start = std::chrono::system_clock::now();
	vec3 v1;
	vec3 v1_n;
	vec3 v2;
	vec3 v2_n;
	vec3 vdist;
	vec3 vdist_n;
	float dist_val;
	float dot_val;
	float dot_val_n;
	vec3 vcross;
	vec3 vcross_n;
	vec3 v3;
	vec3 v3_n;
	const int repeat = 100000000;
	for (int loop = 0; loop < repeat; ++loop)
	{
		sub(v1, v1_n, v2, v2_n, vdist, vdist_n, dist_val, dot_val, dot_val_n, vcross, vcross_n, v3, v3_n, 1.f, 2.f, 3.f, 4.f, loop);
	}
	const auto end = std::chrono::system_clock::now();
	const auto duration = end - start;
	const float sec = static_cast<float>(static_cast<double>(std::chrono::duration_cast<std::chrono::microseconds>(duration).count()) / 1000000.);
#ifdef USE_SIMD
	printf("<use simd>\n");
#else//USE_SIMD
	printf("<not use simd>\n");
#endif//USE_SIMD
	printf("repeat = %d times\n", repeat);
	printf("elapsed time = %.6f sec\n", sec);
	printf("v1       ={%.2f, %.2f, %.2f}(%.4f)\n", v1.x(), v1.y(), v1.z(), v1.length());
	printf("v1_n     ={%.2f, %.2f, %.2f}(%.4f)\n", v1_n.x(), v1_n.y(), v1_n.z(), v1_n.length());
	printf("v2       ={%.2f, %.2f, %.2f}(%.4f)\n", v2.x(), v2.y(), v2.z(), v2.length());
	printf("v2_n     ={%.2f, %.2f, %.2f}(%.4f)\n", v2_n.x(), v2_n.y(), v2_n.z(), v2_n.length());
	printf("vdist    ={%.2f, %.2f, %.2f}(%.4f)\n", vdist.x(), vdist.y(), vdist.z(), vdist.length());
	printf("vdist_n  ={%.2f, %.2f, %.2f}(%.4f)\n", vdist_n.x(), vdist_n.y(), vdist_n.z(), vdist_n.length());
	printf("dist_val =%.4f\n", dist_val);
	printf("dot_val  =%.4f\n", dot_val);
	printf("dot_val_n=%.4f\n", dot_val_n);
	printf("vcross   ={%.2f, %.2f, %.2f}(%.4f)\n", vcross.x(), vcross.y(), vcross.z(), vcross.length());
	printf("vcross_n ={%.2f, %.2f, %.2f}(%.4f)\n", vcross_n.x(), vcross_n.y(), vcross_n.z(), vcross_n.length());
	printf("v3       ={%.2f, %.2f, %.2f}(%.4f)\n", v3.x(), v3.y(), v3.z(), v3.length());
	printf("v3_n     ={%.2f, %.2f, %.2f}(%.4f)\n", v3_n.x(), v3_n.y(), v3_n.z(), v3_n.length());
	return EXIT_SUCCESS;
}

// End of file

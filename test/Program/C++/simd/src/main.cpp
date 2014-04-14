#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

#include <chrono>//èàóùéûä‘åvë™óp

extern void sub(vec4& v1, vec4& v1n, vec4& v2, vec4& v2n, vec4& vd, vec4& vdn, float& dist, const float add, const float mul, const float div, const float sub);

int main(const int argc, const char* argv[])
{
	const auto start = std::chrono::system_clock::now();
	vec4 v1;
	vec4 v1n;
	vec4 v2;
	vec4 v2n;
	vec4 vd;
	vec4 vdn;
	float dist;
	const int repeat = 10000000;
	for (int loop = 0; loop < repeat; ++loop)
	{
		sub(v1, v1n, v2, v2n, vd, vdn, dist, 1.f, 2.f, 3.f, 4.f);
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
	printf("v1 ={%.2f, %.2f, %.2f, %.2f}(%.4f)\n", v1.x(), v1.y(), v1.z(), v1.w(), v1.norm());
	printf("v1n={%.2f, %.2f, %.2f, %.2f}(%.4f)\n", v1n.x(), v1n.y(), v1n.z(), v1n.w(), v1n.norm());
	printf("v2 ={%.2f, %.2f, %.2f, %.2f}(%.4f)\n", v2.x(), v2.y(), v2.z(), v2.w(), v2.norm());
	printf("v2n={%.2f, %.2f, %.2f, %.2f}(%.4f)\n", v2n.x(), v2n.y(), v2n.z(), v2n.w(), v2n.norm());
	printf("vd ={%.2f, %.2f, %.2f, %.2f}(%.4f)\n", vd.x(), vd.y(), vd.z(), vd.w(), vd.norm());
	printf("vdn={%.2f, %.2f, %.2f, %.2f}(%.4f)\n", vdn.x(), vdn.y(), vdn.z(), vdn.w(), vdn.norm());
	printf("dist=%.4f\n", dist);
	return EXIT_SUCCESS;
}

// End of file

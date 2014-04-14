#include "vector.h"

static float s_val[4] = { 1.f, 2.f, 3.f, 4.f };

void sub(vec4& v1, vec4& v1n, vec4& v2, vec4& v2n, vec4& vd, vec4& vdn, float& dist, const float add, const float mul, const float div, const float sub)
{
	vec4 tmp1(s_val[0], s_val[1], s_val[2], s_val[3]);
	vec4 tmp2 = (tmp1 + vec4(add)) * vec4(mul) / vec4(div) - vec4(sub);
	v1 = tmp1;
	v1n = ::normalize(tmp1);
	v2 = tmp2;
	v2n = ::normalize(tmp2);
	vd = tmp2 - tmp1;
	vdn = ::normalize(vd);
	dist = ::dist(tmp1, tmp2);
}

// End of file

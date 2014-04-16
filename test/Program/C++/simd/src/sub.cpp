#include "vector.h"

//静的変数
static float s_val1[3] = { 1.f, 2.f, 3.f };
static float s_val2[3] = { -4.f, -5.f, -6.f };

//パフォーマンステスト用関数
//※コンパイラの最適化の影響が起こらないように、ソースファイルを分けて、かつ、ダミーパラメータを受け渡し
void sub(vec3& v1, vec3& v1_n, vec3& v2, vec3& v2_n, vec3& vdist, vec3& vdist_n, float& dist_val, float& dot_val, float& dot_val_n, vec3& vcross, vec3& vcross_n, vec3& v3, vec3& v3_n, const float add, const float mul, const float div, const float sub, const int dummy)
{
	vec3 tmp1(s_val1[0], s_val1[1], s_val1[2]);
	vec3 tmp2(s_val2[0], s_val2[1], s_val2[2]);
	v1 = tmp1;
	v1_n = normalize(tmp1);
	v2 = tmp2;
	v2_n = normalize(tmp2);
	vdist = tmp2 - tmp1;
	vdist_n = normalize(vdist);
	dist_val = distance(tmp1, tmp2);
	dot_val = dot(tmp1, tmp2);
	dot_val_n = normalizeDot(tmp1, tmp2);
	vcross = cross(tmp1, tmp2);
	vcross_n = normalize(vcross);
	vec3 tmp3 = (vcross + add) * mul / div - sub;
	v3 = tmp3;
	v3_n = normalize(tmp3);
}

// End of file

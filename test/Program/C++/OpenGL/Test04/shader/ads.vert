#version 400

layout (location = 0) in vec3 VertexPosition;
layout (location = 1) in vec3 VertexNormal;
layout (location = 2) in vec4 VertexColor;

out vec3 LightIntensity;
out vec4 Color;

uniform vec4 LightPosition; //視点位置ライト情報
uniform vec3 Kd;            //ディフューズ反射率
uniform vec3 Ld;            //光度の強度

uniform mat4 ModelViewMatrix;
uniform mat3 NormalMatrix;
uniform mat4 ProjectionMatrix;
uniform mat4 MVP;              //投影 * モデルビュー

void main()
{
	//法線と位置を視覚座標に変換
	vec3 tnorm = normalize(NormalMatrix * VertexNormal);
	vec4 eyeCoords = ModelViewMatrix * vec4(VertexPosition, 1.0);
	vec3 s = normalize(vec3(LightPosition - eyeCoords));
	
	//ディフューズ シェーディング方程式
	LightIntensity = Ld * Kd * max(dot(s, tnorm), 0.0);
	
	//位置をクリップ座標に変換して後に渡す
	gl_Position = MVP * vec4(VertexPosition, 1.0);
	
	//カラー
	Color = VertexColor;
}

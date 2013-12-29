//【参考】
//・OpenGL 4.0 シェーディング言語 実例で覚えるGLSLプログラミング : http://www.borndigital.co.jp/book/support/2994.html
//【依存ライブラリ】
//・GLEW ... The OpenGL Extension Wrangler Library : http://glew.sourceforge.net/
//・GLUT ... The OpenGL Utility Toolkit : http://www.opengl.org/resources/libraries/
//・GLM  ... OpenGL Mathematics : http://glm.g-truc.net/0.9.4/index.html
//【各プロジェクト共通のVC++ディレクトリ設定方法（Visual C++ 2010以降）】
//それぞれのライブラリをダウンロードし、所定の配置場所を決めて配置した後、下記の設定を変更してパスを通す。
//  [表示]→[その他のウインドウ]→[プロパティマネージャ]
//    →[(プロジェクト名)]→[(ターゲット/プラットフォーム)]→[Microsoft.Cpp.(target).user]
//        →（右クリック）→[プロパティ]
//            →[共通プロパティ]→[VC++ディレクトリ]
//                →（「インクルードディレクトリ」と「ライブラリディレクトリ」にパスを追加する。）
//                   ※更に、GLUTのDLLは、C:\Windows\SysWOW64\ に配置するなどする。

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform2.hpp>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

const char* TITLE = "OpenGL GLSL4.0 Test 02";

#define SHADER_SOURCE_BASE_PATH "E:\\Work\\GitHub\\public\\test\\Program\\C++\\OpenGL_Test02\\shader\\"

#define countof(array) (sizeof(array) / sizeof(array[0]))

const GLint INVALID_LOC = 0xffffffff;

const GLint ATTRLOC_VERTEX_POSITION = 0;
const GLint ATTRLOC_VERTEX_TEXCOORD = 1;
const GLint ATTRLOC_VERTEX_NUM = 2;

const GLint FRAGLOC_COLOR = 0;
const GLint FRAGLOC_NUM = 1;

GLuint g_program_handle = 0;
int g_window_handle = 0;

const GLint UNIFORM_BLOCK_INNER_COLOR = 0;
const GLint UNIFORM_BLOCK_OUTER_COLOR = 1;
const GLint UNIFORM_BLOCK_RADIUS_INNER = 2;
const GLint UNIFORM_BLOCK_RADIUS_OUTER = 3;
const GLint UNIFORM_BLOCK_NUM = 4;

GLuint g_UNIFORMLOC_BLOCK = INVALID_LOC;
GLubyte* g_UNIFORM_BLOCK_BUFF = NULL;
GLint g_UNIFORM_BLOCK_SIZE = 0;
GLint g_UNIFORM_BLOCK_OFFSET[UNIFORM_BLOCK_NUM];
GLuint g_UNIFORM_HANDLE = 0;

float angle = 0.f;

const float PI = 3.1415926f;

const float RAD = PI;
const float RAD_2 = RAD * 2.f;
const float RAD_HALF = RAD / 2.f;

const float DEG = 180.f;
const float DEG_2 = DEG * 2.f;
const float DEG_HALF = DEG / 2.f;

const float DEG_PAR_RAD = RAD / DEG;
const float RAD_PAR_DEG = DEG / RAD;

inline float DegToRad(const float deg)
{
	return deg * DEG_PAR_RAD;
}
inline float RadToDeg(const float rad)
{
	return rad * RAD_PAR_DEG;
}
inline float limitAngleRad_fast(const float rad)
{
	return rad > RAD ? rad - RAD_2 : rad < -RAD ? rad + RAD_2 : rad;
}
inline float limitAngleRad2_fast(const float rad)
{
	return rad > RAD_2 ? rad - RAD_2 : rad < 0.f ? rad + RAD_2 : rad;
}
float limitAngleRad(const float rad)
{
	if (rad > RAD)
		return limitAngleRad(rad - RAD_2);
	else if (rad < -RAD)
		return limitAngleRad(rad + RAD_2);
	return rad;
}
float limitAngleRad2(const float rad)
{
	if (rad > RAD_2)
		return limitAngleRad2(rad - RAD_2);
	else if (rad < 0.f)
		return limitAngleRad2(rad + RAD_2);
	return rad;
}
inline float limitAngleDeg_fast(const float deg)
{
	return deg > DEG ? deg - DEG_2 : deg < -DEG ? deg + DEG_2 : deg;
}
inline float limitAngleDeg2_fast(const float deg)
{
	return deg > DEG_2 ? deg - DEG_2 : deg < 0.f ? deg + DEG_2 : deg;
}
float limitAngleDeg(const float deg)
{
	if (deg > DEG)
		return limitAngleDeg(deg - DEG_2);
	else if (deg < -DEG)
		return limitAngleDeg(deg + DEG_2);
	return deg;
}
float limitAngleDeg2(const float deg)
{
	if (deg > DEG_2)
		return limitAngleDeg2(deg - DEG_2);
	else if (deg < 0.f)
		return limitAngleDeg2(deg + DEG_2);
	return deg;
}

void drawGLUT()
{
	glUseProgram(g_program_handle);
	
	const float position_data[][3] = {
		{ -0.8f, -0.8f, 0.f },
		{ -0.8f, 0.8f, 0.f },
		{ 0.8f, -0.8f, 0.f },
		{ 0.8f, 0.8f, 0.f },
		{ -0.8f, 0.8f, 0.f },
		{ 0.8f, -0.8f, 0.f }
	};
	const float texcoord_data[][3] = {
		{ 0.f, 0.f, 0.f },
		{ 0.f, 1.f, 0.f },
		{ 1.f, 0.f, 0.f },
		{ 1.f, 1.f, 0.f },
		{ 0.f, 1.f, 0.f },
		{ 1.f, 0.f, 0.f }
	};

	GLuint vao_handles[ATTRLOC_VERTEX_NUM];
	glGenBuffers(ATTRLOC_VERTEX_NUM, vao_handles);
	const GLuint position_buffer_handle = vao_handles[ATTRLOC_VERTEX_POSITION];
	const GLuint texcoord_buffer_handle = vao_handles[ATTRLOC_VERTEX_TEXCOORD];
	glBindBuffer(GL_ARRAY_BUFFER, position_buffer_handle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(position_data), position_data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, texcoord_buffer_handle);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texcoord_data), texcoord_data, GL_STATIC_DRAW);

	GLuint vao_handle;
	glGenVertexArrays(1, &vao_handle);
	glBindVertexArray(vao_handle);

	glEnableVertexAttribArray(ATTRLOC_VERTEX_POSITION);
	glBindBuffer(GL_ARRAY_BUFFER, position_buffer_handle);
	glVertexAttribPointer(ATTRLOC_VERTEX_POSITION, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<GLubyte*>(NULL));

	glEnableVertexAttribArray(ATTRLOC_VERTEX_TEXCOORD);
	glBindBuffer(GL_ARRAY_BUFFER, texcoord_buffer_handle);
	glVertexAttribPointer(ATTRLOC_VERTEX_TEXCOORD, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<GLubyte*>(NULL));

//	g_UNIFORMLOC_BLOCK = glGetUniformLocation(g_program_handle, "BlobSettings");
	if (g_UNIFORMLOC_BLOCK != INVALID_LOC && g_UNIFORM_BLOCK_BUFF > 0)
	{
		const GLfloat inner_color[] = { 1.f, 1.f, 0.75f, 1.f };
		const GLfloat outer_color[] = { 0.f, 0.f, 0.f, 0.f };
		const GLfloat radius_inner = 0.25f;
		const GLfloat radius_outer = 0.45f;
		memcpy(g_UNIFORM_BLOCK_BUFF + g_UNIFORM_BLOCK_OFFSET[UNIFORM_BLOCK_INNER_COLOR], inner_color, 4 * sizeof(GLfloat));
		memcpy(g_UNIFORM_BLOCK_BUFF + g_UNIFORM_BLOCK_OFFSET[UNIFORM_BLOCK_OUTER_COLOR], outer_color, 4 * sizeof(GLfloat));
		memcpy(g_UNIFORM_BLOCK_BUFF + g_UNIFORM_BLOCK_OFFSET[UNIFORM_BLOCK_RADIUS_INNER], &radius_inner, sizeof(GLfloat));
		memcpy(g_UNIFORM_BLOCK_BUFF + g_UNIFORM_BLOCK_OFFSET[UNIFORM_BLOCK_RADIUS_OUTER], &radius_outer, sizeof(GLfloat));
		glBufferData(GL_UNIFORM_BUFFER, g_UNIFORM_BLOCK_SIZE, g_UNIFORM_BLOCK_BUFF, GL_DYNAMIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, g_UNIFORMLOC_BLOCK, g_UNIFORM_HANDLE);
	}

	glBindVertexArray(vao_handle);
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
//	glEnable(GL_DEPTH_TEST);
	
	glDrawArrays(GL_TRIANGLES, 0, countof(position_data));
}
void displayGLUT()
{
	if (glutGetWindow() != g_window_handle){ return; }
	glClearColor(0.f, 0.5f, 0.5f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	drawGLUT();
	glutSwapBuffers();
}
void idleGLUT()
{
	glutSetWindow(g_window_handle);
	glutPostRedisplay();
}
void setupGLUTFunctions()
{
	glutDisplayFunc(displayGLUT);
	glutIdleFunc(idleGLUT);
}

void initGLUT(const int argc, const char* argv[])
{
	glutInit(const_cast<int*>(&argc), const_cast<char**>(argv));
}

void createGLUTWindow()
{
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(512, 512);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	g_window_handle = glutCreateWindow(TITLE);
}

void mainloopGLUT()
{
	glutMainLoop();
}

GLenum initGLEW()
{
	const GLenum result = glewInit();
	if (result != GLEW_OK)
	{
		fprintf(stderr, "Initialize GLEW error!: %s\n", glewGetErrorString(result));
		return result;
	}
	return result;
}

void printGLEWInfo()
{
	const GLubyte* gl_version = glGetString(GL_VERSION);
	GLint gl_version_major;
	GLint gl_version_minor;
	glGetIntegerv(GL_MAJOR_VERSION, &gl_version_major);
	glGetIntegerv(GL_MINOR_VERSION, &gl_version_minor);
	const GLubyte* gl_renderer = glGetString(GL_RENDERER);
	const GLubyte* gl_vendor = glGetString(GL_VENDOR);
	const GLubyte* gl_shading_language_version = glGetString(GL_SHADING_LANGUAGE_VERSION);
	const GLubyte* gl_extensions = glewGetString(GL_EXTENSIONS);
	GLint gl_num_extensions;
	glGetIntegerv(GL_NUM_EXTENSIONS, &gl_num_extensions);
	const GLubyte* glew_version = glewGetString(GLEW_VERSION);

	printf("GL Version: %s\n", gl_version);
	printf("GL Major Version: %d\n", gl_version_major);
	printf("GL Minor Version: %d\n", gl_version_minor);
	printf("GL Renderer: %s\n", gl_renderer);
	printf("GL Vendor: %s\n", gl_vendor);
	printf("GL Shading Language Version: %s\n", gl_shading_language_version);
	printf("GL Extensions: %s\n", gl_extensions);
	printf("GL Extensions: \n");
	for (GLint index = 0; index < gl_num_extensions; ++index)
	{
		printf("  [%d]: %s\n", index, glGetStringi(GL_EXTENSIONS, index));
	}
	printf("GLEW Version: %s\n", glew_version);
}

bool checkGLEWFunctions()
{
	if (!GLEW_VERSION_1_2)
	{
		printf("Not support GLEW Version: 1.2\n");
	//	return false;
	}
	if (!GLEW_VERSION_1_3)
	{
		printf("Not support GLEW Version: 1.3\n");
	//	return false;
	}
	if (!GLEW_VERSION_1_4)
	{
		printf("Not support GLEW Version: 1.4\n");
	//	return false;
	}
	if (!GLEW_ARB_vertex_program)
	{
		fprintf(stderr, "Not support GLEW extension: ARB_vertex_program\n");
		return false;
	}
	if (!GLEW_ARB_fragment_program)
	{
		fprintf(stderr, "Not support GLEW extension: ARB_fragment_program\n");
		return false;
	}
	return true;
}

const GLchar* loadShaderAsString(const char* file_path)
{
	FILE* fp = NULL;
	fopen_s(&fp, file_path, "rb");
	if (!fp)
	{
		fprintf(stderr, "Shader file cannot open or not exist!: %s\n", file_path);
		return NULL;
	}
	fseek(fp, 0, SEEK_END);
	const long file_size = ftell(fp);
	if (file_size <= 0)
	{
		fprintf(stderr, "Shader file is empty!: %s\n", file_path);
		return NULL;
	}
	fseek(fp, 0, SEEK_SET);
	GLchar* mem = new GLchar[file_size + 1];
	if (!mem)
	{
		fprintf(stderr, "Cannot allocate shader source's memory!: %s\n", file_path);
		return NULL;
	}
	const size_t end_pos = fread(mem, 1, file_size, fp);
	fclose(fp);
	mem[end_pos] = '\0';
	return mem;
}

GLint getShaderResult(const GLint program, const GLint status)
{
	GLint result;
	glGetShaderiv(program, status, &result);
	if (result == GL_FALSE)
	{
		fprintf(stderr, "Shader compile error!\n");
		GLint log_len;
		glGetShaderiv(program, GL_INFO_LOG_LENGTH, &log_len);
		if (log_len > 0)
		{
			char* log = new char[log_len];
			if (log)
			{
				GLsizei written_len;
				glGetShaderInfoLog(program, log_len, &written_len, log);
				fprintf(stderr, "  %s\n", log);
				delete log;
				log = NULL;
			}
		}
	}
	return result;
}

GLuint createVertexShader()
{
	GLuint shader_handle = glCreateShader(GL_VERTEX_SHADER);
	if (shader_handle == 0)
	{
		fprintf(stderr, "Vertex shader create error!\n");
		return 0;
	}
	return shader_handle;
}

GLuint createFragmentShader()
{
	GLuint shader_handle = glCreateShader(GL_FRAGMENT_SHADER);
	if (shader_handle == 0)
	{
		fprintf(stderr, "Fragment shader create error!\n");
		return 0;
	}
	return shader_handle;
}

GLuint createShaderProgram()
{
	const GLuint program_handle = glCreateProgram();
	if (program_handle == 0)
	{
		fprintf(stderr, "Shader program create error!\n");
		return 0;
	}
	return program_handle;
}

const GLchar** loadShaderSource(const int shader_source_file_num, const char* shader_source_file_path_list[])
{
	const GLchar** shader_source_file_list = new const GLchar*[shader_source_file_num];
	if (!shader_source_file_list)
	{
		fprintf(stderr, "Shader source file list make error!(%d)\n", shader_source_file_num);
		return NULL;
	}
	for (int shader_source_file_index = 0; shader_source_file_index < shader_source_file_num; ++shader_source_file_index)
	{
		const char* shader_source_file_path = shader_source_file_path_list[shader_source_file_index];
		const GLchar* shader_source_file = NULL;
		if (shader_source_file_path)
		{
			shader_source_file = loadShaderAsString(shader_source_file_path);
			if (!shader_source_file)
			{
				fprintf(stderr, "Shader program load error!(%d): %s\n", shader_source_file_index, shader_source_file_path);
			}
		}
		shader_source_file_list[shader_source_file_index] = shader_source_file;
	}
	return shader_source_file_list;
}

bool freeShaderSource(const int shader_source_file_num, const GLchar* shader_source_file_list[])
{
	if (!shader_source_file_list)
	{
		return false;
	}
	for (int shader_source_file_index = 0; shader_source_file_index < shader_source_file_num; ++shader_source_file_index)
	{
		const GLchar* shader_source_file = shader_source_file_list[shader_source_file_index];
		if (shader_source_file)
		{
			delete const_cast<GLchar*>(shader_source_file);
			shader_source_file_list[shader_source_file_index] = NULL;
		}
	}
	delete shader_source_file_list;
	return true;
}

GLuint createAndLoadVertexShaderAll()
{
	const GLuint shader_handle = createVertexShader();
	if (shader_handle == 0){ return 0; }
	{
		const char* shader_source_file_path_list[] = {
			SHADER_SOURCE_BASE_PATH "basic.vert"
		};
		const int shader_source_file_num = countof(shader_source_file_path_list);
		const GLchar** shader_source_file_list = loadShaderSource(shader_source_file_num, shader_source_file_path_list);
		if (shader_source_file_list)
		{
			glShaderSource(shader_handle, shader_source_file_num, shader_source_file_list, NULL);
			freeShaderSource(shader_source_file_num, shader_source_file_list);
			shader_source_file_list = NULL;
		}
	}
	{
		glCompileShader(shader_handle);
		{
			const GLint shader_compile_result = getShaderResult(shader_handle, GL_COMPILE_STATUS);
			if (shader_compile_result == GL_FALSE){ return 0; }
		}
	}
	return shader_handle;
}

GLuint createAndLoadFragmentShaderAll()
{
	const GLuint shader_handle = createFragmentShader();
	if (shader_handle == 0){ return 0; }
	{
		const char* shader_source_file_path_list[] = {
			SHADER_SOURCE_BASE_PATH "circle.frag"
		};
		const int shader_source_file_num = countof(shader_source_file_path_list);
		const GLchar** shader_source_file_list = loadShaderSource(shader_source_file_num, shader_source_file_path_list);
		if (shader_source_file_list)
		{
			glShaderSource(shader_handle, shader_source_file_num, shader_source_file_list, NULL);
			freeShaderSource(shader_source_file_num, shader_source_file_list);
			shader_source_file_list = NULL;
		}
	}
	{
		glCompileShader(shader_handle);
		{
			const GLint shader_compile_result = getShaderResult(shader_handle, GL_COMPILE_STATUS);
			if (shader_compile_result == GL_FALSE){ return 0; }
		}
	}
	return shader_handle;
}

GLuint createAndLinkShaderProgram(const GLuint vertex_shader_handle, const GLuint fragment_shader_handle)
{
	const GLuint program_handle  = createShaderProgram();
	if (program_handle == 0){ return 0; }
	
	glAttachShader(program_handle, vertex_shader_handle);
	glAttachShader(program_handle, fragment_shader_handle);

	glBindAttribLocation(program_handle, ATTRLOC_VERTEX_POSITION, "VertexPosition");
	glBindAttribLocation(program_handle, ATTRLOC_VERTEX_TEXCOORD, "TexCoord");

	glBindFragDataLocation(program_handle, FRAGLOC_COLOR, "FragColor");

	glLinkProgram(program_handle);
	{
		const GLint shader_link_result = getShaderResult(program_handle, GL_LINK_STATUS);
		if (shader_link_result == GL_FALSE){ return 0; }
	}
	
	g_UNIFORMLOC_BLOCK = glGetUniformBlockIndex(program_handle, "BlobSettings");
	if (g_UNIFORMLOC_BLOCK != INVALID_LOC)
	{
		glGetActiveUniformBlockiv(program_handle, g_UNIFORMLOC_BLOCK, GL_UNIFORM_BLOCK_DATA_SIZE, &g_UNIFORM_BLOCK_SIZE);
		if (g_UNIFORM_BLOCK_SIZE > 0)
		{
			g_UNIFORM_BLOCK_BUFF = new GLubyte[g_UNIFORM_BLOCK_SIZE];
			const GLchar* names[] = { "InnerColor", "OuterColor", "RadiusInner", "RadiusOuter" };
			const GLint name_num = countof(names);
			GLuint indices[name_num];
			glGetUniformIndices(program_handle, name_num, names, indices);
			glGetActiveUniformsiv(program_handle, name_num, indices, GL_UNIFORM_OFFSET, g_UNIFORM_BLOCK_OFFSET);
			
			glGenBuffers(1, &g_UNIFORM_HANDLE);
			glBindBuffer(GL_UNIFORM_BUFFER, g_UNIFORM_HANDLE);
		}
	}

	return program_handle;
}

bool printActiveAttribInfo(const GLuint program_handle)
{
	GLint attr_num, attr_name_len_max;
	glGetProgramiv(program_handle, GL_ACTIVE_ATTRIBUTES, &attr_num);
	glGetProgramiv(program_handle, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &attr_name_len_max);
	GLchar* attr_name = new GLchar[attr_name_len_max];
	if (!attr_name){ return false; }
	printf("<Active Attribute(s) : num=%d>\n", attr_num);
	printf("------------------------------------------------------------\n");
	for (GLint attr_index = 0; attr_index < attr_num; ++attr_index)
	{
		GLint attr_name_len, attr_size;
		GLenum attr_type;
		glGetActiveAttrib(program_handle, attr_index, attr_name_len_max, &attr_name_len, &attr_size, &attr_type, attr_name);
		printf("%3d: \"%s\" len=%d, size=%d, type=%04xh\n", attr_index, attr_name, attr_name_len, attr_size, attr_type);
	}
	printf("------------------------------------------------------------\n");
	delete attr_name;
	attr_name = NULL;
	return true;
}

bool printActiveUniformInfo(const GLuint program_handle)
{
	GLint uniform_num, uniform_name_len_max;
	glGetProgramiv(program_handle, GL_ACTIVE_UNIFORMS, &uniform_num);
	glGetProgramiv(program_handle, GL_ACTIVE_UNIFORM_MAX_LENGTH, &uniform_name_len_max);
	GLchar* uniform_name = new GLchar[uniform_name_len_max];
	if (!uniform_name){ return false; }
	printf("<Active Uniform(s) : num=%d>\n", uniform_num);
	printf("------------------------------------------------------------\n");
	for (GLint uniform_index = 0; uniform_index < uniform_num; ++uniform_index)
	{
		GLint uniform_name_len, uniform_size;
		GLenum uniform_type;
		glGetActiveUniform(program_handle, uniform_index, uniform_name_len_max, &uniform_name_len, &uniform_size, &uniform_type, uniform_name);
		printf("%3d: \"%s\" len=%d, size=%d, type=%04xh\n", uniform_index, uniform_name, uniform_name_len, uniform_size, uniform_type);
	}
	printf("------------------------------------------------------------\n");
	delete uniform_name;
	uniform_name = NULL;
	return true;
}

void testGLM()
{
	glm::vec4 position = glm::vec4(1.f, 0.f, 0.f, 1.f);
	glm::mat4 view = glm::lookAt(glm::vec3(0.f, 0.f, 5.f), glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.f, 1.f, 0.f));
	glm::mat4 model = glm::mat4(1.f);
	model = glm::rotate(model, 90.f, glm::vec3(0.f, 1.f, 0.f));
	glm::mat4 mv = view * model;
	glm::vec4 transformed = mv * position;
}

void  abort_program()
{
//	abort();
	exit(-1);
}

int main(const int argc, const char* argv[])
{
	printf("<< %s >>\n", TITLE);

	//GLU initialize
	{
		initGLUT(argc, argv);
		createGLUTWindow();
	}

	//GLEW initialize
	{
		const GLenum result = initGLEW();
		if (result != GLEW_OK){ abort_program(); return EXIT_FAILURE; }
	}
	{
		printGLEWInfo();
		const bool result = checkGLEWFunctions();
		if (!result){ abort_program(); return EXIT_FAILURE; }
	}

	//Shader initialize
	const GLuint vertex_shader_handle = createAndLoadVertexShaderAll();
	if (!vertex_shader_handle){ abort_program(); return EXIT_FAILURE; }
	const GLuint fragment_shader_handle = createAndLoadFragmentShaderAll();
	if (!fragment_shader_handle){ abort_program(); return EXIT_FAILURE; }
	const GLuint program_handle = createAndLinkShaderProgram(vertex_shader_handle, fragment_shader_handle);
	g_program_handle = program_handle;

	printActiveAttribInfo(program_handle);
	printActiveUniformInfo(program_handle);
	
	//GLM test
	testGLM();

	//Main loop
	setupGLUTFunctions();
	mainloopGLUT();

	return EXIT_SUCCESS;
}

// End of file

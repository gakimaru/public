#include <stdio.h>
#include <stdlib.h>

#include <algorithm>//std::min�p

//--------------------------------------------------------------------------------
//�t�F�[�h�����N���X
//�����`���
class linear_fade
{
public:
	//�A�N�Z�b�T
	inline float begin() const { return m_begin; }//�J�n�l
	inline float end() const { return m_end; }//�I���l
	inline float difference() const { return m_end - m_begin; }//��
	inline float time() const { return m_time; }//����
	inline float gradient() const { return difference() / m_time; }//�X��
	inline float t() const { return m_t; }//�i�s�x
	inline float remain_t() const { return 1.f - m_t; }//�i�s�x�̎c��
	inline float progress_time() const { return m_time * m_t; }//�i�s����
	inline float remain_time() const { return m_time * (1.f - m_t); }//�i�s���Ԃ̎c��
	inline float now() const { return m_now; }//���ݒl
	bool isGoal() const { return m_t == 1.f; }//�S�[���ɒB���Ă��邩�H

public:
	//���\�b�h

	//�X�V����
	void update(const float elapsed_time)
	{
		if (!isGoal())
		{
			const float now_time = m_time * m_t + elapsed_time;//���Ԃ�i�߂�
			m_t = std::min(now_time / m_time, 1.f);//�i�s�x���Z�o
			m_now = m_begin * (1.f - m_t) + m_end * m_t;//���݂̒l���X�V�i���`��ԁj
		}
	}
	//�t�F�[�h�J�n
	void start(const float time, const float begin, const float end)
	{
		m_begin = begin;
		m_end = end;
		m_time = time;
		adjust();
	}
	//���ݒl�������ύX
	void setNow(const float now)
	{
		m_now = now;
		adjust();
	}
private:
	//���ݒl�Ɋ�Â��Đi�s�x���t�Z�E��������
	void adjust()
	{
		if (m_begin == m_end || m_now == m_end)
		{
			m_t = 1.f;
			m_now = m_end;
		}
		else if (m_now == m_begin)
			m_t = 0.f;
		else
		{
			m_t = (m_now - m_begin) / (m_end - m_begin);//���`��Ԃ̋t�Z
			//�v�Z���ʂ̒���
			if (m_t < 0.f)
			{
				m_t = 0.f;
				m_now = m_begin;
			}
			else if (m_t > 1.f)
			{
				m_t = 1.f;
				m_now = m_end;
			}
		}
	}
public:
	//���݂̏�Ԃ�\��
	void debugPrint(const int flame)
	{
		//printf("%2d: now=%.3f, begin=%.3f, end=%.3f, diff=%.3f, time=%.3f, gradient=%.3f, t=%.3f, remain_t=%.3f, progress_time=%.3f, remain_time=%.3f, isGoal()=%s\n", flame, now(), begin(), end(), difference(), time(), gradient(), t(), remain_t(), progress_time(), remain_time(), isGoal() ? "true" : "false");
		printf("%2d: now=%.3f, begin=%.3f, end=%.3f, time=%.3f, t=%.3f, isGoal()=%s\n", flame, now(), begin(), end(), time(), t(), isGoal() ? "true" : "false");
	}
public:
	//�R���X�g���N�^
	linear_fade(const float now = 0.f) :
		m_begin(0.f),
		m_end(0.f),
		m_time(0.f),
		m_t(0.f),
		m_now(now)
	{}
private:
	//�t�B�[���h
	float m_begin;//�J�n�l
	float m_end;//�I���l
	float m_time;//����
	float m_t;//�i�s�x�i�i�s���ԁj
	float m_now;//���݂̏��
};

//�e�X�g
void test()
{
	const float fps = 30.f;//30fps�z��
	const float elapsed_time = 1.f / fps;//1�t���[��������̐i�s����
	printf("frames per second = %.0f, elapsed time per frame = %.3f\n", fps, elapsed_time);
	int flame = 0;

	//�t�F�[�h�I�u�W�F�N�g��������
	linear_fade fade(1.f);//�����l��1.f

	//�t�F�[�h�J�n
	fade.start(1.5f, 1.f, 0.5f);//1.5�b�����āA�ő�(1.0�j���甼���i0.5�j�܂Ńt�F�[�h
	
	//20�t���[�������X�V
	for (int i = 0; i < 20; ++i)
	{
		fade.debugPrint(flame++);
		fade.update(elapsed_time);//�X�V����
	}

	//�t�F�[�h��r���ύX
	fade.start(1.5f, 0.5f, 1.f);//1.5�b�����āA�����i0.5�j����ő�(1.0�j�܂Ńt�F�[�h

	//�t�F�[�h�����܂ōX�V
	while (!fade.isGoal())
	{
		fade.debugPrint(flame++);
		fade.update(elapsed_time);//�X�V����
	}
	fade.debugPrint(flame);
}

//--------------------------------------------------------------------------------
//�e�X�g
int main(const int argc, const char* argv[])
{
	test();

	return EXIT_SUCCESS;
}

// End of file

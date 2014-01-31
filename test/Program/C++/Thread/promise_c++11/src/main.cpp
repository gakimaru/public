#include <stdio.h>
#include <stdlib.h>

#include <future>
#include <thread>
#include <chrono>

//���ʕ\���X���b�h
void threadFunc(const char* name, std::shared_future<int> value)
{
	printf("%s: [BEFORE]\n", name);
	fflush(stdout);

	printf("%s: [AFTER] value=%d\n", name, value.get());//future::get() �́A���ʂ��i�[�����܂ŏ������u���b�N�����
	fflush(stdout);
}

//�e�X�g
int main(const int argc, const char* argv)
{
	//�����J�n
	printf("main: [START]\n");
	fflush(stdout);

	//�敨�ϐ��̗p��
	//����Œl���i�[����ϐ�
	std::promise<int> p_val;

	//���ʑҋ@�I�u�W�F�N�g��p��
	//���敨�ϐ���񓯊��֐��̌��ʂ�ҋ@����I�u�W�F�N�g�B
	//�����ʂ��󂯎�鑤���X���b�h�̏ꍇ�Ashared_future�N���X���g�p�B
	std::shared_future<int> f_val = p_val.get_future().share();

	//�X���b�h����
	static const char* names[] = { "���Y", "���Y", "�O�Y" };
	for(auto name : names)
	{
		//�X���b�h����
		std::thread th = std::thread(threadFunc, name, f_val);
			
		//�X���b�h�̊�����҂��Ȃ��̂ŁA�؂藣���Ă���
		th.detach();
	}

	//1�b�X���[�v
	printf("main: [sleep ...]\n");
	fflush(stdout);
	std::this_thread::sleep_for(std::chrono::seconds(1));

	//�l���i�[
	//�����̎��A�X���b�h���� future::get() ����������
	printf("main: [set_value()]\n");
	fflush(stdout);
	p_val.set_value(123);

	//1�~���b�X���[�v
	std::this_thread::sleep_for(std::chrono::milliseconds(1));

	//�����I��
	printf("main: [END]\n");
	fflush(stdout);
	
	return EXIT_SUCCESS;
}

// End of file

#include <stdio.h>
#include <stdlib.h>

#include <thread>
#include <mutex>

#include <chrono> //���Ԍv���p

//�X���b�h
void threadFunc(const char* name)
{
	//�J�n
	printf("- begin:%s -\n", name);
	fflush(stdout);

	//CallOnce����p�ϐ�
	static std::once_flag s_onceFlag;
	
	//CallOnce����
	std::call_once(s_onceFlag, [&name]()
		{
			//�����_���Œ��ڋL�q
			
			//CallOnce�����J�n
			printf("CallOnce�����F��������(by %s)...\n", name);
			fflush(stdout);

			//1�b�X���[�v
			std::this_thread::sleep_for(std::chrono::seconds(1));

			//CallOnce�����I��
			printf("CallOnce�����F�I��\n");
			fflush(stdout);
		}
	);

	//�I��
	printf("- end:%s -\n", name);
	fflush(stdout);
}

//�e�X�g
int main(const int argc, const char* argv[])
{
	//�X���b�h�쐬
	std::thread thread_obj1 = std::thread(threadFunc, "���Y");
	std::thread thread_obj2 = std::thread(threadFunc, "���Y");
	std::thread thread_obj3 = std::thread(threadFunc, "�O�Y");
	
	//�X���b�h�I���҂�
	thread_obj1.join();
	thread_obj2.join();
	thread_obj3.join();

	return EXIT_SUCCESS;
}

// End of file

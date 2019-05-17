#include <iostream>
#include <time.h>
#include <thread> //Ϊ���ñ�����ʶ��std::thread�࣬��Ҫ����<thread>ͷ�ļ�

void do_some_work() { std::cout << "do something work." << std::endl; }

void do_something() { std::cout << "do something." << std::endl; }
void do_something_else() { std::cout << "do something else." << std::endl; }
class background_work
{
public:
	void operator()() const
	{
		do_something();
		do_something_else();
	}
};

int main() {
	//ʹ��C++�߳̿������̣߳����Թ��Ϊ����std::thread����
	std::thread my_thread1(do_some_work); 

	//std::thread�������ÿɵ��ã�callable�����͹��죬�����к������÷����͵�ʵ������std::thread���У��滻Ĭ�ϵĹ��캯����
	background_work f; //����һ��background_work��Ķ���
	std::thread my_thread2(f); // ��������Ḵ�Ƶ����̵߳Ĵ洢�ռ䵱�У����������ִ�к͵��ö����̵߳��ڴ�ռ��н���

	my_thread1.join();
	my_thread2.join();
	system("pause");
}
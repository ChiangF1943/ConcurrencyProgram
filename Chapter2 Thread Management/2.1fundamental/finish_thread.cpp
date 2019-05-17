#include <iostream>
#include <windows.h>
#include <thread>

void do_some_work()
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "thread1: do some work." << std::endl;
		Sleep(1000);
	}
}

void do_something() { std::cout << "thread2: do something." << std::endl; }
class background_work
{
public:
	background_work(int i):i_(i) {}
	void operator()() const
	{
		do_something();
	}
	int i_;
};

int main() {
	std::thread my_thread1(do_some_work);

	background_work f(3);
	std::thread my_thread2(f);

	/* join()�򵥴ֱ��صȴ��߳���ɻ��߲��ȴ�������join()�����������߳���صĴ洢���֣����std::thread���󽫲���������ɵ��߳����κι���
	*  ����ζ�ţ�ֻ�ܶ�һ���߳�ʹ��һ��join()��ʹ��һ��֮����ʹ��joinable()������false��
	*/
	my_thread1.join(); //ȷ���ֲ����������߳����֮�󣬲ű�����
	my_thread2.join();

	/* detach()�����߳�����֮����ԭ�̷߳��롣���ԭ�߳̽���֮�����߳̿��ܻ������У����ں�̨���С�
	* �̷߳���֮�󣬾Ͳ�������std::thread�����������������Ҳ�Ͳ��ܱ�join()��
	* ����C++���пⱣ֤�����߳��˳�ʱ���������Դ�ܱ���ȷ���ա�
	*/
	//my_thread1.detach();
	//my_thread2.detach();

	Sleep(500);
	std::cout << "The end." << std::endl;
	/* ͨ�������̳߳�Ϊ�ػ��̣߳�daemon threads������UNIX���ػ��߳���ָ��û���κ��û��ӿڡ��ں�̨���е��̡߳�
	*  �����̵߳��ص��ǳ�ʱ�����У��������ڴ�ĳһӦ����ʼ��������
	*/
	system("pause");
}
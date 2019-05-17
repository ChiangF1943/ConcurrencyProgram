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

	/* join()简单粗暴地等待线程完成或者不等待。调用join()，还清理了线程相关的存储部分，因此std::thread对象将不再与已完成的线程有任何关联
	*  这意味着，只能对一个线程使用一次join()。使用一次之后，再使用joinable()将返回false。
	*/
	my_thread1.join(); //确保局部变量在新线程完成之后，才被销毁
	my_thread2.join();

	/* detach()在新线程启动之后，与原线程分离。因此原线程结束之后，新线程可能还在运行，且在后台运行。
	* 线程分离之后，就不可能有std::thread对象能引用它，因此也就不能被join()。
	* 不过C++运行库保证，当线程退出时，其相关资源能被正确回收。
	*/
	//my_thread1.detach();
	//my_thread2.detach();

	Sleep(500);
	std::cout << "The end." << std::endl;
	/* 通常分离线程称为守护线程（daemon threads）。在UNIX中守护线程是指，没有任何用户接口、在后台运行的线程。
	*  这种线程的特点是长时间运行，生命周期从某一应用起始到结束。
	*/
	system("pause");
}
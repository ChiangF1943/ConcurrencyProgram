#include <iostream>
#include <time.h>
#include <thread> //为了让编译器识别std::thread类，需要包含<thread>头文件

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
	//使用C++线程库启动线程，可以归结为构造std::thread对象
	std::thread my_thread1(do_some_work); 

	//std::thread还可以用可调用（callable）类型构造，将带有函数调用符类型的实例传入std::thread类中，替换默认的构造函数。
	background_work f; //创建一个background_work类的对象
	std::thread my_thread2(f); // 函数对象会复制到新线程的存储空间当中，函数对象的执行和调用都在线程的内存空间中进行

	my_thread1.join();
	my_thread2.join();
	system("pause");
}
#include <iostream>
#include <thread>  // 标准C++库中对多线程支持的声明在新头文件中，其中管理线程的函数和类在<thread>中

void hello()// 新线程始于hello
{
	std::cout << "Hello, Concurrent World" << std::endl;	// 写数据的代码被移动到一个独立的函数中
}

// 每个线程都必须拥有一个初始函数，新线程的执行从初始函数开始。对应用程序初始线程来说，初始函数为main
int main() { // 初始线程始于main
	std::thread t(hello); // std::thread类新建了一个对象t，它的构造函数指定了初始函数hello，并创建了这个新线程
	t.join();	// 初始线程等待与std::thread对象相关联的新线程，即t
	system("pause");
	//return 0;
}
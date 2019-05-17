#include <iostream>
#include <thread>
void some_function() { std::cout << "some function" << std::endl; }
void some_other_function() { std::cout << "some other function" << std::endl; }

int main() {
	std::thread::id idd;
	std::cout << idd << " " << std::this_thread::get_id() << std::endl;
	std::thread t1(some_function);			//1
	std::thread t2 = std::move(t1);			//2 显式创建t2，t1的所有权转移给了t2。之后，t1和执行线程已经没有关联，some_function函数与t2关联
	t1 = std::thread(some_other_function);	//3
	std::thread t3;							//4
	t3 = std::move(t2);						//5 将t2关联线程的所有权转移到t3中，显示的调用std::move()，因为t2是一个命名对象
	t1 = std::move(t3);						//6
	t1.join();
	t2.join();
	t3.join();

}
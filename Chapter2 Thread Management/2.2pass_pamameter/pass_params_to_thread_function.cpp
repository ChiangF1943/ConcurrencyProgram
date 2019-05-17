#include <iostream>
#include <string>
#include <thread>

void f(int i, std::string const& s)
{
	std::cout << i << s << s.size() << std::endl; // 字面值向string类型转化
}

void oops(int some_params)
{
	char buffer[1024];
	//std::cout << some_params << std::endl;
	sprintf_s(buffer, "%x", some_params);
	std::thread t(f, 3, buffer);
	//std::cout << buffer << std::endl;
	t.detach();
}
int main() {
	//oops(125);
	//std::thread t(f, 3, "Hello"); // 代码创建了一个调用f(3, "Hello")的线程，这里"Hello"为字面值，即const char*类型
	system("pause");
}
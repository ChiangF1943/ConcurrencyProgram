#include <iostream>
#include <string>
#include <thread>

void f(int i, std::string const& s)
{
	std::cout << i << s << s.size() << std::endl; // ����ֵ��string����ת��
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
	//std::thread t(f, 3, "Hello"); // ���봴����һ������f(3, "Hello")���̣߳�����"Hello"Ϊ����ֵ����const char*����
	system("pause");
}
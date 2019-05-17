#include <list>
#include <mutex>
#include <algorithm>
using namespace std;

class data_lock {
public:
	void add_to_list(int new_value)
	{
		// C++标准库为互斥量提供了一个RAII语法的模板类std::lack_guard，会在构造的时候提供已锁的互斥量，在析构的时候进行解锁，
		// 从而保证一个已锁的互斥量总是被正确的解锁
		lock_guard<mutex> guard(some_mutex); 
		some_list.push_back(new_value);
	}

	bool list_contains(int value_to_find)
	{
		lock_guard<mutex> guard(some_mutex);
		return find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
	}
private:
	list<int> some_list; // 全局变量some_list，被一个全局的互斥量保护
	mutex some_mutex; // 通过实例化std::mutex创建互斥量，通过调用成员函数lock()上锁，unlock()进行解锁。
};

int main()
{
	data_lock dl;
	dl.add_to_list(1);
	dl.list_contains(2);// 两个函数都使用lock_guard<mutex>，使得这两个函数中对数据的访问是互斥的，list_contains()不可能看到正在被add_to_list()修改的列表。
	system("pause");
}
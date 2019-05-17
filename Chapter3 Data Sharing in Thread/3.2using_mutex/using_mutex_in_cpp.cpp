#include <list>
#include <mutex>
#include <algorithm>
using namespace std;

class data_lock {
public:
	void add_to_list(int new_value)
	{
		// C++��׼��Ϊ�������ṩ��һ��RAII�﷨��ģ����std::lack_guard�����ڹ����ʱ���ṩ�����Ļ���������������ʱ����н�����
		// �Ӷ���֤һ�������Ļ��������Ǳ���ȷ�Ľ���
		lock_guard<mutex> guard(some_mutex); 
		some_list.push_back(new_value);
	}

	bool list_contains(int value_to_find)
	{
		lock_guard<mutex> guard(some_mutex);
		return find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
	}
private:
	list<int> some_list; // ȫ�ֱ���some_list����һ��ȫ�ֵĻ���������
	mutex some_mutex; // ͨ��ʵ����std::mutex������������ͨ�����ó�Ա����lock()������unlock()���н�����
};

int main()
{
	data_lock dl;
	dl.add_to_list(1);
	dl.list_contains(2);// ����������ʹ��lock_guard<mutex>��ʹ�������������ж����ݵķ����ǻ���ģ�list_contains()�����ܿ������ڱ�add_to_list()�޸ĵ��б�
	system("pause");
}
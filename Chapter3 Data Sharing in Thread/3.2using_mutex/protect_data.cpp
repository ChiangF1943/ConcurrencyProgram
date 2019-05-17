#include <iostream>
#include <mutex>
#include <thread>
#include <Windows.h>

std::mutex mtx;

static void print_thread_id(int id)
{
	// std::mutex::lock: The calling thread locks the mutex
	// std::mutex::unlock: Unlocks the mutex, releasing ownership over it.
	// critical section (exclusive access to std::cout signaled by locking mtx):
	mtx.lock();
	std::cout << "thread #" << id << '\n';
	mtx.unlock();
}

int test_mutex_2()
{
	std::thread threads[10];
	// spawn 10 threads:
	for (int i = 0; i < 10; ++i)
		threads[i] = std::thread(print_thread_id, i + 1);

	for (auto& th : threads) th.join();

	return 0;
}

int main()
{
	test_mutex_2();
	system("pause");
}
#include <iostream>
#include <thread>
using namespace std;

// this for helping printed number in thread
static int number;

// single handled thread
void print_odd_thread()
{
	using namespace std::literals::chrono_literals;

	cout << "Thread " << number << " is Working" << std::endl;
	this_thread::sleep_for(1s);
}

void print_even_thread()
{
	using namespace std::literals::chrono_literals;

	std::cout << "Thread " << number << " is Working" << std::endl;
	std::this_thread::sleep_for(2.5s);
}

int main()
{

	// single thread handler
	for (int i = 1; i <= 20; i++)
	{
	number = i ;
		if (i % 2 != 0)
		{
			// thread odd
			std::thread odd(print_odd_thread);
			odd.join(); // join when previous thread done
		}
		else
		{
			// thread even
			std::thread even(print_even_thread);
			even.join(); // join when previous thread done
		}
	}

	std::cout << "Thread Complete..." << std::endl;

	std::cin.get();
	return 0;
}

#include "easyfind.hpp"

void test_vector() {
	std::cout << "Test vector" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try {
		std::cout << "try to find 3 ";
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "try to find 42 ";
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void test_list() {
	std::cout << "Test list" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	try {
		std::cout << "try to find 20 ";
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "try to find -5 ";
		std::list<int>::iterator it = easyfind(lst, -5);
		std::cout << "found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void test_deque() {
	std::cout << "Testing deque" << std::endl;
	std::deque<int> deq;
	deq.push_front(100);
	deq.push_back(200);

	try {
		std::cout << "try to find 100 ";
		std::deque<int>::iterator it = easyfind(deq, 100);
		std::cout << "found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << "try to find 999 ";
		std::deque<int>::iterator it = easyfind(deq, 999);
		std::cout << "found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}


int main() {
	test_vector();
	test_list();
	test_deque();
	return 0;
}

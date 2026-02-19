#include "Span.hpp"

Span::Span() : _N(0) {
	_vec.reserve(0);
}

Span::Span(unsigned int N) : _N(N) {
	_vec.reserve(N);
}

Span::Span(Span const &copy) {
	*this = copy;
}

Span::~Span() {}

Span &Span::operator=(Span const &copy) {
	if (this != &copy) {
		_N = copy._N;
		_vec = copy._vec;
	}
	return *this;
}

void Span::addNumber(int n) {
	try {
		if (_vec.size() >= _N)
			throw SpanFullException();
		_vec.push_back(n);
	} 
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	try {
		size_t distance = std::distance(begin, end);
		if (_vec.size() + distance > _N)
			throw SpanFullException();
		_vec.insert(_vec.end(), begin, end);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

int Span::shortestSpan() {
	if (_vec.size() <= 1)
		throw NotEnoughNumbersException();
	std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++) {
		if (sorted[i] - sorted[i-1] < minSpan) {
			minSpan = sorted[i] - sorted[i-1];
		}
	}
	return minSpan;
}

int Span::longestSpan() {
	if (_vec.size() <= 1)
		throw NotEnoughNumbersException();
	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return max - min;
}

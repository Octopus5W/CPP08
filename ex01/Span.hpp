#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <stdexcept>

class Span {
	private:
		unsigned int _N;
		std::vector<int> _vec;
		
	public:
		Span();
		Span(unsigned int N);
		Span(Span const &copy);
		~Span();
		Span &operator=(Span const &copy);

		void addNumber(int n);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
		
		class SpanFullException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Span is full";
				}
		};
		
		class NotEnoughNumbersException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Not enough numbers in the span";
				}
		};
};


#endif

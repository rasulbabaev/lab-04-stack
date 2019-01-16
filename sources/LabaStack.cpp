#include "pch.h"
#include <iostream>

#include "stack.hpp"

int main()
{
	Stack<int> st;

	st.push(1);
	std::cout << st.head() << std::endl;
	st.push(23);
	std::cout << st.head() << std::endl;
	st.pop();
	std::cout << st.head() << std::endl;
}

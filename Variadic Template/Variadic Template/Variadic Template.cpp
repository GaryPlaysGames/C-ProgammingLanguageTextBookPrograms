// Variadic Template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

template<class T>
void g(const T& head) {
	std::cout << head << " ";
}

void f() {
}

template<class T, class... Tail>
void f (const T& head, const Tail&... tail) {
	g(head);
	f(tail...);
}

int main()
{
	int i;
	f(1);
	std::cin >> i;
    return 0;
}


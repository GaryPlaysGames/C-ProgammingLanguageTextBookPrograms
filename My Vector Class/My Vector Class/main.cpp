#include "stdafx.h"
#include <iostream>
#include "My_Vector.h"

template<class T>
My_Vector<T> test_Copy(const My_Vector<int>& vect, My_Vector<T> copy) {
	return vect;
}

template<class T>
My_Vector<T> test_Move(My_Vector<T> copy) {
	return copy;
}

void testConstructors() {
	My_Vector<int> vect1(1);
	vect1[0] = 1;
	My_Vector<int> vect2 { 1, 2, 3 };

	std::cout << "Test #1: Constructor " << std::endl;
	std::cout << vect1 << std::endl;
	std::cout << "Test #2: Initailzer list Constructor " << std::endl;
	std::cout << vect2 << std::endl;
	std::cout << "Test #3: Copy Constructor " << std::endl;
	std::cout << test_Copy(vect1, vect2) << std::endl;
	std::cout << "Test #4: Copy Assignment Constructor " << std::endl;
	vect1 = vect2;
	std::cout << vect1 << std::endl;
	std::cout << "Test #4: Move Constructor " << std::endl;
	std::cout << test_Move(My_Vector<int> { 1, 2, 3, 4, 5 }) << std::endl;
	std::cout << "Test #5: Move Copy Assignment Constructor " << std::endl;
	vect1 = My_Vector<int>{ 7, 8, 9 };
	std::cout << vect1 << std::endl;
	std::cout << "Test #6: +=, -=, *=, /= " << std::endl;
	vect1 += vect2;
	std::cout << vect1 << std::endl;
	vect1 -= vect2;
	std::cout << vect1 << std::endl;
	vect1 *= vect2;
	std::cout << vect1 << std::endl;
	vect1 /= vect2;
	std::cout << vect1 << std::endl;
	std::cout << "Test #7: +, -, *, / " << std::endl;
	std::cout << vect1 + vect2 << std::endl;
	std::cout << vect1 - vect2 << std::endl;
	std::cout << vect1 * vect2 << std::endl;
	std::cout << vect1 / vect2 << std::endl;
	std::cout << "Test #8: ==, != " << std::endl;
	std::cout << (vect1 == vect2) << std::endl;
	std::cout << (vect1 != vect2) << std::endl;
}

int main() {
	char a;
	testConstructors();
	std::cin >> a;
	return 0;
}
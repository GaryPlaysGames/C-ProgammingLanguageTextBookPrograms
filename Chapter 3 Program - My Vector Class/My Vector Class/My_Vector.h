#ifndef MY_FUNCTION_H
#define MY_FUNCTION_H

#include "stdafx.h"
#include <iostream>

template<class T>
class My_Vector {
	public:
		My_Vector(const int& s);
		My_Vector(const std::initializer_list<T>& il);

		My_Vector(const My_Vector<T>& a);
		My_Vector<T>& operator=(const My_Vector<T>& a);

		My_Vector(My_Vector<T>&& a);
		My_Vector<T>& operator=(My_Vector<T>&& a);

		My_Vector<T>& operator+=(const My_Vector<T>& a);
		My_Vector<T>& operator-=(const My_Vector<T>& a);
		My_Vector<T>& operator/=(const My_Vector<T>& a);
		My_Vector<T>& operator*=(const My_Vector<T>& a);

		My_Vector<T> operator+(const My_Vector<T>& a);
		My_Vector<T> operator-(const My_Vector<T>& a);
		My_Vector<T> operator/(const My_Vector<T>& a);
		My_Vector<T> operator*(const My_Vector<T>& a);

		bool operator==(const My_Vector<T>& a);
		bool operator!=(const My_Vector<T>& a);

		constexpr T& operator[](const unsigned int& i);

		template<class T2>
		friend std::ostream& operator<<(std::ostream& os, const My_Vector<T2>& a);

		template<class T2>
		friend std::istream& operator>>(std::istream& is, My_Vector<T2>& a);

		~My_Vector();

	private:
		T* elem;
		int size;
};

template<class T>
My_Vector<T>::My_Vector(const int& s)
	: size(s) {
	try {
		elem = new T[s];
	}
	catch (std::exception& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		delete[] elem;
		throw;
	}
}

template<class T>
My_Vector<T>::My_Vector(const std::initializer_list<T>& il)
	: size{ static_cast<int>(il.size()) } {
	try {
		elem = new T[il.size()];
	}
	catch (const std::exception& e) {
		std::cerr << "ERROR " << e.what() << std::endl;
		delete[] elem;
		throw;
	}
	int counter = 0;
	for (auto i = il.begin(); i != il.end(); ++i) {
		elem[counter++] = (*i);
	}
}

template <typename T>
My_Vector<T>::My_Vector(const My_Vector<T>& a)
	: size{ a.size } {
	std::cout << "COPY HAPPENED" << std::endl;
	try {
		elem = new T[a.size];
		for (int i = 0; i < a.size; ++i) {
			elem[i] = a.elem[i];
		}
	}
	catch (std::exception& e) {
		std::cout << "ERROR: " << e.what() << std::endl;
		delete[] elem;
		throw;
	}
}

template<class T>
My_Vector<T>& My_Vector<T>::operator=(const My_Vector<T>& a) {
	std::cout << "COPY ASSIGNMENT HAPPENED" << std::endl;
	if (this != &a) {
		delete[] elem;
		elem = new T[a.size];
		size = a.size;
		for (int i = 0; i < size; ++i) {
			elem[i] = a.elem[i];
		}
	}
	return *this;
}

template<class T>
My_Vector<T>::My_Vector(My_Vector<T> && a)
	: elem(a.elem), size(a.size) {
	std::cout << "MOVE HAPPENED" << std::endl;
	a.elem = nullptr;
	a.size = 0;
}

template<class T>
My_Vector<T>& My_Vector<T>::operator=(My_Vector<T>&& a) {
	std::cout << "MOVE ASSIGNMENT HAPPENED" << std::endl;
	if (this != &a) {
		elem = a.elem;
		size = a.size;
		a.elem = nullptr;
		a.size = 0;
	}
	return *this;
}

template<class T>
My_Vector<T>& My_Vector<T>::operator+=(const My_Vector<T>& a) {
	if (a.size != size) {
		std::cerr << "Sizes do not match" << std::endl;
		delete[] elem;
		throw;
	}
	for (int i = 0; i < size; ++i) {
		elem[i] += a.elem[i];
	}
}

template<class T>
My_Vector<T>& My_Vector<T>::operator-=(const My_Vector<T>& a) {
	if (a.size != size) {
		std::cerr << "Sizes do not match" << std::endl;
		delete[] elem;
		throw;
	}
	for (int i = 0; i < size; ++i) {
		elem[i] -= a.elem[i];
	}
}

template<class T>
My_Vector<T>& My_Vector<T>::operator/=(const My_Vector<T>& a) {
	if (a.size != size) {
		std::cerr << "Sizes do not match" << std::endl;
		delete[] elem;
		throw;
	}
	for (int i = 0; i < size; ++i) {
		elem[i] /= a.elem[i];
	}
}

template<class T>
My_Vector<T>& My_Vector<T>::operator*=(const My_Vector<T>& a) {
	if (a.size != size) {
		std::cerr << "Sizes do not match" << std::endl;
		delete[] elem;
		throw;
	}
	for (int i = 0; i < size; ++i) {
		elem[i] *= a.elem[i];
	}
}

template<class T>
My_Vector<T> My_Vector<T>::operator+(const My_Vector<T>& a) {
	if (size != a.size) {
		std::cerr << "Sizes do not match" << std::endl;
		delete[] elem;
		throw;
	}
	My_Vector<T> result(a.size);
	for (int i = 0; i < result.size; ++i) {
		result[i] = elem[i] + a.elem[i];
	}
	return result;
}


template<class T>
My_Vector<T> My_Vector<T>::operator-(const My_Vector<T>& a) {
	if (size != a.size) {
		std::cerr << "Sizes do not match" << std::endl;
		delete[] elem;
		throw;
	}
	My_Vector<T> result(a.size);
	for (int i = 0; i < result.size; ++i) {
		result[i] = elem[i] - a.elem[i];
	}
	return result;
}

template<class T>
My_Vector<T> My_Vector<T>::operator*(const My_Vector<T>& a) {
	if (size != a.size) {
		std::cerr << "Sizes do not match" << std::endl;
		delete[] elem;
		throw;
	}
	My_Vector<T> result(a.size);
	for (int i = 0; i < result.size; ++i) {
		result[i] = elem[i] * a.elem[i];
	}
	return result;
}

template<class T>
My_Vector<T> My_Vector<T>::operator/(const My_Vector<T>& a) {
	if (size != a.size) {
		std::cerr << "Sizes do not match" << std::endl;
		delete[] elem;
		throw;
	}
	My_Vector<T> result(a.size);
	for (int i = 0; i < result.size; ++i) {
		result[i] = elem[i] / a.elem[i];
	}
	return result;
}

template<class T>
bool My_Vector<T>::operator==(const My_Vector<T>& a) {
	if (size != a.size) {
		return false;
	}
	for (int i = 0; i < a.size; ++i) {
		if (elem[i] != a.elem[i]) {
			return false;
		}
	}
	return true;
}

template<class T>
bool My_Vector<T>::operator!=(const My_Vector<T>& a) {
	return !((*this) == a);
}

template<class T>
constexpr T& My_Vector<T>::operator[](const unsigned int& i) {
	try {
		return elem[i];
	}
	catch (std::exception& e) {
		std::cerr << "ERROR: " << e.what() << std::endl;
		delete[] elem;
		throw;
	}
}

template<class T>
std::ostream& operator<<(std::ostream& os, const My_Vector<T>& a) {
	for (int i = 0; i < a.size; ++i) {
		os << " " << a.elem[i] << " ";
	}
	return os;
}

template<class T>
std::istream& operator>>(std::istream& is, My_Vector<T>& a) {
	char c;
	for(is >> c; c != ']') {
		if (c != '[' || c != ',') {
			T* temp = new T[++(a.size)];
			for (int i = 0; i < a.size; ++i) {
				temp[i] = a.elem[i];
			}
			is >> a.elem[a.size];
		}
	}
}

template<class T>
My_Vector<T>::~My_Vector() {
	delete[] elem;
}

#endif
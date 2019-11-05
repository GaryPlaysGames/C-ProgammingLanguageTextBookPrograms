#ifndef VEC_H
#define VEC_H

#include <vector>

template<typename T>
class Vec : public std::vector<T> {
	public:
		using std::vector<T>::vector;

		T& operator[](int i) {
			return std::vector<T>::at(i);
		}

		const T& operator[](int i) const {
			return std::vector<T>::at(i);
		}
};

#endif // ! VEC_H

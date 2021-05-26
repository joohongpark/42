/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:58:07 by joopark           #+#    #+#             */
/*   Updated: 2021/05/25 22:47:31 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <exception>

template <typename T>
class Array {
	private:
		T * _arr;
		unsigned int _size;
	public:
		Array() {
			_arr = NULL;
			_size = 0;
		}

		Array(unsigned int n) {
			_arr = new T[n];
			_size = n;
		}

		Array(const Array & array) {
			if (this != &array)
				*this = array;
		}

		Array & operator=(const Array & array) {
			if (this != &array) {
				if (array.arr == NULL) {
					this->_arr = NULL;
				} else {
					this->_arr = new T[_size];
					for (unsigned int i = 0; i < _size; i++)
						this->_arr[i] = array._arr[i];
					this->_size = array._size;
				}
			}
			return (*this);
		}

		~Array() {
			delete [] _arr;
		}

		T & operator[](unsigned int i) {
			if (i >= _size)
				throw Array::OutOfTheLimitsException();
			return (_arr[i]);
		}

		unsigned int size(void) const {
			return (_size);
		}

		class OutOfTheLimitsException : public std::exception {
			virtual const char* what() const throw() {
				return "Out of the limits";
			}
		};
};

#endif

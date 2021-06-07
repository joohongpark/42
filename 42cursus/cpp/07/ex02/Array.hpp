/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joopark <joopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:58:07 by joopark           #+#    #+#             */
/*   Updated: 2021/06/07 14:56:23 by joopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
	private:
		T * _arr;
		unsigned int _size;
	public:
		Array() {
			_arr = new T[0]();
			_size = 0;
		}

		Array(unsigned int n) {
			_arr = new T[n]();
			_size = n;
		}

		Array(const Array & array) {
			if (this != &array)
				*this = array;
		}

		Array & operator=(const Array & array) {
			if (this != &array) {
				delete [] this->_arr;
				this->_arr = new T[array._size];
				for (unsigned int i = 0; i < array._size; i++)
					this->_arr[i] = array._arr[i];
				this->_size = array._size;
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

		const T & operator[](unsigned int i) const {
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

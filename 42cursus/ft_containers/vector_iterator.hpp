#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
    template <class T>
    class vector_iterator {
        public:
            typedef T                                                           iterator_type;
            typedef typename iterator_traits<iterator_type>::iterator_category  iterator_category;
            typedef typename iterator_traits<iterator_type>::value_type         value_type;
            typedef typename iterator_traits<iterator_type>::difference_type    difference_type;
            typedef typename iterator_traits<iterator_type>::pointer            pointer;
            typedef typename iterator_traits<iterator_type>::reference          reference;
        private:
            iterator_type iter;
        public:
            vector_iterator();
            vector_iterator(const iterator_type& x) : iter(x) {}
            //operator vector_iterator<const T> () const { return (vector_iterator<const T>(this->iter)); }

            /*
            template <class T>
            vector_iterator(
                const vector_iterator<T>& i
                typename enable_if<is_convertible<T, iterator_type>::value>::type* = 0)
            : iter(i.base());
            */
            reference           operator*() const {
                return (*iter);
            }
            pointer             operator->() const {
                //return (pointer)_VSTD::addressof(*__i);
                return (iter);
            }
            vector_iterator&    operator++() {
                ++iter;
                return (*iter);
            }
            vector_iterator     operator++(int) {
                vector_iterator tmp(*this);
                ++(*this);
                return (tmp);
            }
            vector_iterator&    operator--() {
                --iter;
                return (*this);
            }
            vector_iterator     operator--(int) {
                vector_iterator tmp(*this);
                --(*this);
                return (tmp);
            }
            vector_iterator     operator+ (difference_type n) const {
                vector_iterator tmp(*this);
                tmp += n;
                return (tmp);
            }
            vector_iterator&    operator+=(difference_type n) {
                iter += n;
                return (*this);
            }
            vector_iterator     operator- (difference_type n) const {
                return (*this + (-n));
            }
            vector_iterator&    operator-=(difference_type n) {
                *this += -n;
                return (*this);
            }
            reference           operator[](difference_type n) const {
                return (iter[n]);
            }
            iterator_type       base() const {
                return (iter);
            }
    };
}
#endif
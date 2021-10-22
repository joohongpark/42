#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {
    template <class T, T val>
    struct integral_constant {
        typedef T                   value_type;
        static const T              value = val;
        typedef integral_constant   type;
        operator value_type() {
            return (value);
        }
        value_type operator ()() const {
            return (value);
        }
    };

    typedef integral_constant<bool, true>  true_type;
    typedef integral_constant<bool, false> false_type;

    template <class T>   struct is_integral_parent                     : public false_type {};
    template <>          struct is_integral_parent<bool>               : public true_type  {};
    template <>          struct is_integral_parent<char>               : public true_type  {};
    template <>          struct is_integral_parent<signed char>        : public true_type  {};
    template <>          struct is_integral_parent<unsigned char>      : public true_type  {};
    template <>          struct is_integral_parent<wchar_t>            : public true_type  {};
    template <>          struct is_integral_parent<short>              : public true_type  {};
    template <>          struct is_integral_parent<unsigned short>     : public true_type  {};
    template <>          struct is_integral_parent<int>                : public true_type  {};
    template <>          struct is_integral_parent<unsigned int>       : public true_type  {};
    template <>          struct is_integral_parent<long>               : public true_type  {};
    template <>          struct is_integral_parent<unsigned long>      : public true_type  {};
    template <>          struct is_integral_parent<long long>          : public true_type  {};
    template <>          struct is_integral_parent<unsigned long long> : public true_type  {};


    template <class T>   struct is_const                               : public false_type {};
    template <class T>   struct is_const<T const>                      : public true_type {};

    template <class T>   struct remove_const                {typedef T type;};
    template <class T>   struct remove_const<const T>       {typedef T type;};
    template <class T>   struct remove_volatile             {typedef T type;};
    template <class T>   struct remove_volatile<volatile T> {typedef T type;};

    template <class T>
    struct remove_cv {
        typedef typename remove_volatile<typename remove_const<T>::type>::type type;
    };

    template <class T>
    struct is_integral : public is_integral_parent<typename remove_cv<T>::type> {};

    template <bool, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> {
        typedef T type;
    };
}


#endif
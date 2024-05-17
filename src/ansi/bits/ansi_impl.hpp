#ifndef ANSI_BITS_ANSI_IMPL_HPP_
#define ANSI_BITS_ANSI_IMPL_HPP_

#include <ostream>

namespace ansi {

namespace __impl {

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& __insert_ostream(std::basic_ostream<_CharT, _Traits>& __os, int __n1, char __c) {
    std::ios_base::fmtflags __flags = __os.flags(static_cast<std::ios_base::fmtflags>(0L));
    __os << "\x1b[" << __n1 << __c;
    __os.flags(__flags);
    return __os;
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& __insert_ostream(std::basic_ostream<_CharT, _Traits>& __os, int __n1, int __n2, char __c) {
    std::ios_base::fmtflags __flags = __os.flags(static_cast<std::ios_base::fmtflags>(0L));
    __os << "\x1b[" << __n1 <<  ';' << __n2 << __c;
    __os.flags(__flags);
    return __os;
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& __insert_ostream(std::basic_ostream<_CharT, _Traits>& __os, int __n1, int __n2, int __n3, char __c) {
    std::ios_base::fmtflags __flags = __os.flags(static_cast<std::ios_base::fmtflags>(0L));
    __os << "\x1b[" << __n1 << ';' << __n2 << ';' << __n3 << __c;
    __os.flags(__flags);
    return __os;
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& __insert_ostream(std::basic_ostream<_CharT, _Traits>& __os, int __n1, int __n2, int __n3, int __n4, int __n5, char __c) {
    std::ios_base::fmtflags __flags =  __os.flags(static_cast<std::ios_base::fmtflags>(0L));
    __os << "\x1b[" << __n1 << ';' << __n2 << ';' << __n3 << ';' << __n4 << ';' << __n5 << __c;
    __os.flags(__flags);
    return __os;
}

} // namespace __impl

} // namespace ansi

#endif // ANSI_BITS_ANSI_IMPL_HPP_
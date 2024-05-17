#ifndef ANSI_CONTROLS_SCREEN_HPP_
#define ANSI_CONTROLS_SCREEN_HPP_

#include <ostream>

#include "ansi/bits/ansi_impl.hpp"

namespace ansi {

struct _Clearscreen {
    int n;
    constexpr _Clearscreen(int __n) noexcept : n(3 < (__n < 0 ? 0 : __n) ? 3 : __n) {};
};

inline constexpr _Clearscreen clearscreen(int n = 2) noexcept {
    return _Clearscreen(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Clearscreen& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'J');
}

struct _Clearline {
    int n;
    constexpr _Clearline(int __n) noexcept : n( 2 < (__n < 0 ? 0 : __n) ? 2 : __n) {};
};

inline constexpr _Clearline clearline(int n = 2) noexcept {
    return _Clearline(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Clearline& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'K');
}

struct _Scrollup {
    int n;
    constexpr _Scrollup(int __n) noexcept : n(__n < 0 ? 0 : __n) {};
};

inline constexpr _Scrollup scrollup(int n = 1) noexcept {
    return _Scrollup(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Scrollup& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'S');
}

struct _Scrolldown {
    int n;
    constexpr _Scrolldown(int __n) noexcept : n(__n < 0 ? 0 : __n) {};
};

inline constexpr _Scrolldown scrolldown(int n = 1) noexcept {
    return _Scrolldown(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Scrolldown& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'T');
}

} // namespace ansi

#endif // ANSI_CONTROLS_SCREEN_HPP_
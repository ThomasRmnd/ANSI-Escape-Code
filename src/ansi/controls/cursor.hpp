#ifndef ANSI_CONTROLS_CURSOR_HPP_
#define ANSI_CONTROLS_CURSOR_HPP_

#include <ostream>

#include "ansi/bits/ansi_impl.hpp"

namespace ansi {

struct _Up {
    int n;
    constexpr _Up(int __n) noexcept : n(__n < 0 ? 0 : __n) {};
};

inline constexpr _Up up(int n = 1) noexcept {
    return _Up(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Up& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'A');
}

struct _Down {
    int n;
    constexpr _Down(int __n) noexcept : n(__n < 0 ? 0 : __n) {};
};

inline constexpr _Down down(int n = 1) noexcept {
    return _Down(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Down& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'B');
}

struct _Forward {
    int n;
    constexpr _Forward(int __n) noexcept : n(__n < 0 ? 0 : __n) {};
};

inline constexpr _Forward forward(int n = 1) noexcept {
    return _Forward(n);
}

inline constexpr _Forward right(int n = 1) noexcept {
    return _Forward(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Forward& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'C');
}

struct _Backward {
    int n;
    constexpr _Backward(int __n) noexcept : n(__n < 0 ? 0 : __n) {};
};

inline constexpr _Backward backward(int n = 1) noexcept {
    return _Backward(n);
}

inline constexpr _Backward left(int n = 1) noexcept {
    return _Backward(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Backward& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'D');
}

struct _Nextline {
    int n;
    constexpr _Nextline(int __n) noexcept : n(__n < 0 ? 0 : __n) {};
};

inline constexpr _Nextline nextl(int n = 1) noexcept {
    return _Nextline(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Nextline& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'E');
}

struct _Prevline {
    int n;
    constexpr _Prevline(int __n) noexcept : n(__n < 0 ? 0 : __n) {};
};

inline constexpr _Prevline prevl(int n = 1) noexcept {
    return _Prevline(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Prevline& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'F');
}

struct _Setcolumn {
    int n;
    constexpr _Setcolumn(int __n) noexcept : n(__n < 1 ? 1 : __n) {};
};

inline constexpr _Setcolumn setcolumn(int n = 1) noexcept {
    return _Setcolumn(n);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setcolumn& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'G');
}

struct _Setposition {
    int x, y;
    constexpr _Setposition(int __x, int __y) noexcept : x(__x < 1 ? 1 : __x), y(__y < 1 ? 1 : __y) {};
};

inline constexpr _Setposition setposition(int x = 1, int y = 1) noexcept {
    return _Setposition(x, y);
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setposition& __f) {
    return __impl::__insert_ostream(__os, __f.x, __f.y, 'H');
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& savecursor(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[s";
}

template<typename _CharT, typename _Traits>
inline std::basic_ostream<_CharT, _Traits>& restorecursor(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[u";
}

} // namespace ansi

#endif // ANSI_CONTROLS_CURSOR_HPP_
#ifndef ANSI_GRAPHICS_TEXT_HPP_
#define ANSI_GRAPHICS_TEXT_HPP_

#include <ostream>

#include "ansi/bits/ansi_impl.hpp"

namespace ansi {

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& bold(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[1m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& faint(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[2m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& italic(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[3m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& underline(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[4m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& blinking(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[5m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& fastblinking(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[6m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& hide(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[8m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& crossedout(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[9m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& resetfont(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[10m";
}

struct _Setfont {
    int n;
    constexpr _Setfont(int __n) noexcept : n(20 < (__n < 11 ? 11 : __n) ? 20 : __n) {};
};

inline constexpr _Setfont setfont(int __n) noexcept {
    return {__n};
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setfont& __f) {
    return __impl::__insert_ostream(__os, __f.n, 'm');
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& doublyunderline(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[21m";
} // or notbold

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& resetintensity(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[22m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notitalic(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[23m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notunderline(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[24m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notblinking(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[25m";
}

// missing enable proportional spacing (27)

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& reveal(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[28m";
}

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notcrossedout(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[29m";
}

// missing disable proportional spacing (50)

// missing framed (51)

// missing encircled (52)

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& overlined(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[53m";
}

// missing notframednorencircled (54)

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notoverlined(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[55m";
}

// missing underline color (58)

// missing default underline color (59)

// missing ideograms (60-65)

// missing superscript (73)

// missing subscript (74)

// missing notsuperscriptnorsubscript (75)

} // namespace ansi

#endif // ANSI_GRAPHICS_TEXT_HPP_
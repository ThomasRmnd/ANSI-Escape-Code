#ifndef ANSI_GRAPHICS_TEXT_HPP_
#define ANSI_GRAPHICS_TEXT_HPP_

#include <ostream>

#include "ansi/bits/ansi_impl.hpp"

namespace ansi {

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& bold(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[1m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& faint(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[2m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& italic(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[3m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& underline(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[4m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& blinking(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[5m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& fastblinking(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[6m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& hide(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[8m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& crossedout(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[9m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& resetfont(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[10m";
};

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
std::basic_ostream<_CharT, _Traits>& doublyunderline(std::basic_ostream<_CharT, _Traits>& __os) { // or notbold
    return __os << "\x1b[21m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& resetintensity(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[22m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notitalic(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[23m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notunderline(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[24m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notblinking(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[25m";
};

// missing enable proportional spacing (27)

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& reveal(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[28m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notcrossedout(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[29m";
};

// missing disable proportional spacing (50)

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& framed(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[51m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& encircled(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[52m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& overlined(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[53m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notframednorencircled(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[54m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notoverlined(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[55m";
};

struct _Setunderlinecolorlookup {
    int c;
    constexpr _Setunderlinecolorlookup(int __c) noexcept : c(__c) {};
};

inline constexpr _Setunderlinecolorlookup setunderlinecolor(int __c) noexcept {
    return {__c};
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setunderlinecolorlookup& __f) {
    return __impl::__insert_ostream(__os, 58, 5, __f.c, 'm');
};

struct _Setunderlinecolorrgb {
    int r, g, b;
    constexpr _Setunderlinecolorrgb(int __r, int __g, int __b) noexcept : r(__r), g(__g), b(__b) {};
};

inline constexpr _Setunderlinecolorrgb setunderlinecolor(int __r, int __g, int __b) noexcept {
    return {__r, __g, __b};
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setunderlinecolorrgb& __f) {
    return __impl::__insert_ostream(__os, 58, 2, __f.r, __f.g, __f.b, 'm');
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& defaultunderlinecolor(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[59m";
};

// missing ideograms (60-65)

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& superscript(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[73m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& subscript(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[74m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& notsuperscriptnorsubscript(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[75m";
};

} // namespace ansi

#endif // ANSI_GRAPHICS_TEXT_HPP_
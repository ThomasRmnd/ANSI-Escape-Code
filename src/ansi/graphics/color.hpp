#ifndef ANSI_GRAPHICS_COLOR_HPP_
#define ANSI_GRAPHICS_COLOR_HPP_

#include <ostream>

#include "ansi/bits/ansi_impl.hpp"

namespace ansi {

enum class _Ansi_Defaultcolors {
    _S_black = 30,
    _S_red = 31,
    _S_green = 32,
    _S_yellow = 33,
    _S_blue = 34,
    _S_magenta = 35,
    _S_cyan = 36,
    _S_white = 37,
    _S_default = 39,
    _S_bblack = 90,
    _S_bred = 91,
    _S_bgreen = 92,
    _S_byellow = 93,
    _S_bblue = 94,
    _S_bmagenta = 95,
    _S_bcyan = 96,
    _S_bwhite = 97
};

typedef _Ansi_Defaultcolors color;

const color black = _Ansi_Defaultcolors::_S_black;
const color red = _Ansi_Defaultcolors::_S_red;
const color green = _Ansi_Defaultcolors::_S_green;
const color yellow = _Ansi_Defaultcolors::_S_yellow;
const color blue = _Ansi_Defaultcolors::_S_blue;
const color magenta = _Ansi_Defaultcolors::_S_magenta;
const color cyan = _Ansi_Defaultcolors::_S_cyan;
const color white = _Ansi_Defaultcolors::_S_white;
const color defaultcolor = _Ansi_Defaultcolors::_S_default;
const color bblack = _Ansi_Defaultcolors::_S_bblack;
const color bred = _Ansi_Defaultcolors::_S_bred;
const color bgreen = _Ansi_Defaultcolors::_S_bgreen;
const color byellow = _Ansi_Defaultcolors::_S_byellow;
const color bblue = _Ansi_Defaultcolors::_S_bblue;
const color bmagenta = _Ansi_Defaultcolors::_S_bmagenta;
const color bcyan = _Ansi_Defaultcolors::_S_bcyan;
const color bwhite = _Ansi_Defaultcolors::_S_bwhite;

struct foreground_tag {};
struct background_tag {};

template<typename _Category>
struct _Setcolor {
    _Ansi_Defaultcolors c;
};

template<typename _Category>
struct _Setcolorlookup {
    int c;
    constexpr _Setcolorlookup(int __c) noexcept : c(255 < (__c < 0 ? 0 : __c) ? 255 : __c) {};
};

template<typename _Category>
struct _Setcolorrgb {
    int r, g, b;
    constexpr _Setcolorrgb(int __r, int __g, int __b) noexcept : 
        r(255 < (__r < 0 ? 0 : __r) ? 255 : __r),
        g(255 < (__g < 0 ? 0 : __g) ? 255 : __g),
        b(255 < (__b < 0 ? 0 : __b) ? 255 : __b) 
    {};
};

// Foreground ############################################################################################################

inline constexpr _Setcolor<foreground_tag> setfgcolor(_Ansi_Defaultcolors __c) noexcept {
    return {__c};
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setcolor<foreground_tag>& __f) {
    return __impl::__insert_ostream(__os, static_cast<int>(__f.c), 'm');
};

inline constexpr _Setcolorlookup<foreground_tag> setfgcolor(int __c) noexcept {
    return {__c};
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setcolorlookup<foreground_tag>& __f) {
    return __impl::__insert_ostream(__os, 38, 5, __f.c, 'm');
};

inline constexpr _Setcolorrgb<foreground_tag> setfgcolor(int __r, int __g, int __b) noexcept {
    return {__r, __g, __b};
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setcolorrgb<foreground_tag>& __f) {
    return __impl::__insert_ostream(__os, 38, 2, __f.r, __f.g, __f.b, 'm');
};

// Background ############################################################################################################

inline constexpr _Setcolor<background_tag> setbgcolor(_Ansi_Defaultcolors __c) noexcept {
    return {__c};
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setcolor<background_tag>& __f) {
    return __impl::__insert_ostream(__os, static_cast<int>(__f.c) + 10, 'm');
};

inline constexpr _Setcolorlookup<background_tag> setbgcolor(int __c) noexcept {
    return {__c};
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setcolorlookup<background_tag>& __f) {
    return __impl::__insert_ostream(__os, 48, 5, __f.c, 'm');
};

inline constexpr _Setcolorrgb<background_tag> setbgcolor(int __r, int __g, int __b) noexcept {
    return {__r, __g, __b};
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& operator<<(std::basic_ostream<_CharT, _Traits>& __os, const _Setcolorrgb<background_tag>& __f) {
    return __impl::__insert_ostream(__os, 48, 2, __f.r, __f.g, __f.b, 'm');
};

// Swap ############################################################################################################

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& swapcolors(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[7m";
};

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& unswapcolors(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[27m";
};

} // namespace ansi

#endif // ANSI_GRAPHICS_COLOR_HPP_
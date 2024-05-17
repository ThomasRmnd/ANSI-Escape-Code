#ifndef ANSI_GRAPHICS_HPP_
#define ANSI_GRAPHICS_HPP_

#include "graphics/color.hpp"
#include "graphics/text.hpp"

namespace ansi {

template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>& reset(std::basic_ostream<_CharT, _Traits>& __os) {
    return __os << "\x1b[0m";
};

} // namespace ansi

#endif // ANSI_GRAPHICS_HPP_
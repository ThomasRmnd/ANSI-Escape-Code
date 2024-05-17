#include <array>
#include <iostream>
#include <iomanip>
#include <numeric>

#include <ansi/graphics/color.hpp>

int main() {

    // Let's recreate the picture on the Wikipedia page (https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit)

    std::array<int, 256> colors = {0};
    std::iota(colors.begin(), colors.end(), 0);

    std::cout << "Standard colors:" << std::endl;
    for (std::size_t i = 0; i < 8; ++i) {
        std::cout << ansi::setbgcolor(colors[i]) << ansi::setfgcolor(i + 8) << std::setw(5) << i << ' ';
    }
    std::cout << ansi::setbgcolor(ansi::defaultcolor) << std::endl;

    std::cout << "High-intensity colors:" << std::endl << ansi::setfgcolor(ansi::black);
    for (std::size_t i = 8; i < 16; ++i) {
        std::cout << ansi::setbgcolor(colors[i]) << ansi::setfgcolor(i - 8) << std::setw(5) << i << ' ';
    }
    std::cout << ansi::setfgcolor(ansi::defaultcolor) << ansi::setbgcolor(ansi::defaultcolor) << std::endl;

    std::cout << "216 colors:" << std::endl;
    for (std::size_t g = 0; g < 6; ++g) {
        if (g == 3) std::cout << ansi::setfgcolor(ansi::black);
        for (std::size_t r = 0; r < 6; ++r) {
            for (std::size_t b = 0; b < 6; ++b) {
                std::cout << ansi::setbgcolor(r * 36 + g * 6 + b + 16) << std::setw(5) << r * 36 + g * 6 + b + 16 << ' ';
            }
            std::cout << ansi::setbgcolor(ansi::defaultcolor) << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << ansi::setfgcolor(ansi::defaultcolor);

    std::cout << "Grayscale colors: ";
    for (std::size_t i = 232; i < 256; ++i) {
        if (i == 244) std::cout << ansi::setfgcolor(ansi::black);
        std::cout << ansi::setbgcolor(colors[i]) << std::setw(5) << i << ' ';
    }
    std::cout << ansi::setfgcolor(ansi::defaultcolor) << ansi::setbgcolor(ansi::defaultcolor) << std::endl;

}
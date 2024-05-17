#include <array>
#include <iomanip>
#include <iostream>

#include <ansi/graphics/color.hpp>

int main() {

    // Let's create a matrix of colors with column as foreground and row as background

    const std::size_t numbers = 16;

    const std::array<ansi::color, numbers> colors = {
        ansi::black, ansi::red, ansi::green, ansi::yellow,
        ansi::blue, ansi::magenta, ansi::cyan, ansi::white,
        ansi::bblack, ansi::bred, ansi::bgreen, ansi::byellow,
        ansi::bblue, ansi::bmagenta, ansi::bcyan, ansi::bwhite
    };

    const std::array<const char*, numbers> labels = {
        "black", "red", "green", "yellow",
        "blue", "magenta", "cyan", "white",
        "bblack", "bred", "bgreen", "byellow",
        "bblue", "bmagenta", "bcyan", "bwhite"
    };

    for (std::size_t i = 0; i < numbers + 1; ++i) {
        for (std::size_t j = 0; j < numbers + 1; ++j) {
            if (i == 0 && j == 0) {
                std::cout << std::setw(10) << "";
            }
            else if (i == 0) {
                // Special case for black label
                if (j == 1) std::cout << ansi::setbgcolor(ansi::bblack) << ansi::setfgcolor(colors[j - 1]) << std::setw(10) << labels[j - 1] << "" << ansi::setbgcolor(ansi::defaultcolor);
                else std::cout << ansi::setfgcolor(colors[j - 1]) << std::setw(10) << labels[j - 1];
            }
            else if (j == 0) {
                // Special case for black label
                if (i == 1) std::cout << ansi::setbgcolor(ansi::bblack) << ansi::setfgcolor(colors[i - 1]) << std::setw(10) << labels[i - 1] << "" << ansi::setbgcolor(ansi::defaultcolor);
                else std::cout << ansi::setfgcolor(colors[i - 1]) << std::setw(10) << labels[i - 1];
            }
            else {
                std::cout << ansi::setfgcolor(colors[i - 1]) << ansi::setbgcolor(colors[j - 1]) << std::setw(10) << "Hello!";
            }
        }
        std::cout << ansi::setfgcolor(ansi::defaultcolor) << ansi::setbgcolor(ansi::defaultcolor) << std::endl;
    }

    return 0;
}
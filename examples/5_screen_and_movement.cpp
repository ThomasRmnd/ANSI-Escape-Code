#include <iomanip>
#include <iostream>

#include <ansi/controls.hpp>
#include <ansi/graphics/color.hpp>

void make_square(int width, int height, ansi::color c) {
    std::cout << ansi::setfgcolor(c) << '+';
    for (int i = 0; i < width - 2; ++i) {
        std::cout << '-';
    }
    std::cout << '+' << ansi::down() << ansi::left();
    for (int i = 0; i < height - 2; ++i) {
        std::cout << '|' << ansi::down() << ansi::left();
    }
    std::cout << '+' << ansi::left(width) << ansi::savecursor << '+';
    for (int i = 0; i < width - 2; ++i) {
        std::cout << '-';
    }
    std::cout << ansi::restorecursor << ansi::up();
    for (int i = 0; i < height - 2; ++i) {
        std::cout << '|' << ansi::up() << ansi::left();
    }
    std::cout << ansi::setfgcolor(ansi::defaultcolor);
}

int main() {

    // Let's create some simples squares

    std::cout << ansi::clearscreen() << ansi::setposition(); // Clear the screen, and go at the top

    ansi::color colors[6] = { ansi::red, ansi::yellow, ansi::green, ansi::cyan, ansi::blue, ansi::magenta };
    const int width = 24, height = 12;


    for (int i = 0; i < 6; ++i) {
        make_square(width - i * 4, height - i * 2, colors[i]);
        std::cout << ansi::down() << ansi::right(2);
    }
    std::cout << ansi::up(6) << ansi::left(12) << ansi::down(height);

    return 0;
}
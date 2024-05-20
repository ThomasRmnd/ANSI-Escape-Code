#include <array>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>

#include <ansi/graphics/text.hpp>

int main() {

    // Let's play with the text styles

    std::cout << "Normal text, " << ansi::bold << "bold text, " << ansi::resetintensity << "normal text again." << std::endl;
    
    std::cout << "Normal text, " << ansi::faint << "faint text, " << ansi::resetintensity << "normal text again." << std::endl;
    
    std::cout << "Normal text, " << ansi::italic << "italic text, " << ansi::notitalic << "normal text again." << std::endl;

    std::cout << "Normal text, " << ansi::underline << "underline text, " << ansi::doublyunderline << "doubly underline text, " << ansi::notunderline << "normal text again." << std::endl;

    std::cout << "Normal text, " << ansi::blinking << "blinking text, " << ansi::notblinking << "normal text again." << std::endl;

    std::cout << "Normal text, " << ansi::fastblinking << "fast blinking text, " << ansi::notblinking << "normal text again." << std::endl; // Normal blinking in my terminal

    std::cout << "Normal text, " << ansi::hide << "hidden text, " << ansi::reveal << "normal text again." << std::endl;

    std::cout << "Normal text, " << ansi::crossedout << "crossed out text, " << ansi::notcrossedout << "normal text again." << std::endl;

    std::cout << "Normal text, " << ansi::overlined << "overlined text, " << ansi::notoverlined << "normal text again." << std::endl;

    return 0;
}
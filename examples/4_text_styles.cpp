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
    
    /* std::array<int, 16> colors;
    std::iota(colors.begin(), colors.end(), 0);
    std::string underline = "underline text,";
    std::cout << "Normal text, " << ansi::underline;
    for (int i = 0; i < colors.size(); ++i) {
        std::cout << ansi::setunderlinecolor(colors[i]) << underline[i];
    }
    std::cout << ansi::notunderline << "normal text again." << std::endl; */ // Not supported with my terminal
    std::cout << "Normal text, " << ansi::underline << "underline text, " << ansi::doublyunderline << "doubly underline text, " << ansi::notunderline << "normal text again." << std::endl;

    std::cout << "Normal text, " << ansi::blinking << "blinking text, " << ansi::notblinking << "normal text again." << std::endl;

    std::cout << "Normal text, " << ansi::fastblinking << "fast blinking text, " << ansi::notblinking << "normal text again." << std::endl; // Normal blinking in my terminal

    std::cout << "Normal text, " << ansi::hide << "hidden text, " << ansi::reveal << "normal text again." << std::endl;

    std::cout << "Normal text, " << ansi::crossedout << "crossed out text, " << ansi::notcrossedout << "normal text again." << std::endl;

    /* std::array<int, 10> fonts;
    std::iota(fonts.begin(), fonts.end(), 1);
    std::cout << "Normal text, ";
    for (int i = 0; i < fonts.size(); ++i) {
        std::cout << ansi::setfont(fonts[i]) << "font " << fonts[i] << ", ";
    }
    std::cout << ansi::resetfont << "normal text again." << std::endl; */ // Not supported with my terminal

    // std::cout << "Normal text, " << ansi::framed << "framed text, " << ansi::notframednorencircled << "normal text again." << std::endl; // Not supported with my terminal

    // std::cout << "Normal text, " << ansi::encircled << "encircled text, " << ansi::notframednorencircled << "normal text again." << std::endl; // Normal encircled in my terminal

    std::cout << "Normal text, " << ansi::overlined << "overlined text, " << ansi::notoverlined << "normal text again." << std::endl;

    // std::cout << "Normal text, " << ansi::superscript << "superscript text, " << ansi::notsuperscriptnorsubscript << "normal text again." << std::endl; // Not supported with my terminal

    // std::cout << "Normal text, " << ansi::subscript << "subscript text, " << ansi::notsuperscriptnorsubscript << "normal text again." << std::endl; // Not supported with my terminal

    return 0;
}
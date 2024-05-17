#include <array>
#include <iomanip>
#include <iostream>

#include <ansi/graphics/color.hpp>

struct rgb {
    int r;
    int g;
    int b;
};

struct hsl {
    double h;
    double s;
    double l;
};

double hue2rgb(double p, double q, double t) {
    if (t < 0.0) t += 1.0;
    if (t > 1.0) t -= 1.0;
    if (t < 1.0 / 6.0) return p + (q - p) * 6.0 * t;
    if (t < 1.0 / 2.0) return q;
    if (t < 2.0 / 3.0) return p + (q - p) * (2.0 / 3.0 - t) * 6.0;
    return p;
}

rgb hsl2rgb(hsl color) {
    double r, g, b;
    if (color.s == 0.0) {
        r = g = b = color.l;
    }
    else {
        double q = color.l < 0.5 ? color.l * (1.0 + color.s) : color.l + color.s - color.l * color.s;
        double p = 2.0 * color.l - q;
        r = hue2rgb(p, q, color.h + 1.0 / 3.0);
        g = hue2rgb(p, q, color.h);
        b = hue2rgb(p, q, color.h - 1.0 / 3.0);
    }
    return {static_cast<int>(r * 255), static_cast<int>(g * 255), static_cast<int>(b * 255)};
}

int main() {

    // Let's draw the HSL cylinder for S = 1

    const int width = 150;
    const int height = 35;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            hsl color = {static_cast<double>(x) / width, 1.0, 1.0 - static_cast<double>(y) / height};
            rgb rgb_color = hsl2rgb(color);
            std::cout << ansi::setbgcolor(rgb_color.r, rgb_color.g, rgb_color.b);
            color = {static_cast<double>(y) / height, 1.0, 1.0 - static_cast<double>(x) / width};
            rgb_color = hsl2rgb(color);
            std::cout << ansi::setfgcolor(rgb_color.r, rgb_color.g, rgb_color.b) << '.';
        }
        std::cout << ansi::setbgcolor(ansi::defaultcolor) << ansi::setfgcolor(ansi::defaultcolor) << std::endl;
    }

    return 0;
}
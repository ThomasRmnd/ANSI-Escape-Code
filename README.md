# ANSI escape code

This repository contains a little project that allows to use ANSI escape codes, which are used to control the formatting, color, and other output options on text terminals, in C++.

This is only a small project, so not everything is yet implemented. I already have a few ideas (as you can see in the comments in the code) and I plan on implement them, but I also want to document myself a bit more on other escape codes that I don't know yet.

The implementation style was highly inspired by the C++ standard library. Especially the implementation of Format Flags in ios_base, std::hex, std::dec, std::setw, std::setfill, etc.

You can find some examples of code in the examples folder. To compile them, just create a bin and build folder and run `cd build`, `cmake ..`, and `make`. Then the executables will be in the bin folder. 

Fill free to report any issues or make any suggestions.

Resources:
- [Wikipedia: ANSI escape code](https://en.wikipedia.org/wiki/ANSI_escape_code)
- [fnky - ANSI Escape Sequences](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797)
- [XTerm Control Sequences](https://invisible-island.net/xterm/ctlseqs/ctlseqs.html)
- [Supported Terminal Sequences](https://xtermjs.org/docs/api/vtfeatures/)
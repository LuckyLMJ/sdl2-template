# SDL2 template
a simple template for getting SDL2 to work.

## Compilation Instructions
### Windows
to compile, install [msys2](https://github.com/msys2/msys2-installer/releases/download/2023-05-26/msys2-x86_64-20230526.exe), run `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-toolchain` in the terminal menu that opens, put the install path in your PATH, then open vscode.
Install the makefile extension for vscode, set the makefile path to mingw32-make, and then build via the `windows` build target through the extension.
### Linux
to compile, install sdl2 (for Debian/Ubuntu/Mint, this can be done with `sudo apt-get install libsdl2-dev`), then run `make linux` in the repository folder.


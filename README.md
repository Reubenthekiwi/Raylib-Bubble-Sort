# Raylib-Bubble-Sort

A sorting algorithm implemented in Raylib

## How to Build

1. Download all files and folders
2. If you don't have MinGW, you can download it [here](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download?use_mirror=telkomuniversity&use_mirror=telkomuniversity&r=)
3. Compile it
    g++ main.cpp -o bubblesort.exe -O2 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
5. Run bubblesort.exe

/* mvayк */

#include <iostream>

// g++ -m64 -shared -o main.dll main.cpp -static-libgcc -static-libstdc++
extern __declspec(dllexport) int main() {
    printf("successful");

    return 0;
}
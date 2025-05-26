/* mvayк */
/* mvayк */
/* mvayк */

#include <iostream>
#include <cstdint>

#include "include/include.h"
#include "include/GL/gl.h"
#include "include/GL/glu.h"

/* integrate master.asm */
extern "C" int asm_main();

/* C main function - gets exported for ctypes */
extern "C" __declspec(dllexport) int main() {
    uint64_t asm_r = asm_main();

    return 0;
}
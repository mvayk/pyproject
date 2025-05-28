/* mvayк */
/* mvayк */
/* mvayк */

//
// TODO: move opengl window stuff into its namespace
//

#include <stdio.h>
#include <windows.h>

#include "include/include.h"
#include "include/GL/gl.h"
#include "include/GL/glu.h"
#include "include/GLFW/glfw3.h"

/* integrate master.asm */
int asm_main();

/* C main function - gets exported for ctypes */
__declspec(dllexport) int WINAPI main() {
    int asm_r = asm_main();

    return 0;
}
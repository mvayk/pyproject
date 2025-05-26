/* mvayк */
/* mvayк */
/* mvayк */

#include <iostream>
#include <cstdint>

#include "include/include.h"
#include "include/GL/gl.h"
#include "include/GL/glu.h"

/* lib with opengl libs */
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

/* integrate master.asm */
extern "C" int asm_main();

/* C main function - gets exported for ctypes */
extern "C" __declspec(dllexport) int WINAPI main(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    uint64_t asm_r = asm_main();

    /* opengl window class */
    WNDCLASSW c_window = {};
    c_window.style = CS_OWNDC;
    c_window.lpfnWndProc = wn_proc;
    c_window.hInstance = hInstance;
    c_window.lpszClassName = L"polzyhuatsa";
    RegisterClassW(&c_window);

    /* spawn window */
    HWND hwnd = CreateWindowW(c_window.lpszClassName, L"opengl", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);

    /* get device context of hwnd */
    HDC h_dc = GetDC(hwnd);

    /* pixel formatting */
    PIXELFORMATDESCRIPTOR pixel_fd;
    pixel_fd.nSize = sizeof(pixel_fd);
    pixel_fd.nVersion = 1;
    pixel_fd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pixel_fd.iPixelType = PFD_TYPE_RGBA;
    pixel_fd.cColorBits = 32;
    pixel_fd.cDepthBits = 24;
    pixel_fd.iLayerType = PFD_MAIN_PLANE;

    int pixel_format = ChoosePixelFormat(h_dc, &pixel_fd);
    SetPixelFormat(h_dc, pixel_format, &pixel_fd);

    /* render context */
    HGLRC hg_context = wglCreateContext(h_dc);
    wglMakeCurrent(h_dc, hg_context);

    MSG message = {};
    BOOL running{true};

    while (running == true && running != false) {
        /* windows dispatch ptsd */
        while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
            if (message.message == WM_QUIT) {
                running = false;
            }

            /* process messages */
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SwapBuffers(h_dc);
        Sleep(1);
    }

    wglMakeCurrent(nullptr, nullptr);
    wglDeleteContext(hg_context);
    ReleaseDC(hwnd, h_dc);

    return 0;
}
/* random file that will contains functions that are not cool enough to be
   allow in main */

#pragma once

#include <iostream>
#include <windows.h>

LRESULT CALLBACK wn_proc(HWND hwnd, UINT message, WPARAM w_param, LPARAM l_param) {
    switch(message) {
        case WM_CLOSE:
            PostQuitMessage(0);
            return 0;
        default:
            return DefWindowProc(hwnd, message, w_param, l_param);
    }
}
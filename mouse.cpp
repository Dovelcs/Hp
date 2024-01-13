#include "mouse.h"

using namespace std;


void MouseLeftClick(HWND hwnd, int cx, int cy) {

    LPARAM lParam = MAKELONG(cx, cy);

    // ģ����갴�º͵������
    SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
    SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, lParam);
}
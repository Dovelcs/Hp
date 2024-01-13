#include "mouse.h"

using namespace std;


void MouseLeftClick(HWND hwnd, int cx, int cy) {

    LPARAM lParam = MAKELONG(cx, cy);

    // 模拟鼠标按下和弹起操作
    SendMessage(hwnd, WM_LBUTTONDOWN, MK_LBUTTON, lParam);
    SendMessage(hwnd, WM_LBUTTONUP, MK_LBUTTON, lParam);
}
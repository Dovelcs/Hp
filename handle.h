#ifndef __HANDLE_H__
#define __HANDLE_H__
#include <string>
#include <vector>
#include <windows.h>
#include <iostream> 


#define ISVISIABLE(hwnd) ((GetWindowLong(hwnd, GWL_STYLE) & WS_VISIBLE) == WS_VISIBLE) //判断窗口是否可见

struct EnumData {
    std::string targetTitle;
    std::vector<HWND> handles;
};


extern void EnumWinhwA(void);                                   //通过EnumWindows函数遍历所有窗口，输出窗口句柄及其标题，枚举以窄字符形式输出 
extern void EnumWinhwW(void);           //通过EnumWindows函数遍历所有窗口，输出窗口句柄及其标题（包含Unicode字符，枚举以宽字符形式输出     
extern std::vector<HWND> FindWinByTit(std::string targetTitle);   //通过EnumWindows函数遍历所有窗口，筛选指定标题的窗口并返回其句柄列表，完全匹配
extern std::vector<HWND> FindWindowsBySubstring(const std::string& targetSubstring); //通过EnumWindows函数遍历所有窗口，筛选包含指定子字符串的窗口并返回其句柄列表，部分匹配





#endif // __HANDLE_H__

#ifndef __HANDLE_H__
#define __HANDLE_H__
#include <string>
#include <vector>
#include <windows.h>
#include <iostream> 
#include <unordered_map>

struct EnumData {
    std::string targetTitle;
    std::vector<HWND> handles;
};

extern void EnumWinhwA(void);            //通过EnumWindows函数遍历所有窗口，输出窗口句柄及其标题，枚举以窄字符形式输出 
extern void EnumWinhwW(void);           //通过EnumWindows函数遍历所有窗口，输出窗口句柄及其标题（包含Unicode字符，枚举以宽字符形式输出     
extern std::vector<HWND> FindWinByTit(std::string targetTitle);   //通过EnumWindows函数遍历所有窗口，筛选指定标题的窗口并返回其句柄列表，完全匹配
extern std::vector<HWND> FindWindowsBySubstring(const std::string& targetSubstring); //通过EnumWindows函数遍历所有窗口，筛选包含指定子字符串的窗口并返回其句柄列表，部分匹配
extern BOOL CALLBACK EnumChildProc(HWND hwndChild, LPARAM lParam); //枚举子窗口回调函数
extern void getHwndsMap(HWND hwnd, std::unordered_map<std::string, HWND>& mpHD); //获取窗口句柄树

#endif // __HANDLE_H__

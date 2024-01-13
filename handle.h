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

extern void EnumWinhwA(void);            //ͨ��EnumWindows�����������д��ڣ�������ھ��������⣬ö����խ�ַ���ʽ��� 
extern void EnumWinhwW(void);           //ͨ��EnumWindows�����������д��ڣ�������ھ��������⣨����Unicode�ַ���ö���Կ��ַ���ʽ���     
extern std::vector<HWND> FindWinByTit(std::string targetTitle);   //ͨ��EnumWindows�����������д��ڣ�ɸѡָ������Ĵ��ڲ����������б���ȫƥ��
extern std::vector<HWND> FindWindowsBySubstring(const std::string& targetSubstring); //ͨ��EnumWindows�����������д��ڣ�ɸѡ����ָ�����ַ����Ĵ��ڲ����������б�����ƥ��
extern BOOL CALLBACK EnumChildProc(HWND hwndChild, LPARAM lParam); //ö���Ӵ��ڻص�����
extern void getHwndsMap(HWND hwnd, std::unordered_map<std::string, HWND>& mpHD); //��ȡ���ھ����

#endif // __HANDLE_H__

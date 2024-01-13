#ifndef __WIN_H__
#define __WIN_H__
#include <Windows.h>
#include <string>
#include <gdiplus.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define ISVISIABLE(hwnd) ((GetWindowLong(hwnd, GWL_STYLE) & WS_VISIBLE) == WS_VISIBLE) //�жϴ����Ƿ�ɼ�

struct MatchParams {
    std::string bigImgPath;
    std::string smallImgPath;
    double similarityThreshold;
    int resultX;
    int resultY;
};


extern bool GetWindowSize(HWND hwnd, RECT& windowRect); // ��ȡ���ڳߴ�bool GetWindowSize(HWND hwnd, RECT& windowRect)
extern bool SetWindowSize(HWND hwnd, int width, int height); // ���ô��ڳߴ�
extern bool SetWindowPosition(HWND hwnd, int x, int y); // ���ô���λ��
extern bool SetWindowVisibility(HWND hwnd, bool visible); // ���ô��ڿɼ���,visibleΪtrue��ʾ�ɼ���false��ʾ����
extern bool SetWindowTopmost(HWND hwnd, bool topmost); // ���ô����Ƿ��ö�,topmostΪtrue��ʾ�ö���false��ʾ���ö�
extern bool GetWindowSize(HWND hwnd, RECT& windowRect, int& width, int& height); // ��ȡ���ڳߴ�
extern bool SetWindowOpacity(HWND hwnd, BYTE opacity); // ���ô��ڲ�͸����
extern bool CaptureWindow(HWND hwnd, const std::string& filePath);// ��ȡ����ͼ��,GDI��ͼ��ǰ̨
extern bool CaptureWindowAndConvertToGrayscale(HWND hwnd, const std::string& filePath ); // ��ȡ��Ļͼ�񲢱���Ϊ�Ҷ�ͼ��
extern void img2gray(const std::string& imgPath, const std::string& grayPath); // ��ͼ��ת��Ϊ�Ҷ�ͼ��
extern bool findTemplateInImage(MatchParams* params); // �ڴ�ͼ�в���Сͼ
extern bool CaptureWindowInMem(HWND hwnd, cv::Mat& tmp); // ��ȡ����ͼ�񱣴浽�ڴ�
extern bool findImageInMem(HWND hwnd, MatchParams* params); // �ڴ棬�ڴ�ͼ�в���Сͼ
#endif
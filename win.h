#ifndef __WIN_H__
#define __WIN_H__
#include <Windows.h>
#include <string>
#include <gdiplus.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#define ISVISIABLE(hwnd) ((GetWindowLong(hwnd, GWL_STYLE) & WS_VISIBLE) == WS_VISIBLE) //判断窗口是否可见

struct MatchParams {
    std::string bigImgPath;
    std::string smallImgPath;
    double similarityThreshold;
    int resultX;
    int resultY;
};


extern bool GetWindowSize(HWND hwnd, RECT& windowRect); // 获取窗口尺寸bool GetWindowSize(HWND hwnd, RECT& windowRect)
extern bool SetWindowSize(HWND hwnd, int width, int height); // 设置窗口尺寸
extern bool SetWindowPosition(HWND hwnd, int x, int y); // 设置窗口位置
extern bool SetWindowVisibility(HWND hwnd, bool visible); // 设置窗口可见性,visible为true表示可见，false表示隐藏
extern bool SetWindowTopmost(HWND hwnd, bool topmost); // 设置窗口是否置顶,topmost为true表示置顶，false表示不置顶
extern bool GetWindowSize(HWND hwnd, RECT& windowRect, int& width, int& height); // 获取窗口尺寸
extern bool SetWindowOpacity(HWND hwnd, BYTE opacity); // 设置窗口不透明度
extern bool CaptureWindow(HWND hwnd, const std::string& filePath);// 截取窗口图像,GDI截图，前台
extern bool CaptureWindowAndConvertToGrayscale(HWND hwnd, const std::string& filePath ); // 截取屏幕图像并保存为灰度图像
extern void img2gray(const std::string& imgPath, const std::string& grayPath); // 将图像转换为灰度图像
extern bool findTemplateInImage(MatchParams* params); // 在大图中查找小图
extern bool CaptureWindowInMem(HWND hwnd, cv::Mat& tmp); // 截取窗口图像保存到内存
extern bool findImageInMem(HWND hwnd, MatchParams* params); // 内存，在大图中查找小图
#endif
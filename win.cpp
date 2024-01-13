#include "win.h"


//#pragma comment(lib, "GdiPlus.lib")
//
//using namespace Gdiplus;
// 函数：GetWindowSize
// 参数：hwnd - 窗口句柄
//       windowRect - 用于存储窗口矩形尺寸的 RECT 结构体的引用
// 返回值：成功获取窗口尺寸时返回 true，否则返回 false
bool GetWindowSize(HWND hwnd, RECT& windowRect) {
    // 如果窗口句柄为空，则返回 false
    if (hwnd == nullptr) {
        return false;
    }

    // 获取窗口矩形尺寸
    // GetWindowRect 返回窗口在屏幕坐标系中的矩形尺寸
    if (!GetWindowRect(hwnd, &windowRect)) {
        return false; // 获取失败时返回 false
    }

    return true; // 成功获取窗口尺寸时返回 true
}

bool GetWindowSize(HWND hwnd, RECT& windowRect, int& width, int& height) {
    // 如果窗口句柄为空，则返回 false
    if (hwnd == nullptr) {
        return false;
    }

    // 获取窗口矩形尺寸
    if (!GetWindowRect(hwnd, &windowRect)) {
        return false; // 获取失败时返回 false
    }

    // 计算窗口的宽度和高度
    width = windowRect.right - windowRect.left;
    height = windowRect.bottom - windowRect.top;

    return true; // 成功获取窗口尺寸时返回 true
}



// 函数：SetWindowSize
// 参数：hwnd - 要设置尺寸的窗口句柄
//       width - 窗口宽度
//       height - 窗口高度
// 返回值：成功设置窗口尺寸时返回 true，否则返回 false
bool SetWindowSize(HWND hwnd, int width, int height) {
    // 如果窗口句柄为空，则返回 false
    if (hwnd == nullptr) {
        return false;
    }

    // 设置窗口位置和大小
    if (!SetWindowPos(hwnd, nullptr, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER)) {
        return false; // 设置失败时返回 false
    }

    return true; // 成功设置窗口尺寸时返回 true
}


// 函数：SetWindowPosition
// 参数：hwnd - 要设置位置的窗口句柄
//       x - 窗口左上角 x 坐标
//       y - 窗口左上角 y 坐标
// 返回值：成功设置窗口位置时返回 true，否则返回 false
bool SetWindowPosition(HWND hwnd, int x, int y) {
    // 如果窗口句柄为空，则返回 false
    if (hwnd == nullptr) {
        return false;
    }

    // 设置窗口位置
    if (!SetWindowPos(hwnd, nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER)) {
        return false; // 设置失败时返回 false
    }

    return true; // 成功设置窗口位置时返回 true
}


// 函数：SetWindowVisibility
// 参数：hwnd - 要设置可见性的窗口句柄
//       visible - 是否可见（true 表示可见，false 表示隐藏）
// 返回值：成功设置窗口可见性时返回 true，否则返回 false
bool SetWindowVisibility(HWND hwnd, bool visible) {
    // 如果窗口句柄为空，则返回 false
    if (hwnd == nullptr) {
        return false;
    }

    // 根据 visible 参数来设置窗口可见性
    if (visible) {
        // 显示窗口
        if (!ShowWindow(hwnd, SW_SHOW)) {
            return false; // 设置失败时返回 false
        }
    }
    else {
        // 隐藏窗口
        if (!ShowWindow(hwnd, SW_HIDE)) {
            return false; // 设置失败时返回 false
        }
    }

    return true; // 成功设置窗口可见性时返回 true
}


// 函数：SetWindowTopmost
// 参数：hwnd - 要设置置顶的窗口句柄
//       isTopmost - 是否置顶（true 表示置顶，false 表示取消置顶）
// 返回值：成功设置窗口是否置顶时返回 true，否则返回 false
bool SetWindowTopmost(HWND hwnd, bool isTopmost) {
    // 如果窗口句柄为空，则返回 false
    if (hwnd == nullptr) {
        return false;
    }

    // 根据 isTopmost 参数设置窗口置顶状态
    if (isTopmost) {
        // 置顶窗口
        if (!SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE)) {
            return false; // 设置失败时返回 false
        }
    }
    else {
        // 取消置顶窗口
        if (!SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE)) {
            return false; // 设置失败时返回 false
        }
    }

    return true; // 成功设置窗口是否置顶时返回 true
}


// 函数：SetWindowOpacity
// 参数：hwnd - 要设置透明度的窗口句柄
//       opacity - 透明度值（0-255，0 表示完全透明，255 表示完全不透明）
// 返回值：成功设置窗口透明度时返回 true，否则返回 false
bool SetWindowOpacity(HWND hwnd, BYTE opacity) {
    // 如果窗口句柄为空，则返回 false
    if (hwnd == nullptr) {
        return false;
    }

    // 设置窗口的透明度
    if (!SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), opacity, LWA_ALPHA)) {
        return false; // 设置失败时返回 false
    }

    return true; // 成功设置窗口透明度时返回 true
}


int GetEncoderClsid(const WCHAR* format, CLSID* pClsid) {
    UINT num = 0; // number of image encoders
    UINT size = 0; // size of the image encoder array in bytes

    Gdiplus::ImageCodecInfo* pImageCodecInfo = nullptr;
    Gdiplus::GetImageEncodersSize(&num, &size);
    if (size == 0) {
        return -1; // failure
    }

    pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));
    if (pImageCodecInfo == nullptr) {
        return -1; // failure
    }

    Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);

    for (UINT j = 0; j < num; ++j) {
        if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0) {
            *pClsid = pImageCodecInfo[j].Clsid;
            free(pImageCodecInfo);
            return j; // success
        }
    }

    free(pImageCodecInfo);
    return -1; // failure
}



bool SaveBitmapToFile(HBITMAP hBitmap, const std::string& filePath) {
    Gdiplus::Bitmap bitmap(hBitmap, nullptr);

    CLSID clsid;
    if (GetEncoderClsid(L"image/jpeg", &clsid) != -1) {
        std::wstring wideFilePath(filePath.begin(), filePath.end());
        if (bitmap.Save(wideFilePath.c_str(), &clsid, nullptr) == Gdiplus::Ok) {
            return true; // 保存成功
        }
    }

    return false; // 保存失败
}



bool CaptureWindow(HWND hwnd, const std::string& filePath = "tmp.jpg") {
    // 如果窗口句柄为空，则返回 false
    if (hwnd == nullptr) {
        return false;
    }
    ULONG_PTR gdiplusToken; // 用于保存 GDI+ 初始化返回的标记
    Gdiplus::GdiplusStartupInput gdiplusStartupInput; // GDI+ 初始化输入参数
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    RECT windowRect;
    if (!GetWindowRect(hwnd, &windowRect)) {
        return false; // 获取窗口尺寸失败
    }

    // 创建设备上下文和位图
    HDC hdcScreen = GetDC(NULL);
    HDC hdcWindow = CreateCompatibleDC(hdcScreen);
    HBITMAP hBitmap = CreateCompatibleBitmap(hdcScreen, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top);
    SelectObject(hdcWindow, hBitmap);

    // 截取窗口内容
    if (!PrintWindow(hwnd, hdcWindow, 0)) {
        DeleteObject(hBitmap);
        DeleteDC(hdcWindow);
        ReleaseDC(NULL, hdcScreen);
        return false; // 截取失败
    }

    // 将位图保存为文件
    if (!SaveBitmapToFile(hBitmap, filePath)) {
        DeleteObject(hBitmap);
        DeleteDC(hdcWindow);
        ReleaseDC(NULL, hdcScreen);
        return false; // 保存失败
    }

    // 释放资源
    DeleteObject(hBitmap);
    DeleteDC(hdcWindow);
    ReleaseDC(NULL, hdcScreen);
    Gdiplus::GdiplusShutdown(gdiplusToken);
    return true; // 成功截取窗口内容并保存到文件
}


bool CaptureWindowAndConvertToGrayscale(HWND hwnd, const std::string& filePath = "tmp.jpg") {
    // 获取窗口的设备上下文
    HDC hWindowDC = GetWindowDC(hwnd);

    // 获取窗口尺寸
    RECT windowRect;
    GetClientRect(hwnd, &windowRect);
    int width = windowRect.right - windowRect.left;
    int height = windowRect.bottom - windowRect.top;

    // 创建兼容的DC和位图
    HDC hCaptureDC = CreateCompatibleDC(hWindowDC);
    HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hWindowDC, width, height);
    SelectObject(hCaptureDC, hCaptureBitmap);

    // 捕获窗口到位图
    BitBlt(hCaptureDC, 0, 0, width, height, hWindowDC, 0, 0, SRCCOPY | CAPTUREBLT);

    // 将位图转换为OpenCV图像
    BITMAPINFOHEADER bi;
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = width;
    bi.biHeight = -height; // 使图像上下颠倒
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    cv::Mat cvImage(height, width, CV_8UC4);
    GetDIBits(hCaptureDC, hCaptureBitmap, 0, height, cvImage.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    // 将BGRA图像转换为灰度图像
    cv::Mat grayscaleImage;
    cv::cvtColor(cvImage, grayscaleImage, cv::COLOR_BGR2GRAY);

    // 保存灰度图像
    cv::imwrite(filePath, grayscaleImage);

    // 清理
    DeleteObject(hCaptureBitmap);
    DeleteDC(hCaptureDC);
    ReleaseDC(hwnd, hWindowDC);

    return true;
}

bool CaptureWindowInMem(HWND hwnd, cv::Mat &tmp) {
    // 获取窗口的设备上下文
    HDC hWindowDC = GetWindowDC(hwnd);

    // 获取窗口尺寸
    RECT windowRect;
    GetClientRect(hwnd, &windowRect);
    int width = windowRect.right - windowRect.left;
    int height = windowRect.bottom - windowRect.top;

    // 创建兼容的DC和位图
    HDC hCaptureDC = CreateCompatibleDC(hWindowDC);
    HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hWindowDC, width, height);
    SelectObject(hCaptureDC, hCaptureBitmap);

    // 捕获窗口到位图
    BitBlt(hCaptureDC, 0, 0, width, height, hWindowDC, 0, 0, SRCCOPY | CAPTUREBLT);

    // 将位图转换为OpenCV图像
    BITMAPINFOHEADER bi;
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = width;
    bi.biHeight = -height; // 使图像上下颠倒
    bi.biPlanes = 1;
    bi.biBitCount = 32;
    bi.biCompression = BI_RGB;
    bi.biSizeImage = 0;
    bi.biXPelsPerMeter = 0;
    bi.biYPelsPerMeter = 0;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;

    cv::Mat cvImage(height, width, CV_8UC4);
    GetDIBits(hCaptureDC, hCaptureBitmap, 0, height, cvImage.data, (BITMAPINFO*)&bi, DIB_RGB_COLORS);

    cv::cvtColor(cvImage, tmp, cv::COLOR_BGR2GRAY);

    DeleteObject(hCaptureBitmap);
    DeleteDC(hCaptureDC);
    ReleaseDC(hwnd, hWindowDC);

    return true;
}


bool findTemplateInImage(MatchParams* params) {
    // 加载大图和小图
#include <ctime>
    auto startTime = std::chrono::high_resolution_clock::now();
    cv::Mat img_big = cv::imread(params->bigImgPath, cv::IMREAD_GRAYSCALE);
    cv::Mat img_small = cv::imread(params->smallImgPath, cv::IMREAD_GRAYSCALE);

    // 检查图像是否成功加载
    if (img_big.empty() || img_small.empty()) {
        std::cerr << "Error reading images." << std::endl;
        return false;
    }

    // 模板匹配
    cv::Mat result;
    cv::matchTemplate(img_big, img_small, result, cv::TM_CCOEFF_NORMED);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << duration.count() << std::endl;
    // 定位最佳匹配
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

    // 检查相似度
    if (maxVal >= params->similarityThreshold) {
        // 计算小图在大图中的中心位置
        params->resultX = maxLoc.x + img_small.cols / 2;
        params->resultY = maxLoc.y + img_small.rows / 2;
        return true;
    }

    return false;
}


bool findImageInMem(HWND hwnd ,MatchParams* params)
{
    cv::Mat BigImg;
    cv::Mat img_small = cv::imread(params->smallImgPath, cv::IMREAD_GRAYSCALE);

    CaptureWindowInMem(hwnd, BigImg);

    // 检查图像是否成功加载
    if (BigImg.empty() || img_small.empty()) {
        std::cerr << "Error reading images." << std::endl;
        return false;
    }
    
    // 模板匹配
    cv::Mat result;
    cv::matchTemplate(BigImg, img_small, result, cv::TM_CCOEFF_NORMED);
    // 定位最佳匹配
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

    // 检查相似度
    if (maxVal >= params->similarityThreshold) {
        // 计算小图在大图中的中心位置
        params->resultX = maxLoc.x + img_small.cols / 2;
        params->resultY = maxLoc.y + img_small.rows / 2;
        return true;
    }

    return false;
}


// 函数将彩色图像转换为灰度图像
void img2gray(const std::string& imgPath, const std::string& grayPath = "") {
    // 读取彩色图像
    cv::Mat colorImage = cv::imread(imgPath, cv::IMREAD_COLOR);

    // 检查图像是否成功加载
    if (colorImage.empty()) {
        std::cerr << "Failed to load image!" << std::endl;
        return;
    }

    // 创建灰度图像
    cv::Mat grayscaleImage;
    cv::cvtColor(colorImage, grayscaleImage, cv::COLOR_BGR2GRAY);

    // 确定灰度图像保存路径
    std::string outputPath = (grayPath.empty()) ? imgPath : grayPath;

    // 保存灰度图像
    cv::imwrite(outputPath, grayscaleImage);
    std::cout << "Grayscale image saved as " << outputPath << std::endl;
}




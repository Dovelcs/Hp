#include "win.h"


//#pragma comment(lib, "GdiPlus.lib")
//
//using namespace Gdiplus;
// ������GetWindowSize
// ������hwnd - ���ھ��
//       windowRect - ���ڴ洢���ھ��γߴ�� RECT �ṹ�������
// ����ֵ���ɹ���ȡ���ڳߴ�ʱ���� true�����򷵻� false
bool GetWindowSize(HWND hwnd, RECT& windowRect) {
    // ������ھ��Ϊ�գ��򷵻� false
    if (hwnd == nullptr) {
        return false;
    }

    // ��ȡ���ھ��γߴ�
    // GetWindowRect ���ش�������Ļ����ϵ�еľ��γߴ�
    if (!GetWindowRect(hwnd, &windowRect)) {
        return false; // ��ȡʧ��ʱ���� false
    }

    return true; // �ɹ���ȡ���ڳߴ�ʱ���� true
}

bool GetWindowSize(HWND hwnd, RECT& windowRect, int& width, int& height) {
    // ������ھ��Ϊ�գ��򷵻� false
    if (hwnd == nullptr) {
        return false;
    }

    // ��ȡ���ھ��γߴ�
    if (!GetWindowRect(hwnd, &windowRect)) {
        return false; // ��ȡʧ��ʱ���� false
    }

    // ���㴰�ڵĿ�Ⱥ͸߶�
    width = windowRect.right - windowRect.left;
    height = windowRect.bottom - windowRect.top;

    return true; // �ɹ���ȡ���ڳߴ�ʱ���� true
}



// ������SetWindowSize
// ������hwnd - Ҫ���óߴ�Ĵ��ھ��
//       width - ���ڿ��
//       height - ���ڸ߶�
// ����ֵ���ɹ����ô��ڳߴ�ʱ���� true�����򷵻� false
bool SetWindowSize(HWND hwnd, int width, int height) {
    // ������ھ��Ϊ�գ��򷵻� false
    if (hwnd == nullptr) {
        return false;
    }

    // ���ô���λ�úʹ�С
    if (!SetWindowPos(hwnd, nullptr, 0, 0, width, height, SWP_NOMOVE | SWP_NOZORDER)) {
        return false; // ����ʧ��ʱ���� false
    }

    return true; // �ɹ����ô��ڳߴ�ʱ���� true
}


// ������SetWindowPosition
// ������hwnd - Ҫ����λ�õĴ��ھ��
//       x - �������Ͻ� x ����
//       y - �������Ͻ� y ����
// ����ֵ���ɹ����ô���λ��ʱ���� true�����򷵻� false
bool SetWindowPosition(HWND hwnd, int x, int y) {
    // ������ھ��Ϊ�գ��򷵻� false
    if (hwnd == nullptr) {
        return false;
    }

    // ���ô���λ��
    if (!SetWindowPos(hwnd, nullptr, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER)) {
        return false; // ����ʧ��ʱ���� false
    }

    return true; // �ɹ����ô���λ��ʱ���� true
}


// ������SetWindowVisibility
// ������hwnd - Ҫ���ÿɼ��ԵĴ��ھ��
//       visible - �Ƿ�ɼ���true ��ʾ�ɼ���false ��ʾ���أ�
// ����ֵ���ɹ����ô��ڿɼ���ʱ���� true�����򷵻� false
bool SetWindowVisibility(HWND hwnd, bool visible) {
    // ������ھ��Ϊ�գ��򷵻� false
    if (hwnd == nullptr) {
        return false;
    }

    // ���� visible ���������ô��ڿɼ���
    if (visible) {
        // ��ʾ����
        if (!ShowWindow(hwnd, SW_SHOW)) {
            return false; // ����ʧ��ʱ���� false
        }
    }
    else {
        // ���ش���
        if (!ShowWindow(hwnd, SW_HIDE)) {
            return false; // ����ʧ��ʱ���� false
        }
    }

    return true; // �ɹ����ô��ڿɼ���ʱ���� true
}


// ������SetWindowTopmost
// ������hwnd - Ҫ�����ö��Ĵ��ھ��
//       isTopmost - �Ƿ��ö���true ��ʾ�ö���false ��ʾȡ���ö���
// ����ֵ���ɹ����ô����Ƿ��ö�ʱ���� true�����򷵻� false
bool SetWindowTopmost(HWND hwnd, bool isTopmost) {
    // ������ھ��Ϊ�գ��򷵻� false
    if (hwnd == nullptr) {
        return false;
    }

    // ���� isTopmost �������ô����ö�״̬
    if (isTopmost) {
        // �ö�����
        if (!SetWindowPos(hwnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE)) {
            return false; // ����ʧ��ʱ���� false
        }
    }
    else {
        // ȡ���ö�����
        if (!SetWindowPos(hwnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE)) {
            return false; // ����ʧ��ʱ���� false
        }
    }

    return true; // �ɹ����ô����Ƿ��ö�ʱ���� true
}


// ������SetWindowOpacity
// ������hwnd - Ҫ����͸���ȵĴ��ھ��
//       opacity - ͸����ֵ��0-255��0 ��ʾ��ȫ͸����255 ��ʾ��ȫ��͸����
// ����ֵ���ɹ����ô���͸����ʱ���� true�����򷵻� false
bool SetWindowOpacity(HWND hwnd, BYTE opacity) {
    // ������ھ��Ϊ�գ��򷵻� false
    if (hwnd == nullptr) {
        return false;
    }

    // ���ô��ڵ�͸����
    if (!SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), opacity, LWA_ALPHA)) {
        return false; // ����ʧ��ʱ���� false
    }

    return true; // �ɹ����ô���͸����ʱ���� true
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
            return true; // ����ɹ�
        }
    }

    return false; // ����ʧ��
}



bool CaptureWindow(HWND hwnd, const std::string& filePath = "tmp.jpg") {
    // ������ھ��Ϊ�գ��򷵻� false
    if (hwnd == nullptr) {
        return false;
    }
    ULONG_PTR gdiplusToken; // ���ڱ��� GDI+ ��ʼ�����صı��
    Gdiplus::GdiplusStartupInput gdiplusStartupInput; // GDI+ ��ʼ���������
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    RECT windowRect;
    if (!GetWindowRect(hwnd, &windowRect)) {
        return false; // ��ȡ���ڳߴ�ʧ��
    }

    // �����豸�����ĺ�λͼ
    HDC hdcScreen = GetDC(NULL);
    HDC hdcWindow = CreateCompatibleDC(hdcScreen);
    HBITMAP hBitmap = CreateCompatibleBitmap(hdcScreen, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top);
    SelectObject(hdcWindow, hBitmap);

    // ��ȡ��������
    if (!PrintWindow(hwnd, hdcWindow, 0)) {
        DeleteObject(hBitmap);
        DeleteDC(hdcWindow);
        ReleaseDC(NULL, hdcScreen);
        return false; // ��ȡʧ��
    }

    // ��λͼ����Ϊ�ļ�
    if (!SaveBitmapToFile(hBitmap, filePath)) {
        DeleteObject(hBitmap);
        DeleteDC(hdcWindow);
        ReleaseDC(NULL, hdcScreen);
        return false; // ����ʧ��
    }

    // �ͷ���Դ
    DeleteObject(hBitmap);
    DeleteDC(hdcWindow);
    ReleaseDC(NULL, hdcScreen);
    Gdiplus::GdiplusShutdown(gdiplusToken);
    return true; // �ɹ���ȡ�������ݲ����浽�ļ�
}


bool CaptureWindowAndConvertToGrayscale(HWND hwnd, const std::string& filePath = "tmp.jpg") {
    // ��ȡ���ڵ��豸������
    HDC hWindowDC = GetWindowDC(hwnd);

    // ��ȡ���ڳߴ�
    RECT windowRect;
    GetClientRect(hwnd, &windowRect);
    int width = windowRect.right - windowRect.left;
    int height = windowRect.bottom - windowRect.top;

    // �������ݵ�DC��λͼ
    HDC hCaptureDC = CreateCompatibleDC(hWindowDC);
    HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hWindowDC, width, height);
    SelectObject(hCaptureDC, hCaptureBitmap);

    // ���񴰿ڵ�λͼ
    BitBlt(hCaptureDC, 0, 0, width, height, hWindowDC, 0, 0, SRCCOPY | CAPTUREBLT);

    // ��λͼת��ΪOpenCVͼ��
    BITMAPINFOHEADER bi;
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = width;
    bi.biHeight = -height; // ʹͼ�����µߵ�
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

    // ��BGRAͼ��ת��Ϊ�Ҷ�ͼ��
    cv::Mat grayscaleImage;
    cv::cvtColor(cvImage, grayscaleImage, cv::COLOR_BGR2GRAY);

    // ����Ҷ�ͼ��
    cv::imwrite(filePath, grayscaleImage);

    // ����
    DeleteObject(hCaptureBitmap);
    DeleteDC(hCaptureDC);
    ReleaseDC(hwnd, hWindowDC);

    return true;
}

bool CaptureWindowInMem(HWND hwnd, cv::Mat &tmp) {
    // ��ȡ���ڵ��豸������
    HDC hWindowDC = GetWindowDC(hwnd);

    // ��ȡ���ڳߴ�
    RECT windowRect;
    GetClientRect(hwnd, &windowRect);
    int width = windowRect.right - windowRect.left;
    int height = windowRect.bottom - windowRect.top;

    // �������ݵ�DC��λͼ
    HDC hCaptureDC = CreateCompatibleDC(hWindowDC);
    HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hWindowDC, width, height);
    SelectObject(hCaptureDC, hCaptureBitmap);

    // ���񴰿ڵ�λͼ
    BitBlt(hCaptureDC, 0, 0, width, height, hWindowDC, 0, 0, SRCCOPY | CAPTUREBLT);

    // ��λͼת��ΪOpenCVͼ��
    BITMAPINFOHEADER bi;
    bi.biSize = sizeof(BITMAPINFOHEADER);
    bi.biWidth = width;
    bi.biHeight = -height; // ʹͼ�����µߵ�
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
    // ���ش�ͼ��Сͼ
#include <ctime>
    auto startTime = std::chrono::high_resolution_clock::now();
    cv::Mat img_big = cv::imread(params->bigImgPath, cv::IMREAD_GRAYSCALE);
    cv::Mat img_small = cv::imread(params->smallImgPath, cv::IMREAD_GRAYSCALE);

    // ���ͼ���Ƿ�ɹ�����
    if (img_big.empty() || img_small.empty()) {
        std::cerr << "Error reading images." << std::endl;
        return false;
    }

    // ģ��ƥ��
    cv::Mat result;
    cv::matchTemplate(img_big, img_small, result, cv::TM_CCOEFF_NORMED);
    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);
    std::cout << duration.count() << std::endl;
    // ��λ���ƥ��
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

    // ������ƶ�
    if (maxVal >= params->similarityThreshold) {
        // ����Сͼ�ڴ�ͼ�е�����λ��
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

    // ���ͼ���Ƿ�ɹ�����
    if (BigImg.empty() || img_small.empty()) {
        std::cerr << "Error reading images." << std::endl;
        return false;
    }
    
    // ģ��ƥ��
    cv::Mat result;
    cv::matchTemplate(BigImg, img_small, result, cv::TM_CCOEFF_NORMED);
    // ��λ���ƥ��
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

    // ������ƶ�
    if (maxVal >= params->similarityThreshold) {
        // ����Сͼ�ڴ�ͼ�е�����λ��
        params->resultX = maxLoc.x + img_small.cols / 2;
        params->resultY = maxLoc.y + img_small.rows / 2;
        return true;
    }

    return false;
}


// ��������ɫͼ��ת��Ϊ�Ҷ�ͼ��
void img2gray(const std::string& imgPath, const std::string& grayPath = "") {
    // ��ȡ��ɫͼ��
    cv::Mat colorImage = cv::imread(imgPath, cv::IMREAD_COLOR);

    // ���ͼ���Ƿ�ɹ�����
    if (colorImage.empty()) {
        std::cerr << "Failed to load image!" << std::endl;
        return;
    }

    // �����Ҷ�ͼ��
    cv::Mat grayscaleImage;
    cv::cvtColor(colorImage, grayscaleImage, cv::COLOR_BGR2GRAY);

    // ȷ���Ҷ�ͼ�񱣴�·��
    std::string outputPath = (grayPath.empty()) ? imgPath : grayPath;

    // ����Ҷ�ͼ��
    cv::imwrite(outputPath, grayscaleImage);
    std::cout << "Grayscale image saved as " << outputPath << std::endl;
}




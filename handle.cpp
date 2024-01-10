#include "handle.h"
using namespace std;

/*****************************************************************************
Copyright: 1988-1999, 520ll Tech. Co., Ltd.
File name: handle.cpp
Description: 用于通过EnumWindows函数遍历所有窗口，输出窗口句柄及其标题
Author: Dovelcs
Version: 1.0
Date: 2024-01-10
History:
    2024-01-10, Dovelcs
        - 初始版本
*****************************************************************************/

// 函数：EnumWinhw
// 描述：通过EnumWindows函数遍历所有窗口，输出窗口句柄及其标题
void EnumWinhwA(void)
{
    // 创建一个EnumData对象，用于传递数据给EnumWindows的回调函数
    EnumData data;
    //SetConsoleOutputCP(CP_ACP);
    // 调用EnumWindows函数，遍历所有顶级窗口
    EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL {
        // 将lParam转换为EnumData指针，以便在回调函数中访问传递的数据
        EnumData* _data = reinterpret_cast<EnumData*>(lParam);

        // 用于存储窗口标题的字符数组
        char windowTitle[256];

        // 获取窗口标题
        GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle));

        // 输出窗口句柄和标题到标准输出
        std::cout << hwnd << "\t" << windowTitle << std::endl;

        // 返回TRUE，以继续枚举窗口
        return TRUE;
        }, reinterpret_cast<LPARAM>(&data)); // 传递EnumData对象的指针作为枚举窗口回调函数的参数
}


/*****************************************************************************
Copyright: 1988-1999, 520ll Tech. Co., Ltd.
File name: handle.cpp
Description: 用于通过EnumWindows函数遍历所有窗口，输出窗口句柄及其标题（包含Unicode字符）
Author: Dovelcs
Version: 1.0
Date: 2024-01-10
History:
    2024-01-10, Dovelcs
        - 初始版本
*****************************************************************************/

// 回调函数，用于处理EnumWindows的每个窗口
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    // 将lParam转换为EnumData指针，以便在回调函数中访问传递的数据
    EnumData* _data = reinterpret_cast<EnumData*>(lParam);

    // 用于存储窗口标题的宽字符数组
    wchar_t windowTitle[256];

    // 获取窗口标题
    GetWindowTextW(hwnd, windowTitle, sizeof(windowTitle) / sizeof(windowTitle[0]));

    // 输出窗口句柄和标题到宽字符流
    std::wcout << hwnd << L"\t" << windowTitle << std::endl;

    // 返回TRUE，以继续枚举窗口
    return TRUE;
}

// 函数：EnumWinhwW
// 描述：通过EnumWindows函数遍历所有窗口，输出窗口句柄及其标题（包含Unicode字符）
void EnumWinhwW(void)
{
    // 创建一个EnumData对象，用于传递数据给EnumWindows的回调函数
    EnumData data;

    // 设置 wcout 的本地化信息为中文（简体中文）
    wcout.imbue(locale("zh_CN"));

    // 调用EnumWindows函数，遍历所有顶级窗口，将回调函数传递给它
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&data));
}


/*****************************************************************************
Copyright: 1988-1999, 520ll Tech. Co., Ltd.
File name: handle.cpp
Description: 通过EnumWindows函数遍历所有窗口，筛选指定标题的窗口并返回其句柄列表
Author: Dovelcs
Version: 1.0
Date: 2024-01-10
History:
    2024-01-10, Dovelcs
        - 初始版本
*****************************************************************************/
// 函数：FindWinByHw
// 描述：通过EnumWindows函数遍历所有窗口，筛选指定标题的窗口并返回其句柄列表
std::vector<HWND> FindWinByTit(std::string targetTitle)
{
	// 创建一个EnumData对象，用于传递数据给EnumWindows的回调函数
	EnumData data;
	data.targetTitle = targetTitle;

	// 调用EnumWindows函数，遍历所有顶级窗口
    EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL {
		// 将lParam转换为EnumData指针，以便在回调函数中访问传递的数据
		EnumData* _data = reinterpret_cast<EnumData*>(lParam);

		// 用于存储窗口标题的字符数组
		char windowTitle[256];

		// 获取窗口标题
		GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle));

		// 输出窗口句柄和标题到标准输出
		//std::cout << hwnd << "\t" << windowTitle << std::endl;
        if (strcmp(windowTitle, _data->targetTitle.c_str()) == 0)
        {
			_data->handles.push_back(hwnd);
		}

		// 返回TRUE，以继续枚举窗口
		return TRUE;
		}, reinterpret_cast<LPARAM>(&data)); // 传递EnumData对象的指针作为枚举窗口回调函数的参数

	return data.handles;
}

// 函数：FindWindowsBySubstring
// 描述：通过EnumWindows函数遍历所有窗口，筛选包含指定子字符串的窗口并返回其句柄列表
std::vector<HWND> FindWindowsBySubstring(const std::string& targetSubstring)
{
    // 创建一个EnumData对象，用于传递数据给EnumWindows的回调函数
    EnumData data;
    data.targetTitle = targetSubstring;

    // 调用EnumWindows函数，遍历所有顶级窗口
    EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL {
        // 将lParam转换为EnumData指针，以便在回调函数中访问传递的数据
        EnumData* _data = reinterpret_cast<EnumData*>(lParam);

        // 用于存储窗口标题的字符数组
        char windowTitle[256];

        // 获取窗口标题
        GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle));

        // 使用 std::string 的 find 函数检查窗口标题是否包含目标子字符串
        if (std::string(windowTitle).find(_data->targetTitle) != std::string::npos)
        {
            _data->handles.push_back(hwnd);
        }

        // 返回TRUE，以继续枚举窗口
        return TRUE;
        }, reinterpret_cast<LPARAM>(&data)); // 传递EnumData对象的指针作为枚举窗口回调函数的参数

    // 返回符合条件的窗口句柄列表
    return data.handles;
}

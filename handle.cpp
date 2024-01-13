#include "handle.h"

using namespace std;
/*****************************************************************************
Copyright: 1988-1999, 520ll Tech. Co., Ltd.
File name: handle.cpp
Description: ����ͨ��EnumWindows�����������д��ڣ�������ھ���������
Author: Dovelcs
Version: 1.0
Date: 2024-01-10
History:
    2024-01-10, Dovelcs
        - ��ʼ�汾
*****************************************************************************/

// ������EnumWinhw
// ������ͨ��EnumWindows�����������д��ڣ�������ھ���������
void EnumWinhwA(void)
{
    // ����һ��EnumData�������ڴ������ݸ�EnumWindows�Ļص�����
    EnumData data;
    //SetConsoleOutputCP(CP_ACP);
    // ����EnumWindows�������������ж�������
    EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL {
        // ��lParamת��ΪEnumDataָ�룬�Ա��ڻص������з��ʴ��ݵ�����
        EnumData* _data = reinterpret_cast<EnumData*>(lParam);

        // ���ڴ洢���ڱ�����ַ�����
        char windowTitle[256];

        // ��ȡ���ڱ���
        GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle));

        // ������ھ���ͱ��⵽��׼���
        std::cout << hwnd << "\t" << windowTitle << std::endl;

        // ����TRUE���Լ���ö�ٴ���
        return TRUE;
        }, reinterpret_cast<LPARAM>(&data)); // ����EnumData�����ָ����Ϊö�ٴ��ڻص������Ĳ���
}


/*****************************************************************************
Copyright: 1988-1999, 520ll Tech. Co., Ltd.
File name: handle.cpp
Description: ����ͨ��EnumWindows�����������д��ڣ�������ھ��������⣨����Unicode�ַ���
Author: Dovelcs
Version: 1.0
Date: 2024-01-10
History:
    2024-01-10, Dovelcs
        - ��ʼ�汾
*****************************************************************************/

// �ص����������ڴ���EnumWindows��ÿ������
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    // ��lParamת��ΪEnumDataָ�룬�Ա��ڻص������з��ʴ��ݵ�����
    EnumData* _data = reinterpret_cast<EnumData*>(lParam);

    // ���ڴ洢���ڱ���Ŀ��ַ�����
    wchar_t windowTitle[256];

    // ��ȡ���ڱ���
    GetWindowTextW(hwnd, windowTitle, sizeof(windowTitle) / sizeof(windowTitle[0]));

    // ������ھ���ͱ��⵽���ַ���
    std::wcout << hwnd << L"\t" << windowTitle << std::endl;

    // ����TRUE���Լ���ö�ٴ���
    return TRUE;
}

// ������EnumWinhwW
// ������ͨ��EnumWindows�����������д��ڣ�������ھ��������⣨����Unicode�ַ���
void EnumWinhwW(void)
{
    // ����һ��EnumData�������ڴ������ݸ�EnumWindows�Ļص�����
    EnumData data;

    // ���� wcout �ı��ػ���ϢΪ���ģ��������ģ�
    wcout.imbue(locale("zh_CN"));

    // ����EnumWindows�������������ж������ڣ����ص��������ݸ���
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&data));
}


/*****************************************************************************
Copyright: 1988-1999, 520ll Tech. Co., Ltd.
File name: handle.cpp
Description: ͨ��EnumWindows�����������д��ڣ�ɸѡָ������Ĵ��ڲ����������б�
Author: Dovelcs
Version: 1.0
Date: 2024-01-10
History:
    2024-01-10, Dovelcs
        - ��ʼ�汾
*****************************************************************************/
// ������FindWinByHw
// ������ͨ��EnumWindows�����������д��ڣ�ɸѡָ������Ĵ��ڲ����������б�
std::vector<HWND> FindWinByTit(std::string targetTitle)
{
	// ����һ��EnumData�������ڴ������ݸ�EnumWindows�Ļص�����
	EnumData data;
	data.targetTitle = targetTitle;

	// ����EnumWindows�������������ж�������
    EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL {
		// ��lParamת��ΪEnumDataָ�룬�Ա��ڻص������з��ʴ��ݵ�����
		EnumData* _data = reinterpret_cast<EnumData*>(lParam);

		// ���ڴ洢���ڱ�����ַ�����
		char windowTitle[256];

		// ��ȡ���ڱ���
		GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle));

		// ������ھ���ͱ��⵽��׼���
		//std::cout << hwnd << "\t" << windowTitle << std::endl;
        if (strcmp(windowTitle, _data->targetTitle.c_str()) == 0)
        {
			_data->handles.push_back(hwnd);
		}

		// ����TRUE���Լ���ö�ٴ���
		return TRUE;
		}, reinterpret_cast<LPARAM>(&data)); // ����EnumData�����ָ����Ϊö�ٴ��ڻص������Ĳ���

	return data.handles;
}

// ������FindWindowsBySubstring
// ������ͨ��EnumWindows�����������д��ڣ�ɸѡ����ָ�����ַ����Ĵ��ڲ����������б�
std::vector<HWND> FindWindowsBySubstring(const std::string& targetSubstring)
{
    // ����һ��EnumData�������ڴ������ݸ�EnumWindows�Ļص�����
    EnumData data;
    data.targetTitle = targetSubstring;

    // ����EnumWindows�������������ж�������
    EnumWindows([](HWND hwnd, LPARAM lParam) -> BOOL {
        // ��lParamת��ΪEnumDataָ�룬�Ա��ڻص������з��ʴ��ݵ�����
        EnumData* _data = reinterpret_cast<EnumData*>(lParam);

        // ���ڴ洢���ڱ�����ַ�����
        char windowTitle[256];

        // ��ȡ���ڱ���
        GetWindowTextA(hwnd, windowTitle, sizeof(windowTitle));

        // ʹ�� std::string �� find ������鴰�ڱ����Ƿ����Ŀ�����ַ���
        if (std::string(windowTitle).find(_data->targetTitle) != std::string::npos)
        {
            //std::cout << hwnd << "\t" << windowTitle << std::endl;
            _data->handles.push_back(hwnd);
        }

        // ����TRUE���Լ���ö�ٴ���
        return TRUE;
        }, reinterpret_cast<LPARAM>(&data)); // ����EnumData�����ָ����Ϊö�ٴ��ڻص������Ĳ���

    // ���ط��������Ĵ��ھ���б�
    return data.handles;
}

BOOL CALLBACK EnumChildProc(HWND hwndChild, LPARAM lParam) {
    std::vector<HWND>* childHwnds = reinterpret_cast<std::vector<HWND>*>(lParam);
    childHwnds->push_back(hwndChild);
    return TRUE; // ���� TRUE �Լ���ö����һ���Ӵ���
}


BOOL CALLBACK EnumChildProc2(HWND hwndChild, LPARAM lParam) {
    std::unordered_map<std::string, HWND>* mpHD = reinterpret_cast<std::unordered_map<std::string, HWND>*>(lParam);

    // ��ȡ�Ӵ��ڵı����ı�
    const int bufferSize = 256;
    char buffer[bufferSize];
    GetWindowTextA(hwndChild, buffer, bufferSize);

    // ʹ�ñ����ı���Ϊ�������Ӵ��ھ���洢��unordered_map��
    //std::cout<< buffer << std::endl;
    (*mpHD)[buffer] = hwndChild;

    return TRUE; // ���� TRUE �Լ���ö����һ���Ӵ���
}

void getHwndsMap(HWND hwnd, std::unordered_map<std::string, HWND>& mpHD) {
    EnumChildWindows(hwnd, EnumChildProc2, reinterpret_cast<LPARAM>(&mpHD));
}
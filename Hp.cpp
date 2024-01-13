#include "handle.h"
#include "win.h"
#include "mouse.h"
#include <windows.h>

int main()
{
	std::unordered_map<std::string, HWND> mptmp;

	//通过EnumWindows函数遍历所有窗口
	std::vector<HWND> handles = FindWindowsBySubstring("MuMu模拟器12");
	

	//通过父句柄获取完整的句柄树
	getHwndsMap(handles[0], mptmp);

	for (auto it = mptmp.begin(); it != mptmp.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}

	//截图到本地的示例
	//CaptureWindowAndConvertToGrayscale(handles[0], "test1.bmp");
	//CaptureWindowAndConvertToGrayscale(mptmp["MuMuPlayer"], "test2.bmp");

#if 0 //使用截图并且匹配本地图片，并点击MUMU模拟器窗口
	MatchParams params = { "test2.bmp","2.png",0.9 };
	findTemplateInImage(&params);
	std::cout<<params.resultX<<" "<<params.resultY<<std::endl;
	MouseLeftClick(mptmp["MuMuPlayer"], params.resultX, params.resultY);
#else//通过读取内存中的图片，并匹配本地图片，并点击MUMU模拟器窗口
	MatchParams params = { "test2.bmp","2.png",0.9 };
	findImageInMem(mptmp["MuMuPlayer"], &params);
	std::cout << params.resultX << " " << params.resultY << std::endl;
	MouseLeftClick(mptmp["MuMuPlayer"], params.resultX, params.resultY);


#endif
	return 0;
}

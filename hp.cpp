#include "handle.h"


int main()
{
	//EnumWinhwA();
	//EnumWinhwW();
	//std::vector<HWND> handles = FindWinByTit("微信");
	std::vector<HWND> handles = FindWindowsBySubstring("百度网盘");
	//std::vector<HWND> handles = FindWindowsBySubstring("微信");
	for (auto handle : handles)
	{
		std::cout<<ISVISIABLE(handle)<<std::endl;
		std::cout << handle << std::endl;
	}
	
	
	return 0;
}

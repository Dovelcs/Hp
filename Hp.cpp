#include "handle.h"
#include "win.h"
#include "mouse.h"
#include <windows.h>

int main()
{
	std::unordered_map<std::string, HWND> mptmp;

	//ͨ��EnumWindows�����������д���
	std::vector<HWND> handles = FindWindowsBySubstring("MuMuģ����12");
	

	//ͨ���������ȡ�����ľ����
	getHwndsMap(handles[0], mptmp);

	for (auto it = mptmp.begin(); it != mptmp.end(); it++)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}

	//��ͼ�����ص�ʾ��
	//CaptureWindowAndConvertToGrayscale(handles[0], "test1.bmp");
	//CaptureWindowAndConvertToGrayscale(mptmp["MuMuPlayer"], "test2.bmp");

#if 0 //ʹ�ý�ͼ����ƥ�䱾��ͼƬ�������MUMUģ��������
	MatchParams params = { "test2.bmp","2.png",0.9 };
	findTemplateInImage(&params);
	std::cout<<params.resultX<<" "<<params.resultY<<std::endl;
	MouseLeftClick(mptmp["MuMuPlayer"], params.resultX, params.resultY);
#else//ͨ����ȡ�ڴ��е�ͼƬ����ƥ�䱾��ͼƬ�������MUMUģ��������
	MatchParams params = { "test2.bmp","2.png",0.9 };
	findImageInMem(mptmp["MuMuPlayer"], &params);
	std::cout << params.resultX << " " << params.resultY << std::endl;
	MouseLeftClick(mptmp["MuMuPlayer"], params.resultX, params.resultY);


#endif
	return 0;
}

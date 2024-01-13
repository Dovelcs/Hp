# Hp
这是一个开源的项目。主要用来方便处理windows上的一些事件，例如查找句柄，简单的鼠标后台、前台、找图等功能。为了方便移植，编码会尽量带有更多的C风格，以及更多的注释。

Tips:所有的cpp为直接操作的源码，h文件为可包含的头。作者原则上希望直接复制cpp和h可以在任何windows环境直接编译通过。

文件夹说明：
  handle.cpp handle.h   句柄操作相关接口
  mouse.cpp mouse.h     鼠标操作相关接口
  win.cpp   win.h       基于win库的截图基于opencv的模板匹配接口


  目前除win库以外依赖opencv，预计会在三个月内还会添加可自动部署的带ai预测识别的api接口

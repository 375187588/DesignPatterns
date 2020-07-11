#检查cmake的版本 至少是2.8.3版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)

#输出消息
MESSAGE("---------------------C++实现的7种创建型模式范例--------------------------")

#工程名字
#SET(entryName "CreationalPattern")
#SET(entryName "CreationalPattern")

#MESSAGE("--------------------正在生成" ${entryName} "------------------------------")
#PROJECT(${objname})

#c++11支持
SET(CMAKE_CXX_FLAGS "-std=c++11" )

#创建型模式
ADD_SUBDIRECTORY(AbstractFactory)
ADD_SUBDIRECTORY(Builder)
ADD_SUBDIRECTORY(CComposite)
ADD_SUBDIRECTORY(Clone)
ADD_SUBDIRECTORY(FAbstractFactory)
ADD_SUBDIRECTORY(Factory)
ADD_SUBDIRECTORY(Singleton)
#结束提示
MESSAGE("执行命令结束")
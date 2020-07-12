#检查cmake的版本 至少是2.8.3版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)

#输出消息
MESSAGE("---------------------C++实现的23种设计模式范例--------------------------")

#工程名字
SET(objname "DesignPatterns")
SET(entryName "DesignPatterns")
#放在同级目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}/bin) 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(PATH ${PROJECT_SOURCE_DIR})

MESSAGE("--------------------正在生成" ${objname} "------------------------------")
PROJECT(${objname})

#c++11支持
SET(CMAKE_CXX_FLAGS "-std=c++11" )

#创建型模式
ADD_SUBDIRECTORY(CreationalPattern)
#结构型模式
ADD_SUBDIRECTORY(StructuralPattern)
#行为型模式
ADD_SUBDIRECTORY(BehaviorPattern)
#结束提示
MESSAGE("执行命令结束")



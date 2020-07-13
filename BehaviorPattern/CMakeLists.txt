#检查cmake的版本 至少是2.8.3版本
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)

#输出消息
MESSAGE("---------------------C++实现的11种行为型模式范例--------------------------")

#工程名字
SET(entryName "BehaviorPattern")

MESSAGE("--------------------正在生成" ${entryName} "------------------------------")
#PROJECT(${entryName})

#c++11支持
SET(CMAKE_CXX_FLAGS "-std=c++11" )
ADD_DEFINITIONS(-std=c++11)
add_compile_options(-std=c++11)

#行为型模式
ADD_SUBDIRECTORY(ChainOfResponsibility)
ADD_SUBDIRECTORY(Command)
ADD_SUBDIRECTORY(Interpreter)
ADD_SUBDIRECTORY(Iterator)
ADD_SUBDIRECTORY(Mediator)
ADD_SUBDIRECTORY(Memento)
ADD_SUBDIRECTORY(Observer)
ADD_SUBDIRECTORY(State)
ADD_SUBDIRECTORY(Strategy)
ADD_SUBDIRECTORY(Template)
ADD_SUBDIRECTORY(Visitor)

#结束提示
MESSAGE("执行命令结束")



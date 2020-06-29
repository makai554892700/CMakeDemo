## msys2安装
* msys2下载下来是个可执行文件 打开
* 一直下一步即可
* 安装完打开 MingGW64 运行


        pacman --noconfirm -Syu
        pacman --noconfirm -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake
        pacman --noconfirm -S mingw-w64-x86_64-extra-cmake-modules make tar
        pacman --noconfirm -S mingw64/mingw-w64-x86_64-cyrus-sasl
        pacman --noconfirm -S git
        
# windows下打.a 包(msys2下运行)


        mkdir build
        cd build
        cmake .. -G "Unix Makefiles"
        make

# windows下打.lib 包(Develop PowerShell 下运行)


        mkdir build
        cd build
        cmake ..
        MSBuild hello.sln /t:Rebuild /p:Configuration=Release /p:Platform=x64

# CMakeLists.txt 个人简介
* $ 变量使用，例：
    * ${CMAKE_CURRENT_SOURCE_DIR} 当前项目根目录
* cmake_minimum_required 限定最小cmake版本，例：
    * cmake_minimum_required(VERSION 3.16) 设置最小cmake版本为3.16
* set 设置变量，例：
    * set(CMAKE_CXX_STANDARD 14) 设置 CMAKE_CXX_STANDARD 为14
* file 组文件或文件夹，例：
    * file(GLOB ODA_INCLUDE_DIRS
              ${CMAKE_CURRENT_SOURCE_DIR}/hello/inc
              ${CMAKE_CURRENT_SOURCE_DIR}/world/inc
              ${CMAKE_CURRENT_SOURCE_DIR}/hello_world/inc
              ) 将当前项目的 hello/inc world/inc hello_world/inc 目录放置于变量 ODA_INCLUDE_DIRS 内 
* if 判断，例：
    * if (CMAKE_SYSTEM_NAME MATCHES "Windows") 判断是否为windows系统
* message 输出log，例：
    * message("ODA_SO_FILES = ${ODA_SO_FILES}") 打印 ODA_SO_FILES 变量 
* include_directories 引入头文件目录，使得目录下的.h/.hpp文件可以被引用，例：
    * include_directories(
              ${ODA_INCLUDE_DIRS}
      ) 引入 ODA_INCLUDE_DIRS 变量包含的目录
* link_directories 链接目录，用于查找静态或动态库，例：
    * link_directories(
              ${ODA_SO_DIRS}
      ) 链接变量 ODA_SO_DIRS 下的所有目录
* add_executable 定义可执行文件及包含的源文件，例：
    * add_executable(ctemp
              main.cpp
              ) 定义可执行文件为ctemp，包含main.cpp 源文件
* target_link_libraries 链接第三方静态/动态库，例：
    * target_link_libraries(ctemp
              -Wl,--start-group
              ${ODA_SO_FILES}
              -Wl,--end-group
              ) 链接 ODA_SO_FILES 变量下的库文件至ctemp
              --Wl,--start-group 与 -Wl,--end-group 配合使用可以忽略多个文件的互相引用的顺序关系
* add_library 定义生成静态/动态库，例：
    * add_library(hello ${CMAKE_CURRENT_SOURCE_DIR}/src/hello.cpp) 定义生成hello的动态库
    * add_library(hello STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/hello.cpp) 定义生成hello的静态库
    * add_library(hello SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/hello.cpp) 定义生成hello的动态库

cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

project(nexus_app_launcher)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static -g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -g")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -static -O2")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -O2")
endif()

include_directories(include)

# load imgui as a cmake project
add_subdirectory(src/imgui)

add_library(nexus_app_launcher SHARED src/main.cpp src/globals.cpp src/gui.cpp src/settings.cpp
                                     src/localization.cpp)
target_link_libraries(nexus_app_launcher imgui)
# 界面文案包含简体中文：源文件为 UTF-8，且执行字符集也需按 UTF-8 编码
# (MSVC: /utf-8；MinGW/Clang: -finput-charset/-fexec-charset)
if(MSVC)
    target_compile_options(nexus_app_launcher PRIVATE /utf-8)
else()
    target_compile_options(nexus_app_launcher PRIVATE -finput-charset=UTF-8 -fexec-charset=UTF-8)
endif()
set_property(TARGET nexus_app_launcher PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
# 汉化版产物文件名：nexus_app_launcher_cn.dll（去掉 MinGW 默认的 lib 前缀）
set_target_properties(nexus_app_launcher PROPERTIES OUTPUT_NAME "nexus_app_launcher_cn" PREFIX "")

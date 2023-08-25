# cmake最低版本
cmake_minimum_required(VERSION 3.16)
# SET(CMAKE_C_COMPILER /usr/bin/gcc)
# SET(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 本项目名
project(main)

# 设置C++11标准，需要满足标准，不用C++拓展语法

# 静态库输出目录
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)

# 动态库输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)

# 可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/bin)


# 进入src文件夹下面的CMakeLists.txt
add_subdirectory(src)

# 进入external文件夹下面的CMakeLists.txt
# add_subdirectory(external)

# 开启测试
# enable_testing()
# 进入 tests 文件夹下面的CMakeLists.txt
# add_subdirectory(tests)
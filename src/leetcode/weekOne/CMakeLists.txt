# 编译静态库，暂不添加任何源码。
file(GLOB_RECURSE SRC_CPP_DIR_LIST "${CMAKE_CURRENT_LIST_DIR}/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/*.c")
file(GLOB_RECURSE SRC_HPP_DIR_LIST "${CMAKE_CURRENT_LIST_DIR}/*.hpp" "${CMAKE_CURRENT_LIST_DIR}/*.h")

# 随后用target_sources添加源码。
# 这种方式更好，因为可以更细粒度地访问权限。
# 例如对cpp文件就是PRIVATE，而hpp则是PUBLIC
target_sources(leetcode
        PRIVATE
        ${SRC_CPP_DIR_LIST}
        PUBLIC
        ${SRC_HPP_DIR_LIST}
)

# 增加头文件目录
target_include_directories(leetcode
        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
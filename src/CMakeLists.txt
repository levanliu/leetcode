# 将main.cpp编译成可执行文件
add_executable(main main.cpp)

set(srcDirs
        dataStructure
        sort
        stringAlgorithm
        leetcode
        search
)

foreach(CURRENT_FOLDER ${srcDirs})
        add_subdirectory(${CURRENT_FOLDER})
        target_link_libraries(main
                PRIVATE ${CURRENT_FOLDER})
endforeach()

add_library(leetcode "")

set(srcDirs
    weekOne
    weekTwo
    weekThree
    weeklyContest)

foreach(CURRENT_FOLDER ${srcDirs})
    add_subdirectory(${CURRENT_FOLDER})
endforeach()
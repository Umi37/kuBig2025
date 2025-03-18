cmake_minimum_required(VERSION 3.10)
project(MainProject)


# #내부 CMakeLists.txt 포함
# include(sqlQuery/CMakeLists.txt) -- 설정파일 저장할 때만
# # include(c_example/part1/CmakeLists.txt)

add_subdirectory(sqlQuery)
add_subdirectory(c_example/part1)
add_subdirectory(c_example/part2)
add_subdirectory(c_example/part3)
add_subdirectory(c_example/project_bowling)  # ✅ bowling 추가

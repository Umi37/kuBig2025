cmake_minimum_required(VERSION 3.10)
project(MainProject)


# #내부 CMakeLists.txt 포함
# include(sqlQuery/CMakeLists.txt) -- 설정파일 저장할 때만
# # include(c_example/part1/CmakeLists.txt)

# add_subdirectory(sqlQuery)
# add_subdirectory(c_example/part1)
# add_subdirectory(c_example/part2)
# add_subdirectory(c_example/part3)
# add_subdirectory(c_example/project_bowling)  # ✅ bowling 추가
# add_subdirectory(stl)
# add_subdirectory(network)
# add_subdirectory(network/ipc)
# add_subdirectory(network/util)
# add_subdirectory(network/tcp)
add_subdirectory(opencv/part1)
add_subdirectory(opencv/part2)
add_subdirectory(opencv/part3)
add_subdirectory(opencv/part4)
add_subdirectory(opencv/follow_color_paper)
add_subdirectory(opencv/part5)
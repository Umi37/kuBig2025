cmake_minimum_required(VERSION 3.10)
project(project_bowling)

# 모든 .c 파일 자동 감지
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_LIST_DIR}/*.c")

set(EXE_NAMES)  # 실행 파일 이름을 저장할 리스트

foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(EXE_NAME ${SOURCE_FILE} NAME_WE)  # .c 확장자 제거
    add_executable(${EXE_NAME} ${SOURCE_FILE})  # 실행 파일 생성
    list(APPEND EXE_NAMES ${EXE_NAME})  # 실행 파일 이름 리스트에 추가
endforeach()

# MySQL 라이브러리 포함
find_package(PkgConfig REQUIRED)
pkg_check_modules(MySQL REQUIRED mysqlclient)

# MySQL 헤더 및 라이브러리 추가
foreach(EXE_NAME ${EXE_NAMES})
    target_include_directories(${EXE_NAME} PRIVATE ${MySQL_INCLUDE_DIRS})
    target_link_libraries(${EXE_NAME} PRIVATE ${MySQL_LIBRARIES})
endforeach()

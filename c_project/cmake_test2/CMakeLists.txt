cmake_minimum_required(VERSION 2.8)
project(CMake_Test)
include_directories("./src")

aux_source_directory(. main_src)


add_subdirectory(src)   #添加外部路径   用于添加一个需要进行构建的子目录       实际构建时会加载添加的目录下的CMakeLists.txt进行构建

add_executable(cmake_test ${main_src})

target_link_libraries(cmake_test src)   # 将目标文件与库文件进行链接    用于指定 target 需要链接 item1 item2 …。这里 target 必须已经被创建，链接的 item 可以是已经存在的 target（依赖关系会自动添加）
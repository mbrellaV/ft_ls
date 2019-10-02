cmake_minimum_required(VERSION 3.13)
project(ls C)

set(CMAKE_C_STANDARD 99)

add_executable(ls main.c ft_ls.h lists.c sort_files.c display_files.c)

target_link_libraries(ls ${CMAKE_SOURCE_DIR}/libft.a)
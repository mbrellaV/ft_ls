cmake_minimum_required(VERSION 3.14)
project(ft_ls C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_ls main.c ft_ls.h lists.c sort_files.c)

target_link_libraries(ft_ls ${CMAKE_SOURCE_DIR}/libft/libft.a)
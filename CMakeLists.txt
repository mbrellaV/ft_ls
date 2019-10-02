cmake_minimum_required(VERSION 3.13)
project(ls C)

set(CMAKE_C_STANDARD 99)

add_executable(ls src/main.c inc/ft_ls.h src/lists.c src/sort_files.c src/display_files.c)

target_link_libraries(ls ${CMAKE_SOURCE_DIR}/libft/libft.a)
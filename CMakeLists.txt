cmake_minimum_required(VERSION 3.13)
project(ft_ls C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_ls main.c ft_ls.h lists.c sort_files.c display_files.c)


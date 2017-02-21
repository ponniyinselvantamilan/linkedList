project(proj1)

cmake_minimum_required(VERSION 2.8)

aux_source_directory(. SRC_LIST)

FILE (GLOB_RECURSE INC_ALL *.h)

add_executable(${PROJECT_NAME} ${SRC_LIST} ${INC_ALL})


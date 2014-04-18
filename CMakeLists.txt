cmake_minimum_required (VERSION 2.6)

project (tp5)

include_directories ("${PROJECT_SOURCE_DIR}/ai")
include_directories ("${PROJECT_SOURCE_DIR}/util")

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
 
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -fopenmp -O3 -g")

set(LIBS
	${PROJECT_SOURCE_DIR}/util/Square.cpp ${PROJECT_SOURCE_DIR}/util/Chrono.hpp
	${PROJECT_SOURCE_DIR}/util/Square.cpp ${PROJECT_SOURCE_DIR}/util/Square.h
	${PROJECT_SOURCE_DIR}/util/Game.cpp ${PROJECT_SOURCE_DIR}/util/Game.h
	${PROJECT_SOURCE_DIR}/util/Player.cpp ${PROJECT_SOURCE_DIR}/util/Player.h
	${PROJECT_SOURCE_DIR}/util/Move.cpp ${PROJECT_SOURCE_DIR}/util/Move.h
	${PROJECT_SOURCE_DIR}/ai/Evaluator.cpp ${PROJECT_SOURCE_DIR}/ai/Evaluator.h
	${PROJECT_SOURCE_DIR}/ai/AlphaBeta.cpp ${PROJECT_SOURCE_DIR}/ai/AlphaBeta.h
	${PROJECT_SOURCE_DIR}/util/lodepng.cpp ${PROJECT_SOURCE_DIR}/util/lodepng.h
	)

add_executable(tp5 oth.cpp ${LIBS})
add_executable(test test.cpp ${LIBS})
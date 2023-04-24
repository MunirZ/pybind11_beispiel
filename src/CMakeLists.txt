set(LIB_NAME "math-lib")

add_library(${LIB_NAME} STATIC
    math.cpp
)

target_include_directories(${LIB_NAME} PUBLIC 
	${CMAKE_CURRENT_LIST_DIR}
)
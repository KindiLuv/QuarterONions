cmake_minimum_required(VERSION 3.21)
project(QuarterONions)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
link_directories(${OPENGL_gl_LIBRARY})

include_directories(./libs/glfw/include)
include_directories(./libs/glew/include)

link_directories(
        ./libs/glfw/lib-static-ucrt,
        ./libs/glew/lib/Release/x64
)

add_executable(QuarterONions main.cpp ./common/GLShader.cpp Quateronion.cpp Quateronion.h Vector3.cpp Vector3.h)

target_link_libraries(QuarterONions glfw3 ${OPENGL_gl_LIBRARY} glew32)

cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#if(WIN32)
#set(CMAKE_C_COMPILER   "c:/mingw64/bin/gcc.exe")
#set(CMAKE_CXX_COMPILER "c:/mingw64/bin/c++.exe")
#endif()

project(Optical_grid)

set(SDL2_ROOT "${CMAKE_SOURCE_DIR}/SDL2")

#enable avx
set(CMAKE_CXX_FLAGS -march=native )

# Find SDL2
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/modules")
find_package(SDL2 REQUIRED)
# find_package(SDL2 REQUIRED COMPONENTS main)

# Add global definitions
add_definitions("-Wall")
include_directories(${SDL2_INCLUDE_DIR} ${CMAKE_BINARY_DIR})
# include_directories(${SDL2_INCLUDE_DIRS} ${SDL2main_INCLUDE_DIRS} ${CMAKE_BINARY_DIR})

# Define executable target
add_executable(Optical_grid
        ido.cpp
        main.cpp
        sajat_sdl.cpp
        resource.cpp
        Analise.cpp Analise.h functions.cpp functions.h matrix.cpp matrix.h optical_grid.cpp optical_grid.h light_sensitive_layer.cpp light_sensitive_layer.h main_loop.cpp main_loop.h maintainer.cpp maintainer.h light_source.cpp light_source.h)

# target_link_libraries(Legitarsasag ${SDL2_LIBS})

# install(TARGETS Legitarsasag DESTINATION bin)
target_link_libraries(Optical_grid ${SDL2_LIBRARIES})

# Copy SDL2 DLLs to output folder on Windows
if(WIN32)
    set(SDL2_DLL "${SDL2_ROOT}/bin/SDL2.dll")
    add_custom_command(TARGET Optical_grid POST_BUILD COMMAND
        ${CMAKE_COMMAND} -E copy_if_different ${SDL2_DLL} $<TARGET_FILE_DIR:Optical_grid>)
endif()

# kopirozzuk a resource konyvtarat a SOURCE konyvtarbol a BINARY konyvtarba
add_custom_command(TARGET Optical_grid POST_BUILD COMMAND
    ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${CMAKE_BINARY_DIR}/resources)

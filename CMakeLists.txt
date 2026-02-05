cmake_minimum_required(VERSION 3.20)
project(LuauShim CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# DLL definition
add_library(LuauShim SHARED library.cpp library.h)

target_include_directories(LuauShim PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Link all 4 core libs
target_link_libraries(LuauShim PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/Luau.Compiler.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/Luau.VM.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/Luau.Ast.lib"
        "${CMAKE_CURRENT_SOURCE_DIR}/deps/Luau.Common.lib"
)

# This is the "Magic" line for MSVC to export symbols from the linked libs
set_target_properties(LuauShim PROPERTIES
        WINDOWS_EXPORT_ALL_SYMBOLS ON
        PREFIX ""
)
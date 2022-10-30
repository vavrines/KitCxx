cmake_minimum_required(VERSION 2.8.12)
project(Kit)

list(APPEND CMAKE_PREFIX_PATH "/home2/vavrines/.julia/artifacts/e74d2fd61bdd4d0ff365351ee632d660b2d43ec5")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

# JlCxx
find_package(JlCxx)
get_target_property(JlCxx_location JlCxx::cxxwrap_julia LOCATION)
get_filename_component(JlCxx_location ${JlCxx_location} DIRECTORY)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib;${JlCxx_location}")
message(STATUS "Found JlCxx at ${JlCxx_location}")

add_library(kit SHARED libkit.cpp)
target_link_libraries(kit JlCxx::cxxwrap_julia)

install(TARGETS
  kit
LIBRARY DESTINATION lib
ARCHIVE DESTINATION lib
RUNTIME DESTINATION lib)

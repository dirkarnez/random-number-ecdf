cmake_minimum_required(VERSION 3.20)

project("armadillo-boilerplate")

if (MSVC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.29.30129 AND CMAKE_VERSION VERSION_GREATER 3.20.3)
    # this change happened in CMake 3.20.4
    set(CMAKE_CXX_STANDARD 23) # /std:c++latest - unlocks the non stable cpp20 features. For new 16.11 versions
else ()
    set(CMAKE_CXX_STANDARD 20) # /std:c++latest for msvc and -std=c++20 for everyone else.
endif ()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(armadillo STATIC IMPORTED)

# set_property(TARGET ortools PROPERTY
#  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
  
set_property(
  TARGET armadillo APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG
)

set_target_properties(armadillo PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${ARMADILLO_ROOT}/build/Debug/armadillo.lib"
)

set_property(
  TARGET armadillo APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
)

set_target_properties(armadillo PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${ARMADILLO_ROOT}/build/Release/armadillo.lib"
)
  
set_target_properties(armadillo PROPERTIES
  MAP_IMPORTED_CONFIG_MINSIZEREL Release
  MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
)

target_include_directories(armadillo INTERFACE "${ARMADILLO_ROOT}/include")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)

# t_property(TARGET ${PROJECT_NAME} PROPERTY
#  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

target_link_libraries(${PROJECT_NAME} armadillo)

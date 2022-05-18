cmake_minimum_required(VERSION 3.20)

project("armadillo-boilerplate")

set(Boost_NO_SYSTEM_PATHS TRUE)
set(Boost_USE_STATIC_LIBS TRUE)
set(BOOST_ROOT "P:/Downloads/cpp-libraries/boost/lib/cmake/Boost-1.78.0")

find_package(Boost REQUIRED)

set(CMAKE_CXX_STANDARD 17)

# if (MSVC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 19.29.30129 AND CMAKE_VERSION VERSION_GREATER 3.20.3)
#     # this change happened in CMake 3.20.4
#     set(CMAKE_CXX_STANDARD 23) # /std:c++latest - unlocks the non stable cpp20 features. For new 16.11 versions
# else ()
#     set(CMAKE_CXX_STANDARD 20) # /std:c++latest for msvc and -std=c++20 for everyone else.
# endif ()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

function (add_cpk_static_library cpk_library)
  add_library(${cpk_library} STATIC IMPORTED)

  # set_property(TARGET ortools PROPERTY
  #  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    
  set_property(
    TARGET ${cpk_library} APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG
  )

  set_target_properties(${cpk_library} PROPERTIES
    IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
    IMPORTED_LOCATION_DEBUG "${ARMADILLO_ROOT}/lib/libarmadillo.a" #armadillo.lib"
  )

  set_property(
    TARGET ${cpk_library} APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE
  )

  set_target_properties(${cpk_library} PROPERTIES
    IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
    IMPORTED_LOCATION_RELEASE "${ARMADILLO_ROOT}/lib/libarmadillo.a" #armadillo.lib"
  )
    
  set_target_properties(${cpk_library} PROPERTIES
    MAP_IMPORTED_CONFIG_MINSIZEREL Release
    MAP_IMPORTED_CONFIG_RELWITHDEBINFO Release
  )

  target_include_directories(${cpk_library} INTERFACE "${ARMADILLO_ROOT}/include")
endfunction()

add_cpk_static_library(armadillo )


include_directories(${Boost_INCLUDE_DIRS})

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

add_executable(${PROJECT_NAME} 
    "src/main.cpp"
)

# if(Boost_FOUND)
  
# endif()

# t_property(TARGET ${PROJECT_NAME} PROPERTY
#  MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

target_link_libraries(${PROJECT_NAME} 
  # ${CPK_LIBRARIES}
  armadillo
  ${Boost_LIBRARIES}
)
# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
project ("Geo")

# Add source to this project's executable.
add_library (libgeo 
	"src/functions.cpp" 
	"src/latitude.cpp" 
	"src/longitude.cpp"
	"src/coordinate.cpp" 
	"src/location.cpp"
	"src/elevation.cpp")

target_include_directories(libgeo
    PUBLIC 
        $<INSTALL_INTERFACE:include>    
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Include sub-projects.
add_subdirectory ("lib")

# UNIT TESTS

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# enable CTest testing
enable_testing()

# Add a testing executable
add_executable(test_geoutil
	"test/functions_unittest.cpp"
	"test/latitude_unittest.cpp"
)

target_link_libraries(test_geoutil
	libgeo
    gtest 
    gtest_main
)

add_test(NAME test_geoutil COMMAND test_geoutil)

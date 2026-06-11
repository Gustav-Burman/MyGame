# CMakeList.txt : CMake project for game, include source and define
# project specific logic here.
#
cmake_minimum_required(VERSION 3.20)

# Enable Hot Reload for MSVC compilers if supported.
#if (POLICY CMP0141)
#  cmake_policy(SET CMP0141 NEW)
#  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
#endif()

project(game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(/Zc:__cplusplus)

# Add libraries
set(SDL3_DIR "${CMAKE_SOURCE_DIR}/libs/SDL3/cmake")
set(SDL3_image_DIR "${CMAKE_SOURCE_DIR}/libs/SDL3_image/cmake")

find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)

include_directories(${SDL3_DIR}/include)
link_directories(${SDL3_DIR}/lib)

include_directories(${SDL3_image_DIR}/i686-w64-mingw32/include)
link_directories(${SDL3_image_DIR}/i686-w64-mingw32/lib)

# Add source to this project's executable.
add_executable (game 
	"src/main.cpp"
	"src/window_utils.cpp"
 "src/card.h" "src/card.cpp" "src/monster.h" "src/player.h" "src/game_state.h")

# Copy assets folder to build configuration
add_custom_command(TARGET game POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	"${CMAKE_SOURCE_DIR}/assets"
	"$<TARGET_FILE_DIR:game>/assets"
)

target_link_libraries(game PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)



# TODO: Add tests and install targets if needed.

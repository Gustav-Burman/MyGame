# CMakeList.txt : CMake project for game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("game")

# Add libraries
set(SDL3_DIR "${CMAKE_SOURCE_DIR}/libs/SDL3")
include_directories(${SDL3_DIR}/include)
link_directories(${SDL3_DIR}/lib)

# Add source to this project's executable.
add_executable (game "src/main.cpp" "src/main.h")
#add_executable (game src/game.cpp)

#target_link_libraries(game SDL3main SDL3)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET game PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

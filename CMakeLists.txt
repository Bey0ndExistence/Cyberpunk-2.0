cmake_minimum_required(VERSION 3.21)
project(Game2D LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(Game2D src/main.cpp src/player.h src/player.cpp src/game.h src/game.cpp src/enemy.h src/enemy.cpp)
target_link_libraries(Game2D PRIVATE sfml-graphics)
target_compile_features(Game2D PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Game2D POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Game2D> $<TARGET_FILE_DIR:Game2D> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Game2D)

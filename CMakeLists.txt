cmake_minimum_required(VERSION 3.28)
project(MineKong LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(MineKong DonkeyKong/main.cpp)

target_include_directories(MineKong PRIVATE DonkeyKong/includes)

# Add source files to the project
target_sources(MineKong PRIVATE
    DonkeyKong/sources/alex.cpp
    DonkeyKong/sources/audios.cpp
    DonkeyKong/sources/barrel.cpp
    DonkeyKong/sources/game.cpp
    DonkeyKong/sources/Kong.cpp
    DonkeyKong/sources/ladder.cpp
    DonkeyKong/sources/mainFunctions.cpp
    DonkeyKong/sources/musics.cpp
    DonkeyKong/sources/platforms.cpp
    DonkeyKong/sources/player.cpp
    DonkeyKong/sources/sounds.cpp)

# Add assets directory to the project
file(COPY DonkeyKong/assets DESTINATION ${CMAKE_BINARY_DIR}/bin)

target_compile_features(MineKong PRIVATE cxx_std_11)
target_link_libraries(MineKong PRIVATE sfml-graphics)
target_link_libraries(MineKong PRIVATE sfml-audio)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT main)
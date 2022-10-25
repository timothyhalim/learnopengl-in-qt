cmake_minimum_required(VERSION 3.10.0)

set(PROJECT Window)

project(${PROJECT})

set(CMAKE_CXX_STANDARD 11)

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add Qt to cmake
set(CMAKE_PREFIX_PATH "C:/Qt/5.15.2/msvc2019_64")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the Qt library
find_package(Qt5 CONFIG REQUIRED COMPONENTS 
    Core
    Gui
    Widgets
)

set(SRC

    window.cpp
    main.cpp
)

# Tell CMake to create the helloworld executable
add_executable(${PROJECT} ${SRC})

# link the module from Qt
target_link_libraries(${PROJECT} Qt5::Widgets)
target_link_libraries(${PROJECT} Qt5::Core)
target_link_libraries(${PROJECT} Qt5::Gui)


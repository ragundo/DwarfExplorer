SET (Qt5_DIR "/home/rafa/Qt/5.12.1/gcc_64/mkspecs/features/data/cmake/")
find_package(Qt5 REQUIRED Widgets)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(qapplication)
add_subdirectory(dwarfexplorer)

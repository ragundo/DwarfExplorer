find_package(Qt5 REQUIRED Widgets)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(dfhack-qt)
add_subdirectory(dwarfexplorer)

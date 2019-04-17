project(qapplication)

set(QAPPLICATION_SOURCES
	main.cpp
	Application.cpp
    Log.cpp
    LogWindow.cpp
)

qt5_wrap_cpp(QAPPLICATION_MOC_SOURCES
	Application.h
    Log.h
    LogWindow.h
)

qt5_wrap_ui(QAPPLICATION_UI_SOURCES
    LogWindow.ui
)

DFHACK_PLUGIN(qapplication
    ${QAPPLICATION_SOURCES} ${QAPPLICATION_MOC_SOURCES} ${QAPPLICATION_UI_SOURCES}
    LINK_LIBRARIES Qt5::Core Qt5::Widgets dfhack-tinythread)
target_include_directories(qapplication PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

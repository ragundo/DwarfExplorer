project(dwarfexplorer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

if(UNIX)
add_definitions(
    -Wfatal-errors
    -Og
    )
endif()

set(DWARFEXPLORER_SOURCES
    main.cpp
    node.cpp
    EventProxy.cpp
    MainWindow.cpp
    dfstructure_window.cpp
    hexviewer_window.cpp
    QtModel/df_model.cpp
    QtModel/df_model_data_from_structure.cpp
    QtModel/df_model_data_from_type.cpp
    QtModel/df_model_data_from_value.cpp
    QtModel/df_model_vector.cpp
    QtModel/df_model_array.cpp
    QtModel/df_model_pointer.cpp
    QtModel/df_model_util.cpp
    QtModel/df_model_df_array.cpp
    generated/offsets_cache.cpp
    generated/fill_nodes.cpp
    generated/fill_offsets.cpp
    generated/df_types_size.cpp
    generated/enum_values.cpp
    generated/bitfields_values.cpp
    generated/df_2_rdf.cpp
    generated/polymorphic_factory.cpp
    generated/fill_globals.cpp
    generated/enums_size.cpp
    QHexView/QHexView.cpp
)

qt5_wrap_cpp(DWARFEXPLORER_MOC_SOURCES
    EventProxy.h
    MainWindow.h
    df_model.h
    dfstructure_window.h
    hexviewer_window.h
)

qt5_wrap_ui(DWARFEXPLORER_UI_SOURCES
    MainWindow.ui
    dfstructure_window.ui
)

DFHACK_PLUGIN(dwarfexplorer
    ${DWARFEXPLORER_SOURCES} ${DWARFEXPLORER_MOC_SOURCES} ${DWARFEXPLORER_UI_SOURCES}
    LINK_LIBRARIES Qt5::Core Qt5::Widgets)
target_include_directories(dwarfexplorer PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

project(dwarfexplorer)

add_definitions(
    -Wfatal-errors
    )

set(DWARFEXPLORER_SOURCES
    main.cpp
    EventProxy.cpp
    MainWindow.cpp
    fill_nodes.cpp
    fill_offsets.cpp
    offsets_cache.cpp
    df_model.cpp
    df_model_data_from_structure.cpp
    df_model_data_from_type.cpp
    df_model_data_from_value.cpp
    df_types_size.cpp
    df_model_vector.cpp
    df_model_array.cpp    
    df_model_pointer.cpp
    df_model_util.cpp
    dfstructure_window.cpp
    node.cpp
    enum_values.cpp
    bitfields_values.cpp
    df_2_rdf.cpp
)

qt5_wrap_cpp(DWARFEXPLORER_MOC_SOURCES
    EventProxy.h
    MainWindow.h
    df_model.h
    dfstructure_window.h
)

qt5_wrap_ui(DWARFEXPLORER_UI_SOURCES
    MainWindow.ui
    dfstructure_window.ui
)

DFHACK_PLUGIN(dwarfexplorer
    ${DWARFEXPLORER_SOURCES} ${DWARFEXPLORER_MOC_SOURCES} ${DWARFEXPLORER_UI_SOURCES}
    LINK_LIBRARIES Qt5::Core Qt5::Widgets)
target_include_directories(dwarfexplorer PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

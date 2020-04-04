project(dwarfexplorer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

if(UNIX)
add_definitions(
    -Wfatal-errors
    -Og
    )
endif()

qt5_add_resources(RSCS
    resources/resources.qrc
    resources/styles/qdarkstyle/style.qrc
)

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
    QtModel/df_proxy_model.cpp
    generated/offsets_cache.cpp
    generated/fill_nodes.cpp
    generated/fill_offsets.cpp
    generated/df_types_size.cpp
    generated/enum_values.cpp
    generated/bitfield_values.cpp
    generated/df_2_rdf.cpp
    generated/polymorphic_factory.cpp
    generated/fill_globals.cpp
    generated/enum_sizes.cpp
    #generated/find_fields_names.cpp
    QHexView/document/commands/hexcommand.cpp
    QHexView/document/commands/insertcommand.cpp
    QHexView/document/commands/removecommand.cpp
    QHexView/document/commands/replacecommand.cpp
    QHexView/document/buffer/qhexbuffer.cpp
    QHexView/document/buffer/qmemoryrefbuffer.cpp
    QHexView/document/buffer/qmemorybuffer.cpp
    QHexView/document/qhexcursor.cpp
    QHexView/document/qhexdocument.cpp
    QHexView/document/qhexmetadata.cpp
    QHexView/document/qhexrenderer.cpp
    QHexView/qhexview.cpp
    ${RSCS}
)

qt5_wrap_cpp(DWARFEXPLORER_MOC_SOURCES
    EventProxy.h
    MainWindow.h
    df_model.h
    QtModel/df_proxy_model.h
    dfstructure_window.h
    hexviewer_window.h
    QHexView/document/commands/hexcommand.h
    QHexView/document/commands/insertcommand.h
    QHexView/document/commands/removecommand.h
    QHexView/document/commands/replacecommand.h
    QHexView/document/buffer/qhexbuffer.h
    QHexView/document/buffer/qmemoryrefbuffer.h
    QHexView/document/buffer/qmemorybuffer.h
    QHexView/document/qhexcursor.h
    QHexView/document/qhexdocument.h
    QHexView/document/qhexmetadata.h
    QHexView/document/qhexrenderer.h
    QHexView/qhexview.h
)

qt5_wrap_ui(DWARFEXPLORER_UI_SOURCES
    MainWindow.ui
    dfstructure_window.ui
)



DFHACK_PLUGIN(dwarfexplorer
    ${DWARFEXPLORER_SOURCES} ${DWARFEXPLORER_MOC_SOURCES} ${DWARFEXPLORER_UI_SOURCES} ${RSCS}
    LINK_LIBRARIES Qt5::Core Qt5::Widgets)
target_include_directories(dwarfexplorer PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

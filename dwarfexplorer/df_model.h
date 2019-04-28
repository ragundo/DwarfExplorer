#ifndef DF_MODEL_H
#define DF_MODEL_H
#include <QAbstractItemModel>
#include "node.h"

class DF_Model  : public QAbstractItemModel
{
    Q_OBJECT
public:
    DF_Model(QObject* p_parent = 0) : QAbstractItemModel(p_parent) {}
    void        set_root(rdf::NodeBase* p_node);
    QModelIndex index(int p_row, int p_column, const QModelIndex& p_parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex& p_child_index) const;
    int         rowCount(const QModelIndex& p_parent = QModelIndex()) const;
    QVariant    data(const QModelIndex& p_index, int p_role = Qt::DisplayRole) const;
    QVariant    headerData(int p_section, Qt::Orientation p_orientation, int p_role = Qt::DisplayRole) const;
    int         columnCount(const QModelIndex& parent = QModelIndex()) const;
    //bool        insertRows(int p_row, int p_count, const QModelIndex& p_parent = QModelIndex());
    bool        removeRows(int p_row, int p_count, const QModelIndex& p_parent = QModelIndex());
    bool        insertColumns(int p_column, int p_count, const QModelIndex& p_parent = QModelIndex());
    bool        removeColumns(int p_column, int p_count, const QModelIndex& p_parent = QModelIndex());
    bool        hasChildren(const QModelIndex& p_parent = QModelIndex()) const;

    bool        insertRowsVector(const QModelIndex& p_parent);
    bool        insertRowsPointer(const QModelIndex& p_parent);    
    bool        insertRowsSimplePointerVector(const QModelIndex& p_parent);
    bool        insertRowsCompound(const QModelIndex& p_parent, int p_num_rows);
    bool        insertRowsArray(const QModelIndex& p_parent);
    bool        insertRowsBitfield(const QModelIndex& p_parent);
    bool        insertRowsSimple(const QModelIndex& p_parent);    
    bool        insertRowsDFFlagArray(const QModelIndex& p_parent);



    std::string to_hex(uint64_t p_dec) const;
    bool is_simple_type(const rdf::NodeBase* l_node) const;
    bool is_simple_type(rdf::RDF_Type p_type) const;
    bool is_simple_type(rdf::DF_Type p_type) const;
    bool is_string(const rdf::NodeBase* l_node) const;

    //NodeBase*   locate(rdf::RDFBase* p_value);
    void        insert_child_nodes(rdf::NodeBase* p_node, const QModelIndex& p_index);
    bool        has_children_from_type(rdf::NodeBase* p_node) const;
    void        update_node_path(rdf::NodeBase* p_source, rdf::NodeBase* p_dest);

    rdf::NodeBase*   nodeFromIndex(const QModelIndex& p_index) const;
    std::size_t      get_vector_size(const rdf::NodeVector* p_node) const;
private:
    QString     data_from_Type(const rdf::NodeBase* p_node) const;
    QString     data_from_Value(const rdf::NodeBase* p_node) const;
    QString     data_from_Structure(const rdf::NodeBase* p_node) const;

    QString     Vector_data_from_Value(const rdf::NodeBase* p_node) const;       

private:
    rdf::NodeBase* m_rootNode;
};

#endif // DF_MODEL_H

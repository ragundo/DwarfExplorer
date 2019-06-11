#include "df_proxy_model.h"


DF_ProxyModel::DF_ProxyModel(QObject* p_parent)
    : QSortFilterProxyModel(p_parent)
{
}

bool DF_ProxyModel::filterAcceptsRow(int p_source_row, const QModelIndex &p_source_parent) const
{
    DF_Model* df_model = dynamic_cast<DF_Model*>(sourceModel());
    if (df_model == nullptr)
        return false;
    rdf::NodeBase* node = df_model->nodeFromIndex(p_source_parent);
    if (node == nullptr)
        return false;
    return true;
}

bool DF_ProxyModel::hasChildren(const QModelIndex& p_parent) const
{
    DF_Model* df_model = dynamic_cast<DF_Model*>(sourceModel());
    if (df_model == nullptr)
        return false;
    return df_model->hasChildren(p_parent);
    rdf::NodeBase* node_base = df_model->nodeFromIndex(p_parent);
    if (node_base == nullptr)
        return false;
    rdf::Node* node = dynamic_cast<rdf::Node*>(node_base);
    if (node == nullptr)
        return false;
    return node->m_children.size() != 0;
}

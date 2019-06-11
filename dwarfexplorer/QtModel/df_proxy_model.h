#ifndef DF_PROXY_MODEL_H
#define DF_PROXY_MODEL_H
#include <QSortFilterProxyModel>
#include "../df_model.h"

class DF_ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

    public:
        DF_ProxyModel(QObject* parent = nullptr);

        bool hasChildren(const QModelIndex& p_parent = QModelIndex()) const;

    protected:
        bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const;
};

#endif // DF_PROXY_MODEL_H
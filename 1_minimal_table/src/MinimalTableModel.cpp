#include "MinimalTableModel.h"

MinimalTableModel::MinimalTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int MinimalTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 2;
}

int MinimalTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 3;
}

QVariant MinimalTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    return QString::number(index.row()) + QString::number(index.column());
}

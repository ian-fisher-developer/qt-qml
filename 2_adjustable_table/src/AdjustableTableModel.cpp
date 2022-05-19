#include "AdjustableTableModel.h"

AdjustableTableModel::AdjustableTableModel(size_t nRows, size_t nCols, QObject *parent)
    : QAbstractTableModel(parent)
{
}

int AdjustableTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 2;
}

int AdjustableTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return 3;
}

QVariant AdjustableTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    return QString::number(index.row()) + QString::number(index.column());
}

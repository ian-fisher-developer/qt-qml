#include "AdjustableTableModel.h"


namespace{

int enforceSizeLimits(int n)
{
    if(n < 1) return 1;
    if(n > 10) return 10;
    return n;
}

} // unnamed namespace


struct AdjustableTableModel::Impl
{
    int m_nRows, m_nCols;

    Impl(int nRows, int nCols)
        : m_nRows(enforceSizeLimits(nRows)),
          m_nCols(enforceSizeLimits(nCols))
    {}

}; // AdjustableTableModel::Impl


AdjustableTableModel::AdjustableTableModel(QObject *parent)
    : QAbstractTableModel(parent),
      pImpl(new Impl(5, 5))
{
}

AdjustableTableModel::~AdjustableTableModel()
{
}

int AdjustableTableModel::nRows() const
{
    return pImpl->m_nRows;
}

int AdjustableTableModel::nCols() const
{
    return pImpl->m_nCols;
}

void AdjustableTableModel::setNRows(int n)
{
    beginResetModel();
    pImpl->m_nRows = enforceSizeLimits(n);
    endResetModel();
}

void AdjustableTableModel::setNCols(int n)
{
    beginResetModel();
    pImpl->m_nCols = enforceSizeLimits(n);
    endResetModel();
}

int AdjustableTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return pImpl->m_nRows;
}

int AdjustableTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
    return pImpl->m_nCols;
}

QVariant AdjustableTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();
    return QString::number(index.row()) + QString::number(index.column());
}

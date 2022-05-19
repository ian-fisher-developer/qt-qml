#include "AdjustableTableModel.h"


namespace{

size_t enforceSizeLimits(size_t n)
{
    if(n < 1) return 1;
    if(n > 10) return 10;
    return n;
}

} // unnamed namespace


struct AdjustableTableModel::Impl
{
    size_t m_nRows, m_nCols;

    Impl(size_t nRows, size_t nCols)
        : m_nRows(enforceSizeLimits(nRows)),
          m_nCols(enforceSizeLimits(nCols))
    {}

}; // AdjustableTableModel::Impl


AdjustableTableModel::AdjustableTableModel(size_t nRows, size_t nCols, QObject *parent)
    : QAbstractTableModel(parent),
      pImpl(new Impl(nRows, nCols))
{
}

AdjustableTableModel::~AdjustableTableModel()
{
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

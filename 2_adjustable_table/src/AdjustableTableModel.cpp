#include "AdjustableTableModel.h"


namespace{

int maxNRows(9);
int maxNCols(26);
int defaultNRows(5);
int defaultNCols(5);

int enforceRowLimit(int n)
{
    if(n < 1) return 1;
    if(n > maxNRows) return maxNRows;
    return n;
}

QString rowLabel(int i)
{
    return QString::number(i+1);
}

int enforceColumnLimit(int n)
{
    if(n < 1) return 1;
    if(n > maxNCols) return maxNCols;
    return n;
}

QString columnLabel(int i)
{
    if(i>maxNCols-1) return QString();
    return QString("ABCDEFGHIJKLMNOPQRSTUVWXYZ")[i];
}

} // unnamed namespace


struct AdjustableTableModel::Impl
{
    int m_nRows, m_nCols;

    Impl(int nRows, int nCols)
        : m_nRows(enforceRowLimit(nRows)),
          m_nCols(enforceColumnLimit(nCols))
    {}

}; // AdjustableTableModel::Impl


AdjustableTableModel::AdjustableTableModel(QObject *parent)
    : QAbstractTableModel(parent),
      pImpl(new Impl(defaultNRows, defaultNCols))
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
    pImpl->m_nRows = enforceRowLimit(n);
    endResetModel();
}

void AdjustableTableModel::setNCols(int n)
{
    beginResetModel();
    pImpl->m_nCols = enforceColumnLimit(n);
    endResetModel();
}

int AdjustableTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;

    return pImpl->m_nRows;
}

int AdjustableTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;

    return pImpl->m_nCols;
}

QVariant AdjustableTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();

    return columnLabel(index.column()) + rowLabel(index.row());
}

QVariant AdjustableTableModel::headerData(int sectionNumber, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) return QVariant();

    if (orientation == Qt::Vertical) {
        return rowLabel(sectionNumber);
    }else{
        return columnLabel(sectionNumber);
    }
}

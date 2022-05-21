#include "AdjustableTableModel.h"


namespace{

const int MAX_NROWS(9);
const int MAX_NCOLS(26);
const QString COLUMN_LABELS("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
const int DEFAULT_NROWS(5);
const int DEFAULT_NCOLS(8);

int enforceRowLimit(int n)
{
    if(n < 1) return 1;
    if(n > MAX_NROWS) return MAX_NROWS;
    return n;
}

QString rowLabel(int i)
{
    return QString::number(i+1);
}

int enforceColumnLimit(int n)
{
    if(n < 1) return 1;
    if(n > MAX_NCOLS) return MAX_NCOLS;
    return n;
}

QString columnLabel(int i)
{
    if(i < 0 || i > COLUMN_LABELS.length()-1) return QString("?");
    return COLUMN_LABELS[i];
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
      pImpl(new Impl(DEFAULT_NROWS, DEFAULT_NCOLS))
{
}

AdjustableTableModel::~AdjustableTableModel()
{
}

int AdjustableTableModel::nRowsMax() const
{
    return MAX_NROWS;
}

int AdjustableTableModel::nRowsDefault() const
{
    return DEFAULT_NROWS;
}

int AdjustableTableModel::nRows() const
{
    return pImpl->m_nRows;
}

int AdjustableTableModel::nColsMax() const
{
    return MAX_NCOLS;
}

int AdjustableTableModel::nColsDefault() const
{
    return DEFAULT_NCOLS;
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

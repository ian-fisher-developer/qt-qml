#include "AdjustableTableModel.h"


namespace{

int maxNRows() {return 9;}

int defaultNRows() {return 5;}

int maxNCols() {return 26;}

int defaultNCols() {return 8;}

QString rowLabel(int i)
{
    return QString::number(i+1);
}

QString columnLabel(int i)
{
    const QString columnLabels("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if(i < 0 || i > columnLabels.length()-1) return QString("?");
    return columnLabels[i];
}

int applyLimits(int n, int max)
{
    if(n < 1) return 1;
    if(n > max) return max;
    return n;
}

} // unnamed namespace


struct AdjustableTableModel::Impl
{
    int m_nRows, m_nCols;

    Impl(int nRows, int nCols)
        : m_nRows(applyLimits(nRows, maxNRows())),
          m_nCols(applyLimits(nCols, maxNCols()))
    {}

}; // AdjustableTableModel::Impl


AdjustableTableModel::AdjustableTableModel(QObject *parent)
    : QAbstractTableModel(parent),
      pImpl(new Impl(defaultNRows(), defaultNCols()))
{
}

AdjustableTableModel::~AdjustableTableModel()
{
}

int AdjustableTableModel::nRowsMax() const
{
    return maxNRows();
}

int AdjustableTableModel::nRowsDefault() const
{
    return defaultNRows();
}

int AdjustableTableModel::nRows() const
{
    return pImpl->m_nRows;
}

int AdjustableTableModel::nColsMax() const
{
    return maxNCols();
}

int AdjustableTableModel::nColsDefault() const
{
    return defaultNCols();
}

int AdjustableTableModel::nCols() const
{
    return pImpl->m_nCols;
}

void AdjustableTableModel::setNRows(int n)
{
    beginResetModel();
    pImpl->m_nRows = applyLimits(n, maxNRows());
    endResetModel();
}

void AdjustableTableModel::setNCols(int n)
{
    beginResetModel();
    pImpl->m_nCols = applyLimits(n, maxNCols());
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
    QString columnLabel = headerData(index.column(), Qt::Horizontal, role).toString();
    QString rowLabel = headerData(index.row(), Qt::Vertical, role).toString();
    return columnLabel + rowLabel;
}

QVariant AdjustableTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation == Qt::Vertical) {
        return rowLabel(section);
    }else{
        return columnLabel(section);
    }
}

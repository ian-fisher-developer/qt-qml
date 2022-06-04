#include "AdjustableTableModel.h"


namespace{

int maxNRows() {return 9;}
int maxNCols() {return 26;}
const QString colLabels() {return "ABCDEFGHIJKLMNOPQRSTUVWXYZ";}

int defaultNRows() {return 5;}
int defaultNCols() {return 8;}

int applyLimits(int n, int max)
{
    if(n < 1) return 1;
    if(n > max) return max;
    return n;
}

} // unnamed namespace


struct AdjustableTableModel::Impl
{
    int nRows, nCols;

    Impl(int _nRows, int _nCols)
        : nRows(applyLimits(_nRows, maxNRows())),
          nCols(applyLimits(_nCols, maxNCols()))
    {}

}; // AdjustableTableModel::Impl


AdjustableTableModel::AdjustableTableModel(QObject *parent)
    : QAbstractTableModel(parent),
      pImpl(new Impl(defaultNRows(), defaultNCols()))
{}

AdjustableTableModel::~AdjustableTableModel()
{}

int AdjustableTableModel::nRowsMax() const
{
    return maxNRows();
}

int AdjustableTableModel::nRows() const
{
    return pImpl->nRows;
}

int AdjustableTableModel::nColsMax() const
{
    return maxNCols();
}

int AdjustableTableModel::nCols() const
{
    return pImpl->nCols;
}

void AdjustableTableModel::setNRows(int n)
{
    beginResetModel();
    pImpl->nRows = applyLimits(n, maxNRows());
    endResetModel();
}

void AdjustableTableModel::setNCols(int n)
{
    beginResetModel();
    pImpl->nCols = applyLimits(n, maxNCols());
    endResetModel();
}

int AdjustableTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return pImpl->nRows;
}

int AdjustableTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return pImpl->nCols;
}

QVariant AdjustableTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) return QVariant();
    QString colLabel = headerData(index.column(), Qt::Horizontal, role).toString();
    QString rowLabel = headerData(index.row(), Qt::Vertical, role).toString();
    return colLabel + rowLabel;
}

QVariant AdjustableTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation == Qt::Vertical) {
        return QString::number(section+1);
    }else{
        if (section < 0 || section > colLabels().length()-1) return QString("?");
        return colLabels()[section];
    }
}

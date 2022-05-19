#ifndef AdjustableTableModel_H
#define AdjustableTableModel_H

#include <QAbstractTableModel>
#include <QtQml/qqml.h>

class AdjustableTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    AdjustableTableModel(size_t nRows, size_t nCols, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &, int role = Qt::DisplayRole) const override;
};

#endif // AdjustableTableModel_H

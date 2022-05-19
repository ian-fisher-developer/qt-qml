#ifndef AdjustableTableModel_H
#define AdjustableTableModel_H

#include <QAbstractTableModel>
#include <QtQml/qqml.h>

class AdjustableTableModel : public QAbstractTableModel
{
    Q_OBJECT
    Q_PROPERTY(int nRows READ nRows WRITE setNRows NOTIFY nRowsChanged)
    Q_PROPERTY(int nCols READ nCols WRITE setNCols NOTIFY nColsChanged)
    QML_ELEMENT

public:
    AdjustableTableModel(QObject *parent = nullptr);
    ~AdjustableTableModel();

    int nRows() const;
    int nCols() const;

    void setNRows(int);
    void setNCols(int);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &, int role = Qt::DisplayRole) const override;

signals:
    void nRowsChanged(int);
    void nColsChanged(int);

private:
    struct Impl;
    const std::unique_ptr<Impl> pImpl;
};

#endif // AdjustableTableModel_H

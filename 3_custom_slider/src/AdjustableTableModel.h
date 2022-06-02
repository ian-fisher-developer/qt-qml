#ifndef AdjustableTableModel_H
#define AdjustableTableModel_H

#include <QAbstractTableModel>
#include <QtQML/qqml.h>

/**
 * A table model with variable row/column dimensions, displaying data as A1, B1, etc.
 * The model my be used with a QtWidgets QTableView, and with a QML TableView.
 */
class AdjustableTableModel : public QAbstractTableModel
{
    Q_OBJECT

    // Exercise implementation notes:
    // - Expose the model to QML with QML_ELEMENT and the Qt Properties System
    // - Sadly, the QML TableView does not natively support table headers
    Q_PROPERTY(int nRowsMax READ nRowsMax CONSTANT)
    Q_PROPERTY(int nRowsDefault READ nRowsDefault CONSTANT)
    Q_PROPERTY(int nRows READ nRows WRITE setNRows NOTIFY nRowsChanged)
    Q_PROPERTY(int nColsMax READ nColsMax CONSTANT)
    Q_PROPERTY(int nColsDefault READ nColsDefault CONSTANT)
    Q_PROPERTY(int nCols READ nCols WRITE setNCols NOTIFY nColsChanged)
    QML_ELEMENT

public:
    AdjustableTableModel(QObject *parent = nullptr);
    ~AdjustableTableModel();

    int nRowsMax() const;
    int nRowsDefault() const;
    int nRows() const;

    int nColsMax() const;
    int nColsDefault() const;
    int nCols() const;

    void setNRows(int);
    void setNCols(int);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation, int role = Qt::DisplayRole) const override;

signals:
    void nRowsChanged(int);
    void nColsChanged(int);

private:
    struct Impl;
    const std::unique_ptr<Impl> pImpl;
};

#endif // AdjustableTableModel_H

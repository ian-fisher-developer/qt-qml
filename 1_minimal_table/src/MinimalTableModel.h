#ifndef MinimalTableModel_H
#define MinimalTableModel_H

#include <QAbstractTableModel>
#include <QtQml/qqml.h>

/**
 * A most simple table model, with fixed row/column dimensions and fixed data.
 * The model my be used with a QtWidgets QTableView, and with a QML TableView.
 */
class MinimalTableModel : public QAbstractTableModel
{
    Q_OBJECT

    // Exercise implementation notes:
    // - Expose the model to QML with QML_ELEMENT
    QML_ELEMENT

public:
    MinimalTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &, int role = Qt::DisplayRole) const override;
};

#endif // MinimalTableModel_H

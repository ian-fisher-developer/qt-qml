#ifndef MinimalTableModel_H
#define MinimalTableModel_H

#include <QAbstractTableModel>
#include <QtQml/qqml.h>

class MinimalTableModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT

public:
    MinimalTableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &, int role = Qt::DisplayRole) const override;
};

#endif // MinimalTableModel_H

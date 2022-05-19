#include <gtest/gtest.h>

#include "../src/MinimalTableModel.h"

TEST(MinimalTableModel, hasTwoRows)
{
    MinimalTableModel *model = new MinimalTableModel;
    EXPECT_EQ(2, model->rowCount());
}

TEST(MinimalTableModel, hasThreeColumns)
{
    MinimalTableModel *model = new MinimalTableModel;
    EXPECT_EQ(3, model->columnCount());
}

TEST(MinimalTableModel, displays00StringInTopLeftCell)
{
    MinimalTableModel *model = new MinimalTableModel;
    QModelIndex topLeft = model->index(0, 0);
    QString result(model->data(topLeft, Qt::DisplayRole).toString());
    EXPECT_EQ("00", result.toStdString());
}

TEST(MinimalTableModel, displays12StringInBottomRightCell)
{
    MinimalTableModel *model = new MinimalTableModel;
    QModelIndex bottomRight = model->index(model->rowCount()-1, model->columnCount()-1);
    QString result(model->data(bottomRight, Qt::DisplayRole).toString());
    EXPECT_EQ("12", result.toStdString());
}

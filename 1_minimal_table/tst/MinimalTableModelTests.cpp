#include "../src/MinimalTableModel.h"
#include <gtest/gtest.h>

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
    QModelIndex index = model->index(0, 0);
    QString cellDisplay(model->data(index, Qt::DisplayRole).toString());
    EXPECT_EQ("00", cellDisplay.toStdString());
}

TEST(MinimalTableModel, displays12StringInBottomRightCell)
{
    MinimalTableModel *model = new MinimalTableModel;
    QModelIndex index = model->index(model->rowCount()-1, model->columnCount()-1);
    QString cellDisplay(model->data(index, Qt::DisplayRole).toString());
    EXPECT_EQ("12", cellDisplay.toStdString());
}

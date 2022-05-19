#include "../src/AdjustableTableModel.h"
#include <gtest/gtest.h>

TEST(AdjustableTableModel, requiresNumberOfRowsAndColumns)
{
    AdjustableTableModel *model = new AdjustableTableModel(3, 5);
    EXPECT_EQ(3, model->rowCount());
    EXPECT_EQ(5, model->columnCount());
}

TEST(AdjustableTableModel, hasAtLeastOneRowAndColumn)
{
    AdjustableTableModel *smallestModel = new AdjustableTableModel(1, 1);
    EXPECT_EQ(1, smallestModel->rowCount());
    EXPECT_EQ(1, smallestModel->columnCount());

    AdjustableTableModel *limitedModel = new AdjustableTableModel(0, 0);
    EXPECT_EQ(1, limitedModel->rowCount());
    EXPECT_EQ(1, limitedModel->columnCount());
}

TEST(AdjustableTableModel, hasAtMostTenRowsAndColumns)
{
    AdjustableTableModel *largestModel = new AdjustableTableModel(10, 10);
    EXPECT_EQ(10, largestModel->rowCount());
    EXPECT_EQ(10, largestModel->columnCount());

    AdjustableTableModel *limitedModel = new AdjustableTableModel(11, 11);
    EXPECT_EQ(10, limitedModel->rowCount());
    EXPECT_EQ(10, limitedModel->columnCount());
}

TEST(AdjustableTableModel, displaysRowColStringInEachCell)
{
    AdjustableTableModel *model = new AdjustableTableModel(10, 10);
    QModelIndex topLeftIndex = model->index(0, 0);
    QModelIndex topRightIndex = model->index(0, model->columnCount()-1);
    QModelIndex bottomLeftIndex = model->index(model->rowCount()-1, 0);
    QModelIndex bottomRightIndex = model->index(model->rowCount()-1, model->columnCount()-1);
    QString topLeft(model->data(topLeftIndex, Qt::DisplayRole).toString());
    QString topRight(model->data(topRightIndex, Qt::DisplayRole).toString());
    QString bottomLeft(model->data(bottomLeftIndex, Qt::DisplayRole).toString());
    QString bottomRight(model->data(bottomRightIndex, Qt::DisplayRole).toString());
    EXPECT_EQ("00", topLeft.toStdString());
    EXPECT_EQ("09", topRight.toStdString());
    EXPECT_EQ("90", bottomLeft.toStdString());
    EXPECT_EQ("99", bottomRight.toStdString());
}

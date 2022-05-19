#include "../src/AdjustableTableModel.h"
#include <gtest/gtest.h>

TEST(AdjustableTableModel, defaultsToFiveRowsAndColumns)
{
    AdjustableTableModel *model = new AdjustableTableModel();
    EXPECT_EQ(5, model->rowCount());
    EXPECT_EQ(5, model->columnCount());
}

TEST(AdjustableTableModel, hasAtLeastOneRowAndColumn)
{
    {
        AdjustableTableModel *smallestModel = new AdjustableTableModel();
        smallestModel->setProperty("nRows", 1);
        smallestModel->setProperty("nCols", 1);
        EXPECT_EQ(1, smallestModel->rowCount());
        EXPECT_EQ(1, smallestModel->columnCount());
    }

    {
        AdjustableTableModel *limitedModel = new AdjustableTableModel();
        limitedModel->setProperty("nRows", 0);
        limitedModel->setProperty("nCols", 0);
        EXPECT_EQ(1, limitedModel->rowCount());
        EXPECT_EQ(1, limitedModel->columnCount());
    }
}

TEST(AdjustableTableModel, hasAtMostTenRowsAndColumns)
{
    {
        AdjustableTableModel *largestModel = new AdjustableTableModel();
        largestModel->setProperty("nRows", 10);
        largestModel->setProperty("nCols", 10);
        EXPECT_EQ(10, largestModel->rowCount());
        EXPECT_EQ(10, largestModel->columnCount());
    }

    {
        AdjustableTableModel *limitedModel = new AdjustableTableModel();
        limitedModel->setProperty("nRows", 11);
        limitedModel->setProperty("nCols", 11);
        EXPECT_EQ(10, limitedModel->rowCount());
        EXPECT_EQ(10, limitedModel->columnCount());
    }
}

TEST(AdjustableTableModel, displaysRowColStringInEachCell)
{
    AdjustableTableModel *model = new AdjustableTableModel();
    model->setProperty("nRows", 10);
    model->setProperty("nCols", 10);
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

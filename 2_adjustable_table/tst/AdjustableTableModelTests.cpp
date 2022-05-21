#include "../src/AdjustableTableModel.h"
#include <gtest/gtest.h>

namespace {

int maximumRowsAndColumns = 9;

} // unnamed namespace


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

TEST(AdjustableTableModel, enforcesMaximumNumberOfRowsAndColumns)
{
    {
        AdjustableTableModel *largestModel = new AdjustableTableModel();
        largestModel->setProperty("nRows", maximumRowsAndColumns);
        largestModel->setProperty("nCols", maximumRowsAndColumns);
        EXPECT_EQ(maximumRowsAndColumns, largestModel->rowCount());
        EXPECT_EQ(maximumRowsAndColumns, largestModel->columnCount());
    }

    {
        AdjustableTableModel *limitedModel = new AdjustableTableModel();
        limitedModel->setProperty("nRows", maximumRowsAndColumns+1);
        limitedModel->setProperty("nCols", maximumRowsAndColumns+1);
        EXPECT_EQ(maximumRowsAndColumns, limitedModel->rowCount());
        EXPECT_EQ(maximumRowsAndColumns, limitedModel->columnCount());
    }
}

TEST(AdjustableTableModel, displaysHeaderRowNumbers)
{
    AdjustableTableModel *model = new AdjustableTableModel();
    model->setProperty("nRows", 5);
    model->setProperty("nCols", 1);
    QString topRow(model->headerData(0, Qt::Vertical, Qt::DisplayRole).toString());
    QString bottomRow(model->headerData(model->rowCount()-1, Qt::Vertical, Qt::DisplayRole).toString());
    EXPECT_EQ("1", topRow.toStdString());
    EXPECT_EQ("5", bottomRow.toStdString());
}

TEST(AdjustableTableModel, displaysHeaderColumnLetters)
{
    AdjustableTableModel *model = new AdjustableTableModel();
    model->setProperty("nRows", 1);
    model->setProperty("nCols", 4);
    QString topRow(model->headerData(0, Qt::Horizontal, Qt::DisplayRole).toString());
    QString bottomRow(model->headerData(model->columnCount()-1, Qt::Horizontal, Qt::DisplayRole).toString());
    EXPECT_EQ("A", topRow.toStdString());
    EXPECT_EQ("D", bottomRow.toStdString());
}

TEST(AdjustableTableModel, displaysDataAsColumnRowLabels)
{
    AdjustableTableModel *model = new AdjustableTableModel();
    model->setProperty("nRows", 3);
    model->setProperty("nCols", 5);
    QModelIndex topLeftIndex = model->index(0, 0);
    QModelIndex topRightIndex = model->index(0, model->columnCount()-1);
    QModelIndex bottomLeftIndex = model->index(model->rowCount()-1, 0);
    QModelIndex bottomRightIndex = model->index(model->rowCount()-1, model->columnCount()-1);
    QString topLeft(model->data(topLeftIndex, Qt::DisplayRole).toString());
    QString topRight(model->data(topRightIndex, Qt::DisplayRole).toString());
    QString bottomLeft(model->data(bottomLeftIndex, Qt::DisplayRole).toString());
    QString bottomRight(model->data(bottomRightIndex, Qt::DisplayRole).toString());
    EXPECT_EQ("A1", topLeft.toStdString());
    EXPECT_EQ("E1", topRight.toStdString());
    EXPECT_EQ("A3", bottomLeft.toStdString());
    EXPECT_EQ("E3", bottomRight.toStdString());
}


#include "../src/AdjustableTableModel.h"
#include <gtest/gtest.h>


namespace {

int maxNRows(9);
int maxNCols(26);

} // unnamed namespace


class AdjustableTableModelTest : public ::testing::Test
{
protected:
    AdjustableTableModel *model;

    void SetUp() override
    {
        model = new AdjustableTableModel();
    }

    void TearDown() override
    {
        delete model;
    }

}; // class AdjustableTableModelTest


TEST_F(AdjustableTableModelTest, hasMaximumDimensions)
{
    EXPECT_EQ(maxNRows, model->nRowsMax());
    EXPECT_EQ(maxNCols, model->nColsMax());
}

TEST_F(AdjustableTableModelTest, hasDefaultDimensions)
{
    EXPECT_EQ(5, model->rowCount());
    EXPECT_EQ(8, model->columnCount());
}

TEST_F(AdjustableTableModelTest, enforcesMinimumNumberOfRows)
{
    model->setProperty("nRows", 1);
    EXPECT_EQ(1, model->rowCount());
    model->setProperty("nRows", 0);
    EXPECT_EQ(1, model->rowCount());
}

TEST_F(AdjustableTableModelTest, enforcesMaximumNumberOfRows)
{
    model->setProperty("nRows", maxNRows);
    EXPECT_EQ(maxNRows, model->rowCount());
    model->setProperty("nRows", maxNRows+1);
    EXPECT_EQ(maxNRows, model->rowCount());
}

TEST_F(AdjustableTableModelTest, enforcesMinimumNumberOfColumns)
{
    model->setProperty("nCols", 1);
    EXPECT_EQ(1, model->columnCount());
    model->setProperty("nCols", 0);
    EXPECT_EQ(1, model->columnCount());
}

TEST_F(AdjustableTableModelTest, enforcesMaximumNumberOfColumns)
{
    model->setProperty("nCols", maxNCols);
    EXPECT_EQ(maxNCols, model->columnCount());
    model->setProperty("nCols", maxNCols+1);
    EXPECT_EQ(maxNCols, model->columnCount());
}

TEST_F(AdjustableTableModelTest, displaysHeaderRowNumbers)
{
    model->setProperty("nRows", 3);
    model->setProperty("nCols", 1);
    QString firstLabel(model->headerData(0, Qt::Vertical, Qt::DisplayRole).toString());
    QString lastLabel(model->headerData(model->rowCount()-1, Qt::Vertical, Qt::DisplayRole).toString());
    EXPECT_EQ("1", firstLabel.toStdString());
    EXPECT_EQ("3", lastLabel.toStdString());
}

TEST_F(AdjustableTableModelTest, displaysHeaderColumnLetters)
{
    model->setProperty("nRows", 1);
    model->setProperty("nCols", 4);
    QString firstLabel(model->headerData(0, Qt::Horizontal, Qt::DisplayRole).toString());
    QString lastLabel(model->headerData(model->columnCount()-1, Qt::Horizontal, Qt::DisplayRole).toString());
    EXPECT_EQ("A", firstLabel.toStdString());
    EXPECT_EQ("D", lastLabel.toStdString());
}

TEST_F(AdjustableTableModelTest, displaysDataAsColumnHeaderPlusRowHeader)
{
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


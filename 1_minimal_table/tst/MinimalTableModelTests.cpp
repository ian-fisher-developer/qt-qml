#include "../src/MinimalTableModel.h"
#include <gtest/gtest.h>


class MinimalTableModelTest : public ::testing::Test
{
protected:
    MinimalTableModel *model;

    void SetUp() override
    {
        model = new MinimalTableModel();
    }

    void TearDown() override
    {
        delete model;
    }

}; // class MinimalTableModelTest


TEST_F(MinimalTableModelTest, hasTwoRows)
{
    EXPECT_EQ(2, model->rowCount());
}

TEST_F(MinimalTableModelTest, hasThreeColumns)
{
    EXPECT_EQ(3, model->columnCount());
}

TEST_F(MinimalTableModelTest, displays00StringInTopLeftCell)
{
    QModelIndex index = model->index(0, 0);
    QString cellDisplay(model->data(index, Qt::DisplayRole).toString());
    EXPECT_EQ("00", cellDisplay.toStdString());
}

TEST_F(MinimalTableModelTest, displays12StringInBottomRightCell)
{
    QModelIndex index = model->index(model->rowCount()-1, model->columnCount()-1);
    QString cellDisplay(model->data(index, Qt::DisplayRole).toString());
    EXPECT_EQ("12", cellDisplay.toStdString());
}

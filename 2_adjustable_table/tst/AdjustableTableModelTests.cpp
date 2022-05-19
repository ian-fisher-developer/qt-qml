#include "../src/AdjustableTableModel.h"
#include <gtest/gtest.h>

TEST(AdjustableTableModel, enforcesAtLeastOneRow)
{
    AdjustableTableModel *model = new AdjustableTableModel(0, 1);
    EXPECT_EQ(1, model->rowCount());
}

TEST(AdjustableTableModel, enforcesAtLeastOneColumn)
{
    AdjustableTableModel *model = new AdjustableTableModel(1, 0);
    EXPECT_EQ(1, model->columnCount());
}

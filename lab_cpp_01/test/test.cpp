#include "list.h"
#include <gtest/gtest.h>

// Тест функції findWatchesWithPriceLessThan
TEST(ProgramingLab01, test_find_watches_with_price_less_than)
{
    List list;
    Watch* watch1 = new Watch("Rolex", "Switzerland", "Classic", 500.0);
    Watch* watch2 = new Watch("Casio", "Japan", "Sports", 300.0);
    Watch* watch3 = new Watch("TAG Heuer", "Switzerland", "Skeleton", 800.0);
    Watch* watch4 = new Watch("Fossil", "USA", "Fashion", 200.0);
    list.addWatch(watch1);
    list.addWatch(watch2);
    list.addWatch(watch3);
    list.addWatch(watch4);

    std::vector<Watch*> expected_result = {watch2, watch4};
    std::vector<Watch*> actual_result = list.findWatchesWithPriceLessThan(400.0);

    ASSERT_EQ(expected_result, actual_result);

    // Cleanup
    delete watch1;
    delete watch2;
    delete watch3;
    delete watch4;
}

// Тест функції findSwissWatchesWithSkeleton
TEST(ProgramingLab01, test_find_swiss_watches_with_skeleton)
{
    List list;
    Watch* watch1 = new Watch("Rolex", "Switzerland", "Classic", 500.0);
    Watch* watch2 = new Watch("Casio", "Japan", "Sports", 300.0);
    Watch* watch3 = new Watch("TAG Heuer", "Switzerland", "Skeleton", 800.0);
    Watch* watch4 = new Watch("Fossil", "USA", "Fashion", 200.0);
    list.addWatch(watch1);
    list.addWatch(watch2);
    list.addWatch(watch3);
    list.addWatch(watch4);

    std::vector<Watch*> expected_result = {watch3};
    std::vector<Watch*> actual_result = list.findSwissWatchesWithSkeleton();

    ASSERT_EQ(expected_result, actual_result);

    // Cleanup
    delete watch1;
    delete watch2;
    delete watch3;
    delete watch4;
}

// Тест функції findClassicStyleWatches
TEST(ProgramingLab01, test_find_classic_style_watches)
{
    List list;
    Watch* watch1 = new Watch("Rolex", "Switzerland", "Classic", 500.0);
    Watch* watch2 = new Watch("Casio", "Japan", "Sports", 300.0);
    Watch* watch3 = new Watch("TAG Heuer", "Switzerland", "Skeleton", 800.0);
    Watch* watch4 = new Watch("Fossil", "USA", "Classic", 200.0);
    list.addWatch(watch1);
    list.addWatch(watch2);
    list.addWatch(watch3);
    list.addWatch(watch4);

    std::vector<Watch*> expected_result = {watch1, watch4};
    std::vector<Watch*> actual_result = list.findClassicStyleWatches();

    ASSERT_EQ(expected_result, actual_result);

    // Cleanup
    delete watch1;
    delete watch2;
    delete watch3;
    delete watch4;
}

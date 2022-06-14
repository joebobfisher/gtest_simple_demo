#include <gtest/gtest.h>
#include <vector>
#include "../src/GildedRose.h"

// Demonstrate some basic assertions.
TEST(gilded_rose_test, BasicAssertions) {
  vector<Item> items;
  items.push_back(Item("Normal Item", 5, 5));
  GildedRose app(items);
  app.updateQuality();
  
  EXPECT_EQ(items[0].quality, 4);
}

#include <gtest/gtest.h>
#include <vector>
#include "../src/GildedRose.h"

#include <iterator>


using std::vector;
using std::string;


struct TestDataStruct {
    string test_name;
    Item input;
    Item expected;
};

class GildedRoseTest :
public testing::TestWithParam<struct TestDataStruct> {
    // You can implement all the usual fixture class members here.
    // To access the test parameter, call GetParam() from class
    // TestWithParam<T>.
};

INSTANTIATE_TEST_SUITE_P(
    AgedBrie,
    GildedRoseTest,
    testing::Values(
        TestDataStruct {
            "AgedBrie_1_10_DecreaseSellInAndIncreaseQuality",
            Item("Aged Brie", 1, 10),
            Item("Aged Brie", 0, 11)
        },
        TestDataStruct {
            "AgedBrie_0_0_DecreaseSellInAndIncreaseQuality",
            Item("Aged Brie", 0, 0),
            Item("Aged Brie", -1, 2)
        },
        TestDataStruct {
            "AgedBrie_0_40_DecrementsSellinAndDoubleIncrementsQuality",
            Item("Aged Brie", 0, 40),
            Item("Aged Brie", -1, 42)
        },
        TestDataStruct {
            "AgedBrie_0_47_DecrementsSellInAndDoubleIncrementsQuality",
            Item("Aged Brie", 0, 47),
            Item("Aged Brie", -1, 49)
        },
        TestDataStruct {
            "AgedBrie_0_48_DecrementsSellInAndDoubleIncrementsQuality",
            Item("Aged Brie", 0, 48),
            Item("Aged Brie", -1, 50)
        },
        TestDataStruct {
            "AgedBrie_0_49_DecrementsSellInAndIncrementsQuality",
            Item("Aged Brie", 0, 49),
            Item("Aged Brie", -1, 50)
        },
        TestDataStruct {
            "AgedBrie_0_50_DecrementsSellIn",
            Item("Aged Brie", 0, 50),
            Item("Aged Brie", -1, 50)
        },
        TestDataStruct {
            "AgedBrie_0_60_DecrementsSellin",
            Item("Aged Brie", 0, 60),
            Item("Aged Brie", -1, 60)
        },
        TestDataStruct {
            "AgedBrie_1_40_DecrementsSellinAndIncrementsQuality",
            Item("Aged Brie", 1, 40),
            Item("Aged Brie", 0, 41)
        },
        TestDataStruct {
            "AgedBrie_1_49_DecrementsSellinAndIncrementsQuality",
            Item("Aged Brie", 1, 49),
            Item("Aged Brie", 0, 50)
        },
        TestDataStruct {
            "AgedBrie_1_50_DecrementsSellin",
            Item("Aged Brie", 1, 50),
            Item("Aged Brie", 0, 50)
        },
        TestDataStruct {
            "AgedBrie_1_51_DecrementsSellin",
            Item("Aged Brie", 1, 51),
            Item("Aged Brie", 0, 51)
        },
        TestDataStruct {
            "AgedBrie_1_99_DecrementsSellin",
            Item("Aged Brie", 1, 99),
            Item("Aged Brie", 0, 99)
        },
        TestDataStruct {
            "BackstagePass_0_0_DecreaseSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 0, 0),
            Item("Backstage passes to a TAFKAL80ETC concert", -1, 0)
        },
        TestDataStruct {
            "BackstagePass_11_50_DecreaseSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 11, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", 10, 50)
        },
        TestDataStruct {
            "BackstagePass_10_50_DecreaseSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 10, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", 9, 50)
        },
        TestDataStruct {
            "BackstagePass_10_49_DecreaseSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 10, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", 9, 50)
        },
        TestDataStruct {
            "BackstagePass_11_49_DecreaseSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 11, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", 10, 50)
        },
        TestDataStruct {
            "BackstagePass_5_50_DecrementsSellIn",
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 50),
            Item("Backstage passes to a TAFKAL80ETC concert", 4, 50)
        },
        TestDataStruct {
            "BackstagePass_5_49_DecrementsSellInAndIncrementsQuality",
            Item("Backstage passes to a TAFKAL80ETC concert", 5, 49),
            Item("Backstage passes to a TAFKAL80ETC concert", 4, 50)
        },
        TestDataStruct {
            "Sulfuras_0_1_Unchanged",
            Item("Sulfuras, Hand of Ragnaros", 0, 1),
            Item("Sulfuras, Hand of Ragnaros", 0, 1)
        },
        TestDataStruct {
            "Sulfuras_0_700_Unchanged",
            Item("Sulfuras, Hand of Ragnaros", 0, 700),
            Item("Sulfuras, Hand of Ragnaros", 0, 700)
        },
        TestDataStruct {
            "Sulfuras_1_700_Unchanged",
            Item("Sulfuras, Hand of Ragnaros", 1, 700),
            Item("Sulfuras, Hand of Ragnaros", 1, 700)
        },
        TestDataStruct {
            "Sulfuras_Negative1_700_Unchanged",
            Item("Sulfuras, Hand of Ragnaros", -1, 700),
            Item("Sulfuras, Hand of Ragnaros", -1, 700)
        },
        TestDataStruct {
            "Foo_Negative1_0_DecrementsSellIn",
            Item("Foo", -1, 0),
            Item("Foo", -2, 0)
        },
        TestDataStruct {
            "Foo_Negative1_1_DecrementsSellInAndQuality",
            Item("Foo", -1, 1),
            Item("Foo", -2, 0)
        },
        TestDataStruct {
            "Foo_0_0_DecrementsSellIn",
            Item("Foo", 0, 0),
            Item("Foo", -1, 0)
        },
        TestDataStruct {
            "Foo_0_1_DecrementsSellInAndQuality",
            Item("Foo", 0, 1),
            Item("Foo", -1, 0)
        },
        TestDataStruct {
            "Foo_0_2_DecrementsSellInAndDoubleDecrementsQuality",
            Item("Foo", 0, 2),
            Item("Foo", -1, 0)
        },
        TestDataStruct {
            "Foo_0_3_DecrementsSellInAndDoubleDecrementsQuality",
            Item("Foo", 0, 3),
            Item("Foo", -1, 1)
        },
        TestDataStruct {
            "Foo_1_0_DecrementsSellIn",
            Item("Foo", 1, 0),
            Item("Foo", 0, 0)
        },
        TestDataStruct {
            "Foo_1_1_DecrementsSellInAndQuality",
            Item("Foo", 1, 1),
            Item("Foo", 0, 0)
        },
        TestDataStruct {
            "Foo_2_0_DecrementsSellIn",
            Item("Foo", 2, 0),
            Item("Foo", 1, 0)
        },
        TestDataStruct {
            "Foo_2_1_DecrementsSellInAndQuality",
            Item("Foo", 2, 1),
            Item("Foo", 1, 0)
        }
    ),
    [](const testing::TestParamInfo<GildedRoseTest::ParamType>& test_data) {
        return test_data.param.test_name;}
    );

TEST_P(GildedRoseTest, TestUpdateQuality_ItemName_SellIn_Quality){
    vector<Item> items;
    struct TestDataStruct parameters = GetParam();
    Item inputItem = parameters.input;
    Item expected = parameters.expected;
    items.push_back(inputItem);
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(items.size(), 1);
    EXPECT_EQ(items[0].name,    expected.name);
    EXPECT_EQ(items[0].sellIn,  expected.sellIn);
    EXPECT_EQ(items[0].quality, expected.quality);
}

TEST(gilded_rose_test, noItems_yields_noItems) {
    vector<Item> items;
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(items.size(), 0);
}

TEST(gilded_rose_test, twoItems_yields_twoItems) {
    vector<Item> items;
    items.push_back(Item("Aged Brie", 0, 47));
    items.push_back(Item("Foo", 0, 3));
    GildedRose app(items);
    app.updateQuality();

    EXPECT_EQ(items.size(), 2);
    EXPECT_EQ(items[0].name,    "Aged Brie");
    EXPECT_EQ(items[0].sellIn,  -1);
    EXPECT_EQ(items[0].quality, 49);
    EXPECT_EQ(items[1].name,    "Foo");
    EXPECT_EQ(items[1].sellIn,  -1);
    EXPECT_EQ(items[1].quality, 1);
}

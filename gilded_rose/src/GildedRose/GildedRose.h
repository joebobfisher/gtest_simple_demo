#include <utility>
#include <vector>
#include "Item.h"

using namespace std;

class GildedRose
{
public:
    vector<Item> & items;

    explicit GildedRose(vector<Item> & items);
    void updateQuality();
    void incrementQuality(int i);
    void handleAgedBrie(int i);
    void handleBackstagePasses(int i);
};


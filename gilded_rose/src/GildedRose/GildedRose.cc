#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items) {}
    
void GildedRose::updateQuality() {
    for (auto & item : items) {
        // TODO This would be great to push down to Item subclasses, but we need to change the tests first!
        // Then we could just call item.updateQuality() for each item...
        if (item.name == "Aged Brie") {
            item.agedBrieUpdateQuality();
        } else if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
            item.backstagePassesUpdateQuality();
        } else if (item.name != "Sulfuras, Hand of Ragnaros") {
            item.updateQuality();
        }
    }
}

#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> & items) : items(items) {}
    
void GildedRose::updateQuality() {
    for (int i = 0; i < items.size(); i++) {
        if (items[i].name == "Aged Brie") {
            handleAgedBrie(i);
        } else if (items[i].name == "Backstage passes to a TAFKAL80ETC concert") {
            handleBackstagePasses(i);
        } else if (items[i].name != "Sulfuras, Hand of Ragnaros") {
            handleOthers(i);
        }
    }
}

void GildedRose::handleAgedBrie(int i) {
    incrementQuality(i);

    items[i].sellIn--;
    if (items[i].sellIn < 0) {
        incrementQuality(i);
    }
}

void GildedRose::handleBackstagePasses(int i) {
    incrementQuality(i);

    if (items[i].sellIn < 11)
    {
        incrementQuality(i);
    }

    if (items[i].sellIn < 6)
    {
        incrementQuality(i);
    }

    items[i].sellIn--;
    if (items[i].sellIn < 0) {
        items[i].quality = 0;
    }
}

void GildedRose::handleOthers(int i) {
    decrementQuality(i);

    items[i].sellIn--;
    if (items[i].sellIn < 0) {
        decrementQuality(i);
    }
}

void GildedRose::decrementQuality(int i) {
    if (items[i].quality > 0) {
        items[i].quality--;
    }
}

void GildedRose::incrementQuality(int i) {
    if (items[i].quality < 50) {
        items[i].quality++;
    }
}

#include "Item.h"

void Item::updateQuality() {
    decrementQuality();

    sellIn--;
    if (sellIn < 0) {
        decrementQuality();
    }
}

void Item::incrementQuality() {
    if (quality < 50) {
        quality++;
    }
}

void Item::decrementQuality() {
    if (quality > 0) {
        quality--;
    }
}


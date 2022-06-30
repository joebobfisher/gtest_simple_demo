#include "Item.h"

void Item::updateQuality() {
    decrementQuality();
    updateSellInAndQuality(this, [this] { this->decrementQuality(); });
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

template<typename Func>
void Item::updateSellInAndQuality(Item * item, Func fn) {
    item->sellIn--;
    if (item->sellIn < 0) {
        fn();
    }
}

// these are temporary until we can break out separate AgedBrie, et al. subclasses
void Item::agedBrieUpdateQuality() {
    incrementQuality();
    updateSellInAndQuality(this, [this] { this->incrementQuality(); });
}

void Item::backstagePassesUpdateQuality() {
    incrementQuality();
    backstagePassesIncrementQualityForSellIn();
    updateSellInAndQuality(this, [this] { this->quality = 0; });
}

void Item::backstagePassesIncrementQualityForSellIn() {
    if (sellIn < 11)
    {
        incrementQuality();
    }

    if (sellIn < 6)
    {
        incrementQuality();
    }
}
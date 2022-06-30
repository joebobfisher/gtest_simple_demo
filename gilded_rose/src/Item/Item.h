#ifndef MY_PROJECT_ITEM_H
#define MY_PROJECT_ITEM_H


#include <string>

using namespace std;

class Item {
public:
    string name;
    int sellIn;
    int quality;

    Item(string name, int sellIn, int quality) : name(std::move(name)), sellIn(sellIn), quality(quality) {}

    void updateQuality();

    // TODO these are temporary until we can break out separate AgedBrie, et al. subclasses
    void agedBrieUpdateQuality();
    void backstagePassesUpdateQuality();

private:
    void incrementQuality();
    void decrementQuality();
    template<typename Func>
    void updateSellInAndQuality(Item * item, Func fn);

    // This is also temporary until we can break out separate AgedBrie, et al. subclasses
    void backstagePassesIncrementQualityForSellIn();
};


#endif //MY_PROJECT_ITEM_H

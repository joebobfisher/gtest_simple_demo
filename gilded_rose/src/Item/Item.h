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
    void incrementQuality();
    void decrementQuality();
};


#endif //MY_PROJECT_ITEM_H

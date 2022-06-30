#include <string>
#include <utility>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;

    Item(string name, int sellIn, int quality) : name(std::move(name)), sellIn(sellIn), quality(quality) {}
};

class GildedRose
{
public:
    vector<Item> & items;

    explicit GildedRose(vector<Item> & items);
    void updateQuality();
    void incrementQuality(int i);
    void decrementQuality(int i);
    void handleAgedBrie(int i);
    void handleBackstagePasses(int i);
    void handleOthers(int i);
};


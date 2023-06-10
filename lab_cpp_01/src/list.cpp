#include "list.h"
#include <iostream>

List::List() {}

List::~List() {
    for (const auto& watch : watches) {
        delete watch;
    }
}

void List::addWatch(Watch* watch) {
    watches.push_back(watch);
}

void List::removeWatch(size_t index) {
    if (index < watches.size()) {
        delete watches[index];
        watches.erase(watches.begin() + index);
    }
}

Watch* List::getWatch(size_t index) const {
    if (index < watches.size()) {
        return watches[index];
    }
    return nullptr;
}

void List::print() const {
    for (const auto& watch : watches) {
        watch->print();
        std::cout << std::endl;
    }
}

std::vector<Watch*> List::findWatchesWithPriceLessThan(double price) const {
    std::vector<Watch*> result;
    for (const auto& watch : watches) {
        if (watch->getPrice() < price) {
            result.push_back(watch);
        }
    }
    return result;
}

std::vector<Watch*> List::findSwissWatchesWithSkeleton() const {
    std::vector<Watch*> result;
    for (const auto& watch : watches) {
        if (watch->getManufacturerCountry() == "Switzerland" && watch->getStyle() == "Skeleton") {
            result.push_back(watch);
        }
    }
    return result;
}

std::vector<Watch*> List::findClassicStyleWatches() const {
    std::vector<Watch*> result;
    for (const auto& watch : watches) {
        if (watch->getStyle() == "Classic") {
            result.push_back(watch);
        }
    }
    return result;
}

#include "list.h"
#include <fstream>
#include <iostream>
#include <sstream>

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
    if (index >= 0 && index < watches.size()) {
        delete watches[index];
        watches.erase(watches.begin() + index);
    }
}

Watch* List::getWatch(size_t index) const {
    if (index >= 0 && index < watches.size()) {
        return watches[index];
    }
    return nullptr;
}

void List::print() const {
    for (const auto& watch : watches) {
        watch->print();
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

void List::readFromFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cout << "Не удалось открыть файл: " << fileName << std::endl;
        return;
    }
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string manufacturer;
        std::string model;
        std::string style;
        std::string country;
        double price;
        if (iss >> manufacturer >> model >> style >> country >> price) {
            watches.push_back(new Watch(false, model, price, manufacturer, style, country));
        }
    }
    inputFile.close();
}

void List::writeToFile(const std::string& fileName) const {
    std::ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        std::cout << "Не вдалося відкрити файл: " << fileName << std::endl;
        return;
    }
    for (const auto& watch : watches) {
        outputFile << watch->getManufacturerName() << " "
                   << watch->getModel() << " "
                   << watch->getStyle() << " "
                   << watch->getManufacturerCountry() << " "
                   << watch->getPrice() << std::endl;
    }
    outputFile.close();
}


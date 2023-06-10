#include "entity.h"

Watch::Watch(bool isWaterproof, const std::string& watchModel, double watchPrice, const std::string& manufacturerName,
    const std::string& manufacturerCountry, const std::string& watchStyle)
    : waterproof(isWaterproof), model(watchModel), price(watchPrice), style(watchStyle) {
    manufacturer.name = manufacturerName;
    manufacturer.country = manufacturerCountry;
}

bool Watch::isWaterproof() const {
    return waterproof;
}

std::string Watch::getModel() const {
    return model;
}

double Watch::getPrice() const {
    return price;
}

std::string Watch::getManufacturerName() const {
    return manufacturer.name;
}

std::string Watch::getManufacturerCountry() const {
    return manufacturer.country;
}

std::string Watch::getStyle() const {
    return style;
}

void Watch::setWaterproof(bool isWaterproof) {
    waterproof = isWaterproof;
}

void Watch::setModel(const std::string& watchModel) {
    model = watchModel;
}

void Watch::setPrice(double watchPrice) {
    price = watchPrice;
}

void Watch::setManufacturerName(const std::string& manufacturerName) {
    manufacturer.name = manufacturerName;
}

void Watch::setManufacturerCountry(const std::string& manufacturerCountry) {
    manufacturer.country = manufacturerCountry;
}

void Watch::setStyle(const std::string& watchStyle) {
    style = watchStyle;
}

std::string Watch::toString() const {
    std::stringstream ss;
    ss << "Модель: " << model << std::endl;
    ss << "Ціна: " << price << " USD" << std::endl;
    ss << "Виробник: " << manufacturer.name << " (" << manufacturer.country << ")" << std::endl;
    ss << "Стиль: " << style << std::endl;
    ss << "Водонепроникний: " << (waterproof ? "Так" : "Ні") << std::endl;
    return ss.str();
}

void Watch::fromString(const std::string& watchString) {
    std::stringstream ss(watchString);
    std::string line;
    while (std::getline(ss, line)) {
        if (line.find("Модель:") != std::string::npos) {
            model = line.substr(line.find(":") + 2);
        }
        else if (line.find("Ціна:") != std::string::npos) {
            std::string priceStr = line.substr(line.find(":") + 2);
            price = std::stod(priceStr);
        }
        else if (line.find("Виробник:") != std::string::npos) {
            std::string manufacturerStr = line.substr(line.find(":") + 2);
            size_t countryStart = manufacturerStr.find("(");
            size_t countryEnd = manufacturerStr.find(")");
            manufacturer.name = manufacturerStr.substr(0, countryStart - 1);
            manufacturer.country = manufacturerStr.substr(countryStart + 1, countryEnd - countryStart - 1);
        }
        else if (line.find("Стиль:") != std::string::npos) {
            style = line.substr(line.find(":") + 2);
        }
        else if (line.find("Водонепроникний:") != std::string::npos) {
            std::string waterproofStr = line.substr(line.find(":") + 2);
            waterproof = (waterproofStr == "Так");
        }
    }
}

void Watch::print() const {
    std::cout << toString();
}

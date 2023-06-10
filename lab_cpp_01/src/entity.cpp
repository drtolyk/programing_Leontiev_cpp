#include "entity.h"
#include <iostream>

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

void Watch::print() const {
    std::cout << "Модель: " << model << std::endl;
    std::cout << "Ціна: " << price << " USD" << std::endl;
    std::cout << "Виробник: " << manufacturer.name << " (" << manufacturer.country << ")" << std::endl;
    std::cout << "Стиль: " << style << std::endl;
    std::cout << "Водонепроникний: " << (waterproof ? "Так" : "Ні") << std::endl;
}

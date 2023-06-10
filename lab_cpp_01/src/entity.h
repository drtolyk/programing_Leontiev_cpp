#include <string>
#include <iostream>
#include <ostream>

struct Manufacturer {
    std::string name;
    std::string country;
};

class Watch {
private:
    bool waterproof;
    std::string model;
    double price;
    Manufacturer manufacturer;
    std::string style;

public:
    Watch(bool waterproof, const std::string& model, double price, const std::string& manufacturerName,
        const std::string& manufacturerCountry, const std::string& style);

    bool isWaterproof() const;
    std::string getModel() const;
    double getPrice() const;
    std::string getManufacturerName() const;
    std::string getManufacturerCountry() const;
    std::string getStyle() const;

    void setWaterproof(bool waterproof);
    void setModel(const std::string& model);
    void setPrice(double price);
    void setManufacturerName(const std::string& manufacturerName);
    void setManufacturerCountry(const std::string& manufacturerCountry);
    void setStyle(const std::string& style);

    void print() const;
};


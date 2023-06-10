#include "list.h"
#include <iostream>

int main() {
    List watchList;

    // Додавання годинників
    watchList.addWatch(new Watch(true, "EFR-526L-1AVUEF", 300, "Casio", "Japan", "Sport"));
    watchList.addWatch(new Watch(false, "CS 55", 1200, "Swatch", "Switzerland", "Classic"));
    watchList.addWatch(new Watch(true, "XYZ", 500, "XYZ Manufacturer", "USA", "Fashion"));

    // Виведення всіх годинників
    std::cout << "Усі годинники:" << std::endl;
    watchList.print();

    // Знайти годинники з ціною менше 400$
    std::cout << "Годинники з ціною менше 400 USD:" << std::endl;
    std::vector<Watch*> cheapWatches = watchList.findWatchesWithPriceLessThan(400);
    for (const auto& watch : cheapWatches) {
        std::cout << watch->toString() << std::endl;
        std::cout << std::endl;
    }

    // Знайти всі швейцарські годинники зі скелетоном
    std::cout << "Швейцарські годинники зі скелетоном:" << std::endl;
    std::vector<Watch*> swissSkeletonWatches = watchList.findSwissWatchesWithSkeleton();
    for (const auto& watch : swissSkeletonWatches) {
        std::cout << watch->toString() << std::endl;
        std::cout << std::endl;
    }

    // Знайти всі годинники стилю "Класика"
    std::cout << "Годинники стилю \"Класика\":" << std::endl;
    std::vector<Watch*> classicStyleWatches = watchList.findClassicStyleWatches();
    for (const auto& watch : classicStyleWatches) {
        std::cout << watch->toString() << std::endl;
        std::cout << std::endl;
    }

    // Записати дані в файл
    watchList.writeToFile("watches.txt");

    // Зчитати дані з файлу
    List newWatchList;
    newWatchList.readFromFile("watches.txt");

    // Вивести годинники з нового списку
    std::cout << "Годинники з нового списку:" << std::endl;
    newWatchList.print();

    return 0;
}

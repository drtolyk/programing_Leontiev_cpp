#include "list.h"

int main() {
    List watchList;

    watchList.addWatch(new Watch(true, "EFR-526L-1AVUEF", 300, "Casio", "Japan", "Sport"));
    watchList.addWatch(new Watch(false, "CS 55", 1200, "Swatch", "Switzerland", "Classic"));
    watchList.addWatch(new Watch(true, "XYZ", 500, "XYZ Manufacturer", "USA", "Fashion"));

    std::cout << "Усі годинники:" << std::endl;
    watchList.print();

    std::cout << "Годинники з ціною менше 400 USD:" << std::endl;
    std::vector<Watch*> cheapWatches = watchList.findWatchesWithPriceLessThan(400);
    for (const auto& watch : cheapWatches) {
        watch->print();
        std::cout << std::endl;
    }

    std::cout << "Швейцарські годинники зі скелетоном:" << std::endl;
    std::vector<Watch*> swissSkeletonWatches = watchList.findSwissWatchesWithSkeleton();
    for (const auto& watch : swissSkeletonWatches) {
        watch->print();
        std::cout << std::endl;
    }

    std::cout << "годинники стилю Класика:" << std::endl;
    std::vector<Watch*> classicWatches = watchList.findClassicStyleWatches();
    for (const auto& watch : classicWatches) {
        watch->print();
        std::cout << std::endl;
    }

    watchList.removeWatch(0);
    watchList.removeWatch(1);

    return 0;
}

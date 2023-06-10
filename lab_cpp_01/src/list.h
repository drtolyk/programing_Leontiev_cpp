#include "entity.h"
#include <vector>

class List {
private:
    std::vector<Watch*> watches;

public:
    List();
    ~List();

    void addWatch(Watch* watch);
    void removeWatch(size_t index);
    Watch* getWatch(size_t index) const;
    void print() const;

    std::vector<Watch*> findWatchesWithPriceLessThan(double price) const;
    std::vector<Watch*> findSwissWatchesWithSkeleton() const;
    std::vector<Watch*> findClassicStyleWatches() const;
};

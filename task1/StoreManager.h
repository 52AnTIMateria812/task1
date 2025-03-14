#include <vector>
#include "Store.h"

class StoreManager {
private:
    std::vector<Store*> stores;

public:
    void addStore(Store* store);
    Store* findStoreWithLowestPrice(const std::string& productName);
};
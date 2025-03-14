#include "StoreManager.h"
#include <limits>

void StoreManager::addStore(Store* store) { stores.push_back(store); }

Store* StoreManager::findStoreWithLowestPrice(const std::string& productName) {
    Store* result = nullptr;
    double minPrice = std::numeric_limits<double>::max();
    
    for (auto store : stores) {
        try {
            double price = store->getProductPrice(productName);
            if (price < minPrice && store->getProductQuantity(productName) > 0) {
                minPrice = price;
                result = store;
            }
        } catch (...) {}
    }
    return result;
}
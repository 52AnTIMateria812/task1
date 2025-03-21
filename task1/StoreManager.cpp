#include "StoreManager.h"
#include <limits>

Store* StoreManager::findStoreWithLowestPrice(const std::string& productName) {
    Store* result = nullptr;
    double minPrice = std::numeric_limits<double>::max();

    for (auto store : stores) {
        try {
            double price = store->getProductPrice(productName);
            int available = store->getProductQuantity(productName);
            
            if (available > 0 && price < minPrice) {
                minPrice = price;
                result = store;
            }
        } catch (const std::runtime_error&) {
            // Продукт отсутствует в магазине - пропускаем
        }
    }
    return result;
}

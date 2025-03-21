#include <iostream>
#include "Store.h"
#include "Customer.h"
#include "StoreManager.h"

int main() {
    try {
        // Инициализация магазинов
        Store store1("SuperMart");
        store1.addProduct("Milk", 2.5, 10);
        store1.addProduct("Bread", 1.0, 15);

        Store store2("MegaMarket");
        store2.addProduct("Milk", 2.2, 8);
        store2.addProduct("Eggs", 1.5, 20);

        // Менеджер магазинов
        StoreManager manager;
        manager.addStore(&store1);
        manager.addStore(&store2);

        // Покупатель
        Customer customer("Alice", 50.0);
        customer.addToShoppingList("Milk", 2);
        customer.addToShoppingList("Bread", 1);

        // Покупка товаров
        customer.purchaseItems(store1);
        std::cout << "Purchase successful! Balance: " 
                  << customer.getBalance() << "\n";

        // Поиск лучшей цены
        if (auto bestStore = manager.findStoreWithLowestPrice("Milk")) {
            std::cout << "Best price for Milk at " 
                      << bestStore->getName() << ": $" 
                      << bestStore->getProductPrice("Milk") << "\n";
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
#include "Customer.h"
#include "Store.h"
#include <stdexcept>

Customer::Customer(const std::string& name, double initialBalance) 
    : name(name), balance(initialBalance) {
    if (initialBalance < 0) 
        throw std::invalid_argument("Negative balance");
}

void Customer::addToShoppingList(const std::string& productName, int quantity) {
    if (quantity <= 0) 
        throw std::invalid_argument("Invalid quantity");
    shoppingList.emplace_back(productName, quantity);
}

void Customer::clearShoppingList() { shoppingList.clear(); }

void Customer::addBalance(double amount) {
    if (amount < 0) 
        throw std::invalid_argument("Negative amount");
    balance += amount;
}

double Customer::getBalance() const { return balance; }

void Customer::purchaseItems(Store& store) {
    double totalCost = 0;
    std::vector<std::pair<std::string, int>> itemsToBuy = shoppingList;

    // Check availability and calculate total
    for (const auto& item : itemsToBuy) {
        const auto& [product, qty] = item;
        int available = store.getProductQuantity(product);
        if (available < qty)
            throw std::runtime_error("Not enough " + product);
        totalCost += store.getProductPrice(product) * qty;
    }

    if (totalCost > balance)
        throw std::runtime_error("Insufficient funds");

    // Process purchase
    for (const auto& item : itemsToBuy) {
        if (!store.sellProduct(item.first, item.second))
            throw std::runtime_error("Failed to purchase " + item.first);
    }
    balance -= totalCost;
    shoppingList.clear();
}
#include "Store.h"

Store::Store(const std::string& name) : name(name) {}

std::string Store::getName() const { return name; }

void Store::addProduct(const std::string& productName, double price, int quantity) {
    if (price <= 0 || quantity <= 0) 
        throw std::invalid_argument("Invalid price or quantity");
    products[productName] = {price, quantity};
}

void Store::updateQuantity(const std::string& productName, int newQuantity) {
    if (newQuantity < 0) throw std::invalid_argument("Quantity cannot be negative");
    auto it = products.find(productName);
    if (it == products.end()) 
        throw std::runtime_error("Product not found");
    it->second.second = newQuantity;
}

void Store::setPrice(const std::string& productName, double newPrice) {
    if (newPrice <= 0) throw std::invalid_argument("Price must be positive");
    auto it = products.find(productName);
    if (it == products.end())
        throw std::runtime_error("Product not found");
    it->second.first = newPrice;
}

bool Store::sellProduct(const std::string& productName, int quantity) {
    auto it = products.find(productName);
    if (it == products.end() || it->second.second < quantity)
        return false;
    it->second.second -= quantity;
    return true;
}

double Store::getProductPrice(const std::string& productName) const {
    auto it = products.find(productName);
    if (it == products.end())
        throw std::runtime_error("Product not found");
    return it->second.first;
}

int Store::getProductQuantity(const std::string& productName) const {
    auto it = products.find(productName);
    if (it == products.end())
        throw std::runtime_error("Product not found");
    return it->second.second;
}
#include <string>
#include <vector>

class Store;

class Customer {
private:
    std::string name;
    double balance;
    // Список покупок хранит товары с их количеством
    std::vector<std::pair<std::string, int>> shoppingList; 

public:
    Customer(const std::string& name, double initialBalance);
    void addToShoppingList(const std::string& productName, int quantity);
    void clearShoppingList();
    void addBalance(double amount);
    double getBalance() const;
    void purchaseItems(Store& store);
};

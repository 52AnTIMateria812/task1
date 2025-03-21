#include <string>
#include <map>
#include <stdexcept>

class Store {
private:
    std::string name;
    // Карта продуктов: ключ - название, значение - пара (цена, количество)
    std::map<std::string, std::pair<double, int>> products;

public:
    Store(const std::string& name);

    std::string getName() const;
    void addProduct(const std::string& productName, double price, int quantity);
    void updateQuantity(const std::string& productName, int newQuantity);
    void setPrice(const std::string& productName, double newPrice);
    bool sellProduct(const std::string& productName, int quantity);
    double getProductPrice(const std::string& productName) const;
    int getProductQuantity(const std::string& productName) const;
};

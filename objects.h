#include <string>
#include <unordered_map>

// Product Object
class Product
{
private:
    int id;
    std::string name;
    double price;

public:
    Product() {}
    Product(int item_id, std::string item_name, double item_price)
    {
        id = item_id;
        this->name = item_name;
        this->price = item_price;
    }
    std::string getItemName()
    {
        return name;
    }

    std::string getDisplayName()
    {
        return name + " : $" + std::to_string(price).substr(0, 4) + "\n";
    }
    char getFirstLetter()
    {
        return name[0];
    }
    friend class Item;
    friend class Cart;
};

class Item
{
    Product x;
    int count = 0;

public:
    Item() {}
    Item(Product temp, int y) : x(temp), count(y) {}

    double getItemPrice()
    {
        return count * x.price;
    }

    std::string getItemsInfo()
    {
        return std::to_string(count) + " x " + x.name + "\n";
    }
    friend class Cart;
};

// Cart Object
class Cart
{
private:
    std::unordered_map<int, Item> userCart;

public:
    void addProduct(Product prod)
    {

        // Check if item is already in hashmap
        if (userCart.count(prod.id) == 0)
        {
            int val = 1;
            Item newProduct(prod, val);
            userCart.insert(std::pair<int, Item>(prod.id, newProduct));
        }
        else
        {
            userCart[prod.id].count++;
        }
    }

    std::string viewCart()
    {
        std::string itemsCarted = "";
        if (userCart.empty())
        {
            itemsCarted += "\nYour cart is empty.\n";
        }
        else
        {
            for (auto list : userCart)
            {
                auto specificItem = list.second;
                itemsCarted += specificItem.getItemsInfo();
            }
        }
        return itemsCarted + "\nTotal price: " + std::to_string(getCartTotal()).substr(0, 4) + "\n";
    }

    double getCartTotal()
    {
        double totalSum = 0;
        for (auto list : userCart)
        {
            auto specificItem = list.second;
            totalSum += specificItem.getItemPrice();
        }
        return totalSum;
    }
    bool isEmpty()
    {
        return userCart.empty();
    }
};

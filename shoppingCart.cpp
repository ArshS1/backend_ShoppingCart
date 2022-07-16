#include <iostream>
#include <vector>
#include "objects.h"

std::vector<Product> allItems = {
    Product(1, "Cookies", 3.99),
    Product(2, "Milk", 4.99),
    Product(3, "KitKat", 1.99),
    Product(4, "Pizza", 12.99),
    Product(5, "Burger", 4.99),
    Product(6, "Taco", 2.99),
};

Product addProduct()
{
    std::cout << "The available products are listed below: \n";

    for (auto prod : allItems)
    {
        std::cout << "(" << prod.getFirstLetter() << ")" << prod.getDisplayName().substr(1);
    }

    // Make a valid choice to add item to cart
    std::cout << "------------**------------\n";
    char choice;
    std::cout << "Please enter a choice: ";
    std::cin >> choice;
    while (!(choice == 'C' || choice == 'M' || choice == 'K' || choice == 'P' || choice == 'B' || choice == 'T'))
    {
        std::cout << "\n------Please make a valid choice.------\n\n";
        std::cout << "Please enter a choice: ";
        std::cin >> choice;
    }
    std::cout << "------------**------------\n";

    for (auto prod : allItems)
    {
        if (choice == prod.getFirstLetter())
        {
            return prod;
        }
    }
    return Product(7, "TEST", 0);
}

bool userCheckout(Cart &cart)
{
    if (cart.isEmpty())
    {
        return false;
    }

    double total = cart.getCartTotal();

    double paid;
    std::cout << "Please pay: " << std::to_string(total).substr(0, 4) << std::endl;
    std::cout << "Payment: ";
    std::cin >> paid;
    while (paid < total)
    {
        std::cout << "Balance remaining: " << std::to_string(total - paid).substr(0, 4);
        std::cin >> paid;

    }

    std::cout << "Thanks for your payment, here's your change: " << std::to_string(paid - total).substr(0, 4); 
    return true; 
}

int main()
{
    char choice;
    Cart cart;
    // Take in input from user
    while (true)
    {
        std::cout << "Make a choice: (a)dd item | (v)iew cart | (c)heckout: ";
        std::cin >> choice;

        // Validate user choice and accordingly show data
        if (choice == 'a' || choice == 'v' || choice == 'c')
        {
            if (choice == 'a')
            {
                // Show list of items
                Product userChose = addProduct();

                std::cout << "\nAdded to the cart: "
                          << userChose.getItemName() << "\n"
                          << std::endl;
                // Add mentioned item to cart
                cart.addProduct(userChose);
            }
            else if (choice == 'v')
            {
                // Show the cart
                std::cout << "------------**------------\n";
                std::cout << cart.viewCart();
                std::cout << "------------**------------\n";
            }
            else
            {
                // Prompt user to checkout with Cash
                userCheckout(cart);
                break;
            }
        }
        else
        {
            std::cout << "\n------Please make a valid choice.------\n\n";
        }
    }

    return 0;
}
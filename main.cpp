#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class User
{
private:
    string name;

public:
    void setName(const string &newName)
    {
        name = newName;
    }

    string getName()
    {
        return name;
    }

    void updateUser(const string &newName)
    {
        setName(newName);
    }

    void showProfile()
    {
        cout << "Name: " << name << endl;
    }
};

class Product
{
private:
    string productName = "", productDescription = "", productTitle = "";
    float productRating = 0;
    double productPrice = 0, productQuantity = 0;

public:
    void setProduct(const string &newProductName, const string &newProductDescription, const float &newProductRating, const double &newProductPrice, const double &newProductQuantity)
    {
        productName = newProductName;
        productDescription = newProductDescription;
        productRating = newProductRating;
        productPrice = newProductPrice;
        productQuantity = newProductQuantity;
    }

    void addProduct()
    {
        cout << "Product name: ";
        getline(cin, productName);

        cout << "Product description: ";
        getline(cin, productDescription);

        while (true)
        {
            cout << "Product rating (0 - 5): ";
            cin >> productRating;

            if (productRating >= 0 && productRating <= 5)
            {
                break;
            }
            else
            {
                cout << "Rating should be between 0 and 5" << endl;
            }
        }

        cout << "Product price: ";
        cin >> productPrice;

        cout << "Product quantity: ";
        cin >> productQuantity;

        cin.ignore();
    }

    void showProduct()
    {
        cout << fixed << setprecision(2);
        cout << "\nProduct name: " << productName << endl;
        cout << "Product description: " << productDescription << endl;
        cout << "Product price: " << productPrice << endl;
        cout << "Product rating: " << productRating << endl;
        cout << "Product quantity: " << productQuantity << endl;
    }

    void searchProduct(Product product[], int size)
    {
        cout << "-----------------------------------------" << endl;
        cout << "|  ";
        cout << "           Search products";
        cout << "           |" << endl;
        cout << "-----------------------------------------" << endl;

        cout << "Enter product to search: ";
        getline(cin, productTitle);
        bool found = false;
        for (int i = 0; i < size; i++)
        {
            if (productTitle == product[i].productName)
            {
                cout << "Product found: " << endl;
                product[i].showProduct();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Product not found" << endl;
        }
    }

    void updateProduct(Product product[], int size)
    {
        cout << "-----------------------------------------" << endl;
        cout << "|  ";
        cout << "           Update product";
        cout << "           |" << endl;
        cout << "-----------------------------------------" << endl;

        cout << "Enter product to update: ";
        getline(cin, productTitle);
        bool found = false;

        for (int i = 0; i < size; i++)
        {
            if (productTitle == product[i].productName)
            {
                cout << "Enter new product details:" << endl;

                string newProductName, newProductDescription;
                float newProductRating;
                double newProductPrice, newProductQuantity;

                cout << "Product name: ";
                getline(cin, newProductName);

                cout << "Product description: ";
                getline(cin, newProductDescription);

                while (true)
                {
                    cout << "Product rating (0 - 5): ";
                    cin >> newProductRating;

                    if (newProductRating >= 0 && newProductRating <= 5)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Rating should be between 0 and 5" << endl;
                    }
                }

                cout << "Product price: ";
                cin >> newProductPrice;

                cout << "Product quantity: ";
                cin >> newProductQuantity;

                cin.ignore();

                product[i].setProduct(newProductName, newProductDescription, newProductRating, newProductPrice, newProductQuantity);
                cout << "Product updated: " << endl;
                product[i].showProduct();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Product not found" << endl;
        }
    }
};

class Wishlist : public Product
{
private:
    Product wishlist[2];
    int count = 0;

public:
    void addToWishlist(Product p)
    {
        if (count < 2)
        {
            wishlist[count] = p;
            count++;
            cout << "Product added to wishlist." << endl;
        }
        else
        {
            cout << "Wishlist is full." << endl;
        }
    }

    void showWishlist()
    {
        if (count == 0)
        {
            cout << "Wishlist is empty." << endl;
        }
        else
        {
            cout << "-----------------------------------------" << endl;
            cout << "|  ";
            cout << "           Wishlist";
            cout << "                |" << endl;
            cout << "-----------------------------------------" << endl;
            for (int i = 0; i < count; i++)
            {
                wishlist[i].showProduct();
            }
        }
    }
};

void mainMenu();

void adminMenu()
{
    const string adminEmail = "admin@admin.com";
    const string adminPassword = "admin123";
    string getAdminEmail, getAdminPass;
    int size = 2;
    Product product[size];
    string option;

    cout << "Enter admin email: ";
    getline(cin, getAdminEmail);
    cout << "Enter admin password: ";
    getline(cin, getAdminPass);

    if (adminEmail == getAdminEmail && adminPassword == getAdminPass)
    {
        while (true)
        {
            cout << "-----------------------------------------" << endl;
            cout << "|  ";
            cout << "           Welcome Admin";
            cout << "             |" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "1. Add product" << endl;
            cout << "2. Show products" << endl;
            cout << "3. Update product" << endl;
            cout << "4. Search product" << endl;
            cout << "5. Logout" << endl;

            cout << "Choose from (1 to 6): ";
            getline(cin, option);

            if (option == "1" || option == "Add product" || option == "add product" || option == "add")
            {
                for (int i = 0; i < size; i++)
                {
                    product[i].addProduct();
                }
            }
            else if (option == "2" || option == "Show product" || option == "show product" || option == "show")
            {
                cout << "-----------------------------------------" << endl;
                cout << "|  ";
                cout << "           See all products";
                cout << "          |" << endl;
                cout << "-----------------------------------------" << endl;
                for (int i = 0; i < size; i++)
                {
                    product[i].showProduct();
                }
            }
            else if (option == "3" || option == "Update product" || option == "update product" || option == "update")
            {
                product[0].updateProduct(product, size);
            }
            else if (option == "4" || option == "Search Product" || option == "search product" || option == "search")
            {
                product[0].searchProduct(product, size);
            }
            else if (option == "5" || option == "Logout" || option == "logout" || option == "quit")
            {
                mainMenu();
            }
            else
            {
                cout << "Invalid option, please try again." << endl;
            }
        }
    }
    else
    {
        cout << "Incorrect credentials" << endl;
    }
}

void userMenu()
{
    string newName;
    int size = 2;
    User user;
    Product product[size];
    string option;
    Wishlist wishlist;

    cout << "Enter your name: ";
    getline(cin, newName);
    user.setName(newName);
    while (true)
    {
        cout << "-----------------------------------------" << endl;
        cout << "|  ";
        cout << "           Welcome " << user.getName();
        cout << "              |" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "1. Show products" << endl;
        cout << "2. Add to cart" << endl;
        cout << "3. Update profile" << endl;
        cout << "4. Show profile" << endl;
        cout << "5. Search Product" << endl;
        cout << "6. Add wishlist" << endl;
        cout << "7. Show Wish List" << endl;
        cout << "8. Logout" << endl;

        cout << "Choose from (1 to 6): ";
        getline(cin, option);

        if (option == "1" || option == "Show product" || option == "show product" || option == "show")
        {
            cout << "-----------------------------------------" << endl;
            cout << "|  ";
            cout << "           See all products";
            cout << "          |" << endl;
            cout << "-----------------------------------------" << endl;
            for (int i = 0; i < size; i++)
            {
                product[i].showProduct();
            }
        }
        else if (option == "3" || option == "Update profile" || option == "update profile" || option == "update")
        {
            cout << "Enter your name: ";
            getline(cin, newName);
            user.updateUser(newName);
        }
        else if (option == "4" || option == "Show Profile" || option == "show profile" || option == "profile")
        {
            user.showProfile();
        }
        else if (option == "5" || option == "Search Product" || option == "search product" || option == "search")
        {
            product[0].searchProduct(product, size);
        }
        else if (option == "6" || option == "Add wishlist" || option == "wishlist")
        {
            product[0].addProduct();
            wishlist.addToWishlist(product[0]);
        }
        else if (option == "7" || option == "Show wishlist")
        {
            wishlist.showWishlist();
        }
        else if (option == "8" || option == "Logout" || option == "logout" || option == "quit")
        {
            mainMenu();
        }
        else
        {
            cout << "Invalid option, please try again." << endl;
        }
    }
}

void mainMenu()
{
    string option;
    cout << "Menu" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|  ";
    cout << "              Login";
    cout << "                  |" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "1. Admin" << endl;
    cout << "2. User" << endl;
    cout << "3. Exit" << endl;

    cout << "Choose option: ";
    getline(cin, option);

    if (option == "admin" || option == "Admin" || option == "1")
    {
        adminMenu();
    }
    else if (option == "user" || option == "User" || option == "2")
    {
        userMenu();
    }
    else if (option == "exit" || option == "3")
    {
        return;
    }
    else
    {
        cout << "Incorrect option: " << endl;
    }
}

int main()
{
    mainMenu();

    return 0;
}

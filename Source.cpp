#include <iostream>
#include<windows.h>
#include<string>
using namespace std;

class User {
private:
    string name;
public:
    User(string name) {
        this->name = name;
    };
    void setData(string name) {
        this->name = name;
    };
    string getName() {
        return this->name;
    };
    void displayInfo() {
        cout << "Name: " << this->name << endl;
    };
    void setName(string name) {
        this->name = name;
    }
};

class Product {
private:
    string name;
    int price;

public:
    Product(string name, int price) {
        this->name = name;
        this->price = price;
    };
    Product(string name, int price, bool payed) {
        this->name = name;
        this->price = price;
    };
    void setData(string name, int price) {
        this->name = name;
        this->price = price;
    };
    string getName() {
        return this->name;
    };
    int getPrice() {
        return this->price;
    };
    void displayInfo() {

    };
};

Product* products[] = {
  new Product("Apple", 20),
  new Product("Banana", 100),
  new Product("Pineapple", 50),
  new Product("Cucember", 300),
  new Product("Pencil", 300),
  new Product("Paper", 300),
  new Product("Computer", 300),
  new Product("Coffee", 300),
  new Product("Charger", 300),
  new Product("Table", 300),
  new Product("Mouse", 300),
  new Product("Keyboard", 300)
};

int numProducts = 12;

void showCommands() {
    cout << "Print one of the commands: " << endl;
    cout << "a: " << "get user details" << endl;
    cout << "b: " << "add money to balance" << endl;
    cout << "c: " << "get list of products" << endl;
    cout << "d: " << "search product" << endl;
    cout << "e: " << "search products that cost less than specified" << endl;
    cout << "f: " << "search products that cost more than specified" << endl;
    cout << "g: " << "get number of products in supermarket" << endl;
    cout << "h: " << "change name" << endl;
    cout << "i: " << "buy smth" << endl;
    cout << "~: " << "exit program" << endl;
}

bool validateName(string name) {
    if (name.length() < 3) {
        cout << "Name must be 3 or more characters" << endl;
        return false;
    }
    else if (name.length() > 15) {
        cout << "Name must be at most 15 characters" << endl;
        return false;
    }
    return true;
}

void getUserDetails(User* user) {
    cout << "Name:    " << user->getName() << endl;
}

void getListOfProducts() {
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << products[i]->getName() << " - " << products[i]->getPrice() << "$" << endl;
    }
}

void searchProduct() {
    string productName;
    cout << "Enter product name" << endl;
    cin >> productName;
    for (int i = 0; i < numProducts; i++) {
        if (products[i]->getName() == productName) {
            cout << products[i]->getName() << " - " << products[i]->getPrice() << "$" << endl;
            return;
        }
    }
    cout << "Product with name: " << productName << " was not found" << endl;
}

void getProductThatCostLessThan() {
    int amount;
    int productIndex = 1;
    cout << "Enter amount of money" << endl;
    cin >> amount;
    cout << "Products that cost less than " << amount << "$:" << endl;
    for (int i = 0; i < numProducts; i++) {
        if (products[i]->getPrice() < amount) {
            cout << productIndex << ". " << products[i]->getName() << " " << products[i]->getPrice() << endl;
        }
        productIndex++;
    }
}

void getProductThatCostMoreThan() {
    int amount;
    int productIndex = 1;
    cout << "Enter amount of money" << endl;
    cin >> amount;
    cout << "Products that cost more than " << amount << "$:" << endl;
    for (int i = 0; i > numProducts; i++) {
        if (products[i]->getPrice() < amount) {
            cout << productIndex << ". " << products[i]->getName() << " " << products[i]->getPrice() << endl;
        }
        productIndex++;
    }
}

void getNumberOfProducts() {
    cout << "Number of products: " << numProducts << endl;
}

void changeName(User* user) {
    string name;
    do {
        cout << "Print your name" << endl;
        cin >> name;
        if (name.length() < 2) {
            cout << "Your name must be at minimum 2 letters!" << endl;
        }
        else if (name.length() > 15) {
            cout << "Your name cannot be more than 15 letters!" << endl;
        }
        else {
            break;
        }
    } while (true);
    user->setName(name);
    cout << "Changed name to: " << name << endl;
}

class Buy {
protected:
    int product, numberofProduct, i = 0, totalCost = 0, i1 = 0;
    char newProduct;
    int addProduct[99];
public:
    void listofProducts() {
        for (int i = 0; i < 12; i++) {
            cout<<"\t\t\t\t\t" << i + 1 << ". " << products[i]->getName() << "\t-\t" << products[i]->getPrice() << "$" << endl;
        }
    };
    void buyProducts() {
        while (true) {
            cout << "\t\t\t\t\tEnter product: ";
            cin >> product;
            if (product > 0 && product < 13) {
                cout << "\t\t\t\t\tNumber of product: ";
                cin >> numberofProduct;
                int a = products[product - 1]->getPrice() * numberofProduct;
                cout << "\t\t\t\t\ta - add new product \n\t\t\t\t\tb - pay\n";
                cin >> newProduct;

                if (newProduct == 'a') {
                    addProduct[i] = a;
                    listofProducts();
                    i++;
                }
                else if (newProduct == 'b') {
                    while (i1 < i) {
                        totalCost += addProduct[i1];
                        i1++;
                    }
                    cout << "Cost: " << totalCost + a << " $" << endl;
                    Payment();
                    break;
                }
                else {
                    cout << "\n\t\t\t\t\t     Wrong input, try again!\n" << endl;
                    listofProducts();
                }
            }
            else {
                cout << "\n\t\t\t\t\t     Wrong input, try again!\n" << endl;
            }
        }
    }
    void Payment() {
        char a;
        long p;
        cout << "a - Cash\nb - Credit Card\nc - Online Wallet\n";
        cin >> a;
        if (a == 'a') {
            cout << "Thank you!" << endl;
        }
        else if (a == 'b') {
            cout << "Enter the password: ";
            cin >> p;
            Sleep(1000);
            cout << "payment was successful\nThank you!" << endl;
        }
        else if (a == 'c') {
            cout << "send money to 123456789 bank account" << endl;
            Sleep(5000);
            cout << "payment was successful\nThank you!" << endl;
        }
    }
};

int main()
{
    User* user;
    string name;
    char command;
    Buy i1;

    do {
        cout << "Print your name" << endl;
        cin >> name;
        if (name.length() < 2) {
            cout << "Your name must be at minimum 2 letters!" << endl;
        }
        else if (name.length() > 15) {
            cout << "Your name cannot be more than 15 letters!" << endl;
        }
        else {
            break;
        }
    } while (true);

    user = new User(name);

    while (true) {
        cout << endl << endl;
        showCommands();
        cin >> command;
        if (command == '~') {
            break;
        }

        switch (command) {
        case 'a':
            getUserDetails(user);
            break;
        case 'c':
            getListOfProducts();
            break;
        case 'd':
            searchProduct();
            break;
        case 'e':
            getProductThatCostLessThan();
            break;
        case 'f':
            getProductThatCostMoreThan();
            break;
        case 'g':
            getNumberOfProducts();
            break;
        case 'h':
            changeName(user);
            break;
        case 'i':
            i1.listofProducts();
            i1.buyProducts();

        }

    }

    cout << "End of program" << endl;

    return 0;
}

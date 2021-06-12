#ifndef PRODUCTS_H
#define PRODUCTS_H

using namespace std;
#include <iostream>

class Products
{
    public:
        Products(int id = 0, string code = "", string type = "",string name = "", string description = "", double weight = 0, double price = 0);
        void Print();

        void Set_id(int id);
        void Set_bar_code(string bar_code);
        void Set_name(string name);
        void Set_type(string type);
        void Set_description(string description);
        void Set_weight(double weight);
        void Set_price(double price);

        int Get_id();
        string Get_bar_code();
        string Get_name();
        string Get_type();
        string Get_description();
        double Get_weight();
        double Get_price();

    private:
        int id;
        string bar_code;
        string type;
        string name;
        string description;
        double weight;
        double price;
};

#endif // PRODUCTS_H

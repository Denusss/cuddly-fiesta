#include "Products.h"




Products::Products(int id, string code, string type, string name, string description, double weight, double price)
{
    this->id = id;
    this->bar_code = code;
    this->type = type;
    this->name = name;
    this->description = description;
    this->weight = weight;
    this->price = price;
}

void Products::Set_type(string type)
{
    this->type = type;
}

string Products::Get_type()
{
    return type;
}

void Products::Print()
{
    cout<<endl
    <<"  Код продукту   -- "<<id <<endl
    <<"  Штрих-код      -- "<<bar_code <<endl
    <<"  Тип продукту   -- "<<type <<endl
    <<"  Назва продукту -- "<<name <<endl
    <<"  Опис продукту  -- "<<description <<endl
    <<"  Вага продукту  -- "<<weight <<endl
    <<"  Цiна за 1 кг   -- "<< price<<endl<<endl;
}

void Products::Set_id(int id)
{
    this->id = id;
}

void Products::Set_bar_code(string bar_code)
{
    this->bar_code = bar_code;
}

void Products::Set_name(string name)
{
    this->name = name;
}

void Products::Set_description(string description)
{
    this->description = description;
}

void Products::Set_weight(double weight)
{
    this->weight = weight;
}

void Products::Set_price(double price)
{
    this->price = price;
}

int Products::Get_id()
{
    return id;
}

string Products::Get_bar_code()
{
    return bar_code;
}

string Products::Get_name()
{
    return name;
}

string Products::Get_description()
{
    return description;
}

double Products::Get_weight()
{
    return weight;
}

double Products::Get_price()
{
    return price;
}

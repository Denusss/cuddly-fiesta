#include "Sale.h"

Sale::Sale(int ID, int ID_Product, int ID_Worker, string NameProduct, double weight, string Date_Sell, double Total_Sum)
{
  this->ID = ID;
    this->ID_Product = ID_Product;
    this->ID_Worker = ID_Worker;
    this->NameProduct = NameProduct;
    this->weight = weight;
    this->Date_Sell = Date_Sell;
    this->Total_Sum = Total_Sum;
}

void Sale::Print()
{
    cout<<endl
    <<"  Код продажi       -- "<<ID <<endl
    <<"  Код продавця      -- "<<ID_Worker <<endl
    <<"  Код товару        -- "<<ID_Product <<endl
    <<"  Назва товару      -- "<<NameProduct <<endl
    <<"  Продано кiлограм  -- "<<weight << " КГ"<<endl
    <<"  Дата продажi      -- "<<Date_Sell <<endl
    <<"  Сума продажi      -- "<<Total_Sum <<endl;
}

void Sale::Set_ID(int ID)
{
    this->ID = ID;
}

void Sale::Set_IDProduct(int ID_Product)
{
    this->ID_Product = ID_Product;
}

void Sale::Set_ID_Worker(int ID_Worker)
{
    this->ID_Worker = ID_Worker;
}

void Sale::Set_NameProduct(string NameProduct)
{
    this->NameProduct = NameProduct;
}

void Sale::Set_weight(double weight)
{
    this->weight = weight;
}

void Sale::Set_Date_Sell(string Date_Sell)
{
    this->Date_Sell = Date_Sell;
}

void Sale::Set_Total_Sum(double Total_Sum)
{
    this->Total_Sum = Total_Sum;
}

int Sale::Get_ID()
{
    return ID;
}

int Sale::Get_ID_Product()
{
    return ID_Product;
}

int Sale::Get_ID_Worker()
{
    return ID_Worker;
}

string Sale::Get_NameProduct()
{
    return NameProduct;
}

double Sale::Get_weight()
{
    return weight;
}

string Sale::Get_Date_Sell()
{
    return Date_Sell;
}

double Sale::Get_Total_Sum()
{
    return Total_Sum;
}

#ifndef SALE_H
#define SALE_H
using namespace std;
#include <iostream>

class Sale
{
    public:

        Sale(int ID = 0, int ID_Product = 0, int ID_Worker=0, string NameProduct = "",
                 double weight = 0, string Date_Sell = "", double Total_Sum = 0);

        void Print();

        void Set_ID ( int ID );
        void Set_IDProduct ( int ID_Product );
        void Set_ID_Worker ( int ID_Worker );
        void Set_NameProduct ( string NameProduct );
        void Set_weight ( double weight );
        void Set_Date_Sell ( string Date_Sell );
        void Set_Total_Sum ( double Total_Sum );

        int Get_ID();
        int Get_ID_Product();
        int Get_ID_Worker();
        string Get_NameProduct();
        double Get_weight();
        string Get_Date_Sell();
        double Get_Total_Sum();

    private:

        int ID;
        int ID_Product;
        int ID_Worker;
        string NameProduct;
        double weight;
        string Date_Sell;
        double Total_Sum;

};

#endif // SALE_H

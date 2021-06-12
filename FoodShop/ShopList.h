#ifndef SHOPLIST_H
#define SHOPLIST_H

#include <conio.h>
#include <ctime>
#include <fstream>
#include <list>

#include "Products.h"
#include "Worker.h"
#include "Sale.h"

class ShopList
{
    public:
        ShopList();
        virtual ~ShopList();
        //
        list<Products> & GetProducts();
        list<Worker> & GetWorkers();
        list<Sale> & GetSales();
        //
        void PrintListWorkers();
        void PrintListProducts();
        void PrintHistorySales();

        //
        void CreateWorker();
        void CreateProducts();
        void CreateSale();
        //Пошук
        list<Worker>::iterator SearchByPIB(string SearchPIB);
        list<Worker>::iterator SearchByID(int SearchID);

        list<Products>::iterator SearchByName(string SearchName);
        list<Products>::iterator SearchByCode(string SearchCode);
        //
        void DeleteWorker_By_PIB(string Delete_PIB);
        void DeleteWorker_By_ID(int Delete_ID);

        void DeleteProducts_By_Name(string Delete_Name);
        void DeleteProducts_By_Code(string Delete_Code);

        //
        void SaveAllData();

    private:
        list<Products> products;
        list<Worker> workers;
        list<Sale> sales;

        void InitAllData();
};

#endif // SHOPLIST_H

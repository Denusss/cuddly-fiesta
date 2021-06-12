#ifndef INTERFACE_H
#define INTERFACE_H

#include "ShopList.h"

class Interface
{
    public:
        void Menu();

        void PWorkers();
        void PProducts();

        void SellProducts();
        void PrintSels();

    private:
        int Action;
        ShopList Data;

};

#endif // INTERFACE_H

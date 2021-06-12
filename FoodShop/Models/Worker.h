#ifndef WORKER_H
#define WORKER_H

using namespace std;
#include <iostream>
class Worker
{
    public:
        Worker(int id = 0, string PIB="", string position = "", double salary = 0);

        void Set_id(int id);
        void Set_PIB(string PIB);
        void Set_position(string position);
        void Set_salary(double salary);

        int Get_id();
        string Get_PIB();
        string Get_position();
        double Get_salary();

        void Print();

    private:

        int id;
        string PIB;
        string position;
        double salary;
};


#endif // WORKER_H

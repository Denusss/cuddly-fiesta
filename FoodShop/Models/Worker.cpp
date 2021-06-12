#include "Worker.h"

Worker::Worker(int id, string PIB, string position, double salary)
{
    this->id = id;
    this->PIB = PIB;
    this->position = position;
    this->salary = salary;
}

void Worker::Set_id(int id)
{
    this->id = id;
}

void Worker::Set_PIB(string PIB)
{
    this->PIB = PIB;
}

void Worker::Set_position(string position)
{
    this->position = position;
}

void Worker::Set_salary(double salary)
{
    this->salary = salary;
}

int Worker::Get_id()
{
    return id;
}

string Worker::Get_PIB()
{
    return PIB;
}

string Worker::Get_position()
{
    return position;
}

double Worker::Get_salary()
{
    return salary;
}
void Worker::Print()
{
    cout<<endl
    <<"  Код      - "<<id<<endl
    <<"  Iнiцiали - "<<PIB<<endl
    <<"  Посада   - "<<position<<endl
    <<"  Зарплата - "<<salary<<endl<<endl;
}

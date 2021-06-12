#include "Interface.h"



void Interface::Menu()
{
    while(true){

        cout
        <<"___________ ПРОДУКТОВИЙ МАГАЗИН ___________"<<endl<<endl<<endl
        <<" 1  - Працiвники."<<endl
        <<" 2  - Продукти. "<<endl
        <<" 3  - Реєстрацiї продажi."<<endl
        <<" 4  - Iсторiя продаж."<<endl<<endl
        <<" 5  - Зберегти всi данi в базу даних."<<endl<<endl
        <<" 6  - Вийти."<<endl<<endl
        <<"__________________________________________"<<endl<<endl<<endl
        <<" Введiть номер пункту!    --> ";
        cin>>Action;

        switch(Action){
            case 1:{
                system("cls");
                PWorkers();
                break;}
            case 2:{
                system("cls");
                PProducts();
                break;}
            case 3:{
                system("cls");
                SellProducts();
                system("cls");
                break;}
            case 4:{
                system("cls");
                PrintSels();
                cout<<endl<<endl<<" Натиснiть клавiшу, щоб продовжити!"<<endl;
                getch();
                system("cls");
                break;}
            case 5:{
                system("cls");
                Data.SaveAllData();
                cout<<endl<<endl<<" Данi успiшно збереженi!!!"<<endl;
                cout<<endl<<endl<<" Натиснiть клавiшу, щоб продовжити!"<<endl;
                getch();
                system("cls");
                break;}

            default : {
                system("cls");
                cout<<endl<<endl<<"Програма завершила свою роботу !"<<endl<<endl;
                return;
                break;}
        }
    }
}

void Interface::PWorkers()
{
    while(true){
        cout
        <<"___________ ПРАЦIВНИКИ __________"<<endl<<endl<<endl
        <<" 1  - Переглянути данi працiвникiв."<<endl
        <<" 2  - Зареєструвати нового працiвника."<<endl
        <<" 3  - Сортувати данi працiвникiв. "<<endl
        <<" 4  - Пошук працiвника."<<endl<<endl
        <<" 5  - Видалення даних працiвника."<<endl<<endl

        <<" 6  - Повернутись в головне меню."<<endl<<endl
        <<"__________________________________"<<endl<<endl<<endl
        <<" Введiть номер пункту!    --> ";
        cin>>Action;

        switch(Action){
            case 1  :{
                system("cls");
                cout<<endl<<endl
                <<"__________ ПРАЦIВНИКИ __________"<<endl<<endl<<endl;
                Data.PrintListWorkers();
                cout
                <<"________________________________"<<endl<<endl<<endl
                <<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                getch();
                system("cls");
                break;}
            case 2  :{
                system("cls");
                cin.ignore();
                Data.CreateWorker();
                cout<<endl<<" НОВI ДАНI ПРАЦIВНИКА УСПIШНО СТВОРЕНО !!!";
                cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                getch();
                system("cls");

                break;}
            case 3  :{
                bool work_sort =  true;
                while(work_sort){
                system("cls");
                cout<<endl<<endl
                <<"_____ СОРТУВАННЯ ДАНИХ ПРАЦIВНИКА _____"<<endl<<endl<<endl
                <<" 1 Сортувати по коду."<<endl
                <<" 2 Сортувати по iнiцiалах."<<endl<<endl
                <<" 3 Вийти."<<endl
                <<"_______________________________________"<<endl<<endl<<endl
                <<" Введiть номер пункту!    --> ";
                cin>>Action;

                switch(Action){
                    case 1: {
                        Data.GetWorkers().sort([](Worker &ob1, Worker &ob2){
                                return ob1.Get_id() < ob2.Get_id();
                                });
                        cout<<endl<<" ДАНI БУЛИ ПОСОРТОВАНI ПО КОДУ !!!";
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        break;}
                    case 2: {
                        Data.GetWorkers().sort([](Worker &ob1, Worker &ob2){
                                return ob1.Get_PIB() < ob2.Get_PIB();
                                });
                        cout<<endl<<" ДАНI БУЛИ ПОСОРТОВАНI ПО IНIЦIАЛАХ !!!";
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        break;}
                    default: {
                        work_sort = false;
                        system("cls");
                        break;}

                }
                }

                break;}
            case 4  :{
                bool work_search =  true;
                while(work_search){
                system("cls");
                cout<<endl<<endl
                <<"_____ ПОШУК ДАНИХ ПРАЦIВНИКА _____"<<endl<<endl<<endl
                <<" 1 Пошук по коду."<<endl
                <<" 2 Пошук по iнiцiалах."<<endl<<endl
                <<" 3 Вийти."<<endl
                <<"__________________________________"<<endl<<endl<<endl
                <<" Введiть номер пункту!    --> ";
                cin>>Action;
                switch(Action){
                    case 1:{
                        system("cls");
                        int search_ID;
                        cout<<endl<<" Введiть код > ";
                        cin>>search_ID;
                        Worker it = *Data.SearchByID(search_ID);
                        if(it.Get_id() == search_ID){
                            it.Print();
                        }
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        system("cls");
                        break;}
                    case 2:{
                        system("cls");
                        cin.ignore();
                        string search_PIB;
                        cout<<endl<<" Введiть iнiцiали > ";
                        getline (cin, search_PIB);
                        Worker it = *Data.SearchByPIB(search_PIB);
                        if(it.Get_PIB() == search_PIB){
                            it.Print();
                        }
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        system("cls");
                        break;}
                    default :{
                        work_search = false;
                        system("cls");
                        break;}
                }
                }
                system("cls");
                break;}
            case 5  :{
                bool work_delete =  true;
                while(work_delete){
                system("cls");
                cout<<endl<<endl
                <<"_____ ВИДАЛЕННЯ ДАНИХ ПРАЦIВНИКА _____"<<endl<<endl<<endl
                <<""<<endl<<endl
                <<" 1 Видалення по коду."<<endl
                <<" 2 Видалення по iнiцiалах."<<endl
                <<" 3 Вийти."<<endl
                <<"______________________________________"<<endl<<endl<<endl
                <<" Введiть номер пункту!    --> ";
                cin>>Action;
                switch(Action){
                    case 1:{
                        int delete_ID;
                        cout<<" Введiть код > ";
                        cin>>delete_ID;
                        Data.DeleteWorker_By_ID(delete_ID);
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        system("cls");
                        break;}
                    case 2:{
                        cin.ignore();
                        string delete_PIB;
                        cout<<" Введiть iнiцiали > ";
                        getline (cin, delete_PIB);
                        Data.DeleteWorker_By_PIB(delete_PIB);
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        system("cls");
                        break;}
                    default :{
                        work_delete = false;
                        system("cls");
                        break;}
                }
                }
                system("cls");
                break;}
            default :{
                system("cls");
                return;
                break;}
        }
    }
}

void Interface::PProducts()
{
    while(true){
        cout
        <<"_______________ ПРОДУКТИ  _______________"<<endl<<endl<<endl
        <<" 1  - Переглянути продукти."<<endl
        <<" 2  - Зареєструвати новий продукт."<<endl
        <<" 3  - Сортувати продукти. "<<endl
        <<" 4  - Пошук продуктiв."<<endl<<endl
        <<" 5  - Видалення продукту."<<endl<<endl

        <<" 6  - Повернутись в головне меню."<<endl<<endl
        <<"________________________________________"<<endl<<endl<<endl
        <<" Введiть номер пункту!    --> ";
        cin>>Action;

        switch(Action){
            case 1  :{
                system("cls");
                cout<<endl<<endl
                <<"__________ ПРОДУКТИ В НАЯВНОСТI __________"<<endl<<endl<<endl;
                Data.PrintListProducts();
                cout
                <<"_________________________________________"<<endl<<endl<<endl
                <<endl<<endl<<"Натиснiть клавiшу, щоб повернутися назад"<<endl;
                getch();
                system("cls");
                break;}
            case 2  :{
                system("cls");
                cin.ignore();
                Data.CreateProducts();
                cout<<endl<<"НОВI ДАНI ПРОДУКТУ УСПIШНО СТВОРЕНО !!!";
                cout<<endl<<endl<<"Натиснiть клавiшу, щоб повернутися назад"<<endl;
                getch();
                system("cls");

                break;}
            case 3  :{
                bool work_sort =  true;
                while(work_sort){
                system("cls");
                cout<<endl<<endl
                <<"_____ СОРТУВАННЯ ПРОДУКТIВ МАГАЗИНУ     _____"<<endl<<endl<<endl
                <<" 1 Сортувати по штрих-коду."<<endl
                <<" 2 Сортувати по назвi."<<endl<<endl
                <<" 3 Вийти."<<endl
                <<"_____________________________________________"<<endl<<endl<<endl
                <<" Введiть номер пункту!    --> ";
                cin>>Action;

                switch(Action){
                    case 1: {
                        Data.GetProducts().sort([](Products &ob1, Products &ob2){
                                return ob1.Get_bar_code() < ob2.Get_bar_code();
                                });
                        cout<<endl<<" ДАНI БУЛИ ПОСОРТОВАНI ПО ШТРИХ-КОДУ !!!";
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        break;}
                    case 2: {
                        Data.GetProducts().sort([](Products &ob1, Products &ob2){
                                return ob1.Get_name() < ob2.Get_name();
                                });
                        cout<<endl<<" ДАНI БУЛИ ПОСОРТОВАНI ПО НАЗВI !!!";
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        break;}
                    default: {
                        work_sort = false;
                        system("cls");
                        break;}

                }
                }

                break;}
            case 4  :{
                bool work_search =  true;
                while(work_search){
                system("cls");
                cout<<endl<<endl
                <<"_____     ПОШУК ПРОДУКТIВ В МАГАЗИНI     _____"<<endl<<endl<<endl
                <<" 1 Пошук по штрих-коду."<<endl
                <<" 2 Пошук по назвi."<<endl<<endl
                <<" 3 Вийти."<<endl
                <<"_____________________________________________"<<endl<<endl<<endl
                <<" Введiть номер пункту!    --> ";
                cin>>Action;
                switch(Action){
                    case 1:{
                        system("cls"); cin.ignore();
                        string search_Code;
                        cout<<endl<<" Введiть штрих-код > ";
                        getline (cin, search_Code);
                        Products it = *Data.SearchByCode(search_Code);
                        if(it.Get_bar_code() == search_Code){
                            it.Print();
                        }
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        system("cls");
                        break;}
                    case 2:{
                        system("cls");
                        cin.ignore();
                        string search_Name;
                        cout<<endl<<" Введiть назву > ";
                        getline (cin, search_Name);
                        Products it = *Data.SearchByName(search_Name);
                        if(it.Get_name() == search_Name){
                            it.Print();
                        }
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        system("cls");
                        break;}
                    default :{
                        work_search = false;
                        system("cls");
                        break;}
                }
                }
                system("cls");
                break;}
            case 5  :{
                bool work_delete =  true;
                while(work_delete){
                system("cls");
                cout<<endl<<endl
                <<"_____   ВИДАЛЕННЯ ПРОДУКТIВ З МАГАЗИНУ   _____"<<endl<<endl<<endl
                <<""<<endl<<endl
                <<" 1 Видалення по штрих-коду."<<endl
                <<" 2 Видалення по назвi."<<endl
                <<" 3 Вийти."<<endl
                <<"_____________________________________________"<<endl<<endl<<endl
                <<" Введiть номер пункту!    --> ";
                cin>>Action;
                switch(Action){
                    case 1:{
                        string search_Code; cin.ignore();
                        cout<<" Введiть штрих-код > ";
                        getline (cin, search_Code);
                        Data.DeleteProducts_By_Code(search_Code);
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        system("cls");
                        break;}
                    case 2:{
                        cin.ignore();
                        string delete_name;
                        cout<<" Введiть назву > ";
                        getline (cin, delete_name);
                        Data.DeleteProducts_By_Name(delete_name);
                        cout<<endl<<endl<<" Натиснiть клавiшу, щоб повернутися назад"<<endl;
                        getch();
                        system("cls");
                        break;}
                    default :{
                        work_delete = false;
                        system("cls");
                        break;}
                }
                }
                system("cls");
                break;}
            default :{
                system("cls");
                return;
                break;}
        }
    }
}

void Interface::SellProducts()
{
    Data.CreateSale();
}

void Interface::PrintSels()
{
    Data.PrintHistorySales();
}


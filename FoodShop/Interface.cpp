#include "Interface.h"



void Interface::Menu()
{
    while(true){

        cout
        <<"___________ ����������� ������� ___________"<<endl<<endl<<endl
        <<" 1  - ����i�����."<<endl
        <<" 2  - ��������. "<<endl
        <<" 3  - �������i� ������i."<<endl
        <<" 4  - I����i� ������."<<endl<<endl
        <<" 5  - �������� ��i ���i � ���� �����."<<endl<<endl
        <<" 6  - �����."<<endl<<endl
        <<"__________________________________________"<<endl<<endl<<endl
        <<" ����i�� ����� ������!    --> ";
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
                cout<<endl<<endl<<" ������i�� ����i��, ��� ����������!"<<endl;
                getch();
                system("cls");
                break;}
            case 5:{
                system("cls");
                Data.SaveAllData();
                cout<<endl<<endl<<" ���i ���i��� ��������i!!!"<<endl;
                cout<<endl<<endl<<" ������i�� ����i��, ��� ����������!"<<endl;
                getch();
                system("cls");
                break;}

            default : {
                system("cls");
                cout<<endl<<endl<<"�������� ��������� ���� ������ !"<<endl<<endl;
                return;
                break;}
        }
    }
}

void Interface::PWorkers()
{
    while(true){
        cout
        <<"___________ ����I����� __________"<<endl<<endl<<endl
        <<" 1  - ����������� ���i ����i����i�."<<endl
        <<" 2  - ������������ ������ ����i�����."<<endl
        <<" 3  - ��������� ���i ����i����i�. "<<endl
        <<" 4  - ����� ����i�����."<<endl<<endl
        <<" 5  - ��������� ����� ����i�����."<<endl<<endl

        <<" 6  - ����������� � ������� ����."<<endl<<endl
        <<"__________________________________"<<endl<<endl<<endl
        <<" ����i�� ����� ������!    --> ";
        cin>>Action;

        switch(Action){
            case 1  :{
                system("cls");
                cout<<endl<<endl
                <<"__________ ����I����� __________"<<endl<<endl<<endl;
                Data.PrintListWorkers();
                cout
                <<"________________________________"<<endl<<endl<<endl
                <<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
                getch();
                system("cls");
                break;}
            case 2  :{
                system("cls");
                cin.ignore();
                Data.CreateWorker();
                cout<<endl<<" ���I ���I ����I����� ���I��� �������� !!!";
                cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
                getch();
                system("cls");

                break;}
            case 3  :{
                bool work_sort =  true;
                while(work_sort){
                system("cls");
                cout<<endl<<endl
                <<"_____ ���������� ����� ����I����� _____"<<endl<<endl<<endl
                <<" 1 ��������� �� ����."<<endl
                <<" 2 ��������� �� i�i�i����."<<endl<<endl
                <<" 3 �����."<<endl
                <<"_______________________________________"<<endl<<endl<<endl
                <<" ����i�� ����� ������!    --> ";
                cin>>Action;

                switch(Action){
                    case 1: {
                        Data.GetWorkers().sort([](Worker &ob1, Worker &ob2){
                                return ob1.Get_id() < ob2.Get_id();
                                });
                        cout<<endl<<" ���I ���� ����������I �� ���� !!!";
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
                        getch();
                        break;}
                    case 2: {
                        Data.GetWorkers().sort([](Worker &ob1, Worker &ob2){
                                return ob1.Get_PIB() < ob2.Get_PIB();
                                });
                        cout<<endl<<" ���I ���� ����������I �� I�I�I���� !!!";
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
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
                <<"_____ ����� ����� ����I����� _____"<<endl<<endl<<endl
                <<" 1 ����� �� ����."<<endl
                <<" 2 ����� �� i�i�i����."<<endl<<endl
                <<" 3 �����."<<endl
                <<"__________________________________"<<endl<<endl<<endl
                <<" ����i�� ����� ������!    --> ";
                cin>>Action;
                switch(Action){
                    case 1:{
                        system("cls");
                        int search_ID;
                        cout<<endl<<" ����i�� ��� > ";
                        cin>>search_ID;
                        Worker it = *Data.SearchByID(search_ID);
                        if(it.Get_id() == search_ID){
                            it.Print();
                        }
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
                        getch();
                        system("cls");
                        break;}
                    case 2:{
                        system("cls");
                        cin.ignore();
                        string search_PIB;
                        cout<<endl<<" ����i�� i�i�i��� > ";
                        getline (cin, search_PIB);
                        Worker it = *Data.SearchByPIB(search_PIB);
                        if(it.Get_PIB() == search_PIB){
                            it.Print();
                        }
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
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
                <<"_____ ��������� ����� ����I����� _____"<<endl<<endl<<endl
                <<""<<endl<<endl
                <<" 1 ��������� �� ����."<<endl
                <<" 2 ��������� �� i�i�i����."<<endl
                <<" 3 �����."<<endl
                <<"______________________________________"<<endl<<endl<<endl
                <<" ����i�� ����� ������!    --> ";
                cin>>Action;
                switch(Action){
                    case 1:{
                        int delete_ID;
                        cout<<" ����i�� ��� > ";
                        cin>>delete_ID;
                        Data.DeleteWorker_By_ID(delete_ID);
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
                        getch();
                        system("cls");
                        break;}
                    case 2:{
                        cin.ignore();
                        string delete_PIB;
                        cout<<" ����i�� i�i�i��� > ";
                        getline (cin, delete_PIB);
                        Data.DeleteWorker_By_PIB(delete_PIB);
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
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
        <<"_______________ ��������  _______________"<<endl<<endl<<endl
        <<" 1  - ����������� ��������."<<endl
        <<" 2  - ������������ ����� �������."<<endl
        <<" 3  - ��������� ��������. "<<endl
        <<" 4  - ����� �������i�."<<endl<<endl
        <<" 5  - ��������� ��������."<<endl<<endl

        <<" 6  - ����������� � ������� ����."<<endl<<endl
        <<"________________________________________"<<endl<<endl<<endl
        <<" ����i�� ����� ������!    --> ";
        cin>>Action;

        switch(Action){
            case 1  :{
                system("cls");
                cout<<endl<<endl
                <<"__________ �������� � ��������I __________"<<endl<<endl<<endl;
                Data.PrintListProducts();
                cout
                <<"_________________________________________"<<endl<<endl<<endl
                <<endl<<endl<<"������i�� ����i��, ��� ����������� �����"<<endl;
                getch();
                system("cls");
                break;}
            case 2  :{
                system("cls");
                cin.ignore();
                Data.CreateProducts();
                cout<<endl<<"���I ���I �������� ���I��� �������� !!!";
                cout<<endl<<endl<<"������i�� ����i��, ��� ����������� �����"<<endl;
                getch();
                system("cls");

                break;}
            case 3  :{
                bool work_sort =  true;
                while(work_sort){
                system("cls");
                cout<<endl<<endl
                <<"_____ ���������� �������I� ��������     _____"<<endl<<endl<<endl
                <<" 1 ��������� �� �����-����."<<endl
                <<" 2 ��������� �� ����i."<<endl<<endl
                <<" 3 �����."<<endl
                <<"_____________________________________________"<<endl<<endl<<endl
                <<" ����i�� ����� ������!    --> ";
                cin>>Action;

                switch(Action){
                    case 1: {
                        Data.GetProducts().sort([](Products &ob1, Products &ob2){
                                return ob1.Get_bar_code() < ob2.Get_bar_code();
                                });
                        cout<<endl<<" ���I ���� ����������I �� �����-���� !!!";
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
                        getch();
                        break;}
                    case 2: {
                        Data.GetProducts().sort([](Products &ob1, Products &ob2){
                                return ob1.Get_name() < ob2.Get_name();
                                });
                        cout<<endl<<" ���I ���� ����������I �� ����I !!!";
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
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
                <<"_____     ����� �������I� � �������I     _____"<<endl<<endl<<endl
                <<" 1 ����� �� �����-����."<<endl
                <<" 2 ����� �� ����i."<<endl<<endl
                <<" 3 �����."<<endl
                <<"_____________________________________________"<<endl<<endl<<endl
                <<" ����i�� ����� ������!    --> ";
                cin>>Action;
                switch(Action){
                    case 1:{
                        system("cls"); cin.ignore();
                        string search_Code;
                        cout<<endl<<" ����i�� �����-��� > ";
                        getline (cin, search_Code);
                        Products it = *Data.SearchByCode(search_Code);
                        if(it.Get_bar_code() == search_Code){
                            it.Print();
                        }
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
                        getch();
                        system("cls");
                        break;}
                    case 2:{
                        system("cls");
                        cin.ignore();
                        string search_Name;
                        cout<<endl<<" ����i�� ����� > ";
                        getline (cin, search_Name);
                        Products it = *Data.SearchByName(search_Name);
                        if(it.Get_name() == search_Name){
                            it.Print();
                        }
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
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
                <<"_____   ��������� �������I� � ��������   _____"<<endl<<endl<<endl
                <<""<<endl<<endl
                <<" 1 ��������� �� �����-����."<<endl
                <<" 2 ��������� �� ����i."<<endl
                <<" 3 �����."<<endl
                <<"_____________________________________________"<<endl<<endl<<endl
                <<" ����i�� ����� ������!    --> ";
                cin>>Action;
                switch(Action){
                    case 1:{
                        string search_Code; cin.ignore();
                        cout<<" ����i�� �����-��� > ";
                        getline (cin, search_Code);
                        Data.DeleteProducts_By_Code(search_Code);
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
                        getch();
                        system("cls");
                        break;}
                    case 2:{
                        cin.ignore();
                        string delete_name;
                        cout<<" ����i�� ����� > ";
                        getline (cin, delete_name);
                        Data.DeleteProducts_By_Name(delete_name);
                        cout<<endl<<endl<<" ������i�� ����i��, ��� ����������� �����"<<endl;
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


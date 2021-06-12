#include "ShopList.h"

ShopList::ShopList()
{
    InitAllData();
}

ShopList::~ShopList()
{
    products.clear();
    workers.clear();
    sales.clear();
}
        //
        list<Products> & ShopList::GetProducts(){
            return *& products;
        }
        list<Worker> & ShopList::GetWorkers(){
            return *& workers;
        }
        list<Sale> & ShopList::GetSales(){
            return *& sales;
        }
        //
        void ShopList::PrintListWorkers(){
            if(workers.empty())
            {
                    std::cout<<" ������ ����i����i� ������i� !!!"<<std::endl;
            }
            else{
                for(auto it = workers.begin(); it != workers.end(); it++){
                    Worker work = *it;
                    work.Print();
                }
            }
        }
        void ShopList::PrintListProducts(){
            if(products.empty())
            {
                    std::cout<<" ������ �������i� ������i� !!!"<<std::endl;
            }
            else{
                for(auto it = products.begin(); it != products.end(); it++){
                    Products product = *it;
                    product.Print();
                }
            }
        }
        void ShopList::PrintHistorySales(){
            if(sales.empty())
            {
                    std::cout<<" ������ ������ ������i� !!!"<<std::endl;
            }
            else{
                for(auto it = sales.begin(); it != sales.end(); it++){
                    Sale sale = *it;
                    sale.Print();
                }
            }
        }

        //
        void ShopList::CreateWorker(){
            cout<<" �������i� ����i����� ������������ ��������"<<endl<<endl;
            string sTmp; double dTmp;
            Worker newWoorker;
            newWoorker.Set_id(workers.size()+1);
            cout<<" ����i�� i�i�i��� ������ ����i�����"<<endl<<" >";

            getline(cin, sTmp);
            newWoorker.Set_PIB(sTmp);
            cout<<" ����i�� ������ ����i�����"<<endl<<" >";
            getline(cin, sTmp);
            newWoorker.Set_position(sTmp);
            cout<<" ����i�� �������� ����i�����"<<endl<<" >";
            cin>>dTmp;
            newWoorker.Set_salary(dTmp);
            workers.push_back(newWoorker);
        }
        void ShopList::CreateProducts(){
            Products product;
            cout<<" "<<endl<<endl;
            string sTmp; double dTmp;
            product.Set_id(products.size()+1);
            cout<<" ����i�� ����� ��� ��������"<<endl<<" >";
            getline(cin, sTmp);
            product.Set_bar_code(sTmp);
            cout<<" ����i�� ��� ��������"<<endl<<" >";
            getline(cin, sTmp);
            product.Set_type(sTmp);
            cout<<" ����i�� ����� ��������"<<endl<<" >";
            getline(cin, sTmp);
            product.Set_name(sTmp);
            cout<<" ����i�� ���� ��������"<<endl<<" >";
            getline(cin, sTmp);
            product.Set_description(sTmp);
            cout<<" ����i�� �i���i��� �i������ �������i� � ��������i (double)"<<endl<<" >";
            cin>>dTmp;
            product.Set_weight(dTmp);
            cout<<" ����i�� �i�� �� ���� �i������ (double)"<<endl<<" >";
            cin>>dTmp;
            product.Set_price(dTmp);
            products.push_back(product);
        }
        void ShopList::CreateSale(){
            double price_ = 0;
            double weight, id, Action, type;
            string code;
            Sale sale;
            Products product;

            sale.Set_ID(sales.size()+1);
            cout<<" �������i� ������i"<<endl<<endl;
            PrintListProducts();
            while(true){
                cout<<endl<<endl<<" ����i�� �����-��� ��������"<<endl<<" > ";
                cin>>code;
                auto it = SearchByCode(code);
                product = *it;
                if(code == product.Get_bar_code()){
                    if(product.Get_weight() > 0){
                    sale.Set_IDProduct(product.Get_id());
                    sale.Set_NameProduct(product.Get_name());
                    price_ = (product.Get_price());
                    weight = product.Get_weight();
                    id = Action;
                    break;
                    }
                    else {
                        cout<<endl
                        <<" ������ �������� ���� � ��������i!"<<endl<<endl
                        <<" ��������� �� ���"<<endl;
                        continue;
                    }
                }
                else{
                    cout<<endl
                        <<" ������ �������� ����!"<<endl<<endl
                        <<" ��������� �� ���"<<endl;
                        continue;
                }

            }
    double total;
    while(true){
        double temp_double;
        cin.ignore();
        cout<<"����i�� �i���i��� �i������ �������� ������� ("<<weight<<" - ��������)"<<endl<<" -->";
        cin>>temp_double;
        if(temp_double > weight){
            cout<<"�� ����� ����������� ����, ����i�� �� ���!  ("<<weight<<" - ��������)"<<endl;
        }
        else{
            total = price_*temp_double;
            sale.Set_weight(temp_double);
            sale.Set_Total_Sum(total);
            product.Set_weight(product.Get_weight() - temp_double);
            auto it = SearchByCode(product.Get_bar_code());
            products.insert(it, product);
            products.erase(it);
            break;
        }

    }
    system("cls");

    cout<<"   ����i�� ����i�����, ���� ������"<<endl<<endl;

    PrintListWorkers();
                while(true){
                    cout<<endl<<"����i�� ��� ����i�����"<<endl<<" --> ";
                    cin>>Action;
                    if(Action > workers.size() || Action <= 0){
                        cout<<endl<<"�� ����� ���i���� ��� ����i�����!"<<endl;
                    }
                    else {
                        id = Action;
                        sale.Set_ID_Worker(Action);
                        break;
                    }
                }
    system("cls");

    time_t now = time(0);
    string dt = ctime(&now);
    dt.erase(24,1);
    sale.Set_Date_Sell(dt);
    cout<<endl<<"���������� ��������!"<<endl;
    sale.Print();
    sales.push_back(sale);

    cout<<endl<<endl<<"������i�� ���� ����i��, ��� ����������� �����"<<endl;
    getch();
    system("cls");

        }
        //�����
        list<Worker>::iterator ShopList::SearchByPIB(string SearchPIB){
            auto null = workers.begin();
            if(!workers.empty()){
                for(auto it = workers.begin(); it != workers.end(); it++){
                    Worker searchWorker = *it;
                    if(searchWorker.Get_PIB() == SearchPIB){
                        return it;
                    }
                }
                cout<<" �� �������� ���i ����i����� = "<<SearchPIB<<endl;
                return null;
            }
            else {
                cout<<" ���i �i�����i!"<<endl;
                return null;
            }
        }
        list<Worker>::iterator ShopList::SearchByID(int SearchID){
            auto null = workers.begin();
            if(!workers.empty()){
                for(auto it = workers.begin(); it != workers.end(); it++){
                    Worker searchWorker = *it;
                    if(searchWorker.Get_id() == SearchID){
                        return it;
                    }
                }
                cout<<" �� �������� ���i ����i����� = "<<SearchID<<endl;
                return null;
            }
            else {
                cout<<" ���i �i�����i!"<<endl;
                return null;
            }
        }

        list<Products>::iterator ShopList::SearchByName(string SearchName){
            auto null = products.begin();
            if(!products.empty()){
                for(auto it = products.begin(); it != products.end(); it++){
                    Products searchProducts = *it;
                    if(searchProducts.Get_name() == SearchName){
                        return it;
                    }
                }
                cout<<" �� �������� ���i ������ = "<<SearchName<<endl;
                return null;
            }
            else {
                cout<<" ���i �i�����i!"<<endl;
                return null;
            }
        }
        list<Products>::iterator ShopList::SearchByCode(string SearchCode){
            auto null = products.begin();
            if(!products.empty()){
                for(auto it = products.begin(); it != products.end(); it++){
                    Products searchProducts = *it;
                    if(searchProducts.Get_bar_code() == SearchCode){
                        return it;
                    }
                }
                cout<<" �� �������� ���i ������ = "<<SearchCode<<endl;
                return null;
            }
            else {
                cout<<" ���i �i�����i!"<<endl;
                return null;
            }
        }
        //
        void ShopList::DeleteWorker_By_PIB(string Delete_PIB){
            auto it = SearchByPIB(Delete_PIB);
            Worker deleteWorker = *it;
            if(deleteWorker.Get_PIB() != Delete_PIB){
                cout<<endl<<" ��������� �� �������!"<<endl;
            }
            else {
                workers.erase(it);
                cout<<endl<<" ������� ���i��� ���������!"<<endl;
            }

        }
        void ShopList::DeleteWorker_By_ID(int Delete_ID){
            auto it = SearchByID(Delete_ID);
            Worker deleteWorker = *it;
            if(deleteWorker.Get_id() != Delete_ID){
                cout<<endl<<" ��������� �� �������!"<<endl;
            }
            else {
                workers.erase(it);
                cout<<endl<<" ������� ���i��� ���������!"<<endl;
            }
        }

        void ShopList::DeleteProducts_By_Name(string Delete_Name){
            auto it = SearchByName(Delete_Name);
            Products Delete_products = *it;
            if(Delete_products.Get_name() != Delete_Name){
                cout<<endl<<" ��������� �� �������!"<<endl;
            }
            else {
                products.erase(it);
                cout<<endl<<" ������� ���i��� ���������!"<<endl;
            }

        }
        void ShopList::DeleteProducts_By_Code(string Delete_Code){
            auto it = SearchByCode(Delete_Code);
            Products Delete_products = *it;
            if(Delete_products.Get_bar_code() != Delete_Code){
                cout<<endl<<" ��������� �� �������!"<<endl;
            }
            else {
                products.erase(it);
                cout<<endl<<" ������� ���i��� ���������!"<<endl;
            }
            }

            //
        void ShopList::SaveAllData(){
            fstream file; bool next = false;
            Worker worker; Sale sale; Products product;
            file.open("FileBase\\Worker.txt", fstream::out);
            if(!file.is_open()){
                cout<<"���� FileBase\\Worker.txt �� ��������!"<<endl;
            }
            else{


            //���������
            for(auto it = workers.begin(); it!=workers.end(); it++){
                worker = *it;
                if(next == true){file <<endl;}
                file <<  worker.Get_id();
                file <<endl <<  worker.Get_PIB();
                file <<endl <<  worker.Get_position();
                file <<endl <<  worker.Get_salary();
                next = true;
                }
            }

            next = false;
            file.close();
            file.open("FileBase\\Sales.txt", fstream::out);
            if(!file.is_open()){
                cout<<"���� FileBase\\Sales.txt �� ��������!"<<endl;
            }
            else{
                for(auto it = sales.begin(); it!=sales.end(); it++){
                    sale = *it;
                    if(next == true){file <<endl;}
                    file <<  sale.Get_ID();
                    file <<endl <<  sale.Get_ID_Worker();
                    file <<endl <<  sale.Get_ID_Product();
                    file <<endl <<  sale.Get_NameProduct();
                    file <<endl <<  sale.Get_weight();
                    file <<endl <<  sale.Get_Date_Sell();
                    file <<endl <<  sale.Get_Total_Sum();
                    next = true;
                    }
            }
            file.close();
            next = false;
            file.close();
            file.open("FileBase\\Products.txt", fstream::out);
            if(!file.is_open()){
                cout<<"���� FileBase\\Products.txt �� ��������!"<<endl;
            }
            else{
                for(auto it = products.begin(); it!=products.end(); it++){
                    product = *it;
                    if(next == true){file <<endl;}
                    file <<  product.Get_id();
                    file <<endl <<  product.Get_bar_code();
                    file <<endl <<  product.Get_type();
                    file <<endl <<  product.Get_name();
                    file <<endl <<  product.Get_description();
                    file <<endl <<  product.Get_weight();
                    file <<endl <<  product.Get_price();
                    next = true;
                    }
            }
            file.close();

        }
        void ShopList::InitAllData(){

            string temp_string;
            double temp_double = 0;
            int temp_int = 0;

            fstream file;

            file.open("FileBase\\Sales.txt", fstream::in);
            if(!file.is_open()){
                cout<<"���� [FileBase\\Sales.txt] �� ��������!"<<std::endl;
            }
            else{
                Sale sale;

                while(!file.eof()){

                    file >> temp_int;
                    sale.Set_ID(temp_int);

                    file >> temp_int;
                    sale.Set_ID_Worker(temp_int);
                    file >> temp_int;
                    sale.Set_IDProduct(temp_int);
file.ignore();
                    getline(file, temp_string);
                    sale.Set_NameProduct(temp_string);

                    file >> temp_double;
                    sale.Set_weight(temp_double);
file.ignore();
                    getline(file, temp_string);
                    sale.Set_Date_Sell(temp_string);

                    file >> temp_double;

                    sale.Set_Total_Sum(temp_double);

                    sales.push_back(sale);
                }
                file.close();
            }

            file.open("FileBase\\Products.txt", fstream::in);
            if(!file.is_open()){
                cout<<"���� [FileBase\\Products.txt] �� ��������!"<<std::endl;
            }
            else{
                Products product;

                while(!file.eof()){
                    file >> temp_int; file.ignore();
                    product.Set_id(temp_int);

                    getline(file, temp_string);
                    product.Set_bar_code(temp_string);

                    getline(file, temp_string);
                    product.Set_type(temp_string);

                    getline(file, temp_string);
                    product.Set_name(temp_string);

                    getline(file, temp_string);
                    product.Set_description(temp_string);

                    file >> temp_double;
                    product.Set_weight(temp_double);
                    file >> temp_double;
                    product.Set_price(temp_double);

                    products.push_back(product);
                }
                file.close();
            }


        file.open("FileBase\\Worker.txt", fstream::in);
        if(!file.is_open()){
            cout<<"���� [FileBase\\Worker.txt] �� ��������!"<<std::endl;
        }
        else{
            Worker worker;

            while(!file.eof()){
                file >> temp_int; file.ignore();
                worker.Set_id(temp_int);

                getline(file, temp_string);
                worker.Set_PIB(temp_string);
                getline(file, temp_string);
                worker.Set_position(temp_string);

                file >> temp_double;
                worker.Set_salary(temp_double);

                workers.push_back(worker);
            }
            file.close();
        }
    }

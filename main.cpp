#include<bits/stdc++.h>
using namespace std;
int ids=0;
class Stock{

    int stock_id,price,quantity;
    string name;
    public:
    Stock* next;
    Stock(string name,int price,int quantity)
    {
        this->stock_id=ids++;
        this->name=name;
        this->price=price;
        this->quantity=quantity;
        this->next=NULL;
    }
    int get_stock_price()
    {
        return this->price;
    }
    int get_stock_quantity(){
        return this->quantity;
    }
    string get_stock_name()
    {
        return this->name;
    }
    int get_stock_id()
    {
        return this->stock_id;
    }
    bool buy_stock()
    {
        this->quantity-=1;
        return true;
    }
    bool sell_stock()
    {
        this->quantity+=1;
        return true;
    }
    void display_stock()
    {
        cout<<this->stock_id<<"\t\t";
        cout<<this->name<<"\t\t";
        cout<<this->price<<"\t\t";
        cout<<this->quantity<<"\n";
    }
};
Stock *head;

Stock* get_stock(int stock_id)
{
    Stock *temp=head;
    while(temp!=NULL)
    {
        if(temp->get_stock_id()==stock_id)
            return temp;
        temp=temp->next;
    }
}

class Person{
    int person_id,money;
    vector<Stock>stocks;
    string name;
    public:
    Person()
    {
        ;
    }
    void intialize(int money,string name){
        this->person_id=0;
        this->money=money;
        this->name=name;
        this->stocks.clear();
    }

    string get_user_name()
    {
        return this->name;
    }
    vector<Stock> get_user_stocks()
    {
        return this->stocks;
    }
    int get_remaining_money()
    {
        return this->money;
    }
    void set_name(string name)
    {
        this->name=name;
    }
    void set_money(int money)
    {
        this->money=money;
    }

    bool buy_this_stock(int stock_id){
        Stock *stock=get_stock(stock_id);
        int price=stock->get_stock_price();
        if(this->money<price)
        {cout<<"Couldnt\n";return false;}

        bool bought=stock->buy_stock();
        if(bought)
        {
            stocks.push_back(*stock);
            this->money-=price;
        }
        else 
        return false;
    }

    bool sell_this_stock(int stock_id)
    {
        Stock *stock=get_stock(stock_id);
        if(this->owns_this_stock(*stock)==false)
        return false;

        bool sold= stock->sell_stock();
        if(sold)
        {
            remove_stock(*stock);
            this->money+=stock->get_stock_price();
            return true;
        }
        return false;
    }

    bool owns_this_stock(Stock stock)
    {
        // int index= binary_search(stocks.begin(),stocks.end(),stock);
        // cout<<index;
        // return index;
        return 1;
    }
    void remove_stock(Stock stock)
    {
        cout<<"REmoved";
    }
    void display_user_details()
    {
        cout<<"UserName: "<<this->name;
        cout<<"\nMoney Left: "<<this->money;
        cout<<"\nPortfolio\n";
        cout<<"StockId\t\t\tStockName\t\t\tStockPrice\t\t\tStockQuantity\n";
        for(auto stock:this->stocks)
        stock.display_stock();
    }

};

Person p;



void show_stocks()
{
    Stock *temp=head;
    while(temp!=NULL)
    {
        temp->display_stock();
        cout<<"\n\n";
        temp=temp->next;
    }
}
void show_menu()
{
    while(1)
    {
        int choice;
        cout<<"Enter the option\n1.Show User Details\n2.Show Stocks\n3.Buy a Stock\n4.Sell a Stock\n0.Exit\n\n";
        cin>>choice;
        switch(choice)
        {
            case 1:p.display_user_details();break;
            case 2:show_stocks();break;
            case 3:{
                int stock_id;
                cout<<"Enter id of the stock to buy : ";
                cin>>stock_id;
                p.buy_this_stock(stock_id);
                break;
            }
            case 4:{
                int stock_id;
                cout<<"Enter id of the stock to sell : ";
                cin>>stock_id;
                p.sell_this_stock(stock_id);
                break;
            }
            case 0:exit(0);
            default:cout<<"Enter a valid option";
        }
    }
}


void decide_user()
{
    int login;
    cout<<"Choose a option\n1.Create new user\n2.Login to exisitng user\n\n";
    cin>>login;
    switch(login)
    {
        case 1:{
            string name;
            cout<<"Enter the user_name\n";
            cin>>name;
            int money;
            cout<<"\nEnter the amount of money with the user\n";
            cin>>money;
            p.intialize(money,name);
            break;
        }
        case 2:{
            p.intialize(1000,"Demo");
            break;
        }
        default:cout<<"Enter a valid option\n";
    }
}
int main()
{
    Stock *stock1=new Stock("stock1",1000,100);
    Stock *stock2=new Stock("stock2",200,40);
    Stock *stock3=new Stock("stock3",13200,20);
    Stock *stock4=new Stock("stock4",1450,64);
    head=stock1;
    head->next=stock2;
    Stock *temp=head;
    temp=stock2;
    temp->next=stock3;
    temp=stock3;
    temp->next=stock4;
    temp=stock4;
    decide_user();
    cout<<p.get_user_name();
    while(1)
    {
        show_menu();
    }
    return 0;
}
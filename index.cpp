#include<iostream>
#include<fstream>

using namespace std;
class shopping 
{
    private:
        int pcode;
        float price;
        float discount;
        string pname;
 
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();

};

void shopping :: menu()
{
    int choice;
    string email;
    string password;
    while (true)
    {
        /* code */
        cout<<"\t\t\t\t------------------------------------\n";
        cout<<"\t\t\t\t                                    \n";
        cout<<"\t\t\t\t      Supermarket Main Menu         \n";
        cout<<"\t\t\t\t                                    \n";
        cout<<"\t\t\t\t------------------------------------\n";
        cout<<"\t\t\t\t                                    \n";
        cout<<"\t\t\t\t|   1) Administrator               |\n";
        cout<<"\t\t\t\t                                    \n";
        cout<<"\t\t\t\t|   2) Buyer                       |\n";
        cout<<"\t\t\t\t                                    \n";
        cout<<"\t\t\t\t|   3) Exit                        |\n";
        cout<<"\t\t\t\t                                    \n";
        cout<<"\n\t\t\t   Please Select :-";
        cin>>choice;

        switch(choice)
        { 
            case 1:
            cout<<"\t\t\t\t PLEASE LOGIN\n";
            cout<<"\t\t\t              \n";
            cout<<"\t\t\t\t Enter Email \n";
            cin>>email;
            cout<<"\t\t\t\t Password \n";
            cin>>password;

            if((email=="shop12@gmail.com") &&(password=="shopsy12")){
                administrator();
            }
            else{
                cout<<"Invalid email/password";
            }
            break;

            case 2:
            {
                buyer();
            }
            case 3:
            {
                exit(0);
            }
            default:
            {
                cout<<" Please select from the given options";
            }
        }
    }
    

   
    // goto m;
}

void shopping :: administrator()
{
    m: 
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t|_______1) Add the Product______|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_______2) Modify the Product___|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_______3) Delete  the Product__|";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t|_______4) Back to Main Menu____|";


    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            add();
            break;

        case 2:
            edit();
            break;

        case 3:
            rem();
            break;

        case 4:
            menu();
            break;

        default :
            cout<<"Invalid choice";
    }
    goto m;
}

void shopping :: buyer()
{
    m:
    int choices;
    cout<<"\t\t\t  Buyer          \n";
    cout<<"\t\t\t_________________\n";
    cout<<"                       \n";
    cout<<"\t\t\t 1) Buy product  \n";
    cout<<"                       \n";
    cout<<"\t\t\t 2) Go Back      \n";
    cout<<"\t\t\t Enter your choice :\n";

    cin>>choices;

    switch(choices){

        case 1:
            receipt();
            break;

        case 2:
            menu();
            break;

        default:
            cout<<"Invalid choice";
            break;
    }
    goto m;
}
  
void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code ";
    cin>>pcode;
    cout<<"\n\n\t Name of product ";
    cin>>pname;
    cout<<"\n\n\t Price of product ";
    cin>>price;
    cout<<"\n\n\t Discount on product ";
    cin>>discount;
    cout << "Data Collected\n Opening file to write " << endl;

    // opening file to write
    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else
    {
        cout << "adding data" << endl;
        data>>pcode>>pname>>price>>discount;

        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>pcode>>pname>>price>>discount;

        }
        data.close();


        if(token==1)
        {
            goto m;
        }
        else
        {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        }
    }
    cout<<"\n\n\t\t Record inserted ";
    menu();
}  

void shopping ::edit(){
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product code";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>discount;
            while(!data.eof())
            {
              if(pkey==pcode)
                {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product :";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount :";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n"; 
                cout<<"\n\n\t\t Record edited ";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry!";
        }
    }
}

void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File doesn't exist";
    }

    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof()){
            if(pcode==pkey)
            {
                cout<<"\n\n\t  Product delete successfully";
                token++;

            }
            else {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0){
            cout<<"\n\n Record not found sorry!";
        }
    }
}    

void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|__________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|__________________________________________________\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;

    }
    data.close();
}

void shopping::receipt()
{
    m:
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float discount=0;
    float total=0;

    cout<<"\n\n\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty database ";
    }
    else{
        data.close();

        list();
        cout<<"\n________________________________________________\n";
        cout<<"\n|                                               \n";
        cout<<"\n          Please place the order                \n";
        cout<<"\n                                                \n";
        cout<<"\n________________________________________________\n";
        do
        {
            cout<<"\n\nEnter product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter product quality :";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code. Please try again! ";
                    goto m;
                }

            }
            c++;
            cout<<"\n\n Do you Want to buy another product if yes then press y else no";
            cin>>choice;
        }
        while(choice =='y');
        cout<<"\n\n\t\t\t________________________RECEIPT___________________________\n";
        cout<<"\n Product No\t Product Name\t Product quality\t price\tAmount \tAmount with discount\n";

        for(int i=0;i<c;i++)
        {
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>discount;

            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount=price*arrq[i];
                    discount=amount-(amount*discount/100);
                    total=total+discount;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<discount;
                }
                data>>pcode>>pname>>price>>discount;
            }
        }
        data.close();
    }
    cout<<"\n\n_____________________________________________";
    cout<<"\n Total Amount : "<<total;
}
int main()
{
    shopping s;
    s.menu();
    // s.buyer();
}
#include <iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void managerDisplaymenu();
void recieptionistDisplaymenu();

class Employee
{
protected:
    string username, password;

public:
    virtual int login(string a, string b)=0;

};
class Recieptionist : public Employee
{
public:
    int login(string a, string b);

};
class Manager : public Employee
{
public:
    int login(string a, string b);
};
class Room
{
private:
    string name,mobile,nic,roomtypename;
    double roomcategory,noofrooms;
    double roomno,roomtype,roomprice;
public:
     void setReservationData(string a, string b, string c, double d, double e, double f);
     void readdata(int a);
     void displayReservation();
     void Reservation();
     void addroom(int a, int b, int c, int d);
     void deleteroom(int a);
};

void Room::displayReservation()
{
        ifstream file;
    file.open("ReservationRooms.txt");
    string display,display1,display2,display3,display4,display5;
            cout<<"\n\tName\tMobile No\tNIC\t\tRoom Category\tNo of Rooms\tRoom Type"<<endl;
    if(file.is_open())
    {
        while(!file.eof())
        {
            file>>display>>display1>>display2>>display3>>display4>>display5;
            cout<<"\t"<<display<<"\t"<<display1<<"\t\t"<<display2<<"\t"<<display3<<"\t\t"<<display4<<"\t\t"<<display5<<endl;
        }
    }
    else
    {
        cout<<"Error"<<endl;
    }
        file.close();
        cout<<"\nPress any key to go Main Menu ";
        getch();
}
void Room :: setReservationData(string a, string b, string c, double d, double e, double f)
{
        name=a;
        mobile=b;
        nic=c;
        roomcategory=d;
        noofrooms=e;
        roomtype=f;
}
void Room :: Reservation()
{
        ofstream file1("ReservationRooms.txt");
        if(file1.is_open())
        {
            file1<<name<<"\t"<<mobile<<"\t"<<nic<<"\t"<<roomcategory<<"\t"<<noofrooms<<"\t"<<roomtype;

        cout<<"\nSuccessfully Reserved!"<<endl;
        }
        else
        {
            cout<<"Error";
        }
        file1.close();
        cout<<"\nPress any key to go Main Menu ";
        getch();
        recieptionistDisplaymenu();
    }
void Room::readdata(int a)
{
        roomcategory=a;
    if(roomcategory==1)
    {
        ifstream file;
    file.open("ordinary.txt");
    string display,display1,display2;
    if(file.is_open())
    {
        while(!file.eof())
        {
            file>>display>>display1>>display2;
            cout<<display<<"\t"<<display1<<"\t"<<display2<<endl;
        }
    }
    else
    {
        cout<<"Error"<<endl;
    }
    file.close();
    }
    else if(roomcategory==2)
    {
        ifstream file;
    file.open("luxuary.txt");
    string display,display1,display2;
    if(file.is_open())
    {
        while(!file.eof())
        {
            file>>display>>display1>>display2;
            cout<<display<<"\t"<<display1<<"\t"<<display2<<endl;
        }
    }
    else
    {
        cout<<"Error"<<endl;
    }
    file.close();
    }
    else if(roomcategory==3)
    {
        ifstream file;
    file.open("royal.txt");
    string display,display1,display2;
    if(file.is_open())
    {
        while(!file.eof())
        {
            file>>display>>display1>>display2;
            cout<<display<<"\t"<<display1<<"\t"<<display2<<endl;
        }
    }
    else
    {
        cout<<"Error"<<endl;
    }
    file.close();
    }
    else
    {
        system("color FC");
        cout<<"invalid category "<<endl;
        system("color F5");
    }
    cout<<"Press Any key to go Main Menu"<<endl;
    getch();
}

void Room :: deleteroom(int a)
{
       roomcategory=a;

    if(roomcategory==1)
    {
        ofstream file1("ordinary.txt");
        if(file1.is_open())
        {
            file1<<"\n";

        cout<<"\n Deleted!"<<endl;
        }
        else
        {
            cout<<"Error";
        }
    }
    else if(roomcategory==2)
    {
        ofstream file1("luxuary.txt");
        if(file1.is_open())
        {
            file1<<"\n";

        cout<<"\n Deleted!"<<endl;
        }
        else
        {
            cout<<"Error";
        }
    }
    else if(roomcategory==3)
    {
        ofstream file1("royal.txt");
        if(file1.is_open())
        {
            file1<<"\n";

        cout<<"\n Deleted!"<<endl;
        }
        else
        {
            cout<<"Error";
        }
    }
    else
    {
        cout<<"\nInvalid Room Category!"<<endl;
    }
        cout<<"\n Press any key to go Main Menu ";
        getch();
        managerDisplaymenu();

}
class Invoice
{
private:
    int noofrooms;
    double roomcharge,total,nettotal;
    double invoiceno;
public:
    void setdata(int a);
    void generatebill(int a,int b);
};
void Invoice :: setdata(int a)
{
    noofrooms=a;
}
void Invoice :: generatebill(int a,int b)
{
    if(b==1)
    {
        if(a==1)
        {
        roomcharge=2000;
        total=roomcharge*noofrooms*0.2;
        nettotal=total+(roomcharge*noofrooms);
        cout<<"Service charge : "<<total<<endl;
        cout<<"Net Total : "<<nettotal;
        }else if(a==2)
        {
        roomcharge=5000;
        total=roomcharge*noofrooms*0.2;
        nettotal=total+(roomcharge*noofrooms);
        cout<<"Service charge : "<<total<<endl;
        cout<<"Net Total : "<<nettotal;
        }else if(a==3)
        {
        roomcharge=10000;
        total=roomcharge*noofrooms*0.2;
        nettotal=total+(roomcharge*noofrooms);
        cout<<"Service charge : "<<total<<endl;
        cout<<"Net Total : "<<nettotal;
        }else
        {
        system("color FC");
        cout<<"Enter valid type:"<<endl;
        system("color F5");
        }
    }else if(b==2)
    {
        if(a==1)
        {
        roomcharge=15000;
        total=roomcharge*noofrooms*0.2;
        nettotal=total+(roomcharge*noofrooms);
        cout<<"Service charge : "<<total<<endl;
        cout<<"Net Total : "<<nettotal;
        }else if(a==2)
        {
        roomcharge=20000;
        total=roomcharge*noofrooms*0.2;
        nettotal=total+(roomcharge*noofrooms);
        cout<<"Service charge : "<<total<<endl;
        cout<<"Net Total : "<<nettotal;
        }else if(a==3)
        {
        roomcharge=50000;
        total=roomcharge*noofrooms*0.2;
        nettotal=total+(roomcharge*noofrooms);
        cout<<"Service charge : "<<total<<endl;
        cout<<"Net Total : "<<nettotal;
        }
        else
        {
        system("color FC");
        cout<<"Enter valid type:"<<endl;
        system("color F5");
        }
    }else if(b==3)
    {
        if(a==1)
        {
        roomcharge=60000;
        total=roomcharge*noofrooms*0.2;
        nettotal=total+(roomcharge*noofrooms);
        cout<<"Service charge : "<<total<<endl;
        cout<<"Net Total : "<<nettotal;
        }else if(a==2)
        {
        roomcharge=70000;
        total=roomcharge*noofrooms*0.2;
        nettotal=total+(roomcharge*noofrooms);
        cout<<"Service charge : "<<total<<endl;
        cout<<"Net Total : "<<nettotal;
        }else if(a==3)
        {
        roomcharge=100000;
        total=roomcharge*noofrooms*0.2;
        nettotal=total+(roomcharge*noofrooms);
        cout<<"Service charge : "<<total<<endl;
        cout<<"Net Total : "<<nettotal;
        }else
        {
        system("color FC");
        cout<<"Enter valid type:"<<endl;
        system("color F5");
        }
    }else
    {
        system("color FC");
        cout<<"Enter valid category:"<<endl;
        system("color F5");
    }
    cout<<"\nPress any key to go Main Menu ";
    getch();
    recieptionistDisplaymenu();
}

int Manager::login(string a,string b)
{   username=a;
    password=b;
    if(username=="Sahan"&&password=="1234")
    {system("color F2");
    system("cls");

        cout<<"\n\n\n\n\t\t\t  ********* Login Successful ***********"<<endl;
        Sleep(1700);
        system("color F5");

    managerDisplaymenu();
    return 1;
    }
    else
    {system("color FC");
    system("cls");

        cout<<"\n\n\n\n\t\t\t********* Invalid username or password ***********"<<endl;
                Sleep(1700);
system("color F5");

        return 0;
    }

}
int Recieptionist::login(string a,string b)
{   username=a;
    password=b;
    if(username=="Limashi"&&password=="1234")
    {system("color F2");
    system("cls");

        cout<<"\n\n\n\n\t\t\t  ********* Login Successful ***********"<<endl;
            Sleep(1700);
system("color F5");

    recieptionistDisplaymenu();
            return 1;

    }
    else
    {system("color FC");
    system("cls");

        cout<<"\n\n\n\n\t\t\t********* Invalid username or password ***********"<<endl;
                Sleep(1700);
system("color F5");

    return 0;
    }

}
void Room :: addroom(int a, int b, int c, int d)
{
    roomno=a;
    roomcategory=b;
    roomtype=c;
    roomprice=d;
    if(roomtype==1)
    {
        roomtypename="Single";
    }
    else if(roomtype==2)
    {
        roomtypename="Double";
    }
    else if(roomtype==3)
    {
        roomtypename="Suit";
    }
    else
    {
        system("color FC");
        cout<<"\n\t\tinvalid type "<<endl;
        system("color F5");

        cout<<"Press Any key to go Main Menu"<<endl;
        getch();
        managerDisplaymenu();
    }
    if(roomcategory==1)
    {
        ofstream file1("ordinary.txt");
        if(file1.is_open())
        {
            file1<<roomno<<"\t"<<roomtypename<<"\t"<<roomprice;

        cout<<"\nSuccessfully Added Room! "<<endl;
        }
        else
        {
            cout<<"Error";
        }
        file1.close();
    }
    else if(roomcategory==2)
    {
        ofstream file1("luxuary.txt");
        if(file1.is_open())
        {
            file1<<roomno<<"\t"<<roomtypename<<"\t"<<roomprice;

        cout<<"\nSuccessfully Added Room! "<<endl;
        }
        else
        {
            cout<<"Error";
        }
        file1.close();
    }
    else if(roomcategory==3)
    {
        ofstream file1("royal.txt");
        if(file1.is_open())
        {
            file1<<roomno<<"\t"<<roomtypename<<"\t"<<roomprice;

        cout<<"\nSuccessfully Added Room! "<<endl;
        }
        else
        {
            cout<<"Error";
        }
        file1.close();
    }
    else
        {
            system("color FC");
            cout<<"\n\t\tinvalid category "<<endl;
        system("color F5");
        }
        cout<<"Press Any key to go Main Menu"<<endl;
        getch();
        managerDisplaymenu();
}
void managerDisplaymenu()
{
    Room room1;
    int category,no,type,price;
    system("cls");
system("color F1");
cout<<"\n\t\t\t         -------------------------";
Sleep(100);
cout<<"\n\t\t\t      ------------------------------";
Sleep(100);
cout<<"\n\t\t\t   ------------------------------------";
Sleep(100);
cout<<"\n\t\t\t------------------------------------------";
Sleep(100);
cout<<"\n\t\t\t* ";
Sleep(250);
cout<<"GRAND ";
Sleep(250);
cout<<"ROCKLAND ";
Sleep(250);
cout<<"HOTEL ";
Sleep(250);
cout<<"MANAGEMENT ";
Sleep(250);
cout<<"SYSTEM ";
Sleep(100);
cout<<"*";
Sleep(100);
cout<<"\n\t\t\t------------------------------------------";
Sleep(100);
cout<<"\n\t\t\t   ------------ Main Menu -------------";
Sleep(100);
cout<<"\n\t\t\t      ------------------------------";
Sleep(100);
cout<<"\n\t\t\t         -------------------------";
Sleep(600);
int choice;
    system("color F5");

    cout<<"\n\n\t\t1  Add Rooms "<<endl;
    cout<<"\t\t2  Delete Rooms "<<endl;
    cout<<"\t\t3  View Rooms "<<endl;
    cout<<"\t\t4  View Reservation Details"<<endl;
    cout<<"\t\t0  Exit "<<endl;
    cout<<"\n\t\tEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
        cout<<"________________________________________"<<endl;
        case 0:
        exit(0);
        break;

         case 1:
          system("cls");
          system("color FD");

         cout<<"\n\nEnter Room No : ";
         cin>>no;

         cout<<"\n\n\t1 - Ordinary"<<endl;
         cout<<"\t2 - Luxury"<<endl;
         cout<<"\t3 - Royal"<<endl;

         cout<<"\nEnter Room Category : ";
         cin>>category;

         cout<<"\n\n\t1 - Single"<<endl;
         cout<<"\t2 - Double"<<endl;
         cout<<"\t3 - Suit"<<endl;

         cout<<"\nEnter Room type     : ";
         cin>>type;

         cout<<"\nEnter Room Price : ";
         cin>>price;

        room1.addroom(no,category,type,price);
         break;

         case 2:
             system("cls");
         cout<<"\n\t1 - Ordinary"<<endl;
         cout<<"\t2 - Luxuary"<<endl;
         cout<<"\t3 - Royal"<<endl;
         cout<<"\n\nEnter Room Category : ";
         cin>>category;

         cout<<endl;

        room1.deleteroom(category);
         break;


         case 3:
             system("cls");
         cout<<"\n\t1 - Ordinary"<<endl;
         cout<<"\t2 - Luxuary"<<endl;
         cout<<"\t3 - Royal"<<endl;
         cout<<"\n\nEnter Room Category : ";
         cin>>category;

         cout<<endl;

         room1.readdata(category);
        managerDisplaymenu();
         break;

         case 4:
         system("cls");
         room1.displayReservation();
         managerDisplaymenu();
         break;

         default:
             system("color FC");
         cout<<"\nInvalid Choice! Try again"<<endl;
         cout<<endl;
         system("color F5");
         Sleep(2000);
         managerDisplaymenu();

         }
}

void recieptionistDisplaymenu()
{
    Room room1;
    int category,type,norooms;
    string name,mobile,nic;
    double roomcategory,roomtype,noofrooms;

    Invoice inv;

    system("cls");
system("color F1");
cout<<"\n\t\t\t         -------------------------";
Sleep(100);
cout<<"\n\t\t\t      ------------------------------";
Sleep(100);
cout<<"\n\t\t\t   ------------------------------------";
Sleep(100);
cout<<"\n\t\t\t------------------------------------------";
Sleep(100);
cout<<"\n\t\t\t* ";
Sleep(250);
cout<<"GRAND ";
Sleep(250);
cout<<"ROCKLAND ";
Sleep(250);
cout<<"HOTEL ";
Sleep(250);
cout<<"MANAGEMENT ";
Sleep(250);
cout<<"SYSTEM ";
Sleep(100);
cout<<"*";
Sleep(100);
cout<<"\n\t\t\t------------------------------------------";
Sleep(100);
cout<<"\n\t\t\t   ------------ Main Menu -------------";
Sleep(100);
cout<<"\n\t\t\t      ------------------------------";
Sleep(100);
cout<<"\n\t\t\t         -------------------------";
Sleep(600);
    system("color F5");
    int choice;

    cout<<"\n\n\t\t1  Reserve a room "<<endl;
    cout<<"\t\t2  View Reservation Details"<<endl;
    cout<<"\t\t3  View Room Details "<<endl;
    cout<<"\t\t4  Genarate Invoice "<<endl;
    cout<<"\t\t0  Exit "<<endl;
    cout<<"\n\t\tEnter your choice : ";
    cin>>choice;
    switch(choice)
    {
        cout<<"________________________________________"<<endl;
        case 0:
        exit(0);
        break;

         case 1:
system("color F1");

    system("cls");
    cout<<"\n\t\t*************** Reservation Details ****************** ";
    cout<<"\nEnter Name of the customer: ";
    cin>>name;
    cout<<"\nEnter Mobile no: ";
    cin>>mobile;
    cout<<"\nEnter NIC no ";
    cin>>nic;
    cout<<"\nEnter The Room Category : ";
    cin>>roomcategory;
    cout<<"\nEnter The Room Type : ";
    cin>>roomtype;
    cout<<"\nEnter The Room # to be Reserved: ";
    cin>>noofrooms;

    room1.setReservationData(name,mobile,nic,roomcategory,roomtype,noofrooms);
    room1.Reservation();
        break;

         case 2:
         system("cls");
         room1.displayReservation();
         recieptionistDisplaymenu();
         break;

         case 3:
    system("cls");
         cout<<"\n\t1 - Ordinary"<<endl;
         cout<<"\t2 - Luxuary"<<endl;
         cout<<"\t3 - Royal"<<endl;
         cout<<"\n\nEnter Room Category : ";
         cin>>category;

         cout<<endl;

         room1.readdata(category);
         recieptionistDisplaymenu();
         break;

         case 4:

    system("cls");
         cout<<"\n\t1 - Ordinary"<<endl;
         cout<<"\t2 - Luxuary"<<endl;
         cout<<"\t3 - Royal"<<endl;

        cout<<"\n\nEnter Room Category : ";
        cin>>category;

         cout<<"\n\t1 - Single"<<endl;
         cout<<"\t2 - Double"<<endl;
         cout<<"\t3 - Suit"<<endl;

        cout<<"\n\nEnter Room Type : ";
        cin>>type;

        cout<<"\n\n\nEnter No Of Rooms Reserved : ";
        cin>>norooms;
        inv.setdata(norooms);
        inv.generatebill(category,type);

         break;

         default:
             system("color FC");
         cout<<"\nInvalid Choice! Try again"<<endl;
         cout<<endl;
         system("color F5");
         Sleep(2000);
         recieptionistDisplaymenu();
         }
}
int main()
{
    Manager man;
    Recieptionist rec;

    int usertype,choice,result;
    string username,password;

    system("color F5");
cout<<"\n\t\t\t         -------------------------";
Sleep(100);
cout<<"\n\t\t\t      ------------------------------";
Sleep(100);
cout<<"\n\t\t\t   ------------------------------------";
Sleep(100);
cout<<"\n\t\t\t------------------------------------------";
Sleep(100);
cout<<"\n\t\t\t* ";
Sleep(250);
cout<<"GRAND ";
Sleep(250);
cout<<"ROCKLAND ";
Sleep(250);
cout<<"HOTEL ";
Sleep(250);
cout<<"MANAGEMENT ";
Sleep(250);
cout<<"SYSTEM ";
Sleep(100);
cout<<"*";
Sleep(100);
cout<<"\n\t\t\t------------------------------------------";
Sleep(100);
cout<<"\n\t\t\t   ------------------------------------";
Sleep(100);
cout<<"\n\t\t\t      ------------------------------";
Sleep(100);
cout<<"\n\t\t\t         -------------------------";
Sleep(600);
system("color F1");
    char a= 177,b=219;
    cout<<"\n\n\t\t\tLoading...";
    cout<<"\n\n\t\t\t";
    for(int i=0;i<=40;i++)
        cout<<" " ;
      Sleep(70);
    cout<<"\r";
    cout<<"\t\t\t";
    for(int i=0;i<=40;i++)
    {
        cout<<b;
        Sleep(70);
    }
do{
    system ("cls");
    system("color F3");

    cout<<"\n\t1 - Manager"<<endl;
    cout<<"\t2 - Receptionist\n"<<endl;

    cout << "Enter user type : ";
    cin>>usertype;


    if(usertype==1)
    {
    cout<<"\nEnter username : ";
    cin>>username;
    cout<<"\nEnter password : ";
    cin>>password;

    result=man.login(username,password);

    }else if(usertype==2)
    {
        cout<<"\nEnter username : ";
        cin>>username;
        cout<<"\nEnter password : ";
        cin>>password;

    result=rec.login(username,password);
    }
    else
    {
        system("color FC");
        cout<<"\n\t\t********* Invalid user type ***********"<<endl;
        system("color F5");
        break;
    }
   }while(result!=1);

    return 0;
}


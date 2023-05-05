#include <iostream>
#include <typeinfo>
#include <exception>
#include <new>
using namespace std;
/*
class Polymorphic
{
    virtual void member(){}
};
int main()
{
    try
    {
        Polymorphic *pb=0;
        typeid(*pb);
    }
    catch(std::exception& e)
    {
        std::cerr<<"Exception Caught: "<<e.what()<<endl;
    }
    return 0;
} */

class ageexception:public exception
{
public:
    const char * what()const throw()
    {
        return "Age is below 18\n";
    }
};
class person
{
    string name;
    int age;
public:
    person(string name,int age)
    {
        this->name=name;
        if(age<18)
        {
            ageexception z;
            throw z;
        }
        else
            this->age=age;
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

/* class Base
{
    virtual void member(){}
};
class derived:Base{};

class negbalance: public exception
{
public:
    const char * what() const throw()
    {
        return "Balance Underflow\n";
    }
};
class account
{
    int acc_no;
    float bal;
public:
    account(int acc_no,float bal)
    {
        this->acc_no=acc_no;
        if(bal<0)
        {
            negbalance z;
            throw z;
        }
        else
            this->bal=bal;
    }
    void display()
    {
        cout<<"Account No: "<<acc_no<<endl;
        cout<<"Balance: "<<bal<<endl;
    }
};
*/
int main()
{

    try
    {
        int a;
        cin>>a;
        cout<<"hi";

    }
    catch(std::bad_cast& c)
    {
        std::cerr<<"bad allocation";
    }
  /* try
    {
        person p("Ram",25);
        p.display();
    }
    catch(exception& e)
    {
        cout<<e.what();
    }

     try
   /* {
        int *myarray=new int[100000000000000000];
    }
    catch(std::bad_alloc&  ba)
    {
        std::cerr<<"Bad_Alloc Caught: "<<ba.what()<<endl;
    }
     try
    {
        Base b;
        derived &rd=dynamic_cast<derived&>(b);
    }
    catch(std::bad_cast& bc)
    {
        std::cerr<<"Bad Casting: "<<bc.what()<<endl;
    }
    try
    {
        account a(102530,-20000);
        a.display();
    }
    catch(exception& e)
    {
        cout<<e.what();
    }
    */
    return 0;
}


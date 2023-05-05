#include<iostream>
#include<exception>
using namespace std;

class sellerexception:public exception
{
  public:
 const char * what()const throw()
    {
        return "Your id does not found in our data base please enroll first :\n";
    }

};
class customerexception:public exception
{
     public:
     const char * what()const throw()
    {
        return "Your phone_number does not found in our data base please enroll first:\n";
    }

};
class invaliditemtype:public exception
{
     public:
     const char * what()const throw()
    {
        return "The item selected by you is invalid";
    }
};
class detailsfound:public exception
{
     public:
     const char * what()const throw()
    {
        return "Your details are already found in our system please login with that:\n";
    }


};
class invaliditemsadding:public exception
{

     public:
     const char * what()const throw()
    {
        return "item not found please enter correct serial no :\n";
    }
};



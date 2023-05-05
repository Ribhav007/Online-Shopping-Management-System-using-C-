#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream>
#include<exception>

using namespace std;
int ord1=0;
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

class date
{
private:
    int dd;
    int mm;
    int yy;
public:
    void  assigndate()
    {
        cout<<"Enter the Date in DD/MM/YYYY format:\n";
        cin>>dd>>mm>>yy;
    }
    void displaydate()
    {
        cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
    }
};
class items
{
private:
public:
    string itemtype;
    string itemname;
    string company;
    float price;
    int quantity;
    string item_description;
    static int totalitems;
    struct itemid
    {
        int id;
        string type;
    };
    struct itemid itemid;
    items()
    {
        itemtype="";
        itemname="";
        price=0.0;
        quantity=0.0;
        item_description="";
        totalitems++;
    }
    virtual void additem();
    virtual void display();
    virtual void catalogdisplay()=0;
    virtual void sellerindisplay()
    {
        cout<<"Item Name:              "<<itemname<<endl;
        cout<<"Item ID:                "<<itemid.type<<itemid.id<<endl;
        cout<<"Item Type:              "<<itemtype<<endl;
        cout<<"Item Description:       "<<item_description<<endl;
        cout<<"Price:                  "<<price<<endl;
        cout<<"Quantity:               "<<quantity<<endl;
    }
};
class electrical:public items
{
private:
public:
    static int ecto;
    int warranty;
    string item_specification;
    electrical():items()
    {
       this->itemtype="electrical";
       itemid.id=totalitems;
       this->itemid.type="EC";
       warranty=0;
       ecto++;
    }
    void additem()
    {
        items::additem();
        cout<<"Enter the warranty: ";
        cin>>warranty;
        cout<<"Enter the Item Specification: ";
        cin>>item_specification;
    }
    void display()
    {
        items::display();
    }
    void catalogdisplay()
    {
        cout<<itemid.type<<itemid.id<<"\t\t\t"<<company<<"\t\t\t"<<itemname<<"\t\t\t"<<price<<"\t\t\t"<<endl;
    }

    void sellerindisplay()
   {
    items::sellerindisplay();

    cout<<"Warranty:               "<<warranty<<endl;
    cout<<"Item Specification:     "<<item_specification<<endl;
   }
};
class fashion:public items
{
public:
    string sizeavailable;
    static int fash;
    fashion():items()
    {
        this->itemtype="fashion";
        itemid.id=totalitems;
        itemid.type="FS";
        sizeavailable='0';
        fash++;
    }
    void additem()
    {
        items::additem();
        cout<<"Enter the available size: ";
        cin>>sizeavailable;
    }
    void display()
    {
        items::display();
        cout<<"\t\t"<<sizeavailable<<endl;
    }
    void catalogdisplay()
    {
        cout<<itemid.type<<itemid.id<<"\t\t"<<company<<"\t\t"<<itemname<<"\t\t"<<price<<"\t\t"<<sizeavailable<<endl;
    }
    void sellerindisplay()
    {
        items::sellerindisplay();
        cout<<"Size available:         "<<sizeavailable<<endl;
    }
};
class food : public items
{
private:
public:
    date dm,de;
    static int fo;
    food():items()

    {
        this->itemtype="food";
        itemid.id=totalitems;
        itemid.type="FD";
        fo++;
    }
    void additem()
    {
        items::additem();
        cout<<"Enter the date of manufacture: ";
        dm.assigndate();
        cout<<"Enter the expiry date: ";
        de.assigndate();
    }
    void display()
    {
        items::display();
        cout<<"\t\t";
        dm.displaydate();
        cout<<"\t\t";
        de.assigndate();
        cout<<endl;
    }
    void catalogdisplay()
    {
        cout<<itemid.type<<itemid.id<<"\t\t"<<company<<"\t\t"<<itemname<<"\t\t"<<price<<"\t\t"<<endl;
    }
    void sellerindisplay()
    {
        items::sellerindisplay();
        cout<<"Manufacture Date:       ";
        dm.displaydate();
        cout<<"Expiry Date:            ";
        de.displaydate();
    }
};
class customer;
class cart
{
private:
    int countitems;
    items *i[10];
    void additemtocart(items* i);
    void cartdisplay();
    void removeitemsfromcart(string item_name);
public:
     cart()
    {
       countitems=0;
    }

    friend class customer;
};
class shipments
{
    string state;
    string district;
    int pincode;
    string address;
public:
    void assignaddress();
    void displayaddress();
};
class orders
{
private:

    struct itemid
    {
        int id;
        string type;
    };
    string item_name;
    int orderid=0;
    struct itemid itemid;
    int signal;
    shipments s;
    void assignorders(shipments s,items *i,int q);
    void cancelorders();
public:
    static int totalorders;
    void displayorder();
    float price=0.0;
    orders()
    {
        signal=0;
        totalorders++;
        orderid=totalorders;
    }

    friend class customer;
    friend class myflipcart;
};
class myflipcart;
class customer
{
private:
    string customer_name;
    struct customerid
    {
        string type;
        int id;
    };
    string coupoun="INVALID";
    int ordercount=0;
    shipments s;
    long int phonenumber;

    cart c;
    struct idgenerate
    {
        string type;
        int id;
    };
    orders *o[10];

   virtual void customerassigndetails();
   virtual void printcustomerdetails();
    void additemcart(items* i);
    void removeitemfromcart();
    void addaddress();
    void displayorders();
    orders* orderproduct();
    void displaycart();
public:
    customer()
    {
        customer_count++;
    }
       static int customer_count;
        struct idgenerate idgenerate;
    friend class myflipcart;
};
class normalcustomers : public customer
{
public:
    static int normal;
    normalcustomers()
    {
        idgenerate.type="NM";
        idgenerate.id=customer_count;
        normal++;
    }
};
class subscribedcustomers:public customer
{
public:
    static int sub;
    float discount_rate=10.0;
    subscribedcustomers()
    {
        idgenerate.type="SB";
        idgenerate.id=customer_count;
        sub++;
    }

};
class sellers;
class catalog
{
    private:
    items *i[10]={NULL};
    int itemcount=0;
    void additemtocatalog(items *j);
    void displaycatalog();
    public:
    friend class myflipcart;
    friend class sellers;
};
class sellers
{
    private:
    string sellername;
    int phno;
    static int count1;
    int sellerid;
    items *i[10];
    int addcount;
    sellers()
    {
        addcount=0;
        count1++;
        sellerid=count1;
    }
    void sellerassign();
    void display();
    items* additem();
    void displayitems();
    friend class myflipcart;
};
class myflipcart
{
private:
    customer *cust[30];
    catalog c;
    sellers *seller[30];
    orders *ord[20];
public:
    myflipcart()
    {
        customer::customer_count=0;
        sellers::count1=0;
        items::totalitems=0;
    }
    void display();
    void custregister();
    void sellerregister();
    void customerentry();
    items* pick();
    void sellerentry();
    void displayorders();
    void shiporders();
    void displaycustomer();
    void displaysellers();
    void displaycatalog();
    void shoplogin();
    void open()
    {
        int status=0;
        int ch;
        while(status==0)
        {
            cout<<"\nPress:\n1. Shop Login\n2. Customer Login\n3. Seller Login\n4. Registration of Customer \n5. Registration of Seller \n6. Exit\n\n";
            cin>>ch;
            switch(ch)
            {
                case 1:
                    shoplogin();
                    break;
                case 2:
                    try{
                    customerentry();
                    }
                    catch(exception& e)
                    {
                        cout<<e.what();
                    }
                    break;
                case 3:
                    try{
                    sellerentry();
                    }
                    catch(exception& f)
                    {
                        cout<<f.what();
                    }
                    break;
                case 6:
                    status=1;
                    break;
                case 4:
                    custregister();
                    break;
                case 5:
                    sellerregister();
                    break;
                default:
                    cout<<"Wrong Choice Try Again";
                    break;
            }
        }
    }
};
void items::additem()
{
    cout<<"\nEnter the Item Name: ";
    cin>>itemname;
    cout<<"Enter the price of item: ";
    cin>>price;
    cout<<"Enter the Item description: ";
    cin>>item_description;
    cout<<"Enter the Quantity of item: ";
    cin>>quantity;
    cout<<"Enter the Company of item: ";
    cin>>company;
}
void items::display()
{
   cout<<itemid.type<<itemid.id<<"\t\t\t"<<company<<"\t\t\t"<<itemname<<"\t\t\t"<<price<<"\t\t\t"<<item_description<<"\t\t\t"<<quantity<<endl;
}
void cart::additemtocart(items* i)
{
    countitems++;
    cout<<"Items in the cart are  :"<<countitems<<endl;
    this->i[countitems]=i;
}
void cart :: cartdisplay()
{
    if(countitems==0)
    {
        cout<<"It is feeling very light";
        cout<<endl;
    }
    else
    {
        cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Serial No\t\tItem ID\t\tCompany\t\tItem Name\t\tPrice\t\tItem Description\t\tQuantity"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
        for(int i1=1;i1<=countitems;i1++)
        {
            cout<<i1<<"----------->";
            i[i1]->sellerindisplay();
            cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
        }
    }
}
void cart::removeitemsfromcart(string item_name)
{
    for(int i1=1;i1<=countitems;i1++)
    {
        if(i[i1]->itemname==item_name)
        {
            i[i1]->sellerindisplay();
            for(;i1<=countitems;i1++)
            {
                i[i1]=i[i1+1];
            }
        }
    }
    countitems--;
}
void shipments:: assignaddress()
{
    cout<<"Enter State: ";
    cin>>state;
    cout<<"Enter District: ";
    cin>>district;
    cout<<"Enter Pincode: ";
    cin>>pincode;
    cout<<"Enter Address: ";
    cin>>address;
    cout<<"\nThe sellers details are created successfully";
    cout<<endl;
}
void shipments::displayaddress()
{
    cout<<"State    -> "<<state<<endl;
    cout<<"District -> "<<district<<endl;
    cout<<"Pincode  -> "<<pincode<<endl;
    cout<<"Address  -> "<<address<<endl;
}
void orders:: assignorders(shipments s,items *i,int q)
{

    item_name=i->itemname;
    this->itemid.id=i->itemid.id;
    this->itemid.type=i->itemid.type;
    this->s=s;
    price=q*i->price;
    cout<<i->itemname;
    s.displayaddress();
}
void orders :: displayorder()
{
    cout<<"The following are the Orders with Order Id: "<<orderid<<endl;
    cout<<"Item name: "<<item_name<<endl;
    cout<<"Item id: "<<itemid.type<<itemid.id<<endl;
    s.displayaddress();
    if(signal==0)
    {
        cout<<"The order is pending for shipment\n";
    }
    else if(signal==1)
    {
        cout<<"The order is shipped to below address";
        cout<<endl;
        s.displayaddress();
    }
    else if(signal==2)
    {
        cout<<"The order has been canceled\n";
    }
}
void orders:: cancelorders()
{
    signal=2;
}
void customer::customerassigndetails()
{
    cout<<"Enter Customer Name: ";
    cin>>customer_name;
    cout<<"Enter Customer Phone number: ";
    cin>>phonenumber;
    cout<<"The Customer is created successfully\n";
    cout<<"The Customer id is given by: ";
    cout<<idgenerate.type<<idgenerate.id;
    cout<<endl;
}
void customer:: printcustomerdetails()
{

    cout<<idgenerate.type<<idgenerate.id<<"\t\t"<<customer_name<<"\t\t"<<phonenumber<<"\t\t"<<coupoun<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
}
void customer :: additemcart(items* i)
{

    c.additemtocart(i);
}
void customer::removeitemfromcart()
{
    string item_name;
    cout<<"Enter the Item Name to remove item from cart: ";
    cin>>item_name;
    c.removeitemsfromcart(item_name);
}
void  customer::addaddress()
{
    s.assignaddress();
    s.displayaddress();
}
orders* customer::orderproduct()
{
    int n=0;
    char q;
    c.cartdisplay();
    if(c.countitems==0)
    {
        cout<<"Go to the cart to enter items\n";
        return 0;
    }
    else
    {
        cout<<"Enter the item no to be ordered: ";
        cin>>n;
        cout<<"Enter QUANTITY :";
        q=getche();
        cout<<endl;
        if(isalnum(q))
           {
               o[ordercount]=new orders;
        o[ordercount]->assignorders(s,c.i[n],(q-48));
        ordercount++;
        return o[ordercount-1];
           }
        else
        {
            cout<<"You entered invalid character";
            cout<<endl;
            orderproduct();

        }
}
}
void customer::displaycart()
{
    c.cartdisplay();
}
void catalog:: additemtocatalog(items *j)
{
    itemcount++;
    if(j->itemtype=="electrical")
    {
        i[electrical::ecto]=j;
    }
    else if(j->itemtype=="fashion")
        i[fashion::fash]=j;
    else if(j->itemtype=="food")
        i[food::fo]=j;
}
void catalog::displaycatalog()
{
    int choice=0;
    int i1;
    cout<<"\n-------------Enter the type of Item do you want to display----------------------"<<endl;
    cout<<"1.Electronics \n 2.fashion \n3.fashion"<<endl;
    cin>>choice;
    if(choice>3 || choice <1)
    {
        invaliditemtype k;
        throw k;
    }
    if(choice==1)
    {
        cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Serial No\tItem ID\t\t\tCompany\t\t\tItem Name\t\tPrice"<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
        for(i1=1;i1<=electrical::ecto;i1++)
        {
            cout<<i1<<"\t\t";
            i[i1]->catalogdisplay();
            cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
        }
    }
    else if(choice==2)
    {
        cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Serial No\t\tItem ID\t\tCompany\t\tItem Name\t\tPrice\t\tSize Available"<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
        for( i1=11;i1<=fashion::fash;i1++)
        {
            cout<<i1<<"\t\t";
            i[i1]->catalogdisplay();
            cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
        }
    }

  else


    {
        cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
        cout<<"Serial No\t\tItem ID\t\tCompany\t\tItem Name\t\tPrice\t\tWeight"<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
        for( i1=21;i1<=food::fo;i1++)
        {
            cout<<i1<<"\t\t";
            i[i1]->catalogdisplay();
            cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
        }
    }


}
void customer::displayorders()
{
    float total_amount=0.0;
    int i;
    for( i=0;i<ordercount;i++)
    {
        cout<<idgenerate.type<<idgenerate.id;
        cout<<endl;
        (*o[i]).displayorder();
        cout<<endl;
    }
        cout<<endl;
        cout<<"------------------------------------------------------------------------------------"<<endl;
        cout<<"ORDER ID\tITEM ID\tITEM NAME\tPRICE"<<endl;
        cout<<"------------------------------------------------------------------------------------"<<endl;

    for(i=0;i<ordercount;i++)
    {
        if(o[i]->signal==0)
        {
            total_amount+=o[i]->price;
         cout<<o[i]->orderid<<"\t"<<"\t"<<o[i]->itemid.type<<o[i]->itemid.id<<"\t\t"<<o[i]->item_name<<"\t\t"<<o[i]->price<<endl;;
         cout<<"------------------------------------------------------------------------------------"<<endl;

        }
    }

    cout<<"                     TOTAL PRICE          :"<<total_amount<<endl;
    cout<<"------------------------------------------------------------------------------------"<<endl;

}

void sellers::sellerassign()
{
    cout<<"Enter the your name: ";
    cin>>sellername;
    cout<<"Enter Phone Number: ";
    cin>>phno;
    cout<<"The seller is created successfully with ID: "<<sellerid<<endl;
}
void sellers::display()
{
    cout<<sellerid<<"\t\t"<<sellername<<"\t\t"<<phno<<endl;
}
items* sellers::additem()
{
    int choice;
    int status=0;
    while(status==0)
    {
        cout<<"\nSelect the category of the product"<<endl;
        cout<<"1. Electronics\n2. Fashion\n3. Food \n4. Go back\n"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                addcount++;
                i[addcount]=new electrical;
                i[addcount]->additem();
                return i[addcount];
                break;
            case 2:
                addcount++;
                i[addcount]=new fashion;
                i[addcount]->additem();
                return i[addcount];
                break;
            case 3:
                addcount++;
                i[addcount]=new food;
                i[addcount]->additem();
                return i[addcount];
                break;
            case 4:
                status=1;
                break;
            default :
                cout<<"You have entered an invalid option"<<endl;
                break;
        }
    }
}
void sellers::displayitems()
{
    cout<<endl;
    cout<<"----------------The total items added by sellers are----------------- "<<endl;
    for(int i1=1;i1<=addcount;i1++)
    {
        cout<<endl<<i1<<"----------->\n\n";
        i[i1]->sellerindisplay();

    }
}
void myflipcart::custregister()
{
    int status=0;
    ifstream infile;
    string copoun;
    string filecopoun;
    cout<<"-------------------------------WELCOME TO CUSTOMER REGISTRATION-----------------------------------\n"<<endl;
    cout<<"IF YOU HAVE COPOUN ID PRESS 1 ELSE PRESS 2  to go back press 3:";
    while(status==0)
    {
       switch(getch())

           {
           case '1':infile.open("copoun.txt");
                cout<<"enter the copouncode  :";
                cin>>copoun;
                while(!infile.eof())
                {
                infile>>filecopoun;
                if(copoun==filecopoun)


                       {
                            cout<<"copoun applied successfully"<<endl;
                            cust[customer::customer_count]=new subscribedcustomers;
                            (*cust[customer::customer_count]).customerassigndetails();
                            cust[customer::customer_count]->coupoun=copoun;
                            infile.close();
                            status=1;
                            break;
                        }
                 }
                if(status==0)
                {
                cout<<"invalid copoun applied please enter again"<<endl;
                infile.close();
                custregister();
                status=1;
                }

                break;
         case '2':cout<<endl;
               cust[customer::customer_count]=new normalcustomers;
              (*cust[customer::customer_count]).customerassigndetails();
              status=1;
               break;
          case '3':cout<<"Exited successfully"<<endl;
          status=1;
           break;
         default :cout<<"Invalid choice. Enter correct option"<<endl;
           break;
    }

    }
}
void myflipcart::sellerregister()
{
    seller[sellers::count1]=new sellers;
    (*seller[sellers::count1]).sellerassign();
}
void myflipcart::customerentry()
{
    int phno;
    int status=1;
    int found=0;
    int ch;
    int i;
    int back1;
    while(found==0)
    {
        cout<<"Enter  Customer Login"<<endl;
        cout<<"Enter your Phone Number: ";
        cin>>phno;
        for(i=1;i<customer::customer_count+1;i++)
        {
            if(cust[i]->phonenumber==phno)
            {
                found=1;
                cout<<"Welcome "<<endl;
                cout<<"----------------------------------------------------------------------------------------"<<endl;
                cout<<"CUSTOMER ID\tCUSTOMER NAME\tPhone Number\tCOUPOUN"<<endl;
                 cout<<"----------------------------------------------------------------------------------------"<<endl;
                cust[i]->printcustomerdetails();
                cout<<endl;
                found=1;
                status=0;
                break;
            }
            else
            if(i>=customer::customer_count)
            {
                cout<<"\nPlease re-enter your number or Press 0 to go back\nPress Enter to Continue\n";
                if(getch()=='0')
                {
                    found=1;
                    break;
                }
            }
        }
        if(customer::customer_count==0)
        {
            cout<<"\n your details are not found \n     Please re-enter your number or Press 0 to go back\n     Press Enter to Continue\n";
                if(getch()=='0')
                {
                    found=1;

                    break;
                }
        }
    }
    found=0;
    while(status==0)
    {
        printf("\nPress:\n1. Add Shipment Address\n2. Add Item to Cart\n3. Order a Product\n4. Remove Item from Cart\n5. Display Orders\n6. Display Cart\n7. Log Out\n");
        cin>>ch;
        switch(ch)
        {
            case 1:
                cust[i]->addaddress();
                break;
            case 2:
                back1=0;
                while(back1==0)
                {
                    cust[i]->additemcart(pick());
                    cout<<"Item added to Cart Successfully.\nPress 0 to add more items\n1 to leave\n";
                    cin>>back1;
                }
                break;
            case 3:
                ord1++;
                ord[ord1]=cust[i]->orderproduct();
                cout<<endl;
                break;
            case 4:
                cust[i]->removeitemfromcart();
                break;
            case 5:
                cust[i]->displayorders();
                break;
            case 6:
                cust[i]->displaycart();
                break;
            case 7:
                status=1;
                break;
            default:
                printf("Wrong Choice.... Please Try again\n");
        }
    }
    status=0;
}
items* myflipcart::pick()
{
    int fo=0;
    int it;
    char t;
    int mark=0;
    while(fo==0)

        {   while(mark==0)
        {


            try {
           c.displaycatalog();
           mark=1;
            }
          catch(exception& n)
          {
              cout<<n.what();
              mark=0;
          }
        }
        mark=0;
        while(mark==0)
        {
            try {
        cout<<"Enter Item Serial no to add";
        cin>>it;
        if(c.i[it]==NULL)
        {
            cout<<"Item not found for given serial number. Enter again: "<<endl;
            cout<<"Press any key to continue";
            getch();
        }
        else
        {
            cout<<endl;
            c.i[it]->sellerindisplay();
            cout<<"Confirm to add in cart. Press y for YES and n for NO: ";
            t=getch();
            cout<<endl;
            if(t=='y')
            {
                return c.i[it];
            }
           }
            }
            catch(...)
            {
                cout<<"item not found please enter again";
                mark=0;
            }
        }
    }
}
void myflipcart::sellerentry()
{
    int phno;
    int status=0;
    int found=0;
    int ch;
    int i;
    int back1;
    int sd;
    int choice;
    while(found==0)
    {
        cout<<"\nEnter your Seller ID to login: "<<endl;
        cin>>sd;
        for( i=1;i<sellers::count1+1;i++)
        {
            if(seller[i]->sellerid==sd)
            {
                found=1;
                cout<<"\nWelcome\n"<<endl;
                cout<<"-----------------------------------------------------------------------"<<endl;
                cout<<"Seller Id       Seller Name\tPhone Number"<<endl;
                cout<<"-----------------------------------------------------------------------"<<endl;
                seller[i]->display();
                cout<<endl;
                status=1;
                break;
            }
            else
            if(i>sellers::count1 || sellers::count1==0)
            {
                sellerexception s;
                throw s;
                cout<<"\nPlease re-enter your number or Press 0 to go back\n";
                cin>>choice;
                if(choice==0)
                {
                    i=sellers::count1+10;
                    found=1;
                }
            }
        }


         if(sellers::count1==0)
        {
                sellerexception s;
                throw s;
        }
    }
    found=0;
    while(status==1)
    {
        printf("\nPress:\n1. Add item to catalog \n2. Display Items\n3. Log out.\n\n");
        cin>>ch;
        switch(ch)
        {
            case 2:
                seller[i]->displayitems();
                break;
            case 1:
                back1=0;
                while(back1==0)
                {
                    c.additemtocatalog(seller[i]->additem());
                    cout<<"\nItem added to Catalog Successfully.\nPress\n0 to add more items\n1 to leave\n";
                    cin>>back1;
                }
                break;
            case 3:
                status=0;
                break;
            default:
                printf("Wrong Choice.... Please Try again\n");
                break;
        }
    }
    cout<<"Seller logged out successfully"<<endl;
    status=1;
}
void myflipcart:: displayorders()
{
    float total_amount=0.0;
    int i=1;
    for(i=1;i<=ord1;i++)
    {
        ord[i]->displayorder();
    }
         cout<<endl;
        cout<<"------------------------------------------------------------------------------------"<<endl;
        cout<<"ORDER ID\tITEM ID\tITEM NAME\tPRICE"<<endl;
        cout<<"------------------------------------------------------------------------------------"<<endl;

    for(i=1;i<=ord1;i++)
    {

        {
            total_amount+=ord[i]->price;
         cout<<ord[i]->orderid<<"\t"<<"\t"<<ord[i]->itemid.type<<ord[i]->itemid.id<<"\t\t"<<ord[i]->item_name<<"\t\t"<<ord[i]->price<<endl;;
         cout<<"------------------------------------------------------------------------------------"<<endl;

        }
    }

    cout<<"                       TOTAL PRICE          :"<<total_amount<<endl;
    cout<<"------------------------------------------------------------------------------------"<<endl;


}
void myflipcart::shiporders()
{
    int id;
    int phno;
    int status=0;
    int i=0,j=0;
    int ch;
    cout<<endl;
    cout<<"Choose Product to Ship on given address\n";
    displayorders();
    while(status==0)
    {
        cout<<"Order Id to Ship to given address\n";
        cin>>id;
        for(i=1;i<=ord1;i++)
        {
            if(ord[i]->orderid==id)
            {
                ord[i]->displayorder();
                cout<<"Enter:\n1. Ship to address \n2. Cancel the order\n3. Exit\n";
                cin>>ch;
                if(ch==1)
                {
                    ord[i]->signal=1;
                    cout<<"The order will be handled to shipment process\n";
                }
                else if(ch==2)
                {
                    ord[i]->signal=2;
                    cout<<"The order will be canceled";
                    cout<<endl;
                }
                else if(ch==3)
                {
                    i=100000;
                    break;
                }
            }
        }
        cout<<endl;
        cout<<"Enter\n1 to go back\n0 to continue";
        cin>>status;
    }
}
void myflipcart:: displaycustomer()
{

    cout<<"                             The CUSTOMER in the shop are                              "<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"Serial No\tCUSTOMER_Id\tCUSTOMER_NAME\tPhone Number\tCOUPOUN"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    for(int i=1;i<=customer::customer_count;i++)
    {   cout<<i<<"\t\t";
        cust[i]->printcustomerdetails();
        cout<<endl;
    }
}
void myflipcart::displaysellers()
{
    cout<<"                             The Sellers in the shop are                              "<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"Serial No\tSeller Id\tSeller Name\tPhone Number"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    for(int i=1;i<=sellers::count1;i++)
    {
        cout<<i<<"\t\t";
        seller[i]->display();
    }
}
void myflipcart::displaycatalog()
{
    cout<<"The items in the catalog are: "<<endl;

       try
       {
        c.displaycatalog();
       }

    catch(exception& m)
    {
        cout<<m.what()<<endl;
    }
}
void myflipcart:: shoplogin()
{
    cout<<"-----------------------------------------Myflipcart-------------------------------------------------------\n";
    int status=0;
    int ch;
    while(status==0)
    {
        cout<<"Press:\n1. Display Customers\n2. Display Sellers\n3. Display Orders\n4. Display Catalog\n5. Ship Orders\n6. Exit\n";
        cout<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                displaycustomer();
                break;
            case 2:
                displaysellers();
                break;
            case 3:
                displayorders();
                break;
            case 4:
                try{
               displaycatalog();
                }
                catch(exception& p)
                {
                    cout<<p.what();
                }
                break;
            case 5:
                shiporders();
                break;
            case 6:
                cout<<"Shop logged out successfully";
                getch();
                status=1;
                break;
            default:
                printf("Wrong Choice.... Please Try again\n");
        }
    }
}
int orders::totalorders=0;
int customer::customer_count=0;
int sellers::count1=0;
int items::totalitems=0;
int electrical::ecto=0;
int fashion::fash=10;
int food::fo=20;
int subscribedcustomers::sub=0;
int normalcustomers::normal=0;
int main()
{
    cout<<"Welcome\n"<<endl;
    myflipcart m;
    m.open();
}



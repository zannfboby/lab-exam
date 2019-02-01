#include<bits/stdc++.h>

using namespace std;

class BookStore;

class Book
{
    string book_name, writer_name, category;
    double price;
    int quantity = 0;
public:
    Book() {}
    Book(string book_name, string writer_name, string category, double price, int quantity)
    {
        book_name = book_name;
        writer_name = writer_name;
        category = category;
        price = price;
        quantity += quantity;
    }
    void getBookDetails()
    {
        cout<<".....Book Information....."<<endl;
        cout<<"Book name: "<<book_name<<endl;
        cout<<"Writer name: "<<writer_name<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Category: "<<category<<endl;
        cout<<"Quantity: "<<quantity<<endl;
    }
    double getPrice(int x)
    {
        return price;
    }
    double getQuantity(int x)
    {
        return quantity;
    }
    void setQuantity(int x)
    {
        quantity += x;
    }
    friend double selectBook( BookStore store );
};

class Customer
{
    string name, date_of_birth;
    double bill = 0;
    string customer_number;
    vector<int> book_numbers;
public:
    Customer() {}
    Customer(string name,string dob, string customer_number)
    {
        name = name;
        date_of_birth = dob;
        customer_number = customer_number;
    }
    double getBill()
    {
        return bill;
    }
    string getID()
    {
        return customer_number;
    }
    void getCustomerDetails()
    {
        cout<<".....Customer Information....."<<endl;
        cout<<"Customer Number: "<<customer_number<<endl;
        cout<<"Customer Name: "<<name<<endl;
        cout<<"Contact No: "<<date_of_birth<<endl;
        cout<<"Due: "<<bill<<endl;
    }
    void clearBill()
    {
        bill = 0;
    }
    void setBill(double x)
    {
        bill += x;
    }
};


class BookStore
{
    vector<Customer> customers;
    vector<Book> books;

public:
    int isCustomer(string customer_id)
    {
        int i;
        for(i = 0; i < customers.size(); i++)
        {
            cout<<customers[i].getID()<<endl;
            if(customers[i].getID() == customer_id)
            {
                return i;
            }
        }
        return -1;
    }

    friend double selectBook(BookStore store);

    void addCustomer(Customer c)
    {
        customers.push_back(c);
    }
    void setBill(int i, double x)
    {
        customers[i].setBill(x);
    }
    void addBook(Book b)
    {
        books.push_back(b);
    }
    Customer getCustomer(int i)
    {
        return customers[i];
    }
    void clearBill(int i)
    {
        customers[i].clearBill();
    }
};

double selectBook( BookStore store )
{
    double prices = 0;
    for(int i = 0; i < store.books.size(); i++)
    {
        int x;
        store.books[i].getBookDetails();
        cout<<"Enter 1 to buy book, 0 to ignore" ;
        cin>>x;
        if(x==1)
            prices += store.books[i].price;
    }
    return prices;
}

int main()
{
    int option;
    BookStore bookStore;
    while(1)
    {
        cout <<"------------Book Store------------"<<endl;
        cout <<"Enter Menu"<<endl;
        cout <<"1  Input Customer in Bookstore"<<endl;
        cout <<"2  Input Book in Bookstore"<<endl;
        cout <<"3  Buy books"<<endl;
        cout <<"4  Get Customer data"<<endl;
        cout <<"5  Clear Payment"<<endl;
        cout <<"0  Exit"<<endl;

        cin>>option;

        switch(option)
        {
        case 0:
            return 0;
            break;
        case 1:
        {
            string name,dob,id;
            cout<<"Enter Customer Name: ";
            cin>>name;
            cout<<"Enter Customer Contact No: ";
            cin>>dob;
            cout<<"Enter Customer ID: ";
            cin>>id;
            Customer customer(name,dob,id);
            bookStore.addCustomer(customer);
        }
        case 2:
        {
            string name,writer,category;
            double price;
            int qty;
            cout<<"Enter book name: ";
            cin>>name;
            cout<<"Enter writer name: ";
            cin>>writer;
            cout<<"Enter Category: ";
            cin>>category;
            cout<<"Enter Price: ";
            cin>>price;
            cout<<"Enter quantity: ";
            cin>>qty;
            bookStore.addBook(Book(name,writer,category,price,qty));
            break;
        }
        case 3:
        {
            string id;
            cout<<"Enter customer number: ";
            cin>>id;
            int customer_id = bookStore.isCustomer(id);
            if(customer_id!=-1)
            {
                double bill = selectBook(bookStore);
                bookStore.setBill(customer_id, bill);
            }
            else
                cout<<"User Not Found!"<<endl;
            break;
        }
        case 4:
        {
            string id;
            cout<<"Please enter customer id: ";
            cin>>id;
            int customer_id = bookStore.isCustomer(id);
            if(customer_id==-1)
                cout<<"User Not Found!"<<endl;
            else
            {
                Customer c = bookStore.getCustomer(customer_id);
                c.getCustomerDetails();
            }
            //else
              //  cout<<"User Not Found!"<<endl;
            break;
        }
        case 5:
        {
            string id;
            cout<<"Please enter customer id: ";
            cin>>id;
            int customer_id = bookStore.isCustomer(id);
            if(customer_id==-1)
                cout<<"User Not Found!"<<endl;
            else
            {
                Customer c = bookStore.getCustomer(customer_id);
                cout<<"Payment Amount: " <<c.getBill()*.95 <<"Taka(5%% discount)" ;
                double amount;
                cin>>amount;
                if((c.getBill()*.95)==amount)
                {
                    bookStore.clearBill(customer_id);
                }
            }
            //else
              //  cout<<"User Not Found!"<<endl;
            break;
        }
        default:
                cin>>option;
        }
    }
    return 0;
}

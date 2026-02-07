#include <iostream>
#include <limits>
using namespace std;
int getValidInteger();

struct book
{
    string title;
    string author;
    int publicYear;
    int ISBN;
    book *prev;
    book *nex;
};

class library
{
    book *start = NULL;
    public:
    void insert(string x,string y, int z, int w){
        book * temp = new book;
        temp->title=x;
        temp->author=y;
        temp->publicYear = z;
        temp->ISBN= w;
        temp->prev = NULL;
        temp->nex = NULL;
        if (start == NULL)
        {
            start = temp;
        }
        else{
            book* cur= start;
            while(cur->nex != NULL){
                cur = cur->nex;
            }
            cur->nex = temp;
            temp->prev = cur;
            temp->nex = NULL;
        }
        
    }
    void search(int w)
    {
        book *cur = start;
        while (cur != NULL)
        {
            if(cur->ISBN == w){
                cout << cur->title << endl;
                cout<<cur->author<<endl;
                cout<<cur->publicYear<<endl;
                cout<<cur->ISBN<<endl;
            }
            cur = cur->nex;
        }
    }

    void modify(int w)
    {
        string x,y;
        int z;
        book *cur = start;
        while (cur != NULL)
        {
            if (cur->ISBN == w)
            {
                cout << "Enter new Title: ";
                cin >> x;
                cout << "Enter new Author: ";
                cin >> y;
                cout << "Enter new Year: ";
                cin >> z;
                cur->title = x;
                cur->author = y;
                cur->publicYear = z;
            }
            cur = cur->nex;
        }
    }
    void display(){
        book *cur = start;
        int count=0;
        cout<<"--All Books--\n";
        while (cur != NULL)
        {

            cout << cur->title << endl;
            cout << cur->author << endl;
            cout << cur->publicYear << endl;
            cout << cur->ISBN << endl;
            cout<<"-------------------------\n";
            cur = cur->nex;
            count++;
        }
        cout<<"Total books: "<<count<<endl;
    }
};
    void intro(){
        cout<<"--Library Management System--\n";
        cout << "1.Insert\n";
        cout<<"2.Search\n";
        cout << "3.Modiy\n";
        cout << "4.Display\n";
        cout << "5.Exit\n";
    }

int main(){
    library books;
    string title,author;
    int publicYear,ISBN,choice;

    while (true)
    {   
        intro();
        choice = getValidInteger();
        switch (choice)
        {
            case 1:
                cout << "Enter Title: ";
                cin >>title;
                cout << "Enter Author: ";
                cin >> author;
                cout << "Enter Year: ";
                cin >> publicYear;
                cout << "Enter ISBN: ";
                cin >> ISBN;
                books.insert(title,author,publicYear,ISBN);
                break;
            
                case 2:
                cout << "Enter ISBN: ";
                cin >> ISBN;
                books.search(ISBN);
                break;
                
                case 3:
                cout << "Enter ISBN: ";
                cin >> ISBN;
                books.modify(ISBN);
                break;
                case 4:
                books.display();
                break;
                case 5:
                    return 0;
                default:
                    cout<<"Invalid chsoice\n";
                    break;
        }
    }
}
// This Function is used to prevent infinite loop
int getValidInteger()
{
    int value;
    while (true)
    {
        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        else
        {
            cout << "Invalid input. Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
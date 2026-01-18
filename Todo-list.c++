#include <iostream>
#include <limits>
using namespace std;
int getValidInteger();

struct node
{
    string task;
    node *link;
};

class App
{
    node *start = NULL;

public:

    // Insertion
    void create(string x)
    {
        node *temp = new node;
        temp->task = x;
        temp->link = NULL;

        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            node *cur = start;
            while (cur->link != NULL)
            {
                cur = cur->link;
            }
            cur->link = temp;
        }
    }
     
    // Delete Function
    void delete_list(string x)
    {
        if (start == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        // If first node needs to be deleted
        if (start->task == x)
        {
            node *temp = start;
            start = start->link;
            delete temp;
            cout << "Deleted\n";
            return;
        }

        node *cur = start;
        node *prev = NULL;

        while (cur != NULL && cur->task != x)
        {
            prev = cur;
            cur = cur->link;
        }

        if (cur == NULL)
        {
            cout << "Not Found\n";
        }
        else
        {
            prev->link = cur->link;
            delete cur;
            cout << "Deleted\n";
        }
    }

    // Search Function
    void search(string x)
    {
        node *cur = start;
        while (cur != NULL)
        {
            if (cur->task == x)
            {
                cout << "Found\n";
                return;
            }
            cur = cur->link;
        }
        cout << "Not Found\n";
    }

    // Display All Function
    void display()
    {
        node *cur = start;

        if (start == NULL)
        {
            cout << "List is empty\n";
        }
        else{
            cout << "--- All The List ---\n";
            while (cur != NULL)
            {
                cout << cur->task << "\n";
                cur = cur->link;
            }
        }
        }
};

int main()
{
    int choice;
    App todolist;

    do
    {
        cout << "--TO DO LIST---\n";
        cout << "1. For Insertion\n";
        cout << "2. For Deleting\n";
        cout << "3. For Searching\n";
        cout << "4. To display all\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        choice = getValidInteger();

        switch (choice)
        {
        case 1:
        {
            string task;
            cout << "Enter your task: ";
            cin >> task;
            todolist.create(task);
            break;
        }
        case 2:
        {
            string task2;
            cout << "Enter your task you want to delete: ";
            cin >> task2;
            todolist.delete_list(task2);
            break;
        }
        case 3:
        {
            string task3;
            cout << "Enter the task you wanted to find: ";
            cin >> task3;
            todolist.search(task3);
            break;
        }
        case 4:
            todolist.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!\n";
            break;
        }
        cout << "\n";
    } while (true);

    return 0;
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
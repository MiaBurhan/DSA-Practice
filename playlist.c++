#include <iostream>
#include <limits>
using namespace std;
int getValidInteger(); // This Function is used to prevent infinite loop

struct song
{
    int ID;
    string title, artistName,duration;
    song *prev;
    song *nex;
};
class playlist{
    private:
    song* start = NULL;
    public:
    void insert(int a, string b, string c , string d){
        song* temp = new song;
        temp->ID = a;
        temp->title = b;
        temp->artistName = c;
        temp->duration = d;
        
        if(start == NULL){
            start = temp;
            start->nex = start;
        }
        else{
            song *cur = start;
            while (cur->nex != start)
            {
                cur = cur->nex;
            }
            cur->nex = temp;
            temp->prev = cur;
            temp->nex = start;
        }
    }
    void search(string title){
        if(start == NULL){
            cout << "Playlist is empty." << endl;
            return;
        }
        song *cur = start;
        do
        {
            if(cur->title == title){
                cout << cur->ID << endl;
                cout << cur->title << endl;
                cout << cur->artistName << endl;
                cout << cur->duration << endl;
                cout<<"This song is now playing........"<<endl;
            }
            cur = cur->nex;
        }
        while (cur!= start);
    }
    void modify(string title)
    {
        if(start == NULL){
            cout << "Playlist is empty." << endl;
            return;
        }
        int a;
        string b ,c;
        song *cur = start;
        do
        {
            if (cur->title == title)
            {
                cout<<"Enter new ID: ";
                a = getValidInteger();
                cout << "Enter new Title: ";
                cin >> b;
                cout << "Enter new Artist name: ";
                cin >> c;
                cur->ID = a;
                cur->title = b;
                cur->artistName = c;
            }
            cur = cur->nex;
        } while (cur!= start);
    }

    void playNextAndprev(){
        if(start == NULL){
            cout << "Playlist is empty." << endl;
            return;
        }
        song *cur = start;
        song *tail = start;
        do
        {
            tail=tail->nex;
        } while (tail->nex!= start);
        
        cout <<"Current song is: "<< cur->title << endl;
        cout << "Press 1 to play next song\n";
        cout<<"Press 2 to play previous song\n";
        int choice;
        cin>>choice;
        if(choice ==1 ){
            cur= cur->nex;
        }
        else if(choice ==2){
            if(cur == start){
                cur = tail;
            }
            else{
                cur = cur->prev;
            }
        }
        cout<<"Now playing "<<cur->title<<"....."<<endl;
    }

    void display(){
        if(start == NULL){
            cout << "Playlist is empty." << endl;
            return;
        }
        song *cur = start;
        int count= 0;
        do
        {
            cout<<cur->ID<<endl;
            cout << cur->title << endl;
            cout << cur->artistName << endl;
            cout << cur->duration << endl;
            cout<<"-----------------------\n";
            cur = cur->nex;
            count++;
        } while (cur!= start);
        cout<<"Total Number of Songs are "<<count<<endl;
    }
};
void intro(){
    cout << "---Welcome to Songs Playlist---" << endl;
    cout << "1. Insert a new song\n";
    cout << "2. Search a song\n";
    cout << "3. Modify a song\n";
    cout << "4. Move to next or Previous song\n";
    cout << "5. Display all songs in the playlist\n";
}

int main() {
   playlist play;
   play.insert(12, "Song no 1", "James", "3 minutes");
   play.insert(21, "Song no 2", "James", "4 minutes");
   play.insert(33, "Song no 3", "James", "5 minutes");
   play.insert(43, "Song no 4", "James", "2.5 minutes");
   play.insert(54, "Song no 5", "James", "7 minutes");
   play.insert(61, "Song no 6", "James", "5 minutes");
   play.insert(71, "Song no 7", "James", "6 minutes");

    int choice, a;
    string b,c,d;
    while(true){
        intro();
        cout << "Enter choice: ";
        choice = getValidInteger();
        switch (choice)
        {
        case 1:
            cout << "Enter ID: ";
            a = getValidInteger();
            cout << "Enter Title: ";
            cin >> b;
            cout << "Enter Artist: ";
            cin >> c;
            cout << "Enter Duration: ";
            cin >> d;
            play.insert(a, b, c, d);
            break;
        case 2:
            cout << "Enter title to search: ";
            cin >> b;
            play.search(b);
            break;
        case 3:
            cout << "Enter title to modify: ";
            cin >> b;
            play.modify(b);
            break;
        case 4:
            play.playNextAndprev();
            break;
        case 5:
            play.display();
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }
        cout << "Do you want to continue? (1=yes 0=no): ";
        int cont;
        cont = getValidInteger();
        if(cont == 0){
            break;
        } 
    }
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
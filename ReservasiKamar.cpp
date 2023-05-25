#include <iostream>
using namespace std;

class Room 
{
    private:
        struct Node
        {
            int id, date;
            string name, roomtype;
            Node* next = NULL;
        };
    public:
        Node* head = NULL;
        void menu();
        void insert();
        void search();
        void update();
        void del();
        void show();
        void sort();
};

void Room::menu()
{
    int choice;
    cout <<"\n";
    cout <<"\n\t\t ------------------------------------";
    cout <<"\n\t\t| Welcome to Hotel Management System |";
    cout <<"\n\t\t ------------------------------------\n\n";
    cout <<"\n\t\t -----------------------------";
    cout <<"\n\t\t|       Reservation Room      |";
    cout <<"\n\t\t -----------------------------";
    cout <<"\n\nNo      Functions                         Description" <<endl;
    cout <<"\n1\tAllocate Room\t\t\tInsert New Room";
    cout <<"\n2\tSearch Room\t\t\tSearch Room with RoomID";
    cout <<"\n3\tUpdate Room\t\t\tUpdate Room ";
    cout <<"\n4\tDelete Room\t\t\tDelete Room with RoomID";
    cout <<"\n5\tShow Room \t\t\tShow Room that (We Added)";
    cout <<"\n6\tExit" <<endl;

    cout << "Enter Your Choice" <<endl;
    cin >> choice;
    switch(choice)
    {
        case 1:
            insert();
            menu();
        case 2:
            search();
            menu();
        case 3:
            update();
            menu();
        case 4:
            del();
            menu();
        case 5:
            sort();
            show();
            menu(); 
        case 6:
            cout << "\nThank You for Using Our Service" << endl;
            exit(0);
        default:
            cout << "Invalid Choice" <<endl;
            menu();
    }

}

void Room::insert() {
    Node* temp = new Node;
    cout << "Enter Room ID (1-100): ";
    cin >> temp->id;

    // Check if the ID already exists
    Node* current = head;
    while (current != nullptr) {
        if (current->id == temp->id) {
            cout << "Room ID already exists. Please enter a different ID.\n";
            delete temp;
            return;
        }
        current = current->next;
    }
    if (temp->id < 1 || temp->id > 100) {
        cout << "Invalid input. ID must be between 1-100.\n";
        delete temp;
        return;
    }
    cout << "Enter Allocate Date (1-30): ";
    cin >> temp->date;
    if (temp->date < 1 || temp->date > 30) {
        cout << "Invalid input. Date must be between 1-30.\n";
        delete temp;
        return;
    }
    cout << "Enter Customer Name (max 30 characters): ";
    cin.ignore();
    getline(cin, temp->name);
    if (temp->name.length() > 30) {
        cout << "Invalid input. Name must be less than or equal to 30 characters.\n";
        delete temp;
        return;
    }
    cout <<"Enter Room Type (Single/Double): ";
    cin >> temp->roomtype;
    temp->next = head;
    head = temp;
    cout <<"\n\n\t New Room Inserted Successfully\n";
}

void Room::search()
{
    cout <<"\n\t\t -------------------------------";
    cout <<"\n\t\t|          Search Room          |";
    cout <<"\n\t\t -------------------------------";
    int t_id;
    if(head == NULL)
    {
        cout <<"\n\nLinked List is Empty\n";
    }
    else
    {
        cout <<"\n\nRoom ID to be Searched: ";
        cin >> t_id;
        Node* ptr = head;
        bool found = false;
        while(ptr != NULL)
        {
            if(t_id == ptr->id)
            {
                cout <<"\nRoom ID: " <<ptr->id;
                cout <<"\nAllocate Date: " <<ptr->date;
                cout <<"\nCustomer Name: " <<ptr->name;
                cout <<"\nRoom Type: " <<ptr->roomtype;
                found = true;
                break;
            }
            ptr = ptr->next;
        }
        if (!found) {
            cout << "Room ID not found.\n";
        }
    }
}


void Room::update()
{
    cout <<"\n\t\t -------------------------------";
    cout <<"\n\t\t|          Update Room          |";
    cout <<"\n\t\t -------------------------------";
    int t_id;
    if(head == NULL)
    {
        cout <<"\n\nLinked List is Empty";
    }
    else
    {
        cout <<"\n\nRoom ID to be Updated: ";
        cin >> t_id;
        Node *ptr = head;
        bool found = false;
        while(ptr != NULL)
        {
            if(t_id == ptr->id)
            {
                cout <<"\n\nRoom ID: " <<ptr->id;
                cout <<"\nAllocate Date: " <<ptr->date;
                cout <<"\nCustomer Name: " <<ptr->name;
                cout <<"\nRoom Type: " <<ptr->roomtype;

                cout <<"\n\nEnter New Room ID: ";
                cin >> ptr->id;

                cout <<"Enter New Allocate Date: ";
                cin >> ptr->date;

                cout <<"Enter New Customer Name: ";
                cin >> ptr->name;

                cout <<"Enter New Room Type (Single/Double): ";
                cin >> ptr->roomtype;

                cout <<"\n\n\t Room Updated Successfully\n";
                found = true;
                break;
            }
            ptr = ptr->next;
        }
        if (!found) {
            cout << "Room ID not found.\n";
        }
    }
}

void Room::del()
{
    cout <<"\n\t\t -------------------------------";
    cout <<"\n\t\t|          Delete Room          |";
    cout <<"\n\t\t -------------------------------";
    int t_id;
    if(head == NULL)
    {
        cout <<"\n\nLinked List is Empty";
    }
    else
    {
        cout <<"\n\nRoom ID to be Deleted: ";
        cin >> t_id;
        bool found = false;
        if(t_id == head->id)
        {
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout <<"\n\n\t Room Deleted Successfully\n";
        }
        else
        {
            Node* pre = head;
            Node* ptr = head;
            while(ptr != NULL)
            {
                if(t_id == ptr->id)
                {
                    pre->next = ptr->next;
                    delete ptr;
                    cout <<"\n\n\t Room Deleted Successfully\n";
                    found = true;
                    break;
                }
                pre = ptr;
                ptr = ptr->next;
            }
            if (!found) {
            cout << "Room ID not found.\n";
        }
        }
    }
}

void Room::show()
{
    Node* ptr = head;
    if(ptr == NULL)
    {
        cout << "\nLinked List is Empty";
    }
    else
    {
        cout << "\n\nList of Allocated Rooms (Sorted by Room ID)";
        while(ptr != NULL)
        {
            cout <<"\n\nRoom ID: " <<ptr->id;
            cout <<"\nAllocate Date: " <<ptr->date;
            cout <<"\nCustomer Name: " <<ptr->name;
            cout <<"\nRoom Type: " <<ptr->roomtype;
            ptr = ptr->next;
        }
    }
}


void Room::sort()
{
    cout <<"\n\t\t -------------------------------";
    cout <<"\n\t\t|          Show Room            |";
    cout <<"\n\t\t -------------------------------";
    if(head == NULL)
    {
        cout <<"\n\nLinked List is Empty";
        menu();
    }
    int count = 0, t_date, t_id;
    string t_name, t_roomtype;
    Node* ptr = head;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    for(int i = 1; i <= count; i++)
    {
        Node *ptr = head;
        for(int j = 1; j < count; j++)
        {
            if(ptr->id > ptr->next->id)
            {
                t_id = ptr->id;
                t_date = ptr->date;
                t_name = ptr->name;
                t_roomtype = ptr->roomtype;
                //Save Date Into Current Node
                ptr->id = ptr->next->id;
                ptr->date = ptr->next->date;
                ptr->name = ptr->next->name;
                ptr->roomtype = ptr->next->roomtype;
                //Save Data Into Next Node
                ptr->next->id = t_id;
                ptr->next->date = t_date;
                ptr->next->name = t_name;
                ptr->next->roomtype = t_roomtype;
            }
            ptr = ptr->next;
        }
    }
}


int main()
{
    Room h;
    h.menu();

    return 0;
}

// Binary Tree
#include <iostream>
#include <cctype>    // tolower
#include <algorithm> // transform
using namespace std;

enum Position
{
    MANAGER,
    ASSISTANT_MANAGER,
    SUPERVISOR,
    STAFF,
    INTERN
};

struct Employee
{
    string firstName, lastName;
    Position position;
    int gaji;
    Employee *left;
    Employee *right;

    Employee(string firstName, string lastName, Position position)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->position = position;
        this->gaji = calculateGaji(position);
        this->left = nullptr;
        this->right = nullptr;
    }

    int calculateGaji(Position position)
    {
        switch (position)
        {
        case MANAGER:
            return 10000;
        case ASSISTANT_MANAGER:
            return 8000;
        case SUPERVISOR:
            return 6000;
        case STAFF:
            return 4000;
        case INTERN:
            return 2000;
        default:
            return 0;
        }
    }
};

class BinaryTree
{
public:
    Employee *root;
    bool isEmployeeExist;

    BinaryTree()
    {
        root = nullptr;
        isEmployeeExist = false;
    }

    Employee *insert(Employee *employee, string firstName, string lastName, Position position)
    {
        if (employee == nullptr)
        {
            isEmployeeExist = true;
            return new Employee(firstName, lastName, position);
        }
        if (firstName < employee->firstName)
        {
            employee->left = insert(employee->left, firstName, lastName, position);
        }
        else if (firstName > employee->firstName)
        {
            employee->right = insert(employee->right, firstName, lastName, position);
        }
        else
        {
            if (lastName < employee->lastName)
            {
                employee->left = insert(employee->left, firstName, lastName, position);
            }
            else if (lastName > employee->lastName)
            {
                employee->right = insert(employee->right, firstName, lastName, position);
            }
        }
        return employee;
    }

    Employee *search(Employee *employee, string firstName, string lastName)
    {
        if (employee == nullptr)
        {
            return nullptr;
        }
        if (toLowerCase(employee->firstName) == toLowerCase(firstName) && toLowerCase(employee->lastName) == toLowerCase(lastName))
        {
            return employee;
        }
        else if (toLowerCase(firstName) < toLowerCase(employee->firstName))
        {
            return search(employee->left, firstName, lastName);
        }
        else if (toLowerCase(firstName) > toLowerCase(employee->firstName))
        {
            return search(employee->right, firstName, lastName);
        }
        else
        {
            if (toLowerCase(lastName) < toLowerCase(employee->lastName))
            {
                return search(employee->left, firstName, lastName);
            }
            else if (toLowerCase(lastName) > toLowerCase(employee->lastName))
            {
                return search(employee->right, firstName, lastName);
            }
        }
        return nullptr;
    }

    string getPositionText(Position position)
    {
        switch (position)
        {
        case MANAGER:
            return "Manager";
        case ASSISTANT_MANAGER:
            return "Assistant Manager";
        case SUPERVISOR:
            return "Supervisor";
        case STAFF:
            return "Staff";
        case INTERN:
            return "Intern";
        default:
            return "";
        }
    }

    void inorderTraversal(Employee *employee)
    {
        if (employee != nullptr)
        {
            inorderTraversal(employee->left);

            cout << "First Name: " << capitalize(employee->firstName) << endl;
            cout << "Last Name: " << capitalize(employee->lastName) << endl;
            cout << "Posisi: " << getPositionText(employee->position) << endl;
            cout << "Salary: " << employee->gaji << endl;
            cout << "=========================" << endl;

            inorderTraversal(employee->right);
        }
    }

    string toLowerCase(string str)
    {
        transform(str.begin(), str.end(), str.begin(), [](unsigned char c)
                  { return tolower(c); });
        return str;
    }

    string capitalize(string str)
    {
        if (!str.empty())
        {
            str[0] = toupper(str[0]);
            for (size_t i = 1; i < str.length(); i++)
            {
                if (str[i - 1] == ' ')
                {
                    str[i] = toupper(str[i]);
                }
                else
                {
                    str[i] = tolower(str[i]);
                }
            }
        }
        return str;
    }

    Employee *deleteEmployee(Employee *employee, string firstName, string lastName)
    {
        bool isDeleted;

        if (employee == nullptr)
        {
            cout << "Tidak ada data employee untuk dihapus." << endl;
            return employee;
        }
        if (firstName < employee->firstName)
        {
            employee->left = deleteEmployee(employee->left, firstName, lastName);
        }
        else if (firstName > employee->firstName)
        {
            employee->right = deleteEmployee(employee->right, firstName, lastName);
        }
        else
        {
            if (employee->lastName == lastName)
            {
                if (employee->left == nullptr && employee->right == nullptr)
                {
                    delete employee;
                    return nullptr;
                }
                else if (employee->left == nullptr)
                {
                    Employee *temp = employee->right;
                    delete employee;
                    return temp;
                }
                else if (employee->right == nullptr)
                {
                    Employee *temp = employee->left;
                    delete employee;
                    return temp;
                }
                Employee *temp = minValueNode(employee->right);

                employee->firstName = temp->firstName;
                employee->lastName = temp->lastName;
                employee->position = temp->position;
                employee->gaji = temp->gaji;
                employee->right = deleteEmployee(employee->right, temp->firstName, temp->lastName);
            }
            else
            {
                employee->left = deleteEmployee(employee->left, firstName, lastName);
            }
        }

        isDeleted = true;
        return employee;
    }

    void deleteEmployeeWrapper()
    {
        if (!isEmployeeExist)
        {
            cout << "\nTidak ada data employee." << endl;
            return;
        }

        string firstName, lastName;
        cout << "\nMasukkan first name employee yang ingin dihapus: ";
        cin.ignore();
        getline(cin, firstName);
        cout << "Masukkan last name employee yang ingin dihapus: ";
        getline(cin, lastName);

        Employee *employee = search(root, firstName, lastName);
        if (employee == nullptr)
        {
            cout << "\nData employee tidak ditemukan." << endl;
            return;
        }

        root = deleteEmployee(root, firstName, lastName);
        cout << "Employee berhasil dihapus." << endl;
        isEmployeeExist = (root != nullptr);
    }

    Employee *minValueNode(Employee *employee)
    {
        Employee *current = employee;
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }
};

int main()
{
    BinaryTree tree;
    bool isEmployeeExist = false;

    while (true)
    {
        cout << "\n===================================" << endl;
        cout << "Manajemen Sumber Daya Manusia Hotel" << endl;
        cout << "===================================" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Search Employee" << endl;
        cout << "3. Inorder Traversal Based on Name" << endl;
        cout << "4. Delete Employee" << endl;
        cout << "5. Exit" << endl;
        cout << "===================================" << endl;

        cout << "Masukkan pilihan anda: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string firstName, lastName;
            int posisi;

            cout << "\nFirst Name: ";
            cin.ignore();
            getline(cin, firstName);
            cout << "Last Name: ";
            getline(cin, lastName);
            cout << "\n1. Manager" << endl;
            cout << "2. Assistant Manager" << endl;
            cout << "3. Supervisor" << endl;
            cout << "4. Staff" << endl;
            cout << "5. Intern" << endl;
            cout << "\nPosisi: ";
            cin >> posisi;

            Position position;

            switch (posisi)
            {
            case 1:
                position = MANAGER;
                break;
            case 2:
                position = ASSISTANT_MANAGER;
                break;
            case 3:
                position = SUPERVISOR;
                break;
            case 4:
                position = STAFF;
                break;
            case 5:
                position = INTERN;
                break;
            default:
                cout << "Posisi tidak valid. Employee tidak ditambahkan." << endl;
                continue;
            }

            tree.root = tree.insert(tree.root, firstName, lastName, position);
            cout << "\nEmployee berhasil ditambahkan." << endl;

            isEmployeeExist = true;
            break;
        }
        case 2:
        {
            if (!isEmployeeExist)
            {
                cout << "\nTidak ada data employee." << endl;
                continue;
            }

            string firstName, lastName;
            cout << "\nMasukkan first name employee yang ingin dicari: ";
            cin.ignore();
            getline(cin, firstName);
            cout << "Masukkan last name employee yang ingin dicari: ";
            getline(cin, lastName);

            Employee *employee = tree.search(tree.root, firstName, lastName);
            if (employee == nullptr)
            {
                cout << "\nEmployee tidak ditemukan." << endl;
            }
            else
            {
                cout << "\nFirst Name: " << tree.capitalize(employee->firstName) << endl;
                cout << "Last Name: " << tree.capitalize(employee->lastName) << endl;
                cout << "Posisi: " << tree.getPositionText(employee->position) << endl;
                cout << "Salary: " << employee->gaji << endl;
            }
            break;
        }
        case 3:
        {
            if (!isEmployeeExist)
            {
                cout << "\nTidak ada data employee." << endl;
                continue;
            }

            cout << "\n=== Inorder Traversal ===" << endl;
            tree.inorderTraversal(tree.root);
            break;
        }
        case 4:
        {
            tree.deleteEmployeeWrapper();
            break;
        }
        case 5:
            cout << "\nExiting program...\n"
                 << endl;
            return 0;
        default:
            cout << "\nPilihan tidak valid. Tolong pilih opsi kembali." << endl;
            break;
        }
    }

    return 0;
}
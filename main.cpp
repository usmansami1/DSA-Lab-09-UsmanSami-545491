// UsmanSami 545491 CS-D
// Linked list suits the student records application as its dynamic and easy to implement
// It also allows easy traversing and searching
// Stack is beneficial for storing search history due to its principle of LIFO

#include <iostream>
using namespace std;

struct studentRecord
{
    int rollNumber;
    string name;
    studentRecord *next;
};
studentRecord *head = nullptr;
studentRecord *curr = nullptr;
studentRecord *temp = nullptr;

bool isStudentRecordEmpty()
{
    return head == nullptr;
}
void addStudent()
{
    int rollNumber;
    string name;

    studentRecord *n = new studentRecord();

    bool unique = true;

    do
    {
        unique = true;

        cout << "Enter roll number: ";
        cin >> rollNumber;

        curr = head;

        while (curr != nullptr)
        {
            if (curr->rollNumber == rollNumber)
            {
                unique = false;
                cout << "Duplicate roll number detected!" << endl;
                cout << "Try again" << endl;
                break;
            }

            curr = curr->next;
        }

    } while (!unique);

    cout << "Enter name: ";
    cin >> name;

    n->rollNumber = rollNumber;
    n->name = name;
    n->next = nullptr;

    if (head == nullptr)
    {
        head = n;
    }
    else
    {
        curr = head;

        while (curr->next != nullptr)
        {
            curr = curr->next;
        }

        curr->next = n;
    }

    cout << "Added " << name << " to the student record." << endl;
}

bool searchStudent(int rollNumber)
{

    curr = head;
    while (curr != nullptr)
    {
        if (curr->rollNumber == rollNumber)
        {
            cout << "Student details are : \n"
                 << curr->rollNumber << " | " << curr->name << endl;
            return true;
        }
        curr = curr->next;
    }
    cout << "Search failed\nStudent record does not exist!" << endl;
    return false;
}

void displayStudentRecord()
{
    if (head == nullptr)
    {
        cout << "Student record is empty!" << endl;
    }
    else
    {
        cout << "Student record is : " << endl;
        curr = head;
        while (curr != nullptr)
        {
            cout << curr->rollNumber << " | " << curr->name << endl;
            curr = curr->next;
        }
        cout << endl;
    }
}
void clearStudentRecord()
{
    if (head == nullptr)
    {
        cout << "Student record is already empty!" << endl;
    }
    else
    {
        curr = head;
        while (curr != nullptr)
        {
            temp = curr;
            curr = curr->next;
            delete temp;
        }
        head = nullptr;
        cout << "Student record is cleared!" << endl;
    }
}

class LinkedStack
{
    struct node
    {
        int rollNumber;
        node *next;
    };

    node *top = nullptr;

public:
    bool IsEmpty()
    {
        return top == nullptr;
    }

    void Push(int value)
    {
        node *n = new node;
        n->rollNumber = value;
        n->next = top;
        top = n;
    }

    void Pop()
    {
        if (IsEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        node *temp = top;
        cout << "Removed: " << temp->rollNumber << endl;
        top = top->next;
        delete temp;
    }

    void Peek()
    {
        cout << top->rollNumber << endl;
    }

    void ClearStack()
    {
        while (!IsEmpty())
        {
            node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    LinkedStack s;
    int choice = 0;
    while (choice != 5)
    {
        cout << "--------------------------------------------------" << endl;
        cout << "===== Student Records Application =====" << endl;
        cout << "1) Add a student." << endl;
        cout << "2) Search student by roll number." << endl;
        cout << "3) Display student record." << endl;
        cout << "4) Display most recent history search entry." << endl;
        cout << "5) Exit." << endl;
        cout << "--------------------------------------------------" << endl;

        cout << "Please enter a choice:";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            if (isStudentRecordEmpty())
            {
                cout << "Student record is empty!" << endl;
            }
            else
            {
                cout << "Enter roll number of student to be searched: ";
                int rollNumber;
                cin >> rollNumber;
                bool valid;
                valid = searchStudent(rollNumber);
                if (valid)
                {
                    s.Push(rollNumber);
                }
            }
            break;
        case 3:
            displayStudentRecord();
            break;
        case 4:
            if (s.IsEmpty())
            {
                cout << "Student search history does not exist!" << endl;
            }
            else
            {
                cout << "Most recent roll number searched is : ";
                s.Peek();
                char history;
                do
                {
                    cout << "Do you want to remove this history? Y/N" << endl;
                    cin >> history;
                    if (history == 'Y')
                    {
                        s.Pop();
                        break;
                    }
                    else if (history == 'N')
                    {
                        cout << "Recent history is not deleted!" << endl;
                        break;
                    }
                    else
                    {
                        cout << "Enter valid choice!" << endl;
                    }
                } while (true);
            }
            break;
        case 5:
            clearStudentRecord();
            s.ClearStack();
            cout << "Exiting the application." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}
// worst case time complexity of adding and searching for a student is O(n)

// During searching, curr pointer starts from the head and travels down to the end of list 
// at the same time it compares values to find out the student

// for this task BST can also be used and may be more efficient but its not that beneficial 
// for sequential inputs and we have to consider many things to get the efficiency
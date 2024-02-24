#include <iostream>

using namespace std;

template <typename T>
struct Node
{
    T data[5];
    Node* next = NULL;
};

template <typename T>
class sublinkedlist;

class Stack
{
private:
    string steps[5];
    size_t m_size;
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "The step number  ( " << i + 1 << " ): " << endl;
            getline(cin >> ws, steps[i]);
            top++;
        }
    }

    void print()
    {
        for (int i = 0; i< m_size; i++)
        {
            cout << steps[i] << " " << endl;
        }
    }

    bool isFull()
    {
        return top == m_size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty can't remove element" << endl;
        }
        else
        {
            top--;
        }
    }

    // Overloading << operator for Stack
    friend ostream &operator<<(ostream &os, const Stack &Stack);
};

// Overloaded << operator for Stack
ostream &operator<<(ostream &os, const Stack &Stack)
{
    for (int i = Stack.top; i >= 0; i--)
    {
        os << Stack.steps[i] << " ";
    }
    return os;
}

template <typename T>
class sublinkedlist
{
private:
    Node<T> *head;
    Node<T> *lastcreated;
    size_t m_size;

public:
    sublinkedlist() : head(NULL), m_size(0), lastcreated(NULL) {}

    ~sublinkedlist()
    {
        clear();
    }

    void insertAsQueue(const T &val)
    {
        if (head == NULL)
        {
            Node<T> *newnode = new Node<T>;
            head = newnode;
            lastcreated = newnode;
            (lastcreated->data[m_size]) = val;
            m_size++;
        }
        else
        {
            if ((m_size % 5) != 0)
            {
                (lastcreated->data[(m_size % 5)]) = val;
                m_size++;
            }
            else
            {
                Node<T> *newnode = new Node<T>;
                lastcreated = newnode;
                Node<T> *curr = head;
                while (curr->next)
                {
                    curr = curr->next;
                }
                curr->next = newnode;
                (lastcreated->data[(m_size % 5)]) = val;
                m_size++;
            }
        }
    }

    void popFront()
    {
        if (head == NULL)
        {
            cout << "Sorry you don't have any element to delete !!!!" << endl;
        }
        else if (((m_size - 1) % 5) == 0)
        {
            Node<T> *curr = head;
            while (curr->next->next)
            {
                for (int i = 0; i < 4; i++)
                {
                    curr->data[i] = curr->data[i + 1];
                }
                curr->data[4] = curr->next->data[0];
                curr = curr->next;
            }
            for (int i = 0; i < 4; i++)
            {
                curr->data[i] = curr->data[i + 1];
            }
            curr->data[4] = curr->next->data[0];
            delete curr->next;
            curr->next = NULL;
            lastcreated = curr;
        }
        else
        {
            Node<T> *curr = head;
            while (curr->next)
            {
                for (int i = 0; i < 4; i++)
                {
                    curr->data[i] = curr->data[i + 1];
                }
                curr->data[4] = curr->next->data[0];
                curr = curr->next;
            }
            for (int i = 0; i < 4; i++)
            {
                curr->data[i] = curr->data[i + 1];
            }
        }
        m_size--;
    }

    void get_size()
    {
        cout << "The size: " << m_size << endl;
    }

    void display()
    {
        int n = m_size;
        Node<T> *curr = head;
        while (curr != NULL)
        {
            for (int i = 0; i < 5; i++)
            {
                if (n)
                {
                    cout << curr->data[i] << " ";
                    n--;
                }
            }
            cout << endl;
            curr = curr->next;
        }
    }

    void clear()
    {
        while (head != NULL)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main()
{
    int i = 0;
    Stack ob[i];
    sublinkedlist <Stack> o1;


    int c;
    do
    {
        cout << "### Smart Factory Manufacturing ###" << endl;
        cout << "1.add new product." << endl;
        cout << "2.delete product." << endl;
        cout << "3.print all products." << endl;
        cout << "enter your selection: ";
        cin >> c;


        switch(c)
        {
        case 1:
            cout << "Enter the five steps for your product,please " << endl;
            ob[i].push();
            o1.insertAsQueue(ob[i]);
            i++;
            break;
        case 2:
            o1.popFront();
            i--;
            cout << "DELETED !!!" << endl;
            break;
        case 3:
            o1.display();
            break;
        default:
            cout << "invalid choice, please try again " << endl;
            break;
        }

    }while (c != 0);

    return 0;
}

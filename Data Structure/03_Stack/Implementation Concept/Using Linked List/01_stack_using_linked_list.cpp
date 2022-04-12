/*stack using linked list*/
#include <iostream>
using namespace std;

class list
{
    int data;
    class list *next;

    /*returns 1 if empty else 0*/
    int isEmpty(list *top)
    {
        if (top == NULL)
            return 1;
        return 0;
    }

    /*create a node of list type on given address*/
    void createNode(list *ptr)
    {
        cout << "write data (number):" << endl;
        cin >> ptr->data;
    }

public:
    void display(list *top)
    {
        if (isEmpty(top))
            cout << "Stack is empty. Underflow." << endl;
        else
        {
            // we have to show only. So, we can't change the current poiting position of top i.e top of stack
            list *temp = top;
            while (temp != NULL)
            {
                cout << temp->data << endl;
                temp = temp->next;
            }
        }
    }

    list *pop(list *top)
    {
        if (isEmpty(top))
            puts("Stack is empty. Underflow.");
        else
        {
            // we have to free the space other we can simply write top=top->next
            list *temp; // help in freeing the memory
            temp = top;
            cout << "Removed data is " << temp->data << endl;
            top = top->next; // poiting to node available below it.
            free(temp);
        }
        return top;
    }

    list *push(list *top)
    {
        list *ptr = (list *)malloc(sizeof(list));
        if (ptr == NULL) // no memory allocated
            cout << "stack overflow." << endl;
        else
        {
            createNode(ptr);
            ptr->next = top;
            top = ptr; // It's not work. Because we are changing the copied address and the address is remain safe in main()
        }
        return top;
    }
};

// typedef class list list; //not required

int main()
{
    list *top = NULL;
    class list s;
    while (1)
    {
        system("pause");
        system("cls");
        cout << "1. To push in stack of list." << endl;
        cout << "2. To pop number from stack of list." << endl;
        cout << "3. To display the stack." << endl;
        cout << "4. To exit." << endl;
        cout << "$ ";
        int choice;
        cin >> choice;
        fflush(stdin);
        switch (choice)
        {
        case 1:
            top = s.push(top);
            break;
        case 2:
            top = s.pop(top);
            break;
        case 3:
            s.display(top);
            break;
        case 4:
            exit(1); // exit
        default:
            cout << "Wrong choice selected." << endl;
        }
    }
    return 0;
} /*end of main()*/
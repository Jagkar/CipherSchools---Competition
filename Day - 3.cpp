#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

Node *listSorted(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *result;

    if (a->data <= b->data)
    {
        result = a;
        result->next = listSorted(a->next, b);
    }
    else
    {
        result = b;
        result->next = listSorted(a, b->next);
    }

    return result;
}

void mergeSort(Node **  headstr)
{
    Node *head = *  headstr;
    if (!head || !head->next)
        return;

    Node *up;
    Node *back;
    Node *s1 = head;
    Node *s2 = head->next;

    while (s2)
    {
        s2 = s2->next;
        if (s2)
        {
            s1 = s1->next;
            s2 = s2->next;
        }
    }

    up = head;
    back = s1->next;
    s1->next = nullptr;

    mergeSort(&up);
    mergeSort(&back);

    *  headstr = listSorted(up, back);
}

int main()
{
    int n;
    cin >> n;

    Node *head = nullptr;
    Node *tail = nullptr;
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> val;
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // doing the Merge Sort
    mergeSort(&head);
    Node *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    while (head)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

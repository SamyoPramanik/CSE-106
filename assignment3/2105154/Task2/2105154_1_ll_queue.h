#include<iostream>
using namespace std;

template<typename x> class LL {
public:
    class node {
    public:
        x  elementvalue;
        node* next;

        node(node* ptr =NULL) {
            next = ptr;
        }

        node(x value, node* ptr = NULL) {
            elementvalue=value;
            next=ptr;
        }
    };

    node*  head;
    node*  tail;
    node* current;
    int currentsize;

    LL() {
        init();
    }

    void init() {
    head = tail = current = new node;
    currentsize = 0;
    }

    void insert(x val) {
        current->next = new node(val, current->next);
        if (tail == current) {
            tail = current->next;
        }
        currentsize++;
    }

    void prev() {
        if (head ==current) {
             return;
        }
        node* temp = head;
        while (temp->next !=current) {
            temp = temp->next;
        }
        current=temp;
    }

    x remove() {
        bool para=false;
        if (current->next == tail) {
            para=true;
        }
        if (current->next == NULL) {

            cout << "no element!!" << endl;
            return -1;
        }
        x val=current->next->elementvalue;
        node* temp=current->next;
        if (temp == tail) {
        tail = current;
        }
current->next = current->next->next;
delete temp;
        currentsize--;
        if (para == true)  {
            prev();
        }
        return  val;
    }

    void moveToStart() {
        current =  head;
    }

    void moveToEnd()  {
        current =tail;
    }

    void next()  {
        if (current == tail) {
            return;
        }
        current =current->next;
    }

    int length() {
        return currentsize;
    }

    int curPos() {
        node* temp = head;
        int i = 0;
        while (temp != current) {
            temp = temp->next;
            i++;
        }
        return i;
    }

    int  moveToPos(int pos) {
          if (pos < 0 || pos >= currentsize) {
              cout << "This position is not within range!" << endl;
            return -1;
        }
         current = head;
    for (int i = 0; i < pos; i++) {
         current = current->next;
        }
    return 0;
    }

    x getValue() {
        if  (current->next == NULL) {
             cout << "no element at this position!" <<endl;
             return -1;
        }
        return current->next->elementvalue;
    }
void clear() {
        moveToStart();

        while (currentsize != 0) {
            remove();
        }
        init();
    }

    void show() {
        cout << "< ";

        node* temp = head;

        while (temp != current) {
             cout << temp->next->elementvalue << ", ";
             temp = temp->next;
        }
        while (temp != tail) {
              cout << temp->next->elementvalue << ", ";
            temp = temp->next;
        }
        cout << ">" <<endl;
    }
};

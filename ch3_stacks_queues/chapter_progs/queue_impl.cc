#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

template <class T>
class Queue {
    public:
        struct Node {
            T data;
            Node* next;
        };

        Node *head;
        Node *tail;

        Queue() {
            head = NULL;
            tail = NULL;
        }

        ~Queue() {
            Node *curr_node = head;
            while(head != NULL) {
                head = (head -> next);
                delete curr_node;
                curr_node = head;
            }
            head = NULL;
            tail = NULL;
        }

        bool empty() {
            return (tail == NULL);
        }

        void enqueue(const T& t) {
            Node* new_node = new Node();
            (new_node -> data) = T(t);
            (new_node -> next) = NULL;
            if(tail == NULL) {
                tail = new_node;
                head = tail;
            } else {
                (tail -> next) = new_node;
                tail = (tail -> next);
            }
        }

        void dequeue() {
            if(head != NULL) {
                Node* tmp = head;
                head = (head -> next);
                cout << "deleting " << (tmp -> data) << endl;
                delete tmp;
                if(head == NULL)
                    tail = NULL;
            }
        }

        T& front() {
            if(head == NULL) 
                throw domain_error("queue is empty!");
            return (head -> data);
        }
};

int main()
{
    Queue<string> q;
    cout << "created a queue." << endl;
    cout << "is queue empty? " << q.empty() << endl;

    string names[] = {"Ahmad", "MCvoy", "kevin", "kmad", "lakshmi",
        "major", "rajnikanth"};
    int names_size = 1;
    for(int i = 0; i < names_size; i++) {
        cout << "enqueuing " << names[i] << endl;
        q.enqueue(names[i]);
    }

    string top = q.front();
    q.dequeue();
    cout << "dequeued (" << top << ")" << endl;

    string name("ramakanth");
    cout << "enqueuing " << name << endl;
    q.enqueue(name);

    while(!q.empty()) {
        top = q.front();
        cout << "top = " << top << endl;
        try {
            q.dequeue();
            cout << "dequeued (" << top << ")" << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }

    cout << "is queue empty? " << q.empty() << endl;

}

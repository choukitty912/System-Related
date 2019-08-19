/*
 * -------------------------------
 * linkedlist.cpp
 * Aug. 18th, 2019
 *-------------------------------
 */
#include <iostream>
#include <cstdio>

#define DEBUG_FLAG false
#define DEBUG_MSG(fmt, ...)\
    do { if (DEBUG_FLAG) fprintf(stderr, "%s:%d:%s(): " fmt"\n", __FILE__,\
            __LINE__, __func__, ##__VA_ARGS__); } while (0)
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x): val(x), next(NULL) {}
};

class linkedlist{
    public:
        linkedlist() {
            head = NULL;
            tail = NULL;
        }

        /* Insert a value*/
        void insert_value(int value) {
            Node *temp = new Node(value);
            if (head == NULL) {
                head = temp;
            } else {
                tail->next = temp;
            }
            tail = temp;
        }
        
        /* Insert a node which already has value */
        void insert_node(Node *node) {
            if (node == NULL) return;
            if (head == NULL) {
                head = node;
            } else {
                tail->next = node;
            }
            tail = node;
        }

        /* Delete an element which has the given value*/
        void delete_value(int value) {
            if (head == NULL) return;

            Node *dummy_head = new Node(0);
            dummy_head->next = head;
            Node *temp = dummy_head;
            while (temp->next) {
                if (temp->next->val == value) {
                    if (temp->next == tail) {
                        tail = temp;
                    }
                    temp->next = temp->next->next;
                    break;
                } else { 
                  temp = temp->next;
                }
            }
            head = dummy_head->next;
            delete(dummy_head);
            DEBUG_MSG("Done deletion!");
        }

        /*Delete the last occurence of the value*/
        void delete_value_last(int value) {
            if (head == NULL) return;
            Node *dummy_head = new Node(0);
            dummy_head->next = head;
            Node *fast = dummy_head, *slow = dummy_head;
            bool find_flag = false;
            while (fast->next) {
                if (fast->next->val == value) {
                    slow = fast;
                    find_flag = true;
                }
                fast = fast->next;
            }

            if (find_flag) {
                if (slow->next == tail) {
                    tail = slow;
                }
                slow->next = slow->next->next;
            }

            head = dummy_head->next;
            delete (dummy_head);

        }

        /*Delete the node from list*/
        void delete_node(Node *node) {
            if (node == NULL) return;
            if (head == NULL) return;
            Node *dummy_head = new Node(0);
            dummy_head->next = head;
            Node *temp = dummy_head;
            while (temp->next) {
                if (temp->next == node) {
                    if (temp->next == tail) {
                        tail = temp;
                    }
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
            head = dummy_head->next;
            delete(dummy_head);
        }



        void print(void) {
            Node *temp;
            temp = head;
            while(temp) {
                cout<<temp->val<<"->";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }
    private:
        Node *head;
        Node *tail;

};

int main (void){
    linkedlist l = linkedlist();
    Node *node1 = new Node(3);
    l.insert_value(5);
    l.insert_value(6);
    l.insert_node(node1);
    l.print();
    l.insert_value(5);
    l.print();
    l.delete_value(5);
    l.print();
    l.delete_value(5);
    l.print();
    l.delete_value(3);
    l.print();
    l.delete_value(6);
    l.print();
    l.insert_value(5);
    l.insert_value(6);
    l.insert_node(node1);
    l.insert_value(5);
    l.insert_value(5);
    l.insert_value(5);
    l.print();
    l.delete_value_last(5);
    l.print();
    l.delete_value_last(5);
    l.print();
    l.delete_value_last(5);
    l.print();
    l.delete_value_last(5);
    l.print();
    return 0;
}

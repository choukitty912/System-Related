/*
 * ----------------------------------------
 * Implement Queue Using Linked List
 *---------------------------------------
 */
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x):val(x), next(NULL){}
};


class queue_linkedlist {
    public: 
	 queue_linkedlist() {
	 	dummy = NULL;
		tail = NULL;
		size = 0;
	 }

	 void push(int x) {
	 	Node *temp = new Node(x);
		if (size == 0) {
		  dummy = temp;
		  tail = dummy;
		} else{
		  tail->next = temp;
		  tail = tail->next;
		}
		size++;
	 }

	 int pop(void) {
		 int temp;
		 if (isEmpty()) {
		 	cout<<"Empty Queue, Cannot pop"<<endl;
			return -1;
		 }
		 temp = dummy->val;
		 Node* tmp_head = dummy;
		 dummy = dummy->next;
		 delete(tmp_head);
		 size--;
		 cout<<"POP: "<<temp<<endl;
		 return temp;
		 
	 }

	 int front(void) {
		 int temp;
		 if (isEmpty()) {
		 	cout<<"Empty Queue, Top is empty"<<endl;
			return 0;
		 }
		 temp = dummy->val;
		 cout<<"TOP: "<<temp<<endl;
	   	 return temp; 
	 }

	 bool isEmpty(void) {
	      if (size == 0) return true;
	      return false;
	 }
	 
	 void print(void) {
              Node *temp = dummy;
	      cout<<"Print Queue:"<<endl;
	      while (temp){
		      cout<<temp->val<<" ";
	      	     temp = temp->next;
	      } 
	      cout<<endl;

	 }

    private:
	Node *dummy, *tail;
	int size;

};

int main(){
	queue_linkedlist *q = new queue_linkedlist();
        q->push(1);
	q->push(2);
	q->push(10);
	q->print();
	q->front();
	q->pop();
	q->print();
	q->pop();
	q->push(4);
	q->print();
	q->push(7);
	q->push(9);
	q->pop();
	q->pop();
	q->pop();
	q->print();

	return 0;

}



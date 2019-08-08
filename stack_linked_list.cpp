#include <iostream>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node(int x):val(x), next(NULL){}
};


class stack_linkedlist {
    public: 
	 stack_linkedlist() {
	 	dummy = NULL;
		size = 0;
	 }

	 void push(int x) {
	 	Node *temp = new Node(x);
		if (size == 0) {
		  dummy = temp;
		} else{
		  temp->next = dummy;
		  dummy = temp;
		}
		size++;
	 }

	 int pop(void) {
		 int temp;
		 if (isEmpty()) {
		 	cout<<"Empty Stack, Cannot pop"<<endl;
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

	 int top(void) {
		 int temp;
		 if (isEmpty()) {
		 	cout<<"Empty Stack, Top is empty"<<endl;
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
	      cout<<"Print Stack:"<<endl;
	      while (temp){
		      cout<<temp->val<<" ";
	      	     temp = temp->next;
	      } 
	      cout<<endl;

	 }

    private:
	Node *dummy;
	int size;

};

int main(){
	stack_linkedlist *s = new stack_linkedlist();
        s->push(1);
	s->push(2);
	s->push(10);
	s->print();
	s->top();
	s->pop();
	s->print();
	s->pop();
	s->push(4);
	s->print();
	s->push(7);
	s->push(9);
	s->pop();
	s->pop();
	s->pop();
	s->print();

	return 0;

}



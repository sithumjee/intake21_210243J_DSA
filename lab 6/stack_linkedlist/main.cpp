#include <iostream>
#include <chrono>
using namespace std;

class node{
public:
    int value;
    node *next;
};

class stack{
    node *top;
public:
    stack(){
        top=NULL;
    }

    void push(int value){
        node* temp =new node;
        temp->value =value;
        temp->next=top;
        top=temp;
    }

    void pop(){
       node *temp;
           temp=top;
           top=top->next;
           delete temp;

    }

    void display(){
        node* temp=top;
        while(temp != NULL){
            cout<<temp->value<<" ";
            temp=temp->next;
        }
        cout<< endl;
    }
};
int main()
{
    auto start = chrono::steady_clock::now();
    stack stack_linkedlist;
    stack_linkedlist.push(8);
    stack_linkedlist.push(10);
    stack_linkedlist.push(5);
    stack_linkedlist.push(11);
    stack_linkedlist.push(15);
    stack_linkedlist.push(23);
    stack_linkedlist.push(6);
    stack_linkedlist.push(18);
    stack_linkedlist.push(20);
    stack_linkedlist.push(17);
    stack_linkedlist.display();
    stack_linkedlist.pop();
    stack_linkedlist.pop();
    stack_linkedlist.pop();
    stack_linkedlist.pop();
    stack_linkedlist.pop();
    stack_linkedlist.display();
    stack_linkedlist.push(4);
    stack_linkedlist.push(30);
    stack_linkedlist.push(3);
    stack_linkedlist.push(1);
    stack_linkedlist.display();
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"Time taken is :";
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;
    return 0;
}

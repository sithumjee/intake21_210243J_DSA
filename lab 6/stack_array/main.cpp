#include <iostream>
#include <chrono>
using namespace std;

class stack{
    int top;
public:
    int stack_arr[100];

    stack(){
        top=-1;
    }

    void push(int value){
        if(top>=100){
            cout<<"Stack overflow";
        }
        else{
            top++;
            stack_arr[top]=value;
        }
    }


    int pop(){
        if (top<0){
            cout<<"stack underflow";
            return -1;
        }
        else{
            top--;
            return stack_arr[top+1];

        }
    }

    void display(){
        cout<<"Stack is :";
        for(int i=top;i>-1;i--){
            cout<<stack_arr[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    auto start = chrono::steady_clock::now();
    stack *stack_array=new stack();
    stack_array->push(8);
    stack_array->push(10);
    stack_array->push(5);
    stack_array->push(11);
    stack_array->push(15);
    stack_array->push(23);
    stack_array->push(6);
    stack_array->push(18);
    stack_array->push(20);
    stack_array->push(17);
    stack_array->display();
    stack_array->pop();
    stack_array->pop();
    stack_array->pop();
    stack_array->pop();
    stack_array->pop();
    stack_array->display();
    stack_array->push(4);
    stack_array->push(30);
    stack_array->push(3);
    stack_array->push(1);
    stack_array->display();
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout<<"Time taken is :";
    cout << chrono::duration <double, milli> (diff).count() << " ms" << endl;


}
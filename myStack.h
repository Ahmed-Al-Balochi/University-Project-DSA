#include <iostream>
using namespace std;
#include <string.h> 
#pragma once


class ClassStack {
    public:

    struct stack{
    string data;
    stack *next;
};

    stack *Mystack,*tail;
    int top=-1;

    ClassStack(){
    Mystack =NULL;
    tail = NULL;
    }

    virtual void push(string n){
    stack *tmp = new stack;
    
    tmp->data = n;
    tmp->next = NULL;
    if (Mystack ==NULL)
    {
        Mystack = tmp;
        tail = tmp;
        top++;
    }
    else{
        tail->next = tmp;
        tail = tail->next;
        //cout<<"tail is "<<tail->data<<endl;
            }
    }

    void pop(string s){
    stack *tmp;
    stack *pre;

        if(Mystack == NULL){

        return;
        }
            if(Mystack->data ==s){
                tmp = Mystack->next;
                delete Mystack;
                Mystack = tmp;
            }

            else{
            tmp = Mystack;

                while (tmp != NULL && tmp->data != s){
                pre= tmp;
                tmp = tmp->next;
                }
                pre->next = tmp->next;
                delete tmp;
            }
    }

    virtual void displayStack(){
    stack *tmp;
    cout<<" Balance History:"<<endl;
        if(Mystack ==NULL){
            cout<<"Stack Empty"<<endl;
            return;
        }
        else{
        tmp =Mystack;
        while(tmp != NULL){
        cout<<" "<<tmp->data<<endl;
        tmp = tmp->next;
    }
        cout<<"..............................................."<<endl;
        }
    }

    };
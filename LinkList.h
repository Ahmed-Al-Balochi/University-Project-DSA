#include <iostream>
#pragma once
using namespace std;

struct listNodes
{
    double data;
    listNodes *next;
};

class linked_list
{
private:
    listNodes *first,*end;
public:

    linked_list()
    {
        first = NULL;
        end = NULL;
    }

    void add_node(double n)
    {
        listNodes *tmp = new listNodes;
        tmp->data = n;
        tmp->next = NULL;

        if(first == NULL)
        {
            first = tmp;
            end = tmp;
        }
        else
        {
            end->next = tmp;
            end = end->next;
        }
    }

    void display_normallist(){
    listNodes *temp;
    temp = first;

    while(temp)
            {
            cout<<"Intrest History is: "<<temp->data<<endl;
            temp = temp->next;
        }
    }

    void delete_node(double num){
    listNodes *tmp;
    listNodes *pre;

        if(first == NULL){

        return;
        }
            if(first->data ==num){
                tmp = first->next;
                delete first;
                first = tmp;
            }

            else{
            tmp = first;

                while (tmp != NULL && tmp->data != num){
                pre= tmp;
                tmp = tmp->next;
                }
                pre->next = tmp->next;
                delete tmp;
            }

    }

};


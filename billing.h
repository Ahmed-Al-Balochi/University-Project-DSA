#include <iostream>
#include"account.h"
#pragma once

using namespace std;

// queue with 10 persons as a limit if limit reached delete to add new into the queue

struct Queue
{
    int data;
    string docID;
    Queue *next;
};

class billing: public account
{
private:
    Queue *first;
    int inc=1;
    string bill_name;

    account a1;
public:
    billing()
    {
        first = NULL;
    }

    void bill(account obj){     //composition from account
        a1 = obj;

        double bill_price;
        double balance;

        balance = a1.getBalance();

        cout<<"Enter the bill's Price: "<<endl;
        cin>>bill_price;

        cout<<"What is you Bill that you want to pay?"<<endl;
        cin>>bill_name;
        bill_name = bill_name +" For "+to_string(bill_price);

        if(bill_price > balance){
            cout<<"This Transaction can't be done. Balance is less then the bill Price"<<endl;
        }
        else{
            a1.Bill_withdraw(bill_price);
            a1.transaction_name(bill_name);
        }
    }

    void inQueue()
    {
        if (inc > 10){
            cout<<"Queue is Full Wait For Your Turn!"<<endl;
            exit;
        }
        else{
        Queue *tmp = new Queue;
        
        cout<<"Enter You Challan ID"<<endl;
        cin>>tmp->docID;

		tmp->data = inc;
        //cout<<"Your Number in Queue: "<<inc<<" Challan Number: "<<tmp->docID<<endl;

		tmp->next = NULL;

        if(first == NULL)
        {
            first = tmp;  
            inc++;
        }
        else
        {
        	Queue *p=first;
        	while(p->next!=NULL)
            p = p->next;
            p->next = tmp;
            inc++;
        }
    }
}

    void display_Queue(){
	if(first == NULL){
		cout<<"Queue Empty "<<endl;
        return;
        }
        else{
	cout<<"\n in Queue: "<<endl;
	Queue *temp;
    temp = first;
    while(temp!=NULL)
            {
            cout<<"Token ID: "<<temp->data<<" Challan Number: "<<temp->docID<<endl;
         cout<<"........................................................."<<endl;   
            temp = temp->next;
        }
    }
}

    void delete_Queue(){
    Queue *tmp;
        if(first == NULL){
		cout<<"Queue Empty Nothing To Delete"<<endl;
        return;
        }
            else{
            	tmp = first->next;
            	
                //tmp = first->next;
                delete tmp;
                //first = tmp;
                inc--;
   		 }
	}
};

#include<iostream>
#include<string>
#include"contact.h"
//#include"myStack.h"
#include"doublyLinkList.h"

#pragma once

using namespace std;
class bank:public contact, public doublyLinkList {
    private:
        string bank_name;
        int BankNum;
    public:

        virtual void addNode(){
        node *tmp = new node;
        
        tmp->BankName = bank_name;
        tmp->BranchNum = BankNum;
        
        tmp->pre = NULL;
        tmp->next = head;

        if(head == NULL){
            head = tmp;
        }
        else{
            head->pre = tmp;
            head = tmp;
        }
    }

        void set_bank_info(){
        cin.ignore();
        cout<<"Enter Bank Name:"<<endl;
        getline(cin, bank_name);
        
        
        cout<<"Enter Branch Number:"<<endl;
        cin>>BankNum;
        cin.ignore();
        addNode();
        }

        string getbank(){
        return bank_name;
        }

        void displayBankName(){
        cout<<"The Bank Name is: "<<bank_name<<endl;
        }
};
#include<iostream>
#pragma once
using namespace std;

struct node{
    string BankName;
    int BranchNum;

    int data;       //dummy variable
    node *pre;
    node *next;
};


class doublyLinkList{
    public:
    node *head;
    
    doublyLinkList(){
        head = NULL;
    }

    void addNode(){
        node *tmp = new node;
        
        cout<<"Enter Data To Double Link List"<<endl;
        cin>>tmp->data;
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
    
    void delete_node(){
    node *tmp;
    node *previous;
    int num;

    cout<<"Enter The FLoat Number To Delete"<<endl;
    cin>>num;

        if(head == NULL){

        return;
        }
            if(head->BranchNum ==num){
                tmp = head->next;
                delete head;
                head = tmp;
            }

            else{
            tmp = head;

                while (tmp != NULL && tmp->BranchNum != num){
                previous= tmp;
                tmp = tmp->next;
                }
                previous->next = tmp->next;
                delete tmp;
            }

    }

    void displayBankList(){
        node *tmp = new node;

        if (head == NULL){
            cout<<"UnderFlow"<<endl;
            return;
         }
        else{
        tmp = head;
        cout<<"Bank Data: "<<endl;
            while(tmp !=NULL){
            cout<<"Name: "<<tmp->BankName<<"\tBranch Number: "<<tmp->BranchNum<<endl;
            tmp = tmp->next;
                }
            }
        }

};
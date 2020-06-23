#include<iostream>
#include<string>
#pragma once
#include"myStack.h"
#include"contact.h"
#include"bank.h"
#include"customer.h"
#include"LinkList.h"
#include"Tree.h"

using namespace std;
class account:public ClassStack, public linked_list, public Tree{
    private:
    double balance, interst, interestRate;  //Program will Store Interst in link List
    int interst_window;
    string *tran_name;  // to create a dynamic array
    string date[20];    //static array to store date of the transaction
    int inc,dinc;
    time_t tt; //for date

    bank bnk_obj;   //for composition
    customer  cust_obj; //for composition

    public:
    account(){
        balance = 0;
        interst = 0;
        inc = 0;
        dinc = 0;
        interestRate = 0.05;
        interst_window = 12;        //12 months
        tran_name = new string [20];     //dynamic array;
    }

    void account_branch(bank n){        //for composition
    bnk_obj = n;
    }

    void account_customer(customer n){      //for composition
    cust_obj = n;
    }

    double getBalance(){
        return balance;
    }

     double getInterst(){
        return interst;
    }

     int getInterst_window(){
        display_normallist();
        return interst_window;
    }

    void Bill_withdraw(double num){
        balance = balance - num;
        push();
        insert(balance);
    }

    void transaction_name(string billName){
        tran_name[inc] = billName;
        date[dinc] = pdate();
        dinc++;
        inc++;
    }

    void calc_interst(){
    if(balance > 100){

    interst = (balance * interestRate * interst_window) / 100;
    balance = balance + interst;
    add_node(interst);
    }
    else{
        cout<<"Balance is less 100"<<endl;  // if balance is less than 100 then interst will not be added
        return;
    }
    }
    
    void deposit(){
    double in;
    cout<<"Enter the amount you want to deposit: ";
    cin>>in;
    balance = balance + in;

    string d = to_string(in)+ " Deposit";
    
    transaction_name(d);
    date[dinc] = pdate();dinc++;
    push(); //stack
    insert(balance);
    }
    
    void withdraw(){
    double in;
    cout<<"Enter the amount you want to withdraw: ";
    cin>>in;

    balance = balance - in;

    string w = to_string(in)+ " Withdraw";
    transaction_name(w);
    insert(balance); 
    date[dinc] = pdate();dinc++;
    push();
    }

    void delete_balance(){
    delete &balance;
    }

    string pdate(){
    struct tm * ti; 
    string d ;
    time (&tt); 
    ti = localtime(&tt); 
    d= (asctime(ti));
    return d;
    //out<< asctime(ti); 
    }

    virtual void push(){
    stack *tmp = new stack;
    //cout<<" Enter Characters to Reverse them: ";
    //cin>>str;
  
    auto str = to_string(balance);
    tmp->data = str;
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

    void displayAccount_info(){
        cout<<"Your Balance is: "<<balance
        <<"\nThe Interst is: "<<interst
        <<"\nThe Period for The Interst: "<<interst_window<<endl;
    }

    void TransactionHistory(){
        cout<<"Transaction History: "<<endl;
        for(int i=0;i<=inc;i++){
            cout<<"Dated:"<<date[i]<<" "<<tran_name[i]<<endl;
        }
    }
};
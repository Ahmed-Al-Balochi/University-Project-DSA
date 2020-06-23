#include<iostream>
#include<string>
#include"bank.h"
#include"contact.h"
#include"myStack.h"
#include"account.h"
#include"billing.h"
#include"Tree.h"

using namespace std;
int main(){
    
    billing q1;
    bank b1;
    customer c1;
    account a1;

    c1.customer_bank(b1);   //composition between customer and bank
    a1.account_branch(b1);  //composition between account and bank 
    a1.account_customer(c1);    //composition between account and customer

    int sw=11;

    while(sw !=0){
    
    cout<<"To Exit and Display the Entered Data Press 0: "<<endl;
    cout<<"To Enter Persons in Queue Press 1: "<<endl;
    cout<<"To Display Persons in Queue Press 2: "<<endl;
    cout<<"To Delete Persons in Queue Press 3: "<<endl;
    cout<<"To Enter Bank Info Press 4: "<<endl;
    cout<<"To Set the Customer Info Press 5: "<<endl;
    cout<<"To Deposit Money Into Account Press 6: "<<endl;
    cout<<"To Withdraw Press 7: "<<endl;
    cout<<"To Display Account Info Press 8: "<<endl;
    cout<<"To Pay Bills Press 9: "<<endl;
    cout<<"To Clear the Screen Press 10: "<<endl;

    cin>>sw;

        switch(sw){

        case 1:{   //enter persons in Queue 
            q1.inQueue();       //using Queue
            break;
        }
        case 2:{        //display the queue
            q1.display_Queue(); //using Queue
            break; 
        }
        case 3:{    //delete from the queue
            q1.delete_Queue();  //using Queue
            break;
        }
        case 4:{        //sets the bank name and branch number
             b1.set_bank_info();
             b1.setContact();    //sets the bank contact detalils
             break;
        }
        case 5:{  //sets the customer info
            c1.setCustomer();
            c1.setContact();
            c1.customerAge();       //gets the customer age
            break;
        }
        case 6:{        //to deposit and calculate interst
            a1.deposit();
            a1.calc_interst();
            break;
        }
        case 7:{
            a1.withdraw();
            break;
        }
        case 8:{
            a1.displayAccount_info();
            break;
        }
        case 9:{   //to pay bills
            q1.bill(a1);
            break;
        }
        case 10:{
            system ("CLS");
            break;
        }
        default :{
            cout<<"Wrong Data Please Try Again"<<endl;
            break;
        }
    }
}

            // displaying all of the entered data
            cout<<endl<<endl;
            c1.quickSort(c1);       //does quick sort 

            b1.displayBankList();   //display bank Number and name using Double Link List 
            cout<<"bank Contact:\t";b1.displayContact(); 

            a1.display_normallist();        ///to display Intrest using Link List

            c1.displayCustomerInfo();
            cout<<"Customer Contact:\t";c1.displayContact();

            a1.TransactionHistory();    // using dynamic Array
            a1.displayStack();      //show full history transaction using Stack
            cout<<endl<<endl;       //alternate way to show full history transaction using Tree
            a1.displayBinTree();
            cout<<"\nInorder"<<endl;
            a1.displayBinTree_Inorder(); //in
            cout<<"\nPost Order"<<endl;
            a1.displayBinTree_Post();
            cout<<"\nPre Order"<<endl;
            a1.displayBinTree_Pre();
        
        return 0;
}


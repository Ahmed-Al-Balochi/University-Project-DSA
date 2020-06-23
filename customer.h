#include<iostream>
#include<string>
#pragma once
#include <bits/stdc++.h> 
#include"contact.h"
#include"bank.h"

using namespace std;
class customer:public contact{
    private:
    string customer_name;
    int customerID=0,inc =0, ArrID[10]={98,100,50,34,12,1,88,256,8,11}; //for quick sort
    int year, month, day,age; //to get age

    bank obj; //for composition

    public:
    void setCustomer(){
    cin.ignore();
    cout<<"Enter the Customer's Name: "<<endl;
    getline(cin, customer_name);

    customerID++;
    }

    void swap(int *a, int *b){
    int s = *a;
    *a=*b;
    *b=s;
}

int parted(int arr[], int left, int right){
    int pivot = arr[right]; 
    int i = left - 1;
    for(int j = left; j<= right - 1;j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return (i + 1);
}

void Sort(int arr[], int left, int right){
    if (left < right){
        int p = parted(arr, left, right);
        Sort(arr, left , p -1);
        Sort(arr, p+1,right);
    }
}

void displayIDs(){
    cout<<"Sorted Array:"<<endl;
    for (int i=0; i<= 10; i++){
    cout<< ArrID[i]<<", ";
    }
    cout<<endl;
}

void quickSort(customer obj){
    int s = sizeof(ArrID) / sizeof(ArrID[0]);
    Sort(ArrID, 0, s - 1);
    displayIDs();
}

    void customerAge(){
    cout<<"Enter the Customer's day of Birth"<<endl;
    cin>>day;
    cout<<"Enter the Customer's month of Birth"<<endl;
    cin>>month;
    cout<<"Enter the Customer's year of Birth"<<endl;
    cin>>year;

    age = 2020 - year;
    }

    void customer_bank(bank n){     //for composition
    obj = n;
    }

    string getCustomerName(){
        return customer_name;
        }

    int getCustomerID(){
        return customerID;
        }

    void displayCustomerInfo(){
        cout<<"Customer ID: "<<customerID<<"\tCustomer name is: "<<customer_name
        <<"\t Age: "<<age<<endl;
        }
};
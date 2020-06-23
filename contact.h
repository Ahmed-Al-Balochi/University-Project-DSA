#include<iostream>
#include<string>
#pragma once

using namespace std;
class contact{
    private:
    string phone_num, email;

    public:

    void setContact(){
    cout<<"Enter Your Email: "<<endl;
    getline(cin, email);

    cout<<"Enter Your Phone Number: "<<endl;
    getline(cin, phone_num);
    }

    string getPhone(){
        return phone_num;
        }

    string getEmail(){
        return email;
        }
    string getContact(){
        return phone_num,email;
    }

    void displayPhoneNumber(){
        cout<<"The Phone Number is: "<<phone_num<<endl;
        }
    
    void displayEmail(){
        cout<<"The Email is: "<<email<<endl;
        }

    void displayContact(){
        cout<<"The Phone Number is: "<<phone_num<<endl;
        cout<<"The Email is: "<<email<<endl;
    }
};
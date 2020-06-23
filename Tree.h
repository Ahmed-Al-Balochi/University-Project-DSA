#include<iostream>
#pragma once

using namespace std;

struct TreeNodes{
    double data;

    TreeNodes *left;            //Small entry
    TreeNodes *right;          //big entry
};

class Tree{
    private:
    TreeNodes *root;

    public:
    Tree(){
        root = NULL;
    }

    void insert(double item){
    TreeNodes *p=new TreeNodes;
    TreeNodes *parent;
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    parent=NULL;
    if(root ==NULL)
        root=p;
    else{
        TreeNodes *ptr;
        ptr=root;   
        while(ptr!=NULL){
            parent=ptr;  
            if(item>ptr->data)      
                ptr=ptr->right;     //if the entry is > data go to next right
            else
                ptr=ptr->left;       //if the entry is < data go to next left
        }   
        if(item<parent->data)   
            parent->left=p;         //if the entry is smaller data go to store it into left
        else
            parent->right=p;        //if the entry is bigger data go to store it into right
    }
}

    void displayBinTree(){
    cout<<"Balance Using Tree"<<endl;
    printBinTree(root);
}
    
    void printBinTree(TreeNodes *ptr){
    if(ptr!=NULL){
        printBinTree(ptr->left);
        cout<<"  "<<ptr->data<<"     ";
        printBinTree(ptr->right);
    }
}

    void displayBinTree_Pre(){
    printPreorder(root);
}

void displayBinTree_Post(){
    printPostorder(root);
}

void displayBinTree_Inorder(){
    printInorder(root);
}

void printPostorder(struct TreeNodes* node) // goes through left then right then root
{ 
    if (node == NULL) 
        return; 
  
    printPostorder(node->left); 
  
    printPostorder(node->right); 
  
    cout << node->data << " "; 
} 
  
void printInorder(struct TreeNodes* node) // goes through left then root then right
{ 
    if (node == NULL) 
        return; 
  
    printInorder(node->left); 
  
    cout << node->data << " "; 
  
    printInorder(node->right); 
} 
  
void printPreorder(struct TreeNodes* node) // goes through root then left then right
{ 
    if (node == NULL) 
        return; 
  
    cout << node->data << " "; 
  
    printPreorder(node->left);  
  
    printPreorder(node->right); 
}  

};

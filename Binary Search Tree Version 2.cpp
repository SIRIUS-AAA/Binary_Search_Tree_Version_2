/*
    Binary Search Tree Version 2
    SIRIUS
*/

#include <bits/stdc++.h>
using namespace std;

struct Struct_node
{
    Struct_node* lc; 
    Struct_node* rc;
    int val;
};
Struct_node* root;

Struct_node* Create_node(int create_val)
{
    Struct_node* temp_node=new Struct_node;
    temp_node->lc=NULL;
    temp_node->rc=NULL;
    temp_node->val=create_val;
    return temp_node;
}

Struct_node* Insert(Struct_node* cur_node, int insert_val)
{
    if (cur_node==NULL) return Create_node(insert_val);
    else if (insert_val<cur_node->val) cur_node->lc=Insert(cur_node->lc, insert_val);
    else if (cur_node->val<insert_val) cur_node->rc=Insert(cur_node->rc, insert_val);
}

Struct_node* Search_node(Struct_node* cur_node)
{
    Struct_node* temp_node_1=cur_node;
    Struct_node* temp_node_2=cur_node;
    temp_node_1=temp_node_1->lc;
    temp_node_2=temp_node_2->lc;
    while (temp_node_1->rc!=NULL) 
    {
        temp_node_1=temp_node_1->rc;
        if (temp_node_1->rc!=NULL) temp_node_2=temp_node_2->rc;
    }
    if (temp_node_1=cur_node->lc) {delete cur_node; return temp_node_1;}
    temp_node_2->rc=temp_node_1->lc;
    temp_node_1->lc=cur_node->lc;
    temp_node_1->rc=cur_node->rc;
    delete cur_node;
    return temp_node_1;
}

Struct_node* Delete(Struct_node* cur_node, int delete_val)
{
    if (delete_val<cur_node->val) cur_node->lc=Delete(cur_node->lc, delete_val);
    else if (cur_node->val<delete_val) cur_node->rc=Delete(cur_node->rc, delete_val);
    else if (cur_node->val==delete_val)
    {
        if (cur_node->lc==NULL&&cur_node->rc==NULL) {delete cur_node; return NULL;}
        else if (cur_node->lc==NULL&&cur_node->rc!=NULL) 
        {
            Struct_node* temp_node=cur_node->rc;
            delete cur_node; 
            return temp_node;
        }
        else if (cur_node->lc!=NULL&&cur_node->rc==NULL) 
        {
            Struct_node* temp_node=cur_node->lc;
            delete cur_node; 
            return temp_node;
        }
        else if (cur_node->lc!=NULL&&cur_node->rc!=NULL) return Search_node(cur_node);
    }
}

void Inorder(Struct_node* cur_node)
{
    if (cur_node->lc!=NULL) Inorder(cur_node->lc);
    cout<<cur_node->val<<' ';
    if (cur_node->rc!=NULL) Inorder(cur_node->rc);
}

inline void Operate()
{
    while (true)
    {
        string input_str; cin>>input_str;
        if (input_str=="Insert")
        {
            int insert_val; cin>>insert_val;
            root=Insert(root, insert_val);
            cout<<"The inorder of the current Binary Search Tree is"<<endl;
            cout<<"    ";
            Inorder(root);
            cout<<endl;
        }
        if (input_str=="Delete")
        {
            int delete_val; cin>>delete_val;
            root=Delete(root, delete_val);
            cout<<"The inorder of the current Binary Search Tree is"<<endl;
            cout<<"    ";
            Inorder(root);
            cout<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    Operate();
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    node (int d){
        this -> data=d;
        this->left=NULL;
        this->right=NULL;
    }

}

node* BuildTree(){
cout<< "Enter the data:"<<endl;
int data;
cin>> data;
root =new node(data);

if(data ==-1){
    return NULL;
}
cout<< "Enter data for inserting in left" << endl;
root->left = buildTree(root->left);
cout<<"Enter data for inserting in left" << endl;
root->right = BuildTree(root->right);
return root;

}

void levelOrderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* temp = q.back();
        cout << temp->data <<"";
        q.pop();
        if(temp =NULL){ //purana level completely traverse ho chuka hai
            cout<<   endl;
            if(!q.empty()){ //queue still has some child nodes
                q.push(NULL);
            }
        }
        else
        {
           if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp ->right);
        } 
        }
        
    }
}

void inOrder(node * root){ //LNR
    //base case
    if(root ==NULL)
{
    return ;
}
inOrder(root->left); //L
cout << root->data;<<" ";//N
inOrder(root->right);//R
}

void preOrderTraversal(node * root){ //NLR
    //base case
    if(root ==NULL){
        return ;
    }
    cout<< root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

//Creating tree from level Order traversal
void buildfromLevelOrderTraversal(node * root){
    queue<node*>q;
    cout<< "Enter data for root"<<endl;
    int data;
    cin>>data;
    root =new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<< "Enter left node for:"<< root->data <<endl;
        int leftData;
        cin >> leftData;
        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->right);
        }
    }
}

int main(int argc, char const *argv[])
{
    node*root=NULL;
    /*
    //creating a tree
    root = BuildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //level Order
    cout << "Printing levle order Traverasal output" << endl;
    levelOrderTraversal(root);

    cout<<"Inorder traversal is:-"<<endl;
    inOrder(root);

    cout<<"Pre order traversal is:- "<< endl;
    preOrderTraversal(root);
    */

    buildfromLevelOrderTraversal(root);
    levelOrderTraversal(root);
    return 0;
}

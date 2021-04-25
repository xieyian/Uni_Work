#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;





class Node
{
public:
    int value;
    Node *left;
    Node *right;
    int height = 0;
};
  
// find height of tree
int height(Node *X)
{
    if (X == NULL){
        return 0;
    }else {
        return X->height;
    }
}

//find the findmax
int findmax(int a, int b)
{
    if(a>b){
        return a;
    }else{
        return b;
    }
}

// use to sethe the new node point to NULL
Node* setNewNode(int value)
{
    Node* n = new Node();
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return(n);
}
  
// use to right rotate subtree
Node *rightrot(Node *a)
{
    Node *b = a->left;
    Node *c = b->right;
    b->right = a;
    a->left = c;
  
    a->height = 1+findmax(height(a->left),height(a->right));
    b->height = 1+findmax(height(b->left),height(b->right));
  
    return b;
}
  
// used to left rotate the subtree
Node *leftrot(Node *a)
{
    Node *b = a->right;
    Node *c = b->left;
    b->left = a;
    a->right = c;
  
    a->height = 1+findmax(height(a->left),height(a->right));
    b->height = 1+findmax(height(b->left),height(b->right));
  
    return b;
}
  

  
// Get the balance of N
int getBalance(Node *N)
{
    if (N == NULL){
        return 0;
    }else{
        return height(N->left) - height(N->right);
    }
}
  


//insert a new value and returns the new node of the subtree.
Node* insert(Node* n, int value)
{
    if (n == NULL){
        return(setNewNode(value));
    }
  
    if (value < n->value){
        n->left = insert(n->left, value);
    }else if (value > n->value){
        n->right = insert(n->right, value);
    }else{
        return n;
    }
    
    n->height = findmax(height(n->left),height(n->right))+1;
  
    int balance = getBalance(n);
  
    //left  rotate
    if (balance > 1 && value < n->left->value){
        return rightrot(n);
    }
    // Right rotate
    if (balance < -1 && value > n->right->value){
        return leftrot(n);
    }
    
    // Left Right rotate
    if (balance > 1 && value > n->left->value)
    {
        n->left = leftrot(n->left);
        return rightrot(n);
    }
  
    // Right Left rotate
    if (balance < -1 && value < n->right->value)
    {
        n->right = rightrot(n->right);
        return leftrot(n);
    }
  
    return n;
}


//used to find the min value node
Node * minValueNode(Node* node)
{
    Node* current = node;
    while (current->left != NULL){
        current = current->left;
    }
  
    return current;
}


//used to delete node and return a new node of sub tree
Node* deleteNode(Node* n, int value)
{
      
    if (n == NULL){
        return n;
    }
   
    if ( value < n->value ){
        n->left = deleteNode(n->left, value);
    }else if( value > n->value ){
        n->right = deleteNode(n->right, value);
    }else{
        if( (n->left == NULL) || (n->right == NULL)){
            Node *temp = n->left ?
                         n->left :
                         n->right;
  
            
            if (temp == NULL){
                temp = n;
                n = NULL;
            }else{
            *n = *temp;
            }
            free(temp);
        }else{
            Node* temp = minValueNode(n->right);
            n->value = temp->value;
            n->right = deleteNode(n->right,temp->value);
        }
    }
  
   
    if (n == NULL){
        return n;
    }
    
    n->height = 1 + findmax(height(n->left),height(n->right));
  
    int balance = getBalance(n);
  
    // Left Left rotate
    if (balance > 1 && getBalance(n->left) >= 0)
        return rightrot(n);
  
    // Left Right rotate
    if (balance > 1 && getBalance(n->left) < 0)
    {
        n->left = leftrot(n->left);
        return rightrot(n);
    }
  
    // Right Right rotate
    if (balance < -1 && getBalance(n->right) <= 0)
        return leftrot(n);
  
    // Right Left rotate
    if (balance < -1 && getBalance(n->right) > 0)
    {
        n->right = rightrot(n->right);
        return leftrot(n);
    }
  
    return n;
}
  
//print tree with pre order
void preorder(Node *n)
{
     if (n == NULL){
         return;
       }else{
          cout << n->value << " ";
          preorder(n->left);
          preorder(n->right);
       }
}

//print tree with post order
void postorder(Node* n)
{
    if (n == NULL){
        return;
    }else{
        postorder(n->left);
        postorder(n->right);
        cout<<n->value<<" ";
    }
}
  
//print the tree with inorder
void inorder(Node* n)
{
     if (n == NULL){
         return;
       }else{
           inorder(n->left);
           cout << n->value << " ";
           inorder(n->right);
       }
}
  

int main(){
    Node *n = NULL;
    vector<string> in;
    string read;
    getline(cin,read);
    string result;
    stringstream input(read);
    
    while(input>>result){
        in.push_back(result);
    }
    
    for(int i=0;i<in.size();i++){
        int a;
        
        if(in[i][0]=='A'){
            in[i].erase(0,1);
            a=stoi(in[i]);
            n = insert(n, a);
            
        }else if(in[i][0]=='D'){
            in[i].erase(0,1);
            a=stoi(in[i]);
            n=deleteNode(n,a);
            
        }else if(in[i]=="POST"){
            if(n==NULL){
                cout<<"EMPTY"<<endl;
            }else{
                postorder(n);
            }
        }else if(in[i]=="IN"){
            if(n==NULL){
                cout<<"EMPTY"<<endl;
            }else{
                inorder(n);
            }
        }else if(in[i]=="PRE"){
            if(n==NULL){
                cout<<"EMPTY"<<endl;
            }else{
                preorder(n);
            }
        }
    }
    return 0;
}


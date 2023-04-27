#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root!=NULL) {
        traverseInOrder(root->left);
        printf("%d ", root->key);
        traverseInOrder(root->right);
    }
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node==NULL) {
      node=new struct node();
        node->key=key;
        node->left=node->right=NULL;

    }
    else if( key<=node->key){
        node->left=insertNode(node->left,key);
    }
    else{
        node->right=insertNode(node->right,key);
    }
    return node;
}

class node* minValue( node* root) {
    while(root->left != NULL)root = root->left;
    return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    if (root ==NULL){
        root=new struct node();
        root->key=key;
        root->left=root->right=NULL;
        return root;
    }
    if(key<root->key){
        root->left= deleteNode(root->left,key);
    }
    else if(key>root->key){
        root->right= deleteNode(root->right,key);
    }
    else{
        if (root->left==NULL && root->right==NULL){
            delete root;
            root=NULL;
        }
        else if (root->left==NULL && root->right!=NULL){
            struct node * temp = root;
            root=root->right;
            delete temp;
        }
        else if (root->left!=NULL && root->right==NULL){
            struct node * temp = root;
            root=root->left;
            delete temp;
        }
        else{
            struct node *temp = minValue(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right,temp->key);

        }
    }
    return root;

}

int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
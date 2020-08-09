#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* leftptr;
    Node* rightptr;
    Node(int d){
        data = d;
        leftptr = rightptr = NULL;
    }
};

void InOrderTraversal(Node* root){
    if (root == NULL) {
        cout<<" -1";
        return;
    }
    InOrderTraversal(root->leftptr);
    cout<<root->data<<" ";
    InOrderTraversal(root->rightptr);
}

void PreOrderTraversal(Node* root){
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" ";
    PreOrderTraversal(root->leftptr);
    PreOrderTraversal(root->rightptr);
}

int preIndex = 0;

Node* constructTree(int in[], int pre[], int is, int ie){

    if (is > ie)
        return NULL;
    Node* root = new Node(pre[preIndex++]);

    int inIndex;
    for(int i = is; i<=ie; i++){
        if(in[i] == root->data){
            inIndex = i;
            break;
        }
    }

    root ->leftptr = constructTree(in, pre, is, inIndex - 1);
    root ->rightptr = constructTree(in, pre, inIndex + 1 , ie);
    return root;
}
//
//int main() {
//    int inOrder[] = {20, 10, 40, 30, 50};
//    int preOrder[] = {10, 20, 30, 40, 50};
//    Node* root = constructTree(inOrder, preOrder, 0, 4);
//    cout<<"Tree Constructed!";
//    cout<<endl<<"Printing in PreOrder Fashion: ";
//    PreOrderTraversal(root);
//
////    Node* root = new Node(10);
////    root->leftptr = new Node(20);
////    root->leftptr->leftptr = new Node(40);
////    root->rightptr = new Node(30);
////    root->rightptr->leftptr = new Node(50);
////    cout<<"PreOrder Traversal: ";
////    PreOrderTraversal(root);
//    return 0;
//}

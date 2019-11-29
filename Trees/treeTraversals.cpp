#include<bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int data) {

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;

}

void insert(int data, struct Node* root) {

	if(root == NULL) {
		root = newNode(data);
	} else if(root->left == NULL && data < root->data) {
		root->left = newNode(data);
	} else if(root->right == NULL && data > root->data) {
		root->right = newNode(data);
	} else if(data < root->data)
		insert(data, root->left);
	else
		insert(data, root->right);

}

void printInorder(struct Node * root)
{
	if(root == NULL) return;
	else {
		printInorder(root->left);
		cout<<root->data<<" ";
		printInorder(root->right);
	}
}

void printPreorder(struct Node * root)
{
	if(root == NULL) return;
	else {
		cout<<root->data<<" ";
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

void printPostorder(struct Node * root)
{
	if(root == NULL) return;
	else {
		printPostorder(root->left);
		printPostorder(root->right);
		cout<<root->data<<" ";
	}
}

int main() {

	int arr[5]={31, 11, 9, 26,29};
	int i=0, n = 5;
	struct Node *root=newNode(arr[0]);
	i++;
	while(i!=n) {
		insert(arr[i],root);
		i++;
	}
	cout<<"InOrder Traversal :\n";
	printInorder(root);
	cout<<"\nPretOrder Traversal :\n";
	printPreorder(root);
	cout<<"\nPostOrder Traversal :\n";
	printPostorder(root);

}

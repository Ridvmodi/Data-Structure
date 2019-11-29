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

int front=-1, rear=-1;
struct Node * a[100];

void enqueue(struct Node * item) {
	if(front==-1&&rear==-1)
		front=rear=0;
	a[rear]=item;
	rear++;
}


struct Node * dequeue() {
	if(front==rear)
		return NULL;
	struct Node* item=a[front];
	front++;
	return item;
}

int isEmpty() {
	if(front==rear)
		return 1;
	else
		return 0;
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

void printPreorder(struct Node * root)
{
	if(root == NULL) return;
	else {
		cout<<root->data<<" ";
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

void printLevelOrder() {

	if(isEmpty()) return;
	else{
		struct Node *root=dequeue();
		 if(root->left!=NULL)
	    cout<<(root->left->data)<<"-";
	    if(root->right!=NULL)
	    cout<<(root->right->data)<<"-";
	    
	    if(root->left!=NULL)
	      enqueue(root->left);
	    
	    if(root->right!=NULL)
	      enqueue(root->right);
	    
	    printLevelOrder();
		
	}
	
}

void printLevel(struct Node* root)
{
	if(!root)
	return;
	else
	{
		enqueue(root);
		cout<<root->data<<"-";
		printLevelOrder();
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
	cout<<"Pre Order Traversal"<<endl;
	printPreorder(root);
	cout<<endl<<"Level Order Travesal"<<endl;
	printLevel(root);
	cout<<endl;
}

// C++ program to perform operations Binary Tree
#include <iostream>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include<string>
using namespace std;


//Binary Tree creation and tree traversals(using recursion)

/* A binary tree node has data, pointer to left child
and a pointer to right child */

struct Node {
	int data;
	Node* left;
	Node* right;
};



/* Function to create a new node */

Node* CreateNode(int data)
{
	Node* newNode = new Node();
	if (!newNode) {
		cout << "Memory error\n";
		return NULL;
	}
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// Inorder traversal

void inorder(Node* temp)
{
	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << ' ';
	inorder(temp->right);
}

// Preorder traversal
void preorderTraversal(Node* temp) 
{
  if (temp == NULL)
    return;

  cout << temp->data << " ";
  preorderTraversal(temp->left);
  preorderTraversal(temp->right);
}

// Postorder traversal
void postorderTraversal(Node* temp) {
  if (temp == NULL)
    return;

  postorderTraversal(temp->left);
  postorderTraversal(temp->right);
  cout << temp->data << " ";
}

// Non recursive method to find the Depth of Binary Tree
int treeDepth(Node *root)
{
    
    if (root == NULL)
        return 0;
  
    
    queue<Node *> q;
  
    
    q.push(root);
    int height = 0;
  
    while (1)
    {

        int nodeCount = q.size();
        if (nodeCount == 0)
            return height;
  
        height++;
  
        
        while (nodeCount > 0)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
    }
}
 
 
/* Function to get the count of leaf Nodes in
   a binary tree*/
unsigned int getLeafCount(struct Node* node)
{
    
    if (!node)
        return 0;
 
   
    queue<Node *> q;
 
    int count = 0; 
    q.push(node);
    while (!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
        if (temp->left == NULL && temp->right == NULL)
            count++;
    }
    return count;
}

// Function to Print all the leaf nodes of Binary tree  
void printLeafRightToLeft(Node* p) 
{ 
     
    stack<Node*> s; 
    
    while (1) { 
        
        if (p) { 
            s.push(p); 
            p = p->right; 
        } 
    
        else { 
            
            if (s.empty()) 
                break; 
            else { 
                
                if (s.top()->left == NULL) { 
                    p = s.top(); 
                    s.pop(); 
    
                    
                    if (p->right == NULL) 
                        printf("%d ", p->data); 
                } 
    
                while (p == s.top()->left) { 
                    p = s.top(); 
                    s.pop(); 
    
                    if (s.empty()) 
                        break; 
                } 
    
                if (!s.empty()) 
                    p = s.top()->left; 
                else
                    p = NULL; 
            } 
        } 
    } 
} 
 

/* Function to insert element in binary tree */

Node* InsertNode(Node* root, int data)
{
	
	if (root == NULL) {
		root = CreateNode(data);
		return root;
	}

	
	queue<Node*> q;
	q.push(root);

	while (!q.empty()) {
		Node* temp = q.front();
		q.pop();

		if (temp->left != NULL)
			q.push(temp->left);
		else {
			temp->left = CreateNode(data);
			return root;
		}

		if (temp->right != NULL)
			q.push(temp->right);
		else {
			temp->right = CreateNode(data);
			return root;
		}
	}
}

// Mirror Tree/copying
void MirrorTree(Node* r)
{
if (r==NULL)
return;
queue<Node*> q;
q.push(r);
while(!q.empty())
{
Node* t = q.front();
q.pop();
swap(t->left,t->right);
if (t->left)
q.push(t->left);
if (t->right)
q.push(t->right);
}
}

   
//Binary Tree
int main()
{
	Node* root = CreateNode(10);
	root->left = CreateNode(5);
	root->right = CreateNode(16);
	root->left->right = CreateNode(8);
    root->right->left = CreateNode(15);
	root->right->right = CreateNode(20);
	root->right->right->right = CreateNode(23);
	
	
	
	
	cout << "Binary Tree traversals:- ";
    cout << "\n Inorder traversal ";
	inorder(root);
	
	
  cout << "\n Preorder traversal ";
  preorderTraversal(root);

  cout << "\n Postorder traversal ";
  postorderTraversal(root);   
  	cout << endl;
  
  cout << "\nDepth of the Binary Tree:- ";
   
    cout << "\n The Depth of the Binary tree is " << treeDepth(root);
    	cout << endl;
	    
   cout << "\nLeaf Nodes:- ";
   cout <<"\n Count of leaf nodes is " <<getLeafCount(root);
   cout <<"\n The leaf nodes are ";
   printLeafRightToLeft(root);
   	cout << endl;
   	
   	
	cout <<"\nAfter Mirror of the Binry Tree"<<endl;
    preorderTraversal(root);
    	cout << endl;

	cout << "\nInsertion in binary tree ,key 12 inserted";

	cout << "\nInorder traversal before insertion: ";
	inorder(root);
	

	int key = 12;
	root = InsertNode(root, key);
	cout << "\nInorder traversal after insertion: ";
	inorder(root);
 	cout << endl;
	return 0;
}
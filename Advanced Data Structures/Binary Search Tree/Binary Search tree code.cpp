
    //Binary Search tree
    
    # include <iostream>
    # include <cstdlib>

    using namespace std;

    
    //Node Declaration
    struct node
    {
        int info;

        struct node *left;

        struct node *right;

    }*root;


     // Class Declaration

    class BST

    {

        public:

            
            void search(node *, int);
            void insert(node *, node *);
            void find(int, node **, node **); 
            void mirror(node *);
            void inorder(node *);
            void display(node *, int);

            BST()

            {

                root = NULL;

            }

    };


    int main()

    {

        int choice, num,item;

        BST bst;

        node *temp;

        while (1)

        {

            
            cout<<"-----------------"<<endl;
            cout<<"Operations on BST"<<endl;
            cout<<"-----------------"<<endl;

            cout<<"1.Insert Element "<<endl;

            cout<<"2.Search Element"<<endl;
            
            cout<<"3.Mirror"<<endl;

            cout<<"4.Inorder Traversal of BST"<<endl;

            cout<<"5.Display BST"<<endl;

            cout<<"6.Quit"<<endl;
            
            cout<<"          "<<endl;

            cout<<"Enter your choice : ";

            cin>>choice;

            switch(choice)

            {

            case 1:

                temp = new node;

                cout<<"Enter the number to be inserted : ";

    	    cin>>temp->info;

                bst.insert(root, temp);
            break;
            
            case 2:
            cout<<"Enter the element which you wish to search:"<<endl;
            cin>>item;
            bst.search(root,item);
            break; 
            
            case 3:

                cout<<"Tree Mirrored successfully:"<<endl;
                cout<<"Inorder traversal of the Mirrored tree"<<endl;

                bst.mirror(root);
                bst.inorder(root);
                break; 
                

            

            case 4:

                cout<<"Inorder Traversal of BST:"<<endl;

                bst.inorder(root);

                cout<<endl;

                break;

    
                break;

            case 5:

                cout<<"Display BST:"<<endl;

                bst.display(root,1);

                cout<<endl;

                break;

            case 6:
             cout<<"Program exited successfully"<<endl;
                exit(1);

            default:

                cout<<"Wrong choice"<<endl;

            }

        }

    }

     



     //Finding the location of the item
     void BST::find(int item, node **par, node **loc)

    {

        node *ptr, *ptrsave;

        if (root == NULL)

        {

            *loc = NULL;

            *par = NULL;

            return;

        }

        if (item == root->info)

        {

            *loc = root;

            *par = NULL;

            return;

        }

        if (item < root->info)

            ptr = root->left;

        else

            ptr = root->right;

        ptrsave = root;

        while (ptr != NULL)

        {

            if (item == ptr->info)

            {

                *loc = ptr;

                *par = ptrsave;

                return;

            }

            ptrsave = ptr;

            if (item < ptr->info)

                ptr = ptr->left;

    	else
         {
    	    ptr = ptr->right;

         }

        *loc = NULL;

        *par = ptrsave;

    }

     }
     
     
    //Searching the element
    void BST::search(node *root, int data)
    {
   int depth = 0;
   node *temp = new node;
   temp = root;
   while(temp != NULL)
   {
      depth++;
      if(temp->info == data)
      {
         cout<<"\nData found at depth: "<<depth<<endl;
         return;
      }
      else if(temp->info > data)
      temp = temp->left;
      else
      temp = temp->right;
   }
   cout<<"\n Data not found"<<endl;
   return;
   }
   
   

    // Inserting Element into the Tree

    void BST::insert(node *tree, node *newnode)

    {

        if (root == NULL)

        {

            root = new node;

            root->info = newnode->info;

            root->left = NULL;

            root->right = NULL;

            cout<<"Root Node is Added"<<endl;

            return;

        }

        if (tree->info == newnode->info)

        {

            cout<<"Element already in the tree"<<endl;

            return;

        }

        if (tree->info > newnode->info)

        {

            if (tree->left != NULL)

            {

                insert(tree->left, newnode);	

    	}

    	else

    	{

                tree->left = newnode;

                (tree->left)->left = NULL;

                (tree->left)->right = NULL;

                cout<<"Node Added To Left"<<endl;

                return;

            }

        }

        else

        {

            if (tree->right != NULL)

            {

                insert(tree->right, newnode);

            }

            else

            {

                tree->right = newnode;

                (tree->right)->left = NULL;

                (tree->right)->right = NULL;

                cout<<"Node Added To Right"<<endl;

                return;

            }	

        }

    }

    //Mirror tree 

    void BST::mirror(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        node *temp;
        mirror(root->left);
        mirror(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        
    }
}
     


    //Inorder Traversal
    void BST::inorder(node *ptr)

    {

        if (root == NULL)

        {

            cout<<"Tree is empty"<<endl;

            return;

        }

        if (ptr != NULL)

        {

            inorder(ptr->left);

            cout<<ptr->info<<"  ";

            inorder(ptr->right);

        }

    }

    
    
    //Display Tree 
    void BST::display(node *ptr, int level)

    {

        int i;

        if (ptr != NULL)

        {

            display(ptr->right, level+1);

            cout<<endl;

            if (ptr == root)

                cout<<"Root->:  ";

            else

            {

                for (i = 0;i < level;i++)

                    cout<<"       ";

    	}

            cout<<ptr->info;

            display(ptr->left, level+1);

        }

    }
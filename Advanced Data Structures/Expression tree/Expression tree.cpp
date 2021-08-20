//Expression tree code
#include <iostream>
using namespace  std;

//Expression tree node
struct node{
  char data;
  node*left;
  node*right;
};

//Stack
class stack{
  public:
  node *st[20];
  char st1[20];
  char data;
  int top1,top;;
  public:
  stack(){
    top=-1;
    top1=-1;
  };
  int isempty(){
    if(top==-1)
        return 1;
    else{
      return 0;
    }
  }
  int isempty1(){
    if(top==-1)
        return 1;
    else{
      return 0;
    }
  }
  void push(node*nwnode){
    top++;
    st[top]=nwnode;
  }
  node*pop(){
    if(isempty())
      return NULL;
      node*nwnode=st[top];
      top--;
      return(nwnode);  
  }
  void push1(char c){
    top++;
    st1[1]= c;
  };
  char pop1()
  {
    if(! isempty1())
       {
         char c=st1[top1];
         top1--;
         return c;
  }
  };
};
class exptree{
  private :
  char post[20];
  public:
  stack s;
  node*root;
  exptree(){
    root=NULL;
  }
  node*newnode(char );
  bool isoperator(char);
  void convert();
  void inorder(node*);
  void preorder(node*);
  void postorder(node*);
  void nr_inorder();
  void nr_preorder();
  void nr_postorder();
  void recursive();
  void nonrecursive();

};

 
// Function to create new node
node * exptree::newnode(char c ){
  node*tmp=new node;
  tmp->data=c;
  tmp->left=NULL;
  tmp->right=NULL;
  return tmp;
}

// A function to check if 'c' is an operator
bool exptree::isoperator(char c){
  if(c=='+'||c=='-'||c=='*'||c=='/')
    return true;
  return false;  
}
void exptree::convert(){
  node*t,*t2,*t3;
  cout<<"ENTER THE EXPRESSION";
  cin>>post;
  for(int i=0;post[i]!='\0';i++){
    if(isalpha(post[i])||isdigit(post[i]) ){
    // Push the operands in stack
      t=newnode(post[i]);
      s.push(t);
    }
    //Pop the two values from the stack if 'c' is an operator 
    else if(isoperator(post[i])){
      t=newnode(post[i]);
      t2=s.pop();
      t3=s.pop();
      
      //update the tree
      //the character which is popped out first make it the right child
      //the character which is popped out second make it the left child
      t->left=t2;
      t->right=t3;
      
      // Push the node to the stack
      s.push(t);
    }
  }
  t=s.pop();
  root=t;

}
//Recursive inorder treaversal
void exptree::inorder(node*temp){
  if(temp!=NULL){
    inorder(temp->left);
    cout<<temp->data<<" ";
    inorder(temp->right);
  }
}

//Recursive preorder treaversal
void exptree::preorder(node*temp){
    if(temp!=NULL){
    cout<<temp->data<<" ";
    inorder(temp->left);
    inorder(temp->right);
  }

}

//Recursive postorder treaversal
void exptree::postorder(node*temp){
    if(temp!=NULL){
    
    inorder(temp->left);
    inorder(temp->right);
    cout<<temp->data<<" ";
  }

}

//Non-Recursive inorder treaversal
void exptree::nr_inorder(){
  stack s;
  node*temp=root;
  while(1){
    while(temp!=NULL){
      s.push(temp);
      temp=temp->left;
    }
    if(s.isempty())
      return ;
     temp=s.pop();
     cout<<temp->data<<" ";
     temp=temp->right; 
  }
}

//Non-Recursive preorder treaversal
void exptree::nr_preorder(){
  stack s;
  node*temp=root;
  while(1){
    while(temp!=NULL){
      s.push(temp);
      cout<<temp->data<<" ";
      temp=temp->left;
    }
    if(s.isempty())
      return ;
     temp=s.pop();
     temp=temp->right; 
  }
}

//Non-Recursive postorder treaversal
void exptree::nr_postorder(){
stack s;
char flag;
node*temp=root;
while(1){
    while(temp!=NULL){
      s.push(temp);
      s.push1('L');
      temp=temp->left;

    }
    if(s.isempty())
      return;
    else{
      temp=s.pop();
      flag=s.pop1();
      if(flag=='R'){
        cout<<temp->data<<" ";
        temp=NULL;
      }
      else{
        s.push(temp);
        s.push1('R');
        temp=temp->right;
      }
    }  
}
}

//Print the choices
void exptree::recursive(){
  
  cout<<"\nrecursive transversal are:";
  cout<<"\n Inorder";
  inorder(root);
  cout<<"\n preorder";
  preorder(root);
  cout<<"\n postorder";
  postorder(root); 
};
void exptree::nonrecursive(){
  
  cout<<"\n NON-recursive transversal are:";
  cout<<"\n Inorder";
  nr_inorder();
  cout<<"\n preorder";
  nr_preorder();
  cout<<"\n postorder";
  nr_postorder();
}
int main() {
  exptree obj;
  int choice,ch;
  cout<<"\n 1.Create an expression tree";
  cout<<"\n 2.Exit"<<endl;
  cout<<"\n ENTER CHOICE:  ";
  cin>>choice;
  
  if(choice==1){
     
      obj.convert();
      cout<<"exp tree created";
      while(1){
         
          cout<<"\n 1.create new exp tree";
          cout<<"\n 2.display recursive transversal";
          cout<<"\n 3. display non recursive transversal";
          cout<<"\n 4. exit"<<endl;
          cout<<"\nENTER YOUR CHOICE";
          cin>>ch;
          if(ch==1){
            obj.convert();
            cout<<"\n Expression tree created";

          }
          else if(ch==2){
            obj.recursive();
          }
          else if(ch==3){
            obj.nonrecursive();
          }
          else{
            cout<<"\n Programme Ended";
        
          }
      }
  }
  else{
    cout<<"\n Programme Ended successfully";
  }
  return 0;
}


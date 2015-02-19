#include <iostream>
#include <string>
#include <cctype>
using namespace std;
struct Node{
   char c;
   Node *left,*right;
};

const char * const ops="+*-/";

bool isOper(char c){
    const char *ptr=ops;
    for(ptr=ops;*ptr&&*ptr!=c;++ptr);
    return *ptr;
}

bool isOper(Node *node){
    if(node)
        return isOper(node->c);
    else 
        return false;
}
void print(Node* root){
    if(!root)
        return;
    if(root->left){
        if(isOper(root->left)){
            cout<<"(";
            print(root->left);
            cout<<")";
        } else {
            print(root->left);
        }
    }
    cout<<root->c;
    if(root->right){
        if(isOper(root->right)){
            cout<<"(";
            print(root->right);
            cout<<")";
        } else 
            print(root->right);
    }
}
void stack(Node* root){
    if(!root)
        return;
    if(root->left){
        stack(root->left);
    }
    if(root->right){
        stack(root->right);
    }
    cout<<root->c;
    cout<<" ";
}

double evaluate(double a, char op, double b){
    switch(op){
    case '+':
        return a+b;
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
        break;
    default: return 0;
    }
}

bool eval(Node* root,double& val){
    if(!root)
        return false;
    if(isOper(root)){
        double a,b;
        if(!root->left||!eval(root->left,a)){
            return false;
        }
        if(!root->right||!eval(root->right,b)){
            return false;
        }
        val=evaluate(a,root->c,b);
        return true;
    } else if (isdigit(root->c)){
        val=(int)root->c-(int)'0';
        return true;
    } else
        return false;
}

void clear(Node* root){
    if(!root)
        return;
    if(root->left){
        clear(root->left);
    }
    if(root->right){
        clear(root->right);
    }
    delete root;
}

Node* newNode(){
    Node* new_node=new Node;
    new_node->c='\0';
    new_node->left=0;
    new_node->right=0;
    return new_node;
}

Node* Symbol(const char*&);
Node* MulExpr(const char*&);
Node* Expr(const char*& ptr){
    Node *left,*right,*root;
    if(!(left=MulExpr(ptr)))
        return 0;

    if(*ptr=='+'||*ptr=='-'){
        root=newNode();
        root->c=*ptr;
        root->left=left;
        ++ptr;
    } else {
        //clear(root);
        return left;
    }
    if(right=Expr(ptr))
        root->right=right;
    else {
        clear(root);
        return 0;
    }
    return root;
}

Node* MulExpr(const char*& ptr){
    Node *left,*right,*root;
    if(!(left=Symbol(ptr))){
        if (*ptr=='(')
            ++ptr;
        else return 0;
        if(!(left=Expr(ptr)))
            return 0;
        if (*ptr==')')
            ++ptr;
        else {
			clear(root);
			return 0;
		}

    };
    if(*ptr=='*'||*ptr=='/'){
        root=newNode();
        root->c=*ptr;
        root->left=left;
        ++ptr;
    } else {
        return left;
    }
    if(right=MulExpr(ptr))
        root->right=right;
    else {
        clear(root);
        return 0;
    }
    return root;
}

Node* Symbol(const char*& ptr){
    Node *leaf;
    if(isalnum(*ptr)){
        leaf=newNode();
        leaf->c=*ptr;
        ++ptr;
        return leaf;
    } else return 0;
}
Node* parse(const char* source){
    Node* res=Expr(source);
    if(!res)
        cerr<<"Parsing error!"<<endl;
    return res;
}
int main(){
    string s;
    double r;
    for(;;){
        cout<<"Введите выражение."<<endl;
        cin>>s;
        Node *t=parse(s.c_str());
        print(t);cout<<endl;
        stack(t);cout<<endl;
        if(eval(t,r))
            cout<<"Результат: "<<r<<endl;
        clear(t);
        cout<<endl;
    }
    return 0;
}

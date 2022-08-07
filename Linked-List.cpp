/******************************************
* AUTHOR : SUSHANT PANDEY *
* NICK : samheuer26433 *
* INSTITUTION : Lovely Professional University *
******************************************/

#include<bits/stdc++.h>
#define ll       long long int
#define nitro    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb       push_back
#define pi       3.1415926535897932384626
#define mod      1000000007
#define endl     '\n'
#define DEBUG    false
#define F        first
#define S        second
//#pragma GCC optimize "trapv"
using namespace std;
 
 class Node {
    public:
    int key;
    Node * left;
    Node * right;
    Node (int n){
        key=n;
        left=right=NULL;
    }
 };

 void inorder(Node * root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
 }

 void preorder(Node * root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
 }

 void postorder(Node * root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
 }

 int heighttree(Node * root){
    if(root==NULL){
        return 0;
    }
    return max(heighttree(root->left),heighttree(root->right))+1;
 }

 void printkdist(Node * root,int k){
    if(root==NULL){
        return;
    }
    else if(k==0){
        cout<<root->node<<" ";
    }
    else{
        printkdist(root->left,k-1);
        printkdist(root->right,k-1);
    }
 }

void levelorder(Node * root){
    if(root==NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    while(q.empty()==false){
        Node *curr= q.front();
        q.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}

int sizeoftree(Node * root){
    if(root==NULL){
        return 0;
    }
    return 1+ sizeoftree(root->left)+ sizeoftree(root->right);
}

int maximumtree(Node * root){
    if(root==NULL){
        return INT_MIN;
    }
    return max(root->key,max(maximumtree(root->left),maximumtree(root->right)));
}

int main()
{
    Node * root= new Node(10);
    Node * leftfirst= new Node(25);
    Node * rightfirst= new Node(30);
    root->left=leftfirst;
    root->right=rightfirst;
    return 0;
}
/******************************************
* AUTHOR : SUSHANT PANDEY *
* NICK : samheuer26433 *
* INSTITUTION : Lovely Professional University *
******************************************/

#include<bits/stdc++.h>

#define ll       long long int
#define nitro    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb       push_back
#define pi       3.1415926535897932384626
#define mod      1000000007
#define endl     '\n'
#define DEBUG    false
#define F        first
#define S        second
//#pragma GCC optimize "trapv"
using namespace std;
 
class Node{
    int node;
    Node* next;

    Node (int x){
        node=x;
        next=NULL;
    }
};

void iteration(Node * head){
    while(head!=NULL){
        cout<<head->node<<" ";
        head=head->next;
    }
}
void recursive (Node * head){
    if(head==NULL){
        return;
    }
    cout<<head->node<<" ";
    recursive(head->next);
}

void searchiterative(Node * head, int value){
    int counter=0;
    bool flag=false;

    while(head!=NULL){
        counter++;
        if(head->node == value){
            flag=true;
            break;
        }
        head=head->next;
    }
    if(flag){
        cout<<counter<<endl;
    }
    else {
        cout<<-1<<endl;
    }
}

void searchrecursive(Node * head, int value, int counter=0){
    if(head->node==value){
        cout<<counter<<endl;
        return;
    }
    else if(head==NULL){
        cout<<-1<<endl;
        return;
    }
    counter++;
    searchrecursive(head->next, value, counter);
}

Node * insertionatbeginning(Node * head, int value){
    Node * temphead;
    temphead->node=value;
    temphead->next=head;
    return temphead;
}

Node* insertionatend(Node* head, int value){
    if(head==NULL){
        Node* temphead= new Node(value);
        return temphead;
    }
    Node * curr = head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    Node * tempend= new Node(value);
    curr->next=tempend;
    tempend->next=NULL;
    return head;
}

Node * deletefirst(Node * head){
    if(head==NULL){
        return NULL;
    }
    Node * temphead=head->next;
    delete head;
    return temphead;
}

Node * deletelast(Node * head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head;
        return NULL;
    }
    Node * curr=head;
    while(curr->next->next!=NULL){
        curr=curr->next;
    }
    delete curr->next;
    curr->next=NULL;
    return head;
}

Node * insertpos(Node * head, int pos, int value){
    if (pos==1){
        return insertionatbeginning(head, value);
    }
    pos--;
    Node * curr= head;
    while(pos--){
        if(curr==NULL){
            return head;
        }
        curr=curr->next;
    }
    Node * temp= new Node(value);
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

Node * sortedinsertion(Node * head, int value){
    Node * temp= new Node(value);
    Node * curr= head;
    if(head==NULL){
        return temp;
    }
    if(value< head->node){
        return insertionatbeginning(head,value);
    }
    while(curr->next!=NULL && curr->next->node <value){
        curr=curr->next;
    }
    temp->next=curr->next;
    curr->next=temp;
    return head;
}

int efficientmiddlenode(Node * head){
    if (head==NULL){
        return -1;
    }
    Node * slow=head;
    Node * fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow->node;
}

void Nthnodefromend(Node * head, int n){
    if(head==NULL){
        return;
    }
    Node * first=head;
    Node * second=head;
    for(int i=0;i<n;i++){
        if(first==NULL){
            return;
        }
        first=first->next;
    }
    while(first!=NULL){
        first=first->next;
        second=second->next;
    }
    cout<<second->node;
    return;
}

Node * reverse(Node * head){
    Node * curr=head;
    Node * prev=NULL;
    while(curr!=NULL){
        Node * temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

Node * reverserecursive(Node * head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node * resthead= reverserecursive(head->next);
    Node * resttail=head->next;
    resttail->next=head;
    head->next=NULL;
    return resthead;
}

int main()
{
    Node *head= new Node(10);
    Node *first= new Node(20);
    Node *second= new Node(30);
    head->next=first;
    first->next=second;
    iteration(head);
    head=insertionatend(head, 20);
    cout<<endl;
    head= deletelast(head);
    head= sortedinsertion(head,22);
    head= sortedinsertion(head,25); 
    iteration(head);
    cout<<endl<<efficientmiddlenode(head)<<endl;
    Nthnodefromend(head,2);
    return 0;
}
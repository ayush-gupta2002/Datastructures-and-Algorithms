//{ Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
#include <unordered_map>

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    
    Node* floydDetection(Node* head){
        if(head == NULL){
            return NULL;
        }
        Node* slow = head;
        Node* fast = head;
        
        while (slow != NULL && fast != NULL){
            slow = slow -> next;
            fast = fast -> next;
            if(fast){
                fast = fast -> next;
            }
            if(fast == slow){
                return fast;
            }
        }
        return NULL;
    }
    
    Node* getStart(Node* head){
        if(!head){
            return NULL;
        }
        Node* intersection = floydDetection(head);
        Node* slow = head;
        if(!intersection){
            return NULL;
        }
        while(slow != intersection){
            slow = slow -> next;
            intersection = intersection -> next;
        }
        return slow;
    }
    
    void cutLoop(Node* head){
        Node* starting = getStart(head);
        if(!starting){
            return;
        }
        Node* temp = starting;
        while(temp -> next != starting){
            temp = temp -> next;
        }
        temp -> next = NULL;
    }
    
    void removeLoop(Node* head)
    {
        cutLoop(head);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends

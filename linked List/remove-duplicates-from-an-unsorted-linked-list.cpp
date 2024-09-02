//remove-duplicates-from-an-unsorted-linked-list

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // Node* temp = head;
        // set<int>s;
        // s.insert(temp->data);
        // while(temp->next != NULL){
        //     if(s.find(temp->next->data) == s.end()){
        //         s.insert(temp->next->data);
        //         temp = temp->next;
        //     }else{
        //         Node* temp1 = temp->next;
        //         temp->next = temp1->next;
        //         delete temp1;
        //     }
        // }
        // return head;
        
        Node* temp = head;
        unordered_map<int,int>m;
        m[temp->data] = 1;
        while(temp->next != NULL){
            if(m.find(temp->next->data) == m.end()){
                m[temp->next->data] = 1;
                temp = temp->next;
            }else{
                Node* temp1 = temp->next;
                temp->next = temp1->next;
                delete temp1;
            }
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        Node *head = new Node(arr[0]);
        Node *tail = head;

        for (size_t i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        Node *result = ob.removeDuplicates(head);
        printList(result);
    }

    return 0;
}

// } Driver Code Ends

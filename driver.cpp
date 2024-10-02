//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

// class Node {
// public:
//     int data;
//     Node*     ;

//     // Default constructor
//     Node()
//     {
//         data = 0;
//         next = NULL;
//     }

//     // Parameterised Constructor
//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
    
//     // 
// };


class LinkedList
{
public:
    Node *head;
    int count = 0;
    Node *tail;

    LinkedList(int data)
    {
        head = new Node(data);
        tail = head;
        count++;
    }
    void push(int data)
    {
     
        Node *newNode = new Node(data);
        newNode->next = tail;
        tail = newNode;
        count++;
    }
}; 






class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        
            LinkedList *l1 = new LinkedList(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        l1->push(arr[i]);
    }
    return l1->head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        Node* ans = ob.constructLL(arr);
        while (ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
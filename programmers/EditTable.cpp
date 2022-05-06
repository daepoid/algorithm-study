#include "bits/stdc++.h"
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int num) {
        data = num;
        prev = nullptr;
        next = nullptr;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int data) {
        Node* new_node = new Node(data);
        if(head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    Node* remove(Node* node) {
        if(node == head) {
            head = node->next;
            node->next->prev = nullptr;
            return head;
        } else if(node == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            return tail;
        } else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            return node->next;
        }
    }

    void undo(Node* node) {
        if(node->prev == nullptr) {
            head = node;
            node->next->prev = node;
        } else if(node->next == nullptr) {
            tail = node;
            node->prev->next = node;
        } else {
            node->prev->next = node;
            node->next->prev = node;
        }
    }
};

stack<Node*> stk;
LinkedList* linkedlist;

void init(int n) {
    linkedlist = new LinkedList();
    for(int i = 0; i < n; i++) {
        linkedlist->insert(i);
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    init(n);
    Node* curr = linkedlist->head;
    for(int i = 0; i < k; i++) {
        curr = curr->next;
    }

    for(int i = 0; i < cmd.size(); i++) {
        string str = cmd[i];
        switch (str[0]) {
        case 'U':
            for(int j = 0; j < stoi(str.substr(2)); j++) {
                curr = curr->prev;
            }
            break;
        case 'D': 
            for (int j = 0; j < stoi(str.substr(2)); j++) {
                curr = curr->next;
            }
            break;
        case 'C':
            stk.push(curr);
            curr = linkedlist->remove(curr);
            break;
        case 'Z':
            Node* temp = stk.top();
            stk.pop();
            linkedlist->undo(temp);
            break;
        }
    }

    for(int i = 0; i < n; i++) {
        answer += "O";
    }
    while(!stk.empty()) {
        Node* temp = stk.top();
        stk.pop();
        answer[temp->data] = 'X';
    }        
    return answer;
}

int main() {
    int n = 8;
    int k = 2;
    vector<string> cmd = { "D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z" };
    string ans = solution(n, k, cmd);
    cout << ans << endl;
}

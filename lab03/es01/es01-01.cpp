#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void push(vector<T> &s);

void pop(vector<int> &s);
template <typename T>
void visit(vector<T> s);

void get_size(vector<int> s);
template <typename T>
bool empty(vector<T> s);

int main(){
    vector<int> stack;
    char command;

    cout << "Write command (I: insert, E: extract, S: show values, G: get size, R: end programm): ";
    cin >> command;

    while(true){
        switch (command)
        {
        case 'I': push(stack); break;
        case 'E': pop(stack); break;
        case 'S': visit(stack); break;
        case 'G': get_size(stack); break;
        case 'F': empty(stack);
        case 'R': return 0;
        default: break;
        }
        cout << "Write command (I: insert, E: extract, S: show values, G: get size, R: end programm): ";
        cin >> command;
    }
}
template <typename T>
void push(vector<T> &s){
    int value;
    cout << "insert value to add to stack: ";
    cin >> value;
    s.push_back(value);
}

void pop(vector<int> &s){
    s.pop_back();
}
template <typename T>
void visit(vector<T> s){
    for(auto val : s){
        cout << val << " ";
    }
    cout << endl;
}

void get_size(vector<int> s){
    cout << "The size of the stack is: " << s.size() << endl;
}
template <typename T>
bool empty(vector<T> s){
    if(s.size() == 0){
        cout << "Stack is empty!";
        return true;
    }else{
        cout << "Stack not empty";
        return false;
    }
}

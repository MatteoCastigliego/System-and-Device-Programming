#include <iostream>
#include <list>
using namespace std;

void enqueue(list<string> &s);
void dequeue(list<string> &s);
void visit(list<string> s);
void get_size(list<string> s);
void empty(list<string> s);

int main(){
    list<string> stack;
    char command;

    cout << "Write command (I: insert, E: extract, S: show values, G: get size, R: end programm): ";
    cin >> command;

    while(true){
        switch (command)
        {
        case 'I': enqueue(stack); break;
        case 'E': dequeue(stack); break;
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

void enqueue(list<string> &s){
    string value;
    cout << "insert string to add to stack: ";
    cin >> value;
    s.push_back(value);
}

void dequeue(list<string> &s){
    s.pop_front();
}

void visit(list<string> s){
    for(auto val : s){
        cout << val << " ";
    }
    cout << endl;
}

void get_size(list<string> s){
    cout << "The size of the stack is: " << s.size() << endl;
}

void empty(list<string> s){
    if(s.size() == 0){
        cout << "Stack is empty!";
    }else{
        cout << "Stack not empty";
    }
}

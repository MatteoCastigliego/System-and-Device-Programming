#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class vector_class{
    public:
        void push(){
            int value;
            cout << "insert value to add to stack: ";
            cin >> value;
            v.push_back(value);
        }
        void pop(){
            v.pop_back();
        }
        void visit(){
            for(auto val : v){
                cout << val << " ";
            }
            cout << endl;
        }
        void get_size(){
            cout << "The size of the stack is: " << v.size() << endl;
        }
        bool empty(){
            if(v.size() == 0){
                cout << "Stack is empty!";
                return true;
            }else{
                cout << "Stack not empty";
                return false;
            }
        }
    private:
        vector<int> v;
};



int main(){
    vector_class<int> stack;
    char command;

    cout << "Write command (I: insert, E: extract, S: show values, G: get size, R: end programm): ";
    cin >> command;

    while(true){
        switch (command)
        {
        case 'I': stack.push(); break;
        case 'E': stack.pop(); break;
        case 'S': stack.visit(); break;
        case 'G': stack.get_size(); break;
        case 'F': stack.empty();
        case 'R': return 0;
        default: break;
        }
        cout << "Write command (I: insert, E: extract, S: show values, G: get size, R: end programm): ";
        cin >> command;
    }
}


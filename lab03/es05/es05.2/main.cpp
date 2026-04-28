#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

void print_names_in_lexicographical_order(map<string, set<string>>& map);
void print_friends(set<string>& set);

int main(){
    string nome1, nome2, nome3;
    map<string, set<string>> adjacency_list;

    ifstream file_input;
    file_input.open("file.txt", ios::in);
    if(!file_input.is_open()){
        cout<< "Errore nell'apertura del file di input";
        return 0;
    }

    while(file_input >> nome1 >> nome2){
        if(adjacency_list.find(nome1) == adjacency_list.end()) adjacency_list.insert({nome1, {}});
        if(adjacency_list.find(nome2) == adjacency_list.end()) adjacency_list.insert({nome2, {}});

        /* Controls could be obmitted because a set never inserts duplicates, automatically, but I do that as precaution */
        if(adjacency_list[nome1].find(nome2) == adjacency_list[nome1].end()) adjacency_list[nome1].insert(nome2);
        if(adjacency_list[nome2].find(nome1) == adjacency_list[nome2].end()) adjacency_list[nome2].insert(nome1);
    }

    cout << "Print all names in lexicographical order:" << endl;
    print_names_in_lexicographical_order(adjacency_list);

    cout << "Insert name and I will print his friends: ";
    cin >> nome3;
    print_friends(adjacency_list[nome3]);

}

void print_names_in_lexicographical_order(map<string, set<string>>& map){
    for(auto name: map) cout << name.first << " ";
}

void print_friends(set<string>& set){
    for(auto name : set) cout << name << " ";
}

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

bool check_name_presence(vector<string> ST, char name[]);
void print_names_in_lexicographical_order(vector<string> ST);
int get_index_by_name(vector<string> ST, char name[]);
string get_name_by_id(vector<string> ST, int index);
void print_names_in_lexicographical_order(vector<string> ST, vector<list<string>> list, string name);

int main(){
    char name1[30], name2[30];
    vector<string> symble_table;
    string initial_string = {};
    

    ifstream file_input;
    file_input.open("file.txt", ios::in);
    if(!file_input.is_open()){
        cout<< "Errore nell'apertura del file di input";
        return 0;
    }

    while(file_input >> name1 >> name2){
        if(!check_name_presence(symble_table, name1)) symble_table.push_back(name1);
        if(!check_name_presence(symble_table, name2)) symble_table.push_back(name2);
    }
    file_input.close();

    int num_elements = symble_table.size();
    cout << "In total there are " << symble_table.size() << " different names" << endl;
    print_names_in_lexicographical_order(symble_table);

    
    vector<list<string>> adjacency_list(num_elements);
    file_input.open("file.txt", ios::in);
    if(!file_input.is_open()){
        cout<< "Errore nell'apertura del file di input";
        return 0;
    }

    while(file_input >> name1 >> name2){
        int index1 = get_index_by_name(symble_table, name1);
        int index2 = get_index_by_name(symble_table ,name2);

        if(adjacency_list[index1].empty()) adjacency_list[index1].push_back(initial_string);
        if(adjacency_list[index2].empty()) adjacency_list[index2].push_back(initial_string);

        adjacency_list[index1].push_back(get_name_by_id(symble_table, index2));
        adjacency_list[index2].push_back(get_name_by_id(symble_table, index1));
    }

    string name;
    cout << "Insert person name you want to know friends: ";
    cin >> name;

    print_names_in_lexicographical_order(symble_table, adjacency_list, name);

    /* For the last point we could do a Depth-First Search(DFS) or a Breadth-First Search(BFS). 
       The result is the same but BFS guarantees the shortest path, DFS gives a path that could
       not be che shortest
    */

}

bool check_name_presence(vector<string> ST, char name[]){
    return find(ST.begin(), ST.end(), name) != ST.end();
}

void print_names_in_lexicographical_order(vector<string> ST){
    sort(ST.begin(), ST.end());
    for_each(ST.begin(), ST.end(), [](string name){cout << name << ' ';});
}

int get_index_by_name(vector<string> ST, string name){
    for(int i = 0; i < ST.size(); i++){
        if(ST[i] == name) return i;
    }
    return -1;
}

string get_name_by_id(vector<string> ST, int index){
    return ST[index];
}

void print_names_in_lexicographical_order(vector<string> ST, vector<list<string>> list, string name){
    int index = get_index_by_name(ST, name);
    sort(list[index].begin(), list[index].end());
    for_each(list[index].begin(), list[index].end(), [](string name){cout << name << ' ';});
}

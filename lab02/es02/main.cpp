#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Line{ // suggested for moving the pointer
    int id, mark;
    long code;
    char name[31], surname[31];
};

int main(){
    fstream filein("filein.txt", ios::in | ios::out);
    fstream filein_binary("filein_binary.txt", ios::in | ios::binary | ios::out);
    int id, mark;
    long code;
    char surname[31], name[31];

    if(!filein.is_open()){
        cout << "Input file not opened!";
        return EXIT_FAILURE;
    }
    if(!filein_binary.is_open()){
        cout << "Input binary file not opened!";
        return EXIT_FAILURE;
    }

    Line line;
    while(filein >> line.id >> line.code >> line.surname >> line.name >> line.mark){
        filein_binary.write(reinterpret_cast<const char*>(&line), sizeof(Line));
    }
    filein_binary.seekg(0, ios::beg);

    char command;
    int id_command;
    
    cout << "Insert accepted command (R, E and W) and line info (separated: R 3, E 0 for exit):";
    cin >> command >> id_command;

    while(true){

        if(command == 'E') break;

        if(command == 'R'){
            filein_binary.seekg((id_command-1)*sizeof(line), ios::beg); // use id_command-1 because in binary files the count starts from 0
            filein_binary.read(reinterpret_cast<char*>(&line), sizeof(Line));
            cout << line.id << " " << line.code << " " << line.surname << " " << line.name << " " << line.mark << endl;
        }

        if(command == 'W'){
            Line new_line;
            filein_binary.seekp((id_command-1)*sizeof(Line), ios::beg);
            new_line.id = id_command;
            cout << "Insert name and surname: ";
            cin >> new_line.name >> new_line.surname;
            cout << "Insert code: ";
            cin >> new_line.code;
            cout << "Insert mark: ";
            cin >> new_line.mark;

            filein_binary.write(reinterpret_cast<const char*>(&new_line), sizeof(Line)); // update binary file 
            filein_binary.seekg(0, ios::beg);
            filein.close();
            filein.open("filein.txt", ios::out);

            // write again input file to add updates
            while(filein_binary.read(reinterpret_cast<char*>(&line), sizeof(Line))){
                filein << line.id << " " << line.code << " " << line.surname << " " << line.name << " " << line.mark << endl;
            } 
        }

        filein_binary.seekg(0, ios::beg);
              
        cout << "Insert accepted command (R, E and W) and line info (separated: R 3, E 0 for exit):";
        cin >> command >> id_command;
    }
    return 0;
    
}
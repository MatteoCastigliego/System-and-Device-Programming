#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    int id, mark;
    long code;
    char surname[31], name[31];
    ifstream filein;
    ofstream fileout3;
    fstream fileout2;

    filein.open("file_1.txt", ios::in);
    if(!filein.is_open()){
        cout<<"Error during opening input file";
        return EXIT_FAILURE;
    }

    fileout2.open("file_2.txt", ios::out | ios::binary | ios::in);
    if(!fileout2.is_open()){
        cout<<"Error during opening output file 2";
        return EXIT_FAILURE;
    }

    fileout3.open("file_3.txt", ios::out);
    if(!fileout3.is_open()){
        cout<<"Error during opening output file 3";
        return EXIT_FAILURE;
    }

    while(filein >> id >> code >> surname >> name >> mark){
        fileout2.write(reinterpret_cast<const char*>(&id), sizeof(id));
        fileout2.write(reinterpret_cast<const char*>(&code), sizeof(code));
        fileout2.write(reinterpret_cast<const char*>(&surname), sizeof(surname));
        fileout2.write(reinterpret_cast<const char*>(&name), sizeof(name));
        fileout2.write(reinterpret_cast<const char*>(&mark), sizeof(mark));
    }
    filein.close();
    fileout2.close();

    fileout2.open("file_2.txt", ios::out | ios::binary | ios::in);
    while(fileout2.read(reinterpret_cast<char*>(&id), sizeof(id))){
        fileout2.read(reinterpret_cast<char*>(&code), sizeof(code));
        fileout2.read(reinterpret_cast<char*>(&surname), sizeof(surname));
        fileout2.read(reinterpret_cast<char*>(&name), sizeof(name));
        fileout2.read(reinterpret_cast<char*>(&mark), sizeof(mark));

        if(!fileout2.eof()){
            fileout3 << id << " " << code << " " << surname << " " << name << " " << mark << endl;
        }
    }
}
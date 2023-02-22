#include "instafollows.h"
#include "profile.h"
#include "date.h"
#include <iostream>

using namespace std;

Profile::Profile(std::string n, Date d){
    name = n;
    bday = d;
}

std::string Profile::get_name()const{
    return name;
}

Date Profile::get_bday()const{
    return bday;
}

bool Profile::operator == (const Profile& other)const{
    if(name == other.name && bday == other.bday){
        return true;
    }
    else{
        return false;
    }
}

bool Profile::operator != (const Profile& other)const{
    if(name != other.name || bday != other.bday){
        return true;
    }
    else{
        return false;
    }
}

void Profile::input(std::istream& ins){
    if(&ins == &cin){
        cout << "Enter the name: ";
        while(ins.peek() == '\n'){
            ins.ignore();
        }
        getline(ins, name);
        cout << "Enter the bday: ";
        ins >> bday;
    }

    else{
        while(ins.peek() == '\n'){
            ins.ignore();
        }
        getline(ins, name);
        ins >> bday;
    }
    
}

void Profile::output(std::ostream& outs)const{
    if(&outs == &cout){
        outs << "Name: " << name << endl;
        outs << "Bday: " << bday << endl;
    }

    else{
        outs << name << endl;
        outs << bday << endl;
    }

}

std::istream& operator >> (std::istream& ins, Profile& p){
    p.input(ins);
    return ins;
}

std::ostream& operator << (std::ostream& outs, const Profile& p){
    p.output(outs);
    return outs;
}
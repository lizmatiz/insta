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
        ins >> name;
        cout << "Enter the bday: ";
        ins >> bday;
    }

    else{
        ins >> name;
        ins >> bday;
    }
    
}

void Profile::output(std::ostream& outs)const{
    outs << "Name: " << name << std::endl;
    outs << "Bday: " << bday << std::endl;

}

std::istream& operator >> (std::istream& ins, Profile& p){
    p.input(ins);
    return ins;
}

std::ostream& operator << (std::ostream& outs, const Profile& p){
    p.output(outs);
    return outs;
}
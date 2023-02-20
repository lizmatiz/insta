#include "instafollows.h"
#include "profile.h"
#include "date.h"
#include <iostream>

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
    if(&ins == &std::cin){
        std::cout << "Enter the name: ";
    }
    while(ins.peek() == '\n'){
        ins.ignore();
    }
    getline(ins, name); // this is where the issue is
    if(&ins == &std::cin){
        std::cout << "Enter the bday: ";
    }
    ins >> bday;
}

void Profile::output(std::ostream& outs)const{
    outs << "Name: " << name << std::endl;
    outs << "Bday: " << bday << std::endl;

}

std::istream& operator >> (std::istream& ins, Profile& p){
    std::cout << "Yes" << std::endl;
    p.input(ins);
    return ins;
}

std::ostream& operator << (std::ostream& outs, const Profile& p){
    p.output(outs);
    return outs;
}
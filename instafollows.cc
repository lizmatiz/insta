#include "instafollows.h"
#include "profile.h"
#include <iostream>
//#include "date.h"

InstaFollows::InstaFollows(){
    used = 0;
    capacity = 5;
    current_index = 0;
    data = new Profile[capacity];
}

InstaFollows::~InstaFollows(){
    delete []data;
}

InstaFollows::InstaFollows(const InstaFollows& other){
    used = other.used;
    capacity = other.capacity;

    data = new Profile[capacity];

    for(int i = 0; i < used; i++){
        data[i] = other.data[i];
    }
}

void InstaFollows::operator = (const InstaFollows& other){
    if(this == &other){
        return;
    }
    delete []data;
    capacity = other.capacity;
    data = new Profile [capacity];
    for(int i = 0; i < used; i++){
        data[i] = other.data[i];
    }
}

void InstaFollows::start(){
    current_index = 0;
}
    
void InstaFollows::advance(){
    current_index++;
}

bool InstaFollows::is_item()const{
    return current_index < used;
}

Profile InstaFollows::current()const{
    return data[current_index];
}

void InstaFollows::remove_current(){
    int i = 0;
}

void InstaFollows::insert(const Profile& p){
    int i = 0;
}

void InstaFollows::attach(const Profile& p){
    int i = 0;
}

void InstaFollows::show_all(std::ostream& outs)const{
    for(int i = 0; i < used; i++){
        data[i].output(outs);
        outs << std::endl;
    }
}

void InstaFollows::bday_sort(){
    int i = 0;
}

Profile InstaFollows::find_profile(const std::string& name)const{
    Profile p;
    return p;
}

bool InstaFollows::is_profile(const Profile& p) const{
    return true;
}

void InstaFollows::load(std::istream& ins){
    while(!ins.eof()){
        if(used == capacity){
            resize();
        }
        ins >> data[used];
        std::cout << data[used-1] << std::endl;
        used++;
    }
    used--;
}

void InstaFollows::save(std::ostream& outs)const{
    int i = 0;
}

void InstaFollows::resize(){
    Profile tmp[capacity];

    for(int i = 0; i < used; i++){
        tmp[i] = data[i];
    }

    delete []data;

    data = new Profile[capacity+5];

    for(int i = 0; i < used; i++){
        data[i] = tmp[i];
    }

    capacity +=5;
}
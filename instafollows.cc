#include "instafollows.h"
#include "profile.h"
#include <iostream>

using namespace std;

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
    for(int i = current_index; i < used; i++){
        data[i] = data[i+1];
    }
    used--;
}

void InstaFollows::insert(const Profile& p){
    if(used == capacity){
        resize();
    }
    if(current_index < capacity){
        for(int i = used; i > current_index; i--){
            data[i] = data[i-1];
        }
        data[current_index] = p;
    }
    else{
        for(int i = used; i > 0; i--){
            data[i] = data[i-1];
        }
        data[0] = p;
    }
    used++;
}

void InstaFollows::attach(const Profile& p){
    if(used == capacity-1){
        resize();
    }
    if(current_index < capacity){
        for(int i = used; i > current_index; i--){
                data[i+1] = data[i];
            }
            data[current_index + 1] = p;
        }
        else{
            data[used] = p;
    }
    used++;
}

void InstaFollows::show_all(std::ostream& outs)const{
    for(int i = 0; i < used; i++){
        data[i].output(outs);
        outs << std::endl;
    }
}

void InstaFollows::bday_sort(){
    int i, j, smallsp;
    Profile tmp;
    for(i = 0; i < used - 1; i++){
        smallsp = i;
        for(j = i + 1; j < used; j++){
            if (data[j].get_bday() < data[smallsp].get_bday()){
                smallsp = j;
            }
        }
        tmp = data[i];
        data[i] = data[smallsp];
        data[smallsp] = tmp;
    }
}

Profile InstaFollows::find_profile(const std::string& name)const{
    for(int i = 0; i < used; i++){
        if(data[i].get_name() == name){
            return data[i];
        }
    }
    return Profile();
}

bool InstaFollows::is_profile(const Profile& p) const{
    for(int i = 0; i < used; i++){
        if(p == data[i]){
            return true;
        }
    }
    return false;
}

void InstaFollows::load(std::istream& ins){
    while(!ins.eof()){
        if(used == capacity){
            resize();
        }
        ins >> data[used];
        std::cout << data[used] << std::endl;
        used++;
    }
}

void InstaFollows::save(std::ostream& outs)const{
    for(int i = 0; i < used; i++){
        data[i].output(outs);
    }
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
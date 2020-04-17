#include "playtype.h"

Playtype::Playtype(){}

int Playtype::getId(){return p_ID;}

string Playtype::getSinger(){return p_Singer;}

string Playtype::getName(){return p_Name;}

void Playtype::setId(int inid){p_ID = inid;}

void Playtype::setSinger(string insinger){p_Singer = insinger;}

void Playtype::setName(string inname){p_Name = inname;}

bool Playtype::operator==(Playtype item){
    return (this->getId() == item.getId());
}

bool Playtype::operator>(Playtype item){
    return (this->getId() > item.getId());
}

bool Playtype::operator<(Playtype item){
    return (this->getId() < item.getId());
}

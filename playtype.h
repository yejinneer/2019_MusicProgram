#ifndef PLAYTYPE_H
#define PLAYTYPE_H

#include <iostream>
#include <fstream>
using namespace std;


class Playtype
{
public:
    Playtype();

    Playtype(int ID, string SINGER);

    int getId();

    string getSinger();

    string getName();

    void setId(int inid);

    void setSinger(string insinger);

    void setName(string inname);

    bool operator==(Playtype item);

    bool operator>(Playtype item);

    bool operator<(Playtype item);


private:
    int p_ID;
    string p_Singer;
    string p_Name;
};

#endif // PLAYTYPE_H

#pragma once
#ifndef _SINGERLIST_H
#define _SINGERLIST_H
#include <iostream>
#include <string>
#include <fstream>
#include "ArrayList.h"

using namespace std;

struct Song{
    Song(){}
    Song(int inid, string inname, string intag):id(inid),name(inname),tag(intag){}
    bool operator==(Song tempsong){
        return this->id == tempsong.id;
    }
    int id;
    string name;
    string tag;
};

/**
*	item information class.
*/
class SingerType {

private:
    int s_ID;
    string s_Name; //∞°ºˆ¿« ¿Ã∏ß
    string s_Gender; //∞°ºˆ¿« º∫∫∞
    string s_group; //∞°ºˆ¿« ≥™¿Ã
    string s_Debut; //∞°ºˆ¿« µ•∫ﬂ≥‚µµ
    ArrayList<Song> songList;

public:
    /**
    *	default constructor.
    */
    SingerType() {}
    /**
    *	destructor.
    */
    ~SingerType() {}
    /**
    *	@brief	∞°ºˆæ∆¿Ãµ∏¶ ∞°¡Æø¬¥Ÿ.
    *	@pre	∞°ºˆæ∆¿Ãµ∞° ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	∞°ºˆæ∆¿Ãµ
    */
    int GetID() { return s_ID; }

    /**
    *	@brief	∞°ºˆ¿Ã∏ß¿ª ∞°¡Æø¬¥Ÿ.
    *	@pre	∞°ºˆ¿Ã∏ß¿Ã ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	∞°ºˆ¿Ã∏ß.
    */
    string GetName() { return s_Name; }

    /**
    *	@brief	º∫∫∞¿ª ∞°¡Æø¬¥Ÿ.
    *	@pre	º∫∫∞¿Ã ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	º∫∫∞.
    */
    string GetsGender() { return s_Gender; }

    /**
    *	@brief	≥™¿Ã∏¶ ∞°¡Æø¬¥Ÿ.
    *	@pre	≥™¿Ã∞° ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	≥™¿Ã.
    */
    string GetsGroup() { return s_group; }

    /**
    *	@brief	µ•∫ﬂ≥‚µµ∏¶ ∞°¡Æø¬¥Ÿ.
    *	@pre	µ•∫ﬂ≥‚µµ∞° ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	µ•∫ﬂ≥‚µµ.
    */
    string GetsDebut() { return s_Debut; }

    void SetsId(int inid) {s_ID = inid;}
    /**
    *	@brief	∞Ó∏Ì¿ª º≥¡§«—¥Ÿ.
    *	@pre	æ¯¥Ÿ.
    *	@post	∞Ó∏Ì¿Ã º≥¡§µ»¥Ÿ.
    *	@param	inName	¿Ωæ«¿« ¿Ã∏ß.
    */

    void SetsName(string inName) { s_Name = inName; }

    /**
    *	@brief	º∫∫∞¿ª º≥¡§«—¥Ÿ.
    *	@pre	æ¯¥Ÿ.
    *	@post	º∫∫∞¿Ã º≥¡§µ»¥Ÿ.
    *	@param	inGen	º∫∫∞.
    */
    void SetsGender(string inGen) { s_Gender = inGen; }

    /**
    *	@brief	≥™¿Ã∏¶ º≥¡§«—¥Ÿ.
    *	@pre	æ¯¥Ÿ.
    *	@post	≥™¿Ã∞° º≥¡§µ»¥Ÿ.
    *	@param	inAge	∞°ºˆ¿« ≥™¿Ã.
    */
    void SetsGroup(string ingroup) { s_group = ingroup; }

    /**
    *	@brief	µ•∫ﬂ≥‚µµ∏¶ º≥¡§«—¥Ÿ.
    *	@pre	æ¯¥Ÿ.
    *	@post	µ•∫ﬂ≥‚µµ∞° º≥¡§µ»¥Ÿ.
    *	@param	inDebut	∞°ºˆ¿« µ•∫ﬂ≥‚µµ.
    */
    void SetsDebut(string inDebut) { s_Debut = inDebut; }

    void SetRecord(int inid, string inname, string ingender, string ingroup, string inde){
        s_ID = inid;
        s_Name = inname;
        s_Gender = ingender;
        s_group = ingroup;
        s_Debut = inde;
    }

    void AddSong(Song insong){
        songList.Add(insong);
    }

    int ReadDataFromFile(ifstream& fin){
        if(fin.is_open()){
            fin >> s_ID >> s_Name >> s_Gender >> s_group >> s_Debut;
            return 1;
        }
        return 0;
    }

    int WriteDataToFile(ofstream& fout){
        if(fout.is_open()){
            fout << s_ID << "\t" << s_Name << "\t" << s_Gender << "\t" << s_group << "\t" << s_Debut << endl;
            return 1;
        }
        return 0;
    }

    bool operator==(SingerType tempsinger){
        return this->GetID() == tempsinger.GetID();
    }

    bool operator>(SingerType tempsinger){
        return (this->GetID() > tempsinger.GetID());
    }

    bool operator<(SingerType tempsinger){
        return (this->GetID() < tempsinger.GetID());
    }
};

#endif // SINGERTYPE_H

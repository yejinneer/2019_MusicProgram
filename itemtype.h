#pragma once
#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
*	Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL };

/**
*	item information class.
*/
class ItemType {
private:
    int m_ID;
    string m_Name;
    string m_Composer;
    string m_Singer;
    string m_Genre;
    string m_Tag;

public:
    /**
    *	default constructor.
    */
    ItemType() {}

    /**
    *	destructor.
    */
    ~ItemType() {}

    /**
    *	@brief	∞Óπ¯»£∏¶ ∞°¡Æø¬¥Ÿ.
    *	@pre	∞Óπ¯»£∞° ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	∞Óπ¯»£.
    */
    int GetID() { return m_ID; }

    /**
    *	@brief	∞Ó∏Ì¿ª ∞°¡Æø¬¥Ÿ.
    *	@pre	∞Ó∏Ì¿Ã ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	∞Ó∏Ì.
    */
    string GetName() { return m_Name; }

    /**
    *	@brief	¿€∞Ó∞°∏¶ ∞°¡Æø¬¥Ÿ.
    *	@pre	¿€∞Ó∞°∞° ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	¿€∞Ó∞°.
    */
    string GetComposer() { return m_Composer; }

    /**
    *	@brief	∞°ºˆ∏¶ ∞°¡Æø¬¥Ÿ.
    *	@pre	∞°ºˆ∞° ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	∞°ºˆ.
    */
    string GetSinger() { return m_Singer; }

    /**
    *	@brief	¿Â∏£∏¶ ∞°¡Æø¬¥Ÿ.
    *	@pre	¿Â∏£∞° ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	¿Â∏£.
    */
    string GetGenre() { return m_Genre; }

    /**
    *	@brief	≥Î∑°≈¬±◊∏¶ ∞°¡Æø¬¥Ÿ.
    *	@pre	≈¬±◊∞° ¿˙¿Âµ«æÓ ¿÷¥Ÿ.
    *	@post	æ¯¥Ÿ.
    *	@return	≥Î∑°≈¬±◊.
    */
    string GetTag() { return m_Tag; }

    /**
    *	@brief	æ∆¿Ãµ∏¶ º≥¡§«—¥Ÿ.
    *	@pre	æ¯¥Ÿ.
    *	@post	æ∆¿Ãµ∞° º≥¡§µ»¥Ÿ.
    *	@param	inID	æ∆¿Ãµ.
    */
    void SetID(int inID) { m_ID = inID; }

    /**
    *	@brief	∞Ó∏Ì¿ª º≥¡§«—¥Ÿ.
    *	@pre	æ¯¥Ÿ.
    *	@post	∞Ó∏Ì¿Ã º≥¡§µ»¥Ÿ.
    *	@param	inName	¿Ωæ«¿« ¿Ã∏ß.
    */
    void SetName(string inName) { m_Name = inName; }

    /**
    *	@brief	¿€∞Ó∞°∏¶ º≥¡§«—¥Ÿ.
    *	@pre	æ¯¥Ÿ.
    *	@post	¿€∞Ó∞°∞° º≥¡§µ»¥Ÿ.
    *	@param	inComposer	¿Ωæ«¿« ¿€∞Ó∞°.
    */
    void SetComposer(string inComposer) { m_Composer = inComposer; }

    /**
    *	@brief	∞°ºˆ∏¶ º≥¡§«—¥Ÿ.
    *	@pre	æ¯¥Ÿ.
    *	@post	∞°ºˆ∞° º≥¡§µ»¥Ÿ.
    *	@param	inSinger	¿Ωæ«¿« ∞°ºˆ.
    */
    void SetSinger(string inSinger) { m_Singer = inSinger; }

    /**
    *	@brief	¿Â∏£∏¶ º≥¡§«—¥Ÿ.
    *	@pre	æ¯¥Ÿ.
    *	@post	¿Â∏£∞° º≥¡§µ»¥Ÿ.
    *	@param	inGenre		¿Ωæ«¿« ¿Â∏£.
    */
    void SetGenre(string inGenre) { m_Genre = inGenre; }

    void SetTag(string intag){m_Tag = intag;}

    void SetRecord(int inid, string inname, string incomposer, string insinger, string ingenre, string intag){
        SetID(inid); SetName(inname); SetComposer(incomposer); SetSinger(insinger); SetGenre(ingenre); SetTag(intag);
    }

    /**
    *	@brief	Read a record from file.
    *	@pre	the target file is opened.
    *	@post	music record is set.
    *	@param	fin	file descriptor.
    *	@return	return 1 if this function works well, otherwise 0.
    */
    int ReadDataFromFile(ifstream& fin);

    /**
    *	@brief	Write a record into file.
    *	@pre	the target file is opened. And the list should be initialized.
    *	@post	the target file is included the new music record.
    *	@param	fout	file descriptor.
    *	@return	return 1 if this function works well, otherwise 0.
    */
    int WriteDataToFile(ofstream& fout);

    /**
    *	Compare two itemtypes.
    *	@brief	Compare two item types by item id.
    *	@pre	two item types should be initialized.
    *	@post	the target file is included the new item record.
    *	@param	data	target item for comparing.
    *	@return	return LESS if this.id < data.id,
    *			return GREATER if this.id > data.id then,
    *			otherwise return EQUAL.
    */
    RelationType Compare(const ItemType& data);

    /**
    *	Compare two itemtypes.
    *	@brief	Compare two item types by item id.
    *	@pre	two item types should be initialized.
    *	@post	the target file is included the new item record.
    *	@param	data	target item for comparing.
    *	@return	return TRUE if this.id == data.id,
    */
    bool operator==(ItemType data);

    /**
    *	Compare two itemtypes.
    *	@brief	Compare two item types by item id.
    *	@pre	two item types should be initialized.
    *	@post	the target file is included the new item record.
    *	@param	data	target item for comparing.
    *	@return	return TRUE if this.id < data.id,
    */
    bool operator<(ItemType data);

    /**
    *	Compare two itemtypes.
    *	@brief	Compare two item types by item id.
    *	@pre	two item types should be initialized.
    *	@post	the target file is included the new item record.
    *	@param	data	target item for comparing.
    *	@return	return TRUE if this.id > data.id,
    */
    bool operator>(ItemType data);
};
#endif



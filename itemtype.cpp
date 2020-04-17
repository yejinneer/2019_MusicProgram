#include "itemtype.h"

// Read a record from file.
int ItemType::ReadDataFromFile(ifstream& fin) {
    fin >> m_Name >> m_Composer >> m_Singer >> m_Genre >> m_ID >> m_Tag;
    return 1;
}
// Write a record into file.
int ItemType::WriteDataToFile(ofstream& fout) {
    fout << m_Name << m_Composer << m_Singer << m_Genre << m_ID << m_Tag;
    return 1;
}
// Compare two itemtypes.
RelationType ItemType::Compare(const ItemType& data) {
    if (this->m_ID > data.m_ID)
        return GREATER;
    else if (this->m_ID < data.m_ID)
        return LESS;
    else
        return EQUAL;
}

// Compare two itemtypes.
bool ItemType:: operator==(ItemType data) {
    return this->m_ID == data.GetID();
}
// Compare two itemtypes.
bool ItemType:: operator<(ItemType data) {
    return this->m_ID < data.GetID();
}
// Compare two itemtypes.
bool ItemType:: operator>(ItemType data) {
    return this->m_ID > data.GetID();
}

#ifndef CIRCULARDOUBLELINKED_H
#define CIRCULARDOUBLELINKED_H
#pragma once

#define MAAX 10
/**
*	ø¨∞·∏ÆΩ∫∆Æø°º≠ æ≤¿Ã¥¬ NodeType¿« ±∏¡∂√º
*/
template <typename T>
struct DoubleNodeType
{
    T info; ///< ∞¢ ≥ÎµÂ¿« µ•¿Ã≈Õ
    DoubleNodeType<T>* next; ///< ≥ÎµÂ¿« ¥Ÿ¿Ω∏¶ ∞°∏Æ≈∞¥¬ ∆˜¿Œ≈Õ.
    DoubleNodeType<T>* prev; ///< ≥ÎµÂ¿« æ’¿ª ∞°∏Æ≈∞¥¬ ∆˜¿Œ≈Õ.

};

/**
*	¥ı∫Ìº¯»Øø¨∞·∏ÆΩ∫∆Æ ≈¨∑°Ω∫
*/
template <typename T>
class CircularDoubleLinkedList {
public:
    /**
    *	µ∆˙∆Æ ª˝º∫¿⁄.
    */
    CircularDoubleLinkedList();

    /**
    *	º“∏Í¿⁄.
    */
    ~CircularDoubleLinkedList();

    /**
    *	@brief	∏ÆΩ∫∆Æ∏¶ ∫ÒøÓ¥Ÿ.
    *	@pre	æ¯¿Ω.
    *	@post	topPtr endPtr∏¶ ¡¶ø‹«— ∏µÁ µ•¿Ã≈Õ∏¶ ¡ˆøÓ¥Ÿ.
    */
    void MakeEmpty();

    /**
    *	@brief	∏ÆΩ∫∆Æ¿« ±Ê¿Ã∏¶ π›»Ø«—¥Ÿ.
    *	@pre	æ¯¿Ω.
    *	@post	∏ÆΩ∫∆Æ¿« ±Ê¿Ã∏¶ π›»Ø.
    *	@return	m_Length ∏ÆΩ∫∆Æ¿« ±Ê¿Ã π›»Ø.
    */
    int GetLength();

    /**
    *	@brief	∏ÆΩ∫∆Æ∞° ∫Òæ˙¥¬¡ˆ æ∆¥—¡ˆ ∞ÀªÁ«—¥Ÿ.
    *	@pre	m_Length∞° ∞™¿ª ∞°¡ˆ∞Ì ¿÷æÓæﬂ «—¥Ÿ.
    *	@post	∫Òæ˙¥¬¡ˆ æ∆¥—¡ˆ∏¶ æÀ∑¡¡ÿ¥Ÿ.
    *	@return	∫ÒæÓ¿÷¿∏∏È true, æ∆¥œ∏È false∏¶ π›»Ø.
    */
    bool IsEmpty() const;

    /**
    *	@brief	∏ÆΩ∫∆Æ∞° ∞°µÊ √°¥¬¡ˆ æ∆¥—¡ˆ ∞ÀªÁ«—¥Ÿ.
    *	@pre	m_Length∞° ∞™¿ª ∞°¡ˆ∞Ì ¿÷æÓæﬂ «—¥Ÿ.
    *	@post	∞°µÊ √°¥¬¡ˆ æ∆¥—¡ˆ∏¶ æÀ∑¡¡ÿ¥Ÿ.
    *	@return	∞°µÊ ¬˜¿÷¿∏∏È true, æ∆¥œ∏È false∏¶ π›»Ø.
    */
    bool IsFull() const;

    /**
    *	@brief	ªı∑ŒøÓ æ∆¿Ã≈€¿ª ∏ÆΩ∫∆Æø° √ﬂ∞°«—¥Ÿ.
    *	@pre	item¿ª ¿‘∑¬πﬁ¥¬¥Ÿ.
    *	@post	æ∆¿Ã≈€¿ª ∏ÆΩ∫∆Æø° √ﬂ∞°«—¥Ÿ.
    *	@return	∞∞¿∫ æ∆¿Ã≈€¿Ã ¿÷¿∏∏È 0¿ª π›»Ø«œ∞Ì, ¿‘∑¬ø° º∫∞¯«œ∏È 1¿ª π›»Ø. ∏ÆΩ∫∆Æ∞° ≤À ¬˜¿÷¿∏∏È -1 π›»Ø.
    */
    int Add(T newItem);

    /**
    *	@brief	m_pCurPointer∏¶ √ ±‚»≠«—¥Ÿ.
    *	@post	m_pCurPointer∏¶ nullptr∑Œ √ ±‚»≠«—¥Ÿ.
    */
    void ResetList();

    /**
    *	@brief	¥Ÿ¿Ω ∆˜¿Œ≈Õ¿« æ∆¿Ã≈€¿ª ∞°¡Æø¬¥Ÿ.
    *	@pre	item¿ª ¿‘∑¬πﬁ¥¬¥Ÿ.
    *	@post	¥Ÿ¿Ω ∆˜¿Œ≈Õ¿« æ∆¿Ã≈€¿ª itemø° ≥÷¥¬¥Ÿ.
    */
    void GetNextItem(T& item);

    /**
    *	@brief	¿‘∑¬πﬁ¿∫ æ∆¿Ã≈€¿ª ∏ÆΩ∫∆Æø°º≠ ªË¡¶«—¥Ÿ.
    *	@pre	item¿ª ¿‘∑¬πﬁ¥¬¥Ÿ.
    *	@post	¿‘∑¬πﬁ¿∫ æ∆¿Ã≈€¿ª ∏ÆΩ∫∆Æø°º≠ √£æ∆ ªË¡¶«—¥Ÿ.
    */
    bool Delete(T data);

    /**
    *	@brief	¿‘∑¬πﬁ¿∫ æ∆¿Ã≈€¿« ¡§∫∏øÕ ∫Ò±≥«œø© ∞∞¿∫ ∏ÆΩ∫∆Æ¿« æ∆¿Ã≈€¿ª ∞°¡Æø¬¥Ÿ.
    *	@pre	item¿ª ¿‘∑¬πﬁ¥¬¥Ÿ.
    *	@post	∞Àªˆµ» µ•¿Ã≈Õ∏¶ æ∆¿Ã≈€ø° ≥÷¥¬¥Ÿ.
    *	@return	¿œƒ°«œ¥¬ µ•¿Ã≈Õ∏¶ √£¿∏∏È true, ±◊∑∏¡ˆ æ ¿∏∏È false¿ª π›»Ø.
    */
    bool Retrieve(T& item);

    /**
    *	@brief	¿‘∑¬πﬁ¿∫ index¿« æ∆¿Ã≈€¿ª listø°º≠ ∞°¡Æø¬¥Ÿ.
    *	@pre	index¿ª ¿‘∑¬πﬁ¥¬¥Ÿ.
    *	@post	∞Àªˆµ» µ•¿Ã≈Õ∏¶ æ∆¿Ã≈€ø° ≥÷¥¬¥Ÿ.
    *	@return	¿‘∑¬πﬁ¿∫ index¿« æ∆¿Ã≈€.
    */
    T at(int index);

    /**
    *	@brief	µŒ ∞≥¿« æ∆¿Ã≈€¿« info∏¶ º≠∑Œ swap«—¥Ÿ.
    *	@pre	index 2∞≥∏¶ ¿‘∑¬πﬁ¥¬¥Ÿ.
    *	@post	µŒ ∞≥¿« æ∆¿Ã≈€¿« info∏¶ º≠∑Œ swap«—¥Ÿ.
    */
    void ChangeSequence(int, int);


private:
    DoubleNodeType<T>* topPtr; ///< ∏ÆΩ∫∆Æ¿« ∏«§√§µπˆ √≥¿Ω.
    DoubleNodeType<T>* endPtr;  ///< ∏ÆΩ∫∆Æ¿« ∏« ≥°.
    DoubleNodeType<T>* m_pCurPointer; ///< ∏ÆΩ∫∆Æ ∆˜¿Œ≈Õ.
    int m_length; ///< ∏ÆΩ∫∆Æ¿« ±Ê¿Ã.
};

// ∏ÆΩ∫∆Æ¿« ±Ê¿Ã∏¶ 0¿∏∑Œ √ ±‚»≠Ω√ƒ—≥ı¥¬¥Ÿ.
template <typename T>
CircularDoubleLinkedList<T>::CircularDoubleLinkedList()
{
    topPtr = new DoubleNodeType<T>;
    endPtr = new DoubleNodeType<T>;

    topPtr->next = endPtr;
    topPtr->prev = endPtr;
    endPtr->next = topPtr;
    endPtr->prev = topPtr;

    m_length =0;
    m_pCurPointer = nullptr;
}

template <typename T>
CircularDoubleLinkedList<T>::~CircularDoubleLinkedList()
{
    /*DoubleNodeType<T>* current = topPtr;
    while(current)
    {
        DoubleNodeType<T>* next =current->next;
        delete current;
        current = next;
    }*/
}

template <typename T>
void CircularDoubleLinkedList<T>::MakeEmpty()
{
    DoubleNodeType<T>* tempPtr;

    while (topPtr-> next == endPtr)
    {
        tempPtr = topPtr->next;
        topPtr->next = tempPtr->next;
        delete tempPtr;
    }
}
template <typename T>
bool CircularDoubleLinkedList<T>::IsEmpty() const
{
    return topPtr == endPtr;
}
template <typename T>
bool CircularDoubleLinkedList<T>::IsFull() const
{
    return m_length == MAAX;
}

//full:-1, succeed:1
template <typename T>
int CircularDoubleLinkedList<T>::Add(T newItem)
{
    if (IsFull())
        return -1;
    else if (Retrieve(newItem))
        return 0;
    DoubleNodeType<T>* newlocation = new DoubleNodeType<T>;
    newlocation->info = newItem;

    if(IsEmpty())
    {
        newlocation->next = endPtr;
        newlocation->prev = topPtr;
        topPtr->next = newlocation;
        endPtr->prev = newlocation;
    }
    else
    {
        newlocation->next = topPtr->next;
        newlocation->prev = topPtr;
        topPtr->next = newlocation;
    }
    m_length++;
    return 1;
}


template <typename T>
void CircularDoubleLinkedList<T>::GetNextItem(T& item)
{
    if (m_pCurPointer == nullptr)
        m_pCurPointer = topPtr->next;

    else
    {
        m_pCurPointer = m_pCurPointer -> next;
        if (m_pCurPointer==topPtr || m_pCurPointer==endPtr)
        {
            m_pCurPointer = topPtr->next;
        }
    }
    item = m_pCurPointer->info;
}

template <typename T>
void CircularDoubleLinkedList<T>::ResetList()
{
    m_pCurPointer =nullptr;
}

template <typename T>
bool CircularDoubleLinkedList<T>::Retrieve(T& item)
{
    T temp;
    ResetList();
    for (int i=0;i<m_length;i++)
    {
        GetNextItem(temp);
        if (temp==item)
        {
            item = temp;
            return true;
        }
    }
    return false;
}

template <typename T>
int CircularDoubleLinkedList<T>::GetLength()
{
    return m_length;
}

template <typename T>
bool CircularDoubleLinkedList<T>::Delete(T item)
{
    if (Retrieve(item))
    {
        m_pCurPointer->prev->next = m_pCurPointer->next;
        m_pCurPointer->next->prev = m_pCurPointer->prev;

        delete m_pCurPointer;
        m_pCurPointer=nullptr;

        m_length--;
        return true;
    }
    return false;

}

template <typename T>
T CircularDoubleLinkedList<T>::at(int index)
{
    T temp;
    ResetList();
    for (int i=0;i<=index;i++)
    {
        GetNextItem(temp);
    }
    return temp;
}

#endif // CIRCULARDOUBLELINKED_H

#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#pragma once
#include <iostream>
#include <string>
using namespace std;

#define MAXSIZEE 256

/**
*	간단한 unsorted list를 기반으로 한 배열
*/
template <typename T>
class ArrayList {
public:
    /**
    *	기본 생성자
    */
    ArrayList()
    {
        m_Length = 0;
        ResetList();
    }

    /**
    *	소멸자
    */
    ~ArrayList() {}

    /**
    *	@brief	비어있는 리스트 생성
    *	@pre	X
    *	@post	비어있는 리스트
    */
    void MakeEmpty()
    {
        m_Length = 0;
    }

    /**
    *	@brief	현재 리스트에 있는 레코드 수 가져옴
    *	@pre	X
    *	@post	X
    *	@return	현재 리스트에 있는 레코드 수
    */
    int GetLength()
    {
        return m_Length;
    }

    /**
    *	@brief	커렌트 포인터를 초기화시킨다
    *	@pre    포인터를 설정할 m_Array가 존재해야 한다
    *	@post   m_CurPointer가 맨 앞의 전인 -1로 설정된다
    */
    void ResetList()
    {
        m_CurPointer = -1;
    }

    /**
    *	@brief	커렌트 포인터를 한칸 넘겨 정보를 넘긴다
    *	@pre    m_Array가 존재해야 한다
    *	@post   커렌트 포인터를 한칸 넘겨주고, 인자로 받은 데이터에 현재 커렌트 포인터의 정보를 담는다
    *	@param  정보를 담을 데이터
    *	@return 현재 커렌트포인터의 인덱스를 리턴
    */
    int GetNextItem(T& data)
    {
        m_CurPointer++;	// list pointer 증가
        if (m_CurPointer == MAXSIZEE)	// end of list이면 -1을 리턴
            return -1;
        data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

        return m_CurPointer;
    }

    /**
    *	@brief	모든 배열의 사용 여부
    *	@pre	none.
    *	@post	none.
    *	@return	모든 배열 사용중이면 true(1), 아니면 false(0)반환
    */
    bool IsFull()
    {
        if (m_Length > MAXSIZEE - 1)
            return true;
        else
            return false;
    }

    /**
    *	@brief	리스트에 새로운 데이터 추가.
    *	@pre	생성되어있는 리스트가 존재해야한다.
    *	@post	라스트에 새로운 데이터 추가한다.
    *	@param	ItemType형식의 새로운 데이터
    *	@return 제대로 추가 됬다면 1, 아니면 0 반환.
    */
    int Add(T data)
    {
        if (!IsFull())
        {
            m_Array[m_Length] = data;
            m_Length++;
            return 1;
        }
        else
            return -1;
    }


    int Retrieve(T data){
        for (int i = 0; i < m_Length; i++)
        {
            if (m_Array[i] == data)
                return 1;
        }
        return 0;
    }

    /**
    *	@brief  배열이 비었는지 여부
    *	@pre	X
    *	@post	X
    *	@return	비었으면 1, 아니라면 0반환
    */
    int isEmpty()
    {
        if (m_Length == 0)
            return true;
        else
            return false;

    }

    /**
    *	@brief	ID를 통해 기존 레코드의 나이와 주소 삭제
    *	@pre    비교할 m_Array가 존재해야 한다
    *	@post   일치하는 ID의 데이터 삭제
    *	@param  비교할 ID를 담은 data
    *	@return 원하는 ID를 가진 데이터가 존재하여 삭제에 성공하면 1, 존재하지 않아 삭제가 불가능하면 0 리턴
    */
    int Delete(T data)
    {
        bool pandan = false;
        int i;
        for (i = 0; i < m_Length; i++)
        {
            if (m_Array[i] == data)
            {
                pandan = true;
                break;
            }
        }

        if (pandan == true)
        {
            for (int j = i; j < m_Length; j++)
            {
                m_Array[j] = m_Array[j + 1];
            }

//            m_Array[m_Length] = NULL;

            m_Length--;

            return true;
        }
        else
        {
            return false;
        }

    }

    /**
    *	대입 연산자
    */
    ArrayList& operator= (ArrayList & in)
    {
        m_Length = in.m_Length;
        //m_Array = NULL;

        for (int i = 0; i < m_Length; i++)
        {
            m_Array[i] = in.m_Array[i];
        }

        return *this;
    }


    /**
    *	연산자 []
    */
    T operator[](int index)
    {
        return m_Array[index];
    }

    T at(int index){
        return m_Array[index];
    }

private:
    T m_Array[MAXSIZEE];     ///< 리스트 배열(아이디, 이름, 주소)
    int m_Length;			///< 리스트 내에 정보를 담은 갯수
    int m_CurPointer;		///< iterator pointer.
};

#endif // ARRAYLIST_H

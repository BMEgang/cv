#ifndef RANGEARRAY_H
#define RANGEARRAY_H

#include"Array.h"
#include"Exception.h"

namespace DTLib{

template<typename T>
class RangeArray : public Array<T>
{
protected:
    int m_lower;
    int m_upper;
public:
    RangeArray(int lower,int upper)
    {
        this->m_array = new T[upper - lower + 1];

        m_lower = lower;
        m_upper = upper;
    }
    RangeArray(const RangeArray<T>& obj)
    {
        int len = obj.length();

        this->m_array = new T[len];

        for (int i = 0; i < len; i++)
        {
            this->m_array[i] = obj.m_array[i];
        }

        m_lower = obj.m_lower;
        m_upper = obj.m_upper;
        
    }

    RangeArray<T>& operator= (const RangeArray<T>& obj)
    {
        if (this != &obj)
        {
            int len = obj.length();
            T* toDel = this->m_array;
            T* arr = new T[len];

            for (int i = 0; i < len; i++)
            {
                arr[i] = obj.m_array[i];
            }

            m_lower = obj.m_lower;
            m_upper = obj.m_upper;

            this->m_array = arr;

            delete[] toDel;
        }
        
        return *this;
    }

    bool set(int i, const T& e){
        bool ret = ((i >= m_lower) && (i <= m_upper));

        if(ret){
            this->m_array[i-m_lower] = e;
        }

        return ret;
    }

    bool get(int i, T& e) const{
        bool ret = ((i >= m_lower) && (i <= m_upper));

        if(ret){
            e = this->m_array[i-m_lower];
        }

        return ret;
    }

    T& operator [] (int i){
        if((i >= m_lower) && (i <= m_upper)){
            return this->m_array[i-m_lower];
        }else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"Parameter i is invalid...");
        }
        
    }

    T operator [] (int i) const{
        return (const_cast<RangeArray<T>&>(*this))[i];
    }

    int length() const
    {
        return m_upper - m_lower + 1;
    }

    int lower() const
    {
        return m_lower;
    }

    int upper() const
    {
        return m_upper;
    }
};


}

#endif
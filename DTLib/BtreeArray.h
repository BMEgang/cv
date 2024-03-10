#ifndef BTREEARRAY_H
#define BTREEARRAY_H

#include "RangeArray.h"

namespace DTLib
{
    template<typename T>
    class BtreeArray : public Array<T>
    {
    protected:
        RangeArray<T> m_value;
        RangeArray<int> m_mark;
        int m_height; 
    public:
        BtreeArray(int height) : m_value(1,(1 << height)-1),m_mark(m_value.lower(),m_value.upper()), m_height(height)
        {
            for (int i = m_mark.lower(); i <= m_mark.upper(); i++)
            {
                m_mark[i] = 0;
            }

            this->m_array = NULL;
            
        }
        BtreeArray(const BtreeArray<T>& obj) : m_value(obj.m_value), m_mark(obj.m_mark), m_height(obj.m_height)
        {
            this->m_array = NULL;
        }
        BtreeArray<T>& operator= (const BtreeArray<T>& obj)
        {
            if (this != &obj)
            {
                m_value = obj.m_value;
                m_mark = obj.m_mark;
                m_height = obj.m_height;
            }
            
            return *this;
        }

        bool set(int i, const T& e)
        {
            int tmp = 0;
            bool ret = m_mark.get(i,tmp) && ((i == 1) || m_mark[i/2]);

            if (ret)
            {
                m_value[i] = e;
                m_mark[i] = 1;
            }
            
            return ret;
        }

        bool get(int i, T& e) const
        {
            int tmp = 0;
            bool ret = m_mark.get(i,tmp) && m_mark[i];

            if (ret)
            {
                e = m_value[i];
            }
            
            return ret;
        }

        void remove(int i)
        {
            if ((m_mark.lower() <= i) && (i <= m_mark.upper()))
            {
                m_mark[i] = 0;

                remove(left(i));
                remove(right(i));
            }
        }

        void resize(int nh)
        {
            int len = ((1 << nh) - 1);
            RangeArray<T> value(1,len);
            RangeArray<int> mark(1,len);

            for (int i = mark.lower(); i <= mark.upper(); i++)
            {
                mark[i] = 0;
            }

            len = (len < length()) ? len : length();

            for (int i = 1; i <= len; i++)
            {
                value[i] = m_value[i];
                mark[i] = m_mark[i];
            }

            m_value = value;
            m_mark = mark;
            m_height = nh;
        }

        int left(int i) const
        {
            return 2 * i;
        }

        int right(int i) const
        {
            return 2 * i + 1;
        }

        int parent(int i) const
        {
            return i / 2;
        }

        int isNull(int i) const
        {
            return !((1 <= i) && (i <= length()) && m_mark[i]);
        }

        int find(const T& e) const
        {
            int ret = 0;

            for (int i = m_value.lower(); i <= m_value.upper(); i++)
            {
                if (m_mark[i] && (m_value[i] == e))
                {
                    ret = i;
                    break;
                }
                
            }
            
            return ret;
        }

        void clear()
        {
            remove(1);
        }

        T& operator[] (int i)
        {
            if (m_mark[i])
            {
                return m_value[i];
            }
            else
            {
                THROW_EXCEPTION(InvalidOperationException,"Point i is invalid ...");
            }
            
        }

        T operator[] (int i) const
        {
            return (const_cast<BtreeArray<T>&>(*this))[i];
        }

        int height() const
        {
            return m_height;
        }

        int count() const
        {
            int ret = 0;

            for (int i = m_mark.lower(); i <= m_mark.upper(); i++)
            {
                ret += m_mark[i];
            }

            return ret;
        }

        int length() const
        {
            return m_value.length();
        }
    };

}



#endif
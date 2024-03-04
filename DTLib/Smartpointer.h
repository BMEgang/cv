#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include "Pointer.h"

namespace DTLib{
    template<typename T>
    class Smartpointer : public Pointer<T>
    {
    public:
        Smartpointer(T* p = NULL) : Pointer<T>(p){

        }

        Smartpointer(const Smartpointer<T>& obj){
            this->m_pointer = obj.m_pointer;
            const_cast<Smartpointer>(obj).m_pointer = nullptr;
        }

        Smartpointer<T>& operator=(const Smartpointer<T>& obj){
            if (&obj != this)
            {
                T* p = this->m_pointer;
                
                this->m_pointer = obj.m_pointer;
                const_cast<Smartpointer<T>&>(obj).m_pointer = nullptr;

                delete p;
            }
            
            return *this;
        }

        ~Smartpointer(){
            delete this->m_pointer;
        }
    };
    
}

#endif
#include <iostream>
#include <DTLib/ListGraph.h>
#include <DTLib/Exception.h>
#include <DTLib/RangeArray.h>

using namespace std;
using namespace DTLib;


int main() {

    try
    {
        RangeArray<double> ra(-5,10);
        for (int i = ra.lower(); i <= ra.upper(); i++)
        {
            ra[i] = i / 100.0;
        }

        for (int i = ra.lower(); i <= ra.upper(); i++)
        {
            cout << ra[i] << endl;
        }
        
        return 0;
    }
    catch(const Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    
    return 0;
}

#include <iostream>
#include <DTLib/ListGraph.h>
#include <DTLib/Exception.h>
#include <DTLib/DualEndQueue.h>

using namespace std;
using namespace DTLib;

bool IsSym(int n)
{
    DualEndQueue<int> q;

    if (n < 0)
    {
        n = -n;
    }

    while (n)
    {
        q.add(n % 10);
        n /= 10;
    }

    while ((q.length() > 1) && (q.front() == q.back()))
    {
        q.remove();
        q.dismiss();
    }
    
    return (q.length() <= 1);
    
}

int main() {

    try
    {
        cout << IsSym(121) << endl;
        cout << IsSym(2332) << endl;
        cout << IsSym(11) << endl;
        cout << IsSym(2) << endl;
        cout << IsSym(321) << endl;
    }
    catch(const Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    
    return 0;
}

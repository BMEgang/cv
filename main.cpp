#include <iostream>
#include <DTLib/ListGraph.h>
#include <DTLib/Exception.h>
#include <DTLib/BTreeArray.h>

using namespace std;
using namespace DTLib;

int main() {

    try
    {
        BtreeArray<char> bt(3);
        int node = 1;

        bt.set(node,'A');

        cout << "length: " << bt.length() << endl;
        cout << "count: " << bt.count() << endl;

        node = bt.find('A');
        bt.set(bt.left(node),'B');
        bt.set(bt.right(node),'C');

        node = bt.find('C');
        bt.set(bt.left(node),'F');
        bt.set(bt.right(node),'G');

        bt.resize(4);

        cout << "length: " << bt.length() << endl;
        cout << "count: " << bt.count() << endl;

    }
    catch(const Exception& e)
    {
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    
    return 0;
}

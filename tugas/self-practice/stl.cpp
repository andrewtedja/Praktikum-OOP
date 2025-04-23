#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>

int main()
{
    // vector<int> list = {1, 5, 3, 2, 4};
    // vector<int>::iterator it;
    // list.erase(list.begin() + 2);

    // for (it = list.begin(); it != list.end(); ++it)
    // {
    //     cout << *it << " ";
    // }

    map<string, int> m;
    m.insert(pair<string, int>("one", 1));
    m.insert(pair<string, int>("two", 2));
    m.insert(pair<string, int>("three", 3));

    for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        cout << it->first << " " << it->second << endl;
    }

    for (auto pair : m) {
        cout << pair.first << " " << pair.second << endl;
    }

    m.s
}
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    cin.ignore();

    unordered_map<string, string> attributeMap;
    vector<string> tag;

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        line.erase(remove(line.begin(), line.end(), '\"'), line.end());
        line.erase(remove(line.begin(), line.end(), '>'), line.end());

        if (line.substr(0, 2) == "</")
        {
            tag.pop_back();
        }
        else
        {
            stringstream ss;
            ss.str("");
            ss << line;
            string t1, p1, v1;
            char ch;
            ss >> ch >> t1 >> p1 >> ch >> v1;
            string prefix = "";
            if (tag.size() > 0)
            {
                prefix = *tag.rbegin();
                prefix = prefix + "." + t1;
            }
            else
                prefix = t1;
            tag.push_back(prefix);
            attributeMap[*tag.rbegin() + "~" + p1] = v1;
            while (ss)
            {
                ss >> p1 >> ch >> v1;
                attributeMap[*tag.rbegin() + "~" + p1] = v1;
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        string query;
        getline(cin, query);
        if (attributeMap.find(query) == attributeMap.end())
            cout << "Not Found!\n";
        else
            cout << attributeMap[query] << endl;
    }

    return 0;
}
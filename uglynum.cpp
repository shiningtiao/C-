#include <iostream>
#include <vector>

using namespace std;

long long nthuglynum(int n)
{
    vector <long long> v;
    v.push_back(1LL);
    cout << v.back() << endl;
    int i = 0, j =0 ,k = 0;
    int cnt = 0;
    while(cnt < n)
    {
        long long curr = min(min(v[i]*3,v[j]*5),v[k]*7);
        cout << curr << endl;
        v.push_back(curr);
        while(v[i]*3 <= curr) i++;
        while(v[j]*5 <= curr) j++;
        while(v[k]*7 <= curr) k++;
    }
    return v.back();
}

int main()
{
    int x;
    cin >> x;
    cout << nthuglynum(x);
}

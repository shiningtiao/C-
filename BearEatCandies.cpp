#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Bear{
    int fight;
    int hunger;
    int id;
    friend bool operator < (Bear a, Bear b){
    return  a.fight > b.fight;
    }
};
int cand[100];
Bear bear[10];
bool flag[100];
int ans[10];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> cand[i];
    for(int i =0 ; i < n; i++)
    {
        cin >> bear[i].fight >> bear[i].hunger;
        bear[i].id = i;
    }
    sort(bear, bear+n);
    for(int i = 0; i < n; i++){
        int index = -1;
        for(int j = 0 ; j < m; j++)
        {
            if(!flag[j] && cand[j] <= bear[i].hunger && (index == -1 || cand[j] > cand[index]))
                index = j;
        }
        if(index != -1)
        {
            bear[i].hunger -= cand[index];
            flag[index] = true;
            --i;
        }
        else
            ans[bear[i].id] = bear[i].hunger;
    }
    for(int i = 0 ; i < n; i++)
        cout << ans[i] <<endl;

}



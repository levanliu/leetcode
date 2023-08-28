#include<bits/stdc++.h>
using namespace std;


vector<string> compress(vector<string> source)
{
    vector<string> target;

    map<string,int> hm;

    int index = 1;
    vector<int> temp;
    for(string s:source){
        hm[s] = index++;
        temp.push_back(hm[s]);
    }



    

    return target;
}

int main(){
    vector<string> source{
        "absou","absou","142bs","bsoup","bsoup"
        "absou","142bs","bsoup","absou","142bs","bsoup"
    };
    vector<string> target =
        compress(source);
    for(string t:target) cout << t << " ";
    cout << endl;
    return 0;
}
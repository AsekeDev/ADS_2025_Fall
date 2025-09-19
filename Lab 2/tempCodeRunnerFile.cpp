#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char>v;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        queue<char>q;
        for(int j = 0; j < m; j++){
            char c;
            cin >> c;
            if(q.empty()){
                cout << c << " ";
                q.push(c);
                continue;
            }
            if(q.front() != c){
                cout << q.front() << " ";

            }else{
                q.pop();
                if(q.empty()){
                    cout << -1 << " ";
                }else{
                    cout << q.front() << " ";
                }

            }
    }
}


    return 0;
}
// oh, it may go wrong... get time limit exceeded

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <string.h>

using namespace std;

class Solution {
public:
    vector<string> sodu;
    bool filled[10][10];
    bool ok[10][10][10];
    
    int getChoice(int i, int j){
        int counter = 0;
        for(int k=1; k<=9; k++){
            if(ok[i][j][k]==true)
                counter++;
        }
        return counter;
    }
    
    void update(int r, int c, int num){
        sodu[r][c] = num+'0';
        for(int i=0; i<10; i++){
            ok[r][i][num]=false;
            ok[i][c][num]=false;
        }
        // block status
        int sx=3*(r/3), sy=3*(c/3);
        for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            ok[i+sx][j+sy][num]=false;
        return;
    }
    
    void solveSudoku(vector<string> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sodu = board;   
        memset(filled, false, sizeof(filled));
        memset(ok, true, sizeof(ok));
        for(int i=0; i<9; i++)
        for(int j=0; j<9; j++){
            if(sodu[i][j]!='0'){
                int num = sodu[i][j]-'0';
                filled[i][j]=true;
                update(i, j, num);
            }
        }
        
        while(true){
            pair<int, int> pos;
            int choice = 20;
            for(int i=0; i<9; i++)
            for(int j=0; j<9; j++){
                if(choice == 1)
                    break;
                if(filled[i][j]==false && sodu[i][j]=='0' && getChoice(i, j)<choice){
                    choice = getChoice(i, j);
                    pos = make_pair(i,  j);
                }
            }
            if(choice == 20)
                break;
            else{
                cout<<"here: "<<pos.first<<" "<<pos.second<<" "<<choice<<endl;
                for(int i=0; i<9; i++)
                    cout<<sodu[i]<<endl;
                if(pos==make_pair(7, 6) && choice==0)
                    return;
                for(int i=1; i<=9; i++){
                    if(ok[pos.first][pos.second][i]==true){
                        filled[pos.first][pos.second] = true;
                        update(pos.first, pos.second, i);
                        break;
                    }
                }
            }// end else clause
        }// end while loop
        
        board = sodu;
        return;
        
    }
};

int main(){
    int t;
    cin>>t;
    string tmp;
    Solution s;
    while(t--){
        vector<string> boa;
        boa.clear();
        for(int i=0; i<9; i++){
            cin>>tmp;
            boa.push_back(tmp);
        }
        s.solveSudoku(boa);
        for(int i=0; i<9; i++)
            cout<<s.sodu[i]<<endl;
    }
    system("pause");
    return 0;
}

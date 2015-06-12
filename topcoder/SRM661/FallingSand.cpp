#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class FallingSand {
public:
    vector <string> simulate(vector <string>);
};

vector <string> FallingSand::simulate(vector <string> board) {
    int row = board.size(), col = board[0].size();
    for (int i = row - 1; i >= 0; --i) {
        for (int j = col - 1; j >= 0; --j) {
            if (board[i][j] == 'o') {
                int ptr = i + 1;
                while (ptr < row && board[ptr][j] == '.') ++ptr;
                swap(board[i][j], board[ptr - 1][j]);
            }
        }
    }
    return board;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!

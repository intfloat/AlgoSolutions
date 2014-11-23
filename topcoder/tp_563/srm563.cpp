/**division 2 problem1
 *the key point is use the substr() function correctly *
 *
 */
string isPossible(string S, string T)
{
    for (int i=0; i < S.length(); i++) {
	//substr(begin,length)
	//if no length parameter, you will get a substr 
	//to the end
        string V = S.substr(0,i) + S + S.substr(i);
        if (V==T) {
            return "Yes";
        }
    }
    return "No";
}
/**division2 problem 2
 *I correctly solved it, but it didn't need to copy all the board information,
 *we can pass four parameters every time or record the coordinates in 
 *global variables
 */
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
struct CoinsGameEasy
{
    vector<string> board;
    int coinx[2];
    int coiny[2];
    int minSteps;
    
    void rec(int steps)
    {
        // save a backup of the current coin positions:
        int bx[2], by[2];
        for (int i=0; i<2; i++) {
            bx[i] = coinx[i]; by[i] = coiny[i];
        }

        for (int d=0; d < 4; d++) {
            int offBoard = 0;
            for (int i=0; i<2; i++) {
                // Update the coins' positions after moving in direction d:
                coinx[i] = bx[i] + dx[d];
                coiny[i] = by[i] + dy[d];
                
                // Will the coin end outside the board?
                if (  coinx[i] < 0 || coinx[i] >= board.size()
                   || coiny[i] < 0 || coiny[i] >= board[0].size() ) {
                        offBoard++;
                } else if ( board[coinx[i]][coiny[i]] == '#' ) {
                    // Else update the position:
                    coinx[i] = bx[i];
                    coiny[i] = by[i];
                }
            }
            // If exactly one coin falls outside the board, then a 
            // valid sequence of moves of length (steps+1) exists.
            if (offBoard == 1) {
                minSteps = std::min(minSteps, steps + 1);
            } else if ( (offBoard == 0) && (steps + 1 < minSteps) ) {
                // Else continue the recursion, increasing the number of steps
                rec(steps + 1);
            }
        }
        // Restore the backup:
        for (int i=0; i<2; i++) {
            coinx[i] = bx[i]; coiny[i] = by[i];
        }
    }
    
    int minimalSteps(vector <string> board)
    {
        coinx[0] = -1;
        // Find the two positions of the coins
        int t = 0;
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == 'o') {
                    coinx[t] = i;
                    coiny[t++] = j;
                }
            }
        }
        this->board = board;
        minSteps = 11;
        //A large value, so we can detect when no sequence of moves is valid
        rec(0);
        return (minSteps == 11) ? -1 : minSteps;
    }
};
/**division2 problem3
 *a excellent dynamic programming problem
 *very worth leanring
 *from recursion to dp and remeber all the visited states
 */
int n; 
vector<int> lvl, dmg; 
 
int dp[MAX+1][MAX+1]; 
 
int rec(int p, int owed) 
{ 
    int & res = dp[p][owed]; 
    if (res == -1) { 
        if (n - p == owed) { 
            // base case. There are only owed cards left.
            res = 0;
        } else { 
            // Do not use the card. Decrease owed if necessary.
            res = rec(p+1, std::max(owed - 1, 0) ); 

            // Use the card? 
            //  The new number of owed cards must not exceed the number of
            //  remaining cards:
            if (owed + lvl[p] - 1 <= n - p - 1) { 
                res = std::max(res, dmg[p] + rec(p+1, owed + lvl[p] - 1 ) ); 
            } 
        } 
    } 
    return res; 
} 
int maxDamage(vector <int> level, vector <int> damage)
{
    // Initialize memoization table with -1
    memset(dp, -1, sizeof(dp));
    n = level.size();
    lvl = level;
    dmg = damage;
    return rec(0, 0);
}


class Solution {
public:
    int findMinMoves(vector<int>& machines) {

        int moves = 0, N = machines.size();
        int clothes = accumulate(machines.begin(), machines.end(), 0);
        if(clothes % N) return -1;

        int avg = clothes / N, transfer = 0;
        for(const int& machine: machines) {
            transfer += machine - avg;
            moves = max(moves, max(abs(transfer), machine - avg));
        }

        return moves;
    }
};

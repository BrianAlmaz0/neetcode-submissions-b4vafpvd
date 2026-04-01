class Solution {
public:
    int find(vector<int>& par, int node){
        int p = par[node];

        //Keep going up until it's not it's own parent
        while(p != par[p]){
            par[p] = par[par[p]]; //Compression
            p = par[p];
        }
        return p;
    }

    bool Union(vector<int>& par, vector<int>& rank, int n1, int n2){
        int p1 = find(par, n1);
        int p2 = find(par, n2);

        if(p1 == p2) return true;

        if(rank[p1] >= rank[p2]){
            rank[p1] += rank[p2];
            par[p2] = par[p1];
        } else{
            rank[p2] += rank[p1];
            par[p1] = par[p2];
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n + 1);
        vector<int> rank(n + 1, 1);

        for(int i = 0; i <= n; i++){
            par[i] = i;
        }

        for(auto& edge : edges){
            int n1 = edge[0];
            int n2 = edge[1];

            if(Union(par, rank, n1, n2)){
                return {n1, n2};
            }
        }
        return {};
    }
};

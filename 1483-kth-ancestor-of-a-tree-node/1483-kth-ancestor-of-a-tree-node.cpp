class TreeAncestor {
public: 
    vector<vector<int>>up;
    TreeAncestor(int n, vector<int>& parent) {
        up.resize(n, vector<int>(20, -1));

        for(int i=0;i<n;i++){
            up[i][0]=parent[i];
        }

        for(int i=1;i<20;i++){
            for(int node = 0; node<n;node++){
                if(up[node][i-1] == -1){
                    up[node][i] = -1;
                }else{
                    up[node][i]= up[up[node][i-1]][i-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i=19; i>=0;i--){
            if((k&(1<<i))){
                node=up[node][i];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
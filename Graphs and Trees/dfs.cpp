void dfs(int vertex, int par, int idx){
    for(auto &child : graph[vertex]){
        if(child.first==par)continue;
        if(child.second>idx){
            val[child.first]=val[vertex];
        }
        else{
            val[child.first]=val[vertex]+1;
        }
        dfs(child.first,vertex, child.second);
    }
}
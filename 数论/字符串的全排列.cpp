class Solution {
	vector<string> ans; 
	void dfs(string str, int dep){
		if(dep == str.size() - 1) { //递归终止条件：搜索到字符串最后一位 
			ans.push_back(str);
		}
		else{
			
			sort(str.begin()+dep,str.end()); //为了保证按照字典序输出 
			//cout<<str<<endl<<endl;
			for(int i = dep  ; i < str.size();i++){
				char c = str[dep];
				if(i == dep || str[i] != c){
					str[dep] = str[i];
					str[i] = c;
					dfs(str,dep+1); //递归搜索
					c = str[dep]; //复原，因为还有下一个搜索子节点 
					str[dep] = str[i];
					str[i] = c;
				}
			} 
		}
	}
public:
    vector<string> Permutation(string str) {
        ans.clear();
        dfs(str,0);
        return ans; 
    }
};

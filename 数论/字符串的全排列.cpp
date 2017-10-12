class Solution {
	vector<string> ans; 
	void dfs(string str, int dep){
		if(dep == str.size() - 1) { //�ݹ���ֹ�������������ַ������һλ 
			ans.push_back(str);
		}
		else{
			
			sort(str.begin()+dep,str.end()); //Ϊ�˱�֤�����ֵ������ 
			//cout<<str<<endl<<endl;
			for(int i = dep  ; i < str.size();i++){
				char c = str[dep];
				if(i == dep || str[i] != c){
					str[dep] = str[i];
					str[i] = c;
					dfs(str,dep+1); //�ݹ�����
					c = str[dep]; //��ԭ����Ϊ������һ�������ӽڵ� 
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

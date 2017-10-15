/*
假设我们有n种不同面值的硬币｛1，2，5，10，20，50，100，200｝，用这些硬币组合够成一个给定的数值n
有多少种组合方案？  每种硬币都是无限枚
参考： http://blog.csdn.net/qiaoqiao0609/article/details/50830992
*/
/*
本例问题： 有数量不限的硬币，币值为25分、10分、5分和1分，请编写代码计算n分有几种表示法。
给定一个int n，请返回n分有几种表示法。保证n小于等于100000，为了防止溢出，请将答案Mod 1000000007。 
*/ 
class Coins {  
public:  
    int countWays(int n) {  
        // write code here  
        int coins[4]={1,5,10,25};  
        int dp[100001] = {0};         
        dp[0] = 1;  
        for(int i = 0;i < 4;++i){  
            for(int j = coins[i];j <= n;++j){  
                dp[j] =(dp[j]+dp[j-coins[i]])%1000000007;                 
            }  
        }  
        return dp[n];  
    }  
};  

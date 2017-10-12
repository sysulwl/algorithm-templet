struct one_two{
	int first,second;
	one_two() {}
	one_two(int  _first,int _second):first(_first),second(_second) {}
};
struct two_two{
	int a11,a12,a21,a22;
	two_two() {}
	two_two(int _a11,int _a12,int  _a21,int _a22):
	a11(_a11),a12(_a12),a21(_a21),a22(_a22) {}
};
class Solution {
public:
    int climbStairs(int n) {
   	//printf("n = %d\n",n);
	struct one_two f2 = one_two(1,1);
	struct two_two num = two_two(1,1,1,0);
	n -= 1;
	while(n > 0){
		if(n%2 == 1) {
			f2 = mul1(num,f2);
		}
		num  = mul2(num,num);
		n /= 2;
		//printf("this is num:\n[%d %d\n%d %d]\n",num.a11,num.a12,num.a21,num.a22);
		//printf("this is f2:\n");
		//cout<<f2.first<<" "<<f2.second<<endl;
	}
	
	return f2.first;
    }
private:
	struct one_two mul1(struct two_two left,struct one_two right){
		struct one_two temp = 
			one_two(left.a11 * right.first + left.a12 * right.second,
				left.a21 * right.first + left.a22 * right.second);
		return temp;
	}
	struct two_two mul2(struct two_two left,struct two_two right){
                struct two_two  temp = 
                        two_two(left.a11 * right.a11 + left.a12 * right.a21,
				left.a11 * right.a21 + left.a12 * right.a22,
				left.a21 * right.a11 + left.a22 * right.a21,
				left.a21 * right.a12 + left.a22 * right.a22);
                return temp;
        }

};


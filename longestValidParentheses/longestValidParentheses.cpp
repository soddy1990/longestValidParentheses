#include <iostream>
using namespace std;


int longestValidParentheses(string s) {
	int n = s.length();
	if(n<=1){
		return 0; 
	}
	int max_l = 0;
	int i = 0;
	int start = 0;
	int check = 0;

	while(i < n && s.at(i) != '('){
		i++;
	}
	if(i < n){
		start = i;
		check++;
		i++;
		while(check >= 0 && i < n){
			if(s.at(i) == '('){
				check++;
				i++;
			}else if(s.at(i) == ')'){
				check--;
				if(check == 0){
					max_l = max_l>(i - start + 1)? max_l:(i - start + 1);
					i++;
				}else if(check > 0){
					i++;
				}else{
					check = 0;
					while(i<n && s.at(i) != '('){
						i++;
					}
					if(i+1 >= n){
						break;
					}
					start = i;
				}
			}
		}
	}
	int max_r = 0;
	i = n-1;
	int end = i;
	check = 0;

	while(i>=0 && s.at(i) != ')'){
		i--;
	}
	if(i >= 0){
		end = i;
		check++;
		i--;

		while(check >= 0 && i>=0){
			if(s.at(i) == ')'){
				check++;
				i--;
			}else if(s.at(i) == '('){
				check--;
				if(check == 0){
					max_r = max_r>(end - i + 1)? max_r:(end - i + 1);
					i--;
				}else if(check > 0){
					i--;
				}else{
					check = 0;
					while(i >= 0 && s.at(i) != ')'){
						i--;
					}
					if(i <= 0){
						break;
					}
					end = i;
				}
			}
		}
	}
	return max(max_l,max_r);
}

int main() {
	string source = "((((((";
	cout<<longestValidParentheses(source);
	getchar();
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int length(int src){
	if(src >=1000000)
		return -1;
	else if(src >=100000)
		return 6;
	else if(src >=10000)
		return 5;
	else if(src >=1000)
		return 4;
	else if(src >=100)
		return 3;
	else if(src >=10)
		return 2;
	else if(src >=0)
		return 1;
	else
		return -1;
}

int max_winning(int source,int digits,int exchange_number);
void swap(pair<int, int> &x,pair<int, int> &y){
	int tmp;
	tmp = x.second;
	x.second = y.second;
	y.second = tmp;
}
bool cmp(const pair<int, int> &x, const pair<int, int> &y){
	return x.second < y.second;
}
int main(){
	int number;
	cin >> number;
	int src,dest,exchange_num;
	for(int i=1; i<=number;i++){
		cin >> src >> exchange_num;
		int digits = length(src);
		cout <<"digit is : "<<digits<<endl;
		if(digits == -1)
			break;
		else{
			int result = max_winning(src,digits,exchange_num);
			cout << "#"<< i<<" "<<result<<endl;
		}
	}
	return 0;
}
int max_winning(int source,int digits,int exchange_number){
	vector<pair<int,int> > list_of_nums;
	list_of_nums.push_back(make_pair(0,0));
	cout <<"list of vector first is:"<<list_of_nums[0].first<<"second is : "<<list_of_nums[0].second<<endl;
	int count = exchange_number;
	int _digits = digits;
	int _source= source;
	int divided = 10;
	int dividen = source;
	if(_digits == 1)
		return _source;
	for(int i=1; i<=digits;i++){
		int remainder = dividen % divided;
		dividen /= divided;
		list_of_nums.push_back(make_pair(remainder,i));
	}
	sort(list_of_nums.begin(),list_of_nums.end()); //sorting for first.
	for(int i =1;i<=count;){	
		int inserted_digit = _digits+1-i;
		if(inserted_digit == 1)
			break;
		if(list_of_nums[inserted_digit].second != inserted_digit){
			int index = 1;
			while(list_of_nums[index].second != inserted_digit)
				index++;
			swap(list_of_nums[index],list_of_nums[inserted_digit]);
			i++;
		}
		else
			_digits--; //if it has not changed, then digits is minus.
	}
	sort(list_of_nums.begin(),list_of_nums.end(),cmp); //sorting for second.
	string result = "";
	for(int i=1;i<=digits;i++){
		result = to_string(list_of_nums[i].first) +result;
	}
	return atoi(result.c_str());
}

#include <iostream>
using namespace std;
int main()
{
	int number, Board[21][21] = { 0, }, i, j;
	int n;
	number = 1;
	 cout<< "enter the number of cell. n must be odd number."<<endl;;
	 cin >> n;
	if(n < 2 || n % 2 ==0 ){
		cout<< " you input odd number,the program exits"<<endl;
		return 0;
	}
	i = 0;
	j = (n-1)/2;
	Board[i][j] = number;
	while(number < n*n){
		i-=1;
		j+=1;
		if(number%n ==0){
			i +=2;
			j -=1;
			Board[i][j] = ++number;
		}
		else {
			if(i==-1){
				i= n -1;
				Board[i][j] = ++number;
			}
			else if(j==n){
				j=0;
				Board[i][j] = ++number;
			} 
			else
				Board[i][j] = ++number;
			
		}
	} 
	for (int sa = 0; sa <n; ++sa)
	{
		for (int ja = 0; ja < n; ++ja)
		{
			cout << Board[sa][ja] << " ";
		}
		cout << endl;
	}
	return 0;
} 

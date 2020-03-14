#include <iostream>
#include <stdio.h>
using namespace std;
int* assembly_line(int* a1, int* a2, int* t1, int* t2,int station,int e1,int e2,int x1,int x2);
int main(){
	int station;
	int e1, e2;
	int x1, x2;
	int* a1, * a2;
	int* t1, * t2;	
	cin >> station;
	cin >> e1 >> e2;
	cin >> x1 >> x2;
	a1 = new int[station+1];
	a2 = new int[station+1];
	t1 = new int[station];
	t2 = new int[station];
	a1[0] = 0, a2[0] = 0, t1[0] = 0, t2[0] = 0;
	for (int i = 1; i < station+1; i++)
		cin >> a1[i];
	for (int i = 1; i < station+1; i++)
		cin >> a2[i];
	for (int i = 1; i < station; i++)
		cin >> t1[i];
	for (int i = 1; i < station; i++)
		cin >> t2[i];
	int* result = assembly_line(a1, a2, t1, t2, station, e1, e2, x1, x2);
	cout << result[0] << endl;
	for (int i = 1; i <= station; i++)
		cout << result[i] << " " << i << endl;
}

int* assembly_line(int* a1, int* a2, int* t1, int* t2, int station, int e1, int e2, int x1, int x2)
{
	int index = 0;
	int compare_index = 1;
	int temp_index,l;
	int time[2][2];
	int* result;
	result = new int[station + 1];
	int* line1 = new int[station+1];
	int* line2 = new int[station+1];
	time[0][0] = a1[1] + e1;
	time[1][0] = a2[1] + e2;
	for (int i = 1; i < station; i++) {
		if (time[0][index] + a1[i+1] > time[1][index] + t2[i] + a1[i+1]) {
			line1[i] = 2;
			time[0][compare_index] = time[1][index] + t2[i]+a1[i+1];
		}
		else {
			line1[i] = 1;
			time[0][compare_index] = time[0][index] + a1[i + 1];
		}
		if (time[1][index] + a2[i + 1] > time[0][index] + a2[i+1] +t1[i]) {
			line2[i] = 1;
			time[1][compare_index] = time[0][index] + a2[i+1] + t1[i];
			temp_index = index, index = compare_index, compare_index = temp_index;
		}
		else {
			line2[i] = 2;
			time[1][compare_index] = time[1][index] + a2[i+1];
			temp_index = index, index = compare_index, compare_index = temp_index;
		}
	}
	if (time[0][index] + x1 > time[1][index] + x2){
		result[0] = time[1][index] + x2;
		result[station] = 2;
		l = 2;
	}
	else{
		result[0] = time[0][index] + x1;
		result[station] = 1;
		l = 1;
	}
	for (int i = station - 1; i > 0; i--) {
		if (l == 1) {
			l = line1[i];
			result[i] = l;
		}
		else {
			l = line2[i];
			result[i] = l;
		}
	}
	return result;
}

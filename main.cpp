#include <iostream>
#include <vector>
#include "frac.h"
using namespace std;

bool isEnd(vector<Fraction> fLine){
	for(auto &el:fLine)if(el<0)return false;
	return true;
}

int minIndexInRow(vector<Fraction> mass){
	int minPos = 0;
	for(int c=0;c<mass.size();c++){
		if(mass[c]<mass[minPos])minPos = c;
	}
	return minPos;
}

int redRow(vector<vector<Fraction> > mass, int col){
	int minPos = 0;
	// cout<<'~'<<endl;
	for(int c=0;c<mass.size();c++){
		if(mass[c][col]<0)continue;
		if(mass[c].back()/mass[c][col]<mass[minPos].back()/mass[minPos][col])minPos = c;
		// cout<<mass[c].back()/mass[c][col]<<'='<<(double)(mass[c].back()/mass[c][col])<<endl;
	}
	return minPos;
}

void print(vector<vector<Fraction> > mass){
	cout<<"--------------------------------------------"<<endl;
	for(auto &row:mass){
		for(auto &el:row){
			cout<<el<<'\t';
		}
		cout<<endl;
	}
}

void print(vector<Fraction> mass){
	for(auto &el:mass)cout<<el<<'\t';
	cout<<endl;
}

int main(){
	vector<Fraction> fLine = /* F*/  	 {-1, -2, 0, 0, 0, 0, 0, 0};
																	//x1, x2, x3, S1, S2, S3, Res 
	vector<vector<Fraction> > matrix = {
																	 {-1, 1, 1, 0, 0, 0, 0, 8},
																	 {0, 1, 0, 1, 0, 0, 0, 12},
																	 {1, 1, 0, 0, 1, 0, 0, 17},
																	 {1, -2, 0, 0, 0, 1, 0, 2},
																	 {1, 0, 0, 0, 0, 0, 1, 10}};
	// 	vector<Fraction> fLine = /* F*/  	 {10, -7, -5, 0, 0, 0, 0};
	// 																//x1, x2, x3, S1, S2, S3, Res 
	// vector<vector<Fraction> > matrix = {
	// 																 {6, 15, 6, 1, 0, 0, 9},
	// 																 {14, 42, 16, 0, 1, 0, 21},
	// 																 {2, 8, 2, 0, 0, 1, 4}};
	while(!isEnd(fLine)){
		print(matrix);
		print(fLine);
		int col = minIndexInRow(fLine);
		int row = redRow(matrix, col);
		// cout<<"col row "<<col<<' '<<row<<endl;
		Fraction d = matrix[row][col];
		// cout<<"d="<<d<<endl;
		for(auto &el:matrix[row]){
			// cout<<el<<' ';
			el/=d;
			// cout<<el<<endl;
		}
		print(matrix);
		print(fLine);
		for(int c=0;c<matrix.size();c++){
			if(c==row)continue;
			Fraction d = matrix[c][col];
			for(int c1=0;c1<matrix[c].size();c1++){
				//cout<<matrix[c][c1]<<"-("<<matrix[row][c1]<<'*'<<d<<")=";
				matrix[c][c1] = matrix[c][c1] - (matrix[row][c1]*d);
				//cout<<matrix[c][c1]<<endl;
			}
		}
		d = fLine[col];
		for(int c=0;c<fLine.size();c++){
			fLine[c] = fLine[c] - (matrix[row][c]*d);
		}
		print(matrix);
		print(fLine);
		cout<<"==================================================="<<endl;
		// int r;
		// cin>>r;
	}
	return 0;
}
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>

using namespace std;

int main(){
	srand(time(0));
	int N;
	cout << "Please enter the number of unknown" << endl;
	cin >> N;
	cout << endl;
	//生成 N x N 的方陣，儲存係數用 
	double**ary = new double*[N];
	for( int i = 0; i < N; i++){
		ary[i] = new double [N];
	}
	
	for (int i = 0; i < N; i++){
		for ( int j = 0; j < N; j++){
			ary[i][j] = rand() % 21 - 10;
		}
	}
	
	//輸出係數的方陣 
	cout << "The matrix of coeffients of variables is" << endl;
	for( int i = 0; i < N; i++){
		cout << endl;
		for( int j = 0; j < N; j++){
			cout << setw(2) << ary[i][j] << " ";
		}
	} 
	
	//隨機生成方程式的常數並輸出 
	cout << endl << endl << "The matrix of equivalent sums are " << endl;
	double *sum = 0;
	sum = new double [N];
	for ( int i = 0; i < N; i++){
		sum[i] = rand() % 21 - 10; 
	}
	
	for ( int i = 0; i < N; i++){
		cout << setw(2) << sum[i] << endl; 
	} 
	
	cout << endl;
	
	double factor = 0; 
	//使用高斯消去法將係數方陣的下三角消為零 
	for( int i = 0; i < N; i++){
		for ( int j = i + 1; j < N; j++){
			factor = ary[j][i] / ary[i][i];
			sum[j] -= factor * sum[i];
			for (int k = 0; k < N; k++){
				ary[j][k] -= ary[i][k]*factor;
			}
		}
    }

	//使用高斯消去法將係數方陣的上三角消為零 
	for( int i = N - 1; i >= 0; i--){
		for ( int j = i - 1; j >= 0; j--){
			factor = ary[j][i] / ary[i][i];
			sum[j] -= factor * sum[i];
			for (int k = 0; k < N; k++){
				ary[j][k] -= ary[i][k]*factor;
		    }
		}
	}
	
	//將每一列的常數除以每一列變數的係數可得變數的 
	cout << endl << "The solutions in this set of linear equations with " << N << " unknowns are" << endl;
	
	for( int i = 0; i < N; i++){
		cout << sum[i] / ary[i][i] << endl;
	}
	//清除記憶體 
	for ( int i = 0; i < N; i++){
		delete ary[i];
	}
	delete[]ary;
	
	for ( int i = 0; i < N; i++){
		delete ary[i];
	}
	delete[]ary;
	
	delete []sum;
} 

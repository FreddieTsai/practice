#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

double calculate_area(int *point1, int *point2, int *point3); //計算面積函式 

int main(){
	
    srand(time(0));
	int cord[8][2]; //以二維陣列存取8個座標 
	
	int i, j, k, x[8], y[8];
	for(i = 1; i<=8; i++){
		//生成8個不同的x座標 
		do{
			cord[i-1][0]=rand()% 19 - 9; 
			//以for迴圈檢查座標有沒有和前面生成的重複 
			for(j = 1; j <= i; j++){  
				if(cord[i-1][0]==cord[j-1][0]){
					break;
				}
			}
		} while(j!=i);
		
		//生成8個不同的y座標 
		do{
			cord[i-1][1]=rand()% 19 - 9;
			//以for迴圈檢查座標有沒有和前面生成的重複 
			for(k = 1; k <= i; k++){
				if(cord[i-1][1]==cord[k-1][1]){
					break;
				}
			}
		} while(k != i);
		cout << cord[i-1][0] << "," << cord[i - 1][1]<< endl;
	}
	
	cout << endl;
	
	double dis[7][7] = {0};
	int t = 0, dsquare = 0 ; // 用 7x7 二維陣列存取兩點間距離  
	for(int n = 0; n < 8; n++){
		int s = n ; 
		
		for( int i = n + 1; i < 8; i++){
			dsquare = 0;
			for( int j = 0; j < 2; j++){
			int a = cord[i][j]-cord[n][j];//逐次做x座標相減、y座標相減 
			dsquare += a*a; //算出距離平方 
		    }
		    //將算出的距離平方開根號，存到距離 
		    double d = sqrt(dsquare); 
			dis[t][s] = d;  
			//cout << dis[t][s] << " ";
			s++;
		}
		//cout << endl;
		t++;
	}
	
	//找出最大的距離 
	cout << endl;
	double max = dis[0][0];
	for( int i = 0; i < 7; i++){
		for( int j = 0; j < 7; j++){
			if ( dis[i][j] > max){
				max = dis[i][j];
			}
		}
	}
	
	cout << "maximum distance is "<< max;
	
	cout << endl;
	cout << "The coordinate are below " << endl;
	 //依據存取距離的方式可以推論構成最大距離的座標由誰組成 
	for( int i = 0; i < 7; i++){
		for( int j = 0; j < 7; j++){
			if ( dis[i][j] == max){ 
				cout << cord[i][0] << "," << cord[i][1] << " ";
				/*for( int m = 0; m < 2; m++){
					cout << cord[i][m] << " ";
				} */
				cout << " and ";
				for( int n = 0; n < 2; n++){
					cout << cord[j][n] << " ";
				} 
			}
		}
	}
	cout << endl;
	
	//找出最小的距離
	cout << endl;
	double min = dis[0][0];
	for( int i = 0; i < 7; i++){
		for( int j = 0; j < 7; j++){
			if ( dis[i][j] < min && dis[i][j] != 0){
				min = dis[i][j];
			}
		}
	}
	
	cout << "minimum distance is "<< min;
	cout << endl;
	
	//依據存取距離的方式可以推論構成最大距離的座標由誰組成 
	cout << "The coordinate are below " << endl;
	
	for( int i = 0; i < 7; i++){
		for( int j = 0; j < 7; j++){
			if ( dis[i][j] == min && dis[i][j] != 0){
				cout << cord[i][0] << "," << cord[i][1] << " ";
				cout << " and ";
				for( int n = 0; n < 2; n++){
					cout << cord[j][n] << " ";
				} 
			}
		}
	}
	
	//算面積 
	cout << endl;
	double min_area = 100000000, max_area = 0;
	int min_area_points[3] = {0}, max_area_points[3] = {0};
	
	cout << endl;
	
	for(int i = 0; i < 8; i++){
		for(int j = i+1; j < 8; j++){
			for(int k = j+1; k < 8; k++){
				int *p1 = cord[i]; //指定第一組座標 
				int *p2 = cord[j]; //指定第二組座標  
				int *p3 = cord[k]; //指定第三組座標  
				double area = calculate_area(p1, p2, p3); //傳送三個點給計算面積的函式 
				//找最小面積 
				if(area <= min_area && area != 0){ 
					min_area = area;
					min_area_points[0] = i;
					min_area_points[1] = j;
					min_area_points[2] = k;
				
				}
				//找最大面積 
				if(area >= max_area){
					max_area = area;
					max_area_points[0] = i;
					max_area_points[1] = j;
					max_area_points[2] = k;   
				}
			} 
		}
	}
	cout << endl;
	//輸出構成最大三角形的三個點 
	cout << "maximum area of triangle is " <<  max_area << endl;
	cout << cord[max_area_points[0]][0] << "," <<  cord[max_area_points[0]][1] ;
	cout << " & " << cord[max_area_points[1]][0] << "," <<  cord[max_area_points[1]][1] ;
	cout << " & " << cord[max_area_points[2]][0] << "," <<  cord[max_area_points[2]][1] ;
	
	cout << endl << endl;
	//輸出構成最大三角形的三個點
	cout << "minimum area of triangle is " <<  min_area << endl;
	cout << cord[min_area_points[0]][0] << "," <<  cord[min_area_points[0]][1] ;
	cout << " & " << cord[min_area_points[1]][0] << "," <<  cord[min_area_points[1]][1] ;
	cout << " & " << cord[min_area_points[2]][0] << "," <<  cord[min_area_points[2]][1] ;
}
 

double calculate_area(int *point1, int *point2, int *point3){
	double area = 0;
	
	int point1_x = point1[0];
	int point1_y = point1[1];
	
	int point2_x = point2[0];
	int point2_y = point2[1];
	
	int point3_x = point3[0];
	int point3_y = point3[1];
	
	//分別計算兩點間的距離 
	int square_distance_1_2 = (point1_x - point2_x) * (point1_x - point2_x) + (point1_y - point2_y) * (point1_y - point2_y) ;
	int square_distance_3_2 = (point3_x - point2_x) * (point3_x - point2_x) + (point3_y - point2_y) * (point3_y - point2_y) ;
	int square_distance_1_3 = (point1_x - point3_x) * (point1_x - point3_x) + (point1_y - point3_y) * (point1_y - point3_y) ;
	
	double distance_1_2 = sqrt(square_distance_1_2);
	double distance_3_2 = sqrt(square_distance_3_2);
	double distance_1_3 = sqrt(square_distance_1_3);
	
	double half_parameter = (distance_1_2 + distance_3_2 + distance_1_3)*0.5; // half_parameter為三角形半周長 
	
	// 半周長與三邊的差 
	double half_parameter_minus_distance_1_2 = half_parameter - distance_1_2; 
	double half_parameter_minus_distance_3_2 = half_parameter - distance_3_2;
	double half_parameter_minus_distance_1_3 = half_parameter - distance_1_3;
	
	//以海龍公式計算 
	double haron = half_parameter*half_parameter_minus_distance_1_2*half_parameter_minus_distance_3_2*half_parameter_minus_distance_1_3; 
	area = sqrt(haron);  

	return area;
}

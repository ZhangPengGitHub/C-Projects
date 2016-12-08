#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
     
int main () {	
	int num = 0;
	int i = 0,j = 0;
	int m = 0,n = 0;

	int result1 = 0,result2 = 0;

	char buffer[20][10];
	for(int x=0;x<20;x++){
		for(int y=0;y<10;y++){
			buffer[x][y]=0;
		}
	}
	for(int x=0;x<20;x++){
		cout<<buffer[x]<<endl;
	}
    ifstream file("test.txt");
	if (! file.is_open()){ 
		cout << "Error opening file"; exit (1); 
	}
    while (! file.eof() ) {
		file >> buffer[num];
		num++;
	}
	file.close();
	for(int x=0;x<20;x++){
		cout<<buffer[x]<<endl;
	}
	i = 0;
	while(i<num){
		j = 0;
		while(buffer[i][j]!=0){
			if(buffer[i][j]>='0'&&buffer[i][j]<='9'){
				result1++;
				break;
			}
			else{
				j++;
			}
		}
		if(buffer[i][j]==0){
			m = 0;
			while(m<i){
				n = 0;
				while(buffer[m][n]!=0){
					if(buffer[i][n]!=buffer[m][n]){
						break;
					}
					else{
						n++;
					}
				}
				if(buffer[m][n]==0&&buffer[i][n]==0){
					result2++;
					break;
				}
				else{
					m++;
				}
			}
		}
		i++;
	}

	result1 = num - result1;
	result2 = result1 - result2;
	cout<<"一共有"<<result1<<"个单词"<<endl;
	cout<<"一共有"<<result2<<"个非重复单词"<<endl;
    return 0;
}
#include <stdio.h>

int[][] sparse(int arr[][3], int row, int column) {
	int res[row*column][3];
	for(int i; i<row;i++){
		for(int j; j<column;j++){
			if(arr[i][j]) {
				printf("Non Zero!");		
			}
		}	
	}
}

int main() {
	int sprs[][3] = {2,4,5
			3,0,0
			2,0,4}

}

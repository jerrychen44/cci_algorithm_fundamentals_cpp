/**
 * Cracking the coding interview 1.8
 * Write a space efficient algorithm, such that if an element in MxN is 0, the entire row and column containing it are 0.
 *
 * Approach:
 * We can use a boolean matrix of MxN or a bit vector to mark row and columns to be nullified in first iteration, but it wont be space efficient.
 * More space efficient would be to first check first row and column and if any of them contains zero, mark them to be nullified using two boolearn vars
 * let's say firstRow and firstCol, and then iterate through rest of the matrix and store information in first row column elements, only when that row
 * and column is to be marked for nullified, this way we will only change values in first row and column which are already going to be 0 in final solution.
 */

#include <iostream>

void nullifyRow( int ** matrix, int N, int row ) {
	for ( int j = 0; j < N; ++j ) {
		matrix[row][j] = 0;
	}
}

void nullifyCol( int ** matrix, int M, int col ) {
	for ( int i = 0; i < M; ++i ) {
		matrix[i][col] = 0;
	}
}


void nullifyMatrix( int ** matrix, int M, int N ) {

	bool firstRow = false;

	//check first row
	for( int i = 0; i < N; ++i ) {
		if ( matrix[0][i] == 0 ) {
			firstRow = true;
			break;
		}
	}

	//rest of the matrix
	for( int i = 1; i < M; ++i ) {
		bool nullifyThisRow = false;
		for ( int j = 0; j < N; ++j ) {
			if ( matrix[i][j] == 0 ) {
				matrix[0][j] = 0;//add 0 to first row, use first row as map
				nullifyThisRow = true;
			}
		}
		if (nullifyThisRow)
			nullifyRow(matrix, N, i);
	}

	//now we know which column to be nullify using information stored in previous step.
	//cols first
	// the first row is the map we just save
	for ( int j = 0; j < N; ++j ) {
		if ( matrix[0][j] == 0 ) {
			nullifyCol(matrix, M,  j);
		}
	}
	//finially, handle the first row.
	//now first row
	if ( firstRow ) {
		nullifyRow(matrix, N, 0);
	}

}

void printMatrix( int ** matrix, int M, int N ) {
	for ( int i = 0; i < M; ++i ) {
		for ( int j = 0; j < N; ++j ) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//although we can use first row, col as the null map
//but we only use row here, we set the col to 0 directly
//during the checking iteration.
int main()
{
	int M=4, N=5;
	//std::cout << "Enter number of rows:";
	//std::cin >> M;
	//std::cout << "Enter number of cols:";
	//std::cin >> N;

	std::cout << "dim :" << M << " x " << N << std::endl;
	//init matrix
	int ** matrix = new int*[M];
	for ( int i =0; i < M; ++i ) {
		matrix[i] = new int[N];
	}
	/*
	std::cout << "Provide M x N matrix \n";
	for ( int i = 0; i < M; ++i ) {
		for ( int j = 0; j < N; ++j ) {
			std::cin >> matrix[i][j];
		}
	}*/

	matrix[0][0] = 0;
	matrix[0][1] = 1;
	matrix[0][2] = 2;
	matrix[0][3] = 3;
	matrix[0][4] = 2;

	matrix[1][0] = 4;
	matrix[1][1] = 5;
	matrix[1][2] = 6;
	matrix[1][3] = 7;
	matrix[1][4] = 7;

	matrix[2][0] = 8;
	matrix[2][1] = 9;
	matrix[2][2] = 0;
	matrix[2][3] = 11;
	matrix[2][4] = 11;

	matrix[3][0] = 12;
	matrix[3][1] = 13;
	matrix[3][2] = 2;
	matrix[3][3] = 15;
	matrix[3][4] = 15;


	std::cout << "Matrix Before:\n";
	printMatrix(matrix, M, N);
	nullifyMatrix(matrix, M, N);
	std::cout << "Matrix After:\n";
	printMatrix(matrix, M, N);
	return 0;
}

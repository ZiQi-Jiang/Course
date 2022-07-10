#include<cmath>
#include<iostream>
using namespace std;

class Matrix{
	int matrix[3][3];
	public:
		Matrix();
		void input();
		void output();
		void transform();
		void show();
};

Matrix::Matrix(){
	for(int i=0;i<3;i++)
	  for(int j=0;j<3;j++)
	    matrix[i][j] = 0;
	
}

void Matrix::input()
{
	for(int i=0;i<3;i++)
	  for(int j=0;j<3;j++)
	    cin >> matrix[i][j];
	
}
void Matrix::show()
{
	cout<<"datas:"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		  cout<<" "<<matrix[i][j];
		cout<<endl;
	}
}

void Matrix::transform()
{
	for(int i=0;i<3;i++)
	   for(int j=0;j<i;j++)
	{
		swap(matrix[i][j],matrix[j][i]);
	}
}
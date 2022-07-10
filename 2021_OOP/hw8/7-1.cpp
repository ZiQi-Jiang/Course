#include<iostream>
#include <iomanip>
using namespace std;
class Matrix
{
	public:
		Matrix(int, int);
		~Matrix();
		friend istream& operator>>(istream&is, Matrix&a);
		int getRow(){return row;}
		int getColum(){return column;}
		friend Matrix operator*(Matrix&, Matrix&);
		Matrix(const Matrix&);
		void display();
	private:
		int row;
		int column;
		int** mat;
};
Matrix::Matrix(int r, int c)
{
	row = r;
	column = c;
	mat = new int*[r+2];
	for(int i = 0; i < row+2; i++)
	{
		mat[i] = new int[c+2];
	}
}
Matrix::~Matrix()
{
    for(int i = 0; i <row+2; i++)
        delete []mat[i];
    delete []mat;
}
istream& operator>>(istream & is, Matrix & a){
    for(int i=0; i<a.row; i++)
    {
        for(int j=0; j<a.column; j++)
        {
            is>>a.mat[i][j];
        }

    }
}
Matrix operator*(Matrix&a, Matrix&b){
    int i,j,k,x;
    if(a.row==1&&a.column==1)
    {
        Matrix p (b.row,b.column);
        for(i=0;i<b.row;i++){
            for(j=0;j<b.column;j++){
                p.mat[i][j]=a.mat[0][0]*b.mat[i][j];
            }
        }
        return p;
    }
    else
    {
        Matrix p (a.row,b.column);
        for(i=0; i<a.row; i++)
        {
            for(j=0; j<b.column; j++)
            {
                x=0;
                for(k=0; k<a.column; k++)
                {
                     x+=a.mat[i][k]*b.mat[k][j];
                }
                p.mat[i][j]=x;
            }
        }
        return p;
    }
}
Matrix::Matrix(const Matrix&p){
        this->row=p.row;
        this->column=p.column;
        this->mat=new int* [p.row+2];
        int i,j;
        for(i=0; i<p.row+2; i++)
        {
            this->mat[i]=new int [p.column+2];
            for(j=0; j<p.column; j++)
            {
                this->mat[i][j]=p.mat[i][j];
            }
        }
}
void Matrix::display(){
        for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            cout<<setw(10)<<mat[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    int a,b,i,j;
    cin>>a>>b;
    Matrix x(a,b);
    cin>>x;
    cin>>a>>b;
    Matrix y(a,b);
    cin>>y;
   if(x.getColum()==y.getRow()||x.getColum()==1&&x.getRow()==1||y.getRow()==1&&y.getRow()==1) {

       Matrix z=x*y;
       z.display();
   }
   else{
       cout<<"Invalid Matrix multiplication!";
   }
    return 0;
}
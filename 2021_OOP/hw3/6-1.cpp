/* 体育俱乐部I */

Club::Club(string n1, int y, string n2, int wr):c(n2, wr), name( n1 ), year( y ){}

void Coach::show()
{
    cout<<name<<" "<<winRate<<"%"<<endl;
    return  ;
} 

void Club::show()
{
    cout<<name<<" "<<year<<endl;
    c.show();
}
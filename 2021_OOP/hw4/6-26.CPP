    static float totalMoney ;
    static void printTotal(){ cout<<"total:"<<totalMoney<<endl;}

};
void Donator::setName(string _name){ name = _name;}
void Donator::setMoney(float _money){ money = _money; totalMoney+=money;}
float Donator::totalMoney = 0;
string getMaxName(Donator dt[], int n)
{
    string name = dt[0].getName();
    for(int i=1;i<n;i++)  if(dt[i].getMoney() > dt[i-1].getMoney())
        name = dt[i].getName();
    return name;
}
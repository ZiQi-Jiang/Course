/* 工资与提成 */
class Salesman{
    public:
    string name;
    int num;
    float amount;
    float propotion;
    static int total;
    static float total_sum ; 

    Salesman(string _name, int _num, float _amount, float _propotion): name(_name), amount(_amount), propotion(_propotion){ total++; total_sum += _num*_propotion*_amount;}

    static void show()
    {
        cout<<"There are "<<total<<" salesmen,sales amount is:"<<total_sum<<endl;
    }

    static float getAver()
    {
        return total_sum / total;
    }

};
/* They can't be initialised inside the class, but they can be initialised outside the class, in a source file: */
int  Salesman::total = 0;
float Salesman::total_sum = 0;
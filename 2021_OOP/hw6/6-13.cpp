/* 6-13 汽车类的继承 (10 分) */
int Vehicle::get_wheels(){ return wheels;}
float Vehicle::get_weight(){ return weight;}
float Vehicle::wheel_load (){return 0;}
Vehicle::Vehicle(int wheels, float weight):wheels(wheels), weight(weight)
{
    
}
void Vehicle::show()
{
    cout<<"Type:Vehicle"<<endl;
    cout<<"Wheel:"<<wheels<<endl;
    cout<<"Weight:"<<weight<<"kg"<<endl;
}
class Car: public Vehicle
{
    float load;
    public:
    Car(int wheels_, float weight_, float load_):Vehicle(wheels_, weight_),load(load_)
    {}
    void show()
    {
     cout<<"Type:Car"<<endl;
     Vehicle::show();
     cout<<"Load:"<<load<<" persons"<<endl;
    }
};
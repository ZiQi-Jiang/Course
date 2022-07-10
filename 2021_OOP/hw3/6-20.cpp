class RESISTOR{
    private:
    double R;
    public:
    RESISTOR(double a):R(a){
        cout<<"创建电阻"<<R<<"欧"<<endl;
    }
    ~RESISTOR(){
        cout<<"销毁电阻"<<R<<"欧"<<endl;
    }
    void Show() const {
        cout<<"电阻: "<<R<<"欧"<<endl;
    }
};
class INDUCTOR{
    private:
    double DG;
    public:
    INDUCTOR(double a):DG(a){
        cout<<"创建电感"<<DG<<"亨"<<endl;
    }
    ~INDUCTOR(){
        cout<<"销毁电感"<<DG<<"亨"<<endl;
    }
    void Show() const {
        cout<<"电感: "<<DG<<"亨"<<endl;
    }
};
class CAPACITOR{
    private:
    double DR;
    public:
    CAPACITOR(double a):DR(a){
        cout<<"创建电容"<<DR<<"法"<<endl;
    }
    ~CAPACITOR(){
        cout<<"销毁电容"<<DR<<"法"<<endl;
    }
    void Show() const {
        cout<<"电容: "<<DR<<"法"<<endl;
    }
};
class CIRCUIT:public RESISTOR,public INDUCTOR,public CAPACITOR{
    public:
    CIRCUIT(double a,double b,double c):RESISTOR(a),INDUCTOR(b),CAPACITOR(c){
        cout<<"创建电路"<<endl;
    }
    ~CIRCUIT(){
        cout<<"销毁电路"<<endl;
    }
    void Show() const {
        RESISTOR::Show();
        INDUCTOR::Show();
        CAPACITOR::Show();
    }
};

void Car::disp_welcomemsg(){
	cout<<"Welcome to the car world!"<<endl;
	
}
int Car::get_wheels()
{
	return m_nWheels;
}

void Car::set_wheels(int a)
{
	m_nWheels = a;
}
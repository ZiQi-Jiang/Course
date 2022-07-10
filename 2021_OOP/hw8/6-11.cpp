Time::Time(int h,int m,int s)
{
	hours=h;
	minutes=m;
	seconds=s;
}
void Time::DispTime()
{
	cout<<hours<<"h:"<<minutes<<"m:"<<seconds<<"s"<<endl;
}
Time Time::operator +(Time & k)
{
	Time temp;
	temp.minutes=this->minutes+k.minutes;
	temp.seconds=this->seconds+k.seconds;
	temp.hours=this->hours+k.hours;
	if(temp.seconds>59)
	{
		temp.seconds-=60;
		temp.minutes++;
	}
	if(temp.minutes>59)
	{
		temp.minutes-=60;
		temp.hours++;
	}
	return temp;
}

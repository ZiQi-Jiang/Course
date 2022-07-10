void max(Student*p)
{
	int index = 0;
	for(int i=0;i<5;i++)
	if(p[i].score>p[index].score)  index = i;
	cout<<p[index].num<<" "<<p[index].score<<endl;
	
}
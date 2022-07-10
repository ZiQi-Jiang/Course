/* 6-22 各省总销量及最高销量（对象数组） (10 分) */

		s[i].setVolume(volume);
		s[i].setCity(city);
	}
double sum=s[0].getVolume() ;
int max=0;
if(n==1)
cout<<s[max].getProv()<<" "<<"sum="<<sum<<" "<<"max="<<s[max].getCity() <<","<<s[max].getVolume()<<endl;
if(n>1)
{
	for(int i=1;i<n;i++)
	{
		if(s[i].getProv() ==s[max].getProv())
		{
			sum+=s[i].getVolume() ;
			if(s[i].getVolume()>s[max].getVolume())
			{
				max=i;
			}
		}
		if(s[i].getProv() !=s[max].getProv()) 
		{
		cout<<s[max].getProv()<<" "<<"sum="<<sum<<" "<<"max="<<s[max].getCity() <<","<<s[max].getVolume()<<'\n';
			max=i;
			sum=0;
			sum=s[max].getVolume();
			for(int i=max+1;i<=n;i++)
			{
				if(s[i].getProv() ==s[max].getProv()&&i!=n)
				{
					sum+=s[i].getVolume() ;
					if(s[i].getVolume()>s[max].getVolume())
					{
						max=i;
					 }
				
			}
			if(i==n)
					cout<<s[max].getProv()<<" "<<"sum="<<sum<<" "<<"max="<<s[max].getCity() <<","<<s[max].getVolume()<<'\n';}
		}

	}
}
}

void Sale::setProv(string p)
   {
   	prov=p;
   }
   void Sale::setCity(string c)
   {
   	city=c;
   }
   void Sale::setVolume(double v)
   {
   	volume=v;
   }
   string Sale::getProv()
   {
   	return prov;
   }
   string Sale::getCity()
   {
   	return city;
   }
   double Sale::getVolume()
   {
   	return volume;
   }


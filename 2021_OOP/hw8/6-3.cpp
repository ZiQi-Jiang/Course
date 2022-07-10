template<class T>
class Table{
	int size;
	int *key;
	T *val;
	T t;
	static int cnt;
	public:
		Table(int s){
			size=s;
			key=new int[s];
			val=new T[s];
		}
		T& operator[](int k){
			for(int i=0;i<cnt;i++){
				if(key[i]==k){
					return val[i];//存过 
				}
			}
			if(cnt==size)	return t;//存满 
			//没存过
			key[cnt]=k;
			return val[cnt++];
		}
		void min(){
			T m=val[0];
			int n=key[0];
			for(int i=1;i<cnt;i++){
				if(val[i]<m||(val[i]==m&&key[i]<n)){
					m=val[i];
					n=key[i];
				}
			}
			cout<<n<<" "<<m<<endl;
		}
};
template<class T>
int Table<T>::cnt=0;

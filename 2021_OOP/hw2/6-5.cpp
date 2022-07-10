bool Solution:: isPalindrome(char*s)
{
	char* inv_s;
	int len = 0;
	while(s[len]!='@') len++;
	for(int i=0;i<len;i++)
		if(s[i] != s[len-i-1]) return false;
	return true;
}
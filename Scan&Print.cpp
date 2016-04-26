int Scan()
{
	int res, ch=0;
	while(!(ch>='0'&&ch<='9')) ch=getchar();
	res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return res;
}
void Out(int a)
{
    if(a>9)
        Out(a/10);
    putchar(a%10+'0');
}

int Scan2()
{
	int res=0,ch,flag=0;
	if((ch=getchar())=='-')
	    flag=1;
	else if(ch>='0'&&ch<='9')
	    res=ch-'0';
	while((ch=getchar())>='0'&&ch<='9')
		res=res*10+ch-'0';
	return flag?-res:res;
}

void Out2(int a)
{
	if(a<0)
	{
		putchar('-');
		Out(-a);
	}else{
		Out(a);
	}
}

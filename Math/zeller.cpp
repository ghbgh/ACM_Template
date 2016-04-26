
int z(int y, int m, int d) //zeller formular
{
	if(m<3){m+=12;y--;}
	return 365*y+y/4-y/100+y/400+(153*m+2)/5+d;
}


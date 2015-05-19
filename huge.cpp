#include<iostream>
#include <string.h>
#include "huge.h"
using namespace std;

HugeInt::HugeInt( long a)
{
    for ( int i=0;i<30;++i)
        number[i]=0;
    for ( int j=29; a!=0 && j>=0; --j )
    {
        number[j]=a%10;
        a/=10;
	}
}
HugeInt::HugeInt( const char *str )
{
    for ( int i=0;i<30;++i)
        number[i]=0;
    int len = strlen(str);
    for ( int j=30-len,k=0;j<30;j++,k++ )
    {
        if ( isdigit(str[k]) )
            number[j]=str[k]-'0';
    }
}
HugeInt HugeInt::operator+( const HugeInt &obj ) const
{
    HugeInt tmp;
    int stat=0;
	for( int i=29;i>=0;--i)
    {
        tmp.number[i]= number[i] + obj.number[i] + stat;
        if( tmp.number[i]>9 )
        {
            tmp.number[i]%=10;
            stat=1;
        }
        else
            stat=0;
    }
    return tmp;
}
HugeInt HugeInt::operator+( int obj ) const
{
    return *this + HugeInt( obj );
}
HugeInt HugeInt::operator+( const char *obj ) const
{
    return *this + HugeInt( obj );
}
HugeInt HugeInt::operator-( const HugeInt &obj ) const
{
    HugeInt tmp,retmp;
    int stat=0;
    for( int i=29;i>=0;--i)
    {
        retmp.number[i]= number[i] - obj.number[i] + stat;
        if( retmp.number[i]<0 )
        {
          retmp.number[i]%=10;
          tmp.number[i]=-1*retmp.number[i];
    	  stat=-1;
        }
        else
        {
            tmp.number[i]=retmp.number[i];
            stat=0;
        }
    }
    return tmp;
}
HugeInt HugeInt::operator-( int obj ) const
{
    return *this - HugeInt( obj );
}
HugeInt HugeInt::operator-( const char *obj ) const
{
    return *this - HugeInt( obj );
}

ostream &operator<<( ostream &out, const HugeInt &obj )
{  
    for ( int i=0;(obj.number[i]==0)&&(i<30);i++)
    if ( i==30 )
        out<<0;
    else
    {
        for (;i<30;i++)
            out<<obj.number[i];
    }
    return out;
}
istream &operator>> ( istream & in, HugeInt & obj )
{
    char tmp[30];
    in>>tmp;
    obj=tmp;
    return in;
}

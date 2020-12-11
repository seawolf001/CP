#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <climits>
#include <map>

#define FIB_INT long int

using namespace std;


FIB_INT divisor(const FIB_INT& n, const FIB_INT& m)
{
    FIB_INT divisor = -1;
    FIB_INT ii=2;
    while(ii<= n && ii<=m)
    {
        if((n%ii==0)&&(m%ii==0))
        {
            divisor = ii;
            break;
        }
        ii++;
    }
    return divisor;
}


void solution(const FIB_INT& num)
{
    if(num == 2 || num == 3)
    {
        cout<<num<<" "<<num<<"\n";
        return;    
    }
    
    map<FIB_INT,FIB_INT> fiboVec;
    fiboVec[0]=1;
        fiboVec[1]=1;

    FIB_INT ii=1;
    FIB_INT div;
    while(fiboVec[ii] <= LONG_MAX)
    {
        if(fiboVec[ii] >= 2)
        {
            div = divisor( num, fiboVec[ii] );
            if( div > 1 )
            {
                cout<< fiboVec[ii] <<" "<<div<<"\n";
                break;
            }
        }
        ii++;
        fiboVec[ii] = fiboVec[ii-1] + fiboVec[ii-2];
    }
}


int main() 
{
    int testCases;
    vector<FIB_INT> cases;
    FIB_INT ii,aux;
    
    //read data
    cin>>testCases;

    ii = 0;
    while(ii++<testCases)
    {
         cin>>aux;
     cases.push_back(aux);
    }   

    for( ii=0; ii< testCases; ii++ )
    {
    solution(cases[ii]);    
    }
    
    return 0;
}

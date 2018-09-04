#include<iostream>  
#include<cmath>  
using namespace std;  
   
#define max 1000  
int prime[max];  
int i;  
int j;  
   
bool isPrime(int temp)  
{  
    int t;  
    bool flag = true;  
    for(t = 2; t <= sqrt(temp); t++)  
        if( temp%t == 0) {flag = false; break;}  
    return flag;  
}  
   
int main()  
{  
    prime[0] = 2;  
    j = 3;  
    for(i=1; i<max; i++)  
    {  
        for(; j<100000; j++ )  
        {  
            if( isPrime(j) )  
            {  
                prime[i] = j++;  
                break;  
            }  
        }  
    }  
   
    long input;  
    int temp;  
    int num;  
    cin>>input;  
    cout<<input<<"=";  
    if(input == 1) //ÌØÀý  
        cout<<input;  
    else 
    {  
        for(i=0; input != 1; i++)  
        {  
            num = 0;  
            while( (input%prime[i]) == 0)  
            {  
                num++;  
                input = input/prime[i];  
            }  
            if(num >= 1)  
            {  
                cout<<prime[i];  
                if(num > 1)  
                    cout<<"^"<<num;  
                if(input != 1)  
                    cout<<"*";  
            }  
        }  
    }     
    cout<<endl;  
    return 0;  
}  

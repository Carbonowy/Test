#include <iostream>
using namespace std;

void kopiec(int n, int* tab, int szczyt)
{
    while(true)
    {
        for(int i=0; i<n; i++)
        {
            if((2*i)+1 < n && tab[i] < tab[(2*i)+1]) swap(tab[i], tab[(2*i)+1] );
            if((2*i)+2 < n && tab[i] < tab[(2*i)+2]) swap(tab[i], tab[(2*i)+2] );
            if((2*i)+1 > n) break;    
        }
        if(tab[0] == szczyt) break;
    }
}

int max(int n, int* tab)
{
    int max = tab[0];
    
    for(int i=0; i<n; i++)
    {
        if(tab[i] > max) max = tab[i];
    }
    return max;
}

int spacja1(int n)
{
    int a = 0, l = 0;
    for(a=0; a<n; a = (2*a)+1){l++; }
    
    return l;
}

bool szukaj(int i, int* tab, int pocz, int kon)
{
    int center = (pocz+kon)/2;
    
    if(pocz>=kon) return false;

    if(tab[center] == i)

    if(i > tab[center]) szukaj(i,tab,center+1, kon);
        else szukaj(i,tab,pocz,center);

    return true;
}
void wypelnij1(int* tab, int spacja)
{
    tab[0]= 0;
    for(int i=1; i<spacja; i++)
    {
        tab[i] = (tab[i-1]*2)+1;
    }
}

int main()
{
    int n = 10, a, spacja; 
    int tab[n] = {0,3,1,8,7,6,0,10,19,3};
    
    
    a = max(n, tab); 
    kopiec(n, tab, a);
    spacja = spacja1(n); 
    int tablica_spacji[spacja]; 
    int pocz = 0, kon = spacja; 
    int center = (pocz+kon)/2;
    wypelnij1(tablica_spacji, spacja);
   
    for(int i=0; i<n; i++)
    {
        if( szukaj(i, tablica_spacji, pocz,kon) == true)
        {
            for(int j=0; j<spacja; j++){ cout<<" "; spacja--;}
            cout<<tab[i]<<" ";
        }
        else cout<<tab[i]<<" ";      
    }


    return 0;
}
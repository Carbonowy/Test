#include <iostream>
using namespace std;

struct vertex
{
    vertex* edge1;
    vertex* edge2;
    vertex* next;
    int Vertexcounter = 0;
    int nr;
};

vertex* lista(int n)
{
    vertex* head;
    vertex* tmp;
    vertex* a;

    for(int i=0; i<n; i++)
    {
        a = new vertex;
        a -> nr = i;

        if(i == 0) head = a;
        else tmp -> next = a;

        tmp = a;
    }

    a -> next = NULL;

    return head;
}

void fill_up_with_Es_coordinates(int tab[][2], int m)
{
    for(int i=0; i<m; i++)
    {
        cin>>tab[i][0]>>tab[i][1];
    }

}

void sort_tab(int tab[][2], int n)
{
   
   
    int k = 1, schowek; 
    
    for( int i=k; i<n ; i++ )
    {
        if(tab[k][0]<tab[k-1][0])
        {
            schowek = tab[k][0];
            for( int j = k-1; j >= 0; j-- )
            {
                if( schowek < tab[j][0] )
                {
                    swap(tab[j+1][0], tab[j][0]);
                    swap(tab[j+1][1], tab[j][1]);
                }
            }
        }
        k++;
    }

    k = 1;

    for( int i=k; i<n ; i++ )
    {
        if(tab[k][1]<tab[k-1][1] && tab[k][0] == tab[k-1][0])
        {
            schowek = tab[k][1];
            for( int j = k-1; j >= 0; j-- )
            {
                if( schowek < tab[j][1] && tab[j][0] == tab[j+1][0])
                {
                    swap(tab[j+1][1], tab[j][1]);
                }
            }
        }
        k++;
    }
    
}


vertex* znajdz(int n, vertex* head)
{
    vertex* tmp; 
    tmp = head;

    while( tmp -> next != NULL && tmp -> nr != n )
    {
        tmp = tmp -> next;
    }

    return tmp;
}

void graff(vertex* head, int tab[][2])
{
    vertex* a;
    vertex* tmp;
    a = head; 
    tmp = head;
    int cubby;
    

    int i = 0;
    
    while( a -> next != NULL)
    {
        
        while(tab[i][0] == a -> nr)
        {
            cubby = tab[i][1];
            
            tmp = znajdz(cubby, tmp);

            switch(a -> Vertexcounter)
            {
                case 0: a -> edge1 = tmp; break;
                case 1: a -> edge2 = tmp; break;            
            }
            
            a -> Vertexcounter++;
            i++;
        }
        a = a -> next;
        tmp = head;
    }
}


int main()
{
    int amount_of_V, amount_of_E;
    cin>>amount_of_V>>amount_of_E;
    int tab[amount_of_E][2];

    fill_up_with_Es_coordinates(tab, amount_of_E);
    sort_tab(tab, amount_of_E);
    
    vertex* head;
    head = lista(amount_of_V);

    graff(head, tab);

 
    cout<<head->edge1->edge2->nr;
    

    return 0;
}
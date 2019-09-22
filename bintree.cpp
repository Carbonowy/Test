#include <iostream>
using namespace std; 

struct tree
{
    int nr;
    int zmienna;
    tree* next;
    tree* childleft;
    tree* childright;
    tree* parent;
};

tree* lista(int n)
{
    tree* a;
    tree* tmp;
    tree* cone;

    for(int i=0; i<n; i++)
    {
        a = new tree;
        a -> nr = i;
        
        if(i == 0) cone = a;
        else
        {
            tmp -> next = a;
        }
        tmp = a;
    }
    a -> next = NULL;

    return cone;
}

int spacja1(int n)
{
    int a = 0, l = 0;
    for(a=0; a<n; a = (2*a)+1){l++; }
    
    return l;
}

void drzewo(int n, tree* cone)
{
    tree* a;
    tree* tmp;
    a = cone;
    tmp = cone;
    tree* x;
    int wiersz = spacja1(n), licznik = 2;
    
    for(int i=0; i<wiersz; i++)
    {
        if(i == 0)
        {
            cin>>a -> zmienna; // a->zmienna = i;
            a -> parent = NULL;
            a -> childleft = a -> next;
            a -> childright = a -> next -> next;
            a -> next -> parent = a;
            a -> next -> next -> parent = a;
            a = a -> next;
            tmp = tmp -> next -> next -> next;
        }
        else
        {
            for(int k=0; k<licznik; k++)
            {
                cin>>a->zmienna; // a->zmienna = i+k;
                x = a;
                
                
                while(x -> parent != NULL && x->zmienna > x->parent->zmienna )
                {
                    swap( x-> zmienna, x->parent->zmienna);
                    x = x -> parent;
                }
                
                if( (2*a->nr) + 1 < n)
                {
                    cout<<"1"<<endl;
                    a -> childleft = tmp;
                    tmp -> parent = a;
                    tmp = tmp -> next;
                }
                else a->childleft =NULL;

                if( (2*a->nr) + 2 < n)
                {
                    cout<<"2";
                    a -> childright = tmp;
                    tmp -> parent = a;
                    tmp = tmp -> next;    
                }
                else a->childright = NULL;

                if(a->next != NULL)
                a = a->next;
            }
            licznik*=2;
        }
        
    }
    
}

void wypisz(int n, tree* cone)
{
    cout<<endl;
    tree* a = cone;
    for( int i=0; i<n; i++ )
    {
        cout<<a -> zmienna<<" ";
        a = a -> next;
    }
}

int main()
{
  int n;  cin>>n; 

    tree* cone;

    cone = lista(n);

    drzewo(n, cone);
    
    wypisz(n,cone);

	cout<<endl;
   
    return 0;
}

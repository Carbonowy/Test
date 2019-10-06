#include <iostream>
using namespace std; 


struct vertex
{
    int nr;
    int edgecounter = 0;
};


struct edge
{
    vertex* Vertex0;
    vertex* Vertex1;
    edge* next;
    int wage;
};


edge* LinkedVertexCreator(int nr, int vertexamount, int edgeamount,edge* tmpe, vertex* a,vertex* t1, vertex* t2, vertex* t3)
{
    edge* e;
    
    e = new edge;

    if(t1 != NULL && nr - t1->nr == 1) 
    {
        e -> Vertex0 = t1;
        t1 -> edgecounter++;
    }
    else if(t2 != NULL && nr - t2->nr == 1) 
    {
        e -> Vertex0 = t2;
        t2 ->edgecounter++;
    }
    else if(t3 != NULL && nr - t3->nr == 1) 
    {
        e -> Vertex0 = t3;
        t3 ->edgecounter++;
    }
    else if(edgeamount == 0)
    {
        e -> Vertex0 = a;
    }  
    else
    {
        tmpe -> next = e;
        e -> Vertex0 = tmpe -> Vertex1;
    }

    tmpe = e;

    a = new vertex;
    e -> Vertex1 = a;
    
    cout<<"add wage "; 
    cin>>e->wage;
    cout<<endl;
                
    a -> edgecounter++;
    a -> nr = nr;
    
    
    return tmpe;
}

edge* edgeCreator(edge* tmpe, int edgeamount, vertex* V_S, vertex* V_E)
{
    edge* e;
    e = new edge;
    
    if(edgeamount == 0)
    {
        tmpe = e;
    }
    else 
    {
        tmpe->next = e;
        tmpe = e;
    }
    
    e -> Vertex0 = V_S;
    e -> Vertex1 = V_E;
    
    cout<<"add wage "; 
    cin>>e->wage;
    cout<<endl;

    return tmpe;
}

vertex* find_Vertex(int Smthg, edge* head, int edgeamount,vertex* t1, vertex* t2, vertex* t3, vertex* k)
{
    vertex* a;
    edge* h; 
    h = head;

    if(k != NULL && Smthg == k->nr)
    {
        k->edgecounter++;
        a = k;
    }
    if(t1 != NULL && Smthg == t1->nr)
    {
        t1->edgecounter++;
        a = t1;
    }
    else if(t2 != NULL && Smthg == t2->nr)
    {
        t2->edgecounter++;
        a = t2;
    }
    else if(t3 != NULL && Smthg == t3->nr)
    {
        t3->edgecounter++;
        a = t3;
    }
    else
    {
        for(int i=0; i<edgeamount; i++)
        {
            if(h->Vertex0->nr == Smthg)
            {
                a = h -> Vertex0;
                break;
            }        
            else if(h->Vertex1->nr == Smthg)
            {
                a = h -> Vertex1;
                break;
            }
            h = h -> next;
        }
    }
    return a;
}

edge* findedge(int S_V, int E_V, int edgeamount, edge* head_E)
{
    edge* e = head_E;
    edge* pom;
    edge* tmp;

    for(int i=0; i<edgeamount; i++)
    {
        if( e->next -> Vertex0 -> nr == S_V && e-> next ->Vertex1-> nr == E_V ) break; 
        else if(e->next -> Vertex0 -> nr == E_V && e->next ->Vertex1-> nr == S_V)   break; 

        e = e->next;
    }

    if( e == head_E ) 
    {
        pom = e->next;
        delete e;
    }
    else 
    {   
        tmp = e -> next;
        e -> next = e -> next -> next;
        delete tmp;
    }    
    return pom;
}
edge* graf()
{
    vertex* k;
    vertex* V_S;
    vertex* V_E;
    edge* head_E;
    edge* e;
    edge* tmpe;
    int x;
    int nr;
    int vertexamount = 0;
    int edgeamount = 0;
    int V_start;
    int V_end;
    
    vertex* tmp1; bool t1 = false;
    vertex* tmp2; bool t2 = false;
    vertex* tmp3; bool t3 = false;

    tmp1 = NULL; tmp2 = NULL; tmp3 = NULL;
    k = NULL;

    while(true)
    {
        cout<<"What do you want to do?"<<"\n\n"
        <<"1.add new vertex (autoedge with previous vertex [first one will be unlinked])"
        <<endl<<"2.add new unlinked vertex(WARNING:::You re able to have only 3 unlinked Vertex in the same time)"
        <<endl<<"3.add new edge (to already existing vertices)"
        <<endl<<"4.delete edge"
        <<endl<<"(type 0 to end inputting)"<<"\n\n";
        
        cin>>x;
        cout<<endl;

        if( x == 1 )
        {    
            cout<<"input Vertex number  ";
            cin>>nr;
            cout<<endl;

            if(nr >= 2 && nr-vertexamount == 1)
            { 
                
                
                tmpe = LinkedVertexCreator(nr,vertexamount,edgeamount, tmpe,k, tmp1, tmp2, tmp3);
                if(tmp1 != NULL && tmp1->edgecounter == 1){ t1 = false; tmp1 = NULL; }
                if(tmp2 != NULL && tmp2->edgecounter == 1) {t2 = false; tmp2 = NULL;}
                if(tmp3 != NULL && tmp3->edgecounter == 1) {t3 = false; tmp3 = NULL;}
                
                if(edgeamount == 0) head_E = tmpe;
                if(k!=NULL && k->edgecounter == 1) k = NULL;
                vertexamount++;
                edgeamount++;
            }
            else if(nr<=vertexamount || nr - vertexamount >= 2)
            {
                cout<<"such vertex already exists or its number is too high"<<endl<<"previous vertex = "<<vertexamount<<endl<<endl;
            }
            else if( nr == 1 && vertexamount == 0)
            {
                k = new vertex;
                k -> nr = nr;
                k -> edgecounter++;
                vertexamount++;
            }
            
        }
        else if( x == 3 )
        {
            cout<<"input, which  vertices you want to link"<<"\n\n";
            cout<<"start Vertex  "; cin>>V_start;
            cout<<endl<<"end Vertex  "; cin>>V_end; cout<<endl;

            if(vertexamount<3 && edgeamount>0) 
            {
                cout<<"there re no enough vertices"<<endl<<endl;
            }      
            else if(V_start > vertexamount || V_end > vertexamount || V_start<=0 || V_end<=0)
            {
                cout<<"such start Vertex or end Vertex doesn't/can't exists"<<endl<<"previous vertex = "<<vertexamount<<endl<<endl;
            }
            else
            {
                V_S = find_Vertex(V_start, head_E, edgeamount, tmp1, tmp2 , tmp3,k);
                V_E = find_Vertex(V_end, head_E, edgeamount, tmp1, tmp2, tmp3,k);    
                tmpe = edgeCreator(tmpe,edgeamount,V_S,V_E);
                if(tmp1 != NULL && tmp1->edgecounter == 1) {t1 = false; tmp1 = NULL;}
                if(tmp2 != NULL && tmp2->edgecounter == 1) {t2 = false; tmp2 = NULL;}
                if(tmp3 != NULL && tmp3->edgecounter == 1) {t3 = false; tmp3 = NULL;}
                if(edgeamount == 0) 
                {
                    head_E = tmpe;
                    k = NULL;
                }
                edgeamount++;
            }

               
        }
        else if( x == 2 )
        {
            cout<<"input Vertex number  ";
            cin>>nr;
            cout<<endl;
            
            if(nr<=vertexamount || nr - vertexamount >= 2)
            {
                cout<<"such vertex already exists or its number is too high"<<endl<<"previous vertex = "<<vertexamount<<endl<<endl;
            }
            else
            {
                if(t1 == false)
                {
                    tmp1 = new vertex;
                    
                    tmp1 -> nr = nr;
                    t1 = true;
                    vertexamount++;
                }
                else if(t2 == false)
                {
                    tmp2= new vertex;
                    
                    tmp2 -> nr = nr;
                    t2 = true;
                    vertexamount++;
                }
                else if(t3 == false)
                {
                    tmp3 = new vertex;
                    
                    tmp3 -> nr = nr;
                    t3 = true;
                    vertexamount++;
                }
            }

        } 
        else if(x == 4)
        {
            cout<<"input, which which vertices you want to unlink"<<"\n\n";
            cout<<"start Vertex  "; cin>>V_start;
            cout<<endl<<"end Vertex  "; cin>>V_end; cout<<endl;
        
            if(vertexamount<3 && edgeamount>0) 
            {
                cout<<"there re no edges at all"<<endl<<endl;
            }      
            else if(V_start > vertexamount || V_end > vertexamount || V_start<=0 || V_end<=0)
            {
                cout<<"such start Vertex or end Vertex doesn't/can't exists"<<endl<<"previous vertex = "<<vertexamount<<endl<<endl;
            }
            else 
            {
                head_E = findedge(V_start,V_end,edgeamount,head_E);
            }
        }
        else if( x == 0 )   break;
        else if( x > 4 && x < 0) cout<<"there is no such option"<<endl;
    }
    return head_E;
    
}


int main()
{
    edge* h;
    
    h = graf();
        
    cout<<h->Vertex1->nr;

    return 0;
}
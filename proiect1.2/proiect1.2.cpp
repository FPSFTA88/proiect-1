#include <iostream>
#include <algorithm>
using namespace std;

class Vector
{
    int v[101];
    int n;
public:
    //constructori
    Vector (int valuare, int nr)
    {
        int i;
        n = nr;
        for(i=0;i<n;++i)
            v[i] = valuare;
    }
    Vector (): n(0){}
    Vector (int numar)
    {
        int i;
        n = numar;
        for(i=0;i<n;++i)
            v[i] = 0;
    }
    Vector (int tablou[101], int numar)
    {
        int i;
        n = numar;
        for(i=0;i<n;++i)
            v[i] = tablou[i];
    }
    //destructor
    ~Vector () {n = 0;}
    //geteri, seteri
    int Getn(){return n;}
    int Getvi(int i){return v[i];}
    void Setn(int numar){n = numar;}
    void Setvi(int i, int numar){v[i] = numar;}
    //operatori
    friend istream& operator>>(istream& in, Vector& ve)
    {
        in>>ve.n;
        int i;
        for(i=0;i<ve.n;++i)
        {
            in>>ve.v[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Vector& ve)
    {
        int i;
        for(i=0;i<ve.n;++i)
            out<<ve.v[i]<<" ";
        return out;
    }
Vector operator= (Vector ve);
    //metode
    void reactualizare(int numar, int nr);
    int suma ();
    void maxim(int &ma, int &poz);
    void sortare();
};
Vector Vector::operator= (Vector vect)
{
    int i;
    for(i=0;i<n;++i)
        v[i] = 0;
    n = vect.n;
    for(i=0;i<n;++i)
        v[i] = vect.v[i];
}
inline void Vector::reactualizare (int numar, int nr)
{
    n = nr;
    int i;
    for(i=0;i<n;++i)
        v[i] = numar;
}
inline int Vector::suma ()
{
    int i,s=0;
    for(i=0;i<n;++i)
        s += v[i];
    return s;
}
inline void Vector::maxim(int &ma, int &poz)
{
    int i;
    ma = 0;
    for(i=0;i<n;++i)
        if (v[i] > ma)
        {
            ma = v[i];
            poz = i;
        }
}
inline void Vector::sortare()
{
    sort(v,v+n);
}


struct lista{
Vector info;
lista *next;
}*p,*u,*j; //j o sa fie folosit pentru a parcurge lista
void creat(Vector value)
{
    p = new lista;
    u = p;
    p->info = value;
    p->next = NULL;
}
void add(Vector value)
{
    lista *aux;
    aux = new lista;
    aux->info = value;
    aux->next = NULL;
    u->next = aux;
    u = aux;
}


int numar,n,ma,poz,i,choice,nr,ok,index;
int main()
{
    Vector ve;
    cin>>n;
    cin>>ve;
    creat(ve);
    for(i=1;i<n;++i)
    {
        cin>>ve;
        add(ve);
    }
    j=p;
    while(j)
    {
        cout<<j->info<<'\n';
        j = j->next;
    }

    cout<<"MENU"<<'\n';
    cout<<"apasa 0: EXIT '\n' apasa 1: reactualizare '\n'apasa 2: suma '\n'apasa 3: maxim '\n' apasa 4: sortare '\n'";
    ok = 0;
    while(ok == 0){
    cout<<"Alege orice optiune: ";
    cin>>choice;
    switch(choice)
    {
    case 0:
        ok = 1;
        break;
    case 1:
        cout<<"Valuare = ";
        cin>>numar;
        cout<<"Numarul elementelor = ";
        cin>>nr;
        cout<<"index element = ";
        cin>>i;
        j = p;
        for(index=0;index<i;++index)
        {
            j = j->next;
        }
        j->info.reactualizare(numar,nr);
        cout<<"acum vectorul["<<i<<"] = "<<j->info<<'\n';
        break;
    case 2:
        cout<<"Alege indexul vectorului al carui suma o vrei:";
        cin>>i;
        j = p;
        for(index=0;index<i;++index)
        {
            j = j->next;
        }
        cout<<"suma ceruta este: "<<j->info.suma()<<'\n';
        break;
    case 3:
        cout<<"alegeti indexul vectorului: ";
        cin>>i;
        j = p;
        for(index=0;index<i;++index)
        {
            j = j->next;
        }
        j->info.maxim(ma,poz);
        cout<<"maximul este: "<<ma<<'\n'<<"acesta se afla pe pozitia:"<<poz<<'\n';
        break;
    case 4:
        cout<<"Alege indexul vectorului de sortat: ";
        cin>>i;
        j = p;
        for(index=0;index<i;++index)
        {
            j = j->next;
        }
        j->info.sortare();
        cout<<"Acum vectorul ["<<i<<"] = "<<j->info<<'\n';
        break;
    }
    }
    return 0;
}

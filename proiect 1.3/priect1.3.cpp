#include <iostream>
#include <algorithm>
using namespace std;

class Nod
{
    int info;
    Nod *next;
public:
    friend class Vector;
};


class Vector
{
    Nod *p,*u;
    int n;
public:
    //constructori
    Vector (int valuare, int nr)
    {
        p = new Nod;
        p -> info = valuare;
        u = p;
        int i;
        for(i=1;i<n;++i)
        {
            u -> next = new Nod;
            u = u -> next;
            u->info = valuare;
        }
    }
    Vector (): n(0){}
    Vector (int numar)
    {
        n = numar;
        int i;
        p = new Nod;
        p -> info = 0;
        u = p;
        for(i=1;i<n;++i)
        {
            u -> next = new Nod;
            u = u -> next;
            u->info = 0;
        }
    }
    Vector (int tablou[101], int numar)
    {
        n = numar;
        int i;
        p = new Nod;
        p -> info = tablou[0];
        u = p;
        for(i=1;i<n;++i)
        {
            u -> next = new Nod;
            u = u -> next;
            u->info = tablou[i];
        }
    }
    //constructor de copiere
    Vector (Vector &ve)
    {
        Nod *aux;
        ve.Getp(aux);
        p = aux;
        ve.Getu(aux);
        u = aux;
        n = ve.Getn();
    }
    //destructor
    ~Vector ()
    {
        n = 0;
        delete p;
        delete u;
    }
    //geteri, seteri
    int Getn(){return n;}
    void Getp(Nod *aux1){aux1 = p;}
    void Getu(Nod *aux2){aux2 = u;}
    void Setn(int numar){n = numar;}
    void Setp(Nod *aux){p = aux;}
    void Setu(Nod *aux){u = aux;}
    //operatori
    friend istream& operator>>(istream& in, Vector& ve)
    {
        in>>ve.n;
        int i,info;
        in>>info;
        p = new Nod;
        p -> info = info;
        u = p;
        for(i=1;i<ve.n;++i)
        {
            in>>info;
            u -> next = new Nod;
            u = u -> next;
            u -> info = info;
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
    ma = -999999999;
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
int numar,n,v[3]={1,4,8},ma,poz,i,choice,nr,ok;
int main()
{
    Vector ve[101];
    cin>>n;
    for(i=0;i<n;++i)
        cin>>ve[i];
    for(i=0;i<n;++i)
        cout<<ve[i]<<'\n';
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
        if(i>=0&&i<n){
            ve[i].reactualizare(numar,nr);
            cout<<"acum ve["<<i<<"] = "<<ve[i]<<'\n';
        }
        else
            cout<<"Index invalid '\n'";
        break;
    case 2:
        cout<<"Alege indexul vectorului al carui suma o vrei:";
        cin>>i;
        if(i>=0&&i<n)
            cout<<"suma ceruta este: "<<ve[i].suma()<<'\n';
        else
            cout<<"Index invalid '\n'";
        break;
    case 3:
        cout<<"alegeti indexul vectorului: ";
        cin>>i;
        if(i>=0&&i<n){
            ve[i].maxim(ma,poz);
            cout<<"maximul este: "<<ma<<'\n'<<"acesta se afla pe pozitia:"<<poz<<'\n';
        }
        else
            cout<<"Index invalid '\n'";
        break;
    case 4:
        cout<<"Alege indexul vectorului de sortat: ";
        cin>>i;
        if(i>=0&&i<n){
            ve[i].sortare();
            cout<<"Acum ve["<<i<<"] = "<<ve[i]<<'\n';
        }
        else
            cout<<"Index invalid '\n'";
        break;
    }
    }
    return 0;
}

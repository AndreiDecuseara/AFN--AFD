#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
struct mat
{
    char car[20];
}v[100][100];

struct grup
{
    char c;
    struct grup1
    {
        int v[20];
    };
};
int nr_noduri()
{

    fstream f("date.txt");

    int max=0,n,i,x,y;
    string c;
    f>>n;

    for(i=0;i<n;i++)
    {

        f>>x;f>>y;
        if(max<x) max=x;
        if(max<y) max=y;
        f>>c;


    }
    f.close();
    return max;
}
void incarcare(mat v[100][100])
{
    fstream f("date.txt");
    int n;
   f>>n;
for(int i=0;i<nr_noduri();i++)
  for(int j=0;j<nr_noduri();j++)
    for(int k=0;k<1;k++)

  {
     v[i][j].car[k]=' ';
  }
  int r=0,x,y;
  char c[4];
  while(r<n)
  {f>>x>>y;
      f>>c;
      if(strchr(v[x-1][y-1].car,' ')==0)
    strcat(v[x-1][y-1].car,c);
    else
    strcpy(v[x-1][y-1].car,c);
      r++;
  }
  f.close();

}
void noduri_imp(int &nod_inceput,int &nr_noduri_term,int t[])
{
    ifstream f("date.txt");
    int n,x,y;
    char c;
    f>>n;
    for(int i=0;i<n;i++)
    {
        f>>x>>y;
        f>>c;
    }
    f>>nod_inceput;
    f>>nr_noduri_term;
    for(int i=0;i<nr_noduri_term;i++)
    {
       f>>x;
       t[i]=x;
    }
}
void afisare(mat v[100][100])
{
    int dim=nr_noduri();
   for(int i=0;i<dim;i++)
      {
          for(int j=0;j<dim;j++)
          cout<<v[i][j].car<<' ';
        cout<<endl;
      }
}
/*void tabel(mat v[100][100])
{
  int i,j;
cout<<"Tebel pentru A"<<endl;
for(i=0;i<nr_noduri();i++)
{
    cout<<"Q"<<i+1<<" :";
    int nr=0;
    for(j=0;j<nr_noduri();j++)
    {
        if(strchr(v[i][j].car,' ')==0)
          {
              if(strchr(v[i][j].car,'a')!=0)
                cout<<"q"<<j+1<<' ',nr++;
          }
    }

    cout<<endl;
}
cout<<"Tebel pentru B"<<endl;
for(i=0;i<nr_noduri();i++)
{
    cout<<"Q"<<i+1<<" :";
    for(j=0;j<nr_noduri();j++)
    {
        if(strchr(v[i][j].car,' ')==0)
          {
              if(strchr(v[i][j].car,'b')!=0)
                cout<<"q"<<j+1<<' ';
          }
    }
    cout<<endl;
}
}
*/
void tabel1(char c,int i,int &nr,int g[100],mat v[100][100])
{
  int j;
if(c=='a')
{
    nr=0;
    for(j=0;j<nr_noduri();j++)
    {
        if(strchr(v[i][j].car,' ')==0)
          {
              if(strchr(v[i][j].car,'a')!=0)
              {nr++;g[j]=1;}
          }
    }
}



if(c=='b')
{
    nr=0;
    for(j=0;j<nr_noduri();j++)
    {
        if(strchr(v[i][j].car,' ')==0)
          {
              if(strchr(v[i][j].car,'b')!=0)
              {nr++;g[j]=1;}
          }
    }
}
}

void tabel2(char c,mat v[100][100])
{
cout<<"Tebel pentru "<<c<<endl;
   for(int i=0;i<nr_noduri();i++)
   {int nr=0;
   int g[100];
   for(int k=0;k<nr_noduri();k++)
   g[k]=0;
       tabel1(c,i,nr,g,v);
       cout<<"Q"<<i+1<<" :";
       for(int j=0;j<nr_noduri();j++)
       {
           if(g[j]==1) cout<<"Q"<<j+1;
       }
       cout<<endl;
       if(nr>1)
       {
        for(int j=0;j<nr_noduri();j++)
       {
           if(g[j]==1)
           cout<<"q"<<j+1;
       }
       cout<<" :"<<endl;
       }

   }
}

int main()
{

mat v[100][100];
incarcare(v);
afisare(v);
tabel2('a',v);
tabel2('b',v);





        return 0;
}

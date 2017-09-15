#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

void insertie(int n, int v[])
    {

        cout<<endl<<"Tabloul Nesortat este: "<<endl;
        for(int i=0;i<n;i++) cout<<v[i]<<" ";

        for(int i=1;i<n;i++)
        {
            int aux=v[i];
            int j=i-1;

            while(aux<v[j] && j>-1)
                {
                    v[j+1]=v[j];
                    j--;
                }

                v[j+1]=aux;
        }

        cout<<endl<<endl<<"Tabloul Sortat este: "<<endl;
        for(int i=0;i<n;i++) cout<<v[i]<<" ";

        getch();
        system("cls");
    }

void bule(int n, int v[])
    {
        bool sortat=false;

        cout<<endl<<"Tabloul Nesortat este: "<<endl;
        for(int i=0;i<n;i++) cout<<v[i]<<" ";

        while(!sortat)
            {
                for(int i=0;i<n-1;i++)
                {
                    sortat=true;
                    for(int j=i+1;j<n;j++)
                        if(v[i]>v[j])
                            {
                                int aux=v[i];
                                v[i]=v[j];
                                v[j]=aux;
                                sortat=false;
                            }
                }
            }

        cout<<endl<<endl<<"Tabloul Sortat este: "<<endl;
        for(int i=0;i<n;i++) cout<<v[i]<<" ";

        getch();
        system("cls");

    }

void select(int n, int v[])
    {
        cout<<endl<<"Tabloul Nesortat este: "<<endl;
        for(int i=0;i<n;i++) cout<<v[i]<<" ";

        for(int i=0;i<n-1;i++)
        {
            int pozMin=i;
            for(int j=i+1;j<n;j++)
                if(v[j]<v[pozMin]) pozMin=j;

            int aux=v[i];
            v[i]=v[pozMin];
            v[pozMin]=aux;
        }

        cout<<endl<<endl<<"Tabloul Sortat este: "<<endl;
        for(int i=0;i<n;i++) cout<<v[i]<<" ";

        getch();
        system("cls");

    }

void schimb(int n, int v[])
    {
        cout<<endl<<"Tabloul Nesortat este: "<<endl;
        for(int i=0;i<n;i++) cout<<v[i]<<" ";

        for(int i=0;i<n-1;i++)
            {
                for(int j=i+1;j<n;j++)
                    if(v[i]>v[j])
                        {
                            int aux=v[i];
                            v[i]=v[j];
                            v[j]=aux;
                        }
            }

        cout<<endl<<endl<<"Tabloul Sortat este: "<<endl;
        for(int i=0;i<n;i++) cout<<v[i]<<" ";

        getch();
        system("cls");
    }

void quick(int v[], int stanga, int dreapta)
    {
        /////////////////////////////////////////

        int i=stanga, j=dreapta;
        int tmp, pivot=v[(i+j)/2];

        while(i<=j)
        {
            while(pivot>v[i])
                i++;
            while(pivot<v[j])
                j--;

            if(i<=j)
            {
                tmp=v[i];
                v[i]=v[j];
                v[j]=tmp;
                i++;
                j--;
            }
        }
            if(stanga < j)
                quick(v,stanga,j);
            if(dreapta > i)
                quick(v, i, dreapta);



    }

int main()
{
    int opt;

    int n, v[100];

    cout<<endl<<"n=";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cout<<endl<<"v["<<i<<"]=";
        cin>>v[i];
    }

    system("cls");

    do
    {
        cout<<endl<<"1.Sortare Insertie\n2.Sortare Bule\n3.Sortare Selectietie\n4.Sortare Interschimbare\n5.Sortare Rapida (Quick Sort)\n6.Inserati un nou tablou\n\n\n0.IESIRE";
        cout<<endl<<"Sortarea ta: ";
        cin>>opt;
        switch(opt)
            {
                case 1 : insertie(n,v); break;
                case 2 : bule(n,v); break;
                case 3 : select(n,v); break;
                case 4 : schimb(n,v); break;
                case 5 :
                        {
                            quick (v,0,n-1);
                            cout<<endl<<endl<<"Tabloul Sortat este: "<<endl;
                            for(int i=0;i<n;i++) cout<<v[i]<<" ";

                            getch();
                            system("cls");
                        } break;
                case 6 :
                    {
                        cout<<endl<<"n=";
                        cin>>n;

                        for(int i=0;i<n;i++)
                            {
                                cout<<endl<<"v["<<i<<"]=";
                                cin>>v[i];
                            }

                    getch();
                    system("cls");
                    }
                    break;
                case 0 : {break; break;}
                default: { cout<<endl<<"GRESIT!!"; getch(); system("cls");}
            }
    }
    while(opt);

    return 0;
}

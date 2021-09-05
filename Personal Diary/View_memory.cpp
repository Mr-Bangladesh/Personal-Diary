#include <bits/stdc++.h>
#include "View_memory.h"
#include "Maintain.h"
using namespace std;

int toint1(string a)
{
    stringstream geek(a);
    int n=0;
    geek>>n;
    return n;
}

void wait1()
{
    //for(int i=0;i<1e8;i++){}

    for(int j=0;j<1e9;j++){}
}

void suboption1()
{
    sub:

    cout<<"\n\t\t\t\t\t1.Back"<<endl;
    cout<<"\t\t\t\t\t2.Main Menu"<<endl;

    string input;

    cout<<"\t\t\t\t\tEnter: ";

    cin>>input;

    int I=toint1(input);

    if(I==1)
    {
        viewmemory();
    }
    else if(I==2)
    {
        system("cls");
        maintain();
    }
    else
    {
        cout<<"\n\t\t\t\t\tInvalid"<<endl;

        wait1();

        goto sub;
    }


}


void viewmemory()
{
    View_Memory:

        system("cls");

    cout<<"\n\n\t\t\t\t\t***Viewing All Memory***"<<endl<<endl;

    ifstream viewfile;

    viewfile.open("Memory/memories.txt"); ///memories er list

    string S;

    vector <string> listofmemory;

    int index=1;

    while(getline(viewfile,S))
    {
        listofmemory.push_back(S);
        cout<<"\t\t\t\t\t"<<index<<" "<<S<<endl;
        index++;
    }

    viewfile.close();

    if(index==1)
    {
        cout<<"\n\t\t\t\t\t\tList Empty!!!"<<endl;
        wait1();
        system("cls");
        maintain();
    }

    cout<<"\n\n\t\t\t\t\tEnter: ";

    string input;

    cin.ignore();

    cin>>input;

    int I=toint1(input);

    //cout<<"user input "<<I<<" "<<index<<endl;
    index--;

    if(I<1 || I>index)
    {
        cout<<"\n\n\t\t\t\t\tInvalid!"<<endl<<endl;

        wait1();

        system("cls");

        goto View_Memory;
    }

    string data=listofmemory[I-1];


    string data1="Memory/";
    data1+=data;
    data1+=".txt";

    string data2;

    ifstream viewdata;

    viewdata.open(data1,ios::app);

    cout<<endl<<endl<<endl;

    while(getline(viewdata,data2))
    {
        cout<<"\t\t\t"<<data2<<endl;
    }
    viewdata.close();

    cout<<endl<<endl<<endl;

    suboption1();

}

#include <bits/stdc++.h>
#include <fstream>
#include "Maintain.h"
#include "Add_memory.h"
using namespace std;


int toint2(string a)
{
    stringstream geek(a);
    int n=0;
    geek>>n;
    return n;
}
void wait2()
{
    //for(int i=0;i<1e8;i++){}

    for(int j=0;j<1e9;j++){}
}
int suboption()
{
    cout<<"\n\t\t\t\t\t1.Add More memory"<<endl;
    cout<<"\t\t\t\t\t2.Goto Main Menu"<<endl;
    cout<<"\n\t\t\t\t\tEnter: ";

    string input;

    cin>>input;

    int I=toint2(input);

    if(I!=2)
    {
        if(I!=1) {cout<<"\n\t\t\t\t\tInvalid!!"<<endl;
        wait2();}

        add_new_memory();
    }

    else if(I==2)
    {
        system("cls");
        maintain();
    }

}

string upper1(string S)
{
    int len=S.length();

    for(int i=0;i<len;i++)
    {
        S[i]=toupper(S[i]);
    }
    return S;
}

bool isexist1(string name,string location)
{
    name=upper1(name);

    string S;

    ifstream File1;

    File1.open(location);

    while(getline(File1,S))
    {
        S=upper1(S);
        if(name==S) return true;
    }

    File1.close();

    return false;

}

void add_new_memory()
{

    ADD_MEMORY:

        system("cls");

    string name;

    cout<<"\n\n\t\t\t\t\t\t***ADDING NEW MEMORY***"<<endl<<endl;

    cout<<"\t\t\t\t\tEnter name: ";
    cin.ignore();

    getline(cin,name); ///new memory name

    if(isexist1(name,"Memory/memories.txt")==true) ///jodi ei name age thake.
    {
        cout<<"\n\t\t\t\t\t\tAlready Exist!!!"<<endl;
        wait2();
        suboption();
    }


    ofstream savename("Memory/memories.txt",ios::app);

    savename<<name<<endl;

    savename.close();///je name e memory hobe ta list e save ses.

    ///ekhon oi name e ekta file create hobe.

    string S="Memory/";
    S+=name;
    S+=".txt";

    ofstream savememory(S,ios::app); ///je name dea hobe se name e ekta file create korlam.

    ///ekhon file e data dite hobe.

    string Data;

    cout<<"\n\n\t\t\t\tEnter Memory (to save data press '*' ):" <<endl;

    ///ekhon je input neya hobe ta sudhu file e pathaiya dilei hobe.


    while(1)
    {
        getline(cin,Data);
        if(Data=="*") break;
        savememory<<Data<<endl;
    }



    savememory.close();

    cout<<"\n\n\t\t\t\t\tSaved Successfully!!"<<endl<<endl;

    //cout<<"\t\t\t\t\tPress any number to Add new Memory ";

    suboption();

    //goto ADD_MEMORY;

}

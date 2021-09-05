#include <bits/stdc++.h>
#include "Delete_Memory.h"
#include "Maintain.h"
using namespace std;

int toint7(string a)
{
    stringstream geek(a);
    int n=0;
    geek>>n;
    return n;
}

void wait7()
{
    //for(int i=0;i<1e8;i++){}

    for(int j=0;j<1e9;j++){}
}

void suboption6()
{
    sub:

    cout<<"\n\t\t\t\t\t1.Back"<<endl;
    cout<<"\t\t\t\t\t2.Main Menu"<<endl;

    string input;

    cout<<"\t\t\t\t\tEnter: ";

    cin>>input;

    int I=toint7(input);

    if(I==1)
    {
        deletememory();
    }
    else if(I==2)
    {
        system("cls");
        maintain();
    }
    else
    {
        cout<<"\n\t\t\t\t\tInvalid"<<endl;

        wait7();

        goto sub;
    }


}

void deletefromlist1(string input,string R)
{
    string S=input; S+="_copy.txt";
    input+=".txt";

    ifstream filexe(input);

    ofstream fileexe2(S,ios::app);

    string Soo;

    while(getline(filexe,Soo))
    {
        if(Soo==R) continue;
        fileexe2<<Soo<<endl;
    }
    filexe.close(); fileexe2.close();

    ofstream fileexe3(input,ios::out); fileexe3.close();

    ifstream filexe4(S);
    ofstream filexe5(input,ios:: app);

    string Sxe1;

    while(getline(filexe4,Sxe1))
    {
        filexe5<<Sxe1<<endl;
    }

    filexe4.close(); filexe5.close();
    ofstream filexe6(S,ios::out); filexe6.close();
}

void deletedata1(string oopx)
{

    oopx+=".txt";
    ofstream fileexe31(oopx,ios::out); fileexe31.close();
}

void deletememory()
{
    DELETEMEMORY:

        system("cls");

    cout<<"\n\n\t\t\t\t\t***Deleting Memory***"<<endl<<endl;

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
        wait7();
        system("cls");
        maintain();
    }

    cout<<"\n\n\t\t\t\t\tEnter: ";

    string input;

    cin.ignore();

    cin>>input;

    int I=toint7(input);

    //cout<<"user input "<<I<<" "<<index<<endl;
    index--;

    if(I<1 || I>index)
    {
        cout<<"\n\n\t\t\t\t\tInvalid!"<<endl<<endl;

        wait7();

        system("cls");

        goto DELETEMEMORY;
    }

    string data=listofmemory[I-1];


    string data1="Memory/memories";

    deletefromlist1(data1,data);

    string data2="Memory/"; data2+=data;

    deletedata1(data2);

    cout<<"\n\n\t\t\t\t\tSuccessfully Deleted!!!"<<endl;

    cout<<endl<<endl<<endl;

    suboption6();

}

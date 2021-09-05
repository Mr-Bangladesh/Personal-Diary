#include <bits/stdc++.h>
#include "Delete_Event.h"
#include "Maintain.h"
using namespace std;

int toint8(string a)
{
    stringstream geek(a);
    int n=0;
    geek>>n;
    return n;
}

void wait8()
{
    //for(int i=0;i<1e8;i++){}

    for(int j=0;j<1e9;j++){}
}

void suboption7()
{
    sub:

    cout<<"\n\t\t\t\t\t1.Back"<<endl;
    cout<<"\t\t\t\t\t2.Main Menu"<<endl;

    string input;

    cout<<"\t\t\t\t\tEnter: ";

    cin>>input;

    int I=toint8(input);

    if(I==1)
    {
        deleteevent();
    }
    else if(I==2)
    {
        system("cls");
        maintain();
    }
    else
    {
        cout<<"\n\t\t\t\t\tInvalid"<<endl;

        wait8();

        goto sub;
    }


}

void deletefromlist2(string input,string R)
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

void deletedata2(string oopx)
{

    oopx+=".txt";
    ofstream fileexe31(oopx,ios::out); fileexe31.close();
}

void deleteevent()
{
    DELETEEVENT:

        system("cls");

    cout<<"\n\n\t\t\t\t\t***Deleting Event***"<<endl<<endl;

    ifstream viewfile;

    viewfile.open("Event/events.txt"); ///memories er list

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


    vector <string> nameofevent;
    vector <string> dateofevent;

    ifstream file1; ifstream file2;

    file1.open("Event/eventsname.txt"); file2.open("Event/eventsdate.txt");

    string F1,F2;

    while(getline(file1,F1))
    {
        nameofevent.push_back(F1);
    }

    while(getline(file2,F2))
    {
        dateofevent.push_back(F2);
    }

    file1.close(); file2.close();

    if(index==1)
    {
        cout<<"\n\t\t\t\t\t\tList Empty!!!"<<endl;
        wait8();
        system("cls");
        maintain();
    }

    cout<<"\n\n\t\t\t\t\tEnter: ";

    string input;

    cin.ignore();

    cin>>input;

    int I=toint8(input);

    //cout<<"user input "<<I<<" "<<index<<endl;
    index--;

    if(I<1 || I>index)
    {
        cout<<"\n\n\t\t\t\t\tInvalid!"<<endl<<endl;

        wait8();

        system("cls");

        goto DELETEEVENT;
    }

    string data=listofmemory[I-1];
    string D1=nameofevent[I-1];
    string D2=dateofevent[I-1];


    string data1="Event/events";

    deletefromlist2(data1,data);

    deletefromlist2("Event/eventsname",D1);

    deletefromlist2("Event/eventsdate",D2);

    string data2="Event/"; data2+=D1;

    deletedata2(data2);

    cout<<"\n\n\t\t\t\t\tSuccessfully Deleted!!!"<<endl;

    cout<<endl<<endl<<endl;

    suboption7();

}

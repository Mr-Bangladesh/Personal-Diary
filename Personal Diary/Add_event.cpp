#include <bits/stdc++.h>
#include "Maintain.h"
#include "Add_event.h"
using namespace std;

int toint3(string a)
{
    stringstream geek(a);
    int n=0;
    geek>>n;
    return n;
}

string tostring3(int N)
{
    string S;

    while(N!=0)
    {
        int r=N%10;
        N=N/10;
        S+=(r+48);
    }

    reverse(S.begin(),S.end());

    return S;

}

void wait3()
{
    //for(int i=0;i<1e8;i++){}

    for(int j=0;j<1e9;j++){}
}

string date1()
{

    string day,year,month;

    Return_date:

    cout<<"\n\t\t\t\t\tDay: ";
    cin>>day;
    int D=toint3(day);

    if(D<1 || D>31)
        {
            cout<<"\n\t\t\t\t\tNot valid!!"<<endl;
            wait3();
            goto Return_date;

        }

    cout<<"\n\t\t\t\t\tMonth: ";
    cin>>month;

    int M=toint3(month);

    if(M<1 || M>12)
    {
        cout<<"\n\t\t\t\t\tNot valid!!"<<endl;
        wait3();
        goto Return_date;
    }

    cout<<"\n\t\t\t\t\tYear: ";
    cin>>year;

    //string date=day+" "+month+" "+year;
    //cout<<date<<endl;
    string date=tostring3(D)+" "+tostring3(M)+" "+year;
    return date;

}

int suboption2()
{
    cout<<"\n\n\t\t\t\t\t1.Add More Event"<<endl;
    cout<<"\t\t\t\t\t2.Goto Main Menu"<<endl;
    cout<<"\n\t\t\t\t\tEnter: ";

    string input;

    cin>>input;

    int I=toint3(input);

    if(I!=2)
    {
        if(I!=1) {cout<<"\n\t\t\t\t\tInvalid!!"<<endl;
        wait3();}

        addevent();
    }

    else if(I==2)
    {
        system("cls");
        maintain();
    }

}

string upper2(string S)
{
    int len=S.length();

    for(int i=0;i<len;i++)
    {
        S[i]=toupper(S[i]);
    }
    return S;
}

bool isexist2(string name,string location)
{
    name=upper2(name);

    string S;

    ifstream File1;

    File1.open(location);

    while(getline(File1,S))
    {
        S=upper2(S);
        if(name==S) return true;
    }

    File1.close();

    return false;

}

void addevent()
{
    ADDEVENT:

        system("cls");

    cout<<"\n\n\n\n\t\t\t\t\t****ADDING NEW EVENT***"<<endl;

    cin.ignore();

    cout<<"\n\n\n\t\t\t\t\tEvent Name: ";

    string name;

    getline(cin,name);


    if(isexist2(name,"Event/eventsname.txt")==true)
    {
        cout<<"\n\t\t\t\t\tAlready Exist!!!"<<endl;
        wait3();
        suboption2();
    }

    cout<<"\n\n\n\t\t\t\t\t\tDate:"<<endl;

    string D=date1();


    ofstream saveeventname; ///events name save kora hocche.

    saveeventname.open("Event/eventsname.txt",ios::app);
    saveeventname<<name<<endl;
    saveeventname.close();


    ofstream saveeventdate; ///events date save kora hocche.

    saveeventdate.open("Event/eventsdate.txt",ios::app);
    saveeventdate<<D<<endl;
    saveeventdate.close();

    string namedate=name;

    namedate+="    ";
    namedate+=D;

    ofstream saveevent;

    saveevent.open("Event/events.txt",ios::app); ///events list e save kora hocche.

    saveevent<<namedate<<endl;

    saveevent.close();

    string name1="Event/";

    name1+=name;
    name1+=".txt";

    ofstream saveeventdata;

    saveeventdata.open(name1,ios::app);///event er name onusare ekta file create hocche.

    string description;

    cout<<"\n\t\t\t\t\tEnter Description of this Event (press * to save)"<<endl;
    cin.ignore();

    while(1)
    {
        getline(cin,description);
        if(description=="*") break;

        saveeventdata<<description<<endl;

    }

    cout<<"\n\n\t\t\t\t\tSaved Successfully!!"<<endl; saveeventdata.close();


    suboption2();

}

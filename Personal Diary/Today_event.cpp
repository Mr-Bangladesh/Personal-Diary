
#include <bits/stdc++.h>
#include "Passed_event.h"
#include "Today_event.h"
#include "Maintain.h"
using namespace std;


int toint5(string a)
{
    stringstream geek(a);
    int n=0;
    geek>>n;
    return n;
}
string tostring5(int N)
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


void wait5()
{
    //for(int i=0;i<1e8;i++){}

    for(int j=0;j<1e9;j++){}
}

string date3()
{

    string day,year,month;

    Return_date:

    cout<<"\n\t\t\t\t\tDay: ";
    cin>>day;
    int D=toint5(day);

    if(D<1 || D>31)
        {
            cout<<"\n\t\t\t\t\tNot valid!!"<<endl;
            wait5();
            goto Return_date;

        }

    cout<<"\n\t\t\t\t\tMonth: ";
    cin>>month;

    int M=toint5(month);

    if(M<1 || M>12)
    {
        cout<<"\n\t\t\t\t\tNot valid!!"<<endl;
        wait5();
        goto Return_date;
    }

    cout<<"\n\t\t\t\t\tYear: ";
    cin>>year;

    //string date=day+" "+month+" "+year;

    string date=tostring5(D)+" "+tostring5(M)+" "+year;

    //cout<<date<<endl;
    return date;

}


void suboption4()
{
    sub:

        cout<<"\n\n\t\t\t\t\t1.Back"<<endl;
        cout<<"\t\t\t\t\t2.Main Menu"<<endl;
        cout<<"\t\t\t\t\tEnter: ";
        string input;

        cin>>input;

        int I=toint5(input);

        if(I==1)
        {
            todayevent();
        }
        else if(I==2)
        {
            system("cls");
            maintain();
        }
        else
        {
            cout<<"\n\n\t\t\t\t\tInvalid!"<<endl;
            wait5();
            goto sub;
        }
}


void todayevent()
{
    TODAYEVENT:
        system("cls");

    cout<<"\n\n\n\t\t\t\t\t***TODAY EVENTS***"<<endl<<endl;

    cout<<"\n\t\t\t\t\tEnter Today's Date:"<<endl;

    string todaydate=date3();

    ifstream showevent; ///all list of events. date compare kore output debo.

    showevent.open("Event/events.txt");

    string S;

    int index=1;

    cin.ignore();

    cout<<endl<<endl<<endl;

    while(getline(showevent,S))
    {
        if(S.find(todaydate)!= string::npos){
            cout<<"\t\t\t\t\t"<<index<<" "<<S<<endl<<endl;
            index++;
        }
    }

    showevent.close();

    if(index==1)
    {
        cout<<"\n\t\t\t\t\t\tList Empty!!!"<<endl;
        wait5();
        system("cls");
        maintain();
    }


    ///ekhon user input er maddhome events er details dekhabo name input niye name file theke.


    ifstream showeventdata;

    showeventdata.open("Event/eventsname.txt");

    string S1;

    //cin.ignore();

    vector<string> eventdata;

    while(getline(showeventdata,S1))
    {
        eventdata.push_back(S1);
    }

    showeventdata.close();

    string input1;

    cout<<"\n\n\t\t\t\t\tEnter: ";
    cin>>input1;

    int I1=toint5(input1);

    index--;

    if(I1<1 || I1>index)
    {
        cout<<"\n\n\t\t\t\t\tInvalid!"<<endl;

        wait5();

        system("cls");

        goto TODAYEVENT;

    }

    string data=eventdata[I1-1];

    string data1="Event/";
    data1+=data; data1+=".txt";

    string data2;

    ifstream showeventdetails;

    showeventdetails.open(data1,ios::app); ///user input er name namer file ta open hoyeche.

    cout<<endl<<endl<<endl;
    cin.ignore();

    while(getline(showeventdetails,data2))
    {
        cout<<"\t\t"<<data2<<endl;
    }

    showeventdetails.close();

    cout<<endl<<endl<<endl;

    suboption4();



}

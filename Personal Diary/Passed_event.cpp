#include <bits/stdc++.h>
#include "Passed_event.h"
#include "Maintain.h"
using namespace std;


int toint4(string a)
{
    stringstream geek(a);
    int n=0;
    geek>>n;
    return n;
}

void wait4()
{
    //for(int i=0;i<1e8;i++){}

    for(int j=0;j<1e9;j++){}
}

//string date2()
//{
//
//    string day,year,month;
//
//    Return_date:
//
//    cout<<"\n\t\t\t\t\tDay: ";
//    cin>>day;
//    int D=toint4(day);
//
//    if(D<1 || D>31)
//        {
//            cout<<"\n\t\t\t\t\tNot valid!!"<<endl;
//            wait4();
//            goto Return_date;
//
//        }
//
//    cout<<"\n\t\t\t\t\tMonth: ";
//    cin>>month;
//
//    int M=toint4(month);
//
//    if(M<1 || M>12)
//    {
//        cout<<"\n\t\t\t\t\tNot valid!!"<<endl;
//        wait4();
//        goto Return_date;
//    }
//
//    cout<<"\n\t\t\t\t\tYear: ";
//    cin>>year;
//
//    string date=day+" "+month+" "+year;
//    //cout<<date<<endl;
//    return date;
//
//}

void suboption3()
{
    sub:

        cout<<"\n\n\t\t\t\t\t1.Back"<<endl;
        cout<<"\t\t\t\t\t2.Main Menu"<<endl;
        cout<<"\t\t\t\t\tEnter: ";
        string input;

        cin>>input;

        int I=toint4(input);

        if(I==1)
        {
            passedevent();
        }
        else if(I==2)
        {
            system("cls");
            maintain();
        }
        else
        {
            cout<<"\n\n\t\t\t\t\tInvalid!"<<endl;
            wait4();
            goto sub;
        }
}

void passedevent()
{
    PASSEDEVENT:

    system("cls");

    cout<<"\n\n\n\t\t\t\t\t***ALL EVENTS LIST***"<<endl<<endl;

    //cout<<"\n\t\t\t\t\tEnter Today's Date:"<<endl;

    //string todaydate=date2();

    ifstream showevent; ///all list of events. date compare kore output debo.

    showevent.open("Event/events.txt");

    string S;

    int index=1;

    cin.ignore();

    while(getline(showevent,S))
    {
        //if(S.find(todaydate)!= string::npos)
            cout<<"\t\t\t\t\t"<<index<<"\t"<<S<<endl;
            index++;
    }

    showevent.close();

    if(index==1)
    {
        cout<<"\n\t\t\t\t\t\tList Empty!!!"<<endl;
        wait4();
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

    int I1=toint4(input1);

    index--;

    if(I1<1 || I1>index)
    {
        cout<<"\n\n\t\t\t\t\tInvalid!"<<endl;

        wait4();

        system("cls");

        goto PASSEDEVENT;

    }

    string data=eventdata[I1-1];

    string data1="Event/";
    data1+=data; data1+=".txt";

    string data2;

    ifstream showeventdetails;

    showeventdetails.open(data1,ios::app);

    cout<<endl<<endl<<endl;
    cin.ignore();

    while(getline(showeventdetails,data2))
    {
        cout<<"\t\t"<<data2<<endl;
    }

    showeventdetails.close();

    cout<<endl<<endl<<endl;

    suboption3();



}

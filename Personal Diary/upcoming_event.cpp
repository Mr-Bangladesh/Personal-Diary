
#include <bits/stdc++.h>
#include "Passed_event.h"
#include "upcoming_event.h"
#include "Maintain.h"
using namespace std;


int toint6(string a)
{
    stringstream geek(a);
    int n=0;
    geek>>n;
    return n;
}

string tostring6(int N)
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

void wait6()
{
    //for(int i=0;i<1e8;i++){}

    for(int j=0;j<1e9;j++){}
}

string date4()
{

    string day,year,month;

    Return_date:

    cout<<"\n\t\t\t\t\tDay: ";
    cin>>day;
    int D=toint6(day);

    if(D<1 || D>31)
        {
            cout<<"\n\t\t\t\t\tNot valid!!"<<endl;
            wait6();
            goto Return_date;

        }

    cout<<"\n\t\t\t\t\tMonth: ";
    cin>>month;

    int M=toint6(month);

    if(M<1 || M>12)
    {
        cout<<"\n\t\t\t\t\tNot valid!!"<<endl;
        wait6();
        goto Return_date;
    }

    cout<<"\n\t\t\t\t\tYear: ";
    cin>>year;

    //string date=day+" "+month+" "+year;
    string date=tostring6(D)+" "+tostring6(M)+" "+year;
    //cout<<date<<endl;
    return date;

}

bool comparedate1(string today,string date) ///ajker date file er date.
{
    stringstream faizul1(today);
    stringstream faizul2(date);

    string S1[4], S2[4];

    faizul1>>S1[1]>>S1[2]>>S1[3];
    faizul2>>S2[1]>>S2[2]>>S2[3];

    int A1[4],A2[4];

    ///ajker date
    A1[1]=toint6(S1[1]);
    A1[2]=toint6(S1[2]);
    A1[3]=toint6(S1[3]);


    ///file er date
    A2[1]=toint6(S2[1]);
    A2[2]=toint6(S2[2]);
    A2[3]=toint6(S2[3]);

    ///ajker date ta boro kina check korbo.

    if(A1[3]>A2[3]) return 1;
    else if(A1[3]==A2[3])
    {
        if(A1[2]>A2[2]) return 1;
        else if(A1[2]==A2[2])
        {
            if(A1[1]>A2[1]) return 1;
            else return 0;
        }
        else return 0;
    }
    else return 0;


}



void suboption5()
{
    sub:

        cout<<"\n\n\t\t\t\t\t1.Back"<<endl;
        cout<<"\t\t\t\t\t2.Main Menu"<<endl;
        cout<<"\t\t\t\t\tEnter: ";
        string input;

        cin>>input;

        int I=toint6(input);

        if(I==1)
        {
            upcomingevent();
        }
        else if(I==2)
        {
            system("cls");
            maintain();
        }
        else
        {
            cout<<"\n\n\t\t\t\t\tInvalid!"<<endl;
            wait6();
            goto sub;
        }
}


void upcomingevent()
{
    UPCOMINGEVENT:
        system("cls");

    cout<<"\n\n\n\t\t\t\t\t***UPCOMING EVENTS***"<<endl<<endl;

    ///map kore date index e name ta rakhbo.then today date er sathe compare korbo.

    vector <string> nam;
    vector <string> tarikh;

    ifstream datefile; ifstream namefile;

    datefile.open("Event/eventsdate.txt"); namefile.open("Event/eventsname.txt");

    string P1,P2; //cin.ignore();

    while(getline(datefile,P1))
    {
        getline(namefile,P2);

        nam.push_back(P2); tarikh.push_back(P1);
    }

    datefile.close(); namefile.close();

    //for(it=mapping.begin();it!=mapping.end();it++) cout<<it->first<<" "<<it->second<<endl;

    cout<<"\n\t\t\t\t\tEnter Today's Date:"<<endl;

    string todaydate=date4();

    ifstream showevent; ///all list of events. date compare kore output debo. date er theke boro hote hobe.

    showevent.open("Event/eventsdate.txt");

    string S; int index=1;

    cin.ignore();

    cout<<endl<<endl<<endl;

    vector<string> eventdata; bool mark[10000]={0};///ekta date ekbar compare kora hole next time jeno ar na hoy.

    while(getline(showevent,S))///je date today date er ceye boro seta output dekhabo.
    {
        if(comparedate1(todaydate,S)==false){ ///jodi file er date gula ajker date er theke boro hoy.

                int paisi=0;
            for(int i=0;i<tarikh.size();i++)
            {
                if(tarikh[i]==S && mark[i]==0) ///date ta tarikh vector e search kore index ber koresi.
                {
                    //tarikh[i]="#";
                    mark[i]=1;
                    paisi=i; break;
                }
            }

             //cout<<paisi<<" "<<S<<endl;

            cout<<"\t\t\t\t\t"<<index<<"\t"<<nam[paisi]<<"\t"<<S<<endl; ///date index ber kore eventdata vector e nam er oi index ta rekhe disi..

            eventdata.push_back(nam[paisi]);
            index++;
        }
    }

    showevent.close();

    if(index==1)
    {
        cout<<"\n\t\t\t\t\t\tList Empty!!!"<<endl;
        wait6();
        system("cls");
        maintain();
    }


    ///ekhon user input er maddhome events er details dekhabo name input niye name file theke.

    string input1;

    cout<<"\n\n\t\t\t\t\tEnter: ";
    cin>>input1;

    int I1=toint6(input1);

    index--;

    if(I1<1 || I1>index)
    {
        cout<<"\n\n\t\t\t\t\tInvalid!"<<endl;

        wait6();

        system("cls");

        goto UPCOMINGEVENT;

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

    suboption5();



}

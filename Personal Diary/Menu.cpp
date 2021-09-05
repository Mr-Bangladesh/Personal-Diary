#include <bits/stdc++.h>
using namespace std;

int toint(string a)
{
    stringstream geek(a);
    int n=0;
    geek>>n;
    return n;
}


void wait()
{
    for(int i=0;i<1e9;i++){}

    //for(int j=0;j<1e10;j++){}
}

void notvalid()
{
    cout<<"\t\t\t\t\tNot valid"<<endl;
    wait();
    system("cls");
}

int main_menu()
{

    menu:

    cout<<"\n\n\n\n\n\t\t\t\t\t\t1.Add New Memory"<<endl<<endl;
    cout<<"\t\t\t\t\t\t2.View Old Memory"<<endl<<endl;
    cout<<"\t\t\t\t\t\t3.Add New Event"<<endl<<endl;
    cout<<"\t\t\t\t\t\t4.All Events"<<endl<<endl;
    cout<<"\t\t\t\t\t\t5.Upcoming Events"<<endl<<endl;
    cout<<"\t\t\t\t\t\t6.Today's Events"<<endl<<endl;
    cout<<"\t\t\t\t\t\t7.Delete Memory"<<endl<<endl;
    cout<<"\t\t\t\t\t\t8.Delete Event"<<endl<<endl;


    string input;

    cout<<"\t\t\t\t\t\tEnter: ";
    cin>>input;

    int I=toint(input);

    if(I<1 || I>8)
    {
        notvalid();
        goto menu;
    }

    return I;


}

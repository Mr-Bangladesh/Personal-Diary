#include <bits/stdc++.h>
#include <windows.h>
#include "Menu.h"
#include "Add_memory.h"
#include "View_memory.h"
#include "Add_event.h"
#include "Passed_event.h"
#include "Today_event.h"
#include "upcoming_event.h"
#include "Delete_Event.h"
#include "Delete_Memory.h"

using namespace std;

void maintain()
{
    int input=main_menu();

    if(input==1)
    {
        //system("cls");
        add_new_memory();
    }
    else if(input==2)
    {
        //system("cls");
        viewmemory();
    }
    else if(input==3)
    {
        addevent();
    }
    else if(input==4)
    {
        passedevent(); ///etai all events.
    }
    else if(input==5)
    {
        upcomingevent();
    }
    else if(input==6)
    {
        todayevent();
    }

    else if(input==7)
    {
        deletememory();
    }
    else if(input==8)
    {
        deleteevent();
    }

}

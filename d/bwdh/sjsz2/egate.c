//Cracked by Roath
// /d/bwdh/sjsz/wgate.c
// 试剑山庄东门
// by sdong 08/8/99

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

string long_desc();
int do_start(string arg);
int do_stop(string arg);
int start(string host,string challenger);
int do_close_men();
int do_open_men(string arg);


void create()
{
	set("short", HIR"试剑山庄东门"NOR);
	set("long", (: long_desc :));
	set("invalid_startroom", 1);

	//set("no_fight", 1);

	set("exits", ([
		"enter" : "/d/bwdh/sjsz/egarden",
	]));

	create_room();
	setup();
}

void init()
{
	init_room();
}


string long_desc()
{
  	string desc,temp;
	int nRank,i,j;

  	desc  = HIW"

		           /I______________I\\               
		         //||||||||||||||||||\\\\            
		     T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T       
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIM"[ 试剑山庄 ]"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIY"
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIB"
             ||                  "+HIW"[东门]"+HIB"                  ||
             ||                ___________               ||
             ||               @           @              ||
             ||               |           |              ||
             ||               |           |              ||
             ||               |           |              ||
             ||               |           |              ||
             ||               |           |              ||
             ||_______________|___________|______________||\n\n"NOR;

  	return desc;
}



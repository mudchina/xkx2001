//Cracked by Roath
// group bwdh/room 28
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"
void open_basement();

void create() {
    set("short", HIW"比武厅"NOR);
    set("long", @LONG
比武厅花岗石地上血迹斑斑，到处是刀、剑的砍痕。
有的地方还有脚印，显然是内功极深的人印上的。空气中
渗透着血腥气和腐尸味，使你受到异常的刺激，禁不住血
脉忿张。
LONG
	 );
	 set("objects", ([
		  __DIR__"npc/master" : 1,
	 ]));
	 set("exits", ([
		  "north"     : __DIR__"room_23",
		  "east"      : __DIR__"room_26",
		  "south"     : __DIR__"room_24",
		  "west"      : __DIR__"room_21",
	 ]));
	 create_room();


	 setup();

	 call_out("open_basement",2);
}



void init() {
	 init_room();
	 call_out("open_basement",1);
}

void open_basement()
{

	 if( query("exits/down") ) return ;

	 if( !present("master") )
	 {
		if( !query("exits/down") )
			message("vision",HIR"只听轰的一声响，地上自动打开了一扇大门。\n\n"NOR,this_object() );
		 set("exits/down",__DIR__"room_29");
	 }
	 else delete("exits/down");

	 remove_call_out("open_basement");
	 call_out("open_basement",10);
}

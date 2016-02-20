//Cracked by Roath
// /d/bwdh/sjsz/wgarden.c
#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create()
{
		  set("short", HIC"花园"NOR);
		  set("long", @LONG
这是一个园子，庭院清幽，异种花卉甚是不少。百花争放，山石古拙，
杨柳垂清，苍松翠竹，景致煞是宜人。清澈的溪流旁耸立着一座小亭子，
潺潺溪水向西南流去。
LONG
		  );
		  set("exits", ([ /* sizeof() == 2 */
				"east" : __DIR__"wting",
				"out" : __DIR__"wgate",
		  ]));

		  set("cost", 0);
 	          set("outdoors", "city");
		  create_room();
		  setup();
}

void init()
{
	init_room();
}


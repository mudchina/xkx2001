//Cracked by Roath
// /d/hangzhou/haidi.c   海堤
// by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{        set("short", "海堤");
         set("long", @LONG
这儿好几十里是人工修筑的海堤。因为海水倒灌，毁损良田。历代官府经
常动员民工不断修筑海堤，民工众多便自然纠集成塘帮。塘帮都是苦力，虽对
官吏时常克扣工饷不满，但绝无造反之心。
LONG	);

         set("exits", ([ /* sizeof() == 2 */ 
                   "east" : __DIR__"yantian",
                   "southwest" : __DIR__"village", 
         ]));

	 set("objects", ([
                __DIR__"npc/tbbz" : 2,
                
         ]));

	 set("cost", 1);
         set("outdoors", "hangzhou");

         setup();

         replace_program(ROOM);
}

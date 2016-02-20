//Cracked by Roath
// 灵隐寺
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{       set("short", "灵隐寺");
        set("long", @LONG
灵隐寺又名云林寺，寺前有清澈的小溪，溪旁建有冷泉亭和赫雷
亭。天王殿举目可见，殿外有两座经幢。往南便回到大道。
LONG);

        set("exits", ([ /* sizeof() == 2 */ 
               "eastdown" : __DIR__"road34", 
	       "enter" : __DIR__"lingyin1",
        ]));

	set("objects", ([
               __DIR__"npc/zhike" : 1,
        ]));

	set("cost", 1);

        setup();
        replace_program(ROOM);
}

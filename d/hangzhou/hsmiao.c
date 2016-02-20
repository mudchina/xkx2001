//Cracked by Roath
// /d/hangzhou/hsmiao.c   海神庙
// by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{        set("short", "海神庙");
         set("long", @LONG
这里是靠海的一个小丘，东北角一块突出的山岩之上有一所庙宇。屋前扁
额，隐约可见是“海神庙”三字。海神庙极是简陋，满地尘土，庙中也无庙祝。
LONG	);

         set("exits", ([ /* sizeof() == 2 */
                   "southwest" : __DIR__"yantian",
                   "north" : "/d/jiaxing/field",
                 ])
         );

	 set("objects", ([
                __DIR__"npc/tyjz" : 1,
         ]));

	 set("cost", 1);
         set("outdoors", "hangzhou");

         setup();

         replace_program(ROOM);
}

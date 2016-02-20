//Cracked by Roath
// Room: /d/xixia/jiangjunfu.c

inherit ROOM;

void create()
{
	set("short", "大将军府");
	set("long", @LONG
这里是征东大将军赫连铁树的府第，在东大街的正中，对面就是衙门。
一色高檐大屋，两个校尉看上去彪悍骁勇，此刻正神气活现的挎着弯刀守
在门前。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jjdayuan",
  "north" : __DIR__"dongdajie",
]));
	set("objects", ([
		__DIR__"npc/xiaowei" : 2,
	]));
	
	set("outdoors", "xixia");

	setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="south" ) {
        if (present("xiao wei", environment(me)))
                return notify_fail("校尉挡住了你的去路！\n");
        }
   return ::valid_leave(me, dir);
}

//Cracked by Roath
// Room: /d/xixia/ypgate.c

inherit ROOM;

void create()
{
	set("short", "一品堂大门");
	set("long", @LONG
这里是西夏一品堂的所在地，座落在东大街的北面，是一座高大的
石头建筑，看上去坚固之极。门口有两个武士站着，既不高大也不彪悍，
和皇宫门口的守卫差远啦，就是和衙门口的衙役比也颇有不如，但从他
们阴鹫的眼神里你不难看出他们是身怀绝技的高手，谁不知西夏一品堂
广招天下高手为皇上效命。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dayuan",
  "south" : __DIR__"xidajie",
]));
	set("objects", ([
		__DIR__"npc/ypshi" : 4,
	]));
	set("outdoors", "xixia");
	set("cost", 1);

	setup();
}
int valid_leave(object me, string dir)
{
   if (dir =="north" ) {
        if (present("wu shi", environment(me))
	&& !me->query_temp("xixia/一品堂") && me->query("yipin/done") < 10 ) 
                return notify_fail("一品堂武士挡住了你的去路！\n");
	}
   return ::valid_leave(me, dir);
}


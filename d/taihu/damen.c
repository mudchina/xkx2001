//Cracked by Roath
//Kane

inherit ROOM;

void create()
{
	set("short", "大门");
	set("long", @LONG
面前是一座庄院，门楼不甚高大，青砖绿瓦，灰色底的匾上写着
『归云庄』三个大黑字。牌匾较为陈旧，边角处的漆皮已剥落，露出
暗黄色的木质。看来挂在那已不下二十个春秋了。
LONG
	);
	 set("exits", ([
		"enter" : __DIR__"qianyuan",
		"south" : __DIR__"matou",
	]));
	set("cost", 1);
	set("outdoors", "taihu");
	set("objects", ([
		"/d/taihu/npc/jiading" : 2,
	]));

	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
    mapping myfam = (mapping)me->query("family");

    if ( (!myfam || myfam["family_name"] != "桃花岛") && (dir == "enter") && (!me->query_temp("guiyun")) && present("jia ding", environment(me)))
	return notify_fail("家丁做了个揖，说道：尊驾与敝庄素无往来，庄主不见外客，还是请回吧\n");

    return ::valid_leave(me, dir);
}

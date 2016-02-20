//Cracked by Roath
// Room: /d/xixia/jjdayuan.c

inherit ROOM;

void create()
{
	set("short", "将军府大院");
	set("long", @LONG
这里是将军府的大院，当面一堵宽阔的白玉照壁，上书“忠心报国”
四个大字，落款是当今西夏皇帝李元昊。一色的青砖铺地，有几个仆役正
在院中洒扫，南面是内宅，西面是帐房，东面是个小院。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/city/npc/jiading" : 2,
]));
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jiangjunfu",
  "east" : __DIR__"zhaiyuan.c",
  "enter" : __DIR__"xiaolou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

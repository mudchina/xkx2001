//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov7.c

inherit ROOM;

void create()
{
	set("short", "碧鸡山顶");
	set("long", @LONG
碧鸡山坐在滇池的西岸上，与拓东城隔水相望。山势高耸入云，山形有如公
鸡，漫山树木苍翠欲滴。此处乃是极顶，已达云端，东眺滇池一片汪洋，美不胜
收。山下属大理国的昆州。东西皆有下山之路。
LONG);
	set("objects", ([
		__DIR__"npc/youke1.c" : 1,
		]));
	set("exits", ([
		"westdown" : __DIR__"minov6",
		"eastdown" : __DIR__"minov19",
		]));
	set("area", "大叠水瀑布");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

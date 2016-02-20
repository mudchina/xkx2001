//Cracked by Kafei
// Room: /dali/jhg1.c
// AceP

inherit ROOM;

void create()
{
	set("short", "剑湖宫广场");
	set("long", @LONG
这里就是剑湖宫了。此处是无量剑弟子练武的广场，正北面是一座雄伟的大厅，
里面传来刀剑相交之声，看来剑会正在进行中。两边不远有一些房舍，是无量剑弟
子的住所。一些无量剑弟子正在焦急地走动，等待斗剑会的结果。
LONG
	);

	set("exits", ([
		"north"    : __DIR__"jhg",
		"eastdown" : __DIR__"wls",
	]));

	set("objects", ([
		__DIR__"npc/gan": 1,
		__DIR__"npc/ge": 1,
	]));

	set("cost", 1);
        set("outdoors", "dali");
	setup();
}

//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov87.c

inherit ROOM;

void create()
{
	set("short", "剑川山口");
	set("long", @LONG
这是苍山北麓的一个乌夷城镇。此地正处山口，两边崇山峻岭耸立，几乎无
路可行，唯有穿此镇可入苍山，因此是从蜀中至大理的军事要冲，大理国在此修
有刁楼箭塔，常年驻军。有官兵在镇口站岗巡逻，盘察过往行人。
LONG);
	set("objects", ([
		__DIR__"npc/dalishibing" : 3,
		__DIR__"npc/wujiang" : 1,
		]));
	set("exits", ([
		"northup" : __DIR__"minov88",
		"south" : __DIR__"minov86",
		]));
	set("area", "剑川镇");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov89.c

inherit ROOM;

void create()
{
	set("short", "乌弄城");
	set("long", @LONG
此处位于大理的北疆，是乌蒙的珙部的治府，乌蒙属乌夷，居民多居于高山
上。这里正处高山之腰，北临波涛汹涌的大渡河。巷陌皆用山石垒成，高丈余，
延绵全城。此城不大，四面山上分布着些乌蒙民居，有牧人赶着牛羊穿镇而过。
LONG);
	set("objects", ([
		__DIR__"npc/wyshang.c" : 1,
		]));
	set("exits", ([
		"northdown" : __DIR__"minov90",
		"southdown" : __DIR__"minov88",
		"eastup" : __DIR__"minov91",
		]));
	set("area", "乌弄城");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

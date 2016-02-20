//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov48.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一座用木柴及兽皮搭成的乌夷民居。此地的村民主要从事耕作，由于实
行换季轮耕，不得不经常迁徙，因而房舍都颇简陋，说是房舍，倒不如说更象帐
篷，拆、建都甚方便。
LONG);
	set("objects", ([
		__DIR__"npc/wykid" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"minov47",
		]));
	set("area", "泸水沿岸");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

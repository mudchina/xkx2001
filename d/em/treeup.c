//Cracked by Roath
// treeup.c 

inherit ROOM;

void create()
{
        set("short", "树上");
	set("long", @LONG
一股腥臭之气扑面而来。你抬头一看，顿时毛骨悚然，一条碗口粗细的巨
蟒倒悬在树干上，张开大口，正要向你扑来！
LONG
	);
	set("exits", ([
		"down" : __DIR__"dao9"+(random(4)+6),
	]));
	
	set("objects", ([
		__DIR__"npc/jumang" : 1,
	]));

	set("cost", 3);
	setup();
	replace_program(ROOM);
}

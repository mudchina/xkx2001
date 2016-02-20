//Cracked by Roath
//GU MU FROM SANTA
//linn.C

inherit ROOM;

void create()
{
	set("short", "朝英练功室");
	set("long", @LONG
这是石室甚宽，正是当年林朝英练习拳法的地方。
LONG
	);
	 set("exits", ([
		"south" : __DIR__"linc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}







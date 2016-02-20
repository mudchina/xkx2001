//Cracked by Roath
//GU MU FROM SANTA
//lins.C

inherit ROOM;

void create()
{
	set("short", "朝英练功室");
	set("long", @LONG
这是石室甚是狭窄，正是当年林朝英练习掌法的地方。

 LONG
	);
	 set("exits", ([
		"north" : __DIR__"linc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}






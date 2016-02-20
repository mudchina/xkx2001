//Cracked by Roath
//GU MU FROM SANTA
//linw.C

inherit ROOM;

void create()
{
	set("short", "朝英练功室");
	set("long", @LONG
这石室呈圆型，正是当年林朝英练习剑法的地方。

 LONG
	);
	 set("exits", ([
		"east" : __DIR__"linc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}








//Cracked by Roath
//GU MU FROM SANTA
//line.C

inherit ROOM;

void create()
{
	set("short", "朝英练功室");
	set("long", @LONG
这石室呈角状，正是当年林朝英练习镖法的地方。
 LONG
	);
	 set("exits", ([
		"west" : __DIR__"linc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}







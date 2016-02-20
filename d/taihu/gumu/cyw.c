//Cracked by Roath
//GU MU FROM SANTA
//cyw.C

inherit ROOM;

void create()
{
	set("short", "重阳练功室");
	set("long", @LONG
这石室呈角状，正是当年王重阳练习镖法的地方。
 LONG
	);
	 set("exits", ([
		"east" : __DIR__"cyc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}







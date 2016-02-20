//Cracked by Roath
//GU MU FROM SANTA
//cye.C

inherit ROOM;

void create()
{
	set("short", "重阳练功室");
	set("long", @LONG
这石室呈圆型，正是当年王重阳练习剑法的地方。

 LONG
	);
	 set("exits", ([
		"west" : __DIR__"cyc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}







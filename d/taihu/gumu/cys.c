//Cracked by Roath
//GU MU FROM SANTA
//cys.C

inherit ROOM;

void create()
{
	set("short", "重阳练功室");
	set("long", @LONG
这是石室甚宽，正是当年王重阳练习拳法的地方。
LONG
	);
	 set("exits", ([
		"north" : __DIR__"cyc",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}







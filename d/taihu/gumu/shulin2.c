//Cracked by Roath
//GU MU FROM SANTA
//SHULIN2.C

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
入林越深，鸟鸣越是动听，花香也越浓。只是那不
知名的声音也越来越响。还是当心一点的好。
LONG
	);

	set("exits", ([
		"south" : __DIR__"fenglin1",
		"north" : __DIR__"shulin1",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}





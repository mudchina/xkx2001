//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "文华门");
	set("long",  @LONG
从这里向东就可以出东华门，向西是协和门，向南是红本库，向
北是文华殿。
LONG
	);

	set("exits", ([
		"north" : __DIR__"wenhuadian",
		"south" : __DIR__"hongbenku",
		"west"  : __DIR__"xiehemen",
		"east"  : __DIR__"donghuamen",
	]));
	set("outdoors","beijing");
	
	setup();
	replace_program(ROOM);
}
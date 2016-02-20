//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "西华门");
	set("long",  @LONG
这是紫禁城的一个偏门，经常可以看见有人在这进进出出。门口
有几个御林军在站岗，但仔细一看，发现他们在打盹。
LONG
	);

	set("exits", ([
		"east" : __DIR__"wuyingmen",	
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}
//Cracked by Roath
// Room: /d/dali/shanlu3.c

inherit ROOM;

void create()
{
	set("short", "古道");
	set("long", @LONG
一条石板古道，两边树木苍翠，山势平缓，南面是一望无际的西双版纳大森
林。大道北面有一片宏伟建筑，一堵里许长的红墙隔开，越过墙头可见一座高楼
耸立，正是大理名胜五华楼。
LONG);
	set("exits", ([
		"westup" : __DIR__"shanlu2.c",
		"east" : __DIR__"shanlu4.c",
		"north" : __DIR__"wuhua.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

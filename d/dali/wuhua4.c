//Cracked by Roath
// Room: /d/dali/wuhua4.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间客房，靠墙放了一张梨木大床，上面的被褥尽是苏绣，工美绝伦。
正中放了一张八仙桌，几个奇服南人正在高谈阔论。
LONG);
	set("objects", ([
		__DIR__"npc/pucong" : 2,
		]));
	set("exits", ([
		"out" : __DIR__"wuhua8.c",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/quanzhou/qzroad2.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条山路上。时值春日，路旁的山坡上开满了金黄色的油菜花。
东面是江南名城嘉兴。
LONG
	);

	set("exits", ([
                "east"  : __DIR__"jiaxing",
                "northwest" : "/d/taihu/road",
	]));

	set("outdoors", "quanzhou");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}


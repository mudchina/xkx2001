//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov27.c

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
一片临湖的稻田，田里积满了水，田埂很高，且干燥，可以供走动，田间挖
掘了相当多的引水沟渠。南诏雨水充足，河湖众多，虽然是山地地区，灌溉也不
成问题。此去东边有些杆栏民居。
LONG);
	set("objects", ([
		__DIR__"npc/bynong.c" : 2,
		]));
	set("exits", ([
		"southwest" : __DIR__"minov26",
		"east" : __DIR__"minov28",
		]));
	set("area", "阳宗镇");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}

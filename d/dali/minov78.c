//Cracked by Roath
// minority or tribe village and suburban
// Room: /d/dali/minov78.c

inherit ROOM;

void create()
{
	set("short", "鲁望镇");
	set("long", @LONG
这里是普麽部的鲁望镇，普麽部属台夷，领属还有附近的越州。这是一座建
在山坡上的小镇，东面和北面是高耸的群山，向西和南眺望均可见村庄和城镇。
LONG);
	set("objects", ([
		__DIR__"npc/tyshang" : 1,
		]));
	set("exits", ([
		"westdown" : __DIR__"minov71",
		"north" : __DIR__"minov79",
		"south" : __DIR__"minov82",
		"east" : __DIR__"minov83",
		]));
	set("area", "鲁望镇");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}

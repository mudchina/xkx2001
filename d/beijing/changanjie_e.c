//Cracked by Roath
// Room: /d/beijing/changanjie_e.c

inherit ROOM;

void create()
{
	set("short", "东长安街");
	set("long", @LONG
这是繁华热闹的长安街，大街北面就是守卫森严的紫禁城南门天安门了。这
里时常有巡逻的侍卫盘查过路的行人。大街两边是各种店铺，你看的眼都花了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
                "east"  : __DIR__"chongwenmen",
		"west"  : __DIR__"changanjie",
		"southwest" : __DIR__"rongbaozhai",
		"southeast" : __DIR__"huayuan",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	replace_program(ROOM);
}

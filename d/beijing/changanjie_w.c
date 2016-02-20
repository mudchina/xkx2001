//Cracked by Roath
// Room: /d/beijing/changanjie_w.c

inherit ROOM;

void create()
{
	set("short", "西长安街");
	set("long", @LONG
这是繁华热闹的长安街，大街北面就是守卫森严的紫禁城南门天安门了。这
里时常有巡逻的侍卫盘查过路的行人。大街两边是各种店铺，你看的眼都花了。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
                  "east"  : __DIR__"changanjie",
		  "west"  : __DIR__"xuanwumen",
		  "southwest":__DIR__"yuefang",
		  "southeast":__DIR__"qitang",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	replace_program(ROOM);
}

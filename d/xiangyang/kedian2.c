//Cracked by Roath
// Room: /d/xiangyang/kedian2.c

inherit ROOM;

void create()
{
	set("short", "客店二楼");
	set("long", @LONG
这就是襄樊客店二楼的走廊，偶尔有些旅客提心吊胆地走过，
也有几个人似乎没把城外的战事放在心上，神色轻得多。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"kedian3",
  "down" : __DIR__"kedian",
]));

	setup();
	replace_program(ROOM);
}

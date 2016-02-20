//Cracked by Roath
// Room: /d/beijing/zijincheng/kunninggong.c

inherit ROOM;

void create()
{
	set("short", "坤宁宫");
	set("long", @LONG
    这里是皇后住的正宫，它的正门开在偏东一间，后三宫后面
向北开有坤宁门。出坤宁门就是御花园了。
    清宫在这里祭神,每天有朝祭,夕祭,平时有司祝,司香,司俎等
人祭祀,大祭的日子皇帝,皇后亲自参加.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"kunningmen",
  "south" : __DIR__"jiaotaidian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/beijing/zijincheng/houzuomen.c

inherit ROOM;

void create()
{
	set("short", "后左门");
	set("long", @LONG
从这里向北是乾清门，向南是中左门，许多太监和侍卫从这里经过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"qianqingmen",
  "south" : __DIR__"xiaodao2",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/beijing/zijincheng/houyoumen.c

inherit ROOM;

void create()
{
	set("short", "后右门");
	set("long", @LONG
从这里向北是乾清门，向南是中右门，许多太监和侍卫从这里经过。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"qianqingmen",
  "south" : __DIR__"xiaodao1",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

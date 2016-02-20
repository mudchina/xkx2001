//Cracked by Roath
// Room: /d/beijing/zijincheng/jingshifang.c

inherit ROOM;

void create()
{
	set("short", "敬事房");
	set("long", @LONG
这是宫殿监办事处,也是总管各处太监事务的敬事房。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"nanshufang",
  "east" : __DIR__"qianqingmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

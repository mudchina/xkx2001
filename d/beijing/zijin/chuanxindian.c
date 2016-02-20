//Cracked by Roath
// Room: /d/beijing/zijincheng/chuanxin.c

inherit ROOM;

void create()
{
	set("short", "传心殿");
	set("long", @LONG
这是文渊阁的偏殿，里面空无一物，地上落满了灰尘，靠墙处有几个大书架，
不知道是放的什么书．这里看起来好久没有人打扫了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"wenhuadian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

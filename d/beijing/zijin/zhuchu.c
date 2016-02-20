//Cracked by Roath
// Room: /d/beijing/zijincheng/zhuchu.c

inherit ROOM;

void create()
{
	set("short", "海老公处");
	set("long", @LONG
这是一间大房，但物事稀少，只一张桌子，一张椅子。
桌上放着茶壶茶碗，墙上安着两座铜烛台，各点着一只
蜡烛。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"neishi",
  "west" : __DIR__"guang4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/beijing/east/guanmiaoting.c

inherit ROOM;

void create()
{
	set("short", "观妙亭");
	set("long", @LONG
这是五峰亭中的一座，四周景色秀丽，恬静宜人。亭子里有
一张石桌，几张石凳，供游人休息。旁边有一棵歪脖槐树，相传是
明末皇帝崇祯自缢之处。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"shandao6",
  "southdown" : __DIR__"xiaojing3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

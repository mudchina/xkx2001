//Cracked by Roath
// Room: didao1.c 地道
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "地道");
	set("long", @LONG
这里是厚土旗挖的地道，里面黑漆漆的，只有几柄火把插在墙上。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"up": __DIR__"didao",
		"east": __DIR__"didao_e",
		"west": __DIR__"didao_w",
		"north": __DIR__"didao_n",
		"south": __DIR__"didao_s",
]));
	set("no_clean_up", 1);
	set("cost", 1);

	setup();
//	replace_program(ROOM);
}

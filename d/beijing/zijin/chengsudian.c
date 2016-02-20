//Cracked by Roath
// Room: /d/beijing/zijincheng/chengsudian.c

inherit ROOM;

void create()
{
	set("short", "诚肃殿");
	set("long", @LONG
这里是诚肃殿。向北走是景仁宫，向南是斋宫。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jingrengong",
  "south" : __DIR__"zhaigong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/beijing/zijincheng/huangjidian.c

inherit ROOM;

void create()
{
	set("short", "皇极殿");
	set("long", @LONG
这里是乾隆皇帝准备当太上皇举行典礼的地方。嘉庆元年，乾隆
太上皇曾在此殿举行千叟宴。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ningshougong.c",
  "south" : __DIR__"ningshoumen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

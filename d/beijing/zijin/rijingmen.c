//Cracked by Roath
// Room: /d/beijing/zijincheng/rijingmen.c

inherit ROOM;

void create()
{
	set("short", "日精门");
	set("long", @LONG
这是连接后三殿和东六宫的一个偏门。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yuyaofang",
  "north" : __DIR__"duanningdian",
  "east" : __DIR__"neizuomen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

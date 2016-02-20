//Cracked by Roath
// Room: /d/beijing/west/danbiqiao.c

inherit ROOM;

void create()
{
	set("short", "丹陛桥");
	set("long", @LONG
这条大道高出周围平地数尺，如同一座桥将北面的祈年殿和
南面的圜丘连接在一起。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"huangqiongyu",
  "north" : __DIR__"qiniandian",
  "westdown" : __DIR__"shibanlu2",
  "eastdown" : __DIR__"shibanlu3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

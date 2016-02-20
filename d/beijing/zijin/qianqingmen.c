//Cracked by Roath
// Room: /d/beijing/zijincheng/qianqingmen.c

inherit ROOM;

void create()
{
	set("short", "乾清门");
	set("long", @LONG
   这是内廷的正门,是清朝御门听政的地方.很多军国大
事都是在御门听政时决定的.
   这里向北是一条白玉石通道,两侧是庑廊,通向各个房间.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"xiaohuayuan",
  "north" : __DIR__"yard1",
  "west" : __DIR__"jingshifang",
  "east" : __DIR__"shangshufang",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

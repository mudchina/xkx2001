//Cracked by Roath
// Room: /d/xixia/hsxia.c

inherit ROOM;

void create()
{
	set("short", "红山峡");
	set("long", @LONG
红山峡是个非常险峻的峡谷，两边是数十丈的黄土坡，很是陡峭，中
间只有一条可以通行一人一马的窄道，俗称“一线天”。附近没有什么生
物，却有商旅常在这里失踪。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jingyuan",
  "north" : __DIR__"shimen",
]));
	set("objects", ([
		__DIR__"npc/mazei" : 1,
	]));
	setup();
	replace_program(ROOM);
}

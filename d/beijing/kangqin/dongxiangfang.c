//Cracked by Roath
// Room: /d/beijing/kangqin/dongxiangfang.c

inherit ROOM;

void create()
{
	set("short", "东厢房");
	set("long", @LONG
这是一间很宽敞的房间。靠窗口有一张炕，上面铺着锦被。炕
边有张桌子，上面放着一盏油灯。地面很干净，显然经常有人打扫。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"tingyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

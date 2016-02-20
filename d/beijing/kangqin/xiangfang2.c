//Cracked by Roath
// Room: /d/beijing/kangqin/xiangfang2.c

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
这里是康亲王请来的武师们住的地方。房间里摆设不
多，但很齐全。这里经常有仆人来打扫，窗明几亮。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xiaoyuan",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

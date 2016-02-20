//Cracked by Roath
// Room: /d/mingjiao/shenchu.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "密林深处");
	set("long", @LONG
阳光经过枝叶的过滤，落地时已变得十分虚弱。林深处传来种种怪音，
如若不是脚下还有一条小路，谁知这并不欢迎外界来客的树林深处，竟还
住着一群巨木好汉。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"mguangchang",
  "southwest" : __DIR__"xiaolu37",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}

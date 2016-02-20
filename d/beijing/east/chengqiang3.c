//Cracked by Roath
// Room: /d/beijing/east/chengqiang3.c

inherit ROOM;

void create()
{
	set("short", "城墙");
	set("long", @LONG
这是北京外城的一段城墙，大概因为年代久远，加之战火催损，
看起来略现破败；但城墙十分宽阔，足可容四五匹马并排而行，不时
有一队队官兵巡逻而过，平添了几分紧张气氛。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhaoyangmenlou",
  "north" : __DIR__"dongzhimenlou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/beijing/west/chaguan.c

inherit ROOM;

void create()
{
	set("short", "高升茶馆");
	set("long", @LONG
这是一间普通的京城茶馆，经常茶客满坐，热闹非凡，茶博士
在茶客中穿来穿去，不时和熟客闲聊几句。茶馆正中有一座台子，
一个说书先生正起劲的说着一部《大明英烈传》。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"tianqiao3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

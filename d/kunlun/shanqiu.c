//Cracked by Roath
// Room: /d/mingjiao/shanqiu.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "小山丘");
	set("long", @LONG
光秃秃的山丘，连飞鸟也难见一只。时有厚土旗下弟子路过。由于土
质坚硬，倒没被雨水冲去多少。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	"southeast" : __DIR__"shandao42",
	"northdown" : __DIR__"txiaochang",
	"southwest" : __DIR__"didao/didao",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

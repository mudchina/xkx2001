//Cracked by Roath
// Room: /d/beijing/east/guandedian.c

inherit ROOM;

void create()
{
	set("short", "观德殿");
	set("long", @LONG
这里是皇帝、皇后死后暂时停放棺材处。四周点着长明灯。
冷风吹来，烛光摇动，四周黑影憧憧，你的背心上不禁起了
一丝凉意。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shouhuangdian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

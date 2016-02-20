//Cracked by Roath
// Room: /d/mingjiao/jxiaochang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "锐金旗校场");
	set("long", @LONG
此处乃是明教锐金旗校场。场地甚大，四角上各竖一面白色镶边大旗，
迎风忽忽作响。东西两侧摆着几个木架，除十八般兵器之外，更有些长箭，
标枪和短斧之类，供锐金旗弟子们操练阵法之用。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"tianmoling",
  "east" : __DIR__"shanlu28",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/mingjiao/txiaochang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "厚土旗校场");
	set("long", @LONG
此处乃是明教厚土旗校场。场地甚大，四角上各竖一面黄色镶边大旗，
迎风忽忽作响。东西两侧摆着几个木架，除十八般兵器之外，更有些铁铲，
铁锹之类，供厚土旗弟子们操练阵法之用。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"shanqiu",
  "enter" : __DIR__"tdating",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

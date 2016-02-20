//Cracked by Roath
// Room: /d/mingjiao/xiaochang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "校场");
	set("long", @LONG
此处乃是明教洪水旗校场。场地甚大，四角上各竖一面镶边大旗，迎
风忽忽作响。东西两侧摆着几个木架，除十八般兵器之外，更有些喷筒，
供洪水旗弟子们操练阵法之用。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"hst",
  "enter" : __DIR__"hdating",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/mingjiao/houtang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "后堂");
	set("long", @LONG
粉白的四壁上悬挂着几幅泼墨山水。西墙下一红木帐床。床与南窗之
间的角落里置有一盆悬崖菊，虽不到花季，但在这山阴处，也已结满了骨
蕾，倍着几朵耐不住寂寞的花瓣，喧哗着秋的来临。房中间摆放着红木八
仙桌，不知为谁准备得一桌酒菜，还散着热气。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"zoulang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

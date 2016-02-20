//Cracked by Roath
// Room: /d/beijing/west/baozhu.c

inherit ROOM;

void create()
{
	set("short", "宝珠胡同");
	set("long", @LONG
这是一条北京城里十分寻常的僻静小胡同，路边种着几棵柳树
行人也不太多，地上看起来总是灰扑扑的。西边是一家小酒店，东
面则是一家药店，招牌上写着「回春堂」三个大字。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xizhidajie",
  "west" : __DIR__"jiudian",
  "south" : __DIR__"fuchengmenjie2",
  "east" : __DIR__"huichuntang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/xiangyang/kedian3.c

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这是一间客房，摆设甚是简单，墙边摆了一张床铺。窗户似乎
有些不牢靠，风声一起，便嘎嘎作响。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"kedian2",
]));

	setup();
	replace_program(ROOM);
}

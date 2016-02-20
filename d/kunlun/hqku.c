//Cracked by Roath
// Room: /d/mingjiao/hqku.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "火器库");
	set("long", @LONG
此处十分昏暗，但异常干燥。再往里走，隐约可见后面整齐的罗放着
一些木桶，鼻中亦闻到一股硝磺的臭气。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"szchang",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

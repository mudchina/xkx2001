//Cracked by Roath
// Room: /d/beijing/east/guozidamen.c

inherit ROOM;

void create()
{
	set("short", "国子监");
	set("long", @LONG
国子监是太学生起居、学习的地方，为历朝历代的最高学
府。国子监中讲习、教师均是饱学鸿儒之士，翰林院的翰林、
学士也经常来此讲学。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"guoziqianyuan",
  "south" : __DIR__"guozijianjie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

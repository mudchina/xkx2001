//Cracked by Roath
//GU MU FROM SANTA
//fenglin2.C

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
玉蜂越来越密，有些甚至绕着你的头盘旋起来，不过并未展开攻
击。看来没有主人的命令，它们是不会轻易攻击人的。前方隐约可见
一座巨大的坟墓，其间隐约有炊烟升起。你大吃一惊，那坟墓难道是
住活人的!?

LONG
	);

	set("exits", ([
		"south" : __DIR__"shidao",
		"north" : __DIR__"fenglin1",
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}







//Cracked by Roath
// Room: /d/dali/wangfu11.c

inherit ROOM;

void create()
{
	set("short", "厢房");
	set("long", @LONG
只见这间房四面皆是雕空玲珑木板，或「流云百蝠」，或「岁寒三友」，或
山水人物，或翎毛花卉，或集锦，或博古，或万万福寿，各种花样，皆名手雕镂，
五彩销金嵌宝的。一隔一隔，或有贮书处，或设鼎处，或安置笔砚处，供花设瓶
安放盆景处，其格各式各样，或天圆地方，或葵花蕉叶，或连环半壁，真是花团
锦簇，剔透玲珑。倏尔五色纱糊就，竟系小窗；倏尔彩绫轻覆，竟系幽户。且满
墙皆系古玩之形抠成的槽子，诸如琴、剑、悬瓶桌屏之类，虽悬于壁，却都是与
壁相平的。
LONG);
	set("objects", ([
		"/kungfu/class/dali/zhudanchen" : 1,
		"/kungfu/class/dali/weishizhang" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"wangfu9",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

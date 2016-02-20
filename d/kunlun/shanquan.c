//Cracked by Roath
// Room: /d/mingjiao/shanquan.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "山泉");
	set("long", @LONG
一串串珍珠像醉了似的，跌跌倒倒的从那看不到的地缝中不情愿地挤
了出来，转眼又消逝在水面。周围的青松绿柳，嫩草娇花仿佛吸呐了它们
一般，绿的更绿，红的更红，将这泉口似孩子一样，抱得更紧，夸到更秀。
偶时有一二青丽少女，说说笑笑的擦身而过，回眸一笑又溶入这缤纷的世
界。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"bshantan",
		"northeast" : __DIR__"shanjiao1",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}

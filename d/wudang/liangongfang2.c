//Cracked by Roath
// liangongfang2.c 练功房
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "练功房" );
	set("long", @LONG
这里是武当弟子的练功房。房内纸窗虚掩，窗外的阳光投射进来，只见
并无一桌一椅，地上铺着草垫和蒲团。几个武当弟子正盘膝坐在蒲团上观看
两个武当弟子以武当的入门拳法相互切磋技艺。有弟子见你进来，朝你点头
微笑，却并不做声。
LONG
	);
	set("exits", ([
		"north" : __DIR__"xilang2",
		]));
	set("objects", ([
		"kungfu/class/wudang/yu.c" : 1,
		]));
		
	setup();
	replace_program(ROOM);
}


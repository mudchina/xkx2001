//Cracked by Roath
// toutian.c 头天门 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "头天门");
	set("long", @LONG
只见有石梯无数通往山巅，一座石坊上写着“头天门”三个大字，这是攀
登武当绝顶天柱峰的起点。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"huixian",
                "southup" : __DIR__"ertian",
	]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}


//Cracked by Roath
// Ryu, 5/10/97

inherit ROOM;

void create()
{
	set("short", "二台");
	set("long", @LONG
四季的景色，都在这一山之中。山顶上，白雪皑皑，尚在严冬；
山腰里，苍松翠，秋色浓重；山坡上，山花烂漫，如值仲夏；而从那
雪峰直垂下来的溪涧里，冰雪消融，春意盎然。二台以北，有一石洞，
人称仙人洞。
LONG
	);
	set("exits", ([
                "west" : __DIR__"guozi",
                "southdown" : __DIR__"gudao3",
		"north" : __DIR__"xrdong",
        ]));
	set("cost", 2);
	set("outdoors", "tianshan");

	setup();
	replace_program(ROOM);
}

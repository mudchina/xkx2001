//Cracked by Roath
//Kane

inherit FERRY;

void create()
{
	set("short", "码头");
	set("long", @LONG
这是一个在江南水乡极常见的码头，由粗糙的大青条石搭成。
北面似乎有一个极大的庄院。
LONG
	);
	 set("exits", ([
		"north" : __DIR__"damen",
		"east" : __DIR__"matou2",
	]));
	set("cost", 2);
	set("outdoors", "taihu");

	set("name", "湖");
	set("boat", __DIR__"duchuan");
	set("opposite", __DIR__"taihu");

	setup();
}

//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "端门 ");
	set("long",  @LONG
这是一个极大的广场，侍卫们经常在此操练。广场边上是紫禁城
的护城河。向北走便是紫禁城的南大门午门。
LONG
	);


	set("exits", ([
		"north" : __DIR__"wumen",
		"south" : __DIR__"tiananmen",
	]));
	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}

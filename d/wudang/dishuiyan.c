//Cracked by Roath
// dishuiyan.c 滴水檐
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "滴水檐");
	set("long", @LONG
这里是武当大厅前的滴水檐。每逢雨季，雨水打在这里的屋檐上，倾听
时犹如敲打琴乐之声，而滴水终日不断。滴水檐便是因此的名。再往北便可
到武当广场。
LONG
	);
	set("exits", ([
		"south" : __DIR__"dating",
		"north" : __DIR__"guangchang",
	]));
	
	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /city/minwu1.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "小庙");
	set("long", @LONG
小庙里到处都结了蜘蛛网，案台上落了一层厚厚的灰尘，台上供的观世音菩
萨像也已经面目全非了，看来这里好久没人来了。只是东面门口的一张小桌显得
十分的新，而且上面还有一桌没有吃完的酒菜，不知是谁留下的。南面有一扇贴
了封条的门，门上刻了一行小字(xiaozi)。东边则是个很大的院子。
LONG
	);

	set("exits", ([
		"east" : __DIR__"dayuan",
		"north" : __DIR__"minwu2",
		"northwest" : __DIR__"xiaotulu",
		
	]));

	set("objects", ([
	]));

	set("cost", 0);
	setup();
	replace_program(ROOM);
}


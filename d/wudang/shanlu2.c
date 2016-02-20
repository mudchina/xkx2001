//Cracked by Roath
// shanlu1.c 武当山路
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
	你走在登山的路径上，路的左右各有一条大铁链，象两条长蛇向山上山
下蜿蜒爬去。满眼是乔木夹道，如行于绿幕中。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"shanlu1",
		"southup" : __DIR__"shanlu3",
	]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}


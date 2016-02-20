//Cracked by Roath
// shanlu4.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "山路");
	set("long", @LONG
这里道路骤陡，一线天光从石壁之间照射下来，阴气森森，寒意逼人。
LONG
	);

	set("exits", ([
		"east" : __DIR__"shanlu3",
		"west" : __DIR__"gucheng1",
	]));
	set("outdoors","xingxiu");
	set("cost", 6);
	setup();
	replace_program(ROOM);
}


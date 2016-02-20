//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "造办处");
	set("long",  @LONG
    无资料.
LONG
	);

	set("exits", ([
	           "south" : __DIR__"gzxd1",
                      "west" : __DIR__"cininghuayuan",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}

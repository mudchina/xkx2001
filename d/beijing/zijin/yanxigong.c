//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "延禧宫");
	set("long",  @LONG
    东六宫之一,这是明清两代后妃们居住的地方.
LONG
	);

	set("exits", ([
        "west" : __DIR__"gzxd8",
	]));

	set("outdoors","beijing");
	setup();
	replace_program(ROOM);
}

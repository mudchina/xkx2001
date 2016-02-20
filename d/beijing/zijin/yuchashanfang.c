//Cracked by Roath
inherit ROOM;

void create()
{
    set("short", "御茶膳房");
	set("long",  @LONG
    这是外膳房.
LONG
	);

	set("exits", ([
        "west" : __DIR__"jianting",
	]));

	setup();
	replace_program(ROOM);
}

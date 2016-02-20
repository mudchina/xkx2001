//Cracked by Roath
// Room: /d/xiangyang/bydamen.c

inherit ROOM;

void create()
{
	set("short", "兵营大门");
	set("long", @LONG
你正站在兵营的门口，对面一排排的营房，可以看到穿着制服的官兵们正在
加紧操练着，从面不时传来呐喊声。老百姓们是不允许在此观看的，不想惹上
麻烦最好赶快走开。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_sleep_room", 1);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : -1 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"xijie1",
  "west" : __DIR__"bingy2",
  "south" : __DIR__"bingying",
]));

	setup();
	replace_program(ROOM);
}

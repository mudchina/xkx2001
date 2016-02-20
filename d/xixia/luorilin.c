//Cracked by Roath
// Room: /d/xixia/luorilin.c

inherit ROOM;

void create()
{
	set("short", "落日林");
	set("long", @LONG
落日林位于灵州的东北，在西夏王陵和灵州的中间，延绵百里，多
长的是红松。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dalu",
  "southwest" : __DIR__"dongmen",
]));
	set("cost", 2);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}

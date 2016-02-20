//Cracked by Roath
// Room: /d/xixia/hut.c

inherit ROOM;

void create()
{
	set("short", "竹林小屋");
	set("long", @LONG
你面前是一间小屋。小屋亦是紫竹所制，一扇小门紧紧扣着，因为
竹屋与紫竹林浑然一色，不仔细看你很难发觉。竹荫婆娑，竹叶沙沙，
你的心一紧，一股凉意直透脊背。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"zhulin",
  "enter" : __DIR__"hut2",
]));
	set("no_clean_up", 0);
	set("outdoors", "xixia");

	setup();
	replace_program(ROOM);
}

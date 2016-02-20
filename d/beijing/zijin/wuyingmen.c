//Cracked by Roath
// Room: /d/beijing/zijincheng/wuyingmen.c

inherit ROOM;

void create()
{
	set("short", "武英门");
	set("long", @LONG
从此地向北就是御林军的中军大帐，向南是御林军的扎营之处，
向西是西华门，向东是熙和门。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"denglongku",
  "north" : __DIR__"guang3",
  "west" : __DIR__"xihuamen",
  "east" : __DIR__"xihemen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

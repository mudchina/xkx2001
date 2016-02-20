//Cracked by Roath
// Room: /d/xiangyang/djtai.c

inherit ROOM;

void create()
{
	set("short", "点将台");
	set("long", @LONG
此台正临西门，中央乃点将台，左名苍龙之台，右名白虎之台。三台森耸，
可高三丈。点将台底层为巨石砌成，顶部是一平台。一至战时，主帅披挂上台，
高而坐，唤集诸将听令。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");
        set("coordinates", ([ "x" : -3, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"nanjie2",
  "north" : __DIR__"ceting",
  "northwest" : __DIR__"xiaoshi",
  "west" : __DIR__"ximen",
]));

	setup();
	replace_program(ROOM);
}

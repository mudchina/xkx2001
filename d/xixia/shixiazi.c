//Cracked by Roath
// Room: /d/xixia/shixiazi.c

inherit ROOM;

void create()
{
	set("short", "石峡子");
	set("long", @LONG
石峡子是以前的黄河故道，现在遍地是大大小小的鹅卵石，两边是数丈高的
高坡，千沟万壑，向你诉说着世事的沧桑。要是运气好的话你可以在这里拣到非
常漂亮、非常珍贵的雨花石。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"bcwan",
  "southwest" : __DIR__"tumenzi",
]));
	set("objects", ([
		"/clone/weapon/stone" : 2,
	]));
	setup();
	replace_program(ROOM);
}

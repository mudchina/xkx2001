//Cracked by Roath
// Room: /d/beijing/zijincheng/baohedian.c

inherit ROOM;

void create()
{
	set("short", "保和殿");
	set("long", @LONG
又称谨身殿，建极殿。皇帝立后、立太子时，在此着装，再到太
和殿受贺。每当除夕，这里是宴请王公大臣的地方。著名的殿试亦在
此举行。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhonghedian",
  "north" : __DIR__"xiaohuayuan",
]));

	setup();
	replace_program(ROOM);
}

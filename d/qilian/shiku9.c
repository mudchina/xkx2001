//Cracked by Roath
inherit ROOM;

void create()
{
  set ("short", "石窟");
  set ("long", @LONG
这里是一处宋初所凿的洞窟，内中壁画是用典形中国写生手笔所绘的
道教法绘天官像，用色清淡、着笔传神，人物造形丰满。侧壁上则是一幅
彩色凹凸套笔的道教法绘天乐女像。
LONG);
	set("exits", ([
                "east" : __DIR__"dtongdao4",
]));
	set("objects", ([
                "/d/wudang/obj/daodejing-i" : 1,
                "/d/wudang/obj/daodejing-ii" : 1,
]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}


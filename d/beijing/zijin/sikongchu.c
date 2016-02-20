//Cracked by Roath
// Room: /d/beijing/zijincheng/sikongchu.c

inherit ROOM;

void create()
{
	set("short", "祀孔处");
	set("long", @LONG
          一进此屋，只见香烟镣绕，正对着门影影约约
          有一座神象，头顶儒士巾，神采飘逸，正是大
          圣人孔子。此处为皇帝向至圣先师拜祀之地，
          也是天下读书人的圣地。(猜想)
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"shangshufang",
  "north" : __DIR__"yuyaofang",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

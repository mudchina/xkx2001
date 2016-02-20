//Cracked by Roath
// Room: /d/beijing/zijincheng/yuyaofang.c

inherit ROOM;

void create()
{
	set("short", "御药房");
	set("long", @LONG
这是禁城中的御药房，存放了大量珍贵药材．满屋药香扑鼻而来，几个
药罐正嘟嘟冒泡，旁边几个小太监在轻轻扇着金香炉。几位太医正在争论着
什么，不知道是否是皇上龙体欠安。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"sikongchu",
  "north" : __DIR__"rijingmen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/beijing/zijincheng/yuhuayuan.c

inherit ROOM;

void create()
{
	set("short", "御花园");
	set("long", @LONG
这个花园面积12000多平方米，但由于园艺大师们的精心构
思，安排得主次分明。特色是以参天古柏，嶙峋山石，红墙黄瓦
为主调，使得整个花园景色庄严而美丽。在建筑布局上，即是一
处庭院设置，又不失其宫廷的气魄。园中的建筑很多是对称的，
有的造型、装饰上加些变化。有的虽然造型相同，但由于中间有
钦安殿院落及树木竹林相隔，不能同时入眼，所以并不觉得有重
复感。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "north" : __DIR__"shunzhenmen",
  "south" : __DIR__"kunningmen",
  "up" : __DIR__"yujingting",
  "east" : __DIR__"jiangxue",
  "enter" : __DIR__"qinandian",
 ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

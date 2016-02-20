//Cracked by Roath
inherit ROOM;

void create()
{
	set("short", "主敬殿");
	set("long",  @LONG
这是御前侍卫总管休息练功的地方。在墙脚是一桶铁沙子，另一
侧竖着一个铁柱子，不知是干什麽用的。靠里面有一把椅子，椅子旁边
的桌子上放着几只细瓷茶杯和一把紫砂的茶壶。
LONG
	);

	set("exits", ([
		"north" : __DIR__"wenyuange",
		"south" : __DIR__"wenhuadian",
	]));

	setup();
	replace_program(ROOM);
}
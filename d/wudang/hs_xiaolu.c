//Cracked by Roath
// hs_xiaolu.c 后山小路
// xQin 11/00

inherit ROOM;
#include <room.h>
void create()
{
	set("short","后山小路");
	set("long", @LONG
走过竹林这里已经是后山，小路两侧山峰峭峙。远处看去有几株悬松，
根植峭壁，身悬空中，虬枝伸展，刚毅挺拔，启人联想。正符诗中所云：孤
云不锁玄关梦，卧看松枝扫月明。
LONG
	);
	set("outdoors", "wudang");
	set("exits", ([
		"north" : __DIR__"zhulin",
		"south" : __DIR__"xiaoyuan",
		]));
		
	create_door("south", "竹门", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
	
}
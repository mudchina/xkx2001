//Cracked by Roath

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "忘忧谷");
	set("long", @LONG
这里乃是大轮寺外一处僻静所在，四下绝无人迹。前前後後，大大
小小几百座佛塔，被白得耀眼的雪被披盖着。银白色的山野、雪地里闪
耀着红色和蓝色的光带，五彩缤纷，迷宫一样的琼楼仙阁在你眼前出现。
西边一条小径不知通往何处。
LONG
	);

	set("exits", ([
		"southup" : __DIR__"shangu1",
		"west" : __DIR__"luyeyuan",
	]));
	set("objects", ([
		__DIR__"npc/zhuoma" : 1,
		__DIR__"npc/yangzong" : 1,
	]));

	setup();
	set("cost", 5);
	set("outdoors","qilian-shan");
}


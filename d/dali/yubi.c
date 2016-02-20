//Cracked by Kafei
// Room: /dali/yubi.c
// AceP

inherit ROOM;

void create()
{
	set("short", "无量玉壁");
	set("long", @LONG
这里是山路的尽头。前面山崖下就是剑湖，对面的山峰叫白龙峰，峰顶有块很
大的镜面石(stone)，站在这边都能看得很清楚。西北角上有一条大瀑布从山崖上
奔流下来，注入湖中。
LONG );

	set("item_desc", ([
		"stone" : "这块石头平滑如镜，能照见毛发，有人说是块美玉，其实呢，只是一块又白又光的石头罢了。\n",
	]));

	set("exits", ([
		"southdown" : __DIR__"houshan",
	]));

	set("cost", 1);
        set("outdoors", "dali");
	setup();
}

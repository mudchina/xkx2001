//Cracked by Roath
// Room: /d/xixia/hut2.c

inherit ROOM;

void create()
{
	set("short", "小屋");
	set("long", @LONG
这是一间不大的竹屋，顶上还有好几个大大小小的破洞，借着透
下的些许光亮。你发现里面空空荡荡，徒有四壁，屋顶和角落里挂着
些积满尘土的蜘蛛网。地板也是紫竹制成，同样积满了灰尘。西北角
显得特别暗。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"hut",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

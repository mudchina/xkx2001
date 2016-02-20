//Cracked by Roath
// Room: /d/xixia/hougong.c

inherit ROOM;

void create()
{
	set("short", "后宫");
	set("long", @LONG
这里是皇后的寝宫，富丽堂皇，周围悬着粉红色的绸纱。一走进来
你的鼻端就飘来一缕似兰似麝的幽香，不由你觉得有点心猿意马起来。
西边是宫女值夜和休息的偏殿。通过偏殿出去就是御花园。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"piandian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

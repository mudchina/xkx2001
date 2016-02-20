//Cracked by Roath
// hsstreet3
// qfy Oct 15, 97

inherit ROOM;

void create()
{
	set("short", "村外土路");
	set("long", @LONG
这里是华山脚下的土路，游客们或骑马，或坐轿，兴致勃勃地前去游
山玩水。五岳剑派之一的华山派便在华山玉女峰之上，故此经常可以看见
身带佩剑的华山弟子。偶尔也有行色匆匆的其他江湖人士，或神采飞扬，
或垂头丧气。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"hsstreet3",
		"east" : __DIR__"path1",
	]));
	
	set("no_clean_up", 0);
	set("outdoors", "huashan" );

	set("cost", 2);
	setup();
	replace_program(ROOM);
}
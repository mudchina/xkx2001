//Cracked by Roath
// Room: /d/beijing/west/xiaohutong2.c

inherit ROOM;

void create()
{
	set("short", "小胡同");
	set("long", @LONG
这是一条北京城里极常见的小胡同，因为地处偏僻，所以行人
不多，地上看起来也不太干净，一有刮风就尘土飞扬。老北京口中
的“晴天是香炉，雨天是墨盒”，就是指这种小胡同。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"nantianmen",
  "southwest" : __DIR__"shizilukou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/xiangyang/chexiang.c

inherit ROOM;

void create()
{
	set("short", "车巷子");
	set("long", @LONG
这条遍僻窄抑的小巷充斥着狗肉与酒水的臭味，令闻者掩鼻而退，不愿接
近这。几个叫化子坐在地上抓虱子晒太阳。东面墙角似乎有个狗洞(dong)。
LONG
	);
        set("coordinates", ([ "x" : 1, "y" : 5 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"beijie3",
]));
	set("no_clean_up", 0);
        set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}

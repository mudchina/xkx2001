//Cracked by Roath
// Room: /d/xiangyang/diluqiao.c

inherit ROOM;

void create()
{
	set("short", "的卢桥");
	set("long", @LONG
这座小木桥是由附近乡人依着汉时刘备所乘的坐骑跃溪而过，故命名。小桥
摇摇晃晃，看似危险，其实甚是稳固。周围青山绿水，树木葱茏，桥下檀溪流水
淙淙，风景秀丽。
LONG
	);
        set("coordinates", ([ "x" : -11, "y" : 0 ]) );
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"tanxi",
  "westdown" : __DIR__"wotieniu",
]));

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
// Room: /d/xiangyang/wotieniu.c

inherit ROOM;

void create()
{
	set("short", "卧铁牛");
	set("long", @LONG
从前古人在这铸铁为牛，投入檀溪中，以镇水患。那檀溪源自襄阳远郊扁
山南麓，流经城西，在城南岘山东簏观音阁注入汉水。扁山紫檀茂密，溪流其间
，故名。东面有一座小木桥，可从那渡过檀溪。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -12, "y" : 0 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"shanlu",
  "eastup" : __DIR__"diluqiao",
]));

	setup();
	replace_program(ROOM);
}

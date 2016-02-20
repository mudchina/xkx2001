//Cracked by Roath
// Room: /d/xiangyang/shanlu.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
见路上一个牧童跨於牛背上，口吹短笛而来。附近稀稀落落的分布着几十
间土坯泥房，遥望山畔数人，荷锄耕於田间作歌。周围山青水秀，树木苍翠，风
景秀丽。
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -13, "y" : -1 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"qilidian",
  "northeast" : __DIR__"wotieniu",
]));

	setup();
	replace_program(ROOM);
}

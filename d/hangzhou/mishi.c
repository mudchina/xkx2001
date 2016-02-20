//Cracked by Roath
//Kane
//maco moveed to hangzhou 1999/12/28 

inherit ROOM;

void create()
{
	set("short", "秘室");
	set("long", @LONG
这是酒馆碗橱之後的一座秘室，只有五六尺见方，里面放了
一座铁床，一只大铁箱，但却丝毫不现得局促，空气也十分清新，
闻不到一点霉味。
LONG
	);

        set("no_fight", "1");
	set("resource/water", 1);
	set("exits", ([
                "out" : __DIR__"jiudian",
        ]));

	set("cost", 2);
/*	
	set("item_desc", ([
	"skulls" : "这是一堆共九个人头骨，分为上中下三层，下层五个，中层三个，上层一个\n",
	]));
*/

	set("objects", ([
		"/kungfu/class/taohua/lingfeng" : 1,
	]));

	setup();
	replace_program(ROOM);
}

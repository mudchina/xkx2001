//Cracked by Roath
// Room: /d/beijing/east/wushengbiaoju.c

inherit ROOM;

void create()
{
	set("short", "武胜镖局");
	set("long", @LONG
这里是京城最大的镖局--武胜镖局，自在京城开张以来已历
三代，算是京城的老招牌、老字号，一向信誉卓著，从未失镖。
现任总镖头是“金枪王”王武通。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"west" : __DIR__"chongwendajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "黄药师居处");
	set("long", @LONG
这是桃花岛主黄药师的卧室，一张竹榻靠在屋东北角，窗前一几，几上一张瑶
琴，一本琴谱。瑶琴颜色黯旧，琴尾已完全烧焦，琴谱里夹着一张纸，可以看见一
些字迹。向窗外望去，隐隐可以看见一座坟茔。
LONG
	);
	set("objects", ([
		__DIR__"obj/paper2" : 1,
		"/kungfu/class/taohua/huang" : 1,
	]));
	 set("exits", ([
                "east" : __DIR__"changlang2",
        ]));
	setup();
	replace_program(ROOM);
}

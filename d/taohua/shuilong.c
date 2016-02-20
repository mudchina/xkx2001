//Cracked by Roath
//kane

inherit ROOM;

void create()
{
	set("short", "水龙轩");
	set("long", @LONG
这里是桃花岛主黄药师日常起居活动的地方，轩内陈设十分简单。四壁挂着一些
晋人字画，中间一副墨迹淋漓的条幅(tiaofu)，正是黄药师时常吟颂的《水龙吟》。
门楣上嵌着一个黑黝黝的铁八卦(bagua)，桌上零散放着几只茶杯，一部翻开的阮籍
诗钞，一张当书签的字纸，除此之外再无长物。西面和北面各有一道长廊。
LONG
	);
	set("cost", 2);
	set("item_desc", ([
        "tiaofu" : "放船千里凌波去，略为吴山留顾。云屯水府，涛随神女，九江东注。北客翩然，壮心偏\n"
		   "感，年华将暮。念伊蒿旧隐，巢由故友，南柯梦，遽如许。回首妖氛未扫，问人间何处？\n"
		   "奇谋复国，可怜无用，尘昏白扇。铁锁横江，锦帆冲浪，孙郎良苦。但愁桂棹，悲吟梁\n"
		   "父，泪流如雨 。。\n",
	"bagua" : "这个铁八卦卦象排得零零落落，歪歪斜斜，既非伏羲先天八卦，也非文王\n"
		  "后天八卦，不知道派什么用场。\n",
        ]));
	 
	set("exits", ([
                "west" : __DIR__"changlang2",
                "out" : __DIR__"jingshe",
                "north" : __DIR__"changlang",
        ]));
	         set("objects", ([
                __DIR__"obj/paper1" : 1,
	]));
	
	setup();
	replace_program(ROOM);
}

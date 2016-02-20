//Cracked by Roath
// Room: /d/beijing/caishikou.c

inherit ROOM;

void fix_exits_for_night(int is_night);

void create()
{
	set("short", "菜市口");
	set("long", @LONG
这里是朝廷处斩犯人示众的场所。路中央有一个断头台 (tai)，应该就是行
刑用的。不远处天桥的热闹还能隐约听到，与这里肃杀的气氛构成了鲜明的对比。
LONG
	);
	fix_exits_for_night(0);
	set("no_clean_up", 0);

	set("item_desc", ([
	"tai" : "一个血迹斑斑的木台子。\n",
]));
	set("outdoors", "beijing");
	set("cost", 2);
	setup();
}


void fix_exits_for_night(int is_night)
{
    object me = this_object();
    if (is_night) {
	me->set("exits", ([ /* sizeof() == 3 */
	  "east"  : __DIR__"tianqiao",
	  "north" : __DIR__"xuanwudajie",
          "south" : __DIR__"youandajie",
	]));
    }else{
	me->set("exits", ([ /* sizeof() == 3 */
	  "east"  : __DIR__"tianqiao",
	  "north" : __DIR__"xuanwudajie",
	  "west"  : __DIR__"guanganmen",
	  "south" : __DIR__"youandajie",
	]));
    }
}


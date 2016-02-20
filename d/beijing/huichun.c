//Cracked by Roath
// Room:回春堂 
// Ssy 

inherit ROOM;

void create()
{
        set("short", "回春堂");
        set("long", @LONG
这是京城老字号药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几百
个小抽屉里散发出来的。一位大夫坐在八仙桌旁，据说他就是京城里有名的大夫
姚春，除了御医便数他了。一名小伙计站在柜台后招呼着顾客。柜台上贴着一张
广告(guanggao)。
LONG
        );
        set("item_desc", ([
			   "guanggao" : "本店出售药品，并诊治伤病人。\n",
        ]));

        set("objects", ([
			 __DIR__"npc/yaochun" : 1,
			 __DIR__"npc/hcthuoji" : 1,
        ]));

        set("exits", ([
		       "east" : __DIR__"fuchengdajie_s",
        ]));

        set("cost", 0);
        set("day_shop", 1);
        setup();
        replace_program(ROOM);
}

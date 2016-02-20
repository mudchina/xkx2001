//Cracked by Roath
// Mantian remove Ssy north room path since mirror and @us ppl can't access wiz tree 05/12/2001
// Mantian add up path to 麻将 room 05/12/2001


inherit ROOM;

void create()
{
        set("short", "小宝斋");
        set("long", @LONG
你一走进这里，便被这里富丽堂皇的装饰吓了一大跳。原来这里就是鹿
鼎公韦公爷新开的小宝斋，专门修复各种衣物防具，因为韦公爷交情阔，手
笔大，而且传下话来这个地方是结交江湖朋友的，所以无论什麽贵重装备都
能很快修好，而且收费不高。楼上是新近开张的“韦氏公司”。
LONG
        );
//        set("outdoors", "city");

        set("exits", ([
                "south" : __DIR__"dongnanjie",
//				"north" : "/u/ssy/paimai",
//				"west" : __DIR__"nandajie2",
				"up" : __DIR__"mjroom",
        ]));

        set("objects", ([
                // __DIR__"npc/shuanger" : 1,
                // __DIR__"npc/xiaoping" : 1,
                // "/kungfu/class/shenlong/su" : 1,
        ]));

        set("cost", 0);
        setup();
}

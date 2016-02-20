//Cracked by Roath
// Room: /d/village/smithy2.c

inherit ROOM;

void create()
{
        set("short", "小房间");
        set("long", @LONG
这是铁匠的住宅，屋子里十分简单，靠墙有一张木床，墙角摆着个小桌子，桌
上胡乱的摆着几个酒杯、茶碗，桌上靠墙放着一把长剑(sword)。西边有个小门，门
上挂著个破布帘，出去就是铁匠的铺子了。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" :"/d/village/smithy1",
]));
        set("item_desc", ([
        "sword" : 
"这是一把看起来挺普通的剑，连剑鞘都没有，大概新出炉不久。\n"
"你一撩布帘，正要出去，在外间炉火映照下，一眼瞥见剑身上仿\n"
"佛有些花纹。你伸手想把剑拿起来看个究竟，可一恍惚间，居然\n"
"抓了个空。你不信邪的再要拿，又是抓了个空。你注意到桌上酒\n"
"杯、茶碗的位置似乎有些怪。\n",
])  ) ;
        set("no_clean_up", 0);

        set("cost", 0);
        setup();
        replace_program(ROOM);
}



//Cracked by Roath
// xiakedao/xkx14.c
// modifiedy by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 4;

void create()
{
        set("short", "石室");
        set("long", @LONG
这里光线黯淡，水珠时而从头顶的石壁上滴下，略略有些霉气。
把石室照得明亮。壁上刻得有图有字。右侧一位老乞丐正在对着独自
石壁(wall)练拳，拳劲十足。
LONG );

      set("exits", ([
		"north" : __DIR__"xiakexing4",
      ]));
	set("item_desc",([
	    "wall" : "
这面墙的字迹却与众不同，几个大字「五狱倒为轻」刻在正中。在大
字的比划中间，是密密的一段段小注，深浅不一。远远看去，却又颇
似图画。识得一行注是：象曰：山下有泽，损，君子以惩忿窒欲。\n",
	]));
	set("objects",([
            __DIR__+"npc/hong.c" : 1,
            ]));

	set("indoors", "xiakedao" );
	set("cost", 0);
	setup();
}
void init()
{
        ::init();
	add_action("do_study", "study");
}

#include "/d/xiakedao/xkx.h"

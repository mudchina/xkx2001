//Cracked by Roath
// xiakedao/xkx5.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 3;

void create()
{
        set("short", "石室");
        set("long", @LONG
一位仙风道骨的老者正和一位高大的西域人切磋武功，两人均是
虚持空剑，招式忽快忽慢，阵阵劲风将室内的火把激荡得明暗不定，
石壁(wall)上的图案亦是班驳陆离。
LONG );

      set("exits", ([
		"south" : __DIR__"xiakexing2",
      ]));
	set("item_desc",([
	    "wall" : "
墙的正上方刻着「十步杀一人」几个大字。其下的图案却是一副工笔
山水。绘的是山边密林，那树木的枝条长短不一，前后纵横，倒也笔
力雄健，栩栩如生。图旁有无数小注。\n"
	]));

	set("indoors", "xiakedao" );
	set("cost", 0);
      set("objects",([
            __DIR__+"npc/ouyang.c" : 1,
            __DIR__+"npc/ding.c" : 1,
          ]));
	setup();
}
void init()
{
        ::init();
	add_action("do_study", "study");
}
#include "/d/xiakedao/xkx.h"

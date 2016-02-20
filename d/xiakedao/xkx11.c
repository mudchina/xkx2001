//Cracked by Roath
// xiakedao/xkx11.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";

int flag = 5;

void create()
{
        set("short", "石室");
        set("long", @LONG
进门便觉得室中潮气极重，呼吸不畅，想来是深入山腹之故。数
人也是或坐或立，默不做声地各自研习武功。火把却不知为何少了几
支，石壁(wall)上投下了大片阴影。
LONG );

      set("exits", ([
		"west" : __DIR__"xiakexing3",
      ]));
	set("item_desc",([
	    "wall" : "
墙的正上方刻着「将炙啖朱亥」几个大字。字的下方刻的是信陵君拜
访朱亥的故事。传说那朱亥杀猪为生，画中之人袒胸持刀，满脸剽悍
之色。魏公子无忌在一旁站立，神色恭谨。\n",
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

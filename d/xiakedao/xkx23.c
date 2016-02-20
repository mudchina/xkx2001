//Cracked by Roath
// xiakedao/xkx23.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 13;

void create()
{
        set("short", "石室");
        set("long", @LONG
石室中有三个蒲团，仅正中蒲团坐有一人，正与一个面色焦黄的
女子对掌。那女子似是行有余力，尚有闲暇不时瞟一眼石壁(wall)，
空着的左手也在虚拟作势。一个书生手持笔墨，在地下随写随抹，摇
头晃脑地很是得意。
LONG );

      set("exits", ([
		"west" : __DIR__"xiakexing6",
      ]));
	set("item_desc",([
	    "wall" : "
几个大字「谁能书阁下」在右侧直排。左边图上绘的是一名高瘦老者，
正自端坐抚琴。只见他左手捻弦，右手虚扬，面上的微笑也甚是优雅。
一行淡淡的注云：李侍郎致酒行：空将笺上两行书。又注：《道德经》
云：反者道之动，弱者道之用。\n",
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

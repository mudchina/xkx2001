//Cracked by Roath
// xiakedao/xkx.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 1;

void create()
{
        set("short", "石室");
        set("long", @LONG
这里火光昏暗，只见那龙岛主与木岛主盘膝坐在锦垫之上，面对
石壁(wall)，凝神苦思。此石室已是山腹最深处，却宽阔高大，足可
容下近百人。洞中火把亦是其他洞的二三倍之多。
LONG );

      set("exits", ([
		"east" : __DIR__"xiakexing6",
      ]));
	set("objects", ([ 
		__DIR__"npc/daozhu1" : 1, 
		__DIR__"npc/daozhu2" : 1, 
      ]));

	set("item_desc",([
	    "wall" : "
墙的正上方刻着「白首太玄经」几个大字。字的下方刻的是密密麻麻
的蝌蚪文，成千上万。文字排列甚不整齐，或横或竖，或直或斜。左
下的大片甚至混成一团难分次序，委实难以辨认。\n",
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

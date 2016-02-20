//Cracked by Roath
// xiakedao/xkx9.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 4;

void create()
{
        set("short", "石室");
        set("long", @LONG
这里是石洞深处，较为气闷。此石室内甚是安静，一名虬髯大汉
和一名道士相对而立，正在缓缓地推手。一人站在远处墙角，将墙上
的火把取下来擎在手中，紧盯着石壁(wall)，鼻子似乎已经贴了上去。
LONG );

      set("exits", ([
		"south" : __DIR__"xiakexing3",
      ]));
	set("item_desc",([
	    "wall" : "
墙的正上方刻着「闲过信陵饮」几个大字。字的下方刻的正是「侠客
行」诗中三人饮酒的故事。只见一人剑眉入鬓，高冠华服，却坐在下
首相陪，不问可知是信陵君；另一人干瘦白须，乃是侯嬴。第三人是
背影，肩宽膀阔。图画之侧小注无数。\n",
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

//Cracked by Roath
// xiakedao/xkx19.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 11;

void create()
{
        set("short", "石室");
        set("long", @LONG
这里极为低矮，身材稍高之人便要低头。室内仅余西北角一支火
把，其余的均已燃为灰烬。昏暗的光线中，仅有一人盘膝而坐，对照
石壁(wall)比划着。只见掌指交替，繁杂无比。
LONG );

      set("exits", ([
		"west" : __DIR__"xiakexing5",
      ]));
	set("item_desc",([
	    "wall" : "
墙的正上方刻着「千秋二壮士」几个大字。下方绘出侯嬴与朱亥二人
携手而行，正是古风“侠客行”原意。侧面一行小楷：子曰：知者乐
水，仁者乐山。知者动，仁者静。又注：庄子秋水篇：不知何时止而
不盈；尾闾泻之。\n",
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

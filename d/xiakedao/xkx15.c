//Cracked by Roath
// xiakedao/xkx15.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 8;

void create()
{
        set("short", "石室");
        set("long", @LONG
这里酒气浓重，地上抛弃了不少酒袋或葫芦。东侧两人说话已经
含糊不清，兀自向嘴里不停倒酒，踉跄地模仿石壁(wall)上的图案。
距二人丈许外一个女子掩鼻而立，面带厌恶之色。
LONG );

      set("exits", ([
		"west" : __DIR__"xiakexing4",
      ]));
	set("item_desc",([
	    "wall" : "
墙的正上方刻着「眼花耳热後」几个大字。下面刻的是鲁智深醉闹山
门的故事，画中的胖和尚大醉如泥，惟妙惟肖。空中又绘着无数落叶，
随风飞舞。\n",
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

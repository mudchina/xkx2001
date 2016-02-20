//Cracked by Roath
// xiakedao/xkx17.c
// modified by aln  5 / 98

inherit __DIR__"no_pk_room";
int flag = 9;

void create()
{
        set("short", "石室");
        set("long", @LONG
这里铿锵之声不绝，一个身材矮小的汉子手持黄金棍，与使蛾眉
刺的少妇双战一个瘦子。那瘦子在一片黄光中身形晃动，丝毫不落下
风。兵刃劲风激荡之下，火把也熄灭了两支。石壁(wall)上的图谱隐
约可见。
LONG );

      set("exits", ([
		"south" : __DIR__"xiakexing5",
      ]));
	set("item_desc",([
	    "wall" : "
墙的正上方刻着「救赵挥金槌」几个大字。下面的图画波澜壮阔，豪
气逼人。正是岳武穆大破金兵，八大锤闹朱仙镇。只见刀枪蔽日，血
肉横飞。旁边注释不多，均是笔力雄健。\n",
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

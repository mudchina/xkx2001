//Cracked by Roath
// xiakedao/xkx4.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 2;
void create()
{
        set("short", "石室");
        set("long", @LONG
此洞中仍是较为拥挤。有几人脚踏北斗七星方位，或正或逆地行
走；一名老者端坐于北极星位闭目打坐，头顶隐隐透出丝丝白气。另
有两个黄衫女子并肩而立，在石壁(wall)上指指点点。
LONG );

      set("exits", ([
		"east" : __DIR__"xiakexing1",
      ]));
	set("item_desc",([
	    "wall" : "
墙的正上方刻着「飒沓如流星」几个大字。字的下方刻有一张黄道星
空图，其中北斗七星大而明显。旁有图注：虽云“流星”，然动从静
中求，毋舍本逐末也。又一行小注：春雪似锦秋风飒。\n",
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

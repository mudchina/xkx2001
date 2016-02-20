//Cracked by Roath
// xiakedao/xkx10.c
// modifiedy by aln 5 / 98

inherit __DIR__"no_pk_room";

int flag = 3;

void create()
{
        set("short", "石室");
        set("long", @LONG
这里却也安静。右面地上一人横卧，似是过度疲倦，已经沉沉睡
去。一个布衣男子袖手而立，呆呆地望着石壁(wall)出神，他身旁站
着一位美貌少妇。旁边的火把将要燃尽，摇曳不定。地上横七竖八丢
弃了一些破损的兵刃。
LONG );

      set("exits", ([
		"north" : __DIR__"xiakexing3",
      ]));
	set("item_desc",([
	    "wall" : "
墙的正上方刻着「脱剑膝前横」几个大字。字的下方未见图画，只是
大大小小，以各种字体写满了注释。一行草书是：杜工部诗云：一舞
剑器动四方。又一行隶书入石甚深：江南山水通志：岭南有石，瘦长
似剑。传有神异，土人多膜拜。名为横剑。另有寥寥几个蝇头小楷：
戴，而后脱之。\n",
	]));
      set("objects",([
            __DIR__+"npc/hong2.c" : 1,
            __DIR__+"npc/su.c" : 1,
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

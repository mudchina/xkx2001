//Cracked by Roath
// xiakedao/xkx2.c
// modified by aln 5 / 98

inherit __DIR__"no_pk_room";
int flag = 1;
void create()
{
        set("short", "石室");
        set("long", @LONG
进入第二间石室，只觉眼前一花，端的是剑气纵横。数人各持长
剑，正在捉对较量，兵刃撞击，铮铮不绝。地上遗弃着几柄长短不一
的断剑。墙上也有些兵器劈砍的斑痕。旁边有两位老者正在争论着什
麽。石壁(wall)上有若干字迹。
LONG );

      set("exits", ([
                "north" : __DIR__"xiakexing1",
      ]));
        set("item_desc",([
            "wall" : "
墙的正上方刻着「吴钩霜雪明」几个大字。大字的下方又密密麻麻地
刻满了数千小字，笔划各异，大小不同。第一行是：鲍照乐府：“锦
带配吴钩”。又有一行写的是：白居易诗云：“勿轻直折剑，犹胜曲
全钩。”\n",
        ]));

        set("indoors", "xiakedao" );
	set("no_fight", 1);
        set("cost", 0);
        set("objects",([
            __DIR__+"npc/zhang.c" : 1,
            __DIR__+"npc/feng.c" : 1,
            ]));
        setup();


}
void init()
{
        ::init();
        add_action("do_study", "study");
}
#include "/d/xiakedao/xkx.h"

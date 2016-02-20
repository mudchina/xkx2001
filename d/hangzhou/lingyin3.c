//Cracked by Roath
// 灵隐寺之大雄宝殿
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "大雄宝殿");
    set("long", @LONG
殿内正中一尊如来佛像，两旁塑有二十尊诸天的佛像，大殿後壁
有五十三参海岛像，岛上有姿态各异的大小佛像一百五十个。灵隐寺
时常延请外寺高僧前来讲经说佛。
LONG);

   set("exits", ([ /* sizeof() == 1 */ 
                  "out" : __DIR__"lingyin2", 
                ])
       );
   set("objects", ([__DIR__"npc/kumu" : 1,]));
	
	set("cost", 0);
    setup();
   //  replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if( me->query_condition("lyjob") ) {
                me->apply_condition("lyjob", 0);
                message_vision("\n$N站起身来，对周围众僧说道：" + RANK_D->query_self(me) + "有点急事，下次有机会一定前来谢过今日之仓促。\n", me);
        }

        return ::valid_leave(me, dir);
}

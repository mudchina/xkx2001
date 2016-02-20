//Cracked by Roath
// Room: /city/shuyuan.c
// YZC 1995/12/04 
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"书院"NOR);
        set("long", @LONG
这里是书院的讲堂，窗明几净，一尘不染。一位庄重严肃的老者坐在太师椅
上讲学，那就是当今大儒朱先生了。在他的两侧坐满了求学的学生。一张古意盎
然的书案放在朱先生的前面，案上摆着几本翻开了的线装书籍。朱先生的身后是
一个书架。讲堂内多历代楹联石刻，足见书院历史的悠久。值得一提的是嵌在讲
堂前左壁的学规(xuegui)和右壁的证书(zhengshu)。
LONG
        );

        set("exits", ([
                "south" : __DIR__"dongdajie1",
                "up": __DIR__"cangshuge",
        ]));

        set("item_desc", ([
                "xuegui" : "日讲经书三起，日看纲目数页。"  
                        "\n通晓时务物理，参读古文诗赋。" 
                        "\n读书必须过笔，会课按时蚤完。"
                        "\n夜读仍戒晏起，疑误定要力争。\n\n"
                        "求学需缴学费二两\n",
                "zhengshu" : "京师国子监授权举办科举考试与代授学位，"
                             "具体问题亲问朱先生。关於科举简介使用帮助"
                             "(help keju)。\n",
        ]));
        
        set("objects", ([
                __DIR__"npc/zhu": 1,
        ]));

        set("day_shop", 1);
        set("cost", 0);
        setup();
}

int valid_leave(object me, string dir)
{
      object *inv;
        int i;
        inv = all_inventory(me);
	   if ( dir == "south" || dir == "up" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开这里。\n");
                }
        }
	   me->set_temp("mark/朱", 0);
        return ::valid_leave(me, dir);
}

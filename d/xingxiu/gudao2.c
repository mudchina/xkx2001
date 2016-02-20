//Cracked by Roath
// Ryu, 5/10/97
// wsky, 5/7/00
#include <ansi.h>;
inherit ROOM;
string look_stone();
void create()
{
        set("short", "冰川古道");
        set("long", @LONG
冰冷刺骨的大风卷着飞沙走石，从北面的冰川古道方向滚滚而来，
呼呼之声，令人心悸。山道边上的大石(stone)，上面隐隐刻有得几
行字。
LONG
        );
        set("exits", ([
                "westup" : __DIR__"gudao3",
                "southdown" : __DIR__"gudao1",
                "eastup":__DIR__"gcliff",
        ]));
        set("item_desc",([
                "stone"         :       (: look_stone :),
        ]));
        set("cost", 20);
        set("outdoors", "tianshan");

        setup();
}
string look_stone()
{
        return
        "\n"
        "    ※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"
        "    ※※※※  　 　　　　　　           　　　 　※※※※\n"
        "    ※※※※  　　　　沙　违　不　多　寻　山　 　※※※※\n"
        "    ※※※※  　唐　　雨　犯，得　暴　复　谷　 　※※※※\n"
        "    ※※※※  　玄　　石，　　褚　龙　结　秋　 　※※※※\n"
        "    ※※※※  　奘　　　　灾　衣，难　冰。雪， 　※※※※\n"
        "    ※※※※ 　 法　　遇　祸　　　　　　　　 　　※※※※\n"
        "    ※※※※ 同 师　　者　目　持　凌　经　春　 　※※※※\n"
        "    ※※※※ 侣 　　　丧　睹。瓠　犯　途　夏　 　※※※※\n"
        "    ※※※※ 商 　　　命。　　大　行　险　合　 　※※※※\n"
        "    ※※※※ 旅 　　　　　暴　声　人。阻，冻， 　※※※※\n"
        "    ※※※※ 商 　　　难　风　叫　　　　　 　　　※※※※\n"
        "    ※※※※ 胡 　　　以　奋　唤，由　寒　虽　 　※※※※\n"
        "    ※※※※ 数 　　　全　发，　　此　风　有　 　※※※※\n"
        "    ※※※※ 十 　　　生。　　微　路　惨　消　 　※※※※\n"
        "    ※※※※ 人 　　　　　飞　有　者，烈。泮， 　※※※※\n"
        "    ※※※※　　   　  　　　　             　 　※※※※\n"
        "    ※※※※※※※※※※※※※※※※※※※※※※※※※※※\n";
}
int valid_leave(object me, string dir)
{
        object *inv;
        int i, flag, j=0;

        inv = all_inventory(me);

        for (i=0; i<sizeof(inv); i++) {
                if ((string)inv[i]->query("id")=="xuelian") j++;
        }

        if( random((int)me->query_skill("dodge")) <= 30 || ( j > 1 ) ){

                me->receive_damage("qi", 50, "从山坡上滚下来摔死了");
                me->receive_wound("qi",  50, "从山坡上滚下来摔死了");
                message_vision(HIR"$N一不小心脚下一滑，... 啊...！\n"NOR, me);
                me->move(__DIR__"lake");
                message("vision", HIR"只见" + me->query("name")
                + "咕碌咕碌地从山坡上滚下来，差点儿掉进湖里。\n"NOR, environment
(me), me);
        if ( j > 1 )
        for (i=0; i < sizeof(inv); i++) {
                if ( !inv[i]->query("armor_prop/armor") ) {
                        destruct(inv[i]);
                        flag += 1;
           }
        if ( flag ) tell_object(me, "你身上的东西都扑通扑通掉进了湖里。\n");
        }

        return notify_fail(HIR"你从山坡上咕碌咕碌地滚了下来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
        }
        return ::valid_leave(me, dir);
}

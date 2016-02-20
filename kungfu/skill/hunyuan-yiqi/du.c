//Cracked by Roath
// du.c 
// by aln 4 / 98

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        mapping fam;
        string dest;

        mapping bank_bank = ([
                "/d/shaolin/hanshui1" : "/d/shaolin/hanshui2",
                "/d/shaolin/hanshui2" : "/d/shaolin/hanshui1",
                "/d/xixia/oldwall"    : "/d/xixia/xhbao",
                "/d/xixia/xhbao"      : "/d/xixia/oldwall",
                "/d/taihu/taihu"      : "/d/taihu/matou",
                "/d/taihu/matou"      : "/d/taihu/taihu",
        ]);

        fam = me->query("family");
        if( fam["family_name"] != "少林派" || fam["generation"] != 35 )
        return notify_fail("你不是少林渡字辈高僧不会使用一苇渡江功！\n");

        if( me->query_skill("shaolin-shenfa", 1) < 200 )
        return notify_fail("你的少林身法功力不够，无法施展一苇渡江绝技！\n");

        if( me->query_skill("hunyuan-yiqi", 1) < 160 )
        return notify_fail("你的混元一气功功力不够，无法施展一苇渡江绝技！\n");

        if( me->query_skill_mapped("dodge") != "shaolin-shenfa" )
        return notify_fail("你现在没有使用少林身法作为轻功的的特殊技能。\n");

        if( me->query("max_neili") < 2000 || me->query("neili") < 1000 )
        return notify_fail("你的内力不够，无法施展一苇渡江绝技！\n");

        if( undefinedp(dest = bank_bank[base_name(environment(me))]) )
        return notify_fail("此地不适合施展一苇渡江绝技！\n");

        message_vision("\n$N拾起岸边的一枝芦苇，投入波涛滚滚的水面。\n" +
        "接著$N一跃而起，脚尖在苇枝上一点，两袖飘飘，箭一般地在水面上穿了过去。\n\n", me);

        me->add("neili", - (100 + random(200)));
        me->move(dest);
        return 1;
}

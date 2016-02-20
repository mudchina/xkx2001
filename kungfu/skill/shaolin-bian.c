//Cracked by Roath
// riyue-bian.c 日月鞭法
// maco 修改描述、code

#include <ansi.h>

int dead_msg(object me, object victim, object weapon, int damage);

inherit SKILL;
///*****************************************************************************

/*
只觉两条长物从脸上横掠而过，相距不逾半尺，去势奇急，却是绝无劲风，正是两条黑索。他只滚出丈余，又是一条黑索向胸口点到，那黑索化成一条笔直的兵刃，如长矛，如杆棒，疾刺而至，
那条长索一抖，一股排山倒海的内劲向胸口撞到，这内劲只要中得实了，当场便得肋骨断折，五脏齐碎。
三招九式，每一式中都隐藏数十招变化，数十下杀手，
黑索抖动，转成两个圆圈
不但招数精巧，内劲更是雄厚无比。
他当下以巧补弱，使得黑索滚动飞舞，宛若灵蛇乱颤，
两条黑色长鞭灵动威猛，直和一双乌龙相似，

“金刚伏魔圈”

三条黑索便如三条张牙舞爪的墨龙相似，急升而上，分从三面扑到。
只听得“啊”的一声惨叫，何太冲背脊中索，从圈子中直摔出来，眼见得是不活了。
渡劫道：“我们单打独斗，并无胜你把握。这等血海深仇，也不能讲究江湖规矩了。好魔头，下来领死罢。阿弥陀佛！”他一宣佛号，渡厄、渡难二僧齐声道：“我佛慈悲！”三根黑索倏地飞起，疾向他身上卷来。
他越斗越是心惊，只觉身周气流在三条黑索和三股掌风激荡之下，竟似渐渐凝聚成胶一般。
当下向渡厄急攻三招，待要抢出圈子，不料三条黑索所组成的圈子已如铜墙铁壁相似，他数次冲击，均被挡回，已然无法脱身。
呼呼两声，两条黑索分从左右袭到，
少林三僧的黑索渐渐收短。黑索一短，挥动时少耗内力，但攻敌时的灵动却也减了几分。更斗数十招，三僧的黑索又缩短了六七尺。
寻瑕抵隙，步步进逼，竭力要扑到三僧身边。但三僧黑索收短后守御相当严密，三条黑索组成的圈子上似有无穷弹力，两名黑须老人不住变招抢攻，总是被索圈弹了出去。
只须黑索再缩短八尺，便组成了“金刚伏魔圈”，
三僧黑索一抖，犹似三条墨龙一般，围成了三层圈子。
已将索圈压得缩小了丈许圆径。然而三僧的索圈压小，抗力越强，三人每攻前一步，便比前要多花几倍力气。

但这三位少林高僧枯禅数十年坐将下来，心意相通，一僧招数中露出破绽空隙，其余二僧立即予以补足。
三僧的“金刚伏魔圈”却正是以佛力伏魔的精妙大法。旁人只见他越斗越精神
不免便全然处于三僧佛门上乘武功的克制之下，
三僧的“金刚伏魔圈”以“金刚经”为最高旨义，最后要达“无我相，无人相，无众生相，无寿者相”，于人我之分，生死之别，尽皆视作空幻。
只是三僧修为虽高，一到出手，总去不了克敌制胜的念头，虽已将自己生死置之度外，人我之分却无法泯灭，因此这“金刚伏魔圈”的威力还不能练到极致。
三僧中渡厄修为最高，深体必须除却“人我四相”，但渡难、渡劫二僧争雄斗胜的念头一盛，染杂便深，着了世间相的形迹，渡厄的鞭法非和他二人相配不可。
少林三僧拚到此时，已瞧出久战于已不利，突然间齐声高喝，三条长鞭急速转动，鞭影纵横，似真似幻。张无忌凝视敌鞭来势，一一拆解，

*****************************************************************************///

mapping *action = ({
([      "action": "$N手中$w挥出，$w势道奇急，却是绝无劲风，自$n$l横掠而过，相距已不逾半尺",
        "dodge":  -5,
        "damage": 60,
        "force" : 160,
        "lvl" : 30,
        "damage_type":  "鞭伤"
]),
([      "action": "$N手腕一抖，$w直昂上来，撞向$n面门，灵动威猛，便如一条张牙舞爪的墨龙相似",
        "dodge": -10,
        "damage":  95,
        "force" : 320,
        "lvl" : 60,
        "damage_type":  "鞭伤"
]),
([      "action": "$N$w抖动，转成两个圆圈，从半空中往$n头顶盖下，不但招数精巧，内劲更是雄厚无比",
        "dodge":  -15,
        "damage": 120,
        "force" : 480,
        "lvl" : 90,
        "damage_type":  "鞭伤"
]),
([      "action": "$N手运刚劲，$w上所发内力直如排山倒海一般，向着四面八方逼去，登时迫得$n连连倒退",
        "dodge":  -15,
        "damage": 140,
        "force" : 520,
        "lvl" : 120,
        "damage_type":  "内伤",
	"post_action" : (: dead_msg :)
]),
([      "action": "$N手腕一抖，$w向$n胸口点到，化成一条笔直的兵刃，如长矛，如杆棒，疾刺而至，招数厉害之极",
        "dodge":  -15,
        "damage": 160,
        "force" : 400,
        "lvl" : 180,
        "damage_type":  "刺伤",
	"post_action" : (: dead_msg :)
]),
([      "action": "$N鞭上内劲不绝催动，内功施展到了淋漓尽致，$w呼啸而出，向$n面门点去，鞭身未到，$w上所挟劲风已令$n一阵气窒",
        "dodge":  -15,
        "damage": 140,
        "force" : 540,
        "lvl" : 240,
        "damage_type":  "内伤",
	"post_action" : (: dead_msg :)
]),
([      "action": "$N手中$w滚动飞舞，宛若灵蛇乱颤，鞭影纵横，似真似幻，骤出三招九式，每一式中都隐藏数十招变化，数十下杀手",
        "dodge":  -15,
        "damage": 170,
        "force" : 600,
        "lvl" :  300,
        "damage_type":  "鞭伤",
	"post_action" : (: dead_msg :)
])
});

int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

int valid_learn(object me)
{
        mapping fam;
        object weapon;

        fam = me->query("family"); 
        if( !mapp(fam) || fam["family_name"] != "少林派" )
                return notify_fail("你不属于少林派，不能学习博大精深的日月鞭法！\n");

        if ( fam["family_name"] == "少林派" && fam["generation"] > 36 )
                return notify_fail("你资格不够，不能学习日月鞭法，等到升了辈份再说吧。\n");

        if( (int)me->query("max_neili") < 500 )
                return notify_fail("你的内力不足，没有办法练日月鞭法，多练些内力再来吧。\n");

        if ((int)me->query_skill("hunyuan-yiqi", 1) < 50)
                return notify_fail("你的混元一气功火候太浅。\n");

        if ( !objectp(weapon = me->query_temp("weapon"))
        || ( string)weapon->query("skill_type") != "whip" )
                return notify_fail("你必须先找一条鞭子才能练鞭法。\n");

        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("shaolin-bian",1);
        for(i = sizeof(action); i > 0; i--)
        
        if (random(level) > 300 && random(me->query("neili")) > 1000 ){
        me->add("neili", -20);
        return ([
        "action":HIW"$N心神宁定，$w"NOR+HIW"挥动时无声无息，内力返照空明，功力精纯，不露棱角，$n祗觉身周气流略有异状，这一下袭击事先竟无半点朕兆"NOR,
        "force" : 520+(level/5)+random(level/2),
        "dodge" : 0,
        "parry" : 0,
        "damage" : 150+random(level/3),
        "damage_type":"内伤",
	"post_action" : (: dead_msg :)
        ]);
        }
        else if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("你的精力不够练日月鞭法。\n");
        me->receive_damage("jingli", 10 );
        if( me->query_skill("riyue-bian",1) > 150 ) me->receive_damage("jingli", 5 );
        if( me->query_skill("riyue-bian",1) > 180 ) me->receive_damage("jingli", 10 );
        if( me->query_skill("riyue-bian",1) > 200 ) me->receive_damage("jingli", 15 );

        return 1;
}
/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level;
	object weapon;
        string *msg;
        weapon = me->query_temp("weapon");
        msg = ({
                HIR"只听得“啊”的一声惨叫，$n背脊为"+weapon->name()+HIR"所击中，摔出了战圈，眼见是不活了。\n"NOR,
                HIR"这一鞭威力极巨，登时打得$p脑浆迸裂，四肢齐折，不成人形。\n"NOR,
                HIR""+weapon->name()+HIR"一抖之下，一股排山倒海的内劲向$n胸口撞到，$n当场肋骨断折，五脏齐碎。\n"NOR,
        });
        level  = (int) me->query_skill("shaolin-bian",1);
	if ( !living(victim) && level > 200 && me->query("neili")>1000) 
	return msg[random(sizeof(msg))];
}
*/      

string perform_action_file(string action)
{
        if ( this_player()->query_skill("riyue-bian", 1) >= 50 )
                return __DIR__"riyue-bian/" + action;
}


int dead_msg(object me, object victim, object weapon, int damage)
{
	int level;
//	object weapon;
        string *msg;
        //weapon = me->query_temp("weapon");
        msg = ({
                HIR"只听得“啊”的一声惨叫，$n背脊为"+weapon->name()+HIR"所击中，摔出了战圈，眼见是不活了。\n"NOR,
                HIR"这一鞭威力极巨，登时打得$p脑浆迸裂，四肢齐折，不成人形。\n"NOR,
                HIR""+weapon->name()+HIR"一抖之下，一股排山倒海的内劲向$n胸口撞到，$n当场肋骨断折，五脏齐碎。\n"NOR,
        });
        level  = (int) me->query_skill("shaolin-bian",1);
	if ( !living(victim) && level > 200 && me->query("neili")>1000) 
	message_vision(msg[random(sizeof(msg))], me, victim);

}
//Cracked by Roath
// touch.c 十八摸
inherit SKILL;

mapping *action = ({
([
        "action" : "摸呀摸，$N满脸胀得通红，手里握住$n的$l，忍不住舔了一下",
        "damage" : 40,
        "weapon" : "舌头",
        "damage_type" : "抽伤"
]),
([
        "action" : "摸呀摸，$N伸手在$n的胸口轻轻一摸，嗤的一声，撕开了$p的衣衫",
        "damage" : 25,
        "damage_type" : "抓伤"
]),
([      "action" : "四十八呀摸，$N陶醉的摸住了$n的脸庞，$p登时感觉舒服得说不出话来",
        "damage" : 25,
        "damage_type" : "挫伤"
]),
([      "action" : "四十七呀摸，$N把手一伸，穿过了$n的大腿，用力的捏了$p一下",
        "damage" : 25,
        "damage_type" : "挫伤"
]),
([
        "action" : "四十六呀摸，$N抓住了$n的双手，用头发轻柔地在$p身上乱摸",
        "damage" : 25,
        "damage_type" : "抓伤"
]),
([
        "action" : "四十五呀摸，$N轻轻用手心贴在$n的胸口，$p忍不住心跳加速起来",
        "damage" : 28,
        "damage_type" : "内伤"
]),
([
        "action" : "四十四呀摸，$N轻柔的抚摸着$n的肩膀，$p登时热血沸腾，面红耳赤，不能自己",
        "damage" : 28,
        "damage_type" : "内伤"
]),
([
        "action" : "四十三呀摸，$N把脸贴在$n的胸口，伸手在$p的背后用力的抚摸",
        "damage" : 12,
        "damage_type" : "内伤"
]),
([
        "action" : "四十二呀摸，$N手臂紧紧的搂住了$n的细腰，越搂越紧，$p登时喘不过气来",
        "damage" : 38,
        "damage_type" : "挫伤"
]),
([
        "action" : "四十一呀摸，$N双掌突然飞了起来，左右开弓，在$n的脸上轻轻的摸去",
        "damage" : 18,
        "damage_type" : "内伤"
]),
([
        "action" : "四十呀摸，$N温柔地伸出大手，往$n的$l摸来摸去",
        "damage" : 18,
        "damage_type" : "内伤"
]),
([
        "action" : "三十九呀摸，$N双手回旋反复地从$n的大腿内侧一直摸到内侧",
        "damage" : 15,
        "damage_type" : "内伤"
]),
([
        "action" : "三十八呀摸，$N手指猛然穿过$n的头发，渐渐地往下摸去",
        "damage" : 15,
        "damage_type" : "内伤"
]),
([
        "action" : "三十七呀摸，$N双手温柔地抓住$n的$l，手指一阵一阵地用力的按摩",
        "damage" : 30,
        "damage_type" : "抓伤"
]),
([      "action" : "三十六呀摸，$N把手压在$n的$l上，连连不绝的抚摸着",
        "damage" : 15,
        "damage_type" : "内伤"
]),
([      "action" : "三十五呀摸，$N伸手拦住了$n的细腰，温柔地抚摸着$p的背部",
        "damage" : 25,
        "damage_type" : "挫伤"
]),
([      "action" : "三十四呀摸，$N连环三次，轻轻地捏了捏$n的$l",
        "damage" : 35,
        "damage_type" : "内伤"
]),
([      "action" : "三十三呀摸，$N用力摩擦着$n的$l，$p登时如醉如痴",
        "damage" : 10,
        "damage_type" : "挫伤"
]),
([      "action" : "三十二呀摸，$N一脸贼忒嘻嘻，口中轻哼十八摸小调，在$n身上一阵乱摸",
        "damage" : 20,
        "damage_type" : "内伤"
]),
([      "action" : "三十一呀摸，$N大手在$n腰际游移，$n只觉浑身发软，$N趁机又在$p$l摸了几把",
        "damage" : 30,
        "damage_type" : "挫伤"
]),
([      "action" : "三十呀摸，$N只手紧紧搂住$n，另一只手已探入$p的衣衫",
        "damage" : 40,
        "damage_type" : "内伤"
]),
([      "action" : "二十九呀摸，$n突然觉得脸上一热，$N将脸颊贴了过来，跟著$p又觉$N伸手来自己身上摸索",
        "damage" : 50,
        "damage_type" : "抽伤"
]),
([      "action" : "二十八呀摸，$N伸臂将$n搂在怀里，$n奋力挣扎，$N左臂更搂得紧了些，右手轻轻抚摸$p脸蛋",
        "damage" : 55,
        "damage_type" : "内伤"
]),
([      "action" : "二十七呀摸，$N假意一跤摔在地上，趁$n踏前之际，双手一伸往$p小腿摸去",
        "damage" : 45,
        "damage_type" : "瘀伤"
]),
([      "action" : "二十六呀摸，$N一脸陶醉，想去亲亲$n，$p红著脸避了开来，$N又伸手往$n身上摸去",
        "damage" : 15,
        "damage_type" : "抓伤"
]),
([      "action" : "二十五呀摸，$N摸了摸$n的$l，又亲亲$p的脸蛋",
        "damage" : 25,
        "damage_type" : "挫伤"
]),
([      "action" : "二十四呀摸，$N摸到了$n的屁股，$p忍不住尖声大叫，$N又往$n的$l摸去",
        "damage" : 35,
        "damage_type" : "内伤"
]),
([      "action" : "二十三呀摸，$N在$n胸脯摸了几把，跟著又向下去摸$p的腰肢",
        "damage" : 10,
        "damage_type" : "瘀伤"
]),
([      "action" : "二十二呀摸，$N左手放在$n脸蛋上，来回抚摸，右手在$p胸口用力一捏",
        "damage" : 20,
        "damage_type" : "抽伤"
]),
([      "action" : "二十一呀摸，$N捏捏$n的脸颊，一张嘴直往前凑去吻了$p一下",
        "damage" : 30,
        "damage_type" : "瘀伤"
]),
([      "action" : "二十呀摸，$N右手轻轻抚摸著$n的头发，左手又去摸$p的后颈",
        "damage" : 40,
        "damage_type" : "抽伤"
]),
([      "action" : "十九呀摸，$N笑嘻嘻地伸出大手，在$n脸蛋上摸了一把",
        "damage" : 45,
        "damage_type" : "瘀伤"
]),
([      "action" : "十八呀摸，$N转到$n的后面，轻轻抚摸着$p的背部",
        "damage" : 15,
        "damage_type" : "抽伤"
]),
([      "action" : "十七呀摸，$N嘴里大叫，双手痛快地挤压着$n的小腿",
        "damage" : 55,
        "damage_type" : "瘀伤"
]),
([      "action" : "十六呀摸，$N渐渐的摸到了$n的头颈，伸嘴在$p的耳朵呵气，轻轻咬了一口",
        "damage" : 35,
        "damage_type" : "抽伤"
]),
([      "action" : "十五呀摸，$N用力的捏了捏$n的屁股",
        "damage" : 25,
        "damage_type" : "挫伤"
]),
([      "action" : "十四呀摸，$N口中唔唔唔的腻声轻哼，伸手轻轻地摩擦着$n的肩膀",
        "damage" : 15,
        "damage_type" : "抓伤"
]),
([      "action" : "十三呀摸，$N一手搂著$n的脖子，一手乱摸$p的$l",
        "damage" : 35,
        "damage_type" : "抽伤"
]),
([      "action" : "十二呀摸，$N热情如火的抱住了$n的身子，手里抚摸着$p的$l，$p登时情迷意乱",
        "damage" : 55,
        "damage_type" : "瘀伤"
]),
([      "action" : "十一呀摸，$N轻轻的按住了$n的胸，$p登时羞得满脸通红",
        "damage" : 35,
        "damage_type" : "抽伤"
]),
([      "action" : "十呀摸，$N双手慢慢地摸到$n的肚子，$p登时情热如沸",
        "damage" : 45,
        "damage_type" : "瘀伤"
]),
([      "action" : "九呀摸，$N伏在$n的脚边，温柔地抚摸$p的大腿",
        "damage" : 55,
        "damage_type" : "抓伤"
]),
([      "action" : "八呀摸，$N一个转身，手掌突然温柔地摸了摸$n的$l",
        "damage" : 50,
        "damage_type" : "瘀伤"
]),
([      "action" : "七呀摸，$N扑了上来，伏在$n的怀里，伸手乱摸$p的$l",
        "damage" : 60,
        "damage_type" : "瘀伤"
]),
([      "action" : "六呀摸，$N紧紧的握住了$n的双脚，开始舔$p的脚趾",
        "damage" : 20,
        "damage_type" : "抽伤"
]),
([      "action" : "五呀摸，$N忽然狠狠的抓住了$n的五根手指尖",
        "damage" : 40,
        "damage_type" : "抓伤"
]),
([      "action" : "四呀摸，美人脸蛋象瓜子，$N的手指轻轻的抚摸着$n的脸蛋",
        "damage" : 40,
        "damage_type" : "抓伤"
]),
([      "action" : "三呀摸，$N陶醉地摸到了$n的头发边",
        "damage" : 30,
        "damage_type" : "抓伤"
]),
([      "action" : "二呀摸，$N一把搂住了$n的纤纤细腰",
        "damage" : 50,
        "damage_type" : "抓伤"
]),
([      "action" : "一呀摸，$N摸到$n的$l，$p登时全身酸软",
        "damage" : 50,
        "damage_type" : "瘀伤"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="unarmed" || usage=="parry"; }

int valid_learn(object me)
{
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("你的精力太低了。\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("你的内力不够练十八摸。\n");
        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}
 
string perform_action_file(string action)
{
        return __DIR__"touch/" + action;
}   

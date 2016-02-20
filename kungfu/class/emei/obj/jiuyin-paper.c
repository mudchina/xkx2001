//Cracked by Roath
// jiuyin-paper.c 手抄九阴真经
// 18th-Aug-2000: by yasuko

#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;

string* subject = ({
        "cuixin-zhang",
        "jiuyin-zhao",
        "feiyu-bian",
});

void create()
{
	set_name(HIW"绢片"NOR, ({ "juan pian", "paper" }));
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "束");
		set("long", "一束薄如蝉翼的绢片，密密麻麻的写满了小字。\n");
		set("material", "silk");
	}
	::create();
}

void init()
{
    add_action( "do_lingwu", "lingwu" );
    add_action( "do_xiulian", "xiulian" );
}

int do_lingwu(string arg)
{
	object report,*ob,me=this_player();
	int i,flag,slow=0;
        string skill;

        if (me->query_busy() > 0) return notify_fail("你正忙着呢。\n");
        if (!arg) return notify_fail("你想领悟真经中的哪门武功？\n");
        flag=0;
	for(i=0;i<sizeof(subject);i++) {
                if (arg==subject[i]) flag=1;
        }
        if (flag==0) return notify_fail("你无法从绢片上领悟这门武功。\n");
        if (!me->query_skill(arg,1)) return notify_fail("别开玩笑了，你根本不会这门武功。\n");
        if (me->query_skill(arg,1)<=40) return notify_fail("以你现在的武功级别，还没法进行领悟。\n");
        switch(arg) {
                case "jiuyin-zhao":      skill="claw";
                                       	 if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        		         return notify_fail("领悟九阴白骨爪必须空手。\n");
                                         break;
                case "cuixin-zhang":     skill="strike";
                                       	 if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        		         return notify_fail("领悟摧心掌必须空手。\n");
                                         break;
                case "feiyu-bian":       skill="whip";
                                         return notify_fail("你现在没法领悟飞雨飘萍鞭。\n");
                                         break;
        }
	if ((int)me->query_skill(skill,1)*3<(int)me->query_skill(arg,1)*2)
		return notify_fail("你的基本功尚不扎实，无法继续领悟。\n");
	if (environment(me)->query("no_fight"))	return notify_fail("这里空气不好，无法专心领悟。\n");
        ob = all_inventory(environment(me));
       	for(i=0; i<sizeof(ob); i++) {
		if ((string)ob[i]->query("race") == "人类"  && ob[i] != me )
                        return notify_fail("领悟时最好是一个人，否则会走火入魔的。\n");
        }
	if (((int)me->query_skill(arg, 1)) %10==9&&(int)me->query_skill(arg, 1)<380)
		return notify_fail("你似乎碰到了什么难题，百思不得其解。最好还是去问问师父吧。\n");
        if (me->query("jiuyin/corpse_poison")>151740)
		return notify_fail("你发现绢片中所述竟与先前修炼的方法大相径庭，丝毫不得要领。\n");
	if ((int)me->query("jing") < 50) return notify_fail("你的精神太差了。\n");
	if ((int)me->query("jingli") < 30) return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20) return notify_fail("你的内力不够了。\n");
	if ((int)me->query("qi") < 10) return notify_fail("你的体力太差了。\n");
        if (random(me->query("jiuyin/corpse_poison"))>1681) {
                slow=1;
		tell_object(me,"你反复将领悟的内容与修炼时的招式相印证，却总觉得有些不对劲。\n");
        }
        me->start_busy(1);
        me->receive_damage("jing", 50+slow*50);
        me->receive_damage("jingli", 30+slow*30);
        me->add("neili", -(20+slow*20));
        me->receive_damage("qi", 10+slow*10);
        me->improve_skill(arg, (int)me->query_skill(skill,1)/(5+slow)+1);
        message_vision( "$N一边仔细地阅读着绢片，两手一边不停地笔画着。\n", me);
        return 1;
}

int do_xiulian(string arg)
{
	object report,*ob,skeleton,me=this_player();
	int i,flag,tmp;
        string skill,item;

        if (me->query_busy() > 0) return notify_fail("你正忙着呢。\n");
        if (!arg) return notify_fail("你想修炼真经中的哪门武功？\n");
        flag=0;
	for(i=0;i<sizeof(subject);i++) {
                if (arg==subject[i]) flag=1;
        }
        if (flag==0) return notify_fail("绢片上没有记载这门武功。\n");
        if (!me->query_skill(arg,1)) return notify_fail("别开玩笑了，你根本不会这门武功。\n");
        if (me->query_skill(arg,1)<=40) return notify_fail("以你现在的武功级别，还没法进行修炼。\n");
        switch(arg) {
                case "jiuyin-zhao":      skill="claw";
                                       	 if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        		         return notify_fail("修炼九阴白骨爪必须空手。\n");
                                         item="skeleton";
                                         break;
                case "cuixin-zhang":     skill="strike";
                                       	 if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                        		         return notify_fail("修炼摧心掌必须空手。\n");
                                         item="corpse";
                                         break;
                case "feiyu-bian":       skill="whip";
                                         return notify_fail("你现在没法修炼飞雨飘萍鞭。\n");
                                         break;
        }
	if ((int)me->query_skill(skill,1)*3<(int)me->query_skill(arg,1)*2)
		return notify_fail("你的基本功尚不扎实，无法继续修炼。\n");
	if (environment(me)->query("no_fight"))	return notify_fail("这里毫无杀气，无法进行修炼。\n");
	if ((int)me->query("jingli") < 30) return notify_fail("你的精力太低了。\n");
	if ((int)me->query("neili") < 20) return notify_fail("你的内力不够练摧心掌。\n");
	skeleton = present(item, me);
	if (!objectp(skeleton)) {
                if (item=="corpse") return notify_fail("你得找一具尸体来练摧心掌。\n");
                if (item=="skeleton") return notify_fail("你得找一些骸骨来练九阴白骨爪。\n");
        }
        ob = all_inventory(environment(me));
	tmp = 0;
       	for(i=0; i<sizeof(ob); i++) 
        {
		if ((string)ob[i]->query("race") == "人类"  && ob[i] != me )
		{
			if (item=="corpse") message_vision(HIR "$N左手拿着一具尸体，举手正要往下拍去，忽然瞥见周围有人，大叫一声！\n" NOR, me);
			if (item=="skeleton") message_vision(HIR "$N左手拿着一具骨骸，右手正要往下插，忽然瞥见周围有人，大叫一声！\n" NOR, me);
               		me->kill_ob(ob[i]);
               		ob[i]->fight_ob(me);
			tmp = 1;
		}
        }
	if (tmp) return notify_fail("你想杀人灭口！\n");
	if (skeleton->query("used")*500 > skeleton->query("combat_exp") ) {
                if (item=="skeleton") {
                        skeleton->set("long", "这副骸骨的头盖骨已经碎裂，象是被九阴白骨爪所碎。\n");
                        return notify_fail("这副骸骨的头盖骨已经碎裂，不能再用了。\n");
                }
		if (item=="corpse") return notify_fail("这具尸体的内脏已然碎裂，不能再用了。\n");
	}
        if (me->query("jiuyin/corpse_poison")>151740) {
                i=random(me->query_kar());
                if (report=find_player("yasuko")) tell_object(report,sprintf("id:%s,kar:%d,i:%d\n",me->query("id"),me->query("kar"),i));
                if (i<10) {
                        tell_object(me, BLU"突然一股阴寒之气从你的丹田奔涌而出，在你各处经脉里乱窜。\n"NOR);
                        if (i==3) {
                                me->set_temp("last_damage_from", "尸毒攻心而死。");
                                me->add("jiuyin/corpse_poison",-(int)me->query("jiuyin/corpse_poison")/100);
                                me->die();
                        }
                        else me->unconcious();
                        return 1;
                }
        }
        skeleton->add("used", 1);
        me->receive_damage("jingli", 10);
        me->add("neili", -5);
        tmp=(int)me->query_skill(skill,1)/5+3;
        me->improve_skill(arg, tmp);
        message_vision( "$N按着绢片上的招式，击打着"+skeleton->name()+"。\n" ,me);
        if (!me->query("jiuyin/corpse_poison")) me->set("jiuyin/corpse_poison",tmp);
        else me->add("jiuyin/corpse_poison",tmp);
        me->add("shen", -random(3));
        if (random(10) == 3) tell_object(me, "你练着练着一股邪念冒上心头。\n");
        return 1;
}
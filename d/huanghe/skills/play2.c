//Cracked by Roath
// play.c 碧海潮生曲
// modified by aln

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	object weapon, room, *inv;
	int i, dp, skill, damage;

	if( (int)me->query("neili") < 800 ) {
		tell_object(me, "你的内力不够。\n");
                return 1;
        }

        room = environment(me);
	if( room->query("no_fight") ) {
		tell_object(me, "在这里不能攻击他人。\n");
                return 1;
        }

	if( !(weapon = me->query_temp("weapon")) ) {
               tell_object(me, "你使用的武器不对。\n");
               return 1;
        }

	if( (string)weapon->query("id") != "yu xiao"
        &&  (string)weapon->query("id") != "tie xiao"
        &&  (string)weapon->query("id") != "zhu xiao" ) {
		tell_object(me, "你使用的武器不对。\n");
                return 1;
        }
        
	if( (string)me->query_skill_mapped("force") != "bitao-xuangong" ) {
                tell_object(me, "你所用的并非碧涛玄功，无法施展碧海潮生曲！\n");
                return 1;
        }
	
	if( (skill = (int)me->query_skill("bitao-xuangong", 1)) < 80 ) {
                tell_object(me, "你的碧涛玄功火候未到，无法施展碧海潮生曲！\n");
                return 1;
        }

   //  modified by aln to give a more reasonable damage
	me->add("neili", -100);
	me->receive_damage("qi", 10);

   //  modified by aln to give a more reasonable busy time
	me->start_busy(1 + random(5 - skill/60));
	message_vision(
		HIG "$N抽出一支洞箫，潜运内力，放到唇边吹奏起来，箫声婉转缠绵，如良宵私语，又如昆岗凤呜。ⅵ\n" NOR, me);

	inv = all_inventory(room);
	for(i = 0; i < sizeof(inv); i++) {
		if( !living(inv[i]) || inv[i] == me ) continue;

                dp = (int)inv[i]->query_skill("force");
		if( random(skill + dp) <= dp * 3 / 2 ) {
        // modified by aln to let enemy kill
        // if you bother them by play, they should kill you
                        inv[i]->kill_ob(me);
                        continue;
                }

        // modified by aln to give a more reasonable damage
		damage = skill * 40 / ((int)inv[i]->query_con() + 20);

                inv[i]->receive_damage("jing", damage);
                inv[i]->receive_damage("jingli", damage);

	        message_vision(HIM"$N觉得全身飘飘欲仙，脸上露出迷惘而满足的神情，情不自禁的手舞足蹈起来......\n"NOR, inv[i]);
		inv[i]->start_busy(damage/100);
	}

	return 1;
}


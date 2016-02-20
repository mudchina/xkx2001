//Cracked by Roath
// qianzhu-poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
                tell_object(me, "你试着运行真气, 发现已然无碍了！\n");
                return 0;
        }
	/*
	if (!living(me)) {
	    me->die();
	    return 0;
	}
	*/
        me->apply_condition("qianzhu-poison", duration - 1);
	tell_object(me, YEL "你只觉得一阵头晕, 眼前只看见五彩斑斓的一片模糊, 原来你中的千蛛万毒手发作了!\n" NOR);
	if (me->query("neili") > duration*duration) {
 	    message_vision(CYN "$N气凝丹田，强行压住千蛛毒气，顿时感觉好多了.\n" NOR, me);
	    me->add("neili", -duration*duration);
	    me->receive_wound("qi", duration);
	    me->receive_wound("jing", duration);
	}else {
 	    message_vision(CYN "$N一阵摇晃, 猛提丹田之气却提不上来，结果险些摔倒.\n" NOR, me);
	    me->receive_wound("qi", duration*duration/2, "毒发身亡");
	    me->receive_wound("jing", duration*duration/2, "毒发身亡");
	}
        return 1;
}

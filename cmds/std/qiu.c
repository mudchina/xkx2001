//Cracked by Roath
// propose.c

#include <ansi.h>
#include <dbase.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, old_app;

        if (me->is_busy())
                return notify_fail("你现在正忙着呢。\n");

	if( !arg ) 
		return notify_fail("指令格式：propose | qiu [cancel]|<对象>\n");
		
	if( arg=="cancel" ) {
		old_app = me->query_temp("marriage/propose");
		if( !objectp(old_app) )
			return notify_fail("你现在并没有向任何人求婚。\n");
		write("你改变主意不向" + old_app->name() + "求婚了。\n");
		tell_object(old_app, me->name() + "改变主意不向你求婚了。\n");
		me->delete_temp("marriage/propose");
		return 1;
	}

	if( !(ob = present(arg, environment(me)))
	||	!ob->is_character() )
		return notify_fail("你想向谁求婚？\n");

	if( me->query("age") < 18 )
		return notify_fail("小孩子捣什么乱？\n");
		
	if( ob==me ) 
		return notify_fail("向自己求婚？你的脑子有毛病吧！\n");
		
        if( !userp(ob) )
		return notify_fail("你只能向玩家求婚。\n");
                        
        if( !living(ob) ) 
		return notify_fail("你必须先把" + ob->name() + "弄醒。\n");
		
	if( me->query("gender") == "无性" || me->query("class") == "taoist" )
		return notify_fail("你俗根已尽，没有自知之明么？\n");
		
	if( me->query("gender") == "女性" )
		return notify_fail("女孩子家向人求婚，这个...不大妥当吧？\n");
		
	if( me->query("class") == "bonze" )
		return notify_fail("你身在佛门，这婚嫁之事嘛，不提也罢！\n");

        if( me->query("class") == "lama" 
	 && me->query_skill("lamaism", 1) < 120)
		return notify_fail("娶妻生子可是高级喇嘛的特权，你等级不够！\n");
		
	if( me->is_spouse_of(ob) )
		return notify_fail("她已经嫁给你啦！\n");
	
	if( me->is_married() )
		return notify_fail("别太贪心了，有一个就差不多啦！\n");
		
	old_app = me->query_temp("marriage/propose");
	if( ob==old_app )
		return notify_fail("你向" + ob->name() + "求婚，但是对方还没有答应。\n");
		
	if( objectp(old_app) ) {
		write("你改变主意不向" + old_app->name() + "求婚了。\n");
		tell_object(old_app, me->name() + "改变主意不向你求婚了。\n");
	}
	
	if( objectp(old_app = me->query_temp("marriage/banquet"))
	||  objectp(old_app = me->query_temp("marriage/ring")) ) {
		if( ob == old_app ) 
			return notify_fail("她已经答应你了，抓紧时间办酒席买戒指吧！\n");
			
		write("你改变主意不想跟" + old_app->name() + "结婚了。\n");
		tell_object(old_app, me->name() + "改变主意不想跟你结婚了。\n");
		me->delete_temp("marriage/banquet");
		me->delete_temp("marriage/ring");
		old_app->delete_temp("marriage/accept");
		old_app->delete_temp("marriage/ring");
	}	

	message_vision("$N向$n求婚。\n", me, ob);
	me->set_temp("marriage/propose", ob );
	tell_object(ob, YEL "如果你愿意与" + me->name() + "结为连理，用 marry 指令。\n" NOR);
	if( me->query("gender") == "无性" )
		tell_object(ob, YEL "不过先警告你，他可是个公公啊，你... 还是三思而后行吧。\n" NOR);
		
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : propose|qiu [cancel]|<对象>
 
这个指令能让你向某人求婚，你必须等到对方用 marry 指令答应与你成婚，
然后男女双方各花一张银票向聚金阁掌柜买戒指，再各花一张银票给醉仙楼
老板办酒席，当时在网上的玩家都可得到一只烤鸭和一瓶女儿红。最后双方
互相交换戒指戴上，就算结婚了。

结婚以后夫妻可以互相学习文化，双方实战经验值超过一万点后，还可以互
相学习武功。以前离过婚的人的配偶可能不大愿意教授全部武功，所以不要
三心二意。

请参考相关指令 marry。
HELP
        );
        return 1;
}

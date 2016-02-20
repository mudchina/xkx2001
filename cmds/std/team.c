//Cracked by Roath
// team.c
//
// Zhuang@XKX 960831
//
// Implementation Notes:
//
// To start a team, `team invite sb`, then you become the team leader.
// To join a team, after the team leader invites you, `team join leader`.
// If you are a leader, `team dismiss` disbands the team, `team dismiss memeber`
// kicks out the member.
// If you are not a leader, `team dismiss` makes you leave the team.
// When a team leader quits or dies, the second most senior member
// automatically becomes the new leader.
// As a team leader, if you accepts someone's invitation, you will bring the
// whole team to the new leadership.
//

#include <command.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *t;

	return 1;
	if( !arg ) {
		if( !pointerp(t = me->query_team()) )
			return notify_fail("你现在并没有参加任何队伍。\n");
		write("你现在队伍中的成员有：\n  " + implode(t->name(1), "\n  ") + "。\n");
		return 1;
	}
	if( arg=="dismiss" ) {
		if( !pointerp(t = me->query_team()) )
			return notify_fail("你现在并没有参加任何队伍。\n");
		if( me->is_team_leader() ) {
			message("team", HIG "【队伍】" + me->name(1) + "将队伍解散了。\n" NOR, t, me);
			write(HIG "你将队伍解散了。\n" NOR);
		} else {
			message("team", HIG "【队伍】" + me->name(1) + "决定脱离队伍。\n" NOR, t, me);
			write(HIG "你脱离了你的队伍。\n" NOR);
		}
		me->dismiss_team();
		return 1;
	}
	if( sscanf(arg, "dismiss %s", arg)==1 ) {
		object ob;

		if( !pointerp(t = me->query_team()) || !me->is_team_leader() )
			return notify_fail("只有队伍领袖可以开除成员。\n");

        if( !(ob = find_living(arg))
        ||  !ob->is_character()
        ||  ob==me
		||  !me->have_team_member(ob) )
			return notify_fail("你想开除谁？\n");

		message("team", HIG "【队伍】" + me->name(1) + "将" + ob->name(1) + "开除了。\n" NOR, t, me);
		write(HIG "你将" + ob->name(1) + "开除出你的队伍。\n" NOR);
		me->dismiss_team(ob);
		return 1;
	}
	if( sscanf(arg, "fight %s", arg)==1 ) {
		if( !pointerp(t = me->query_team()) || !me->is_team_leader() )
			return notify_fail("只有队伍领袖可以发起集体战斗。\n");

		for( int i = 0; i < sizeof(t); i++ )
			if( living(t[i]) )
				KILL_CMD->main(t[i], arg);
		return 1;
    }
	if( sscanf(arg, "invite %s", arg)==1 ) {
		object ob;

		if( pointerp(me->query_team()) && !me->is_team_leader() )
			return notify_fail("只有队伍领袖可以邀请别人加入。\n");

		if( !(ob = present(arg, environment(me)))
		||	!living(ob)
		||	!ob->is_character()
		||	ob==me )
			return notify_fail("你想邀请谁加入？\n");

		if( me->have_team_member(ob) )
			return notify_fail(ob->name(1) + "已经是你的队伍成员了。\n");

		message_vision("$N邀请$n加入$P的队伍。\n", me, ob);
		tell_object(ob, YEL "如果你愿意加入，请用 team join " + me->query("id") + "。\n" NOR);
		me->set_temp("pending/team", ob);
		return 1;
	}
	if( sscanf(arg, "join %s", arg)==1 ) {
		object ob;

        if( !(ob = present(arg, environment(me)))
        ||  !living(ob)
        ||  !ob->is_character()
        ||  ob == me
		||  me != (object)ob->query_temp("pending/team") )
            return notify_fail("你想加入谁的队伍？\n");

		if( pointerp(t = me->query_team()) && !me->is_team_leader() )
			return notify_fail("你已经在一个队伍中了。\n");

		if( !pointerp(t) ) {
			ob->add_team_member(me);
			message_vision("$N决定加入$n的队伍。\n", me, ob);
			message("team", HIG "【队伍】" + me->name(1) + "加入" + ob->name(1) + "的队伍。\n" NOR, me->query_team());
		} else {
			me->join_team(ob);
			message_vision("$N决定加入$n的队伍。\n", me, ob);
			message("team", HIG "【队伍】" + implode(t->name(1), "、") + "加入" + ob->name(1) + "的队伍。\n" NOR, me->query_team());
		}
		ob->delete_temp("pending/team");
		return 1;
	}
	if( sscanf(arg, "talk %s", arg)==1 ) {
		if( !pointerp(t = me->query_team()) )
			return notify_fail("你现在并没有和别人组成队伍。\n");
		message("team", HIW "【队伍】" + me->name(1) + "(" + capitalize(me->query("id")) + ")" + "：" + arg + "\n" NOR, t);
		return 1;
	}
	if( sscanf(arg, "talk* %s", arg)==1 ) {
		string vb, emote_arg;
		
		if( !pointerp(t = me->query_team()) )
			return notify_fail("你现在并没有和别人组成队伍。\n");
                        
		if( sscanf(arg, "%s %s", vb, emote_arg) != 2 ) {
			vb = arg;
			emote_arg = "";
		}
		arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);
		if( !arg ) arg = me->name()+vb+" "+emote_arg+"\n"; 
		message("team", HIW "【队伍】" + arg + NOR, t);
		
		return 1;
	}	
	if( sscanf(arg, "form %s", arg)==1 ) {
		if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
			return notify_fail("你必须是一个队伍的领袖才能组织阵形。\n");
		if( !me->query_skill(arg, 1) )
			return notify_fail("这种阵形你没学过。\n");
		return SKILL_D(arg)->form_array(me);
	}
}

int help(object me)
{
	write(@HELP
队伍指令使用方法:

team invite <某人>  - 邀请某人加入你的队伍。你必须是队伍领袖或不属于任何队伍。
team join <某人>    - 加入某人的队伍。你必须先受到邀请。如果你是队伍领袖，你会
                      带领全队加入。
team dismiss        - 离开队伍。若下此指令的是领袖，则整个队伍会解散。
team dismiss <某人> - 将某人开除出队。你必须是队伍领袖。
team fight <某人>   - 集体攻击某人，可以用 tf <某人> 替代。你必须是队伍领袖。
team talk <讯息>    - 跟队伍里其他的人谈话, 可以用 tt <讯息> 替代。
team form <阵法>    - 如果队伍的领队学过阵法的话，可以将队伍中的成员组织成
                      某种阵形，组成阵形的状态只要领袖一移动就会解除。

直接下 team 指令时则会显示你目前是否有加入队伍及队员名单。

注: team 跟 follow 是独立的，你不一定要 follow 队伍的领袖。
HELP
	);
	return 1;
}

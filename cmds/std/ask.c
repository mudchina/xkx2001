//Cracked by Roath
// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// 07/02/96 Marz 
// 3/16/97 Jay


#include <ansi.h>

inherit F_CLEAN_UP;
//add ask job_system someting
//#include "/clone/obj/job/job_ask_about.h"
////////////////////////////////////wzfeng 2000 7/////////////

string *msg_dunno = ({
	"$n摇摇头，说道：没听说过。\n",
	"$n睁大眼睛望着$N，显然不知道$P在说什么。\n",
	"$n耸了耸肩，很抱歉地说：无可奉告。\n",
	"$n说道：嗯....这我可不清楚，你最好问问别人吧。\n",
	"$n想了一会儿，说道：对不起，你问的事我实在没有印象。\n"
});

string *msg_foreign = ({
        "$n说道：你在说外国话吧？我不会，你最好带个翻译来。\n",
        "$n嘻嘻笑道：你说什么鸟语？\n",
        "$n说道：才阿八热古里古鲁。你看，我也能假装会说外国话。\n"
});


int main(object me, string arg)
{
	string dest, topic, msg, att;
	object ob;
	mapping inquiry;

	int iyes = 0;

	seteuid(getuid());

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("你要问谁什么事？\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("这里没有这个人。\n");

	if( ob == me)
		return notify_fail("何必问自己？\n");

	if( !ob->is_character() ) {
		message_vision("$N对着$n自言自语....\n", me, ob);
		return 1;
	}

	if( !ob->query("can_speak") ) {
		message_vision("$N向$n打听有关『" + topic + "』的消息，但是$p显然听不懂人话。\n", me, ob);
		return 1;
	}
	if( iyes = !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N向$n打听有关『" + topic + "』的消息。\n", me, ob);

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("但是很显然的，$n现在的状况没有办法给$N任何答覆。\n",
			me, ob);
		return 1;
	}
	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N说道：" + msg + "\n" NOR, ob);
			return 1;
		}
	}
	else if (topic[0] < 128  && iyes) {
                message_vision(msg_foreign[random(sizeof(msg_foreign))], me, ob);

	}
	else if ( ob->query("name") == topic || topic == "name" )

	{
		att = ob->query("attitude");
		
		switch (att)
		{
		case "aggressive":
		case "killer":
			message_vision(YEL"$N对$n把眼一瞪："+RANK_D->query_self_rude(ob)
				+"的名字是可以随便提的吗？！我看你这"+RANK_D->query_rude(me)
				+"是活腻了！\n"NOR, ob, me);
			break;	
		case "heroism":
			message_vision(CYN"$N对$n哈哈一笑："+ob->query("name")+"便是"
				+RANK_D->query_self_rude(ob)+"！\n"NOR, ob, me);
			break;
		case "peaceful":
		case "friendly":
			message_vision(CYN"$N对$n作了一揖：这位"+RANK_D->query_respect(me)
				+"可真会开玩笑，怎么会突然问起"+RANK_D->query_self(ob)
				+"的名字？\n"NOR, ob, me);
			EMOTE_D->do_emote(ob, "sigh", ob->query("id"), 0);
			break;	
		default:
			message_vision(CYN"$N对$n作了一揖：这位"+RANK_D->query_respect(me)
				+"可真会开玩笑，怎么会突然问起"+RANK_D->query_self(ob)
				+"的名字？\n"NOR, ob, me);
			EMOTE_D->do_emote(ob, "sigh", ob->query("id"), 0);
			break;	
		}		

		return 1;
		
	} else
		switch(topic)
	{
		case "here":
			message_vision(CYN "$n对$N说道：这里是" + environment(ob)->query("short") + "，其它的" + RANK_D->query_self(ob) + "不便多说。\n" NOR, me, ob);
			break;
//////////////////////////////////add job system ask about//////////////////////////////////
			//case "贡献度":
			//case "gongxiandu":
			//	tell_player_family_job_contribute(me,ob);
			//	break;
			//case "任务地点":
			//	tell_player_family_job_opposepkerplace(me,ob);
			//	break;
/////////////////////////////////////////////////////////////////////wzfeng 2000 7/////////

			default:
				message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
	}
		

	return 1;
}

int help(object me)
{
   write( @HELP
指令格式: ask <someone> about <something>

这个指令在解谜时很重要, 通常必须藉由此一指令才能
获得进一步的资讯。
HELP
   );
   return 1;
}

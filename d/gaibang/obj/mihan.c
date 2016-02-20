//Cracked by Roath
// mihan.c

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("密函", ({"mihan", "letter", "han"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("material", "paper");
        }
}

void init()
{
	add_action("do_give", "give");
}

int do_give(string arg)
{
	string target, item;
        object obj, who, me=this_player();

        if(!arg) return notify_fail("你要给谁什么东西？\n");

        if( sscanf(arg, "%s to %s", item, target)==2
        || sscanf(arg, "%s %s", target, item)==2 );
        else return notify_fail("你要给谁什么东西？\n");

	if ( item != "mihan" ) return 0;

	if ( !objectp(obj = present(item, me)) )
		return notify_fail("你身上没有这样东西。\n");

	if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

        if (!objectp(who = present(target, environment(me))) || !living(who))
                return notify_fail("这里没有这个人。\n");

	if ( userp(who) )
		return notify_fail("对方不接受这样东西。\n");

	if ( who->query("race") != "人类" )
		return notify_fail("别找碴儿！畜生也能读信吗？\n");

        if( who == me) return notify_fail("自己给自己？！\n");

	message_vision("$N给$n一封密函。\n", me, who);
	call_out("response", 1, me, who, obj);
	obj->move(who);

	return 1;
}

int response(object me, object who, object obj)
{
	string boss;

	switch(random(3)) {
		case 0:
			boss = "大金完颜洪烈六王爷";
			break;
		case 1:
			boss = "蒙古铁木真大汗";
			break;
		case 2:
			boss = "大辽耶律洪基圣上";
			break;
		}

	message_vision("$N抽出密函仔细的看了一遍。\n", who);
	
	if ( obj->query("target_id") != who->query("id") 
	|| obj->query("target_name") != who->name() ) {
		message_vision("$N抬起头来，疑惑地说道：这信不是给我的呀？\n", who);

		if ( who->query("shen") < 0 ) {
			message_vision("$N奸声笑道：嘿嘿！人不为己，天诛地灭！天大的富贵送上门来，岂能放过！\n", who);
			message_vision("$N沉声说道：我得赶紧向"+boss+"报告丐帮的计划！\n", who);

			if ( random(me->query("kar")) > 10 ) {
				message_vision("$N狰狞地对$n说道：你只好自认倒霉，向阎王诉苦去吧！\n", who, me);

				who->kill_ob(me);
				me->kill_ob(who);
			}
			else {
				message_vision("$N沉声对$n说道：快滚！这密函我留下了！\n", who, me);
			}

			destruct(obj);
		}
		else {
			message_vision("$N将密函还给$n，郑重的说道：唉！你怎麽如此大意！要让恶徒将消息走露那可怎麽办？\n", who, me);

			obj->move(me);
		}

		return 1;
	}
	else if ( obj->query("owner") != me->query("id") ) {
		message_vision("$N抬起头来，疑惑地说道：这信不应由你送来，你是怎麽得来的？\n", who);

		if ( who->query("shen") < 0 ) {
			message_vision("$N奸声笑道：嘿嘿！人不为己，天诛地灭！天大的富贵送上门来，岂能放过！\n", who);
			message_vision("$N沉声说道：我得赶紧向"+boss+"报告丐帮的计划！\n", who);

			if ( me->query("shen") > 0 && random(me->query("kar")) > 10 ) {
				message_vision("$N狰狞地对$n说道：你只好自认倒霉，向阎王诉苦去吧！\n", who, me);

				who->kill_ob(me);
				me->kill_ob(who);
			}
			else if ( me->query("shen") > 0 ) {
				message_vision("$N沉声对$n说道：快滚！这密函我留下了！\n", who, me);
			}
			else {
				message_vision("$N拍着$n肩膀高声说道：干得好！这密函我留下了！你的功劳我记着便是。\n", who, me);
			}

			destruct(obj);
		}
		else {
			message_vision("$N将密函还给$n，郑重的说道：唉！你怎麽如此大意！要让恶徒将消息走露那可怎麽办？\n", who, me);
			message_vision("$N说道：快将密函交还给丐帮吧！\n", who);

			obj->move(me);
		}
		
		return 1;
	}
	else if ( me->query("gb/job_pending") ) {
		me->set("gb/job_status", 2);                     
	}
	
	if ( who->query("shen") < 0 ) {
		message_vision("$N抬起头来，目中阴鹫一闪，沉声说道：嘿！岂有此理，道不同不相为谋。\n", who);
				
		if ( random(me->query("kar")) > 10 ) {
			message_vision("$N沉声对$n说道：嘿！俗话说两国交锋，不斩来使，但算你倒霉！\n", who, me);
			message_vision("$N奸笑道：我正愁不知要送甚麽给"+boss+"以表达我的心意，你自个儿送上门来，可怨不得我！\n", who);

			who->set_temp("kill_initiater", 1);
			who->kill_ob(me);
			me->kill_ob(who);
			obj->set("target_name", who->name());

			remove_call_out("check_fight");
			call_out("check_fight", 1, me, who, obj);
//			me->start_call_out( (: call_other, __FILE__, "check_fight", me, obj :), 1);
		}
		else {
			message_vision("$N沉声对$n说道：快滚！甚麽狗屁国家民族大义？这世上只有金银权位才是好东西！\n", who, me);
			message_vision("$N大声说道：识时务者为俊杰，你快叫鲁老儿向"+boss+"投诚，否则大军杀到，将你丐帮夷为平地！\n", who);
			destruct(obj);
		}
	}
	else {
		message_vision("$N抬起头来，对$n拱手说道：有劳"+RANK_D->query_respect(me)+"一路奔波，请代我问侯贵帮鲁长老。\n", who, me);

		switch(random(3)) {
		case 0:
			message_vision("$N说道：请告知鲁长老说他交待的大事，我届时一定会尽力，以尽侠义道的本分！\n", who);
			break;
		case 1:
			message_vision("$N说道：请告知鲁长老说我届时一定出席贵帮的君山大会，和他共襄盛举。\n", who);
			break;
		case 2:
			message_vision("$N说道：请告知鲁长老说我到时或有要事在身，未必能够到来，深感汗颜。\n", who);
			break;
		}

		destruct(obj);
	}

	return 1;
}

int check_fight(object me, object who, object obj)
{
	object corpse;

	if ( !objectp(obj) ) return 1;

	if ( objectp(corpse = present("corpse", environment(me))) 
	&& corpse->query("victim_name") == obj->query("target_name")
	&& corpse->query("my_killer") == me->query("id") ) {
		me->set("gb/job_kill", obj->query("target_name"));
		destruct(obj);
	}
	else if ( objectp(who) && !me->is_fighting(who) ) {
		destruct(obj);
	}
	else {
		call_out("check_fight", 1, me, who, obj);
//		me->start_call_out( (: call_other, __FILE__, "check_fight", me, obj :), 1);
	}

	return 1;
}

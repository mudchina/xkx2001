//Cracked by Roath
#include <ansi.h>
#define TRAVERSER "/clone/obj/traverser"

//int playing(object me);
//int halt_play(object me);
//void sound_float(object me, int range);

void init()
{
	add_action("do_play", "play");
	add_action("do_lianxi", "lianxi");
	add_action("halt_play", "halt");
	add_action("halt_play", "end");

}

string *play_msg = ({
	HIM"但听得箫声连绵不断，越来越是明彻，忽高忽低，愈变愈奇，实在美妙之极，柔媚之音萦绕耳际。",
	HIG"那箫声忽高忽低，忽前忽後，忽焉在西，倏尔在南，似乎有十多人伏在四周，此起彼伏的吹箫戏弄一般。",
	MAG"箫声调子陡变，似浅笑，似低诉，柔靡万端。",
	HIG"只听得箫声由柔媚宛转而渐渐急促，似是催人起舞。",
	HIM"这时那$w"+HIM"之声情致飘忽，缠绵宛转，便似一个女子一会儿叹息，一会儿呻吟，一会儿又软语温存、柔声叫唤。",
	HIM"$w"+HIM"曲调比适才更加勾魂引魄，柔媚宛转，轻轻细细的耍了两个花腔。",
	HIG"$N吹到清羽之音，只听得箫声越拔越高，愈吹愈是回肠荡气。",
	HIM"$N曲调突转，缓缓的变得柔靡万端，恰如昆岗凤鸣，深闺私语。",
});

string *bihai_play_msg = ({
	HIB"此时箫声犹如潮水中鱼跃鲸浮，海面上风啸鸥飞，再加上水妖海怪，群魔弄潮，忽而冰山飘至，忽而热海如沸，极尽变幻之能事。",
	BLU"此时曲调如潮退後水平如镜，海底却又是暗流湍急，于无声处隐伏凶险，更令聆曲者不知不觉而入伏，尤为防不胜防。",
	HIB"洞箫本以柔和宛转见长，这时的音调却极具峻峭肃杀之致。",
	BLU"$N又吹得半晌，$w"+BLU"声愈来愈细，几乎难以听闻。这正是《碧海潮生曲》的厉害之处，箫声愈轻，诱力愈大。",
});

string *succeed_msg = ({
	HIM"$n心头一荡，脸上不自禁的露出微笑，只感全身热血沸腾，就只想手舞足蹈的乱动一番，方才舒服。",
	HIM"$n听到箫声，登时心神荡漾，情欲激动，心烦意乱之极，更觉心头滚热，喉干舌燥。",
	HIM"$n心中一荡，呆了一呆，又听得一阵，只感面红耳赤，血脉贲张，便想手舞足蹈一番。",
	HIM"那箫声具有极大魔力，$n抵挡不住，凝神倾听之下，心中的韵律节拍渐渐与箫声相合。",
});

string *bihai_succeed_msg = ({
	HIB"$n只感心旌摇动，身不由主的一震一跳。",
	HIB"$n再支持了一阵，忽听得箫声中飞出阵阵寒意，霎时间便似玄冰裹身，不禁簌簌发抖。",
	HIB"$n被萧声所侵，渐感冷气侵骨，身子凛有寒意。",
});

string *fail_msg = ({
	"$n刚想随着箫声伸手踢足，立时惊觉，潜运$f，竭力镇摄心神。",
	"总算$n功力精湛，心头尚有一念清明，硬生生把伸出去挥袖舞蹈的手缩了回来。",
	"$n宁定心神，心中一片空明，不着片尘，任$N箫声再荡，听来只与海中波涛、树梢风响一般无异。",
	"$n只感心中一荡，脸上发热，连忙镇慑心神。",
});

string *bihai_fail_msg = ({
	"但是$n防护周密，抱元守一，静心凝志，$N连变数调，却也不能将$p降服。",
	"$n暗暗凝神守一，专守不攻，对这箫声虽是应付裕如，却也不敢有丝毫怠忽。",
});

string *dazuo_fail_msg = ({
	"$n盘膝坐在地下，低头行功，奋力抵御箫声的引诱。",
	"$n左手抚胸，右手放在背後，潜运$f，收敛心神，对$N的吹奏全然不闻不见。",
	"$n盘膝而坐，数次身子已伸起尺许，终于还是以极大的定力坐了下来。",
	"$n盘膝坐在地上，一面运起$f，摒虑宁神，抵御箫声的引诱。",
});

string *faint_msg = ({
	HIM"但听得箫声流转，$n再也忍耐不住，跟著箫声翩翩起舞......",
	HIM"$n听了片刻箫声，自制之力渐失，不由自主的婆娑起舞......",
	HIM"$n觉得全身飘飘欲仙，脸上露出迷惘而满足的神情，情不自禁的手舞足蹈起来......\n",
});

int do_play()
{
	int i, count, range;
	object me, ob, weapon;
	string msg, play_type, *shape;

	ob = this_object();
	me = this_player();
	shape = ob->query("shape");

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");
		
	if( me->query_skill_mapped("force") != "bitao-xuangong" )
		return notify_fail("你所用的并非碧涛玄功，无法施展碧海潮生曲！\n");
	
	if( me->query_skill("force") < 120 )
		return notify_fail("你的碧涛玄功火候未到，无法施展碧海潮生曲！\n");

	if( (int)me->query_skill("music", 1) < 100 )
		return notify_fail("凭你的音律造诣，还无法吹奏得出碧海潮生曲。\n");

	if( (int)me->query("neili") < 800 )
		return notify_fail("你的内力不够。\n");

	if( !objectp(weapon = me->query_temp("weapon")) )
		return notify_fail("你手中并没有拿箫。\n");

	if( weapon->query("name") != ob->query("name") )
		return notify_fail("你手中并没有拿箫。\n");

	for( i=0; i < sizeof(shape); i++ )
		if( shape[i] == "flute" )
		{
			count++;
			break;
		}

//	if( !count ) return notify_fail("你手中并没有拿箫。\n");
	
	
	if(me->query_temp("wuzhuan") && !me->query_temp("playing_bihai") )
	msg = "但见$N神色郑重，手按$n，边走边吹，脚下踏着八卦方位。";
	else msg = "$N$n就唇，幽幽咽咽的吹了起来。";
	if( environment(me)->query("no_fight") )
		msg += "这吹奏不含丝毫内力，便与常人吹箫无异。\n";
	else
	{
		msg += "\n";
		me->add("neili", -200);
		me->receive_damage("qi", 10);
		play_type = "martial";
	}

	message_vision(msg, me, ob);
	me->set_temp("apply/short", ({ me->name() +"正吹奏著"+ ob->name() +"。"}));
	me->set_temp("play_type", play_type);

	message_vision(HIC"突然之间，半空中如鸣琴，如击玉，发了几声，接着悠悠扬扬，飘下一阵清亮柔和的洞箫声来。\n"NOR, me);
//	me->start_busy((: playing :), (: halt_play :));
	me->start_busy(2);
	call_out("playing", 1, me);
//		range = 1+(me->query_skill("bitao-xuangong", 1)-100)/4;
//		sound_float(me, range);
		me->set_temp("exercise/playing", 1);

	return 1;
}

void playing(object me)
{
	string play, succeed, fail, faint, map_force;
	int range, i, k=0, flag, music, music2, force, force2, tag, attacker, defender,damage,times;
	object *target, ob, env;
	
	env = environment(me);
	ob = me->query_temp("weapon");
	force = me->query_skill("force");
	music = (int)me->query_skill("music",1);
	times = me->query_temp("played_times");

	if(!me->query_temp("exercise/playing"))
	{
		message_vision(CYN"箫声忽停，四下阒无声息，一音袅袅，曲终音歇。\n"NOR, me);
		me->delete_temp("apply/short");
		me->set_temp("delete/playing");
		me->delete_temp("played_times");
		me->delete_temp("playing_bihai");
		me->delete_temp("exercise/playing");
		return 0;
	}


	me->start_busy(2);

	if( !objectp(ob) )
	{
		message_vision(CYN"$N手中无箫，箫声顿停。\n"NOR, me);
		me->delete_temp("apply/short");
		me->set_temp("delete/playing");
		me->delete_temp("played_times");
		me->delete_temp("playing_bihai");
		me->delete_temp("exercise/playing");
		return 0;
	}
	if( me->query("jing") < 200 || me->query("neili") < 200 
	|| !living(me) || me->is_ghost())
	{
		if( me->query("jing") < 200)
			tell_object(me,"你的精神不足以继续吹奏碧海潮生曲了。\n");
		if( me->query("neili") < 200)
			tell_object(me,"你的内力不足以继续吹奏碧海潮生曲了。\n");
		message_vision(CYN"箫声忽停，四下阒无声息，一音袅袅，曲终音歇。\n"NOR, me);
		me->delete_temp("apply/short");
		me->set_temp("delete/playing");
		me->delete_temp("played_times");
		me->delete_temp("playing_bihai");
		me->delete_temp("exercise/playing");
		return 0;
	}

	target = all_inventory(environment(me));

		for(i=0; i<sizeof(target); i++) {
		if( !living(target[i]) || target[i]==me ) continue;
		k++;
		}

	if(k < 1 && !environment(me)->query("no_fight")) {
		tell_object(me,CYN"四下并无敌人，无需再吹奏碧海潮生曲了。\n"NOR);
		me->delete_temp("apply/short");
		me->set_temp("delete/playing");
		me->delete_temp("played_times");
		me->delete_temp("playing_bihai");
		me->delete_temp("exercise/playing");
		return 0;
	}
	else {
		if(me->query_temp("wuzhuan") && !me->query_temp("playing_bihai") ) {

			me->set_temp("apply/short", ({ me->name() +"手按"+ ob->name() +"，脚下踏着八卦方位，边行边吹。"}));
			me->add_temp("playing_bihai",1);  //改为碧海msg
		}

		//决定play讯息类别
		if(me->query_temp("playing_bihai") == 1) 
		play = HIC"这套曲子模拟大海浩淼，万里无波，远处潮水缓缓推近，渐近渐快，其後洪涛汹涌，白浪连山。";
		else if(!me->query_temp("playing_bihai")) 
		play = play_msg[random(sizeof(play_msg))];
		else 
		play = bihai_play_msg[random(sizeof(bihai_play_msg))] ;
		//end
		
		if(me->query("neili") < random(600)) message_vision(CYN"箫声忽地微有窒滞，但随即回归原来的曲调。\n"NOR, me);  //警告play者


		if(times != 0 && times/2 * 2 == times)
			message_vision("", me);
		else message_vision("\n"+replace_string( play, "$w", ob->name() ) +"\n"NOR, me, ob);

		me->receive_damage("jing", 20+random(20), "精力透支过度死了");

		if( environment(me)->query("no_fight") ) { //nofight-room no use
		call_out("playing", 1, me);
		return;
		}

		//play效果计算
		me->add_temp("played_times",1);

		if( this_object()->query("id") == "yu xiao" )
		flag = 2;
		else flag = 1;

		attacker = me->query("neili")/20 + random(force)/2+random(music*flag);

		if(me->query_temp("wuzhuan"))
		attacker = me->query("neili")/20 + random(force)/2+random(music*flag) + times*10;
		if( attacker <= 0 ) attacker = 0;
		//开始重复计算所有敌人
		for(i=0; i<sizeof(target); i++) {
		
		if( !living(target[i]) || target[i]==me ) continue;
					//决定讯息类别 2

		if(!me->query_temp("playing_bihai")) {
		play = play_msg[random(sizeof(play_msg))];
		succeed = succeed_msg[random(sizeof(succeed_msg))];
		fail = fail_msg[random(sizeof(fail_msg))];
		}
		else {
		play = bihai_play_msg[random(sizeof(bihai_play_msg))] ;
		succeed = bihai_succeed_msg[random(sizeof(bihai_succeed_msg))];
		fail = bihai_fail_msg[random(sizeof(bihai_fail_msg))];
		}
		faint = faint_msg[random(sizeof(faint_msg))];
		
		if(target[i]->query_temp("pending/exercise") || target[i]->query_temp("pending/respirate", 0))
		fail = dazuo_fail_msg[random(sizeof(dazuo_fail_msg))];
		
			//end

		tag = target[i]->query("married_times");
		if(tag > 20) tag = 20;
		music2 = (int)target[i]->query_skill("music",1);
		force2 = target[i]->query_skill("force");
		defender = target[i]->query("neili")/25 - tag*5 + random(force2) + music2;
		//打坐、吐纳时防御提高
		if(target[i]->query_temp("pending/exercise") || target[i]->query_temp("pending/respirate", 0)) 
		defender = target[i]->query("neili")/10 - tag*10 + random(force2) + music2;

		if(defender < 1) defender = 1;

		if( times/2 * 2 != times && target[i]->query("family/family_name") == "桃花岛" && music2 > music/2 ) {
			message_vision("$n尽知曲中诸般变化，与$N心神如一，自是不受危害。\n"NOR, me, target[i]);
			}
		else if( attacker < defender ) {
		
		map_force = target[i]->query_skill_mapped("force");
		if (!target[i]->query_skill_mapped("force")) map_force = "force";
			if(target[i]->query("race") != "人类" || times/2 * 2 == times )
			message_vision("", me, target[i]);
			else message_vision( replace_string( fail, "$f", to_chinese(map_force)) +"\n"NOR, me, target[i]);
			if (wizardp(me) && me->query("env/check_play"))
			tell_object(me,sprintf("attacker：%d ,defender：%d \n"
			,attacker,defender));
		}
		else {
			damage = force + music/3+ random(music/2)*flag + random(tag*10) + (-(int)target[i]->query("max_neili") / 30) + -random(force2/2) + -force2/3;
			if( damage > 600+flag*200 ) damage = 600+flag*200; // most ppl have at most 1k+ jing
			if( damage < 100 ) damage = 100;

			damage = damage + me->query_temp("playing_bihai")*8;
			
			if (wizardp(me) && me->query("env/check_play"))
			tell_object(me,sprintf("attacker：%d ,defender：%d ,damage：%d \n"
			,attacker,defender,damage));

			if( damage > 0 ) {
			target[i]->receive_damage("jing", damage, me);

			target[i]->add("jingli", -damage, me);
			target[i]->add("neili",-damage);
			target[i]->add_temp("be_played/"+me->query("id"),1);
			target[i]->start_busy(1);

			if (!target[i]->is_killing(me->query("id")) || !target[i]->is_fighting(me) || !me->is_fighting(target[i]))
			target[i]->kill_ob(me);

			//target[i]->set_temp("last_damage_from",me);
			//不同曲调伤害不同
			if(!me->query_temp("playing_bihai")) 
			target[i]->receive_damage("jing", random(damage/3 + tag*5), me);
			else target[i]->add("neili",-random(damage/2));
			//
			if( target[i]->query("neili") < 0)
				target[i]->set("neili",0);

			if((target[i]->query("jing") < 0 || target[i]->query("jingli") < 0 )
			&& target[i]->query("race") == "人类") 
			message_vision( faint+"\n"NOR, me, target[i]);
			else if((target[i]->query("jing") < 0 || target[i]->query("jingli") < 0 ) && target[i]->query("race") != "人类")
			message_vision("只见$n昂起了头，随着箫声摇头摆脑的舞动。\n"NOR, me, target[i]);
			else if(times/2 * 2 == times)
			message_vision("", me, target[i]);
			else if(target[i]->query("race") != "人类")
			message_vision("只见$n昂起了头，随着箫声摇头摆脑的舞动。\n"NOR, me, target[i]);
			else message_vision( succeed +"\n"NOR, me, target[i]);
			}
			}
		}
		//play效果计算到这

		if (wizardp(me) && me->query("env/check_play"))
			tell_object(me,sprintf("times：%d\n" ,times));

		if(me->query_temp("playing_bihai")) me->add_temp("playing_bihai",1); 
		me->add("neili", -100);
		env->set("playing", me);
		call_out("playing", 1, me);
		return;
	}
}

int halt_play()
{
	object me;
	me = this_player();
	if(me->query_temp("exercise/playing")) {
	message_vision(CYN"箫声忽停，四下阒无声息，一音袅袅，曲终音歇。\n"NOR, me);
	me->delete_temp("apply/short");
	me->set_temp("delete/playing");
	me->delete_temp("played_times");
	me->delete_temp("playing_bihai");
	me->delete_temp("exercise/playing");
	remove_call_out("playing");
	return 1;
	}
	else return 0;
}

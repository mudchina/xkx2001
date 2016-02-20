//Cracked by Roath
// “滑不留手”游迅，找宝物用npc
// by maco 

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
#include "/d/REGIONS.h";

string* homes = ({
        "/d/city/guangchang",
        "/d/quanzhou/zhongxin",
        "/d/wudang/shanmen",
        "/d/shaolin/guangchang1",
        "/d/taishan/fengchan",
        "/d/taishan/huima",
        "/d/village/square",
        "/d/xingxiu/tianroad3",
        "/d/emei/baoguomen",
        "/d/emei/xixiang",
        "/d/qilian/qilian",
        "/d/dali/taihejie2",
        "/d/xixia/square",
});


void create()
{
        set_name("游迅", ({ "you xun", "you","xun" }) );
        set("long", "这人身穿茧绸长袍，头顶半秃，一部黑须，肥肥胖胖，满脸红光，\n神情十分和蔼可亲，衣饰华贵，是个富商模样。\n");
	set("nickname", "滑不留手");
        set("gender", "男性");
        set("age", 48);
        set("attitude", "friendly");
        set("str", 16);
        set("int", 26);
        set("con", 18);
        set("dex", 30);
        set("max_qi", 500);
        set("max_jing", 300);
	set("max_jingli", 600);
	set("jingli", 600);
        set("neili", 400);
        set("max_neili", 400);
        set("combat_exp", 100000);
	set("no_get","这伙号称滑不留手，你怎能抓他得住？");
	set("special_npc",1);
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set_skill("dodge", 100); 
	set_skill("force", 60);
	set_skill("parry", 60);
	set_skill("unarmed", 100);

        set("inquiry", ([
                "油浸泥鳅" : "这是江湖上朋友抬爱，称赞兄弟的轻功造诣不差，好像泥鳅一般敏捷，其实惭愧得紧，这一点微末功夫，实在不足挂齿。",
		"滑不留手" : "兄弟有个难听的外号，叫作“滑不留手”。大家说兄弟爱结交朋友，为了朋友，兄弟是千金立尽，毫不吝惜，虽然赚得钱多，金银却是在手里留不住的。" ,
		"rumors" : "常言道得好，宝剑赠烈士，红粉赠佳人，好消息嘛，自当卖给财主。兄弟所卖的不是关子，而是消息，给一百两金子，我便说给你听。" ,
		"消息" : "兄弟武功平平，消息却十分灵通。江湖上有甚么秘密讯息，要瞒过兄弟的千里眼、顺风耳，可不大容易。" ,
		"讯息" : "兄弟武功平平，消息却十分灵通。江湖上有甚么秘密讯息，要瞒过兄弟的千里眼、顺风耳，可不大容易。" ,
		"辟邪剑谱" : "啊哟，你也在争《辟邪剑谱》？据我所知，这剑谱可不在余观主手中啊。",
		"gold" : "各位知道兄弟的外号叫作「滑不留手」，钱财左手来，右手去，这几天实在穷得要命。各位都是大财主，拔一根寒毛，也比兄弟的腿子粗。",
		"岳不群" : "最近岳先生一剑刺瞎一十五名强敌，当真名震江湖，小人佩服得五体投地。好剑法！好剑法！",
		"令狐冲" : "兄弟从东方来，听得不少江湖朋友提到令狐公子的大名，心下好生仰慕。" ,
		"令狐" : "兄弟从东方来，听得不少江湖朋友提到令狐公子的大名，心下好生仰慕。" ,
        ]) );

        setup();
        carry_object("/d/xiakedao/npc/obj/bluerobe")->wear();
}

void init()
{
        object ob;
        ::init();
	add_action("do_find","find");
}


int do_find(string arg)
{
        object *obs, *ppl, ob, where, fake, me = this_player();
        string region, baowu, env, putin;
	int i,k=0,exp = 0,kar;

        if( !living(this_object()) )
                return notify_fail("嗯....你得先把游迅弄醒再说。\n");

	if (!arg) return notify_fail("你想找什麽宝物？\n");
	
	if (me->query_temp("asked_youxun") && me->query_temp("find_gold")) 
		message_vision(CYN"$N不耐烦地朝游迅催问：快说，"+arg+"到底是在谁的手里？\n\n"NOR, me);
	else message_vision(CYN"$N朝游迅问道：现在江湖上，是谁得了"+arg+"？\n\n"NOR, me);
 
	switch(arg) {
		case "降魔杵": baowu = "/clone/weapon/xiangmo-chu.c"; break;
		case "倚天剑": baowu = "/clone/weapon/yitian-jian.c"; break;
		case "屠龙刀": baowu = "/clone/unique/tulong-dao.c"; break;
		case "玉箫": baowu = "/clone/unique/yuxiao.c"; break;
		case "打狗棒": baowu = "/clone/unique/yuzhu-zhang.c"; break;
		case "伏魔刀": baowu = "/clone/unique/fumo-dao.c"; break;
		case "金蛇剑": baowu = "/clone/unique/jinshe-jian.c"; break;
		case "鳄嘴剪": baowu = "/clone/unique/eyujian.c"; break;
		case "鳄尾鞭": baowu = "/clone/unique/eweibian.c"; break;
		case "玄铁剑":
		case "玄铁重剑": baowu = "/clone/unique/xuantie-jian.c"; break;
		case "七绝针": baowu = "/clone/weapon/qijue.c"; break;
		case "鱼肠剑": baowu = "/clone/unique/yuchang-jian.c"; break;
		case "真武剑": baowu = "/clone/unique/zhenwu.c"; break;
		case "重阳剑": baowu = "/clone/unique/cy-jian.c"; break;
		case "金刚罩": baowu = "/d/shaolin/obj/jingang-zhao.c"; break;
		case "乌蚕衣": baowu = "/d/xueshan/obj/wucan-yi.c"; break;
		case "软猬甲": baowu = "/d/taohua/obj/ruanwei-jia.c"; break;
		case "血刀": baowu = "/clone/unique/xuedao.c"; break;
		case "鸳刀": baowu = "/clone/unique/yuandao.c"; break;
		case "鸯刀": baowu = "/clone/unique/yangdao.c"; break;
		case "毒龙鞭": baowu = "/clone/unique/dulong-bian.c"; break;
		case "哭丧棒": baowu = "/clone/unique/kusang-bang.c"; break;
		case "七伤拳经": baowu = "/clone/unique/qs-jing.c"; break;
		case "神木王鼎": baowu = "/d/xingxiu/obj/muding.c"; break;
		case "神照经": baowu = "/d/city/npc/obj/shenzhao.c"; break;
		case "洛书": baowu = "/d/taohua/obj/luoshu"; break;
		case "河图": baowu = "/d/taohua/obj/hetu"; break;
		case "九阳神功残篇": baowu = "/kungfu/class/wudang/obj/canpian.c"; break;
		case "九阴真经": baowu = "/clone/unique/jiuyin_force_book.c"; break;
		case "金蛇密笈": 
		case "金蛇密籍": 
		case "金蛇秘籍": 
		case "金蛇秘笈": baowu = "/d/huashan/obj/jinshe_book2.c"; break;
		case "龙象般若经": baowu = "/d/xueshan/obj/lx-jing.c"; break;
		case "蓝玉钵": baowu = "/d/xingxiu/obj/yaobo.c"; break;
		case "白龙剑": baowu = "/clone/weapon/bailong-jian"; break;
		default: baowu = "none";	break;
		}


	if(baowu == "none" && !is_chinese(arg)){
	command("say 咦，这是外国玩意麽？兄弟可不知道了。");
	return 1;
	}
	
	if(baowu == "none"){
	command("say 哦，这是什麽宝贝？兄弟还真没听说过。");
	return 1;
	}

	ob = 0;
        obs = filter_array(children(baowu), (: clonep :));

        if (sizeof(obs) == 0){
	command("say 这个"+arg+"嘛，最近江湖上似乎没人见到过。");
	me->delete_temp("asked_youxun");
	return 1;
	}

        if (sizeof(obs) > 1 && wizardp(me)) 
        write("一共有"+chinese_number(sizeof(obs))+"个。\n");

        ob = obs[0];
	where = environment(ob);

	//if target put baowu in yaodai or budai, You Xun will know it
	if (!living(where) && living(environment(where))) {
	putin = where->name();
	where = environment(where);
	env = where->query("short");
	}
	else if (!living(where) ) {
	env = where->query("short");
	command("say 这个"+arg+"嘛，最近江湖上似乎没人见到过。");
		if (wizardp(me))
		write("游迅在你的耳边悄声说道：其实"+ob->name()+"是在"+env+"("+base_name(where)+")。\n");
	me->delete_temp("asked_youxun");
	return 1;
	}

	if (!me->query_temp("find_gold")) {
	command("walkby");
	message_vision(CYN"游迅笑嘻嘻的伸出手来，说道：给一百两金子，我便说给你听。\n"NOR, me);
	me->set_temp("asked_youxun",1);
	return 1;
	} 

	ppl = all_inventory(environment(me));
	for(i=0; i<sizeof(ppl); i++) {
		if( !living(ppl[i]) ) continue;
		k++;	}

	if( k > 2 ) {
	command("say 有外人在，这可不便说了。我要一百两金子，是每人一百两，可不是将这个大消息只卖一百两金子。如此大贱卖，世上焉有此理？");
	command("hehe you xun");
		return 1;
	}

	
	if (where->query("combat_exp") > 1000000 && 
	where->query("combat_exp") > me->query("combat_exp")*3/2 ) {
	command("say 好，我便说了，只不过"+RANK_D->query_respect(me)+"听在耳里，却是痒在心里，半点也无可奈何。那"+arg+"倘若为旁人所得，也还有几分指望，现下偏偏是在这一位主儿手中，那就……那就……咳咳，这个……");
	}
	ppl = users();
	for( i = 0; i < random(sizeof(ppl)+1); i++) {
		if( ppl[i]->query("combat_exp") > random(exp) 
		&& !wizardp(ppl[i])
		&& environment(ppl[i])
		&& strsrch(file_name(environment(ppl[i])), "/d/") >= 0) {
			fake = ppl[i];
			exp = fake->query("combat_exp");
		}
	}

		if(where == me) {
		command("say "+RANK_D->query_respect(me)+"自己心知肚明，难道真要兄弟抖出来麽？");
		command("hehe");
		command("escape");
		me->delete_temp("asked_youxun");
		me->delete_temp("find_gold");
		message_vision("游迅急急忙忙地离开了。\n", me);
		return move(load_object(homes[random(sizeof(homes))]));
//		destruct(this_object());
		}
		kar = me->query_kar()/3;
		if( kar > 10) kar = 10;
		if( kar < 2) kar = 2;
		
		if (random(kar) == 1) {
	//	env = fake->name()+"("+fake->query("id")+")"; //假讯息
		where = fake;
		}

		env = where->name(); 

	command("hehe");
	command("say 就告诉你吧，这"+arg+"呢，乃是落在"+env+"("+where->query("id")+")"+"手上。");
	if(putin) command("say 听说"+gender_pronoun(where->query("gender"))+"是把"+arg+"藏在个"+putin+"里面。");
	command("say 信不信由你，兄弟可要先走了。这话要是传到"+env+"耳里，定要找游某的麻烦。");
	message_vision("游迅急急忙忙地离开了。\n", me);
	me->delete_temp("asked_youxun");
	me->delete_temp("find_gold");
//	destruct(this_object());
	move(load_object(homes[random(sizeof(homes))]));

	me->start_busy(1);

	me->delete_temp("asked_youxun");
	me->delete_temp("find_gold");
	return 1;
}


int accept_object(object who, object ob)
{
        object me = this_player();
	if(me->query("combat_exp") < 10000)
		return notify_fail("你行走江湖的经验太少，十之八九会给游迅骗着，还是算了。\n");

        if (ob->query("money_id") && ob->value() >= 1000000 ) 
        {
                who->set_temp("find_gold",1);
		message_vision(CYN"\n游迅接过银子，在手中掂了掂，说道：这就多谢了。\n"NOR, me);
		command("rich you xun");
		write(YEL" (指令：find <宝物中文名称> )\n"NOR);
		return 1;
        }
        else if (ob->query("money_id") && ob->value() < 1000000) 
        {
		command("rich you xun");
		command("say 财源广进多多益善，来者不拒！");
                return 1;
        }

        return 0;
}


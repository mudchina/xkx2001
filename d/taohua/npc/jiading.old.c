//Cracked by Roath
//指认yapu_npc的家丁
//maco

inherit NPC;
#include <ansi.h>
int ask_yapu();

void create()
{
	set_name("家丁", ({ "jia ding", "ding" }));
	set("long", "一个二十出头的小伙子，身板结实，双目有神，似乎练过几年功夫。\n");
	set("gender", "男性");
	set("age", 25);

	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("stick", 30);
	set_skill("staff", 30);
	set_skill("sword", 30);
	set_skill("blade", 30);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("inquiry", ([
		"哑仆" : (:ask_yapu:),
		"yapu" : (:ask_yapu:),
	]));

	setup();
}

int start_check(object me)
{
		call_out("leave", 1200, me);
		call_out("check", 1, me);
}

void init()
{
	::init();

	add_action("do_recognize", "ren");
	add_action("do_recognize", "recognize");
	add_action("do_bring", "bring");
	add_action("do_bring", "dai");
	add_action("do_order", "order");

}
void leave(object me)
{
	string killer = me->query_temp("my_killer");
	object jiading = this_object();

	if (query("recognized") && objectp(present(me, environment(jiading)))) {
	command("addoil "+jiading->query("job_master"));
	call_out("leave", 60, me);
	}

	else if(objectp(present(me, environment(jiading)))){
	message_vision(CYN"$N说道：这麽久还捉不到那"+query("find_yapu_real")+"装成的"+query("find_yapu")+"，我看今天是逮不到他了，不如先回归云庄吧。\n"NOR,jiading);
	command("sigh");
	message_vision("$N快步离开了。\n"NOR,jiading);
	destruct(jiading);
	}

	else {
	message_vision("$N快步离开了。\n"NOR,jiading);
	destruct(jiading);
	}

	return;
}

void check(object me)
{
	string killer = me->query_temp("my_killer");
	object jiading = this_object();

	if(!me->query("find_yapu"))
	{
	command("bye "+me->query("id"));
	message_vision("$N快步离开了。\n"NOR,jiading);
	destruct(jiading);
	}

	else if(me->is_ghost() )
	{
	command("ah");
	command("cry corpse");
	command("grpfight "+me->query_temp("my_killer"));
	command("kill "+me->query_temp("my_killer"));
	}
	else call_out("check", 1, me);
}

int do_recognize(string arg)
{
	object me, ob, jiading, where, weapon, huwei;
	mapping skill_status;
	string *sname;
	int i ,num, level = 0, s_level, j, gain, exp, ob_exp, rate;

	me = this_player();
	exp = me->query("combat_exp");

	jiading = this_object();
	if( query("job_master") != me->query("id"))
		return 0;
	if( query("recognized"))
		return notify_fail("家丁已经指认出来对方了！\n");
	if( !living(jiading) )
		return notify_fail("嗯....你得先把家丁弄醒再说。\n");
	if( !arg )
		return notify_fail("你要家丁指认谁？\n");
	if(!objectp(ob = present(arg, environment(this_player()))))
		return notify_fail("这里没有这个人。\n");
	if(ob->query("th_victim"))
		return notify_fail(ob->name()+"已经被指认出来了！\n");
	if(ob == me)
		return notify_fail("指认你自己？有意义吗？\n");
	if(ob == jiading)
		return notify_fail("要家丁指认家丁？\n");
	if(ob->query("family/family_name") == "桃花岛")
		return notify_fail("你连桃花岛的人物也认不出来？\n");
	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着呢。\n");
	if( jiading->is_busy() || jiading->is_fighting() )
		return notify_fail( "家丁正忙着呢。\n");
	if(environment(me)->query("no_fight"))
		return notify_fail("这里不能战斗，认出来也没用。\n");


	me->start_busy(1);

	message_vision("$N低声在家丁耳边说道：是不是这个"+ob->name()+"？\n",me,ob);
	where = environment(ob);

	if (ob->query("yapu_target") == me->query("id") 
	&& ob->query("name") == query("find_yapu") )
	{
	if( !living(ob) )
	ob->revive();
	command("ah");
	command("points "+ob->query("id"));
	ob->interrupt_me();
	ob->set("real_face",1);
	set("recognized",1);

	//yapu_npc的身分改换
	{
	ob->set("long",ob->query("real_long"));
	if(ob->query("real_title"))
	ob->set("title",ob->query("real_title"));
	ob->clear_condition();
	ob->set("shen_type", -1);
	
	if ( mapp(skill_status = me->query_skills()) ) {
		skill_status = me->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( skill_status[sname[i]] > level ) level = skill_status[sname[i]];
		}
		
		level = (int)level*3/4 + 1;
		s_level = (int)level*11/10;

		rate = random(3)+9;

		ob->set("combat_exp", exp*rate/10 + random(exp/100) );
		ob_exp = ob->query("combat_exp");

		ob->set("th_victim", me->query("id"));
		//此npc的reward
		
		ob->set("gain", 50 + level);
		gain = ob->query("gain");
		
		if(exp <  100000) //100k
			gain = gain + random(level/2);
		else if(exp <  500000) //500k
			gain = gain + random(level/3);
		else if(exp < 1000000) //1m
			gain = gain + random(level/4);
		else if(exp < 3000000) //3m
			gain = gain + random(level/5);
		else gain = gain + random(level/8);
		
		ob->set("gain_exp", gain);
		ob->set("gain_pot", gain/4 +random(gain/10));
		ob->set("shen",-ob_exp/10);
		
		if(ob_exp < 1000000) {
		ob->add("gain_exp", random(5)+10);
		ob->add("gain_pot", random(5)+1);
		}
		else if(ob_exp < 2000000) {
		ob->add("gain_exp", random(5)+15);
		ob->add("gain_pot", random(5)+5);
		}
		else if(ob_exp < 3000000) {
		ob->add("gain_exp", random(5)+20);
		ob->add("gain_pot", random(5)+10);
		}
		else {
		ob->add("gain_exp", random(5)+25);
		ob->add("gain_pot", random(5)+15);
		}


		ob->set("max_qi", me->query("max_qi")*9/10);
		ob->set("eff_qi", me->query("max_qi")*9/10);
		ob->set("max_jing", me->query("max_jing")*9/10);
		ob->set("eff_jing", me->query("max_jing")*9/10);
		ob->set("qi", ob->query("max_qi"));
		ob->set("jing", ob->query("max_jing")*9/10);
		ob->set("jiali", me->query("jiali")/2);
		if ( me->query("max_neili") > 0 ) {
			ob->set("max_neili", level*20);
		}
		else ob->set("max_neili", 500);
		
		if ( me->query("max_jingli") > 0 ) {
			ob->set("max_jingli", me->query("max_jingli")*9/10);
		}
		else ob->set("max_jingli", 500);
		ob->set("neili", ob->query("max_neili"));
		ob->set("jingli", ob->query("max_jingli"));
		ob->set("no_sing", 1);
		ob->set_skill("dodge", level);
		ob->set_skill("parry", level );
		ob->set_skill("force", level);
		
	switch (ob->query("real_menpai")) {
	case "huashan" :
	ob->set_name("大盗", ({"da dao", "dao" ,"robber"}) );
	ob->set_skill("blade", s_level);
	ob->set_skill("sword", s_level);
	ob->set_skill("cuff", s_level);
	ob->set_skill("strike", s_level);
	ob->set_skill("huashan-jianfa", level);
	ob->set_skill("liangyi-dao", level);
	ob->set_skill("ding-dodge", s_level);
	ob->set_skill("zixia-gong", level);
	ob->set_skill("pishi-poyu", level);
	ob->set_skill("hunyuan-zhang", level);
	ob->set_skill("ziyin-yin", level);
	ob->set_skill("zhengqi-jue", level);

	ob->map_skill("force", "zixia-gong");
	ob->map_skill("dodge", "ding-dodge");
	ob->map_skill("parry", "huashan-jianfa");
	ob->map_skill("strike", "hunyuan-zhang");
	ob->map_skill("cuff", "pishi-poyu");
	ob->map_skill("sword", "huashan-jianfa");
	ob->map_skill("blade", "liangyi-dao");
	ob->prepare_skill("cuff", "pishi-poyu");
	ob->prepare_skill("strike", "hunyuan-zhang");
	ob->set("real_message", HIR"小贩脸色一变，喝道："+RANK_D->query_rude(me)+"原来是黄老邪门下？想捉"+RANK_D->query_self_rude(ob)+"，可没那麽容易！\n"NOR);
	ob->add("gain_exp", random(10)+30);
	ob->add("gain_pot", random(5)+20);
	ob->add_money("silver", 20+random(31));
	if(random(3) == 1)  weapon=new("/clone/weapon/gangdao");
	else if(random(3) == 1) weapon=new("/clone/weapon/changjian");
	
		break;
		
	case "dajin" :
	ob->set_name("杀手", ({"shashou", "shou", "killer"}) );
	ob->set_skill("sword", s_level);
	ob->set_skill("cuff", s_level);
	ob->set_skill("taiji-shengong", s_level);
	ob->set_skill("taiji-jian", s_level);
	ob->set_skill("tiyunzong", level);
	ob->set_skill("taiji-quan", s_level);
	ob->set_skill("taoism", level);
	ob->set_skill("literate", level);
	ob->map_skill("force", "taiji-shengong");
	ob->map_skill("parry", "taiji-jian");
	ob->map_skill("cuff", "taiji-quan");
	ob->map_skill("dodge", "tiyunzong");
	ob->map_skill("sword", "taiji-jian");
	ob->prepare_skill("cuff", "taiji-quan");
	ob->set("real_message", HIR"书生冷笑一声，道："+RANK_D->query_rude(me)+"，特地前来送死吗？\n"NOR);
	ob->set("jiali", 0);
	ob->set("str", 27+random(4));
	ob->carry_object("/clone/anqi/feibiao")->set_amount(2+random(3));
	if(random(3) != 0) weapon=new("/clone/weapon/changjian");
		break;
		
	case "tiezhang" :
	ob->set_name("恶霸", ({"e ba", "ba"}) );
	ob->set_skill("strike", s_level+20);
	ob->set_skill("blade", s_level);
	ob->set_skill("taixuan-gong", level);
	ob->set_skill("tie-zhang", s_level+20);
	ob->set_skill("ding-dodge", s_level);
	ob->set_skill("wuhu-duanmen", s_level);
	ob->map_skill("blade","wuhu-duanmen");
	ob->map_skill("dodge","ding-dodge");
	ob->map_skill("strike","tie-zhang");
	ob->map_skill("force", "taixuan-gong");
	ob->map_skill("parry", "tie-zhang");
	ob->prepare_skill("strike", "tie-zhang");
	ob->add("gain_exp", -20);
	ob->add("gain_pot", -20);
	ob->set("real_message", HIR"趟子手吃了一惊，脸上陡现杀气，朝$N冲了过来！\n"NOR);
		break;
		
	case "shaolin" :
	ob->set_name("破戒僧", ({"pojie seng", "seng"}) );
	ob->set_skill("blade", s_level);
	ob->set_skill("sword", s_level);
	ob->set_skill("club", s_level);

	ob->set_skill("buddhism", level);
	ob->set_skill("damo-jian", s_level);
	ob->set_skill("xiuluo-dao", s_level);
	ob->set_skill("zui-gun", s_level);
	ob->set_skill("jingang-quan", s_level);
	ob->set_skill("shaolin-shenfa", level);
	ob->set_skill("hunyuan-yiqi", level);
	ob->set_skill("yizhi-chan", level);
	ob->set_skill("banruo-zhang", level);
	ob->map_skill("force", "hunyuan-yiqi");
	ob->map_skill("dodge", "shaolin-shenfa");
	ob->map_skill("parry", "damo-jian");
	ob->map_skill("cuff","jingang-quan");
	ob->map_skill("sword", "damo-jian");
	ob->map_skill("blade", "xiuluo-dao");
	ob->map_skill("club", "zui-gun");
	ob->set("real_message", HIR"僧人脸色一变，狞笑道：好哇，你居然认出了"+RANK_D->query_self_rude(ob)+"来，需容你不得！\n"NOR);
		switch (random(3)) {
		case 0 :
			ob->set_skill("finger", s_level);
			ob->set_skill("yizhi-chan", s_level);
			ob->set_skill("strike", s_level);
			ob->set_skill("banruo-zhang", s_level);
			ob->map_skill("finger","yizhi-chan");
			ob->map_skill("strike","banruo-zhang");
			ob->prepare_skill("finger","yizhi-chan");
			ob->prepare_skill("strike","banruo-zhang");
			if(random(3) == 0) weapon=new("/d/shaolin/npc/obj/jiedao");
			break;
		case 1 :
			ob->set_skill("cuff", s_level);
			ob->set_skill("jingang-quan", s_level);
			ob->map_skill("cuff","jingang-quan");
			ob->prepare_skill("cuff","jingang-quan");
			if(random(3) == 0) {
			ob->apply_condition("drunk", ob->query("con") + ob->query("max_neili")/100 + 3);
			weapon=new("/d/shaolin/npc/obj/qimeigun");
				}
			break;
		case 2 :
			ob->set_skill("claw", s_level);
			ob->set_skill("longzhua-gong", s_level);
			ob->map_skill("claw","longzhua-gong");
			ob->prepare_skill("claw","longzhua-gong");
			break;
		}
		break;
		
	case "xiyu" :
	ob->set_name("蒙古武将", ({"menggu wujiang", "wujiang", "jiang"}) );
	ob->set("class", "officer");
	ob->set("dali/rank",3);
	ob->set("rank_info/rude", "狗鞑子");
	ob->set_skill("hamagong", s_level+10);
	ob->set_skill("lingshe-zhang", s_level);
	ob->set_skill("wuxingbu", s_level);
	ob->set_skill("luan-blade", s_level);
	ob->set_skill("blade", s_level);
	ob->set_skill("strike", s_level);
	ob->set_skill("parry", s_level);
	ob->set_skill("shentuo-zhang", s_level);
	ob->set_skill("lingshe-quan", s_level);

	ob->map_skill("force", "hamagong");
	ob->map_skill("blade", "luan-blade");
	ob->map_skill("dodge", "wuxingbu");
	ob->map_skill("parry", "luan-blade");
	
	ob->set("real_message", "");
	message_vision(HIR"胡人双眼一噔，冷笑道：就凭你这"+RANK_D->query_rude(me)+"，也想跟"+RANK_D->query_self_rude(ob)+"作对？\n"NOR, me, ob);

	{
	num = 1+random(3);
	message_vision(HIR"胡人拍了拍手，身後突然跃出"+chinese_number(num)+"个铁甲护卫，"+chinese_number(num+1)+"人向$N左右包抄！\n"NOR, me, ob);
		    for (i=0; i<num; i++) {
		huwei = new("/d/taohua/npc/mg_huwei");
		huwei->set("combat_exp", exp/2 + random(exp/1000) );
		huwei->set("rank_info/rude", "狗鞑子");
		huwei->set("max_qi", ob->query("max_qi")/2);
		huwei->set("eff_qi", ob->query("max_qi")/2);
		huwei->set("max_jing", ob->query("max_jing")/2);
		huwei->set("eff_jing", ob->query("max_jing")/2);
		huwei->set("qi", huwei->query("max_qi"));
		huwei->set("jing", huwei->query("max_jing"));
		huwei->set("jiali", ob->query("jiali")/2);
		huwei->set("max_neili", ob->query("max_neili")/2);
		huwei->set("max_jingli", ob->query("max_jingli")/2);
		huwei->set("neili", huwei->query("max_neili"));
		huwei->set("jingli", huwei->query("max_jingli"));

		huwei->set_skill("ding-force", level*3/4);
		huwei->set_skill("san-sword", level*3/4);
		huwei->set_skill("ding-dodge", level*3/4);
		huwei->set_skill("luan-blade", level*3/4);
		huwei->set_skill("wrestling", level*3/4);
		huwei->set_skill("hand", level*3/4);
		huwei->set_skill("force", level*3/4);
		huwei->set_skill("parry", level*3/4);
		huwei->set_skill("dodge", level*3/4);
		huwei->set_skill("sword", level*3/4);

		huwei->map_skill("force", "ding-force");
		huwei->map_skill("sword", "san-sword");
		huwei->map_skill("dodge", "ding-dodge");
		huwei->map_skill("parry", "san-sword");
		huwei->map_skill("hand", "wrestling");
		huwei->prepare_skill("hand", "wrestling");

		huwei->move(environment(me));
		
		huwei->kill_ob(me);
		huwei->start_check(ob);
		huwei->set_leader(ob);
		me->fight_ob(huwei);
		ob->add("gain_exp", random(10)+20);
		ob->add("gain_pot", random(5)+5);
		}
	}
	ob->add_money("silver", 20+random(31));
	if(ob->query_temp("armor/cloth"))
	destruct(ob->query_temp("armor/cloth"));
	ob->carry_object("/clone/armor/tiejia")->wear();
	if(random(3) == 0) weapon=new("/clone/weapon/gangdao");
	if(random(me->query("combat_exp")) > 2000000) {
	ob->map_skill("strike", "hamagong");
	ob->prepare_skill("strike", "hamagong");
	ob->add("gain_exp", random(10)+40);
	ob->add("gain_pot", random(5)+10);
	}
	else {
	ob->map_skill("cuff","lingshe-quan");
	ob->map_skill("strike","shentuo-zhang");
	ob->prepare_skill("cuff","lingshe-quan");
	ob->prepare_skill("strike","shentuo-zhang");
	}

		break;
		
	case "mizong" :
	ob->set_name("护法喇嘛", ({"hufa lama", "hufa", "lama"}) );
	ob->set("class", "lama");
	ob->set_skill("longxiang-banruo", level);
	ob->set_skill("shenkongxing", level);
	ob->set_skill("huoyan-dao", s_level);
	ob->set_skill("yujiamu-quan", level);
	ob->set_skill("dashou-yin", s_level);
	ob->set_skill("lamaism", level);
	ob->set_skill("xue-dao", s_level);
	ob->set_skill("mingwang-jian", s_level);
	ob->set_skill("jingang-chu", level);
	ob->set_skill("staff", level);
	ob->set_skill("sword", s_level);
	ob->set_skill("blade", s_level);
	ob->set_skill("cuff", s_level);
	ob->set_skill("hand", s_level);
	ob->set_skill("strike", s_level);
	ob->map_skill("force", "longxiang-banruo");
	ob->map_skill("dodge", "shenkongxing");
	ob->map_skill("parry", "xue-dao");
	ob->map_skill("blade", "xue-dao");
	ob->map_skill("sword", "mingwang-jian");
	ob->map_skill("staff", "jingang-chu");
	ob->set("real_message", HIR"穷汉见$N目光瞧来，脸上忽然变得狰狞可怖，叫道："+RANK_D->query_rude(me)+"是桃花岛来的？\n"NOR);
	
	if(ob->query_temp("armor/cloth"))
	destruct(ob->query_temp("armor/cloth"));
	
	ob->carry_object("/d/qilian/obj/lamajiasha")->wear();
	if(random(6) == 0) weapon=new("/clone/weapon/changjian");
	else if(random(5) == 1)	weapon=new("/d/xueshan/obj/miandao");
	else if(random(4) == 2) weapon=new("/d/xueshan/obj/fachu");

	if(random(me->query("combat_exp")) > 2000000) {
	ob->map_skill("strike", "huoyan-dao");
	ob->prepare_skill("strike", "huoyan-dao");
	ob->add("gain_exp", random(20)+50);
	ob->add("gain_pot", random(10)+20);
	}
	else {
	ob->map_skill("hand", "dashou-yin");
	ob->map_skill("cuff", "yujiamu-quan");
	ob->prepare_skill("hand", "dashou-yin");
	ob->prepare_skill("cuff", "yujiamu-quan");
	}
		break;
	case "miaojiang" :
	ob->set_name("苗疆巫女", ({"miaojiang wunu", "wunu", "nu"}) );
	ob->set_skill("claw", s_level);
	ob->set_skill("strike", s_level);
	ob->set_skill("huagong-dafa", level);
	ob->set_skill("zhaixinggong", level);
	ob->set_skill("chousui-zhang", s_level);
	ob->set_skill("sanyin-zhua", s_level);
	ob->set_skill("feixing-shu", s_level);
	ob->set_skill("poison", level);
	ob->set_skill("dodge", s_level);

	ob->map_skill("force", "huagong-dafa");
	ob->map_skill("strike", "chousui-zhang");
	ob->map_skill("claw", "sanyin-zhua");
	ob->map_skill("dodge", "zhaixinggong");
	ob->map_skill("parry", "sanyin-zhua");
	ob->prepare_skill("strike", "chousui-zhang");
	ob->prepare_skill("claw", "sanyin-zhua");

	ob->set("real_message", "");
	message_vision(HIR"女孩眼珠一转，微笑道：这位"+RANK_D->query_respect(me)+"，你该不是要捉我吧？那……我可要先下手。\n"NOR, me);
	
	ob->carry_object("/clone/drug/xxqingxin-san");
	ob->carry_object("/d/xingxiu/obj/lianxin");
	ob->carry_object("/d/xingxiu/obj/blzhen")->set_amount(1+random(3));

	if(ob->query_temp("armor/cloth"))
	destruct(ob->query_temp("armor/cloth"));
	ob->carry_object("/d/city/obj/jin_ao")->wear();
	//has poison,add reward
	ob->add("gain_exp", random(10)+30);
	ob->add("gain_pot", random(5)+10);

	if(random(me->query("combat_exp")) > 2000000 && ob->query_skill("strike") > 250 && ob->query("neili") > 1000 && random(2) == 1) {
	message_vision("$N把玉笛放到口边，轻轻一吹，只听一阵极尖极细的哨子声远远传了出去。\n", ob);
	message_vision(HIR"随着哨子声，玉笛里突然飞出蓝印印的一点火星，火星陡地熄灭，随即大亮，蓬的一声响，腾向半空，升起有丈许，这才缓缓降落。\n"NOR, me);
	new("/d/xingxiu/obj/flute_fire")->move(environment(me));
	ob->add("gain_exp", random(20)+50);
	ob->add("gain_pot", random(10)+30);
	}

		break;

	}
		if(weapon != 0) {
		weapon->move(ob);
		weapon->wield();
		}
		//设定完成
		message_vision(""+ob->query("real_message")+"", me, ob);
		ob->kill_ob(me);
		me->fight_ob(ob);

	}

	}
	//改换完成
	}
	else if (ob->query("name") == query("find_yapu"))
	{
	command("shake");
	command("say 打扮差不多，不过不是。");
	}

	else if (ob->query("race") != "人类" )
	{
	command("consider");
	command("say 就算那"+query("find_yapu_real")+"作恶多端，禽兽不如，好歹也还是个人哪……。");
	}

	else if (ob->query("gender") == "女性" && ob->query("per") >= 30 && ob->query("age") < 30)
	{
	message_vision("家丁呆呆地看著$n……\n",me,ob);
	command("shake");
	command("say 这位"+ RANK_D->query_respect(me) +"神仙一般的人物，怎麽会是那个"+query("find_yapu_real")+"？");
	}
	else if (ob->query("gender") == "男性" && ob->query("per") >= 30)
	{
	command("shake");
	command("say 这位"+ RANK_D->query_respect(me) +"仪表堂堂，岂是那"+query("find_yapu_real")+"可以比拟？");
	}
	else
	{
	command("shake");
	command("say 不是不是。");
	}
	return 1;

}

int do_bring(string arg)
{
	object me, ob, jiading, where, weapon;
	int yapu_exp, yapu_pot;
	string lu;
	me = this_player();
	jiading = this_object();

	if( query("job_master") != me->query("id"))
		return 0;
	if( !living(jiading) )
		return notify_fail("嗯....你得先把家丁弄醒再说。\n");
	if( !arg )
		return notify_fail("你要家丁带走谁？\n");
	if(!objectp(ob = present(arg, environment(this_player()))))
		return notify_fail("这里没有这个人。\n");
	if(ob == me)
		return notify_fail("带走自己？你到底在想什麽？\n");
	if(ob == jiading)
		return notify_fail("要家丁带走家丁？\n");
	if(ob->query("th_victim") != me->query("id"))
		return notify_fail("你无法确定"+ob->name()+"是不是你要捉的对象。\n");
	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着呢。\n");
	if( jiading->is_busy() || jiading->is_fighting() )
		return notify_fail( "家丁正忙着呢。\n");

	switch (me->query("family/master_name")) {
	case "黄药师" :
	lu = "我陆师兄";
	break;
	default:
	lu = "陆庄主";
	}

	yapu_exp = ob->query("gain_exp");
	yapu_pot = ob->query("gain_pot");

	if(yapu_exp > 500) yapu_exp = 500+random(40);
	if(yapu_pot > 250) yapu_exp = 240+random(30);

	if (arg == "corpse" && (ob = present(arg, environment(me))) 
	&& ob->query("yapu_fail") == me->query("id"))
	{
	command("shrug");
	command("say 怎麽把人打死了？……算了，还是先把它带回去交差吧。");
	message_vision("家丁将"+ob->name()+"扶了起来背在背上，走掉了。\n",me,ob);
	me->delete("find_yapu");
	me->apply_condition("th_yapu_fail", 5);
	destruct(ob);
	destruct(jiading);
	}
	else if(ob->query("th_victim") == me->query("id") && !living(ob)){
		message_vision(CYN"$N说道：把这"+ob->name()+"处理了！\n"NOR,me,ob);
		command("nod "+getuid(me));
		
		if(ob->query_temp("last_damage_from") == me && ob->query("age") < 20 && me->query("shen") > 1000 ) {
		message_vision(HIR"家丁掏出一把细长的铁柄小刀，扳开$n的嘴巴，正要斩去$n的舌头……\n"NOR,me,ob);
		message_vision(CYN"$N忽然说道：且慢！这"+ob->name()+"年纪尚轻，虽然误入歧途，但是未始不能改过。\n"NOR,me,ob);
		message_vision(CYN"$N说道：你先别动手，直接把$p带回归云庄，交给"+lu+"，由他处理便是。\n"NOR,me,ob);
		command("ok");
		me->add("th_exp",yapu_exp);
		me->add("th_pot",yapu_pot);
		me->set("th_help_yapu",1);
		}
		else if(ob->query_temp("last_damage_from") == me) {
		message_vision(HIR"家丁掏出一把细长的铁柄小刀，扳开$n的嘴巴，飞快地斩去了$n的舌头，跟着转过刀锋，在$p双耳各刺一刀，立时鲜血泉涌！\n"NOR,me,ob);
		message_vision(HIR"家丁收起小刀，取出一个瓷瓶，挑出伤药弹在$p断舌和双耳伤处，流血立缓，可是从此也已成聋哑之人。\n"NOR,me,ob);
		me->add("th_exp",yapu_exp);
		me->add("th_pot",yapu_pot);
		}
		else {
		command("say 虽然不是"+ RANK_D->query_respect(me) +"亲手摆平的，不过总算是逮到这"+RANK_D->query_rude(ob)+"了！");
		me->set_temp("not_me",1);
		//算成功，不过没reward。
		}
	command("say 我现在就把这"+RANK_D->query_rude(ob)+"带回归云庄上。");
	message_vision("家丁将"+ob->name()+"扶了起来背在背上，走掉了。\n",me,ob);
	me->set("th_yapu_ok",1);

		if(me->query_temp("not_me")) {
		tell_object(me,"此次工作本来可获得"+yapu_exp+"点桃花exp，"+yapu_pot+"点桃花pot，不过因为不是你自己完成的，所以不算。\n");
		log_file("test/yapu_job",
		sprintf("%s(%s) failed to get %d th_exp and %d th_pot from %s on %s\n", 
		me->name(), me->query("id"), yapu_exp, yapu_pot, ob->name(), ctime(time())));
		me->delete_temp("not_me");
		}
		else {
		tell_object(me,"此次工作获得"+yapu_exp+"点桃花exp，"+yapu_pot+"点桃花pot。\n");
		log_file("test/yapu_job",
		sprintf("%s(%s) got %d th_exp and %d th_pot from %s on %s\n", 
		me->name(), me->query("id"), yapu_exp, yapu_pot, ob->name(), ctime(time())));

		}
		if(me->query("th_exp")> 10000) {
		me->set("th_exp",10000);
		tell_object(me,"你的桃花经验已经达到10000点的满点，不能再累积了。\n");
		}

		if(me->query("th_pot")>me->query("max_potential")*10) {
		me->set("th_pot",me->query("max_potential")*10);
		tell_object(me,"你的桃花潜能已经达到"+(me->query("max_potential")*10)+"点的满点，不能再累积了。\n");
		}
		
	destruct(ob);
	destruct(jiading);
	}
	else tell_object(me,"你得先打昏"+ob->name()+"才行！\n");

	return 1;
}

string ask_yapu()
{
	object me;
	me = this_player();

	if( query("job_master") == me->query("id")) {
	return "我在"+query("yapu_region")+""+query("yapu_room")+CYN"见到那"+query("find_yapu_real")+"时，看来是个寻常"+query("find_yapu")+"模样。";	
	}
	else return 0;
}

int do_order(string arg)
{
	object me, jiading;
	me = this_player();
	jiading = this_object();

	if( query("job_master") != me->query("id")) return 0;
	
	if( !living(jiading) )
		return notify_fail("嗯....你得先把家丁弄醒再说。\n");
	if( me->is_busy() || me->is_fighting() )
		return notify_fail("你正忙着呢。\n");
	if( jiading->is_busy() || jiading->is_fighting() )
		return notify_fail( "家丁正忙着呢。\n");

	command("nod "+me->query("id"));
	if( arg == "follow" ) command("follow "+me->query("id"));
	if( arg == "stay" ) command("follow none");
}

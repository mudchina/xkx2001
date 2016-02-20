//Cracked by Roath
// hua-hegen.c 华赫艮

inherit NPC;

string ask_me();
void skill_set1(object, int);
void skill_set2(object, int);
void skill_set3(object, int);

void create()
{
	set_name("华赫艮", ({ "hua hegen", "hua"}));
    set("long", "华赫艮本名阿根，出身贫贱，现今大理国位列三公，未发迹时，干的却是盗墓掘坟的勾当。\n");
	set("title","大理国司徒");
    set("gender", "男性");
    set("age", 45);
    set("inquiry", ([
		"治安" : (: ask_me :),
		]));

	set_skill("claw", 150);
    set_skill("longzhua-gong", 160);
    set_skill("dodge", 145);
    set_skill("ding-dodge", 150);
    set_skill("parry", 140);
    set_skill("force", 140);
    set_skill("staff", 145);
	set_skill("fengmo-zhang",155);
	set_skill("ding-force",150);

    map_skill("claw","longzhua-gong");
    map_skill("dodge","ding-dodge");
	map_skill("force","ding-force");
	map_skill("parry","fengmo-zhang");
	map_skill("staff","fengmo-zhang");

	prepare_skill("claw","longzhua-gong");

    set("str", 40);
    set("int", 25);
    set("con", 25);
    set("dex", 25);

	set("max_qi", 1500);
	set("qi", 1500);
	set("max_jing", 1200);
	set("jing", 1200);
	set("max_neili", 2000);
	set("neili", 2000);
	set("max_jingli", 2000);
	set("jingli", 2000);
	set("jiali", 60);
	set("combat_exp", 700000);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set_temp("apply/armor", 60);
	set_temp("apply/dodge", 20);

	setup();
	carry_object("/d/dali/obj/zipao")->wear();	
	carry_object("/d/dali/obj/gangchan")->wield();
}

string ask_me()
{
	object ob,  weapon, room, who=this_object(), me=this_player();
	int exp, level, i, room_no;
	string areaname;

	exp=me->query("combat_exp");
	for (level=1;level*level*level<exp*10;level++) {}
        
	if (who->query_temp("job_offered"))
		return "我这里现在没什么要紧的事情，"+RANK_D->query_respect(me)+"请先回去休息吧。";
        
	if (!me->query("dali/employee"))
		return RANK_D->query_respect(me)+"和我大理素无瓜葛，何有此问啊？";

	if (environment(this_object())!=find_object("/d/dali/sangong3"))
		return "对不起，我只在府衙办理公务，等我回府去你再来问我吧。";

	if (me->query("dali/trust")<0
		|| (me->query("family/family_name") != "大理段家"
		&& me->query("combat_exp")>3000000)) {
		command("hmm "+me->query("id"));
		return "我这里现在没什么要紧的事情，"+RANK_D->query_respect(me)+"请先回去休息吧。";
	}

	if (me->query("combat_exp")<30000) {
		command("pat "+me->query("id"));
		command("say 大理境内强人都颇为凶悍，"+RANK_D->query_respect(me)+"功力不够，恐怕不能立功，反而危及自身性命。");
		return RANK_D->query_respect(me)+"还是先回去练好基本功再来吧。";
	}

	if (me->query_temp("dalijobon")) {
		return "你先把你手头的活干完吧";
		}
	
	if (me->query("mud_age") - me->query("dali/lastjob") < 120) {
		return "我这里现在没什么要紧的事情，"+RANK_D->query_respect(me)+"请先回去休息吧。";
		}

	me->set("dali/lastjob",me->query("mud_age"));
	me->set_temp("dalijobon",1);

	if (me->query("combat_exp")<500000) {
		ob = new("/d/dali/npc/dlbandit1");
		skill_set1(ob, level);
	}
	else {
		if (me->query("combat_exp")<1500000) {
			ob = new("/d/dali/npc/dlbandit2");
			skill_set2(ob, level);
		}
		else {
			ob = new("/d/dali/npc/dlbandit3");
			skill_set3(ob, level);
			}
		}

	ob->move(load_object("/d/dali/feiwo.c"));

	ob->set("combat_exp",(me->query("combat_exp")/100)*(150+random(51)));
	ob->set("shen",-ob->query("combat_exp")/10);
	ob->set("max_qi", me->query("max_qi")*(10+random(3))/10);
	ob->set("eff_qi", ob->query("max_qi"));
	ob->set("qi", ob->query("max_qi"));
	ob->set("max_jing", me->query("max_jing")*(10+random(3))/10);
	ob->set("eff_jing", ob->query("max_jing"));
	ob->set("jing", ob->query("max_jing"));
	ob->set("max_neili", me->query("max_neili")*(9+random(3))/15);
	ob->set("neili", ob->query("max_neili"));
	ob->set("jiali",ob->query("max_neili")/50);
	ob->set("max_jingli", me->query("max_jingli")*(10+random(3))/10);
	ob->set("jingli", ob->query("max_jingli"));

	i = random(9);
	switch (i) {
	case 0 :
		room_no=1+random(10);
		break;
	case 1 :
		room_no=11+random(10);
		break;
	case 2 :
		room_no=21+random(10);
		break;
	case 3 :
		room_no=31+random(10);
		break;
	case 4 :
		room_no=41+random(10);
		break;
	case 5 :
		room_no=51+random(10);
		break;
	case 6 :
		room_no=61+random(10);
		break;
	case 7 :
		room_no=71+random(10);
		break;
	case 8 :
		room_no=81+random(14);
		break;
	}
	room=load_object("/d/dali/minov"+room_no+".c");
	remove_call_out("moveto");
	call_out("moveto", 15+random(8), ob, room_no);

	set_temp("job_offered",1);
	remove_call_out("clearn_jo");
	call_out("clean_jo", 50, who);

	me->set("dali/lastjob", me->query("mud_age"));

	if (room->query("short")==room->query("area"))
	{
		command("say 在"+room->query("area")+"附近一带据报有"+ob->query("name")+"活动。");
	}
	else {
		switch (random(3))
		{
			case 0 :
				command("say "+room->query("area")+"左右"+room->query("short")+"有非法之徒异动。");
				break;
			case 1 :
				command("say 在"+room->query("area")+"附近一带据报有"+ob->query("name")+"活动。");
				break;
			case 2 :
				command("say 据报有"+ob->query("name")+"在"+room->query("area")+"地区活动。");
				break;
		}
	}
	return "你去那一带巡查巡查，发现有在逃的通缉要犯的，务必活捉送定安府。";
}

void moveto(object ob, int room_no)
{
	object room;
	room_no=room_no+random(5)-random(5);
	if (room_no > 94) room_no=94;
	if (room_no < 1) room_no=1;
	room=load_object("/d/dali/minov"+room_no+".c");
	ob->move(room);

	switch (random(3)) {
	case 0 :
		message("vision", "一个"+ob->query("name")+"不知从什么地方鬼鬼祟祟地钻了出来。\n", room, ob);
		break;
	case 1 :
		message("vision", "一个"+ob->query("name")+"大摇大摆地走了过来。\n", room, ob);
		break;
	case 2 :
		message("vision", "一个"+ob->query("name")+"杀气腾腾地从山上冲下来。\n", room, ob);
		break;
	}
	return;
}

void clean_jo(object ob)
{
	ob->delete_temp("job_offered");
	return;
}

void skill_set1(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "星宿派拍马手" :
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("staff", level-45-random(10));
		ob->set_skill("poison", level-60+random(5));
		ob->set_skill("huagong-dafa", level-45-random(10));
		ob->set_skill("zhaixinggong", level-40-random(10));
		ob->set_skill("tianshan-zhang", level-40-random(10));
		ob->map_skill("staff","tianshan-zhang");
		ob->map_skill("dodge","zhaixinggong");
		ob->map_skill("parry", "tianshan-zhang");
		ob->map_skill("force","huagong-dafa");
		switch (random(2)) {
		case 0 :
			ob->set_skill("claw", level-45-random(10));
			ob->set_skill("sanyin-zhua", level-40-random(10));
			map_skill("claw","sanyin-zhua");
			prepare_skill("claw","sanyin-zhua");
			break;
		case 1 :
			ob->set_skill("strike", level-45-random(10));
			ob->set_skill("chousui-zhang", level-40-random(10));
			map_skill("strike","chousui-zhang");
			prepare_skill("strike","chousui-zhang");
			break;
		}
		weapon=new("/d/xingxiu/obj/tiezhang.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "华山派弃徒" :
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("zixia-gong", level-45-random(10));
		ob->set_skill("huashan-shenfa", level-40-random(10));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		switch (random(1)) {
		case 0 :
			ob->set_skill("cuff", level-45-random(10));
			ob->set_skill("pishi-poyu", level-40-random(10));
			ob->map_skill("cuff","pishi-poyu");
			ob->prepare_skill("cuff","pishi-poyu");
			break;
		case 1 :
			ob->set_skill("strike", level-45-random(10));
			ob->set_skill("hunyuan-zhang", level-40-random(10));
			ob->map_skill("strike","hunyuan-zhang");
			ob->prepare_skill("strike","hunyuan-zhang");
			break;
		}
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-45-random(10));
			ob->set_skill("liangyi-dao", level-40-random(10));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-45-random(10));
			ob->set_skill("huashan-jianfa", level-40-random(10));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/changjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "武当派叛徒" :
		ob->set_skill("cuff", level-45-random(10));
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("sword", level-45-random(10));
		ob->set_skill("taiji-shengong", level-45-random(10));
		ob->set_skill("taiji-jian", level-40-random(10));
		ob->set_skill("taiji-quan", level-40-random(10));
		ob->set_skill("tiyunzong", level-40-random(10));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/changjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "雪山派小喇嘛" :
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("longxiang-banruo", level-45-random(10));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-40-random(10));
			ob->map_skill("dodge","shenkongxing");
			break;
		case 1 :
			ob->set_skill("xueshitiao", level-40-random(10));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		switch (random(2)) {
		case 0 :
			ob->set_skill("cuff", level-45-random(10));
			ob->set_skill("yujiamu-quan", level-40-random(10));
			ob->map_skill("cuff","yujiamu-quan");
			ob->prepare_skill("cuff","yujiamu-quan");
			break;
		case 1 :
			ob->set_skill("hand", level-45-random(10));
			ob->set_skill("dashou-yin", level-40-random(10));
			ob->map_skill("hand","dashou-yin");
			ob->prepare_skill("hand","dashou-yin");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-45-random(10));
			ob->set_skill("xue-dao", level-40-random(10));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-45-random(10));
			ob->set_skill("mingwang-jian", level-40-random(10));
			ob->map_skill("sword","mingwang-jian");
			ob->map_skill("parry","mingwang-jian");
			weapon=new("/d/city/obj/changjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("staff", level-45-random(10));
			ob->set_skill("jingang-chu", level-40-random(10));
			ob->map_skill("staff","jingang-chu");
			ob->map_skill("parry","jingang-chu");
			weapon=new("/d/xueshan/obj/fachu.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "丐帮恶贼" :
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("hand", level-45-random(10));
		ob->set_skill("huntian-qigong", level-45-random(10));
		ob->set_skill("xiaoyaoyou", level-45-random(10));
		ob->set_skill("shexing-diaoshou", level-45-random(10));
		ob->map_skill("dodge","xiaoyaoyou");
		ob->map_skill("force","huntian-qigong");
		ob->map_skill("hand","shexing-diaoshou");
		ob->prepare_skill("hand","shexing-diaoshou");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-45-random(10));
			ob->set_skill("liuhe-dao", level-45-random(10));
			ob->map_skill("blade","liuhe-dao");
			ob->map_skill("parry","liuhe-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("staff", level-45-random(10));
			ob->set_skill("fengmo-zhang", level-45-random(10));
			ob->map_skill("staff","fengmo-zhang");
			ob->map_skill("parry","fengmo-zhang");
			weapon=new("/d/xingxiu/obj/tiezhang.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "五毒教打手" :
		ob->set_skill("cuff", level-45-random(10));
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("sword", level-45-random(10));
		ob->set_skill("tangshi-jian", level-40-random(10));
		ob->set_skill("wuxing-quan", level-40-random(10));
		ob->set_skill("wuxingbu", level-40-random(10));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("sword","tangshi-jian");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "tangshi-jian");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/d/city/obj/changjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}

void skill_set2(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "西域少林恶僧" :
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("hunyuan-yiqi", level-45-random(10));
		ob->set_skill("shaolin-shenfa", level-40-random(10));
		ob->map_skill("dodge","shaolin-shenfa");
		ob->map_skill("force","hunyuan-yiqi");
		switch (random(3)) {
		case 0 :
			ob->set_skill("hand", level-45-random(10));
			ob->set_skill("fengyun-shou", level-40-random(10));
			ob->map_skill("hand","fengyun-shou");
			ob->prepare_skill("claw","fengyun-shou");
			break;
		case 1 :
			ob->set_skill("hand", level-45-random(10));
			ob->set_skill("qianye-shou", level-40-random(10));
			ob->map_skill("hand","qianye-shou");
			ob->prepare_skill("hand","qianye-shou");
			break;
		case 2 :
			ob->set_skill("cuff", level-45-random(10));
			ob->set_skill("luohan-quan", level-40-random(10));
			ob->map_skill("cuff","luohan-quan");
			ob->prepare_skill("cuff","luohan-quan");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-45-random(10));
			ob->set_skill("cibei-dao", level-40-random(10));
			ob->map_skill("blade","cibei-dao");
			ob->map_skill("parry","cibei-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("club", level-45-random(10));
			ob->set_skill("weituo-gun", level-40-random(10));
			ob->map_skill("club","weituo-gun");
			ob->map_skill("parry","weituo-gun");
			weapon=new("/clone/weapon/qimeigun.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("staff", level-45-random(10));
			ob->set_skill("pudu-zhang", level-40-random(10));
			ob->map_skill("staff","pudu-zhang");
			ob->map_skill("parry","pudu-zhang");
			weapon=new("/d/xingxiu/obj/tiezhang.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "华山派弃徒" :
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("zixia-gong", level-45-random(10));
		ob->set_skill("huashan-shenfa", level-40-random(10));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		switch (random(2)) {
		case 0 :
			ob->set_skill("cuff", level-45-random(10));
			ob->set_skill("pishi-poyu", level-40-random(10));
			ob->map_skill("cuff","pishi-poyu");
			ob->prepare_skill("cuff","pishi-poyu");
			break;
		case 1 :
			ob->set_skill("strike", level-45-random(10));
			ob->set_skill("hunyuan-zhang", level-40-random(10));
			ob->map_skill("strike","hunyuan-zhang");
			ob->prepare_skill("strike","hunyuan-zhang");
			break;
		}
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-45-random(10));
			ob->set_skill("liangyi-dao", level-40-random(10));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-45-random(10));
			ob->set_skill("huashan-jianfa", level-40-random(10));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/changjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "武当派叛徒" :
		ob->set_skill("cuff", level-45-random(10));
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("sword", level-45-random(10));
		ob->set_skill("taiji-shengong", level-45-random(10));
		ob->set_skill("taiji-jian", level-40-random(10));
		ob->set_skill("taiji-quan", level-40-random(10));
		ob->set_skill("tiyunzong", level-40-random(10));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/changjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "雪山派喇嘛" :
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("longxiang-banruo", level-45-random(10));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-40-random(10));
			ob->map_skill("dodge","shenkongxing");
			break;
			case 1 :
			ob->set_skill("xueshitiao", level-40-random(10));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		switch (random(1)) {
		case 0 :
			ob->set_skill("cuff", level-45-random(10));
			ob->set_skill("yujiamu-quan", level-40-random(10));
			ob->map_skill("cuff","yujiamu-quan");
			ob->prepare_skill("cuff","yujiamu-quan");
			break;
		case 1 :
			ob->set_skill("hand", level-45-random(10));
			ob->set_skill("dashou-yin", level-40-random(10));
			ob->map_skill("hand","dashou-yin");
			ob->prepare_skill("hand","dashou-yin");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-45-random(10));
			ob->set_skill("xue-dao", level-40-random(10));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-45-random(10));
			ob->set_skill("mingwang-jian", level-40-random(10));
			ob->map_skill("sword","mingwang-jian");
			ob->map_skill("parry","mingwang-jian");
			weapon=new("/d/city/obj/changjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("staff", level-45-random(10));
			ob->set_skill("jingang-chu", level-40-random(10));
			ob->map_skill("staff","jingang-chu");
			ob->map_skill("parry","jingang-chu");
			weapon=new("/d/xueshan/obj/fachu.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "五毒教香主" :
		ob->set_skill("cuff", level-45-random(10));
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("sword", level-45-random(10));
		ob->set_skill("tangshi-jian", level-40-random(10));
		ob->set_skill("wuxing-quan", level-40-random(10));
		ob->set_skill("wuxingbu", level-40-random(10));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("sword","tangshi-jian");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "tangshi-jian");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/d/city/obj/changjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}

void skill_set3(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "西域少林高僧" :
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("hunyuan-yiqi", level-45-random(10));
		ob->set_skill("shaolin-shenfa", level-40-random(10));
		ob->map_skill("dodge","shaolin-shenfa");
		ob->map_skill("force","hunyuan-yiqi");
		switch (random(3)) {
		case 0 :
			ob->set_skill("hand", level-45-random(10));
			ob->set_skill("fengyun-shou", level-40-random(10));
			ob->map_skill("hand","fengyun-shou");
			ob->prepare_skill("claw","fengyun-shou");
			break;
		case 1 :
			ob->set_skill("hand", level-45-random(10));
			ob->set_skill("qianye-shou", level-40-random(10));
			ob->map_skill("hand","qianye-shou");
			ob->prepare_skill("hand","qianye-shou");
			break;
		case 2 :
			ob->set_skill("cuff", level-45-random(10));
			ob->set_skill("luohan-quan", level-40-random(10));
			ob->map_skill("cuff","luohan-quan");
			ob->prepare_skill("cuff","luohan-quan");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-45-random(10));
			ob->set_skill("cibei-dao", level-40-random(10));
			ob->map_skill("blade","cibei-dao");
			ob->map_skill("parry","cibei-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("club", level-45-random(10));
			ob->set_skill("weituo-gun", level-40-random(10));
			ob->map_skill("club","weituo-gun");
			ob->map_skill("parry","weituo-gun");
			weapon=new("/clone/weapon/qimeigun.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("staff", level-45-random(10));
			ob->set_skill("pudu-zhang", level-40-random(10));
			ob->map_skill("staff","pudu-zhang");
			ob->map_skill("parry","pudu-zhang");
			weapon=new("/d/xingxiu/obj/tiezhang.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "华山派弃徒" :
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("zixia-gong", level-45-random(10));
		ob->set_skill("huashan-shenfa", level-40-random(10));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		switch (random(2)) {
		case 0 :
			ob->set_skill("cuff", level-45-random(10));
			ob->set_skill("pishi-poyu", level-40-random(10));
			ob->map_skill("cuff","pishi-poyu");
			ob->prepare_skill("cuff","pishi-poyu");
			break;
		case 1 :
			ob->set_skill("strike", level-45-random(10));
			ob->set_skill("hunyuan-zhang", level-40-random(10));
			ob->map_skill("strike","hunyuan-zhang");
			ob->prepare_skill("strike","hunyuan-zhang");
			break;
		}
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-45-random(10));
			ob->set_skill("liangyi-dao", level-40-random(10));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-45-random(10));
			ob->set_skill("huashan-jianfa", level-40-random(10));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/changjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "武当派叛徒" :
		ob->set_skill("cuff", level-45-random(10));
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("sword", level-45-random(10));
		ob->set_skill("taiji-shengong", level-45-random(10));
		ob->set_skill("taiji-jian", level-40-random(10));
		ob->set_skill("taiji-quan", level-40-random(10));
		ob->set_skill("tiyunzong", level-40-random(10));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/changjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "雪山派喇嘛" :
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-45-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("longxiang-banruo", level-45-random(10));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-40-random(10));
			ob->map_skill("dodge","shenkongxing");
			break;
			case 1 :
			ob->set_skill("xueshitiao", level-40-random(10));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		switch (random(2)) {
		case 0 :
			ob->set_skill("cuff", level-45-random(10));
			ob->set_skill("yujiamu-quan", level-40-random(10));
			ob->map_skill("cuff","yujiamu-quan");
			ob->prepare_skill("cuff","yujiamu-quan");
			break;
		case 1 :
			ob->set_skill("hand", level-45-random(10));
			ob->set_skill("dashou-yin", level-40-random(10));
			ob->map_skill("hand","dashou-yin");
			ob->prepare_skill("hand","dashou-yin");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-45-random(10));
			ob->set_skill("xue-dao", level-40-random(10));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-45-random(10));
			ob->set_skill("mingwang-jian", level-40-random(10));
			ob->map_skill("sword","mingwang-jian");
			ob->map_skill("parry","mingwang-jian");
			weapon=new("/d/city/obj/changjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("staff", level-45-random(10));
			ob->set_skill("jingang-chu", level-40-random(10));
			ob->map_skill("staff","jingang-chu");
			ob->map_skill("parry","jingang-chu");
			weapon=new("/d/xueshan/obj/fachu.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "五毒教堂主" :
		ob->set_skill("cuff", level-45-random(10));
		ob->set_skill("dodge", level-45-random(10));
		ob->set_skill("force", level-random(10));
		ob->set_skill("parry", level-45-random(10));
		ob->set_skill("sword", level-45-random(10));
		ob->set_skill("tangshi-jian", level-40-random(10));
		ob->set_skill("wuxing-quan", level-40-random(10));
		ob->set_skill("wuxingbu", level-40-random(10));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("sword","tangshi-jian");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "tangshi-jian");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/d/city/obj/changjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}

#include "/kungfu/class/dali/sangong.h"

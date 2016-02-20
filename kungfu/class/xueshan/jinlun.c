//Cracked by Roath
// Summer 9/26/1996.

inherit NPC;

string ask_me();

void create()
{
	set_name("金轮法王", ({ "jinlun fawang", "jinlun", "fawang" }));
//	set("nickname", "蒙古国师");
	set("long", 
"一个中年番僧，身形极高极瘦，婉如一跟长竹杆。脑门微陷，由如一个碟子。\n"
"他就是当今蒙古国护国法王。\n");
	set("title", "蒙古国师");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("class","lama");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 3500);
	set("max_jing", 3500);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 100);
	set("combat_exp", 3600000);
	set("score", 5000);
	set("inquiry", ([
		"金轮" : (: ask_me:),
        ]) );
	set("lun_count", 1);
	set_temp("apply/armor", 100);

	set_skill("force", 360);
	set_skill("dodge", 360);
	set_skill("parry", 360);
	set_skill("hammer", 360);
	set_skill("cuff", 300);
	set_skill("lamaism", 360);
	set_skill("hand", 300);
	set_skill("riyue-lun", 400);
	set_skill("shenkongxing", 400);
	set_skill("longxiang-banruo", 360);
	set_skill("jingang-chu", 360);
	set_skill("staff", 320);
	set_skill("necromancy", 360);
	set_skill("dashou-yin", 360);

	map_skill("force", "longxiang-banruo");
	map_skill("parry", "riyue-lun");
	map_skill("hammer", "riyue-lun");
	map_skill("dodge", "shenkongxing");
	map_skill("staff", "jingang-chu");
	map_skill("hand", "dashou-yin");
	
	prepare_skill("hand", "dashou-yin");

	create_family("雪山派", 9, "法王" );

	setup();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
	carry_object("/clone/weapon/falun")->set_amount(4);
	carry_object("/clone/weapon/falun")->wield();
}
void attempt_apprentice(object ob)
{
	if( ob->query("family/family_name") != "雪山派"
        && ob->query("family/family_name") != "血刀门"
        && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "是"
                +ob->query("family/family_name")+"高手，本派可不敢收留！");
                return;
        }

	if ((int)ob->query_skill("longxiang-banruo", 1) < 60
	&& (int)ob->query_skill("xiaowuxiang", 1) < 60) {
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在龙象般若功上多下点功夫？");
		return;
	}
	if ((int)ob->query("jlfw") < 1){
		command("say " + RANK_D->query_respect(ob) +
                        "先去把我徒弟达尔巴打败，再来拜我吧。");
	return;
	}
        command("recruit " + ob->query("id"));
	command("say 那贫僧就收下你吧。");
}
string ask_me()
{
        object ob, me = this_player();
                return "这东西我花了一千两金子才打出来，可不能给你玩。";
/*	if (me->query("family/master_id") != "jinlun fawang" ) 
		return "你先拜我为师吧。";
        add("lun_count", -1);
        command ("give lun to "+ me->query("id"));
        return "好！你拿去玩，可千万别给我弄丢了。";
*/
}


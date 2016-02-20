//Cracked by Roath
// azi.c 阿紫
#include "/kungfu/class/xingxiu/auto_perform.h"
inherit NPC;
inherit F_MASTER;
int do_incense();
int auto_perform();
void create()
{
	set_name("阿紫", ({ "azi" }));
	set("nickname", "星宿派小师妹");
	set("long", 
		"她就是丁春秋弟子阿紫。\n"
		"她容颜俏丽，可眼神中总是透出一股邪气。\n");
	set("gender", "女性");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 18);
	set("int", 28);
	set("con", 20);
	set("dex", 24);
	
	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 10);
	set("combat_exp", 50000);
	set("score", 10000);
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
	set("inquiry", ([
                "香" : (: do_incense :),
                "香料" : (: do_incense :),
        ]) );


	set_skill("force", 40);
  	set_skill("huagong-dafa", 25);
	set_skill("dodge", 30);
	set_skill("feixing-shu", 60);
	set_skill("poison", 40);
	set_skill("zhaixinggong", 40);
	set_skill("claw", 40);
	set_skill("sanyin-zhua", 40);
	set_skill("strike", 30);
	set_skill("chousui-zhang", 40);
	set_skill("parry", 20);
	set_skill("staff", 20);
  	set_skill("literate", 30);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-zhua");
	map_skill("parry", "chousui-zhang");

	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-zhua");

	create_family("星宿派", 2, "弟子");

	setup();
	carry_object("/d/xingxiu/obj/xxqingxin-san");
	carry_object("/d/xingxiu/obj/yellow-cloth")->wear();
	carry_object("/d/xingxiu/obj/blzhen");
	carry_object("/d/xingxiu/obj/lianxin");
}

void attempt_apprentice(object me)
{
	if( me->query("family/family_name") == "丐帮"
        && me->query("combat_exp") >= 10000 ) {
		command ("say 我们老仙最恨叫化子，我可不敢收你。");
                return;
	}
	command("say 好吧，我就收下你了。");
	command("recruit " + me->query("id"));
}
int do_incense()
{
	if( this_player()->query("family/family_name") != "星宿派"){
        say("阿紫哼了一声说：这东西可不是给你用的。\n");
        return 1;
        }
	if (this_player()->query("marks") == "毒蛛丝"||
	this_player()->query("marks") == "毒蛇胆"||
	this_player()->query("marks") == "蜈蚣蚣"||
	this_player()->query("marks") == "沙虫壳"||
	this_player()->query("marks") == "蝎子壳") {
	say("阿紫不耐烦地说道：我不是叫你去找" +this_player()->query("marks")
	+ "了吗？东西找来就给你。\n");
	return 1;
	}
	switch( random(5) )
        {
	
            case 0:
	say("阿紫脸上露出一丝微笑，说道：你给我找十个蛇胆来，我就给你。\n");
	this_player()->set("marks", "毒蛇胆");
	break;
	case 1:
	say("阿紫脸上露出一丝微笑，说道：你给我找五个蜈蚣壳来，我就给你。\n");
        this_player()->set("marks", "蜈蚣壳");
        break;
        case 2:
	say("阿紫脸上露出一丝微笑，说道：你给我找五个蝎子壳来，我就给你。\n");
        this_player()->set("marks", "蝎子壳");
        break;
        case 3:
	say("阿紫脸上露出一丝微笑，说道：你给我找三个沙虫壳来，我就给你。\n");
        this_player()->set("marks", "沙虫壳");
        break;
        case 4:
	say("阿紫脸上露出一丝微笑，说道：你给我找三卷毒蛛丝来，我就给你。\n");
        this_player()->set("marks", "毒蛛丝");
        break;
	}
	return 1;
}
int accept_object(object who, object ob)
{
	object obj;

	if ( userp(ob) ) {
	command("grin");
	command("say 这人正好用来练功。干得好！");
	message_vision("$N说着运起腐尸毒一掌拍向$n的胸口。\n", this_object(), ob);
	ob->receive_wound("qi", ob->query("max_qi")+100, "被阿紫杀死了");
	return 1;
	}
	if ((string)ob->query("name")=="毒蛛丝" &&
        this_player()->query("marks") == "毒蛛丝"
		&&!userp(ob)) {
	command( "hehe");
	this_player()->add("azi", 1);
        call_out("destroy_it", 1, ob);
	if( (int)this_player()->query("azi")>=3){
	command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
	command( "say 这枝香好好拿去用吧。");
	obj = new("/d/xingxiu/obj/incense");
	obj->move(this_player());
	this_player()->delete("azi");
	this_player()->delete("marks"); 
	}
	return 1;
    }
	if ((string)ob->query("name")=="毒蛇胆" &&
        this_player()->query("marks") == "毒蛇胆" 
		&&!userp(ob)) {
        command( "hehe");
        this_player()->add("azi", 1);
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("azi")>=10){
        command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
        command( "say 这枝香好好拿去用吧。");
        obj = new("/d/xingxiu/obj/incense");
        obj->move(this_player());
        this_player()->delete("azi");
	this_player()->delete("marks");
	}
        return 1;
    }
	if ((string)ob->query("name")=="蜈蚣壳" &&
        this_player()->query("marks") == "蜈蚣壳" 
		&&!userp(ob)) {
        command( "hehe");
        this_player()->add("azi", 1);
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("azi")>=5){
        command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
        command( "say 这枝香好好拿去用吧。");
        obj = new("/d/xingxiu/obj/incense");
        obj->move(this_player());
        this_player()->delete("azi");
	this_player()->delete("marks");
	}
        return 1;
    }
	if ((string)ob->query("name")=="蝎子壳" &&
        this_player()->query("marks") == "蝎子壳" 
		&&!userp(ob))  {
        command( "hehe");
        this_player()->add("azi", 1);
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("azi")>=5){
        command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
        command( "say 这枝香好好拿去用吧。");
        obj = new("/d/xingxiu/obj/incense");
        obj->move(this_player());
        this_player()->delete("azi");
	this_player()->delete("marks");
	}
        return 1;
    }
	if ((string)ob->query("name")=="沙虫壳" &&
        this_player()->query("marks") == "沙虫壳" 
		&&!userp(ob))  {
        command( "hehe");
        this_player()->add("azi", 1);
        call_out("destroy_it", 1, ob);
        if( (int)this_player()->query("azi")>=3){
        command( "say 辛苦这位"+RANK_D->query_respect(who)+"了。");
        command( "say 这枝香好好拿去用吧。");
        obj = new("/d/xingxiu/obj/incense");
        obj->move(this_player());
        this_player()->delete("azi");
	this_player()->delete("marks");
	}
        return 1;
    }
	else { return 0;}
}
void destroy_it(object ob)
{
	if(ob)
	destruct (ob);
}

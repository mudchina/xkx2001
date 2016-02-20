//Cracked by Roath
// Ryu, 7/14/97

inherit NPC;
int ask_me();
int ask_sword();
int ask_iron();
void create()
{
	set_name("欧治子", ({ "ou zhizi", "ou", "zhizi" }) );
	set("gender", "男性" );
	set("age", 40);
	set("long",
		"一位背微驮，两鬓微白老者，显然经历风霜，饱尝冷暖。\n");
	set("combat_exp", 3000);
        set("str", 35);
        set("dex", 20);
        set("con", 20);
        set("int", 22);
	set("attitude", "friendly");
        set("inquiry", ([
		"铸剑" : (: ask_me :),
		"风胡子" : "那是鄙人小徒。\n",
		"薛烛" : "那是鄙人小徒。\n",
		"宝剑" : (: ask_sword :),
		"铁石" : (: ask_iron :),
		"紫铁" : (: ask_iron :),
	]));	

	set_skill("dodge", 25);
	set_skill("parry", 25);
	set_skill("unarmed", 30);
	
	setup();
        carry_object("/d/city/obj/cloth")->wear();
	add_money("coin", 200);
}
int ask_iron()
{
	object ob, me = this_player();

	if (query("iron_done") == me->query("id")){
	command("nod");
	command("say 这块铁虽打不出什么宝物，不过这把刀也有几分钢火，你那去吧。");
	ob = new("/clone/weapon/zijin-dao");
	ob->move(this_object());
	command("give " +me->query("id")+ " " + ob->query("id"));
	this_object()->delete("iron_done");
	return 1;
	}

	command("look "+me->query("id"));
	write("欧治子低下头，对你睬也不睬，开始沉思起来。\n");
	return 1;
}
int ask_sword()
{
	object ob, me=this_player();

	if (me->query_temp("wait_sword")){
	if (!query("sword_done")){
	command("say 不是让你半个月後来吗？不要心急。");
	return 1;
	}
	else {
	ob=new("/clone/unique/yuchang-jian");
	ob->move(me);
	say("欧治子走进後堂取出一个纸包，唰！的一声抽出一柄寒光四射的宝剑！\n");
	message_vision("欧治子递给$N一柄鱼肠剑。\n", me);
	set("sword_done", 0);
	set("sword_making", 0);
	me->delete_temp("wait_sword");
	command("say 你拿去吧！");
	command("rumor "+me->query("name")+"弄到了一柄鱼肠剑。");
	return 1;
	     }
	}
	else {return 0;}
}	
		
int ask_me()
{
	object ob;
	
	if (this_player()->query_temp("wait_sword") && !query("sword_done")){
        command("say 不是让你半个月後来吗？不要心急。");
        return 1;
        }

	if (this_player()->query("age") < 20 || this_player()->query("combat_exp") < 15000){
	command("say 你这个小毛孩子是在打趣老夫吧！边上玩着去！");
	return 1;
	}

	if (query("sword_making")){
	write("欧治子说道；好剑我现在只能做一把，已被别的客官订了，阁下以後再来吧。\n");
	return 1;
	}
	ob=new("/clone/unique/yuchang-jian");
	if (ob){
	write("欧治子上上下下把你打亮了一番，说道：客官是想铸一柄什麽样的剑呐？\n");	
	this_player()->set_temp("marks/铸", 1);
	add_action("do_say", "say");
	destruct(ob);
        return 1;
	}
	else{
	command("yawn "+this_player()->query("id"));
	command("zzz");
	return 1;
	}
}
int do_say(string arg)
{
	object me = this_player();

	if( !arg || arg=="" ) return 0;
	
	if( !me->query_temp("marks/铸")) return 0;

	if( arg == "宝剑" ){
	message_vision("$N说道： 宝剑。\n", me);
	command("sneer");
	command("say 你以为打造一柄上好宝剑，说一句话就行了吗？");
	command("say 你先去准备好两百斤好铁和十斤黄金再说吧。");
	me->delete_temp("marks/铸");
	me->set_temp("marks/剑", 1);	
	return 1;
	}
} 
int accept_object(object who, object ob)
{
	if (ob->query("for_blade")){
	write("欧治子眼睛突然一亮，接过石块来回打亮。\n");
	call_out("say_ob", 10, ob, who);
	return 1;
	}

	if (!who->query_temp("marks/剑")){
	command("? " +who->query("id"));
	return 0;
	}

	if (query("sword_making")){
        write("欧治子说道；好剑我现在只能做一把，已被别的客官订了，阁下以後再来吧。\n");
        return 0;
        }

	if (ob->value() >= 1000000){
	command("nod " +who->query("id"));
	who->set_temp("marks/金", 1);
	call_out("destroy_it", 1, ob);
	if (who->query_temp("marks/剑") >= 100000){
	who->delete_temp("marks/剑");
        who->delete_temp("marks/金");
        who->set_temp("wait_sword", 1);
        set("sword_making", 1);
        command("say 你过半个月来取剑吧。");
        call_out("do_make", 700, who);
	      }
	return 1;
	}

	if (ob->query("material") == "steel"){
	if (ob->query("weapon_prop/damage") > 0){
	command("say 这不是好好的一把"+ ob->query("name")+"？你拿给我做什麽？");
	return 0;
	}
	else {
	command("nod");
	who->add_temp("marks/剑", ob->query_weight());  
	if (who->query_temp("marks/剑") >= 100000){
	if (!who->query_temp("marks/金")){
	command("say 再添十斤黄金便可开炉铸剑了。");
	}
	else {
	who->delete_temp("marks/剑");
	who->delete_temp("marks/金");
	who->set_temp("wait_sword", 1);
	set("sword_making", 1);
	command("say 你过半个月来取剑吧。");
	call_out("do_make", 700, who);
	     }
	}
	call_out("destroy_it", 1, ob);
	}
	return 1;
	}
	else {
	command("say 这块东西可打不出宝剑来！");
	return 0;
	}
}
void say_ob(object ob, object who)
{
	if (present(who, environment(this_object()))){
	command("hmm " +who->query("id"));
	command("say 这块铁。。。。似乎有点用，你过几天再来，我看能不能弄出什么名堂。");
	call_out("make_ob", 500, who);
	}

	if(objectp(ob)) destruct(ob);
	return;
}
	
void destroy_it(object ob)
{
	if(objectp(ob)) destruct(ob);
	return;
}
void do_make()
{
	set("sword_done", 1);
	return;
}
void make_ob(object who)
{
	set("iron_done", who->query("id"));
	return;
}

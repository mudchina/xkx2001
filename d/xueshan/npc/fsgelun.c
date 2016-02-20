//Cracked by Roath
// /d/xueshan/npc/fsgelun.c
// Summer 9/26/1996.

inherit NPC;
int do_fashi();
void create()
{
	set_name("葛伦布", ({ "ge lunbu", "ge", "lunbu" }));
	set_weight(3000000);
	set("long", 
"他是密宗的戒律僧，长得膀大腰，手中提着法器，身着黄袍，头戴黄帽，\n"
"满面肃杀之气。\n");
	set("gender", "男性");
	set("age", 20);
	set("attitude", "heroism");
	set("class","lama");
	set("shen_type", -1);
	set("str", 50);
	
	set("max_qi", 500);
	set("max_jing", 450);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 40);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 50);
	set_skill("dodge", 55);
	set_skill("parry", 60);
	set_skill("staff", 60);
	set_skill("cuff", 60);
	set_skill("hammer", 60);

        map_skill("parry", "jingang-chu");
        map_skill("staff", "jingang-chu");

        set("inquiry", ([
                "准备法事" : (: do_fashi :),
		"preparation" : (: do_fashi :),
        ]) );

        setup();
	switch( random(3) )
        {
                case 0:
       			 carry_object("/clone/weapon/falun")->wield();
                         break;
		case 1:
			 carry_object("/d/qilian/obj/fachu")->wield();
			 break;
		case 2:
		 	 carry_object("/d/qilian/obj/faling")->wield();
	}
        carry_object(__DIR__"obj/lamajiasha")->wear();
}


int do_fashi()
{
	int i;
	object ob, me, mengzhu, room, *obj, room1, gang;
	ob=(present("fa tan", (environment(this_object()))));
	me=this_player();
	
	
	if (! present("fa tan", (environment(this_object())))){
	command("say 我正忙着呢，你去问值日的葛伦布吧。");
	return 1;
	}

	if (me->query("class") != "lama"){
	command("say 你是想让我们大喇嘛把你超度了，是吧？");
        return 1;
        }

	if ( me->query("family/family_name") != "雪山派"
	&& me->query("family/family_name") != "血刀门"){
	command("say 你是想让我们大喇嘛把你超度了，是吧？");
	return 1;
	}

	if(!( room = find_object("/d/taishan/fengchan")) )
        room = load_object("/d/taishan/fengchan");
        seteuid(getuid(me));
        if( !objectp(mengzhu = present("mengzhu", room)) )
        mengzhu = new("/clone/npc/meng-zhu");
        if (userp(me) && me->query("id") == mengzhu->query("winner") ){
	command("say 上人身为武林盟主，这法事您老就别操心啦！");
	return 1;
	}

	if (me->query_skill("lamaism", 1) < 60){
	command("say 很好！你去弄些做法事用的酥油来吧。");
	return 1;
	}

    // add to involve the butter stuff
	if(!( room1 = find_object("/d/xueshan/dumudian")) )
		room1 = load_object("/d/xueshan/dumudian");
	if ( !objectp(gang = present("tong gang", room1)) ) {
    	command("say 做法事用的酥油不见了，上人赶快去查一下吧！");
		return 1;
	}

	if (gang->query_current_liquid() < 40) {
	    command("say 做法事用的酥油不够用了，请上人弄些酥油来吧。");
		return 1;
	}

	if (ob->query("burning")){
	obj = all_inventory(environment());
        for(i=0; i<sizeof(obj); i++){
        if( obj[i]->query("name") == ob->query("pending") ){
	command("say " +ob->query("pending") + "上人正在做法事，这位" 
	+ RANK_D->query_respect(me) + "请一旁稍候。\n");
	return 1;
	}
	}
	command("say " +ob->query("pending") + "上人法事做到一半後不知跑哪里去了？真不象话！"
	+me->query("name") + "上人替" + ob->query("pending") + "上人把余下的法事做完吧。\n");
	ob->set("pending", me->query("name"));
	return 1;
	}
/*
	if (me->query("name") == ob->query("last_burner")){
	command("say  上人不是刚做完法事吗？你还是先歇一会儿吧。");
	return 1;
	} 
*/
	if (ob->query("pending")){
        command("say " + ob->query("pending") + "上人刚做完法事，祭坛还未熄，待我等清理完後"
	 + RANK_D->query_respect(me) + "再来做法事吧。\n");
	return 1;
	}
	
	else{
	command("say " + me->query("name") + RANK_D->query_respect(me) +
	"是要给哪位施主做法事呀？\n");
	me->set_temp("marks/葛", 1);	
	return 1;
	}
}
int accept_object(object me, object ob)
{
	if (ob->query("beheaded")){
	command("say 怎麽没有头？");
	return 0;
	}

	if (ob->query("id") == "corpse" && present("fa tan", (environment(this_object())))
	&& me->query_temp("marks/葛") == 1) {
	write("葛伦布急急忙忙吩咐左右往祭坛里填柴，倒酥油。\n");
	me->delete_temp("marks/葛");
	if (ob->query("combat_exp") > me->query("combat_exp")
	&& ob->query("my_killer") == me->query("id")){
	me->set_temp("award_pending", ob->query("combat_exp"));
	me->set_temp("award_pot", ob->query("combat_exp"));
	if (ob->query("was_userp"))
	me->set_temp("award_doubling", 1);
	}
	if(ob->query("combat_exp") > 1000000
	&& ob->query("my_killer") == me->query("id")) {
	me->set_temp("award_pot", ob->query("combat_exp"));
	}
	remove_call_out("preparing");
        call_out("preparing",5, me);
        return 1;
	}

	if (ob->name()=="酥油罐"
        && me->query("class") == "lama"){
        if (me->query_skill("lamaism", 1) < 30){
	me->set("lama_butter",me->query("mud_age"));
        command ("bow");
        command ("say 佛主保佑施主！");
//        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        return 1;
        }
        if (me->query_skill("lamaism", 1) >= 30
        && me->query_skill("lamaism", 1) < 60){
        me->set("lama_butter",me->query("mud_age") + 7600);
        command ("bow");
        command ("say 佛主保佑施主！");
        remove_call_out("destroy_it");
        call_out("destroy_it", 1, ob);
        return 1;
        }
   }
//	else if (ob->name()!="酥油" && ob->query("id") != "corpse") {
	else {
        write("葛伦布脸上露出迷惑的表情。\n");
        command ("shake");
//	remove_call_out("destroy_it");  // if player #10 give him some stuff,
					// 1 got dest but others 9 still on him   
        call_out("destroy_it", 1, ob);
        return 1;
        }
	return 1;
}	
void destroy_it (object ob)
{
        destruct(ob);
        return;

}
void preparing(object me)
{
	object ob, obj, room, tonggang, guan;
	ob=(present("fa tan", (environment(this_object()))));
	obj=(present("corpse", this_object()));
	ob->set("pending", me->query("name"));
	ob->set("in_use", 1);

	write("不一会儿，一切准备停当。\n");
	command("say " + me->query("name") + "上人请为亡灵超度吧！\n");
/*	command("chat " + me->query("title") + me->query("name") +
                "上人，于今日" + NATURE_D->game_time() + "超度" 
		+ obj->query("victim_name") + "！\n");
*/
	command("put corpse in fa tan");
	obj->set_weight(ob->query_weight()*10);
	return;
}

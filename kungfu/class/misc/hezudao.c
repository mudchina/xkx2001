//Cracked by Roath
// 管象棋的npc！ (反正没有昆仑派)  by maco

inherit NPC;
#include <ansi.h>

int ask_score();
string ask_win();
string ask_lose();

void create()
{
        set_name("何足道", ({ "he zudao", "he", "zudao" }));
        set("nickname", "昆仑三圣");
        set("long", "这是一个身著白衣的中年男子，长脸深目，瘦骨棱棱，\n"
        "身负琴、剑、棋三绝，世称「昆仑三圣」。\n"
        "目前扬州的象棋棋苑由他负责，也记录所有来此下棋的棋士成绩。\n");
        set("gender", "男性");
        set("age", 36);
        set("special_npc", 1);
        set("no_get", 1);
	set("title", "昆仑派掌门、棋苑主人");
        set("attitude", "heroism");
        set("str", 30);
        set("int", 33);
        set("con", 29);
        set("dex", 33);
        set("max_qi", 6000);
        set("max_jing",6000);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jingli", 3000);
        set("max_jingli", 3000);
        set("jiali", 250);
        set("combat_exp", 3600000);


        set_skill("force", 360);
        set_skill("dodge", 400);
        set_skill("parry", 360);
        set_skill("strike", 360);
        set_skill("sword", 400);
        set_skill("literate", 300);
        set_skill("qimen-dunjia", 280);
        set_skill("taixuan-gong", 360);
        set_skill("liangyi-jian", 400);
        set_skill("poem-dodge", 360);
        set_skill("liuyang-zhang", 360);
        
        map_skill("dodge","poem-dodge");
        map_skill("strike","liuyang-zhang");
        map_skill("sword", "liangyi-jian");
        map_skill("force", "taixuan-gong");
        map_skill("parry", "liangyi-jian");
        prepare_skill("strike", "liuyang-zhang");

	create_family("昆仑派", 1, "掌门");

        set("inquiry", ([
                "name" : "我姓何，名字叫做「足道」。\n",
                "昆仑三圣" : "我在西域闯出了一点小小名头，当地的朋友说我琴剑棋三绝，可以说得上是琴圣、剑圣、棋圣。因我常年住于昆仑山中，是以给了我一个外号，叫作「昆仑三圣」。\n",
                "昆仑三圣何足道" : "这个「圣」字，岂是轻易称得的？虽然别人给我脸上贴金，也不能自居不疑，因此上我改了自己的名字，叫作「足道」，联起来说，便是「昆仑三圣何足道」。人家听了，便不会说我狂妄自大了。\n",
		"何足道" : "这个「圣」字，岂是轻易称得的？虽然别人给我脸上贴金，也不能自居不疑，因此上我改了自己的名字，叫作「足道」，联起来说，便是「昆仑三圣何足道」。人家听了，便不会说我狂妄自大了。\n",
               	"成绩" : (: ask_score :),
		"score" : (: ask_score :),
		"象棋" : "象棋相关指令都在help c_chess中。\n",
		"围棋" : "侠客行尚未开放围棋。\n",
		"放弃" : "清理自己的成绩，从零开始，输入clean。",
		"abandon" : "清理自己的成绩，从零开始，输入clean。",
		"clean" : "清理自己的成绩，从零开始，输入clean。",
		"win" : (: ask_win :),
		"胜" : (: ask_win :),
		"lose" : (: ask_lose :),
		"败" : (: ask_lose :),

        ]) );
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "sword.xunlei" :),
        }) ); 

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xingxiu/obj/wcloth")->wear();

}


void init()
{
    add_action("do_clean", "clean");
}

int do_clean()
{
    object me = this_player();
	int win, lose, draw, all;

	win = me->query("c_chess/win");
	lose  = me->query("c_chess/lose");
	draw  = me->query("c_chess/draw");
	all = win + lose + draw;
	
	if(all < 20) {
	return notify_fail("必需累积满二十局棋赛才能重新记录成绩。\n");
	}

    	me->delete("c_chess/win");
    	me->delete("c_chess/lose");
    	me->delete("c_chess/draw");
    	command("say 好，"+RANK_D->query_respect(me) +"的象棋胜负记录已经全部清除了。\n");
    return 1;
}

int ask_score()
{
	object me = this_player();
	int win, lose, draw, all;
	string msg;
	
	win = me->query("c_chess/win");
	lose  = me->query("c_chess/lose");
	draw  = me->query("c_chess/draw");
	all = win + lose + draw;

	if (all < 1) {
	command("say "+RANK_D->query_respect(me) + "还没有跟人对弈过吧？");
	return 1;
	}

	msg = me->name()+RANK_D->query_respect(me) + 
	"对弈象棋"+chinese_number(all) +"局，成绩是";

	if(win > 0)	msg += chinese_number(win) +"胜";
	if(lose > 0)	msg += chinese_number(lose) +"败";
	if(draw > 0)	msg += chinese_number(draw) +"和";
	msg += "。";
	
	command("say "+msg);
	if(all > 10) {
		if( lose > win*4 ) command("disapp "+me->query("id"));
		else if( lose > win ) command("nocry "+me->query("id"));

		if( win > lose*4 ) command("admire "+me->query("id"));
		else if(win > lose ) command("applaud "+me->query("id"));
		}
	return 1;
}

string ask_win()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, win = 0, lose, draw, all;

	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("c_chess/win") > win 
		&& where ) {
			obj = ob_list[i];
			win = obj->query("c_chess/win");
		}
	}
	if ( !obj ) {
		msg ="嗯，全侠客行里面，还没人下象棋有赢过的。\n";
		return msg;
	}

	lose  = obj->query("c_chess/lose");
	draw  = obj->query("c_chess/draw");
	all = win + lose + draw;

	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="说到当今侠客行第一象棋国手，那当然是"+name+"！其成绩是"+chinese_number(all)+"战"+chinese_number(win)+"胜。\n";

	return msg;
}

string ask_lose()
{
	object where,obj,*ob_list;
	string msg, name;
	int i, lose = 0,win, draw, all;

	ob_list = users();

	for( i = 0; i < sizeof(ob_list); i++) {
		where = environment(ob_list[i]);
		if( ob_list[i]->query("c_chess/lose") > lose 
		&& where) {
			obj = ob_list[i];
			lose = obj->query("c_chess/lose");
		}
	}
	if ( !obj ) {
		msg ="全侠客行居然没有人下象棋输过，到底是个个都是大国手，还是没人会下棋？\n";
		return msg;
	}
	win = obj->query("c_chess/win");
	draw  = obj->query("c_chess/draw");
	all = win + lose + draw;

	name = obj->query("name")+"("+obj->query("id")+")";
	msg ="放眼侠客行，下象棋输得最惨的就数"+name+"了，成绩是"+chinese_number(all)+"战"+chinese_number(lose)+"败。\n";

	return msg;
}

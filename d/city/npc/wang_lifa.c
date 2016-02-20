//Cracked by Roath
// 管象棋的npc！  by maco
// Modified by xQin 6/00

inherit NPC;
#include <ansi.h>

int ask_score();
string ask_win();
string ask_lose();

void create()
{
        set_name("王老板", ({ "wang laoban", "wang", "laoban" }));
//        set("nickname", "");
        set("long", "他便是王利发，据说因父亲早死，他很年轻就做了春来茶馆的掌柜。\n"
                    "为人精明能干，虽有些自私，但心眼不坏。茶馆内的象棋胜负由他\n"
                    "亲自负责，也记录所有来此下棋的棋士成绩。\n");
        set("gender", "男性");
        set("age", 22);
        set("special_npc", 1);
        set("no_get", 1);
	set("title", "春来茶馆掌柜");
        set("attitude", "friendly");
        set("str", 20);
        set("int", 26);
        set("con", 20);
        set("dex", 20);
        set("max_qi", 1000);
        set("max_jing",700);
        set("neili", 400);
        set("max_neili", 700);
        set("jingli", 3000);
        set("max_jingli", 700);
        set("jiali", 1);
        set("combat_exp", 50000);


        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("strike", 60);
        set_skill("literate", 60);
        set_skill("unarmed", 60);

        



        set("inquiry", ([
        	"tea" : "客官要喝茶可真是来对地方了，请里面坐，小二这就上茶点。\n",
                "name" : "在下是王利发，这里的掌柜。\n",
                "王利发" : "我便是，客官可有吩咐？\n",
                "品茶" : "嘿黑，我这里的茶可都是极品啊，客官您不信可以去打听打听(help tea)。\n",
               	"成绩" : (: ask_score :),
		"score" : (: ask_score :),
		"象棋" : "象棋相关指令都在help c_chess中。\n",
		"围棋" : "围棋棋苑在大理，不过听说对面也要开一间了。\n",
		"放弃" : "清理自己的成绩，从零开始，输入clean。",
		"abandon" : "清理自己的成绩，从零开始，输入clean。",
		"clean" : "清理自己的成绩，从零开始，输入clean。",
		"win" : (: ask_win :),
		"胜" : (: ask_win :),
		"lose" : (: ask_lose :),
		"败" : (: ask_lose :),

        ]) );
        setup();
        add_money("gold", 1);
//        carry_object(__DIR__"obj/tiesuanpan")->wield();
        carry_object("/d/quanzhou/npc/obj/guazi")->wear();

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

int accept_kill(object me)
{
        command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

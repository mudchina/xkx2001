//Cracked by Roath
#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

int jiaban(object me);
int do_move();
int ask_yirong();
int ask_mianju();

void create()
{
        set_name("江湖术士", ({ "shu shi", "shi", "jianghu shushi"}));
        set("long",  "此人相貌猥琐，手持一折扇，衣着着实讲究，颇有富家子弟之风。\n此人似乎武功奇高。");
        set("gender", "男性");
        set("age", 45);
        set("attitude", "heroism");
        set("shen_type", 0);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 2000);
        set("max_jing",2000);
        set("eff_jing",2000);
        set("eff_qi",2000);
        set("neili", 2500);
        set("max_neili", 2500);
        set("jiali", 150);
        set("env/wimpy", 80);
        set("combat_exp", 800000);
        set("chat_chance_combat", 15);
        
 	set("inquiry", ([
        "易容之术" : (: ask_yirong :),
	"人皮面具" : (: ask_mianju :),
	]));

        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("ding-dodge", 200);
        set_skill("ding-force", 200);
        set_skill("ding-unarmed", 200);
        set_skill("parry", 200);
        set_skill("unarmed", 200);
        set_skill("san-sword", 200);
        set_skill("pike", 200);

        map_skill("dodge", "ding-dodge");
        map_skill("force", "ding-force");
        map_skill("unarmed", "ding-unarmed");
        map_skill("pike", "san-sword");

        setup();
        if( clonep() )
        {
        	carry_object("/d/city/obj/cloth")->wear();
        	carry_object("/d/xingxiu/obj/mianju");
        }

}

void init()
{
	object me=this_player();
        ::init();
        
        if(random(me->query("kar"))<3){
        	call_out("jiaban", 20, me );	
        }
        //call_out("do_move", (random(20)+20));
        call_out("dest", 500 );
}


int jiaban(object me){
       	command("ban "+me->query("id"));
       	//command("hehe");
 }

int ask_mianju(){
	
	object ob;
	object me=this_player();
	
	if(me->query_temp("gave")){
		if(present("mian ju", this_object())){
			ob = present("mian ju", this_object());
			if(ob){
				ob->move(me);
			}
			command("say 这面具给你，好好收着罢。");
			command("hehe");
			CHANNEL_D->do_channel(me, "rumor", sprintf("听说%s弄到了一张人皮面具。", me->query("name")));  
		
		} else {
			command("say 哎哟，这真不巧，面具已经卖出去了。");
			command("hehe");
		}
	
		me->delete_temp("gave");
		me->set_temp("canlearn", 1);	
		//say("江湖术士一抱拳，匆匆离开了。\n");
		//destruct(this_object());
	} else
	 	say("江湖术士嘿嘿一声干笑：“这东西乞能轻易给人？\n");
	
	return 1;
}

int ask_yirong(){
	
	object me=this_player();
	
	if(me->query_temp("canlearn", 1) && me->query_temp("gave", 1)){
		say("经过江湖术士的详细解释，你终于领悟到了易容术的奥秘。\n");
		me->set_temp("can_ban", 1);
		call_out("dest", 20 );	
	} else {
		say("你想了想，觉得还是不要在碰钉子了。\n");
	}
	
	return 1;
	
}

int accept_object(object me, object obj){

	if(obj->query("name")=="金元宝" || obj->query("id")=="jin yuanbao"){
		say("江湖术士高高兴兴地将元宝放到了怀里。\n");
		me->set_temp("gave", 1);
		call_out("destob", 1, obj);
		return 1;
	} else return 0;
	
	
}

void unconcious(){
	say("江湖术士一声：“哎哟” 转身跑得无影无踪。\n");
	destruct(this_object());
}

void die(){
	say("江湖术士一声：“哎哟” 转身跑得无影无踪。\n");
	destruct(this_object());
}

void destob(object ob){
	destruct(ob);
}

void dest(){
	say("江湖术士匆匆忙忙地离开了。\n");
	destruct(this_object());
}

int do_move()
{
    object room;
    mapping exits;
    string  *dirs;

    room = environment(this_object());
    exits = room->query("exits");
    dirs = keys(exits);
    command("go "+dirs[random(sizeof(dirs))]);
    call_out("do_move", (random(20)+1));
    return 1; 
}
//Cracked by Roath
// Npc: /d/mingjiao/mingjiao_shouwei.c
// Date: Wzfeng@xkx 99 6 

#include "mingjiao_npc.c"


int ask_rujiao();
int find_yang(object player);

void create()
{
	mapping S_skills= ([ ]);
	set_name("明教守卫", ({"mingjiao shouwei","shouwei",}));
    set_weight((random(2)+ 1) * 1300000);
	set("long",
		"他是一名明教的山门守卫，一身结实的肌肉显出不凡的武功家底。\n"
		"他头系红色头巾，身穿灰色明教圣袍，圣袍上锈着一个大红火焰。\n"
	);

	set("gender", "男性");
	set("attitude", "peaceful");
	set("age", 25);
	set("shen_type", 1);
	set("inquiry", ([
		"入教": (: ask_rujiao :),
		"join": (: ask_rujiao :),
		]));

	Set_Npcattrib(20,1,1000,300,500,100,1000,100,1000,100,100000,10000);

	set_skill("force", 30+random(10));
	set_skill("dodge", 30+random(10));
	set_skill("parry", 30+random(10));
	set_skill("blade", 30+random(10));
	set_skill("sword", 30+random(10));
	

/*	if(!get_day())
	{
	set("chat_chance", 1);
    set("chat_msg", ({
		"明教守卫强打精神,喝道：“现在已是夜间，兄弟们要加强守护，防止六大派的奸细混入我光明圣教！\n",
        }) );
	}
	*/
	create_family("明教", 38, "弟子");
	
	setup();
	carry_object(OBJ_PATH"/blade")->wield();
	carry_object(OBJ_PATH"/changpao")->wear();

}

int ask_rujiao()
{
     object player=this_player();
     mapping fam = player->query("family");
//为了test，今后正式开放是要打开
	 	 if(player->query_temp("ask_rujiao"))
	 {
	 	 tell_object(player,"明教守卫对你说到：“你不是已经问过了吗？”\n");
		 return 1;
	 }
	 
     
	 if (!fam || fam["family_name"] != "明教")
		 if(player->query("combat_exp")<10000)
	 {
		 command("say "+RANK_D->query_respect(player)+"既与我教有缘，我这就去请杨左使来，让他为你办理入教大典。\n");
		 player->set_temp("ask_rujiao",1);
         message_vision("明教守卫往里快步走去。\n",this_object());
		 player->start_busy(3);
         remove_call_out("find_yang");
         call_out("find_yang", 1, player);

               return 1;
     }
		 
			 if(fam["family_name"] == "明教")
			 {
				 command("say "+"我看这位"+RANK_D->query_respect(player)+"已是我教教众，还问这个干什么？\n");
				 return 1;
			 }
	command("say "+"我看这位"+RANK_D->query_respect(player)+"已是江湖高手，我教恐怕不能收留，还是请回吧。\n");
		 

	return 1;
}

int find_yang(object player)
{
	object yang,where,room;
	object me=this_object();
    if(!( room = find_object(MINGJIAO"/shting")) )
       room = load_object(MINGJIAO"/shting");
	me->move(room);
	if(!objectp(yang = present("yang xiao", room) )||!living(yang)||yang->is_busy())
		{
	        	me->move(MINGJIAO"/damen");
        	     message_vision("\n明教守卫快步走了过来。\n", me);
				message_vision("明教守卫对$n报了个拳，说到：“杨左使现在公务繁忙，暂时无法替你办入教大典，你下次再来吧。\n", me,player);
				return 1;
			
		}
    message_vision("$N快步走了过来，对$n报拳说到：“山下有人想加入我教，还请杨左使为其办理入教大典。\n", me, yang);
	message_vision("$N对$n点了点头说到：“好，我这就去。\n", yang,me);
	message_vision("明教守卫走了出去。\n", me);
    me->move(MINGJIAO"/damen");
	yang->move(MINGJIAO"/damen");
	message_vision("$N走了出去。\n", yang);
	message_vision("明教守卫走了过来。\n", me);
	message_vision("杨逍走了过来。\n", me);
	yang->rujiao(player);
	player->start_busy(4);
	
	return 1;
}



void init()
{


}


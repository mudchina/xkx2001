//Cracked by Roath
// yinggu.c  dali NPC
// acep , mantian , mantian

inherit NPC;
string ask_me();
int do_answer(string);

void create()
{
	set_name("瑛姑", ({ "ying gu", "ying", "gu" }) );
	set("gender", "女性" );
	set("age", 48);
	set("long", 
		"她头发花白，身批麻衫，凝视着地上无数的一根根竹片，"
		"显然正在潜心思索，虽然听得有人进来，却不抬头。\n");

	set("str", 25);
	set("dex", 35);
	set("con", 27);
	set("int", 25);
	set("shen_type", 1);
	set("max_neili",800);
	set("neili",800);
	set("jiali",30);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("sword",100);
	set_skill("force", 100);
	set("combat_exp", 100000);

	set("attitude", "peaceful");
	set("inquiry", ([
		"段皇爷" : "你提他作什么，哼，求他医伤麽，死了这条心吧。",
		"段智兴" : "你提他作什么，哼，求他医伤麽，死了这条心吧。",
		"算术" :  (: ask_me :),
		]) );

	setup();

	carry_object("/d/forest/npc/obj/gebu-changpao")->wear();
	if (clonep()) carry_object("/clone/weapon/qijue.c", "/clone/weapon/xiuhua.c")->wield();
}

void init()
{
	::init();
	add_action("do_answer","answer");
}

string ask_me()
{
	object who=this_player();
	if (who->query_temp("marks/瑛")) {
			write("瑛姑冷冷的说：上一道你还没答出来呢，急什么？\n");
			return "一道一道的来。\n";
	}
	else {
		write("瑛姑抬头看了你一眼：这位"+RANK_D->query_respect(who)+"也懂算术？\n");
		switch(random(2)) 
		{
		case 0:
			write("五万五千二百二十五的平方根为其何\n");
			who->set_temp("marks/瑛", 1);
			break;
		case 1:
			write("百数方阵，纵横斜正各五百零五数，\n");  
			write("四二，四一，七六各据一角，余角何数? \n");
			who->set_temp("marks/瑛", 2);
			break;
		case 2:
			write("丈许长杆，日取其半，几日可终? \n");
			who->set_temp("marks/瑛", 3);
			break;
		}
		message_vision("瑛姑冷冷地对$N说：解否? \n", who);
		return "你解出来就回答(answer)我。\n";
	}
}

int do_answer(string arg)
{
	int soln,riddle;
	object me = this_player();
	riddle = this_player()->query_temp("marks/瑛");

	if (!riddle) {
		write("我又不是你师傅，你用不着回答我。\n");
		return 1;
	}

	if( !arg || arg=="" ) {
		write("想好谜底再回答。\n");
		return 1;
	}
	message("vision", me->name() + "朗声回答。\n", environment(me), ({me}));

	switch (arg) 
	{
	case "二百三十五": soln=1; break;
	case "六十" : soln=2; break;
	case "万载不终" : soln=3; break;
	default :
		say("瑛姑冷笑道：“班门弄斧。”然后就把"+ me->name() +"赶了出去。\n");
		me->move("/d/dali/maze1");
	return 1;
	}

	if (riddle==soln) {
		this_player()->set_temp("marks/瑛", 0);
		say ("瑛姑抬头冷冷的瞥了"+me->name()+"一眼，你要找段智兴从我后门出去。\n");
		me->move("/d/dali/yideng1");
		write ("你走出后门来到了一座小山脚下！\n");
		return 1;
	}
	else {
		command("slapsb "+getuid(me));
		say("瑛姑怒道：“你到底懂不懂算术？！”把"+ me->name() +"赶了出去。\n");
		me->move("/d/dali/droad2");
	return 1;
	}
}

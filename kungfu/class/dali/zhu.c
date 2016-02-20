//Cracked by Roath
//Zhu ZiLiu  oyxb/acep , mantian , mantian

inherit NPC;

void create()
{
	set_name("朱子柳", ({ "zhu ziliu", "ziliu", "zhu" }) );
	set("gender", "男性" );
	set("age", 48);
	set("long", 
		"这是一个中年书生，手里拿了一本旧书，正读得摇头晃脑的。 \n");        
	set("str", 25);
	set("dex", 20);
	set("con", 17);
	set("int", 15);
	set("shen_type", 1);
	set_skill("unarmed", 70);
	set_skill("dodge", 65);
	set_skill("hammer",70);
//    set("combat_exp", 550000);


	set("attitude", "peaceful");
	set("inquiry", ([
		"段皇爷" : "他以经死了。",
		"让路" :  "路我是不让的，你要敢跳，我就戳你一指。",
		]) );

	setup();

	set("chat_chance", 20);
	set("chat_msg", ({
		"朱子柳问道：是樵夫放你们上来的么？他有什么信物给你们带上来？\n",
	}) );
}

void init()
{
	::init();
	add_action("do_answer","answer");
}

int accept_object(object who, object ob)
{
	object me=this_object();

	if ((string)ob->query("name")=="锈铁斧" 
		&& ob->query("material") == "steel") {
		
		remove_call_out("destroying");
		call_out("destroying", 1, ob);

		if (me->query("visited")>3) {
			write("朱子柳摇头道：对不住，我师傅今天和师叔出去游山了，阁下改天再来吧。\n");
			return 1;
		}
		me->add("visited",1);

		if (who->query_temp("marks/子柳")) {
			write("朱子柳笑眯眯的说：答不出来就好好去读读书嘛。\n");
			return 1;
		}
		else {
			write("朱子柳抬头看了你一眼："+"这位"+RANK_D->query_respect(who) + "也懂诗词？\n");
			write("朱子柳摇头晃脑的吟道：\n");
			switch(random(7)) {
			case 0:
				write("抽刀断水水更流，举杯销愁愁更愁。\n");
				write("人生在世不称意，明朝散发弄□□。\n");
				who->set_temp("marks/子柳", 1);
				break;
			case 1:
				write("郑公粉绘随长夜，曹霸丹青已白头。\n");  
				write("天下何曾有山水，人间不解重□□。 \n");
				who->set_temp("marks/子柳", 2);
				break;
			case 2: 
				write("锦瑟无端五十弦，一弦一柱思华年。\n");
				write("庄生晓梦迷蝴蝶，望帝春心托杜鹃。\n");
				write("沧海明珠应有泪，蓝天日暖玉生烟。\n");
				write("此情可待成追忆，□□□□□□□。\n");
				who->set_temp("marks/子柳", 3);
				break;
			case 3:
				write("白骨露於野，千里无鸡鸣。 \n");
				write("生民百遗一，念之断□□。  \n");
				who->set_temp("marks/子柳", 4);
				break;
			case 4:
				write("梳洗罢，独倚望江楼。过尽千帆皆不是，\n");
				write("斜晖脉脉水□□，肠断白苹洲！ \n");
				who->set_temp("marks/子柳", 5);
				break;
			case 5:
				write("墙里秋千墙外道，墙外行人，墙里佳人笑。 \n");
				write("笑渐不闻声渐悄，□□□□□□□ \n");
				who->set_temp("marks/子柳", 6);
				break;
			case 6:
				write("恨春去，不与人期，弄月色， \n");
				write("空遗满地□□□  \n");
				who->set_temp("marks/子柳", 7);
				break;
			case 7:
				write("前不见古人，后不见来者， \n");
				write("□□□□□□□□□□□□ \n"); 
				who->set_temp("marks/子柳", 8);
				break;
			}
			message_vision("朱子柳笑眯眯的问道：我不记得了，你能告诉我么？\n", who);
			return 1;
		}
	}
	return 0;
}

void destroying(object obj)
{
	destruct(obj);
	return;
}

int do_answer(string arg)
{
	int soln,riddle;
    object me = this_player();
    riddle = this_player()->query_temp("marks/子柳");

    if (!riddle) {
		write("我又不是你师傅，你用不着回答我。\n");
		return 1;
	}
    if( !arg || arg=="" ) {
		write("想好谜底再回答。\n");
		return 1;
	}

    message("vision", me->name() + "朗声回答。\n", environment(me), ({me}) );
	switch (arg) {
	case "扁舟": soln=1; break;
	case "骅骝" : soln=2; break;
	case "只是当时已枉然" : soln=3; break;
	case "人肠" : soln=4; break;
	case "悠悠" : soln=5; break;
	case "多情却被无情恼" : soln=6; break;
	case "梨花雪": soln=7; break;
	case "念天地之悠悠独伧然而涕下" : soln=8; break;
	default :
		say("朱子柳冷笑道，你扫过盲了么。\n"+me->name()+"急忙退了出去。\n");
		me->move("/d/dali/maze1");
		return 1;
        }

	if (riddle==soln) {
		this_player()->delete_temp("marks/子柳");
		say ("朱子柳一鞠到地，对" + me->name() + "说道：高明，高明。佩服，佩服\n");
		write ("朱子柳移开三尺，你从他身边一跃而过，上山而去。 \n");
		me->move("/d/dali/yideng8");
	}
	else write (" 不对！！\n");
	return 1;
} 

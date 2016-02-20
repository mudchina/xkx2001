//Cracked by Roath
// wang.c

inherit NPC;

int ask_me();

void create()
{
        set_name("王小二", ({ "wang xiaoer", "wang" }) );
        set("gender", "男性" );
        set("age", 21);
        set("long", "这是个典型的关西汉子，一脸彪悍之色。\n");
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
        set("combat_exp", 5000);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);

	set("shen_type", -1);
        set("str", 28);
        set("dex", 25);
        set("con", 20);
        set("int", 17);
        set("attitude","heroism");
        set("inquiry", ([
		"鸡" : (: ask_me :),
		"偷鸡" : (: ask_me :),
        ]) );
	set("book_count", 1); 
        setup();
	carry_object("/clone/armor/cloth")->wear();
        add_money("coin", 200);
}
/*void init()
{
        ::init();
        add_action("do_bihua", "bihua");
}
*/

int ask_me()
{
	if ((int)this_player()->query_temp("marks/王3")) {
		say(
"王小二眼露凶光，对" + this_player()->name() + "喊道：杀人不过头点地，我已经\n"
"服了软，你还不放过我，老子跟你拼了！\n");
		set_temp("apply/attack", 30);
     		set_temp("apply/defense", 30);
		this_object()->kill_ob(this_player());
		return 1;
	} else {
	say(
"王小二看了" + this_player()->name() + "一眼，满不在乎的说道：\n"
"不错，鸡是我偷的，你要怎麽样？！看你也是出来闯江湖的，难道\n" 
"不知江湖上谁的拳头大谁说话？！你不服气？那好，咱俩练几招，\n"
"要是你赢了，我马上按双倍价赔给老太太。而且我还另外送你点\n"
"东西。你要输了，就给我爬着出去。怎麽着，敢不敢比划几下？\n");
	this_player()->set_temp("marks/王2", 1);
	return 1;
	}
}

int accept_fight()
{
        object me, ob;

        me = this_object();
        ob = this_player();

        if( ob->query_temp("marks/王2") ) {
        say(ob->name() + "对王小二说：好吧，那"
		 + RANK_D->query_self_rude(ob) + "就同你练几招。\n");

          me->set_temp("challenger", ob);
          ob->delete_temp("marks/王2");
          return 1;
        }
        else {
	  say("王小二不耐烦的对" + ob->name() + "说道：大爷我现在正在钻研赌技，没空。\n");
          return 0;
	}
}

int chat()
{
        object me = this_object();
        object ob = me->query_temp("challenger");
        object book, *obs;
        int my_max_qi, his_max_qi;

        if( !objectp(ob) ) return ::chat();

        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if (me->is_fighting(ob)) return ::chat();

        me->delete_temp("challenger");

        if (me->is_fighting()) return ::chat();

        if ( !present(ob, environment()) ) return ::chat(); 

        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ) 
        {

	   if (query("book_count") >= 1) {
		obs = filter_array(children(__DIR__"obj/sword_book.c"), (: clonep :));
        	if (sizeof(obs) > 2){
        		command("fear"); 
        		command("escape");
        		destruct(me);
			return 1;
           	}
                say(
"王小二对" + ob->name() + "说道：今儿您赢了我，您说什么我都得听着，我这就把\n"
"       钱给老太太送去。另外，这本书也是您的了。这是前些日子华山派从这\n"
"       路过，在庙里歇脚时落下的。\n"
                );
		book = new(__DIR__"obj/sword_book");
                book->move(ob);
		ob->set_temp("marks/王3", 1);
		message_vision("$N交给$n一本书。\n", me, ob);
		add("book_count", -1);
                return ::chat();
	   }
	   else {
		say(
"王小二对" + ob->name() + "说道：今儿您赢了我，您说什么我都得听着，我这就把\n"
"       钱给老太太送去。\n"

		    );
                return ::chat();
           }
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ) 
        {
		say(
"王小二冲着" + ob->name() + "撇了撇嘴，说道：就你这点本事还来\n"
"充英雄？！给我乖乖的爬出去吧！\n"
                );
                message("vision",
ob->name() + "乖乖的趴在地上，从洞里爬了出去。\n", environment(ob), ({ob}) );
                ob->move("/d/village/temple1");
                message("vision",
ob->name() + "从洞里爬了出来。\n", environment(ob), ({ob}) );
                return ::chat();
        }
        return ::chat();
}


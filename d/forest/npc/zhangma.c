//Cracked by Roath
// Jay 7/12/96
//changed by wzfeng 99 12

inherit NPC;

void create()
{
        set_name("张妈", ({ "zhang ma", "ma", "zhang" }) );
        set("gender", "女性" );
	set("title", "佣妇");
        set("age", 48);
        set("long", 
	     "萧府的女佣。\n");
        set("str", 20);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set("combat_exp", 500);

        set("attitude", "peaceful");
        set("inquiry", ([
            "萧府" : "如果你是来贺寿的，我才能让你进门。",
	    "here" : "这里就是萧府。",
	    "name" : "我还没成家，问我名字让人多不好意思。",
	    "贺寿" : "你的寿礼呢？",
	    "萧半和" : "那是我们家老爷。",
       ]) );

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}
private void go_home()
{
	if( !living(this_object()) ) return;
        message_vision("$N神色慌张地离开了。\n", this_object());
        this_object()->move("/d/forest/gate");
	message_vision("$N快步走了过来。\n", this_object());
}

void init()
{
        object ob;

        ::init();
        if( environment() != load_object("/d/forest/gate") ) {
		remove_call_out("go_home");
		call_out("go_home", 1);
		}
		else
			if (interactive(ob = this_player()) && !is_fighting()) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
    command("bow " + me->query("id"));
    command("say 这位" + RANK_D->query_respect(me)+"是来给我们家老爷贺寿的吧。");
}

int accept_object(object me, object obj)
{
	if ((string)obj->query("name")=="金钗") {
		remove_call_out("destroying");
		call_out("destroying", 1, this_object(), obj); 
	message("vision",me->name()+"给张妈一支金钗。\n",environment(me),
                ({me}));
	command("ah");
	command("say 这是我家小姐的金钗，莫非这位"+RANK_D->query_respect(me)+"就是令我们小姐神魂颠倒的意中人？");
	command("look "+me->query("id"));
	command("say 你先随我入筵席。");
	message_vision("张妈领着$N进了萧府。\n", me);
	me->move("/d/forest/yanting");
	message("vision", me->name()+"跟着张妈走进来。\n",environment(me),
		({me}));
	write("你一看满桌丰盛的酒菜就吃了起来。\n");
	me->set("food",me->query("str")*10 + 120);
	me->set("water",me->query("str")*10 + 120);
	}
	else command("say 这怎麽好意思。");
        return 1;
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
} 


//Cracked by Roath
// phshang.c

inherit NPC;
//inherit F_DEALER;
inherit F_VENDOR;

int random_walk();
string *walkrooms = ({
        "/d/changbai/beicheng",
        "/d/changbai/dongcheng",
        "/d/changbai/huanglu1",
        "/d/changbai/huanglu2",
        "/d/changbai/jishi",
        "/d/changbai/nancheng",
        "/d/changbai/ssmiao",
        "/d/changbai/xiaoxiang",
        "/d/changbai/xuedi1",
});       

void create()
{
	set_name("皮货商", ({ "pihuo shang", "seller", "shang" }) );
	set("gender", "男性" );
	set("age", 40);
	set("long",
		"这是个贩卖皮货的商人。\n");

	set("combat_exp", 3000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "friendly");

	set("vendor_goods", ({
		"/d/changbai/obj/piqiu",
	}) );
      
        set("chat_chance", 20);
        set("chat_msg", ({
                  (:random_walk:)
        }));

	setup();

        carry_object("clone/misc/cloth")->wear();
	add_money("silver", 3);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

int random_walk()
{
        mapping exits;
        string *dirs, dir;

        if( member_array(base_name(environment()), walkrooms) == -1 ) {
                message_vision("$N一溜烟跑掉了。\n", this_object());
                destruct(this_object());
        }

        if( !objectp(environment()) 
        || !mapp(exits = environment()->query("exits")) 
        || query("jingli") < query("max_jingli") / 2 ) return 0;

        dirs = keys(exits);
        dir = dirs[random(sizeof(dirs))];
        if( member_array(exits[dir], walkrooms) == -1 ) return 0;

        if( !random(3) )
                say("皮货商凑上来对你说道：“这位" + RANK_D->query_respect(this_player()) + "是要进山么？快买一件皮裘吧，不然出了城就会被冻死的！\n");

        command("go " + dir);
        return 1;
}






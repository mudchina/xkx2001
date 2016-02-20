//Cracked by Roath
// huoji.c 草店夥计

inherit NPC;
inherit F_DEALER;

string ask_me(string);

void create()
{
	set_name("店夥计", ({ "dian huoji", "huoji", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店夥计正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/wudang/obj/mianbing",
		"/d/city/obj/baozi",
		"/d/city/obj/jitui",
		"/d/city/obj/jiudai",
		"/d/village/npc/obj/bottle",
	}));
        set("inquiry", ([
	"武当山" : "出了这店，沿着黄土路往西南便到武当山了，山上的风景可是不能不尚啊。\n",
	"武当派" : "嘿嘿，近年来武当派的名气可真不小啊，尤其是武当七侠的名堂江湖上只怕没人不晓吧。\n",
        ]) );

	setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}


void greeting(object me)
{
	if( !me || environment(me) != environment() ) return;
	if( base_name(environment(me)) != "/d/wudang/caodian" ) return;
	
	switch( random(2) ) {
		case 0:
			say( "店夥计笑咪咪地说道：这位" + RANK_D->query_respect(me)
				+ "赶路一定累了，歇歇腿吧。\n");
			break;
		case 1:
			say( "店夥计用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(me)
				+ "，请进请进，要不要我帮您把牲口也喂一下？\n");
			break;
		}

}



//Cracked by Roath
// farmer.c 农夫
// A.P.

inherit NPC;

int do_push(string);

void create()
{
        set_name("武三通", ({ "wu santong", "nong", "farmer", "wu" }));
        set("long", 
			"一个中年农夫。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 30);
        set("con", 25);
        set("dex", 30);
        set("shen", 0);
        
        set("max_qi", 2000);   
       set("max_jing", 500);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 120);
//        set("combat_exp", 350000);
        set("score", 5000);

        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("axe", 160);
        set_skill("finger", 130);
        set_skill("yiyang-zhi", 120);
        set_skill("duanshi-shenfa", 100);
        set_skill("kurong-changong", 80);

        map_skill("dodge", "duanshi-shenfa");
        map_skill("force", "kurong-changong");
	map_skill("finger", "yiyang-zhi");
	prepare_skill("finger", "yiyang-zhi");

        set("inquiry", ([
	"上山" : "什么上山下山，没看见我都快挺不住了吗？！\n",
        ]));

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_push", "push");
}

int do_push(string arg)
{
	object me;
	me=this_player();

	if (arg!="rock") { return 0; }
	if (environment(me)!=find_object("/d/dali/yideng5.c")) { return 0; }
	if (me->query_str()>25 && (int)me->query("max_neili")>=1000) {
		write("你大喊一声：大叔，顶住，我来帮你！！！\n");
		write("你使出全身力气，双掌上推，帮农夫将大石推起尺许来高！\n");
		write("农夫身形一晃，闪在大石之外，却不去牵牛，把一双大眼将你上下不停地打量！\n\n");
		me->move("/d/dali/yideng6.c");
		return 1;
	}

	write("你试图用力助农夫推开大石，无奈显然功力不够，怎样用力也没效果。\n");
	return 1;
}

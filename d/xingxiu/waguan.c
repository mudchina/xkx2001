//Cracked by Roath
//10/8/00

inherit ITEM;
#include <ansi.h>

void setup()
{}


void create()
{
        set_name("瓦罐", ({"wa guan", "wa", "guan"}));
        set_weight(15000);
        set_max_encumbrance(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "只");
                set("long", "一只质地精细的瓦罐。\n");
  		set("no_drop", 1);
        	set("no_get", 1);
	        set("no_steal", 1);
		set("no_sell", 1);
        }

//        ::create();
}
int is_container() { return 1; }

void init()
{
   add_action("do_hold", "kou");                       
   add_action("do_xiulian", "xiulian");	
}

int do_hold(string arg)
{
        string me, what;
        object ob, obj=this_object();

        if( !arg || sscanf(arg, "%s", what)!=1 )
                return notify_fail("命令格式: kou <物品> 。\n");

        ob = present(what, environment(this_player()));
        if( !ob ) return notify_fail("这里没有" + what + "这样东西。\n");

	if (ob->query("id")!="du chong") return notify_fail("这东西最好不要抓。\n");

        if (this_player()->is_busy()) return notify_fail("你正忙着呢。\n");

	else {
          	if(random(this_player()->query_skill("poison",1))*5 > (this_player()->query_skill("force")))
                        {    
                        message_vision("$N举起手中的瓦罐猛地将毒虫扣住，然后小心翼翼地将瓦罐翻起来盖住。\n",this_player());

                        this_player()->add("neili",-50);
			set("bug_hold",1);
			set("long", "一只质地精细的瓦罐。\n里面盛着一只毒虫。\n");
			this_player()->set_temp("bug_hold",1);		
                        destruct(ob);
                        }
                else message_vision("$N猛的出手用瓦罐扣向"+ob->query("name")+",但"+ob->query("name")+"机灵的跳开了。\n",this_player());
 		
                this_player()->start_busy(random(1)+1);               
                return 1;
        }
}

int do_xiulian()
{
        if (query("bug_hold")!=1) return notify_fail("没有毒虫，你想要用空气修行吗？\n");
	message_vision(HIR"$N运起内力，然后闭上眼睛将手指伸入瓦罐。\n"NOR, this_player());
        message_vision(HIR"毒虫立刻咬住$N的手吸起血来。\n"NOR, this_player());
	call_out("do_xiulian2", 8, this_player());
	this_player()->start_busy(10);
	return 1;
}

void do_xiulian2(object me){
	object dan;
	dan=new("/d/xingxiu/obj/dudan");
	dan->set("player",this_player()->query("id"));
	message_vision(HIG"毒虫将血吸完，肚子高高涨起，啪地一身掉进罐底，挣扎了几下，死了。\n"NOR, this_player());
	message_vision("$N将死虫子拿出瓦罐，将其肚子剖开，拿出一粒腥如血的丹丸来。\n"NOR, this_player());
	tell_object(this_player(),"你中毒了！\n");
        this_player()->apply_condition("insect_poison", this_player()->query("poison"));
        this_player()->improve_skill("poison", 200);
	this_player()->set_temp("found",1);
	dan->move(this_player());
}


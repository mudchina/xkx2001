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
                set("long", "一只质地精细的瓦罐，不知道有什么用途。\n");
  		set("no_drop", 1);
        	set("no_get", 1);
	        set("no_steal", 1);
		set("no_sell", 1);
        }

}
int is_container() { return 1; }

void init()
{
   add_action("do_hold", "kou");                       
   add_action("do_xiulian", "xiulian");	
}

int do_hold(string arg)
{
        string what;
        
	object ob;
	object obj=this_object();
	object me=this_player();

	if( !arg || me != this_player(1)) 
			return notify_fail("命令格式: kou <物品> 。\n");
	
	ob = present(arg, environment(me));
	if( !ob || !living(ob))
		return notify_fail("这里没有这个生物。\n");
	
        if (ob->query("sub")!="xx_job") return notify_fail("这东西最好不要抓。\n");

        if (this_player()->is_busy()) return notify_fail("你正忙着呢。\n");
        
        if (this_player()->query_temp("hold")) return notify_fail("已经有毒虫了，修炼吧。");
	
	if (ob->query("playerid")!=(string)this_player()->query("id") )
        	return notify_fail("别人找出来的，你好意思抓吗？:)\n");
        
	if(this_player()->query_skill("poison",1) > random(this_player()->query_skill("force")*3)) {    
                        message_vision(HIG"$N举起手中的瓦罐猛地将"+ob->query("name")+"扣住，然后小心翼翼地将瓦罐翻起来盖住。\n"NOR,this_player());
			set("bug_hold",1);
			set("count", random(10));
			set("long", "一只质地精细的瓦罐。\n里面盛着一只"+ob->query("name")+"。\n");
			set("xiulian", random(5));
			set("bug_name", ob->query("name"));
			this_player()->set_temp("bug_hold",1);	
			this_player()->set_temp("found",1);		
                        destruct(ob);
         } else message_vision("$N猛的出手用瓦罐扣向"+ob->query("name")+",但"+ob->query("name")+"机灵的跳开了。\n",this_player());
 	 
 	 this_player()->add("neili",-50);
         this_player()->start_busy(random(1)+1);               
         return 1;
         
}

int do_xiulian()
{
	if(this_player()->is_busy()) return notify_fail("你正忙着呢。\n");
        if (query("bug_hold")!=1) return notify_fail("没有毒虫，你想要用空气修行吗？\n");
	message_vision(HIR"$N运起内力护住全身大穴，然后闭上眼睛将手指伸入瓦罐。\n"NOR, this_player());
        message_vision(HIR+query("bug_name")+"立刻咬住$N的手吸起血来。\n"NOR, this_player());
	call_out("do_xiulian2", 10, this_player());
	this_player()->start_busy(10);
	return 1;
}

void do_xiulian2(object me){
	object dan;	
	message_vision("$N运功完毕，身子一震，慢慢地站了起来。\n",me);
	if (query("xiulian")<=0){
		dan=new("/d/xingxiu/obj/dudan");
		dan->set("player",this_player()->query("id"));
		message_vision(HIG+query("bug_name")+"将血吸完，肚子高高涨起，啪地一身掉进罐底，挣扎了几下，死了。\n"NOR, this_player());
		message_vision("$N将死"+query("bug_name")+"拿出瓦罐，将其肚子剖开，拿出一粒腥如血的丹丸来。\n"NOR, this_player());
		if(me->query("combat_exp")>100000){
			tell_object(this_player(),HIR"你中毒了！\n"NOR);
        		this_player()->apply_condition("huadu_poison", this_player()->query_skill("poison",1)/5);
        	}
        	this_player()->set_temp("found",1);
		this_object()->delete("bug_hold");
		set("long", "一只质地精细的瓦罐。\n");
		dan->move(this_player());
	} else message_vision(HIR+query("bug_name")+"肚子高高涨起，啪地一身掉进罐底。\n"NOR, this_player());
        add("xiulian",-1);
        if (this_player()->query_skill("poison",1)<420)
        	this_player()->improve_skill("poison", this_player()->query_skill("feixing-shu",1));
}


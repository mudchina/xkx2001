//Cracked by Roath
//wzfeng changed 99/11/29
#include <ansi.h>

inherit ITEM;

#include "/clone/drug/drug_list.h"

#define _DES "一只小巧玲珑的药炉，青铜质地，模样古旧，两侧各有一只兽口吞环，顶上\n一个盖子(lip)，盖中偏左有一孔，炉下设有一只炭盆，盆内的木炭(coal)\n看来是新加的。\n"
#define _FIRE HIR"\n药炉下正燃着火。\n"NOR
#define _OPEN "药炉盖子已经揭开。\n"
 
void create()
{
        set_name(CYN"药炉"NOR,( {"yao lu","yaolu","lu"} ));
        set_weight(3000);
        if (clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","只");
                set("long",_DES);
                set("value",10000);
                set("material","bronze");
                set("no_get",1);
				set("cure_s",0);
                set("cure_d",0);
                set("cure_n",0);
                set("count",6);
                set("drug","none");
        }
        setup();
}

void init()
{
        add_action("do_open","open");
        add_action("do_addyao","add");
        add_action("do_close","close");
        add_action("do_addwater","dao");
        add_action("do_addwater","pour");
        add_action("do_burn","burn");
        add_action("do_miehuo","mie");
        add_action("do_aoyao","aoyao");
        add_action("do_aoyao","lianyao");
        add_action("do_quyao","qu");
}


int do_open(string arg)
{
        object obj,me;
        me = this_player();
        obj = this_object();

        if (me->is_busy() 
        || me->query_temp("pending/exercising") 
        || me->query_temp("exit_blocked"))
                return notify_fail("你现在正忙着呢。\n");

        if (arg != "lip")
                return notify_fail("你要打开什么？\n");
                
        if (query("open"))
                return notify_fail("盖子已经打开了。\n");

        if (query("is_burning"))
        {
                message_vision(RED"只听「啊」的一声惨叫，原来$N被药炉烫了手。\n"NOR,me);
                me->add("qi",-150+random(50),"被烫死了。");
                set("long",_DES+_FIRE);
				return 1;
        }
        message_vision("$N将药炉盖子揭开。\n", me);
        set("long",_DES+_OPEN);
        set("open", 1);
        return 1;
}
        

int do_addyao(string arg)
{
        object me, obj,ob;
        string item, target; 
        int s,d,n;
        me = this_player();
        ob = this_object();
        
        if (!query("open"))
                return notify_fail("你先把盖子打开吧。\n"); 

        if (!arg || sscanf(arg, "%s in %s", item, target) != 2 )
            return notify_fail("你要将什么东西放进哪里？\n");
                
	  if (item == "all" ) 
                return notify_fail("这小小药炉怎么装得下这么多东西？\n");
                
        if (!objectp(obj = present(item, me)))
                return notify_fail("东西呢？\n");
                                                                
        if (!obj->query("yaocai"))
                return notify_fail("药炉里只能放药材。\n");
				if (query("is_burning"))
                return notify_fail("火已点燃，不要乱动。\n");
                
        if (query("count") < 1)
                return notify_fail("你已放了太多药材了。\n");
        
        s = obj->query("cure_s");
        d = obj->query("cure_d");
        n = obj->query("cure_n");
        //add by wzfeng
		if(!sizeof(query("drug_list")))
		{
			set("drug_list/1",obj->query("id"));
		}
		else
			set("drug_list/"+(sizeof(query("drug_list"))+1)+"",obj->query("id"));

		


        
        message_vision("$N把一"+obj->query("unit")+obj->query("name")+"放进药炉。\n",me);
        destruct(obj);
        add("count",-1);
        add("cure_s",s);
		add("cure_d",d);
        add("cure_n",n);
		if (wizardp(me))       
        printf("%d\t%d\t%d\t\n",query("cure_s"),query("cure_d"),query("cure_n"));
        
        set("ready", 1);
        return 1;
}

int do_addwater(string arg)
{
        object ob,me;
        me = this_player();
        if (!query("open"))
                return notify_fail("你先把盖子打开吧。\n");
                
        if (arg != "water")
                return notify_fail("你要添加什么？\n");
                
        if (!query("ready"))
		 return notify_fail("你要烧开水吗？\n");
                
        if (!present("jiudai", me))
                return notify_fail("你需要一个水袋。\n");

        ob = present("jiudai",me);      
        if (ob->query("liquid/remaining") < 1)
                return notify_fail(ob->query("name")+"里面的水已经用光了。\n");

        if (query("is_burning"))
                return notify_fail("火已点燃，不要乱动。\n");
        
        ob->add("liquid/remaining", -1);
        set("water",1);
        message_vision("$N从"+ob->query("name")+"中倒了一些水在药炉里。\n",me);
        return 1;
}

int do_close(string arg)
{       
        object me;
        me = this_player();
        
		 if (arg != "lip")
                return notify_fail("你要关闭什么？\n");
                
        if (!(query("open")))
                return notify_fail("盖子已经扣上了。\n");
                
        if (query("is_burning"))
        {
                message_vision(RED"只听「啊」的一声惨叫，原来$N被药炉烫了手。\n"NOR,me);

                me->add("qi",-150+random(50),"被烫死了。");
                set("long",_DES+_OPEN+_FIRE);
                return 1;
        }
        message_vision("$N把药炉盖子扣上。\n", me);
        set("long",_DES);
        set("open", 0);
        return 1;
}

int do_burn(string arg)
{
        object me;
		me = this_player();

        if (arg != "coal")
                return notify_fail("你要点燃什么？\n");
                
        if (!present("fire",me))
                return notify_fail("你用什么点火？\n");
                
        if (!(query("ready")))
                return notify_fail("药炉里什么都没有。\n");
                
        if (query("is_burning"))
                return notify_fail("火已经点燃了。\n");
                
        if (query("open"))
                return notify_fail("你先把盖子盖好吧。\n");

        message_vision(RED"$N将炭盆点燃。\n\n"NOR,me);
        message_vision(HIB"青蓝色的火苗轻轻跳动，将$N的脸映得阴森恐怖。\n"NOR,me);
        set("is_burning", 1);
        
        if (query("open"))
                set("long",_DES+_OPEN+_FIRE);
		else
                set("long",_DES+_FIRE);
        
        remove_call_out("burning");
        call_out("burning",10+random(5),me);
        return 1;
}

int do_miehuo(string arg)
{
        object me;
        me = this_player();
        if (arg != "huo")
                return 0;
                
        if (!(query("is_burning")))
                return notify_fail("火还没点燃。\n");
                
        message_vision(RED"$N将炭火熄灭。\n"NOR, me);
        
        if (query("open"))
                set("long",_DES+_OPEN);
        else
		  set("long",_DES);
        set("is_burning", 0);
        set("fire_ready", 0);
        remove_call_out("burning");
        return 1;
}

void burning(object me)
{
        object obj = this_object();

        if (!query("water"))
        {
                set("long","一只小巧玲珑的炼药炉。\n");
                message_vision(HIR"突然间药炉内火光大盛，黑烟冒出，$N急忙将火头扑灭。\n"NOR,me);
                message_vision(HIR"$N取出药材一看，已经烧成一团焦炭。\n"NOR,me);

                obj->set("open",0);
                obj->set("is_burning",0);
                obj->set("ready",0);
                obj->set("fire_ready",0);
                obj->set("pending",0);
                obj->set("done",0);
				 obj->set("long",_DES);
                obj->set("cure_s",0);
                obj->set("cure_d",0);
       

        obj->set("cure_n",0);
                obj->set("drug","none");
                obj->set("count",6);
                
                return;
        }
        message_vision("\n"HIY"炭火渐渐明亮，看来可以开始了。\n"NOR,me);
        set("fire_ready", 1);
        return;
}
        

int do_aoyao()
{
        object me;
        int time,s,d,n,ds,dd,dn,i;
        me = this_player();
        time = 0;

        if (me->is_busy()|| me->query_temp("pending/exercising")
        || me->query_temp("exit_blocked"))
                return notify_fail("你现在正忙着呢。\n");

        if (!query("fire_ready"))
                return notify_fail("火侯未到！\n");
                
        if ((int)me->query("neili") < 1000)
                return notify_fail("你的内力不足！\n");

        if ((int)me->query("jingli") < 300)
                return notify_fail("你的精力不足！\n");
                        
        s = query("cure_s");
        d = query("cure_d");
        n = query("cure_n");

if (wizardp(me))
        printf("%d\t%d\t%d\t\n\n--------------------\n",s,d,n);

        for (i=0;i<sizeof(drug_list);i++)
        {
                ds = drug_list[i]["s"];
				 dd = drug_list[i]["d"];
                dn = drug_list[i]["n"];
if (wizardp(me))                
        printf("%d\t%d\t%d\t\n",ds,dd,dn);
                if ( s == ds && d == dd && n == dn )
                {
                        set("drug",drug_list[i]["file"]);
                        time = drug_list[i]["time"];
                        break;
                }
        }
        
        message_vision(HIC"$N一手靠近炉火一抽一放，借内力操控火势；一手握住药杵，从盖上孔中伸入\n不停搅拌。\n"NOR,me);
        message_vision(HIR"\n$N不停的重复运动，一会儿已是满身大汗。\n"NOR,me);
        if (time == 0)
                time = 20;
        if (time > 30)
                me->start_busy(time-random(5)+1);
        else
                me->start_busy((int)(time/2)+1);
        set("pending", 1);
        remove_call_out("finish");
        call_out("finish",time,me);
		  return 1;
}
                        
void finish(object me)          
{
        object obj;
        int gain, neili;
        obj = this_object();
        
        message_vision("\n"HIY"$N深吸一口气，停了下来。\n"NOR,me);
        me->add("neili",-(700+random(300)));
        me->add("jingli",-random(300));

        neili = (int)me->query("neili");
        gain = (int)(me->query("neili")/1000);  
        if ( (query("drug") != "none") 
        && (me->query("potential") < me->query("max_potential")) ) {

                if( gain > 50 ) {
                        write_file("/log/test/Yaolu",
                        sprintf("%s(%s) has %s neili on %s. \n",
                        me->name(), getuid(me), 
                        chinese_number(neili), ctime(time())) );
						 gain = 20+random(20);
                }

                me->add("potential",gain*2);
                me->add("combat_exp",gain);
        }
        
        if (me->query("potential") > me->query("max_potential"))
        me->set("potential",me->query("max_potential"));

        set("done", 1);
        set("pending",0);
}


int do_quyao(string arg)
{       
        object ob,me,obj;
        me = this_player();
        obj = this_object();
        
        if (me->is_busy()
        || me->query_temp("pending/exercising")
		|| me->query_temp("exit_blocked"))
                return notify_fail("你现在正忙着呢。\n");

        if (arg != "yao")
                return notify_fail("你要取什么？\n");

        if (query("pending"))
                return notify_fail("你正在运功炼药。\n");
                
        if (!(query("done")))
                return notify_fail("你要取什么？\n");
                
        if (query("is_burning"))
        {
                message_vision(RED"只听「啊」的一声惨叫，原来$N被药炉烫了手。\n"NOR,me);
                me->add("qi",-150+random(50),"被烫死了。");
                return 1;
        }
        
        if (!(query("open")))
                return notify_fail("你先把盖子打开吧。\n");
        
        if (!query("drug") || query("drug") == "none")
		  {


                message_vision(HIB"$N开炉一看，炉中之物象一团浆糊一样，看来没什么用。\n"NOR,me);
        }
        else
        {               
			    ob = new(DRUG_D(query("drug")));
//			    ob = new("/clone/drug/buyin-wan");
                message_vision("$N从药炉中取出一"+ob->query("unit")+ob->query("name")+"\n\n", me);
//add by wzfeng
				if(ob->query("id")=="buyin wan")
				{
					ob->set("drug_list",query("drug_list"));
				}

                ob->move(me);
                me->start_busy(3);
        }
		delete("drug_list");        
        obj->set("open",0);
        obj->set("is_burning",0);
        obj->set("ready",0);
        obj->set("fire_ready",0);
        obj->set("pending",0);
        obj->set("done",0);
        obj->set("long",_DES);
        obj->set("cure_s",0);
        obj->set("cure_d",0);
        obj->set("cure_n",0);
        obj->set("drug","none");
        obj->set("count",6);
        return 1;
}

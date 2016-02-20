//Cracked by Roath
// long_shiliang.c 龙石梁
// xQin 11/00

inherit ROOM;
#include <ansi.h>
string look_lu();
int burnt, start_burn; 
int is_burning();

void create()
{
        set("short", "龙石梁");
        set("long","石梁上地形险峻，若非轻功极高亦无法跃上来。只见石梁顶端雕刻了一\n"
"个香炉(lu)。\n\n"
"    "HBWHT+HIC"这里上接青天，下临深谷，至身其中有如在云幻景。\n\n"NOR
	);
	set("item_desc",([
            "lu" : ( :look_lu:),
        ]));
        setup();

        burnt = 0;
	call_out("burn", 120, 1);

}

void init()
{
	add_action("do_jing", "jing");
	add_action("do_jump", "jump");
}

int is_buring()
{
	return (burnt < 3);
}	

void burn(int phase)
{
	burnt = phase;
	
	if (burnt < 3) call_out("burn", 120, phase + 1);

} 
string look_lu()
{

	switch (burnt) {
	case 0:
		return(YEL"香炉上供奉着新上的香火，芬芳四周。\n"NOR);
		break;
	
	case 1:
		return(YEL"香炉上香烟缭绕，香火烧得正旺。\n"NOR);
		break;
		
	case 2:
		return(YEL"香炉上的香火已经烧了大半，几缕余烟，奄奄欲息。\n"NOR);
		break;
		
	default:
		return(YEL"香炉上只剩下一堆烟灰，等着有人敬(jing)龙头香！！\n"NOR);
		break;
		
		}
}
int do_jing(string arg)
{
	object obj, me;
	
	if ( !objectp(me = this_player()) ) return 0;	
	
	if (!arg ) return notify_fail("你要敬什么？\n");  
					
	if( !objectp(obj = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	           
	if ( obj->query("id") != "incense" 
	 ||  obj->is_character() ) return notify_fail("只能敬香！\n");  
	
	burnt = 0;
	remove_call_out("burn");
	call_out("burn", 120, 1);
	
	message_vision(HIC"$N拿出一"+obj->query("unit")+obj->query("name")
		+"，恭恭敬敬地插在龙头的香炉上。\n"NOR, me);
	if (me->query("family/family_name") == "武当派" )
	me->add("combat_exp", 20+random(20));
	me->add("potential", 10+random(10));	
	if (me->query("age") < 20 && me->query("wudang/offerring") < 60)
	me->add("wudang/offerring", 2);
	if (me->query("age") < 30 && me->query("wudang/offerring") < 120)
        me->add("wudang/offerring", 2);
	if (me->query("age") > 30 && me->query("wudang/offerring") < 150)
	me->add("wudang/offerring", 2);	                                         		                              		

	destruct(obj);
	
	return 1;		
}

int do_jump(string arg)
{
	object me;
	int lv, cost;
	me = this_player();
	
	
	if(me->is_busy())
        return notify_fail("你还在忙着呢。\n");
        
        cost = (me->query_dex()*me->query_skill("dodge")/ me->query_con() )/10;
        if (cost < 10) cost= 10;
        if( me->query("jingli") < 30)
        return notify_fail("你已经精疲力竭了。\n");
        
	if (arg == "back" || arg == "shidian" ) {      
	message_vision("$N纵身跳回石殿。\n\n", me);
        me->move(__DIR__"shidian");
        message("vision", me->name() + "纵身从龙石梁上跳了下来。\n",environment(me), ({me}) );
        me->add("jingli", -cost);  
        
	lv = me->query("int", 1)*2;
	if (me->query_skill("dodge") > 200) lv /=2;
	if (me->query_skill("dodge") > 300) lv /=3;
	if (me->query_skill("dodge") > 400) lv /=4;
	if (me->query_skill("dodge") > 500) lv /=5;
	
	me->improve_skill("dodge", lv+random(lv) );
	me->start_busy( 1 );
	if (me->query("family/family_name") == "武当派" 
	&& me->query_skill("tiyunzong", 1) > 0 )
	me->improve_skill("tiyunzong", random(lv) );
	return 1;
	}
        return 1;
}
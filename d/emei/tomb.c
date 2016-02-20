//Cracked by Roath
// d/emei/tomb.c 郭襄之墓
// xbc 1997/02/03

#include <ansi.h>

inherit ROOM;

int visited, start_visit; 
int is_visiting();
int look_tomb();
int dig_times;

void create()
{
	set("short", "郭襄之墓");
	set("long", @LONG
这里是一座规模不大的墓，墓碑上刻着几个大字：峨嵋派祖师郭襄之墓。
原来这是峨嵋派创派祖师郭襄的墓。郭女侠乃是大侠郭靖的小女儿。她晚年
在峨嵋山定居，创立了峨嵋派，死后峨嵋弟子将她安葬在此处。这里四季如
春，常年鲜花盛开，十分幽静。
LONG
	);
	
	set("exits", ([
		"south" : __DIR__"grassland",
		"east" : __DIR__"tombpath",
	]));
	
	set("objects", ([
		__DIR__"npc/lamb" : 1,
	]));
	set("item_desc", ([
		"tomb" : (: look_tomb :),
	]));
		                                
	set("cost", 1);
	setup();
	
	dig_times = 0;
	set("tomb_door", 0);	//door closed
	set("guard_count", 1);
	visited = 0;
	call_out("visit", 120, 1); 
}

void init()
{
	add_action("do_jing", "jing");
	add_action("do_clean", "sao");
	add_action("do_clean", "clean");
	add_action("do_dig", "dig");
	add_action("do_dig", "wa");
}

int is_visiting()
{
	return (visited < 3);
}	

string look_tomb()
{
	if ( !query("tomb_door")) {
		switch (visited) {
		case 0:
			return(GRN"墓旁的草剪得整整齐齐，墓碑也纤尘不染。\n"NOR);
			break;
		case 1:
			return(YEL"墓前插了几柱香，香烟缭绕。\n"NOR);
			break;
		case 2:
			return(MAG"墓前放着几朵小野花。\n"NOR);
			break;
		default:
			return(WHT"墓旁杂草丛生，好久没有人来打扫过了。\n"NOR);
			break;
		}
	}
	else 
		return("墓后给人掘开一个洞，一道大石门露出来。\n");
} 

void visit(int phase)
{
	visited = phase;
	
	if (visited < 3) call_out("visit", 120, phase + 1);

}

int do_jing(string arg)
{
	object obj, me;
	
	if ( !objectp(me = this_player()) ) return 0;	
	if (!arg ) return notify_fail("你要敬什么？\n");  
	if( !objectp(obj = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if ( !(obj->id( "incense")) && !(obj->id( "flower")) ) 
		return notify_fail("你敬这个做什么？\n");  
	
	visited = 0;
	remove_call_out("visit");
	call_out("visit", 120, 1);
	
	message_vision("$N拿出一"+obj->query("unit")+obj->query("name")
		+"，恭恭敬敬地放在墓前。\n", me);
		
	me->add_temp("visit_tomb", 1);	                                         		                              		
	destruct(obj);
	
	return 1;		
}

int do_clean(string arg)
{
        object me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( arg == "tomb" ) {
                message_vision("$N将墓边的杂草清理干净。\n", me);
		me->add_temp("visit_tomb", 1);
                return 1;
	}
	return 0;
}

int do_dig(string arg)
{
	object weapon, me = this_player();
	object guard;
	object room = load_object(__DIR__"tomb2");
	
	if ( !arg || arg == "" ) return 0;

	if ( arg == "tomb" || arg == "mu") {
		if ( query("tomb_door")) {
			write("墓已经掘开了，一道大石门横在地上。\n");
			return 1;
		}
		if( me->is_fighting() ){
			return notify_fail("你正忙着呐！\n");
		}
		if( !objectp(weapon = me->query_temp("weapon")) ) {
			message_vision(HIR"$N向坟墓乱挖一通，弄得双手鲜血淋淋。\n"NOR, me);
			me->add("jingli", -random(30));
			me->add("qi", -random(30));
                	return 1;
		}
		else if ((string)weapon->query("skill_type") != "sword"
                	&& (string)weapon->query("skill_type") != "blade" 
                	&& (string)weapon->query("skill_type") != "axe" 
			&& (string)weapon->query("id") != "tie qiao") {
        		message_vision(WHT"$N操起手中" + weapon->name() +WHT"朝坟墓乱挖一通。\n"NOR, me);
                	message_vision(WHT"结果「啪」地一声，$N手中的" + weapon->name()
                        	+ "已经断为两截！\n"NOR , me );
                	weapon->unequip();
                	weapon->move(environment(me));
                	weapon->set("name", "断掉的" + weapon->query("name"));
                	weapon->set("value", 0);
                	return 1;
        	}

        	message_vision(WHT"$N操起手中" + weapon->name() + WHT"，吭吃吭吃地挖起墓来。\n"NOR, me);
		me->add("jingli", -(8+random(36-(int)me->query("str"))));
        	me->receive_damage("jingli", 8+random(36-(int)me->query("str")),
                 	"掘墓累死了");

		dig_times++;

		if ( random(3) && (query("guard_count") > 0 ) 
		&& ! objectp(guard=present("guard", environment(me)) )) {
			add("guard_count", -1);
			guard = new(__DIR__"npc/guard2.c");
			guard->move(__FILE__);
			me->set_temp("digger/myname", 1);
			message_vision(RED"忽然间一个青衣女子由侧地里冲出来，厉声道：大胆盗贼，吃我一剑！\n"NOR,me); 
			message_vision(YEL"$N一下子满脸杀气，决定杀人灭口！\n\n"NOR,me);
			if( !guard->is_killing(me->query("id")) )
			guard->kill_ob(me);
			if( !me->is_killing(me->query("id")))
			me->kill_ob(guard);
			return 1;
		}

		if ( objectp(guard=present("guard", environment(me)) )) {
			guard->set_temp("digger/myname", 1);
			message_vision(RED"守墓弟子厉声道：大胆盗贼，吃我一剑！\n"NOR,me); 
			message_vision(YEL"$N一下子满脸杀气，决定杀人灭口！\n\n"NOR,me);
			if( !guard->is_killing(me->query("id")) )
			guard->kill_ob(me);
			if( !me->is_killing(me->query("id")))
			me->kill_ob(guard);
			return 1;
		}
		if ( dig_times > (15+random(5)) ) {
			message_vision("墓碑后面被掘开个大洞，眼前出现了一道石门。\n",me); 
			set("tomb_door", 1);
			set("exits/down", __DIR__"tomb2");
			room->set("exits/up", __FILE__);
			tell_room(room, "门外传来沙沙声，似乎有人将泥土掘开来了。\n");
			delete("dig_times");
			remove_call_out("close_tomb");
			call_out("close_tomb", 30, me);
                	return 1;
		}
		else
			return 1;
        }
}


void close_tomb()
{
	object room = load_object("d/emei/tomb2");

	if( !query("tomb_door") ) return;

	message("vision", "忽然，门旁的泥土塌了下来，把掘开的石门给盖住了。\n", this_object() );
	delete("exits/down");
	room->delete("exits/up");
	tell_room(room, "门外又传来沙沙声，似乎泥土塌下来，把石门给盖住了。\n");
	dig_times = 0;
	set("tomb_door", 0);
}


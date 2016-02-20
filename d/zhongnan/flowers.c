//Cracked by Roath
// wsky, 5/7/00
inherit ROOM;

#include <ansi.h>
#include "/d/REGIONS.h";

int do_hide();
int do_look();
int event_one(object me);
int event_two(object me);
int event_three(object me);

void create()
{
        set("short", "花丛中");
        set("long", @LONG
这里是终南山后山的花丛中，这丛红花排开来长达数丈，密密层层，奇香
扑鼻。但见花丛有如一面大屏风，红瓣绿枝，煞是好看，四下里树荫垂盖
，便似天然结成的一座花房树屋。

这些红花(flowers)似乎可以推开。
LONG);

	set("item_desc",(["flowers" : "这花丛既深且密，到是一个很好的藏身之处。\n",]));

        set("exits", ([ 	
        ]));

        set("no_clean_up", 0);

        set("outdoors", "zhongnanshan");

        set("cost", 2);
        setup();
        

}

void init()
{       
        add_action("do_hide", "hide");
        add_action("do_hide", "cang");
        add_action("do_push", "push");
        add_action("do_push", "tui");
}

int do_hide(){

	object me=this_player();
	if (me->is_busy())
		return notify_fail("你现在正忙着哪！\n");

	if (me->query_temp("hiding"))
		return notify_fail("你已经藏好了。\n");
	
	if (me->query_temp("found_lianhuan_book"))
		return notify_fail("你还藏什么？\n");
	
	tell_object(me, "你小心翼翼地藏到了花丛中。\n");
	
	me->set_temp("hiding",1);
	
	
	call_out("event_one", 10, me);
	
	return 1;
}

int do_push(){

	object room;
	object me=this_player();
	
	if (me->is_busy())
		return notify_fail("你现在正忙着哪！\n");

	tell_object(me, "你轻轻地推开花木，向外走了出去。\n");
	
	me->set_temp("hiding",1);
	me->delete_temp("hiding");
	
	room = load_object("/d/zhongnan/milin4");
	
	room->set("hide_person",1);
	room->delete("hide_person");
	
	me->move(room);
    return 1;

}

int event_one(object me){
	
	if(me->query_temp("hiding")){
	
		tell_object(me, HIG"突然间山后传来脚步声响，两个人一面说话，一面走近。原来竟是尹志平和赵志敬。两个人越说越大声，竟似在互相争辩。\n"NOR);
		
		remove_call_out("event_one");
		call_out("event_two", 5, me);
	}

	return 1;
}

int event_two(object me){
	
	if(me->query_temp("hiding")){
	
		tell_object(me, HIG"只听见赵志净冷笑到：“你不守清规，犯了我教的大戒，怎能再做首座弟子？”你心下纳闷，不知赵志敬什么意思。\n"NOR);
		tell_object(me, HIG"你心中嘀咕中，尹赵两人已越吵越凶。突然间，赵志敬喊道：“你还敢抵赖？咱们招丘师伯评理去！\n"NOR);
		tell_object(me, HIG"尹志平再也忍耐不住，唰地一声，长剑出鞘，分心便刺，赵志敬侧身避开，抽剑出匣，两人打到一起。\n"NOR);
		
		remove_call_out("event_one");
		call_out("event_three", 15, me);
	}
	
	return 1;
}


int event_three(object me){
	
	if(me->query_temp("hiding")){
	
		tell_object(me, HIG"只见尹赵而人出招凌厉变幻，已非你所知，你不禁手心中全是冷汗。\n"NOR);
		tell_object(me, HIR"\n\n再拆数招，尹志平左剑平刺，右掌正击，同时左腿横扫而出，正是全真派中的“三连环”绝招。\n"NOR);
				
		remove_call_out("event_two");
		call_out("event_four", 15, me);
	}
	
	return 1;
}

int event_four(object me){
	
	object book;
	
	if(me->query_temp("hiding")){
	
		tell_object(me, HIG"只见尹志平大声怒喝，连走险招，竟然不再挡驾对方来招，一味猛攻。\n"NOR);
		tell_object(me, HIG"\n\n再拆数招，赵志敬在对方拼命下渐渐招架不住，撒腿向别处逃去。\n"NOR);
		
		tell_object(me, HIY"\n\n尹志平一愣，随后追去，你只听见嗒地一声，一本小册子从尹志平身上掉了下来。\n"NOR);
		tell_object(me, "\n\n待尹志平走后，你忙起身将那小册子拣了起来。\n"NOR);
		
		me->set_temp("found_lianhuan_book", 1);
		me->delete_temp("hiding", 1);
		book=new("/d/zhongnan/obj/lh_book");
		book->set("player_id", me->query("id"));
		book->move(me);
						
		remove_call_out("event_three");
		
	}
	
	return 1;
}

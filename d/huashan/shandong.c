//Cracked by Roath
// 华山山洞
// qfy 26/6/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_mianbi();
int do_strike(string);

void create()
{
   set("short", "山洞");
   set("long", @LONG
山洞内有块光溜溜的大石，不知道曾有多少华山派的前辈在此思过面
壁，以致这块大石竟被坐得滑溜。石壁(wall)左侧刻着「风清扬」三个大
字，是以利器所刻，笔划苍劲，深有半寸。这三字刻得劲力非凡，想必其
人武功一定十分了得。
LONG
	);
   set("exits", ([ /* sizeof() == 1 */
   "out" : __DIR__"siguoya",
   ]));

   set("item_desc", ([
      "wall" : "一面很厚的石壁。\n",
   ]));
       
	set("cost", 2);
   setup();
}

void init()
{
   object me = this_player();

   if ( interactive(me) && me->query("huashan/job_pending") ) {
	me->set_temp("hz_job/sgy", 1);
   }

   add_action("do_mianbi","面壁");
   add_action("do_mianbi","mianbi");
   add_action("do_strike","strike");
   add_action("do_lingwu","lingwu");
}

int do_mianbi()
{
   int shen_n, check, level;
   object me = this_player();
   shen_n = me->query("shen");

   level = (int)me->query_skill("force",1);
   check = level*level*level;

   message_vision("$N在大石上坐了下来，面对着石壁趺坐静思。\n", me);

   if ( random(15) == 9 && !me->query_temp("marks/面") ) { 
      write("良久，你突然有一股破壁(strike)的冲动。\n");
      me->set_temp("marks/面", 1);
      }
      me->set_busy(10);

   if ( random(200) == 18 && (int)me->query("shen") < 30000 ) {
      me->set("shen",shen_n+20);
      write("你的侠义正气增加了。\n");
      }

   if ( random(200) == 1 && (int)me->query_skill("force", 1) <= 40 
   && check < (int)me->query("combat_exp")*10 ) {
      me->receive_damage("jing", 10, "心力绞瘁死了");
      me->improve_skill("force", me->query("int"));
      write("你领悟了内功方面的几个疑难。\n");
      }

   return 1;
}        
		
int do_lingwu()                
{
   object me = this_player();
   int level, check;

   level = (int)me->query_skill("zixia-gong",1);
   check = level*level*level;   
   
   if ( (int)me->query_skill("zixia-gong", 1) >= 50 
   && (int)me->query_skill("zixia-gong", 1) <= 100
   && present("zixia book", me) && (int)me->query("jing") > 29 ) {
      if ( check < (int)me->query("combat_exp")*10 ) {
	me->receive_damage("jing", 20, "心力绞瘁死了");
	me->improve_skill("zixia-gong", me->query("int"));
	write("你领悟了紫霞神功方面的几个疑难。\n"); 
      }
      else {
	write("你实战经验不足，无法领悟紫霞神功。\n");
      } 
   }    
   else if ( (int)me->query("jing") < 30 ) {
      write("你精神无法集中。\n");
   }            
   else {
     write("什么？\n");
   } 
	 
   return 1;
}    

int do_strike(string arg)
{
   int n, q;
   object weapon, me = this_player(); 
   n = me->query("neili");
   q = me->query("qi");
	
 if( me->query_temp("marks/面") ) 
 {
   
   if( !arg || arg!="wall" ) 
       return notify_fail("你要击破甚么？！\n");
				
   if( !objectp(weapon = me->query_temp("weapon"))
   || (string)weapon->query("skill_type") != "sword" ) {

   if( me->query("neili") < 200)
	return notify_fail("你的内力不够！\n");

	message_vision(
	"$N站起身来，拜出骑马蹲裆式，深吸一口气，双掌同时拍向石壁。\n", me);
	message_vision(
	"结果什么也没发生。看来破壁的方法并不对，$N自己反而受伤。\n", me);
	me->set("neili",n-200);
	me->receive_damage("qi",200,"体力透支过度死了");                                        
   }
   else {       
	if (n>=200) {
	   message_vision(
	   "$N举剑运足内力刺向石壁，擦的一声，剑竟尔插入石壁之中，直没至柄！\n", me);
	   message_vision(
	   "$N随即抽出剑来，但听得砰砰之声不绝，石头不住滚落，露出一个窄窄的孔道。\n", me);
	   set("exits/enter", __DIR__"yongdao1");
	   me->set("neili",n-200);
	   me->delete_temp("marks/面");
	   remove_call_out("close");
	   call_out("close", 5, this_object());
	}
	else {   
	   message_vision(
	   "$N举剑，运足内力刺向石壁，锵的一声，结果剑断人伤，原来内力不足！\n", me);
	   me->set("neili",0);
	   me->receive_damage("qi",200,"体力透支过度死了"); 
	   destruct(weapon);
	}
	
	return 1;
   }       

   return 1;
   
 }
 else {
   write("什么？\n");
 }     
   
 return 1;    
}

void close(object room)
{
    message("vision","石头稀里哗拉坍塌下来，又封住了入口。\n", room);
    room->delete("exits/enter");
}

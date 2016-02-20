//Cracked by Roath
// 华山甬道
// qfy 26/6/1996

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_strike(string);

void create()
{
        set("short", "甬道");
	set("long", @LONG
甬道边伏着一具骷髅，骷髅身上的衣着已腐朽成为尘土，身旁放着两
柄大斧。又见石壁上都是利斧砍过的一片片切痕，原来这条孔道竟是这骷
髅生前用利斧砍出来的！不远处又有两具骷髅，一具倚壁而坐，一具蜷成
一团。甬道向左边伸延过去。	
LONG
        );

	set("exits", ([ /* sizeof() == 1 */
	"left" :  __DIR__"midong",
	]));
	   
	set("cost", 1);
                setup();
}

void init()
{
	add_action("do_strike","strike");
}

int do_strike(string arg)
{
   int n, q;
   object weapon, me = this_player();
   n = me->query("neili");
   q = me->query("qi");
   
   if( !arg || arg!="wall" ) 
       return notify_fail("你要击破甚么？！\n");
                      
   if(!objectp(weapon = me->query_temp("weapon"))
   || (string)weapon->query("skill_type") != "sword"){
               
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
   	   "$N举剑运足内力刺向石壁，擦的一声，剑竟尔插入石壁之中，直没至柄！\n",me);
   	   message_vision(
   	   "$N随即抽出剑来，但听得砰砰之声不绝，石头不住滚落，露出出口。\n", me);
   	   set("exits/out", __DIR__"shandong");
   	   me->set("neili",n-200);
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
  
void close(object room)
{
    message("vision","石头稀里哗拉坍塌下来，又封住了入口。\n", room);
    room->delete("exits/out");
}

//Cracked by Roath
// 华山甬道
// qfy 26/6/1996

#include <room.h>
#include <ansi.h>

inherit ROOM;
int do_use(string);
int do_strike(string);
int do_left();

void create()
{
        set("short", "甬道");
	set("long", @LONG
这是一条黑漆漆的甬道，甚么也看不到，不知通往何处，有何危险。	
LONG
        );
	 switch(random(2)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1,
				  "/d/xingxiu/npc/spider2" : 1]));
                break;
        default:
                set("objects", ([ "/d/xingxiu/npc/spider2" : 1]));
                break;
        }

	set("cost", 1);
        setup();
}

void init()
{
	write("只听得身后石头稀里哗拉坍塌下来，封住了入口。\n");
	add_action("do_strike","strike");
	add_action("do_use","use");
	add_action("do_left","left");
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
	"结果什么也没发生。看来破壁的方法并不对，$N自己反而受损。\n", me);
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
  
int do_use(string arg)
{
    object me = this_player();
       
    if( !arg || arg=="" ) return 0;
    if (!present("fire", me))  return 0;
    if( arg=="fire" ) {
         write("你点燃了火折，便发现甬道边伏着一具骷髅，把你吓出了一身冷汗。\n");
         write("骷髅身上的衣着已腐朽成为尘土，身旁放着两柄大斧。又见石壁上都\n");
         write("是利斧砍过的一片片切痕，原来这条孔道竟是这骷髅生前用利斧砍出\n");
         write("来的！不远处又有两具骷髅，一具倚壁而坐，一具蜷成一团。甬道向\n");
         write("左边伸延过去。这里唯一的出口是 left。\n");
         this_player()->set_temp("marks/左", 1);	
                  } 
 
     return 1;
}

int do_left()
{
    object me = this_player();
    
    if ( me->query_temp("marks/左") ) {
         message("vision", me->name() + "突然不见了。\n", environment(me), ({me}) );
         me->move(__DIR__"midong");
	 message("vision", me->name() + "走了过来。\n", environment(me), ({me}) );
         me->delete_temp("marks/左");
    }
    else {
         write("什么？\n");
    }
    
    return 1;
}         
                		

void close(object room)
{
    message("vision","石头稀里哗拉坍塌下来，又封住了入口。\n", room);
    room->delete("exits/out");
}
                    

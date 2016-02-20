//Cracked by Roath
// 华山秘洞
// qfy 26/6/1996.

#include <room.h>
#include <ansi.h>

inherit ROOM;
string do_look();
int do_lingwu();
int do_ketou(string);

void create()
{
   set("short", "秘洞");
   set("long", @LONG
眼前出现了一个极大的石洞，足以容得不千人之众，洞中有七具骸骨   
，或坐或卧，身旁均有兵刃，一对铁牌，一对判官笔，一根铁棍，一根铜
棒，一具似是雷震挡，另一件是生满狼牙的三尖两刃刀，更有一件兵刃似
刀非刀，似剑非剑，从来没有见过。只见右首山壁旁数丈处突出一块大石
(stone)，似是个平台。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
   "right" : __DIR__"yongdao2",
   ]));

   set("item_desc", ([
      "wall" : (:do_look :),
      "dazi" : 
	"“五岳剑派，无耻下流，比武不胜，暗算害人”。每四个字一排，每个\n"
	"字都有尺许见方，深入山石，是用极锋利的兵刃刻入，深达数寸，十六\n"
	"个字棱角四射，大有剑拔驽张之态。\n",
      "xiaozi" :
	"大字旁更刻了无数小字，都是“卑鄙无赖”，“可耻已极”，“低能”\n"
	"，“懦怯”等诅咒字眼，满壁尽是骂人的语句。\n",
      "skeleton" :
	"骷髅身上的衣着已腐朽成为尘土，可知在此已超过数十年。\n",
      "stone" :
	"大石之下石壁(wall)上刻十六个大字(dazi)和无数小字(xiaozi)。。\n",
   ]));
   
   set("book_count",1);
           
	set("cost", 2);
   setup();
}

void init()
{
   this_player()->set_temp("ketou_times", 0);   
   add_action("do_lingwu","lingwu");
   add_action("do_ketou","ketou");
   add_action("do_ketou","kneel");
}

int do_lingwu()                
{
   object me = this_player();
   int check;

   if ( (int)me->query_skill("staff", 1) >= 30
   && (int)me->query_skill("staff", 1) <= 100
   && present("staff book", me) )
   {
     check = (int)me->query_skill("staff",1)*(int)me->query_skill("staff",1)*(int)me->query_skill("staff",1);
     if ( check < (int)me->query("combat_exp")*10 && (int)me->query("jing") > 29 ) {
     	me->receive_damage("jing", 20, "心力绞瘁死了");
      	me->improve_skill("staff", me->query("int"));
      	write("你领悟了基本杖法方面的几个疑难。\n");
     }
     else if ( check < (int)me->query("combat_exp")*10 && (int)me->query("jing") < 30 ) {
      	write("你精神无法集中。\n");
     }	
     else {
	write ("你实战经验不足，无法领悟基本杖法。\n");
     }	
   } 
   else if ( (int)me->query_skill("staff", 1) > 100 ) {
     write("你基本杖法造诣艺炉火纯青，不能从书上学到什么了。\n");
   }	  
   else {
     write("什么？\n");
   } 
         
   return 1;
}    

string do_look()
{
   object me = this_player();	
   int check;	
	
   if ( !present("sword book", me) || (int)me->query_skill("sword", 1) > 100 ) {
   switch (random(5)) {
   case 0:
   	write("你更往石壁上照看时，见一行字刻着：“范松赵鹤破恒山剑法于此”。\n");
	write("这一行之旁是无数人形，每两个人形一组，一个使剑而另一个使斧。\n");
	write("粗略一计少说也有五六百个人形，显然是使斧的人形在破解使剑的人\n");
	write("形的剑法。\n");
	break;
   case 1:
   	write("石壁上赫然出现一行字迹：“张乘风张乘云尽破华山剑法于此”。那\n");
   	write("行字旁多组图形，使剑人形虽只草草数笔，线条甚为简陋，但从姿形\n");
   	write("之中可以明白，那正是华山剑法，剑势飞舞而出出，轻盈灵动，与之\n");
   	write("对拆人形中持着一条直线形的兵刃，不知道是棒棍还是枪矛。眼见使\n");
   	write("棍人形的棍法来势凌厉之极，正是华山剑法的克星。\n");
   	break;
   case 2:
	write("只见石壁左侧另有多组图形，使剑人形使的剑法诡奇难测，飘乎异常\n");
	write("，正是衡山剑法的绝招。与使剑人形对拆的人形使的是一面铁牌，招\n");
	write("式虽挫，但是却巧妙之极。铁牌面积什大，左拦右挡，衡山剑法的长\n");
	write("处完全无法发挥。\n");
   	break;	
   case 3:
	write("石壁右上角的多组图形中刻的正是破解泰山剑法的招式。泰山剑法以\n");
	write("迅捷辛辣见称，不出招则已，一出招则攻势连绵不绝，似乎永不停止\n");
        write("。破解泰山剑法的人形使的判官笔，笔势凌厉，以快制快，一招内含\n");
	write("无数后着，端的是惊天动地的绝学。\n");
        break;
   case 4:
	write("石壁右边还有多组图形，使剑人形剑招气象森严，剑气纵横，攻势凌\n");
	write("厉，正是嵩山剑法的绝招。另一个人形用的兵器是三尖两刃刀，上劈\n");
        write("下扫，前挑后刺中把嵩山剑招破尽破绝，其势无可挽救。最后使剑者\n");
	write("唯有弃剑跪地投降。\n");
        break;
   }
   }	
   else if ( (int)me->query_skill("sword", 1) >= 30
   && (int)me->query_skill("sword", 1) <= 100 )
   {
   switch (random(5)) {
   case 0:
        write("你仔细地观摩嵩山剑法。\n");
	break;
   case 1:
	write("你仔细地观摩泰山剑法。\n");	
	break;
   case 2:
	write("你仔细地观摩衡山剑法。\n");
        break;
   case 3:
	write("你仔细地观摩华山剑法。\n");
        break;
   case 4:
        write("你仔细地观摩恒山剑法。\n");
        break;
   }
   check = (int)me->query_skill("sword",1)*(int)me->query_skill("sword",1)*(int)me->query_skill("sword",1);	
   if ( check < (int)me->query("combat_exp")*10 && (int)me->query("jing") > 29 ) {
      me->receive_damage("jing", 20, "心力绞瘁死了");
      me->improve_skill("sword", me->query("int"));
      write("你领悟了基本剑法方面的几个疑难。\n");
   }
   else if ( check < (int)me->query("combat_exp")*10 && (int)me->query("jing") < 30 ) {
        write("你精神无法集中。\n");
   }
   else {
        write ("你实战经验不足，无法领悟基本剑法。\n");
   }

   }
	
   return "";
} 

int do_ketou(string arg)
{
   object book, *obs, me = this_player();
	
   if( !arg || arg!="skeleton" ) 
       return notify_fail("什么？\n");
   
   message_vision("$N恭恭敬敬地在几具骸骨前跪了下来，磕了一个响头。\n", me);
   me->add_temp("ketou_times", 1);
	
   if( me->query_temp("ketou_times") == 20 && !me->query_temp("marks/见") ) {
   	write("\n你突然发现在其中一具骸骨后面石壁上刻有几行小字：\n\n");
   	write("余风清扬空负绝世剑法，身受师门深恩，于师门有难时却未能及时效\n");
   	write("力，师门惨遭大难。可叹凶徒竟为同门。呜呼！欲雪大恨，又恐师门\n");
   	write("从此式微，愧对先祖。唯有埋剑深山，退隐江湖。\n");
   	write("汝能不拘小节，跪拜魔教十大长老，实乃性情中人也。见吾留字，可\n");
   	write("谓有缘，请赴后山吾处相见。吾当量材以教，授以神剑。\n");
   	write("于华山朝阳峰三呼吾名，自有人引汝至吾隐居之所。\n\n");
   	write("\t\t\t\t\t华山罪徒 风清扬字\n\n");
   	me->delete_temp("ketou_times");
   	me->set_temp("marks/见", 1);
   }

   if ( me->query_temp("ketou_times") == 15 ) {
	message_vision("\n骸骨在$N面前塌了下来，发出一阵响声，吓了$N一跳。\n\n", me);
 	message("vision","你也被吓了一跳。\n\n", environment(me), ({me}));
   }
   
   if( me->query_temp("ketou_times") == 10 && !present("staff book",me) 
   && query("book_count") >= 1 && !me->query_temp("marks/杖") ) { 	 
	message_vision("\n只见$N磕头的地面突然陷了下去，露出一个长方形的小洞。\n", me);

	obs = filter_array(children(__DIR__"obj/staff_book.c"), (: clonep :));
        if (sizeof(obs) > 2)
	return notify_fail("你发现原来这里曾经有人来过，不知其人有何意图。\n");

	book = new("/d/huashan/obj/staff_book");
	add("book_count", -1);
	book->move(me);
	CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了一册杖法图解。", me->query("name")));
	message_vision("$N将小洞里一册张乘风张乘云留下的杖法图解拿起收好。\n\n", me);
	me->set_temp("marks/杖", 1);
   }	
   
   me->add("jing",-5, "心力绞瘁死了");
   write("你觉得有点昏昏沉沉，可能是由于磕头的缘故。\n");

   return 1;
}

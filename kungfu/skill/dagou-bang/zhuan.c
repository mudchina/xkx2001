//Cracked by Roath
// zhuan.c 打狗棒转字决
// fear@xkx 2001.7

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
inherit F_DBASE;

private int error_checking(object me, object target);
int effect_one(object me, object target, object weapon, int succeed);
int effect_two(object me, object target, object weapon, int succeed);
int effect_three(object me, object target, object weapon, int succeed);
int jump_around(object me, object target);
private int remove_effect(object me, object target, int zhuan_busy);

int perform(object me, object target)
{
  string* msghit, msg;
  object weapon;
  int ranNum, succeed;
  int zhuan_busy, zhuan_cost, zhuan_duration;
  string *limb, type, limb_hurt;

  
  if( !target ) target = offensive_target(me);

  if(error_checking(me, target) == -1) return -1;
 
  if( !objectp(weapon = me->query_temp("weapon")) )
    return notify_fail("空手如何使用转字决？？\n");
  

  if (random(me->query("combat_exp")) * me->query_skill("stick") > 
      random(target->query("combat_exp")) * (target->query_skill("dodge")+ 
      target->query_skill("parry"))/3)
      succeed = 1;
  
  effect_one(me, target, weapon, succeed);
  //effect_two(me, target, weapon, succeed);
  //effect_three(me, target, weapon, succeed);
  
  /*ranNum == random(3);
  
  if( ranNum == 1) effect_one(me, target, weapon, succeed);
  else if( ranNum == 2 ) effect_two(me, target, weapon, succeed);
  else effect_three(me, target, weapon, succeed);*/

  return 1;
}

private int error_checking(object me, object target)
{
  string msg;
  
  if( !wizardp(me) )
    msg = "你不是黄蓉，不会使用「转字诀」！\n";

  else if( !target || !target->is_character()
      || !me->is_fighting(target)
      || !living (target) )
    msg = "转字诀只能对战斗中的对手使用。\n";

  else if( target->is_busy() ) {
    me->add("neili", -10);
    me->add("jingli", -5);
    msg = target->name() + "目前正自顾不暇，放胆攻击吧！\n";
  }

  else if( me->query_temp("ban",1) )
    msg = "你已在使用转字诀！\n";

  else if( me->query_temp("pfmfeng",1) )
    msg = "你已在使用转字诀！\n";

  else if( me->query_temp("zhuan",1) )
    msg = "你已在使用转字诀！\n";

  else if( me->query_skill_mapped("force") != "huntian-qigong" )
     msg = "你所用的并非混天气功，无法施展转字诀！\n";

  else if( me->query_skill("huntian-qigong") < 100 )
    msg = "你的混天气功火候未到，无法施展转字诀！\n";

  else if( me->query_skill("dagou-bang") < 100 )
    msg = "你的打狗棒法修为不足，还不能使用转字诀！\n";

  else if( me->query("neili") <= 1000 )
    msg = "你的内力不够！\n";

  else if( me->query("jingli") <= 600 )
    msg = "你的精力不够！\n";
    
  else return 0;
  
  tell_object(me, msg);
  return -1;  
}

/*******************************************************************************
effect 1 (dianxue):
------------------
perform:
$N棒法一变，+ weapon->name()+化成了一团碧影，猛点$n后心“强间”、“风府”、“大椎”、“灵台”、“悬枢”各大要穴。

fail:
(1)$n识得厉害，当下向前窜跃趋避。
// this looks like succeed.(2)$n无法可施，只得向前急纵，却是避开前棒，后棒又至。

success (hurt without dianxue):
(1)$n大意抢攻，略见疏神，竟被$P在+limb_hurt+上戳了一下，虽在未被封闭穴道，却也是疼痛良久。
// this one looks like fail (2)$n被戳了一下，但在危急中急闭穴道，竟未曾受伤。

success (dianxue):
(1)$n一个不慎，被棒端点中+xuedao name
(2)只见棒端噗地戳中$n的+xuedao name

xuedao name ="强间","风府","大椎","灵台","悬枢"
*******************************************************************************/

int effect_one(object me, object target, object weapon, int succeed)
{
  string* msghit;
  string msg, color;
  int zhuan_busy, zhuan_cost, zhuan_duration;
  string *xuedaoName = ({"强间","风府","大椎","灵台","悬枢"});
  
  msg = HIG "\n" + "$N棒法一变，" + weapon->name()+ 
    "化成了一团碧影，猛点$n后心“强间”、“风府”、“大椎”、“灵台”、“悬枢”各大要穴。\n"NOR;

  message_vision(msg, me, target);
  
  if(succeed) {
    msghit = ({ "\n$n大意抢攻，略见疏神，竟被$P在+limb_hurt+上戳了一下，虽在未被封闭穴道，却也是疼痛良久。\n",
                "\n$n一个不慎，被棒端点中"+ xuedaoName[random(5)] + "\n",
                "\n只见棒端噗地戳中$n的" + xuedaoName[random(5)] + "\n" });

    msg = HIY"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;

    zhuan_busy= me->query_skill("stick")/15;

    target->add("qi",-me->query_skill("stick")/5);
    target->add("jing",-me->query_skill("stick")/10);
    target->add("jingli",-me->query_skill("stick")/10);
    target->start_busy(zhuan_duration);
    me->set_temp("zhuan",1);

    //me->start_busy( 1 + random(2));
    zhuan_duration= 5 + zhuan_busy/( weapon->weight()/1000);

    //call_out("jump_around", 1, me, target);

    if(me->is_fighting() && target->is_fighting()) 
      call_out("effect_two", 1, me, target, weapon, succeed);
    
    else me->start_call_out( (: call_other, __FILE__, "remove_effect", 
      me,target, zhuan_busy :), zhuan_duration);

  }
  
  else {
    msg = CYN"\n$n识得厉害，当下向前窜跃趋避。\n" NOR;
    me->start_busy( 1 + random(3));
    me->add("qi", -me->query_skill("stick")/5);
    message_vision(msg, me, target);
    me->delete_temp("zhuan");
  }

  zhuan_cost = me->query_skill("stick") / 2;
  me->add("neili", -zhuan_cost );
  me->add("jingli", -zhuan_cost/2 );  
}

/*******************************************************************************
effect 2 (drop jingli/qi):
------------------------
perform:
(1)$N微微一笑，使出了「转」字诀，挥棒往$n脸上横扫过去，势挟劲风，甚是峻急。 
(2)$N见$n下盘扎的马步松了，+ weapon->name()+回带，使个「转」字诀，往$n脚下掠去。 

fail:
$n忙仰后相避，堪堪避开了$n这一招。 

success:
(1)$n闪避不及，脸上被扫中，当即面如死灰，委顿在地。 
(2)$n立足不稳，登时扑地跌倒。 
*******************************************************************************/

int effect_two(object me, object target, object weapon, int succeed)
{
  string* msghit;
  string msg, color;
  int zhuan_busy, zhuan_cost, zhuan_duration;
  
  msghit = ({ "\n$N微微一笑，使出了「转」字诀，挥棒往$n脸上横扫过去，势挟劲风，甚是峻急。\n",
         "\n$N见$n下盘扎的马步松了，" + weapon->name()+ "回带，使个「转」字诀，往$n脚下掠去。\n" });
  msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
  message_vision(msg, me, target);

  if(succeed) {
    msghit = ({ "\n$n闪避不及，脸上被扫中，当即面如死灰，委顿在地。\n",
                "\n$n立足不稳，登时扑地跌倒。\n" });

    msg = HIY"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;

    zhuan_busy= me->query_skill("stick")/15;

    target->add("qi",-me->query_skill("stick")/5);
    target->add("jing",-me->query_skill("stick")/10);
    target->add("jingli",-me->query_skill("stick")/10);
    me->set_temp("zhuan",1);

    //me->start_busy( 1 + random(2));
    zhuan_duration= 5 + zhuan_busy/( weapon->weight()/1000);

    call_out("jump_around", 1, me, target);

    if(me->is_fighting() && target->is_fighting()) 
      call_out("effect_three", 1, me, target, weapon, succeed);
    
    else me->start_call_out( (: call_other, __FILE__, "remove_effect", 
      me,target, zhuan_busy :), zhuan_duration-1);

  }
  
  else {
    msg = CYN"\n$n忙仰后相避，堪堪避开了$N这一招。 \n" NOR;
    me->start_busy( 1 + random(3));
    me->add("qi", -me->query_skill("stick")/5);
    message_vision(msg, me, target);
    me->delete_temp("zhuan");
  }

  zhuan_cost = me->query_skill("stick") / 2;
  me->add("neili", -zhuan_cost );
  me->add("jingli", -zhuan_cost/2 );
}

/*******************************************************************************
effect 3 (jump around):
-----------------------
perform:
(1)$N使出了「转」字诀，点打连绵不断，一点不中，又点一穴，棒影只在$n背后各穴上晃来晃去。 
(2)$N手臂抖处，已变为「转」字诀，身子凝立不动，手腕急画小圈，如陀螺般急速旋转。 

fail:
(1)$n斗然跃高，身在半空，牢牢抓住棒端，+weapon->name()+登时便不转了，$N反而被摔了出去。 
(2)$N使力过重，失了轻妙之致，被$n一把抓住棒尖，且顺势一带，当下连人带棒直摔了出去。 

success:
(1)$N手腕抖得愈快，$n转得也是愈快，手中+ weapon->name()+就如陀螺的长柄，也是跟着滴溜溜的旋转。 
(2)$n脚下加劲，欲待得机转身，但$p纵跃愈快，棒端来得愈急。 
(3)$n绕着$N飞奔跳跃，大转圈子，举棒不离$n后心。圈子越转越大，逼得旁人不得不趋避。 
******************************************************************************/

int effect_three(object me, object target, object weapon, int succeed)
{
  string* msghit;
  string msg, color;
  int zhuan_busy, zhuan_cost, zhuan_duration;
  
  msghit = ({ "\n$N使出了「转」字诀，点打连绵不断，一点不中，又点一穴\n" + 
      "，棒影只在$n背后各穴上晃来晃去。\n",
              "\n$N手臂抖处，已变为「转」字诀，身子凝立不动，手腕急画\n" + 
      "小圈，如陀螺般急速旋转。\n" });
  msg = HIG"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
  message_vision(msg, me, target);

  if(succeed) {
    message_vision(HIY"\n$N脚下加劲，欲待得机转身，但$N纵跃愈快，棒端来得愈急。\n", target);

    zhuan_busy= me->query_skill("stick")/15;

    target->add("qi",-me->query_skill("stick")/5);
    target->add("jing",-me->query_skill("stick")/10);
    target->add("jingli",-me->query_skill("stick")/10);
    me->set_temp("zhuan",1);

    me->start_busy( 1 + random(2));
    zhuan_duration= 5 + zhuan_busy/( weapon->weight()/1000);

    call_out("jump_around", 1, me, target);

    me->start_call_out( (: call_other, __FILE__, "remove_effect", 
      me,target, zhuan_busy :), zhuan_duration-2);

  }
  
  else {
    msghit = ({	"$n斗然跃高，身在半空，牢牢抓住棒端，"+(string)weapon->name()+"
登时便不转了，$N反而被摔了出去。\n",
                "$N使力过重，失了轻妙之致，被$n一把抓住棒尖，且顺势一带，当下连
人带棒直摔了出去。\n" });
    msg = CYN"\n"+ msghit[random(sizeof(msghit))] +"\n" NOR;
    me->start_busy( 1 + random(3));
    me->add("qi", -me->query_skill("stick")/5);
    message_vision(msg, me, target);
  }

  zhuan_cost = me->query_skill("stick") / 2;
  me->add("neili", -zhuan_cost );
  me->add("jingli", -zhuan_cost/2 );
  me->delete_temp("zhuan");
}

int jump_around(object me, object target)
{
  object env = environment(target);
  
  if(!me->is_living() || !target->is_living()) return -1;
  
  message_vision("$N无可奈何，唯有象猴子那样跳来跳去。\n", target);
  
  // see look.c file.
}

private int remove_effect(object me, object target, int zhuan_busy)
{
  object weapon;
  me->delete_temp("zhuan");
  
//  tell_object(me, HIY"\n你手中的武器太过沉重，数招之后便感变化不灵。\n"NOR);
//  tell_object(target, HIY"\n你的棒招陡变，打狗棒的「封」字诀已然瓦解。\n"NOR);
  
  if(objectp(me) && objectp(target) && target->is_fighting(me) )
    message_vision(HIG"\n$N数招之后便已感变化不灵。\n"NOR, me, target);
  
  return 1;
}


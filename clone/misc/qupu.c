//Cracked by Roath
#include <ansi.h>
#include <command.h>
inherit ITEM;
void create()
{
        set_name(YEL "曲谱" NOR, ({ "qu pu", "pu"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "册");
                set("long", "
一册裱钉精美的曲谱，你可以唱(chang)里面的曲子：

　《香冢·铭文》(xiangzhong)
　《洞仙歌》(dongxian_ge)
　《迈陂塘·雁丘词》(maipo_tang)
　《波斯小曲》(bosi_xiaoqu)
　《笑傲江湖》(xiaoao_jianghu)
　《山坡羊》(shanpo_yang)
　《蝶恋花》(dielian_hua)
　《采桑子》(caisang_zi)
　《无俗念》(wusu_nian)   
　《洞仙歌》(dongxian_ge)
　《采桑子》(caisang_zi)
  《三台》(san_tai)
  《御街行》(yujie_xing)
  《醉垂鞭》(zuichui_bian)
  《水调歌头》(shuidiao_getou)
 
你如果觉得唱得不好，可以停(ting)下，再回去练练。
\n");
                set("value", 10000);
                set("material", "silk");
             }
        setup();
}

void init()
{
        add_action("do_sing", "chang");
        add_action("do_halt", "ting");
}
#include "sing.c";

int do_halt()
{
        if (find_call_out("sing_stage") < 0) return 0;
        message_vision(HIR"\n$N发现大家一脸痛苦的表情，尴尬地咳嗽了两声，停下了噪音。\n"NOR, this_player());
        remove_call_out("sing_stage");
        return 1;
}

int do_sing(string arg)
{
       object me, ob; 
       int i = sizeof(qupu);
       int stage;
       stage = 0;
       me = this_player();
       ob = this_object();
       if(me->query("id") != "xqin")
       return notify_fail("你琢磨了半天，可是半句也唱不出来。\n");
       if (find_call_out("sing_stage") >= 0) return notify_fail("你能同时唱两首曲子吗？\n");
       if(!arg) return notify_fail("你想唱什么？\n");
        while (i--) if (arg == qupu[i]["name"]) break;
        if (i<0) return notify_fail("曲谱里还没有你想唱的曲子。\n");
        if(me->is_busy())
           return notify_fail("你正忙着呢。\n");
        if(me->query("gender") != "男性"){

        if(present("zhu xiao", me))
        message_vision(HIG"$N拿起竹箫放到嘴边轻轻的吹了起来，箫声清而不淡，响而不俗，令人不觉陶醉其中。\n\n"NOR,me, ob);
          else message_vision("$N翻开$n，放开歌喉，呀呀呀唱了起来：\n\n"NOR, me, ob);
          }
      call_out("sing_stage", 2, me, stage, i, sizeof(qupu[i]["context"]));
      return 1;
}

void sing_stage(object me, int stage, int i, int size)
{
   if(stage < size) {
   message_vision(qupu[i]["context"][stage], me);
   me->start_busy(1);
   call_out("sing_stage", 1, me, ++stage, i, size);
   }
   else {
    if(me->query("gender") != "男性"){
      if(present("zhu xiao", me))
         message_vision(HIG"\n过了一会，$N手中箫声渐缓渐轻，似乎流水汩汩远去，终于歌完曲终，寂然无声。\n"NOR, me);
      else message_vision("\n$N唱完最后一字，仰天一声长啸，啸声远远传了开去。\n", me);
          }
    }
}
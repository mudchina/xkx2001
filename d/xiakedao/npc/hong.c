//Cracked by Roath
// Modified by xbc; add quests 06/21/97
// Modified by xuy; fixed crashing bugs in quests 08/11/97

inherit NPC;

int auto_perform();

void create()
{
        set_name("洪七公", ({"hong qigong", "hong", "qigong"}));
        set("nickname", "九指神丐");
        set("gender", "男性");
        set("age", 75);
        set("long",
"他一张长方脸，颌下微须，粗手大脚，身上衣服东一块西一块的打满了补丁，
却洗得干干净净，背上负着个朱红漆的大葫芦。\n");
        set("attitude", "peaceful");
        
        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 30);
        
        set("rank", 10);
        
        set("chat_chance", 10);
        set("chat_msg", ({
"洪七公双掌平平提到胸前，神色沉重的缓缓施出「亢龙有悔」推向石
壁。\n",
"洪七公突然身形飞起，双掌居高临下一招「飞龙在天」击在地上发出
一声巨响。",
"洪七公右掌一招「见龙在田」，迅捷无比地劈向右边的一块大石，大
石被打的飞了起来。\n",
"洪七公双掌施出一招「鸿渐于陆」，隐隐带着风声凌空挥出。掌风把
你往後推了几步。\n",
"洪七公左掌聚成拳状，右掌一招「潜龙勿用」缓缓向前推出，暗劲刮
的你脸上发痛。\n",
"洪七公施出一招「利涉大川」，右掌插腰，左掌劈向左边的一块大石。\n",
"洪七公使出「突如其来」，右掌从不可能的角度向右边的一块大石推
出。\n",
"洪七公大吼一声，双掌使出「震惊百里」，不顾一切般击向石壁。\n",
"洪七公使出「或跃在渊」，向左边的一块大石连拍数掌。\n",
"洪七公身形滑动，双掌使一招「双龙取水」一前一后按向右边的一块
大石。\n",
"洪七公使出「鱼跃于渊」，身形飞起，双掌并在一起向左边的一块大
石劈下。\n",
"洪七公双掌立起，使出「时乘六龙」向石壁连砍六下。每一下都震得
石洞幌了一幌。\n",
"洪七公使出「密云不雨」，左掌封住退路，右掌斜斜地劈向石壁。\n",
"洪七公使出「损则有孚」，双掌软绵绵地拍向右边的一块大石。\n",
"洪七公脚下一转，突然欺到石壁前，一招「龙战于野」拍向左边的一块大石。\n",
"洪七公门户大开，一招「履霜冰至」向右边的一块大石劈去。\n",
"洪七公使出「羝羊触蕃」，双掌由下往上击向左边的一块大石。\n",
"洪七公左掌护胸，右掌使一招「神龙摆尾」上下晃动着击向右边的一块大石。\n",
        }));
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
        
        set("qi", 3000);
        set("max_qi", 3000);
        set("jing", 800);
        set("max_jing", 800);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 300);
        
        set("combat_exp", 900000);
        set("score", 200000);
         
        set_skill("force", 180);             // 基本内功
        set_skill("huntian-qigong", 180);    // 混天气功
        set_skill("strike", 180);            // 基本掌法
        set_skill("xianglong-zhang", 180);   // 降龙十八掌
        
        set_skill("hand", 180);              // 基本手法
        set_skill("shexing-diaoshou", 200);  // 蛇形刁手
        set_skill("dodge", 200);             // 基本躲闪
        set_skill("xiaoyaoyou", 200);        // 逍遥游
        set_skill("parry", 180);             // 基本招架
        set_skill("stick", 200);             // 基本棍杖
        set_skill("dagou-bang", 200);        // 打狗棒法
        set_skill("begging", 100);           // 叫化绝活
        set_skill("checking", 100);          // 道听途说
        set_skill("training", 120);          // 驭兽术
        set_skill("digging", 100);
        
        map_skill("force", "huntian-qigong");
        map_skill("strike","xianglong-zhang");
        map_skill("hand",  "shexing-diaoshou");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "dagou-bang");
        map_skill("stick", "dagou-bang");
        
        prepare_skill("strike", "xianglong-zhang");
        
        create_family("丐帮", 17, "帮主");
        setup();
        
        carry_object("/d/gaibang/obj/yuzhu-zhang");
        carry_object("/d/gaibang/obj/budai")->set_amount(9);
        carry_object("/d/gaibang/obj/budai")->wear();
}

void attempt_apprentice(object ob)
{
        command ("say 这「侠客行」的古诗图解，包藏着古往今来最博大精深
的武学秘奥，老夫竭尽心智，尚自不能参悟其中十之一二，哪还能分
心去理会世上俗事。 ");
}

#include "/kungfu/class/gaibang/auto_perform.h"


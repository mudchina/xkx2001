// paper.c
#include <ansi.h>;
inherit ITEM;
void create()
{
        set_name(HIR"贺卡"NOR, ({"card"}));
        set("unit", "张");
        set("long",HIR" 

┏━━━━━━━━━ 新婚志喜 ━━━━━━━━━┓
┃  ┌───────────────────┐  ┃
┃  │                                      │  ┃
┃  │                                      │  ┃
┃  │  homename: 设定房间名称。            │  ┃
┃  │  homedesc: 设定房间描述。            │  ┃
┃  │  bedname : 设定床铺名称。            │  ┃
┃  │  beddesc : 设定床铺描述。            │  ┃
┃  │  findbaby: 找你们的小孩。            │  ┃
┃  │  gosleep : 上床睡觉。这样才会有baby。│  ┃
┃  │  sleep <sb>: 创造爱的结晶。          │  ┃
┃  │                                      │  ┃
┃  │                      天下有雪恭贺    │  ┃
┃  │                                      │  ┃
┃  └───────────────────┘  ┃
┗━━━━━━━━━━━━━━━━━━━━━━━┛

");
        set("value", 0);
        set_weight(10);
        setup();
}



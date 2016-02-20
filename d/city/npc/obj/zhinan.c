//Cracked by Roath
// 婚姻指南.c
#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("婚姻指南", ({ "zhinan", "guide"}) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("no_drop", 1);
                set("long",
"       ————————————————\n"
"       |                               |\n"
"       |                               |\n"
"       |                      ——     |\n"
"       |                     | 婚 |    |\n"
"       |                     |    |    |\n"
"       |                     | 姻 |    |\n"
"       |                     |    |    |\n"
"       |  　         　      | 指 |    |\n"
"       |  　         　      |    |    |\n"
"       |  小         诚      | 南 |    |\n"
"       |  白         征       ——     |\n"
"       |  菜      稿 撰                |\n"
"       |  婚      费 稿                |\n"
"       |  姻      从 人                |\n"
"       |  介      优                   |\n"
"       |  绍                           |\n"
"       |  所                           |\n"
"       |                               |\n"
"       |                               |\n"
"       ————————————————\n\n"

"这是一本婚姻指南，由小白菜婚姻介绍所发行的。\n"
"这本书除了封面以外，每页都是空的。\n\n" );
                set("value", 5);
                set("material", "paper");
        }
        setup();
}


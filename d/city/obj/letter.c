//Cracked by Roath
// Write by Wzfeng 12-29


#include <ansi.h>
#include <localtime.h>

inherit ITEM;
static string *sym_di = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });
string chinese_time(int date)
{
    mixed *local;
    int i;

    local = localtime(date);
    i = (local[LT_HOUR]+1) % 2 * 2 + local[LT_MIN] / 30;
    return sprintf("戊寅年%s月%s日%s时%s",
    chinese_number(local[LT_MON] + 1),
    chinese_number(local[LT_MDAY]),
    sym_di[((local[LT_HOUR] + 1) % 24) / 2],
    i?chinese_number((local[LT_HOUR]+1) % 2 * 2 + 
    local[LT_MIN] / 30 ) + "刻":"正");
}

void create()
{       
    set_name("信函", ({"letter","xin han"}));
    set("long", "这是一只已经封好的信函。\n");

    set_weight(5);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "封");
        set("can_shi", 1);

    }
}

void init ()
{
    add_action("do_read", "read");
    add_action("do_shi", "chai");
    add_action("do_shi", "open");
}

int do_shi(string arg)
{
    object ob;
    string str_time;
    if(!arg) return notify_fail("你要拆开什么？\n");

    ob = present(arg, this_player());

    if(!ob)  return notify_fail("你身上并没有这封信函。\n");

    if(!ob->query("can_shi"))
        return notify_fail("对不起，你不能拆开这件物品。\n");
        
    str_time=chinese_time(ob->query("letter/time"));

    switch( ob->query("letter/send_level"))
    {
        case 1:
        {
            message_vision("只见$N从怀中拿出一封信来，将上面的封漆撕掉，抽出里面的信件。\n", this_player());
            ob->set("long", 
                "这是一封别人写给你的信，你可读(read)它的内容。上面写着：\n"
                +this_player()->query("name")+"      亲启。\n"+
                ob->query("letter/from")+"托扬州驿站转。\n"
                "扬州驿站签发于"+str_time+"。\n");
            ob->set_name("信", ({"xin","letter"}));
        }

        break;
        case 2:
        {
            message_vision("只见$N从身上拿出一封信来，慢慢的将上面的封漆撕掉，取出里面的信件。\n", this_player());
            ob->set("long", 
                "这是一封别人写给你的信，你可读(read)它的内容。上面写着：\n"
                +this_player()->query("name")+"      亲启。\n"+
                ob->query("letter/from")+"托扬州驿站转。\n"
                "扬州驿站签发于"+str_time+"。\n");
            ob->set_name(YEL"信"NOR, ({"xin","letter"}));
        }

        break;
        case 3:
        {
            message_vision("只见$N从贴身处取出一个帛囊，小心翼翼的将上面的封漆撕掉，取出里面的信件。\n", this_player());
            ob->set("long", 
                "这是一封别人写给你的信，你可读(read)它的内容。上面写着：\n"
                +this_player()->query("name")+"      亲启。\n"+
                ob->query("letter/from")+"托扬州驿站转。\n"
                "扬州驿站签发于"+str_time+"。\n");
            ob->set_name(HIR"信"NOR, ({"xin","letter"}));
        }
        break;

    }

    ob->set("can_read_letter",1);
    ob->set("can_add_jinnang",1);
    set("can_shi",0);
    return 1;
}

int do_read(string arg)
{
     object ob_letter;
     int i;
     mapping letter;


     if(!arg) return notify_fail("你要读什么信件？\n");
        ob_letter = present(arg, this_player());

    if(!ob_letter)
        return notify_fail("你身上并没有这封信件。\n");
    if(!ob_letter->query("can_read_letter"))
        return notify_fail("对不起，你无法从这里面读到任何东西。\n");
        
        
    //letter=ob->query("letter");
    letter=ob_letter->query("letter");
    if(!ob_letter->query("be_read"))
        {
        letter["time"]=chinese_time(letter["time"]);
    }
    printf("【书信标题】：%s\n【收信人】：%s\n【信件内容】：\n%s\n\t\t%s写于%s\n\n\n",
    letter["title"],
    letter["to"],
    letter["text"],
    letter["from"],
    letter["time"]
    );
    ob_letter->set("be_read",1);

    return 1;
}


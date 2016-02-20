//Cracked by Roath
#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;


mapping box = ([]);

void create()
{

		string file;
		object new_box;

        set_name("捐纳箱", ({"xiang", "juan na xiang"}));
        set_weight(80000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一个半人高的木盒子，顶上开了个洞，箱内装着喇嘛们和信徒们捐赠
的金银珠宝。箱上铭刻着几个大字－众志成城，再塑我佛金身。\n");
                set("unit", "只");
                set("material", "wood");
                set("value", 100000000);
        }

	    setup();

		box["total_value"]=0;
		box["current_value"]=0;
        file = "/data/box/xueshan.o";
        assure_file( file );

        if(file_size(file)!=-1)  {
            new_box=new("/clone/misc/save_box");
            new_box->set_owner("xueshan");
			box = new_box->query("box");
            destruct(new_box);
        }
		// set the info so zhiri lama also know
		this_object()->set("box_content",box);
        ::create();

}

int init()
{
    add_action("do_donate", "donate");
	// these two function are only for wiz now
	add_action("do_withdraw", "withdraw");
	add_action("do_reset", "reset_all");
}


int do_donate(string arg)
{

        string what, *names, name1, file;
        int amount, real_value;
        object what_ob, me, lama, new_box;

        me = this_player();

        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        return notify_fail("命令格式：donate <数量> <货币单位>\n");

        what_ob = present(what + "_money", me);
        if (!what_ob)
        return notify_fail("你身上没有带这种钱。\n");

        if (amount < 1)
        return notify_fail("你想敬献多少" + what_ob->query("name") + "？\n");

        if ((int)what_ob->query_amount() < amount)
        return notify_fail("你带的" + what_ob->query("name") + "不够。\n");

        // donate the Money

        what_ob->add_amount(-amount);
		real_value = what_ob->query("base_value") * amount;
      
        message_vision(sprintf("$N对着释迦牟尼金像行过五体投地大礼后虔诚地将%s%s%s敬献到捐纳箱中。\n", 
        chinese_number(amount), what_ob->query("base_unit"), 
        what_ob->query("name")), me);
		names = keys(box);
	 //	name1 = me->query("id");
        name1 = me->name(1) + "(" + me->query("id") + ")";

	    if ( member_array(name1, names) == -1 ) {
			// id not found create a new id
			box[name1] = real_value;
		}
		else {
			box[name1] += real_value;
		}
		box["total_value"] += real_value;
		box["current_value"] += real_value;

		// set the info so zhiri lama also know
		this_object()->set("box_content",box);
		// save

        new_box=new("/clone/misc/save_box");
        new_box->set_owner("xueshan");
		new_box->save_box_count(box);
        destruct(new_box);

        if (lama = present("zhiri lama", environment(this_object()))) {
			   lama->thank_doner();
		}

        return 1;

}

int do_withdraw (string arg)
{
        int amount, v;
        string what, file;
        object me, new_box;

        me = this_player();

        if (!wizardp(me)) return notify_fail("捐纳箱锁着呢，打不开。\n");
        
        if (!arg || sscanf(arg, "%d %s", amount, what) != 2)
        return notify_fail("命令格式：withdraw <数量> <货币单位>\n");

        if (amount < 1)
        return notify_fail("你发疯啦，取负数？\n");

        if (file_size("/clone/money/" + what + ".c") < 0)
        return notify_fail("你想取出什么钱？\n");

        what = "/clone/money/" + what;
        if ((v = amount * what->query("base_value")) > box["current_value"])
              return notify_fail("捐纳箱里的钱不够取。\n");

        box["current_value"] -= v;
        MONEY_D->pay_player(me, v);


		// set the info so zhiri lama also know
		this_object()->set("box_content",box);
		// save
        new_box=new("/clone/misc/save_box");
        new_box->set_owner("xueshan");
		new_box->save_box_count(box);
        destruct(new_box);

        message_vision(sprintf("$N从捐纳箱里取出%s。\n", MONEY_D->money_str(v)),
                me);

        return 1;
}


int do_reset()
{
	string file;
	object new_box, me;

   	me = this_player();

    if (!wizardp(me)) return notify_fail("你无权使用此功能！\n");

    file = "/data/box/xueshan.o";
    assure_file( file );

    // also clear the current data
	box = ([]);

	// set the info so zhiri lama also know
	this_object()->set("box_content",box);

    if(file_size(file)!=-1)  {
            new_box=new("/clone/misc/save_box");
            new_box->set_owner("xueshan");
			new_box->reset_all_value();
            destruct(new_box);
    }

    return 1;

}


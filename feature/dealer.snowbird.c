//Cracked by Roath
// dealer.c 商人
// This is a inheritable object.
// Each dealer should support buy, sell, list, value 4 commands
// Ryu added category division, and sorted with quantity on 3/14/97.
// added cashflow control, snowbird

#include <dbase.h>

string is_vendor_good(string arg)
{
	string *goods;
	object ob;
	int i;

	if (arrayp(goods = query("vendor_goods"))) 
		for (i = 0; i < sizeof(goods); i++) 
			if (goods[i]->id(arg))
				return goods[i];
	return "";
}

int do_value(string arg)
{
	object ob;
	int value;

	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("你要估什么的价？\n");
	
	if (ob->query("money_id"))
		return notify_fail("你没用过钱啊？\n");

	value = ob->query("value");
	if (value < 1)
		write(ob->query("name") + "一文不值！\n");
	else 
		write(ob->query("name") + "值" + 
		MONEY_D->price_str(value * 70 / 100) + "。\n");
	return 1;
}

int do_sell(string arg)
{
	object ob, *inv;
	int value, i;
	inv = all_inventory(this_object());	
	if (!arg || !(ob = present(arg, this_player())))
		return notify_fail("你要卖什么？\n");

	if (ob->query("money_id"))
		return notify_fail("你想卖「钱」？？\n");

	if (ob->query("no_drop"))
		return notify_fail("这样东西不能卖。\n");

	if (is_vendor_good(arg) != "") 
		return notify_fail("卖给你好不好？\n");

	if (ob->query("food_supply"))
		return notify_fail("剩菜剩饭留给您自己用吧。\n");
	
        if (ob->query("shaolin"))
                return notify_fail("小的只有一个脑袋，可不敢买少林庙产。\n");

	if (ob->query("no_sell"))
		return notify_fail("这东西小的买了，只怕卖不出去。\n");

	if (ob->query("skill_type") == "throwing")
		return notify_fail("对不起，本店一向不收购暗器。\n");

	value = ob->query("value");
	if (value < 30)
		write(ob->query("name") + "一文不值！\n");
	else if (value > 1000000 )
		return notify_fail("此乃至宝，小的可买不起！\n");
// Adding the new cash flow control here
	if (MONEY_D->player_dealer_pay(this_player(), this_object(), value * 70 / 100) )
	{
		message_vision("$N卖掉了一" + ob->query("unit") + 
		ob->query("name") + "给$n。\n", this_player(), this_object());
			for (i = 0; i < sizeof(inv); i++)
			if (inv[i]->query("name") == ob->query("name")){
			inv[i]->add("quantity", 1);
			destruct(ob);
			return 1;
			}
			ob->move(this_object());
			ob->set("quantity", 1);
			if (ob->query_amount())
			destruct(ob);
	}
	else
		return notify_fail("对不起，小的现在买不起这东西。\n");
	return 1;
}

int do_list(string arg)
{
	string *goods;
	object *inv;
	int i;

	inv = all_inventory(this_object());

	if( arg=="" ) return 0;

	if (!sizeof(inv) && !arrayp(goods = query("vendor_goods")))
		return notify_fail("目前没有可以买的东西。\n");
	
	if(! arg){
	if (arrayp(goods = query("vendor_goods"))){
                for (i = 0; i < sizeof(goods); i++)
                        printf("%30-s：%s\n", goods[i]->short(),
                        MONEY_D->price_str(goods[i]->query("value")));
        return 1;
	}
	else
	printf("你想看哪一柜？（armor、weapon、drug、book or misc）\n");	
	return 1;
	}
	
	if( arg=="weapon" ) {
	printf("你可以向%s购买下列武器：\n", query("name"));
	for (i = 0; i < sizeof(inv); i++) 
		if (!inv[i]->query("equipped") && inv[i]->query("weapon_prop/damage")
		&&!inv[i]->query("money_id"))
		printf("%30-s：%s（还剩%s%s）\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
		chinese_number(inv[i]->query("quantity")),
		inv[i]->query("unit"));
	return 1;
	}
	if( arg=="armor" ) {
        printf("有下列服饰穿戴出售：\n", query("name"));
        for (i = 0; i < sizeof(inv); i++)
                if (!inv[i]->query("equipped") && inv[i]->query("armor_prop/armor") 
                &&!inv[i]->query("money_id"))
		printf("%30-s：%s（还剩%s%s）\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
                chinese_number(inv[i]->query("quantity")),
		inv[i]->query("unit"));
        return 1;
        }
	if( arg=="book" ) {
        printf("有下列书藉出售：\n", query("name"));
        for (i = 0; i < sizeof(inv); i++)
                if (!inv[i]->query("equipped") && inv[i]->query("material") == "paper"
                && !inv[i]->query("money_id"))
		printf("%30-s：%s（还剩%s%s）\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
                chinese_number(inv[i]->query("quantity")),
		inv[i]->query("unit"));
        return 1;
        }
	if( arg=="drug" ) {
        printf("有下列药物出售：\n", query("name"));
        for (i = 0; i < sizeof(inv); i++)
                if (!inv[i]->query("equipped") && inv[i]->query("medicine") 
                && !inv[i]->query("money_id"))
		printf("%30-s：%s（还剩%s%s）\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
                chinese_number(inv[i]->query("quantity")),
		inv[i]->query("unit"));
        return 1;
        }
	if( arg=="misc" ) {
        printf("有下列杂货出售：\n", query("name"));
        for (i = 0; i < sizeof(inv); i++)
                if (!inv[i]->query("equipped") && !inv[i]->query("armor_prop/armor")
		&& inv[i]->query("material") != "paper"
		&& inv[i]->query("medicine") < 1
		&& !inv[i]->query("weapon_prop/damage") && !inv[i]->query("money_id"))
		printf("%30-s：%s（还剩%s%s）\n", inv[i]->short(),
		MONEY_D->price_str(inv[i]->query("value") * 6 / 5),
                chinese_number(inv[i]->query("quantity")),
		inv[i]->query("unit"));
        return 1;
	}
}	

int do_buy(string arg)
{
	int i, amount, value, val_factor;
	string goods, ob_file, file;
	object ob, obj;
//	mapping fam;

//      if ( (fam = this_player()->query("family")) && fam["family_name"] == "丐帮" ) 
//		return notify_fail("你是个穷叫化，买什麽东西！\n");
	
	if( !arg ) return notify_fail("你想买什么？\n");

        if( sscanf(arg, "%d %s", amount, goods)!=2 )
	{
		amount = 1;
		goods = arg;
        }

	if( amount < 1 ) return notify_fail("您想买多少？\n");
	if( amount > 10 ) return notify_fail("我这不是批发商。\n");

	if( !(ob = present(goods, this_object())) )
		if( (ob_file = is_vendor_good(goods)) == "" )
			return notify_fail("你想买的东西我这里没有。\n");
        if( ob && ob->query("money_id") )
                return notify_fail("你想买「钱」？？\n");

	if( !ob )
	{
		ob = new(ob_file);
		if( ob->query("base_unit") )
			ob->set_amount(amount);
		else ob->set("quantity", amount);
		val_factor = 10;
	}
	else
	{
		if( ob->query("equipped") )
			return notify_fail("你想买的东西我不卖。\n");

		if( ob->query("base_unit") && ob->query_amount() < amount )
			return notify_fail("您想要的东西我这不够卖。\n");
		else if( amount > 2 && ob->query("quantity") < amount )
			return notify_fail("您想要的东西我这不够卖。\n");
		val_factor = 12;
	}

        if( query_temp("busy") )
                return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	if( ob->query("value") * amount * val_factor / 10 > 1000000 )
		return notify_fail("唷！咱小本生意，可做不起这大宗买卖呐！\n");

	switch( MONEY_D->player_pay(this_player(), ob->query("value") * amount * val_factor / 10) )
	{
	case 0:
		return notify_fail("穷光蛋，一边呆着去！\n");
	case 2:
		return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	default:
		set_temp("busy", 1);
		message_vision("$N从$n那里买下了"+ chinese_number(amount) +
		( ob->query("base_unit") ? ob->query("base_unit") : ob->query("unit") ) + 
		ob->query("name") + "。\n", this_player(), this_object());

		if( ob->query("base_unit") )
		{
			if( ob->query_amount() > amount )
			{
				file = base_name(ob) + ".c";
				obj = new(file);
				obj->move(this_player());
				obj->set_amount(amount);
				ob->add_amount(-amount);
			}
			else ob->move(this_player());
		}
		else for( i=0; i < amount; i++ )
		{
			ob->add("quantity", -1);
			if( ob->query("quantity") < 1 )
				ob->move(this_player());
			else
			{
				file = base_name(ob) + ".c";
				obj = new(file);
				obj->move(this_player());
			}
		}
	}
	remove_call_out("enough_rest");
        call_out("enough_rest", 1);

	return 1;
}

void enough_rest()
{
        delete_temp("busy");
}



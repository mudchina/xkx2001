//Cracked by Kafei
// moneyd.c  钱的功能

// by Xiang@XKX (95/12/22)
// updated by snowbird (March 2000)

// This is max amount of cash in xkx before money source is limited
// assume the max number is about 200 ppl online, about 1/4 is dummy
// the rest ppl (150) each carrys about 20 gold, newbie carry a little
// less, higher rank player carry a bit more. 150*20=3000 Gold
//
// Made it to use silver as unit to avoid overflow for cashflow coz the amount may be too long as int, 
// also increased the limit to 4k golds sdong, 4/8/2000
//
#define MAX_CASHFLOW_ALLOWED 400000

//function prototypes
string money_str(int amount);
string price_str(int amount);
void pay_player(object who, int amount);
int player_pay(object who, int amount);

int player_dealer_pay(object who, object from, int amount);
int player_bank_pay(object who, object from, int amount);
int player_job_pay(object who, object from, int amount);

int query_avalible_xkx_cashflow();
int query_total_xkx_cashflow();

string money_str(int amount)
{
        // returns a chinese string of `amount` of money
        string output;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "两黄金";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "两白银";
                amount %= 100;
        }
        if (amount)
                return output + chinese_number(amount) + "文铜板";
        return output;
}

string price_str(int amount)
{
        // returns a chinese string of `amount` of money
	string output;

        if (amount < 1)
                amount = 1;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "两黄金";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
		if (output != "")
                	output += "又" + chinese_number(amount / 100) + "两白银";
		else
			output = chinese_number(amount / 100) + "两白银";
                amount %= 100;
        }
        if (amount)
		if (output != "")
                	return output + "又" + chinese_number(amount) + "文铜板";
		else
			return chinese_number(amount) + "文铜板";
        return output;
}

void pay_player(object who, int amount)
{
        int v;
        object ob;

	seteuid(getuid());
        if (amount < 1)
                amount = 1;
        if (v = amount / 10000) {
                ob = new(GOLD_OB);
                ob->set_amount(amount / 10000);
                ob->move(who);
                amount %= 10000;
        }
        if (amount / 100) {
                ob = new(SILVER_OB);
                ob->set_amount(amount / 100);
                ob->move(who);
                amount %= 100;
        }
        if (amount) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}

int player_pay(object who, int amount)
{
	object g_ob, s_ob, c_ob;
	int gc, sc, cc, left;

	seteuid(getuid());

	if (g_ob = present("gold_money", who))
		gc = g_ob->query_amount();
	else
		gc = 0;
	if (s_ob = present("silver_money", who))
		sc = s_ob->query_amount();
	else
		sc = 0;
	if (c_ob = present("coin_money", who))
		cc = c_ob->query_amount();
	else
		cc = 0;
	
	if (cc + sc * 100 + gc * 10000 < amount) 
		if (present("thousand-cash", who))
			return 2;
		else 
			return 0;
	else {
		left = cc + sc * 100 + gc * 10000 - amount;
		gc = left / 10000;
		left = left % 10000;
		sc = left / 100;
		cc = left % 100;

		if (g_ob)
			g_ob->set_amount(gc);
		else sc += (gc * 100);
		if (s_ob)
		 	s_ob->set_amount(sc);
		else if (sc) {
			s_ob = new(SILVER_OB);
			s_ob->set_amount(sc);
			s_ob->move(who);
		}
		if (c_ob)
			c_ob->set_amount(cc);
		else if (cc) {
			c_ob = new(COIN_OB);
			c_ob->set_amount(cc);
			c_ob->move(who);
		}

		return 1;
	}
}
//********** New code to add a cap to total cashflow in mud
// No output to players right now.
// the messege can be used later 
// Right now the function will return zero when we CAN NOT pay the players.
// it's up the the program uses the function to print out the error msg.

// This for vendor to pay players
int player_dealer_pay(object who, object from, int amount)
{
	string str;
	str = from->name(1) + "告诉你：对不起，小的现在买不起这东西。\n";
	if (amount <= query_avalible_xkx_cashflow())
	{
		pay_player(who, amount);
      return 1;
	}
	else
	{
//    tell_object(who, str);
		return 0;
	}     
}

// This for bank to pay players
int player_bank_pay(object who, object from, int amount)
{
	string str;
	str = from->name(1) + "告诉你：对不起There is no money to withdraw\n";
	if (amount <= query_avalible_xkx_cashflow())
	{
		pay_player(who, amount);
      return 1;
	}
	else
	{
//    tell_object(who, str);
		return 0;
	}     
}

// This for job reward to pay players
int player_job_pay(object who, object from, int amount)
{
	string str;
	str = from->name(1) + "告诉你：There is no money to pay you\n";
	if (amount <= query_avalible_xkx_cashflow())
	{
		pay_player(who, amount);
      return 1;
	}
	else
	{
//    tell_object(who, str);
		return 0;
	}     
}

// This function returns if any more cashflow is allowed
int query_avalible_xkx_cashflow()
{
	int mm;
	int amount = query_total_xkx_cashflow();

	mm = MAX_CASHFLOW_ALLOWED;
	if (amount < mm)
		return (mm - amount);
	else
		return 0;
}

// This function returns the total current cashflow in xkx.
int query_total_xkx_cashflow()
{
	
	object *money;
	int amount, i;

	amount = 0;
	money = children(GOLD_OB);
	for (i = 0; i < sizeof(money); i++)
	{
		amount = amount + money[i]->query_amount() * 100;
	}
	money = children(SILVER_OB);
	for (i = 0; i < sizeof(money); i++)
	{
		amount = amount + money[i]->query_amount();
	}
	money = children(COIN_OB);
	for (i = 0; i < sizeof(money); i++)
	{
		amount = amount + money[i]->query_amount()/100;
	}
   return amount;
}


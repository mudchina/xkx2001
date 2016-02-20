//Cracked by Roath
// jiangpai_b.c 奥运奖牌榜

#include <ansi.h>

#define BOARD_CAPACITY query("capacity")

inherit BULLETIN_BOARD;

void init();
string short();
string long();
int do_add(string);
int do_delete(string);
int do_change(string);

mapping medal_name = ([
        "gold"		: HIY "金牌" NOR,
        "silver"	: HIW "银牌" NOR,
        "bronze"	: HIC "铜牌" NOR,
]);
        
void create()
{
	set_name("奥运奖牌榜", ({ "jiangpai bang", "bang" }) );
        set("location", "/d/city/kedian");
	set("board_id", "jiangpai_b");
	set("long", @LONG
	中华健儿１９９６亚特兰大奥运会奖牌榜
	
	姓名		奖牌		项目
------------------------------------------------------------
LONG
	);
	set("capacity", 300);
	setup();
}

void init()
{
	add_action("do_add", "add");
	add_action("do_delete", "delete");
	add_action("do_change", "change");
}

string short()
{
	mapping *medals = query("medals");
	
	return sprintf("%s [ 共有 %d 枚奖牌，%d 金 %d 银 %d 铜 ]",
		query("name") + "(" + capitalize(query("id")) + ")",
		sizeof(medals), (int)query("gold"),
		(int)query("silver"), (int)query("bronze"));
}

string long()
{
	mapping *medals;
	int i;
	string msg;

	medals = query("medals");
	msg = query("long");
	if( !pointerp(medals) || !sizeof(medals) ) return msg;

	for(i=0; i<sizeof(medals); i++)
		msg += sprintf(
"[%d]	%s		%s		%s\n",
		i+1, medals[i]["name"], medal_name[medals[i]["medal"]], 
		medals[i]["event"]);
	return msg;
}

int do_add(string arg)
{
	object me = this_player();
	mapping row, *medals;
	string name, medal, event;
	
	if( !wizardp(me) )
               return notify_fail("你不是巫师，无权修改奖牌榜! \n");
	                
	if( !arg || sscanf(arg, "%s %s %s", name, medal, event) != 3 ) 
		return notify_fail("指令格式：post <姓名> <gold|silver|bronze> <项目>\n");
	
	row = allocate_mapping(3);
	row["name"] = name;
	row["medal"] = medal;
	row["event"] = event;
	
	if( !query(medal) ) set(medal, 1);
	else add(medal, 1);
	
	medals = query("medals");
        if( !pointerp(medals) || !sizeof(medals) )
		medals = ({ row });
	else
		medals += ({ row });
                                                
	// Truncate the notes if maximum capacity exceeded.
	if( sizeof(medals) > BOARD_CAPACITY )
		medals = medals[BOARD_CAPACITY / 2 .. BOARD_CAPACITY];

	set("medals", medals);
	write("修改完毕。\n");

	save();
	return 1;
}

int do_delete(string arg)
{
	object me = this_player();
	mapping *medals;
	int num;
	string medal;

        if( !wizardp(me) )
		return notify_fail("你不是巫师，无权修改奖牌榜! \n");
                       
	if( !arg || sscanf(arg, "%d", num)!=1 )
		return notify_fail("指令格式：discard <奖牌编号>\n");
		
	medals = query("medals");
	if( !arrayp(medals) || num < 1 || num > sizeof(medals) )
		return notify_fail("没有这枚奖牌。\n");
	num--;

	medal = medals[num]["medal"];
	add(medal, -1);
	medals = medals[0..num-1] + medals[num+1..sizeof(medals)-1];
	set("medals", medals);
	
	save();
	write("删除第 " + (num+1) + " 枚奖牌....Ok。\n");
	return 1;
}

int do_change(string arg)
{
	object me = this_player();
	mapping *medals;
	string name, medal, event, oldmedal;
	int num;
	
	if( !wizardp(me) )
               return notify_fail("你不是巫师，无权修改奖牌榜! \n");
	                
	if( !arg || sscanf(arg, "%d %s %s %s", num, name, medal, event) != 4 ) 
		return notify_fail("指令格式：change <奖牌编号> <姓名> <gold|silver|bronze> <项目>\n");
	
	medals = query("medals");
	if( !arrayp(medals) || num < 1 || num > sizeof(medals) )
		return notify_fail("没有这枚奖牌。\n");
	num--;
	
	oldmedal = medals[num]["medal"];
	add(oldmedal, -1);
	medals[num]["name"] = name;
	medals[num]["medal"] = medal;
	medals[num]["event"] = event;
	if( !query(medal) ) set(medal, 1);
	else add(medal, 1);
	
	set("medals", medals);
	write("修改完毕。\n");

	save();
	return 1;
}

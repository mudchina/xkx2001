//Cracked by Roath
// Room: /city/qianzhuang.c
// YZC 1995/12/04 
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"钱庄"NOR);
	set("long", @LONG
这是一家老字号的钱庄，已有几百年的历史，在全国各地都有分店。它发行
的银票信誉非常好，通行全国。墙上新贴着一张布告(bugao)。
LONG
	);

	set("item_desc", ([
		"bugao" : "
闯王义军克日即到扬州。扬州钱庄从即日起由华山派大弟子
黄真先生主持。一切钱庄业务照旧。

	开开大门迎闯王
	闯王来了不纳粮

— 闯王军师李岩启
\n",
	]));

	set("no_drop",1);
	set("exits", ([
		"south" : __DIR__"dongdajie3",
	]));

	set("objects", ([
		__DIR__"npc/huang" : 1
	]));
	set("day_shop", 1);
	set("cost", 0);
	setup();
}
void init()
{
	int balance;

	if( !this_player()->query("newsaver") ) 
	{
		balance = this_player()->query("balance");
		if( balance >= 1000000 ) balance = balance/10;
		if( balance >= 1000000 ) balance = 1000000;
		this_player()->set("balance", balance);
		this_player()->set("newsaver", 1);
	}
	
	this_player()->save();
}


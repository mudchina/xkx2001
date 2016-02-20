//Cracked by Roath

inherit ROOM;

void create()
{
	set("short", "ÃÜÊÒ");
	set("long", @LONG
ÕâÀïÏóÊÇÒ»¸öµØ½Ñ£¬¿ÉÄÜÊÇÒ©ÆÌÊÕ²ØÕä¹óÒ©ÎïµÄµØ·½¡£¶«Ê×Ò»¸ö
´ó¼Ü×Ó£¬·Å×ÅÒ©²ÄºÍÎÞÊýÐ¡´ÉÆ¿¡£µØÉÏÓÐÒ»Ö»Á¶Ò©Â¯£¬¿ÕÆøÖÐ¾¡ÊÇÒ©
Î¶¡£
LONG
	);
	set("no_clean_up", 0);

    set("objects", ([
         __DIR__"obj/yaolu" : 1,
]));
	setup();
}


void init()
{
	add_action("do_turn","zhuan");
	add_action("do_turn","turn");
	add_action("do_search","search");
}

int do_turn(string arg)
{
	object me;
	me = this_player();
	if( !arg || arg == "" ) return 0;
	if( arg == "ball" || arg == "qiu")
	{
		message_vision("$N×øÔÚÒÎÉÏ£¬°ÑÒÎ±³ÌúÇòÏñÓÒÒ»×ª£¬Í·ÉÏ¿ª³öÒ»¶´¡£¡
£\nÒÎ×Ó´ø×Å$NÉýÁËÉÏÈ¥¡£\n",me);
		me->move(__DIR__"neitang");
		return 1;
	}
	else
		return notify_fail("ÄãÒª¸ÉÊ²Ã´£¿\n");
}

int do_search(string arg)
{
	object ob,me;
	me = this_player();
	if (!arg || arg == "") return 0;
	
	if (arg == "jia" || arg == "shelf")
	{
		if (query("searched"))
			return notify_fail("ÄãÔÚ¼Ü×ÓÉÏ·­Ñ°ÁËÒ»Õó£¬µ«Ê²Ã´¶¼Ã»ÕÒµ½¡£\n");

		switch (random(7))
		{
			case 0:
			ob = new("/d/dongtinghu/obj/yangxin");
			break;
			case 1:
			ob = new("/d/dongtinghu/obj/jinchuang");
			break;
			case 2:
			ob = new("/d/dongtinghu/obj/baicao-dan");
			break;
			case 3:
			ob = new("/d/dongtinghu/obj/yulu-wan");
			break;
			case 4:
			ob = new("/d/dongtinghu/obj/xxqingxin-san");
			break;
			case 5:
			ob = new("/d/dongtinghu/obj/heishi-dan");
			break;
			case 6:
			ob = new("/d/dongtinghu/obj/dali-dan");
			break;
		}

		set("searched",1);		
		message_vision("Äã´ÓÒ»¸öÐ¡Æ¿×ÓÀïÕÒµ½Ò»¿Å"+ob->query("name")+"¡£\n",me);
		ob->move(me);
		return 1;
	}
}	


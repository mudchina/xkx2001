//Cracked by Roath
// qiyuan4.c


#include <ansi.h>
#include <room.h>
#include "/d/city/chess_room.h"

inherit ROOM;
string look_book();
void do_back(object ob);
int do_knock(object ob);

void create()
{
	set("short", "ÆåÊÒ°");
	set("long", @LONG
ÕâÀïÊÇ²è¹ÝÖÐµÄÆåÊÒÖ®Ò»£¬ÕýÊÇÈýÎåÖª¼º¸ßÌ¸À«ÂÛ£¬Æ·²è¶ÔÞÈµÄºÃµØ·½¡£ÊÒ     
ÄÚ²¼ÖÃ¼òµ¥µ«Ò²ÑÅÖÂ¡£Ç½ÉÏ¹ÒÖøÒ»·ù¶ÔÁª (duilian)¡£Ä¾×ÀÉÏÃæ·Å×ÅÏóÆåÆåÅÌºÍ
Æå×Ó£¬ËæÊ±¿ÉÒÔ¿ªÊ¼(start)ÏÂÆå£¬×ÀÉÏ(table)³ýÁËÆå¾ßÍâ£¬»¹·ÅÁËÒ»±¾Ð¡²á×Ó 
(book)¡£
LONG
	);
	set("exits", ([
		"west" : "/d/city/chaguan",
        ]));
        set("no_fight", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"book" : (:look_book:),
		"table": "Ò»ÕÅµäÑÅµÄÌÒÄ¾Ð¡×À£¬ÉÏÃæ·Å×ÅÆåÅÌºÍÒû²èÆ÷¾ß¡£\n",
		"duilian" : MAG"
	****** ******
	* Íß * * Üø *
	* ºø * * Íë *
	* Çë * * Ïã *
	* ¿Í * * ÌÚ *
	* Ñû * * ÒÅ *
	* Çë * * Ë¯ *
	* ¿Í * * Ä§ *
	****** ******\n\n"NOR,
 	
	]));
	set("no_clean_up", 0);
        setup();
        set("no_user", 1);
}


int do_knock(string arg)
{       
        object me = this_player();
	object waiter;

        if ( (!arg )|| (arg != "table"))
	  {       
	        write("ÇÃÊ²Ã´Ñ½£¿(knock table)\n");
                return 1;
	  }
        if( (arg == "table") )
	  {     
                if(!(waiter = find_living("chaguan xiaoer")))
                  {
		        waiter = new("/d/city/npc/c_waiter");
		        waiter->move(environment(me));
                  }

                waiter->move(environment(me));
                message_vision("$NÉì³öÁ½¸öÖ¸Í·À´£¬ÇÃÁËÇÃ×À×Ó£¬²è¹ÝÐ¡¶þÅÜÁË¹ýÀ´¡£\n", me);
		remove_call_out("do_back");
	        call_out("do_back", 20 + random(10), waiter);
                return 1;
	  }
        return 1;
}

void do_back(object ob)
{
  message("vision", 
	  "¿Í¹ÙÄúÂýÓÃ£¬Ð¡µÄÏÈÍËÏÂÁË¡£\n", 
	  environment(ob), ({ob}));
  ob->move("/d/city/chaguan");
}
void reset()
{
        ::reset();
        set("no_clean_up", 1);
}

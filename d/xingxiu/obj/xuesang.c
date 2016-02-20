//Cracked by Roath
// xuesang.c  
// By Haowen 1/14/98

#include <ansi.h>

inherit ITEM;


void create()
{
        set_name("Ñ©É£",({"xue sang","sang"}));
        set_weight(900000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÒ»¿ÃÌìÉ½ÌØÓÐµÄÉú³¤ÔÚÑ©·åµÄÑ©É£Ê÷¡£
´«ËµÓÐÒ»ÖÖÑ©²Ï×îÏ²»¶Éú³¤ÔÚÕâÑ©É£Ö®ÉÏ£¬¾­³£ÓÐÈËÀ´Ñ°ÕÒ(search)¡ \n");
                set("unit", "¿Ã");
                set("value", 8);
                set("no_get", 1);
		set("leaves",20);
       }
       
        setup();
}

void init()
{
        add_action("do_search", "search");
        add_action("do_feed", "fed");
	add_action("do_look", "look");
	add_action("do_look", "l");
}

int do_search()
{
object obj=this_object(),me=this_player();

if (me->query_temp("find_can"))
	return notify_fail("Ñ©²ÏÒÑ¾­ÔÚÑ©É£ÉÏÁË£¬Äã»¹ÕÒÊ²Ã´Ñ½£¿\n");

if(random(me->query("kar"))>15)
	{
        tell_object(me,HIG"Äã×ÐÏ¸µÄ·­¶¯Ñ©É£Ò¶£¬µ½´¦Ñ°ÕÒÆðÀ´¡£\n" NOR);
	if(random(10)>5)
		{
                tell_object(me,HIR"ÄãºöÈ»ÑÛÇ°Ò»ÁÁ£¬Ò»Ìõ¾§Ó¨Ñ©°×µÄÑ©²Ï(can)ÕýÎÔÔÚÒ»Æ¬Ñ©É£Ò¶ÉÏ£¡\n"NOR);
		me->set_temp("find_can",1);
		}
        me->add("neili",-10);
        return 1;
	}
else    {
        me->add("neili",-10);
        return notify_fail("ÄãÕÒÁË°ëÌìÊ²Ã´Ò²Ã»ÕÒµ½£¡\n");
        }
}

int do_feed(string arg)
{
object ob,obj=this_object(),me=this_player();
string what;

//message_vision(arg);
if (!arg || sscanf(arg,"%s",what)!=1)
	return notify_fail("ÄãÒªÎ¹Ê²Ã´£¿\n");

if (what!="can")
	return notify_fail("ÕâÀïµÄÑ©É£Ò¶Ö»ÓÐÌìÉ½Ñ©²Ï°®³Ô£¡\n");

if (!me->query_temp("find_can"))
	return notify_fail("ÕâÑ©É£ÉÏÊ²Ã´Ò²Ã»ÓÐ£¬ÄãÒªÎ¹Ê²Ã´£¿\n");

if (me->query_temp("get_si"))
	return notify_fail("Ñ©²Ï¸ÕÍÂ¹ýË¿£¬¿ÖÅÂÏÖÔÚ²»»áÔÙÍÂÁË£¡\n");

if (obj->query("leaves")>1)
	{
        tell_object(me,HIY "ÄãÕªÁËÒ»Æ¬Ñ©É£Ò¶Î¹¸øÑ©²Ï³Ô¡£Ñ©²Ï×ÐÏ¸µÄ³ÔÁËÆðÀ´¡£\n" NOR);
	obj->set("leaves",obj->query("leaves")-1);
		if (random(10)>5)
			{
                        tell_object(me,HIY "Ñ©²Ï³ÔÍêÁËÉ£Ò¶£¬Í·Ò»°º£¬ÍÂ³öÒ»¸ù²ÏË¿£¬Äã¸Ï½ôÓÃÊÖ½Ó×¡¡£\n" NOR);
                        me->set_temp("get_si",1);
			ob=new("/d/xingxiu/obj/xuecan-si");
			ob->move(me);
			}
	return 1;}
else 
	{
	call_out("grow",200,obj);
	return notify_fail("Ñ©É£ÉÏµÄÒ¶×Ó¶¼ÕªÍêÁË£¬µÈÂýÂý³¤³öÀ´ÔÙÀ´Î¹°É£¡\n");
	}
}

int do_look(string arg)
{
        object ob,me=this_player();
	string what;
        ob=this_object();
 
        if( !arg || arg == "" || sscanf(arg,"%s",what)!=1) return 0;

	
        if(what=="sang" || what=="xue sang")
		{	
		if(me->query_temp("find_can"))
                        tell_object( me, ob->query("long") + "ÏÖÔÚÉÏÃæÓÐÒ»Ö»Ñ©²Ï(can)£¡ºÃÏóÕýÔÚµÈÄãÎ¹(fed)Ëü¡£\n");
		else	tell_object( me, ob->query("long"));
                return 1;
                }

return 0;

}

int grow(object ob)
{
	message_vision(HIG "Ñ©É£ÉÏµÄÉ£Ò¶ÓÖ³¤³öÀ´ÁË£¡\n");
	ob->set("leaves",20);
}

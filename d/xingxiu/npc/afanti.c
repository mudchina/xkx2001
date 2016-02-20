//Cracked by Roath
// npc: /d/xingxiu/npc/afanti.c
// Jay 3/26/96

inherit NPC;

//string ask_me();

void create()
{
        set_name("°¢·²Ìá", ({ "afanti" }) );
        set("gender", "ÄĞĞÔ" );
        set("age", 48);
        set("long", 
            "ËûÍ·ÉÏ°ü×ÅÍ·½í£¬³¤×Å´óºú×Ó£¬×îÏ²»¶×½Åª°ÍÒÀ¡¢°ïÖúÇîÈË¡£Ëû³£"
            "¸ø±ğÈË³öÃÕÓï¡£\n");
        set("str", 25);
        set("dex", 20);
        set("con", 17);
        set("int", 15);
        set("shen_type", 1);

        set_skill("unarmed", 70);
        set_skill("dodge", 65);
	set_skill("hammer",70);
        set("combat_exp", 55000);

        set("attitude", "peaceful");
        set("inquiry", ([
            "name" : "ÎÒ¾ÍÊÇ°¢·²Ìá¡£",
            "here" : "ÕâÀï¿ÉÕæÊÇ¸öºÃµØ·½¡£",
            "ÃÕÓï" : "ÎÒÀÛÁË£¬ÒÔºóÔÙËµ°É¡£",
            "°ÍÒÀ" : "Ëû°ÑÎÒ¹ØÔÚÕâÀï£¬ÓĞ³ÔÓĞºÈ£¬ÎÒ¾Í²»×ßÁË¡£°ÍÒÀÊÇ¸ö»µµ°£¬Ô¸ºú´ó³Í·£Ëû¡£",
            "ºú´ó" : "¾ÍÊÇÕæÖ÷¡£ÓÖÃû°²À­»ò°¢À­¡£",
            "ÕæÖ÷" : "ÕæÖ÷ÖÁ´ó£¬ÍòÎï·ÇÖ÷£¬Î¨ÓĞÕæÖ÷¡£ÄÂº±Ä¬µÂÊÇÕæÖ÷µÄÊ¹Õß¡£",
       ]) );

        setup();
        carry_object(__DIR__"obj/wcloth")->wear();
        carry_object(__DIR__"obj/dongbula");
	carry_object(__DIR__"obj/tieguo")->wield();
}
/*
void init()
{
        ::init();
        add_action("do_answer","answer");
}

int accept_object(object who, object ob)
{
     if((string)ob->query("name")=="Ğ¡Ã«Â¿" && ob->query("race") == "¼ÒĞó") {
           remove_call_out("destroying");
           call_out("destroying", 1, this_object(), ob);

           if( who->query_temp("marks/ÃÕ") ) {
                 write("°¢·²ÌáĞ¦ÁËĞ¦£¬Ëµ£ºÄãÏÈ°ÑÉÏ¸öÃÕ²Â³öÀ´ÔÙËµ¡£\n");
//               destruct(ob);
                 return 1;
           }
           else {
                 write("°¢·²ÌáĞ¦µÃ×ì¶¼ºÏ²»ÉÏÁË£¬Ëµ£º¶àĞ»ÕâÎ»" + 
                       RANK_D->query_respect(who) +
                       "µÄ°ïÖú£¬ÔÛÃÇ²Â¸öÃÕÓï°É£º\n");
                 switch(random(20)) {
                   case 0:
                       write("¸¾Å®¶ÁÎï¡£(´òÒ»±¾ÄàÌ¶Íæ¼ÒÃû)\n");
                       who->set_temp("marks/ÃÕ", 1);
                       break;
                   case 1:
                       write("Ñ©ÔÚÉÕ£¬Ñ©ÔÚÉÕ¡£(´òÒ»±¾ÄàÌ¶Íæ¼ÒÃû)\n");
                       who->set_temp("marks/ÃÕ", 2);
                       break;
                   case 2:
                       write("µËĞ¡Æ½Ö®ºó¡£(´òÒ»±¾ÄàÌ¶NPCÃû)\n");
                       who->set_temp("marks/ÃÕ", 3);
                       break;
                   case 3:
                       write("ÓùÓÃ¾­µä¡£(´òÒ»±¾ÄàÌ¶Íæ¼ÒÃû)\n");
                       who->set_temp("marks/ÃÕ", 4);
                       break;
                   case 4:
                       write("´ò¹È³¡ÉÏµÄNPC¡£(´òÒ»±¾ÄàÌ¶Íæ¼ÒÃû)\n");
                       who->set_temp("marks/ÃÕ", 5);
                       break;
                   case 5:
		       write("°ÍÀèÏ°Óï¡£(´òÒ»±¾ÄàÌ¶¼¼ÄÜÃû£¬¾íÁ±¸ñ)\n");
                       who->set_temp("marks/ÃÕ", 6);
                       break;
                   case 6:
                       write("¹°ÖíÈëÃÅ¡£(´òÒ»×Ö)\n");
                    // this riddle made by ÀÏ¹ş£¨ÃÀ¹ú¡¡Ã÷ÄáËÕ´ï´óÑ§£©
                       who->set_temp("marks/ÃÕ", 7);
                       break;
                   case 7:
                       write("¹°ÖíÍõÃÆÃÆ²»ÀÖ¡£(´òÒ»×Ö)\n");
                    // this riddle modified from one made by ÂÌÌï¡¡£¨ÃÀ¹ú¡¡ÃÜÖ´°²Öİ£©
                       who->set_temp("marks/ÃÕ", 8);
                       break;
                   case 8:
                       write("½õ·«²Å¶É¶ùÀÉÈ¥¡£(´òÒ»±¾ÄàÌ¶Î×Ê¦ÍøÃû)\n");
                    // this riddle made by ÔÀº­¡¡£¨ÃÀ¹ú¡¡ÃÜÖ´°²Öİ£©
                       who->set_temp("marks/ÃÕ", 9);
                       break;
                   case 9:
                       write("µÂÒâÈÕÕ½°Ü¡£(´òÒ»±¾ÄàÌ¶NPCÃû)\n");
                    // this riddle modified from one made by Å£¡¡£¨ÃÀ¹ú£©
                       who->set_temp("marks/ÃÕ", 10);
                       break;
                   case 10:
                       write("ÕûÄêµ±±ø¡£(´òÒ»±¾ÄàÌ¶NPCÃû)\n");
                    // this riddle made by ËÄÔÂ¡¡£¨ÃÀ¹ú£©
                       who->set_temp("marks/ÃÕ", 11);
                       break;
                   case 11:
                       write("Å·Ñô·æÁ·¹¦¡£(´òÒ»³ÉÓï)\n");
                    // this riddle made by Ä§¡¡£¨ÃÀ¹ú£©
                       who->set_temp("marks/ÃÕ", 12);
                       break;
                   case 12:
                       write("ºúÌßÂÒõß¡£(´òÒ»±¾ÄàÌ¶NPCÃû)\n");
                    // this riddle made by ¾ÓÊ¿¡¡£¨ÃÀ¹ú£©
                       who->set_temp("marks/ÃÕ", 13);
                       break;
                   case 13:
                       write("Âó¿Ë½Ü¿ËÑ·¡£(´ò¶ş±¾ÄàÌ¶NPCÃû)----»Ø´ğÊ±¶şÃûÒ»Æğ»Ø´ğ£¬ÖĞ¼ä²»¼ÓÈÎºÎ±êµã¡£\n");
                       who->set_temp("marks/ÃÕ", 14);
                       break;
                   case 14:
                       write("ÕÙ¡££(´ò¶ş±¾ÄàÌ¶NPCÃû)----»Ø´ğÊ±¶şÃûÒ»Æğ»Ø´ğ£¬ÖĞ¼ä²»¼ÓÈÎºÎ±êµã¡£\n");
                    // this riddle made by ÀÏ¹ş¡¡£¨ÃÀ¹ú£©
                       who->set_temp("marks/ÃÕ", 15);
                       break;
                   case 15:
                       write("Ê¥Ö¼¡£(´òÒ»±¾ÄàÌ¶Íæ¼ÒÃû)\n");
                       who->set_temp("marks/ÃÕ", 16);
                       break;
                   case 16:
                       write("ÔµºÎÒ»Ï¦ÃÎÎ´³É¡£(´òÒ»±¾ÄàÌ¶ÃÅÅÉÃû)\n");
                    // this riddle made by ÀÏ¹ş¡¡£¨ÃÀ¹ú£© hanxx002@maroon.tc.umn.edu
                       who->set_temp("marks/ÃÕ", 17);
                       break;
                   case 17:
                       write("ÌÆÀÖ¡£(´òÒ»±¾ÄàÌ¶NPCÃû)\n");
                    // this riddle made by ¡ïÄ§¡¡£¨ÃÀ¹ú£© ning@phish.ecii.org
                       who->set_temp("marks/ÃÕ", 18);
                       break;
                   case 18:
                       write("Ò»ÑùµÄ²»Ö¹Ò»µãÁ½µã¡£(´òÒ»±¾ÄàÌ¶µØÃû¼°Ò»¼¼ÄÜÃû)\n");
                       who->set_temp("marks/ÃÕ", 19);
		       break;
                   case 19:
                       write("»Ø¿Û¡£(´òÒ»±¾ÄàÌ¶NPCÃû)\n");
                       who->set_temp("marks/ÃÕ", 20);
                       break;

                  }
                  write("ÏëºÃÁË»Ø´ğ (answer) ÎÒ¡£¼Ç×¡£¬²»¿ÉĞ¹Â¶ÃÕÓï»òÃÕµ×¡£\n");
                  message("vision", "°¢·²Ìá¶Ô×Å"+who->name()+"àÖ¹¾ÁË¼¸¾ä»°¡£\n",
                          environment(who), ({who}) );
                  remove_call_out("destroying");
                  call_out("destroying", 1, this_object(), ob);
                  return 1;
            }
      }
}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
int do_answer(string arg)
{
        object me,gold;
        int soln,riddle;
        me = this_player();
        riddle = this_player()->query_temp("marks/ÃÕ");

        if (!riddle) {
           write("ÎÒÓÖ²»ÊÇÄãÊ¦¸µ£¬ÄãÓÃ²»×Å»Ø´ğÎÒ¡£\n");
           return 1;
        }

        if( !arg || arg=="" ) {
           write("ÏëºÃÃÕµ×ÔÙ»Ø´ğ¡£\n");
           return 1;
        }
        message("vision", me->name() + "°Ñ×ì´Õµ½°¢·²ÌáµÄ¶ú±ßàÖàÖ¹¾¹¾¡£\n",
                 environment(me), ({me}) );

        switch (arg) {
          case "æ©": soln=1; break;
          case "ÁéÁé" : soln=2; break;
          case "½­°ÙÊ¤" : soln=3; break;
          case "Ãµ" : soln=4; break;
          case "¶şÍŞ" : soln=5; break;
          case "µÀÑ§ĞÄ·¨" : soln=6; break;
          case "ºÒ" : soln=7; break;
          case "º¤" : soln=8; break;
          case "·½ÖÛ×Ó" : soln=9; break;
          case "Å·Ñô¿Ë" : soln=10; break;
          case "¶¡´ºÇï" : soln=11; break;
          case "µ¹ĞĞÄæÊ©" : soln=12; break;
          case "Â³ÓĞ½Å" : soln=13; break;
          case "ºÚÎŞ³£°×ÎŞ³£":
          case "°×ÎŞ³£ºÚÎŞ³£": soln=14; break;
          case "Å·Ñô·æÅ·Ñô¿Ë": soln=15; break;
          case "ÁúÔÆ": soln=16; break;
	  case "ÉÙÁÖ": soln=17; break;
	  case "ÀîÄª³î" : soln=18; break;
	  case "åĞÒ£¶´åĞÒ£ÓÎ" : soln=19; break;
          case "ÂòÂôÌá" : soln=20; break;
          default :
              say("°¢·²Ìá´óĞ¦ÆğÀ´£¬ËµµÀ£ºÄãËµÊ²Ã´Ñ½£¬Å£Í·²»¶ÔÂí×ì¡£\n"
                  + me->name() + "µÄÁ³±»ëıµÃÍ¨ºì¡£\n");
              return 1;
        }

        if (riddle==soln) {
          gold = new("clone/money/gold");
          gold->move(this_player());
          say("°¢·²Ìá¸øÁË" + me->name() + "Ò»Á½»Æ½ğ¡£\n");
          this_player()->set_temp("marks/ÃÕ", 0);
          say ("°¢·²Ìá¶Ô" + me->name() + "ÊúÆğ´óÄ·Ö¸£º¾ÓÈ»ÈÃÄã²Â×ÅÁË¡£»Æ½ğÊÇ°ÍÒÀµÄ²»ÒåÖ®²Æ£¬ÄãÄÃÈ¥·Ö¸øÇîÈË°É¡£\n");
          this_player()->set("combat_exp",this_player()->query("combat_exp")+80);
          write ("ÄãµÄ¾­ÑéÔö¼ÓÁË£¡\n");

        }
        else
          write ("Ë­°ÑÃÕµ×¸æËßÄãµÄ? ²»¶Ô!!\n");
        return 1;
} 
 
*/
   
